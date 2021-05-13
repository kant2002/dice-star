/* Automatically generated by the Kremlin tool */



#ifndef __L0_X509_AliasKeyTBS_H
#define __L0_X509_AliasKeyTBS_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include "LowStar_Printf.h"
#include <string.h>


#include "L0_X509_AliasKeyTBS_Extensions.h"
#include "L0_X509_AliasKeyTBS_Issuer.h"
#include "L0_X509_AliasKeyTBS_Subject.h"
#include "ASN1_X509.h"

typedef struct aliasKeyTBS_payload_t_s
{
  int32_t aliasKeyTBS_version;
  octet_string_t aliasKeyTBS_serialNumber;
  oid_t aliasKeyTBS_signatureAlg;
  aliasKeyTBS_issuer_payload_t aliasKeyTBS_issuer;
  x509_validity_payload_t aliasKeyTBS_validity;
  aliasKeyTBS_subject_payload_t aliasKeyTBS_subject;
  subjectPublicKeyInfo_payload_t aliasKeyTBS_aliasKey_pub;
  aliasKeyTBS_extensions_payload_t aliasKeyTBS_extensions;
}
aliasKeyTBS_payload_t;

uint32_t
len_of_aliasKeyTBS_payload(
  octet_string_t serialNumber,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_country,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_country,
  int32_t version
);

typedef aliasKeyTBS_payload_t aliasKeyTBS_t;

uint32_t
len_of_aliasKeyTBS(
  octet_string_t serialNumber,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_country,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_country,
  int32_t version
);

uint32_t
serialize32_aliasKeyTBS_payload_backwards(
  aliasKeyTBS_payload_t x,
  uint8_t *input,
  uint32_t pos
);

uint32_t serialize32_aliasKeyTBS_backwards(aliasKeyTBS_payload_t x, uint8_t *b, uint32_t pos);

aliasKeyTBS_payload_t
x509_get_AliasKeyTBS(
  int32_t crt_version,
  octet_string_t serialNumber,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes i_country,
  FStar_Bytes_bytes notBefore,
  FStar_Bytes_bytes notAfter,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_country,
  int32_t ku,
  octet_string_t keyID,
  int32_t version,
  FStar_Bytes_bytes fwid,
  FStar_Bytes_bytes deviceIDPub,
  FStar_Bytes_bytes aliasKeyPub
);

#if defined(__cplusplus)
}
#endif

#define __L0_X509_AliasKeyTBS_H_DEFINED
#endif
