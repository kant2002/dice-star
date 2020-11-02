/* Automatically generated by the Kremlin tool */



#include "L0_X509_AliasKeyTBS_Extensions_ExtendedKeyUsage.h"

uint32_t
serialize32_aliasKeyTBS_extensions_extendedKeyUsage_backwards(
  aliasKeyTBS_extensions_extendedKeyUsage_t x,
  uint8_t *b,
  uint32_t pos
)
{
  K___ASN1_Base_oid_t_bool x1 = x.fst;
  oid_t x2 = x.snd;
  uint32_t offset_data = serialize32_asn1_oid_TLV_backwards(x2, b, pos);
  uint32_t
  offset20 =
    serialize32_asn1_length_of_type_backwards(((asn1_tag_t){ .tag = SEQUENCE }),
      offset_data,
      b,
      pos - offset_data);
  b[pos - offset_data - offset20 - (uint32_t)1U] =
    encode_asn1_tag(((asn1_tag_t){ .tag = SEQUENCE }));
  uint32_t offset10 = (uint32_t)1U;
  uint32_t offset_tag_len = offset10 + offset20;
  uint32_t offset_data0 = offset_tag_len + offset_data;
  uint32_t
  offset21 =
    serialize32_asn1_length_of_type_backwards(((asn1_tag_t){ .tag = OCTET_STRING }),
      offset_data0,
      b,
      pos - offset_data0);
  b[pos - offset_data0 - offset21 - (uint32_t)1U] =
    encode_asn1_tag(((asn1_tag_t){ .tag = OCTET_STRING }));
  uint32_t offset11 = (uint32_t)1U;
  uint32_t offset_tag_len0 = offset11 + offset21;
  uint32_t offset22 = offset_tag_len0 + offset_data0;
  oid_t x11 = x1.fst;
  bool x21 = x1.snd;
  uint32_t offset210 = serialize32_asn1_boolean_TLV_backwards(x21, b, pos - offset22);
  uint32_t offset12 = serialize32_asn1_oid_TLV_backwards(x11, b, pos - offset22 - offset210);
  uint32_t offset13 = offset12 + offset210;
  uint32_t offset_data1 = offset13 + offset22;
  uint32_t
  offset2 =
    serialize32_asn1_length_of_type_backwards(((asn1_tag_t){ .tag = SEQUENCE }),
      offset_data1,
      b,
      pos - offset_data1);
  b[pos - offset_data1 - offset2 - (uint32_t)1U] =
    encode_asn1_tag(((asn1_tag_t){ .tag = SEQUENCE }));
  uint32_t offset1 = (uint32_t)1U;
  uint32_t offset_tag_len1 = offset1 + offset2;
  return offset_tag_len1 + offset_data1;
}

aliasKeyTBS_extensions_extendedKeyUsage_t
x509_get_aliasKeyTBS_extensions_extendedKeyUsage(bool criticality)
{
  return
    (
      (aliasKeyTBS_extensions_extendedKeyUsage_t){
        .fst = { .fst = OID_EXTENDED_KEY_USAGE, .snd = criticality },
        .snd = OID_CLIENT_AUTH
      }
    );
}

