/// Reference: https://github.com/microsoft/RIoT/blob/master/Reference/DICE/DiceCore.cpp
module Minimal.DICE

open LowStar.BufferOps
open Lib.IntTypes
open FStar.Integers

open Spec.Hash.Definitions
open Hacl.Hash.Definitions

open HWIface

module I  = FStar.Integers
module HI  = Lib.IntTypes

module SHA2= Hacl.Hash.SHA2
module SHA1= Hacl.Hash.SHA1
module MD5 = Hacl.Hash.MD5
module HMAC= Hacl.HMAC

module B   = LowStar.Buffer
module M   = LowStar.Modifies
module HS  = FStar.HyperStack
module HST = FStar.HyperStack.ST
module IB  = LowStar.ImmutableBuffer

unfold inline_for_extraction noextract
let dice_hash (alg: dice_alg): hash_st alg =
  match alg with
  | SHA2_256 -> SHA2.hash_256
  | SHA2_384 -> SHA2.hash_384
  | SHA2_512 -> SHA2.hash_512
  | SHA1     -> SHA1.legacy_hash

unfold inline_for_extraction noextract
let dice_hmac (alg: dice_alg): HMAC.compute_st alg =
  match alg with
  | SHA2_256 -> HMAC.compute_sha2_256
  | SHA2_384 -> HMAC.compute_sha2_384
  | SHA2_512 -> HMAC.compute_sha2_512
  | SHA1     -> HMAC.legacy_compute_sha1

#reset-options "--z3rlimit 30"
let dice_on_stack
  (st: state)
  (riot_size: riot_size_t)
  (riot_binary: B.buffer uint8{B.length riot_binary == v riot_size})
: HST.Stack unit
  (requires fun h ->
    h `HWIface.contains` st /\
    h `B.live` riot_binary /\
    B.all_disjoint ((get_loc_l st)@[B.loc_buffer riot_binary]))
  (ensures  fun h0 _ h1 ->
    B.live h1 riot_binary /\
    (let uds, cdi = get_uds st, get_cdi st in
       B.modifies (B.loc_buffer cdi) h0 h1 /\
       B.as_seq h1 cdi
         == Spec.Agile.HMAC.hmac alg
              (Spec.Agile.Hash.hash alg (B.as_seq h0 uds))
              (Spec.Agile.Hash.hash alg (B.as_seq h0 riot_binary))))
=
  HST.push_frame();

  let uds, cdi = get_uds st, get_cdi st in

  (**)let h0 = HST.get () in

  (* compute uDigest *)
  let uDigest: b:B.buffer uint8{B.length b == hash_length alg}
    = B.alloca (u8 0x00) digest_length in
  dice_hash alg
    uds uds_length
    uDigest;

  (**)let h1 = HST.get () in
  (**)assert (B.modifies (B.loc_buffer uDigest) h0 h1 /\
  (**)        B.as_seq h1 uDigest == Spec.Agile.Hash.hash alg (B.as_seq h0 uds));

  (* compute rDigest *)
  let rDigest: b:B.buffer uint8{B.length b == hash_length alg}
    = B.alloca (u8 0x00) digest_length in
  dice_hash alg
    riot_binary riot_size
    rDigest;

  (**)let h2 = HST.get () in
  (**)assert (B.modifies (B.loc_buffer rDigest) h1 h2 /\
  (**)        B.as_seq h2 rDigest == Spec.Agile.Hash.hash alg (B.as_seq h1 riot_binary));

  (* compute cdi *)
  dice_hmac alg
    cdi
    uDigest digest_length
    rDigest digest_length;

  HST.pop_frame()

/// <><><><><><><><><><><><> DICE main funtion <><><><><><><><><><><>

#reset-options "--z3rlimit 50"
let dice_main
  (riot_size: riot_size_t)
  (riot_binary: B.buffer uint8 {B.length riot_binary == v riot_size})
: HST.ST (st:state{B.all_disjoint ((get_loc_l st)@[B.loc_buffer riot_binary])})
  (requires fun h ->
    uds_is_uninitialized h /\
    h `B.live` riot_binary /\
    (let (| _, _, local_st |) = local_state in
      B.loc_disjoint (B.loc_buffer riot_binary) (B.loc_mreference local_st)))
  (ensures  fun h0 _ h1 ->
    (*FIXME: sometimes I can prove this, sometimes not*)//B.live h1 riot_binary /\
    uds_is_disabled)
=
  (* allocating in the heap *)
  (* pass `riot_binary` to `initialize` in order to maintain disjointness *)
  let st: st:state{B.all_disjoint ((get_loc_l st)@[B.loc_buffer riot_binary])}
      = initialize riot_binary in


  (* only allocating on the stack *)
  dice_on_stack st riot_size riot_binary;

  (* wipe and disable uds *)
  unset_uds st;
  disable_uds st;

  (*return*) st

/// <><><><><><><><><><><><> C main funtion <><><><><><><><><><><>

assume val riot_size: riot_size_t

assume val riot_binary:
  b:B.buffer uint8
    {B.length b == v riot_size /\
    (let (| _, _, local_st |) = local_state in
      B.loc_disjoint (B.loc_buffer b) (B.loc_mreference local_st))}

assume val safe_load
  (riot_size: riot_size_t)
  (riot_binary: B.buffer uint8{B.length riot_binary == v riot_size})
  (base_address: B.buffer pub_uint8)
: HST.Stack unit
  (requires fun h ->
    B.live h riot_binary /\
    B.live h base_address)
  (ensures  fun h0 _ h1 ->
    B.modifies (B.loc_buffer riot_binary) h0 h1)

let riot_main_t =
  (st:state)
-> HST.Stack state
  (requires fun h ->
    uds_is_disabled /\
    h `B.live` riot_binary /\
    (let (| _, _, local_st |) = local_state in
      B.loc_disjoint (B.loc_buffer riot_binary) (B.loc_mreference local_st)) /\
    (let uds_value, cdi = get_uds_value st, get_cdi st in
     B.as_seq h cdi
        == Spec.Agile.HMAC.hmac alg
             (Spec.Agile.Hash.hash alg uds_value)
             (Spec.Agile.Hash.hash alg (B.as_seq h riot_binary))))
  (ensures  fun h0 _ h1 ->
    let cdi = get_cdi st in
      B.as_seq h1 cdi == Seq.create (v cdi_length) (u8 0x00))

assume val riot_main: riot_main_t

val safe_call
    (riot_main: riot_main_t)
    (st: state)
: HST.Stack (st:state{B.all_disjoint ((get_loc_l st)@[B.loc_buffer riot_binary])})
  (requires fun h ->
    uds_is_disabled /\
    h `B.live` riot_binary /\
    (let (| _, _, local_st |) = local_state in
      B.loc_disjoint (B.loc_buffer riot_binary) (B.loc_mreference local_st)))
  (ensures  fun h0 _ h1 ->
    B.live h1 riot_binary /\
    uds_is_disabled)
let safe_call riot_main st = riot_main st

let main ()
: HST.ST C.exit_code
  (requires fun h ->
    uds_is_uninitialized h /\
    B.live h riot_binary)
  (ensures  fun h0 _ h1 ->
    uds_is_disabled)
=
  (* Added a dynamic check, since we might assume `riot_size` in F*
     and computation relevant refinements on `riot_size` won't
     reach C code. Do we need it? *)
  if (0 < v riot_size && v riot_size <= max_input_length alg) then
    let st = dice_main riot_size riot_binary in
    C.EXIT_SUCCESS
  else
    C.EXIT_FAILURE
