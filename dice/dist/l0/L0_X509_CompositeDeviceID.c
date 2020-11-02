/* Automatically generated by the Kremlin tool */



#include "L0_X509_CompositeDeviceID.h"

uint32_t
serialize32_compositeDeviceID_payload_backwards(
  compositeDeviceID_payload_t x,
  uint8_t *input,
  uint32_t pos
)
{
  uint32_t offset2 = serialize32_fwid_backwards(x.l0_fwid, input, pos);
  uint32_t
  offset21 = serialize32_subjectPublicKeyInfo_backwards(x.l0_deviceID, input, pos - offset2);
  uint32_t
  offset1 = serialize32_asn1_integer_TLV_backwards(x.l0_version, input, pos - offset2 - offset21);
  uint32_t offset10 = offset1 + offset21;
  return offset10 + offset2;
}

uint32_t
serialize32_compositeDeviceID_backwards(
  compositeDeviceID_payload_t x,
  uint8_t *b,
  uint32_t pos
)
{
  uint32_t offset_data = serialize32_compositeDeviceID_payload_backwards(x, b, pos);
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

compositeDeviceID_payload_t
x509_get_compositeDeviceID(
  int32_t version,
  FStar_Bytes_bytes deviceKeyPub,
  FStar_Bytes_bytes fwid
)
{
  subjectPublicKeyInfo_payload_t
  deviceIDPublicKeyInfo = x509_get_subjectPublicKeyInfo(deviceKeyPub);
  fwid_payload_t fwid1 = x509_get_fwid(fwid);
  return
    (
      (compositeDeviceID_payload_t){
        .l0_version = version,
        .l0_deviceID = deviceIDPublicKeyInfo,
        .l0_fwid = fwid1
      }
    );
}

