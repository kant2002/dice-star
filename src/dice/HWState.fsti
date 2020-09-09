module HWState

open FStar.Integers
open FStar.HyperStack.ST

module G = FStar.Ghost
module HS = FStar.HyperStack
module B = LowStar.Buffer

open DICE.Definitions

type mbuffer (a:Type0) (len:nat) =
  b:B.lbuffer a len{B.frameOf b == HS.root /\ B.recallable b}

val t : Type0

noeq
type l0_image_t = {
  l0_image_header_size : signable_len;
  l0_image_header      : mbuffer byte_sec (v l0_image_header_size);
  l0_image_header_sig  : mbuffer byte_sec 64;
  l0_binary_size       : hashable_len;
  l0_binary            : mbuffer byte_sec (v l0_binary_size);
  l0_binary_hash       : mbuffer byte_sec (v digest_len);
  l0_image_auth_pubkey : mbuffer byte_sec 32;
}

noeq
type state = {
  ghost_state : mbuffer (G.erased t) 1;

  cdi : mbuffer byte_sec (v digest_len);

  l0 : img:l0_image_t{
    B.(all_disjoint [loc_buffer ghost_state;
                     loc_buffer cdi;
                     loc_buffer img.l0_image_header;
                     loc_buffer img.l0_image_header_sig;
                     loc_buffer img.l0_binary;
                     loc_buffer img.l0_binary_hash;
                     loc_buffer img.l0_image_auth_pubkey ])
  }
}
