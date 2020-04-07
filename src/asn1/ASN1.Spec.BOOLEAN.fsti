module ASN1.Spec.BOOLEAN

open LowParse.Spec.Base
open LowParse.Spec.Combinators
open LowParse.Spec.Int

open ASN1.Base

(* BOOLEAN primitive *)
val filter_asn1_boolean
  (b: byte)
: Ghost bool
  (requires True)
  (ensures fun r -> r == (b = 0xFFuy || b = 0x00uy))

let valid_asn1_boolean_byte = parse_filter_refine filter_asn1_boolean

val synth_asn1_boolean
    (b: parse_filter_refine filter_asn1_boolean)
: Ghost (datatype_of_asn1_type BOOLEAN)
  (requires True)
  (ensures fun x -> x == (b = 0xFFuy))

val synth_asn1_boolean_inverse
  (x: datatype_of_asn1_type BOOLEAN)
: Ghost (b: parse_filter_refine filter_asn1_boolean{synth_asn1_boolean b == x})
  (requires True)
  (ensures fun b -> synth_asn1_boolean b == x)

let parse_asn1_boolean_kind = strong_parser_kind 1 1 None
val parse_asn1_boolean
: parser parse_asn1_boolean_kind (datatype_of_asn1_type BOOLEAN)

val parse_asn1_boolean_unfold
  (input: bytes)
: Lemma (
  parse parse_asn1_boolean input ==
 (match parse parse_u8 input with
  | Some (x, consumed) -> if filter_asn1_boolean x then
                          ( Some (synth_asn1_boolean x, consumed) )
                          else
                          ( None )
  | None -> None) /\
 (Some? (parse parse_asn1_boolean input) ==>
   Seq.length input > 0 /\
   parse parse_u8 input == Some (input.[0], 1)))

val serialize_asn1_boolean
: serializer parse_asn1_boolean

val serialize_asn1_boolean_unfold
  (b: datatype_of_asn1_type BOOLEAN)
: Lemma (
  serialize serialize_u8 (synth_asn1_boolean_inverse b)
  `Seq.equal`
  Seq.create 1 (synth_asn1_boolean_inverse b) /\
  serialize serialize_asn1_boolean b
  `Seq.equal`
  serialize serialize_u8 (synth_asn1_boolean_inverse b))

/// Specialized TLV
///
open ASN1.Spec.Tag
open ASN1.Spec.Length

val synth_asn1_boolean_TLV
  (a: (the_asn1_type BOOLEAN * asn1_int32_of_type BOOLEAN) * datatype_of_asn1_type BOOLEAN)
: GTot (value: datatype_of_asn1_type BOOLEAN{value == snd a})

val synth_asn1_boolean_TLV_inverse
  (x: datatype_of_asn1_type BOOLEAN)
: GTot (a: ((the_asn1_type BOOLEAN * asn1_int32_of_type BOOLEAN) * datatype_of_asn1_type BOOLEAN){x == synth_asn1_boolean_TLV a})

let parse_asn1_boolean_TLV_kind
: parser_kind
= strong_parser_kind 3 3 None
// = parse_asn1_tag_kind
//   `and_then_kind`
//   parse_asn1_length_kind_of_type BOOLEAN
//   `and_then_kind`
//   parse_asn1_boolean_kind

let parse_asn1_boolean_TLV
: parser parse_asn1_boolean_TLV_kind (datatype_of_asn1_type BOOLEAN)
= parse_the_asn1_tag BOOLEAN
  `nondep_then`
  parse_asn1_length_of_type BOOLEAN
  `nondep_then`
  parse_asn1_boolean
  `parse_synth`
  synth_asn1_boolean_TLV

val parse_asn1_boolean_TLV_unfold
  (input_TLV: bytes)
: Lemma (
  parse parse_asn1_boolean_TLV input_TLV ==
 (parser_kind_prop_equiv parse_asn1_tag_kind (parse_the_asn1_tag BOOLEAN);
  match parse (parse_the_asn1_tag BOOLEAN) input_TLV with
  | None -> None
  | Some (BOOLEAN, 1) ->
    (parser_kind_prop_equiv (parse_asn1_length_kind_of_type BOOLEAN) (parse_asn1_length_of_type BOOLEAN);
     let input_LV = Seq.slice input_TLV 1 (Seq.length input_TLV) in
     match parse (parse_asn1_length_of_type BOOLEAN) input_LV with
     | None -> None
     | Some (1ul, 1) ->
       (parser_kind_prop_equiv parse_asn1_boolean_kind parse_asn1_boolean;
        let input_V = Seq.slice input_LV 1 (Seq.length input_LV) in
        match parse parse_asn1_boolean input_V with
        | None -> None
        | Some (value, 1) -> Some (value, (1 + 1 + 1 <: consumed_length input_TLV)))))
)

let serialize_asn1_boolean_TLV
: serializer parse_asn1_boolean_TLV
= serialize_synth
  (* p1 *) (parse_the_asn1_tag BOOLEAN
            `nondep_then`
            parse_asn1_length_of_type BOOLEAN
            `nondep_then`
            parse_asn1_boolean)
  (* f2 *) (synth_asn1_boolean_TLV)
  (* s1 *) (serialize_the_asn1_tag BOOLEAN
            `serialize_nondep_then`
            serialize_asn1_length_of_type BOOLEAN
            `serialize_nondep_then`
            serialize_asn1_boolean)
  (* g1 *) (synth_asn1_boolean_TLV_inverse)
  (* Prf*) ()

val serialize_asn1_boolean_TLV_unfold
  (value: datatype_of_asn1_type BOOLEAN)
: Lemma (
  serialize serialize_asn1_boolean_TLV value
  `Seq.equal`
 (serialize (serialize_the_asn1_tag BOOLEAN) BOOLEAN
  `Seq.append`
  serialize (serialize_asn1_length_of_type BOOLEAN) 1ul
  `Seq.append`
  serialize serialize_asn1_boolean value)
)
