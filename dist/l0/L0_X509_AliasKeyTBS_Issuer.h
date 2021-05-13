/* Automatically generated by the Kremlin tool */



#ifndef __L0_X509_AliasKeyTBS_Issuer_H
#define __L0_X509_AliasKeyTBS_Issuer_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include "LowStar_Printf.h"
#include <string.h>


#include "ASN1_X509.h"

typedef struct aliasKeyTBS_issuer_payload_t_s
{
  x509_rdn_string_t aliasKeyTBS_issuer_Common;
  x509_rdn_string_t aliasKeyTBS_issuer_Organization;
  x509_rdn_string_t aliasKeyTBS_issuer_Country;
}
aliasKeyTBS_issuer_payload_t;

uint32_t
len_of_aliasKeyTBS_issuer_payload(
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_country
);

typedef aliasKeyTBS_issuer_payload_t aliasKeyTBS_issuer_t;

uint32_t
len_of_aliasKeyTBS_issuer(
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_country
);

uint32_t
serialize32_aliasKeyTBS_issuer_payload_backwards(
  aliasKeyTBS_issuer_payload_t x,
  uint8_t *input,
  uint32_t pos
);

uint32_t
serialize32_aliasKeyTBS_issuer_backwards(
  aliasKeyTBS_issuer_payload_t x,
  uint8_t *b,
  uint32_t pos
);

aliasKeyTBS_issuer_payload_t
x509_get_aliasKeyTBS_issuer(
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_common,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_org,
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes s_country
);

#if defined(__cplusplus)
}
#endif

#define __L0_X509_AliasKeyTBS_Issuer_H_DEFINED
#endif
