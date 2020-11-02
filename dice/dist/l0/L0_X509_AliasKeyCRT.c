/* Automatically generated by the Kremlin tool */



#include "L0_X509_AliasKeyCRT.h"

uint32_t len_of_aliasKeyCRT_payload(uint32_t tbs_len)
{
  return tbs_len + (uint32_t)74U;
}

uint32_t len_of_aliasKeyCRT(uint32_t tbs_len)
{
  return
    (uint32_t)1U
    + len_of_asn1_length(len_of_aliasKeyCRT_payload(tbs_len))
    + len_of_aliasKeyCRT_payload(tbs_len);
}

uint32_t
serialize32_aliasKeyCRT_payload_backwards(
  uint32_t tbs_len,
  aliasKeyCRT_payload_t x,
  uint8_t *input,
  uint32_t pos
)
{
  uint32_t offset0 = serialize32_asn1_bit_string_TLV_backwards(x.aliasKeyCRT_sig, input, pos);
  uint32_t offset2 = offset0;
  uint32_t pos1 = pos - offset2;
  uint32_t
  offset = serialize32_algorithmIdentifier_backwards(x.aliasKeyCRT_sig_alg, input, pos1);
  uint32_t offset21 = offset;
  uint32_t pos2 = pos1 - offset21;
  uint32_t offset1 = serialize32_flbytes32_backwards(tbs_len, x.aliasKeyCRT_tbs, input, pos2);
  uint32_t offset10 = offset1;
  uint32_t offset3 = offset10 + offset21;
  uint32_t offset11 = offset3;
  return offset11 + offset2;
}

uint32_t
serialize32_aliasKeyCRT_backwards(
  uint32_t tbs_len,
  aliasKeyCRT_payload_t x,
  uint8_t *b,
  uint32_t pos
)
{
  uint32_t offset0 = serialize32_aliasKeyCRT_payload_backwards(tbs_len, x, b, pos);
  uint32_t offset_data = offset0;
  uint32_t pos1 = pos - offset_data;
  uint32_t
  offset1 =
    serialize32_asn1_length_of_type_backwards(((asn1_tag_t){ .tag = SEQUENCE }),
      offset_data,
      b,
      pos1);
  uint32_t offset2 = offset1;
  uint32_t pos2 = pos1 - offset2;
  uint32_t offset = (uint32_t)1U;
  uint8_t content = encode_asn1_tag(((asn1_tag_t){ .tag = SEQUENCE }));
  b[pos2 - offset] = content;
  uint32_t offset3 = offset;
  uint32_t offset10 = offset3;
  uint32_t offset4 = offset10 + offset2;
  uint32_t offset_tag_len = offset4;
  return offset_tag_len + offset_data;
}

aliasKeyCRT_payload_t
x509_get_AliasKeyCRT(
  uint32_t tbs_len,
  FStar_Bytes_bytes aliasKeyCRT_tbs,
  FStar_Bytes_bytes signature32
)
{
  oid_t aliasKeyCRT_sig_alg = OID_ED25519;
  bit_string_t
  aliasKeyCRT_sig =
    { .bs_len = (uint32_t)65U, .bs_unused_bits = (uint32_t)0U, .bs_s = signature32 };
  return
    (
      (aliasKeyCRT_payload_t){
        .aliasKeyCRT_tbs = aliasKeyCRT_tbs,
        .aliasKeyCRT_sig_alg = aliasKeyCRT_sig_alg,
        .aliasKeyCRT_sig = aliasKeyCRT_sig
      }
    );
}

