/* Automatically generated by the Kremlin tool */



#include "L0_X509_DeviceIDCRI.h"

uint32_t
len_of_deviceIDCRI_payload(
  int32_t version,
  character_string_t s_common,
  character_string_t s_org,
  character_string_t s_country
)
{
  return
    (uint32_t)1U
    + len_of_asn1_length(len_of_asn1_integer(version))
    + len_of_asn1_integer(version)
    + len_of_deviceIDCRI_subject(s_common, s_org, s_country)
    + (uint32_t)44U
    +
      (uint32_t)1U
      +
        len_of_asn1_length((uint32_t)1U
          +
            len_of_asn1_length((uint32_t)1U
              + len_of_asn1_length((uint32_t)9U)
              + (uint32_t)9U
              +
                (uint32_t)1U
                +
                  len_of_asn1_length((uint32_t)1U
                    + len_of_asn1_length((uint32_t)14U)
                    + (uint32_t)14U)
                + (uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U)
          +
            (uint32_t)1U
            + len_of_asn1_length((uint32_t)9U)
            + (uint32_t)9U
            +
              (uint32_t)1U
              + len_of_asn1_length((uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U)
              + (uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U)
      +
        (uint32_t)1U
        +
          len_of_asn1_length((uint32_t)1U
            + len_of_asn1_length((uint32_t)9U)
            + (uint32_t)9U
            +
              (uint32_t)1U
              + len_of_asn1_length((uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U)
              + (uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U)
        +
          (uint32_t)1U
          + len_of_asn1_length((uint32_t)9U)
          + (uint32_t)9U
          +
            (uint32_t)1U
            + len_of_asn1_length((uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U)
            + (uint32_t)1U + len_of_asn1_length((uint32_t)14U) + (uint32_t)14U;
}

uint32_t
len_of_deviceIDCRI(
  int32_t version,
  character_string_t s_common,
  character_string_t s_org,
  character_string_t s_country
)
{
  return
    (uint32_t)1U
    + len_of_asn1_length(len_of_deviceIDCRI_payload(version, s_common, s_org, s_country))
    + len_of_deviceIDCRI_payload(version, s_common, s_org, s_country);
}

uint32_t
serialize32_deviceIDCRI_payload_backwards(
  deviceIDCRI_payload_t x,
  uint8_t *input,
  uint32_t pos
)
{
  uint32_t
  offset2 = serialize32_deviceIDCRI_attributes_backwards(x.deviceIDCRI_attributes, input, pos);
  uint32_t
  offset21 =
    serialize32_subjectPublicKeyInfo_backwards(x.deviceIDCRI_subjectPKInfo,
      input,
      pos - offset2);
  uint32_t
  offset22 =
    serialize32_deviceIDCRI_subject_backwards(x.deviceIDCRI_subject,
      input,
      pos - offset2 - offset21);
  uint32_t
  offset1 =
    serialize32_asn1_integer_TLV_backwards(x.deviceIDCRI_version,
      input,
      pos - offset2 - offset21 - offset22);
  uint32_t offset10 = offset1 + offset22;
  uint32_t offset11 = offset10 + offset21;
  return offset11 + offset2;
}

uint32_t serialize32_deviceIDCRI_backwards(deviceIDCRI_payload_t x, uint8_t *b, uint32_t pos)
{
  uint32_t offset_data = serialize32_deviceIDCRI_payload_backwards(x, b, pos);
  uint32_t
  offset2 =
    serialize32_asn1_length_of_type_backwards(((asn1_tag_t){ .tag = SEQUENCE }),
      offset_data,
      b,
      pos - offset_data);
  b[pos - offset_data - offset2 - (uint32_t)1U] =
    encode_asn1_tag(((asn1_tag_t){ .tag = SEQUENCE }));
  uint32_t offset1 = (uint32_t)1U;
  uint32_t offset_tag_len = offset1 + offset2;
  return offset_tag_len + offset_data;
}

deviceIDCRI_payload_t
x509_get_deviceIDCRI(
  int32_t version,
  character_string_t s_common,
  character_string_t s_org,
  character_string_t s_country,
  int32_t ku,
  FStar_Bytes_bytes deviceIDPub
)
{
  deviceIDCRI_subject_payload_t
  subject =
    x509_get_deviceIDCRI_subject(FStar_Pervasives_dfst__uint32_t_FStar_Bytes_bytes(s_common),
      FStar_Pervasives_dsnd__uint32_t_FStar_Bytes_bytes(s_common),
      FStar_Pervasives_dfst__uint32_t_FStar_Bytes_bytes(s_org),
      FStar_Pervasives_dsnd__uint32_t_FStar_Bytes_bytes(s_org),
      FStar_Pervasives_dfst__uint32_t_FStar_Bytes_bytes(s_country),
      FStar_Pervasives_dsnd__uint32_t_FStar_Bytes_bytes(s_country));
  deviceIDCRI_attributes_t deviceIDCRI_attributes = x509_get_deviceIDCRI_attributes(ku);
  subjectPublicKeyInfo_payload_t deviceID_PKInfo = x509_get_subjectPublicKeyInfo(deviceIDPub);
  return
    (
      (deviceIDCRI_payload_t){
        .deviceIDCRI_version = version,
        .deviceIDCRI_subject = subject,
        .deviceIDCRI_subjectPKInfo = deviceID_PKInfo,
        .deviceIDCRI_attributes = deviceIDCRI_attributes
      }
    );
}

