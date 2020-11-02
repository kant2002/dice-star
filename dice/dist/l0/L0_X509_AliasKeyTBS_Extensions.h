/* Automatically generated by the Kremlin tool */



#ifndef __L0_X509_AliasKeyTBS_Extensions_H
#define __L0_X509_AliasKeyTBS_Extensions_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include "LowStar_Printf.h"
#include <string.h>


#include "L0_X509_AliasKeyTBS_Extensions_BasicConstraints.h"
#include "ASN1_X509.h"
#include "L0_X509_AliasKeyTBS_Extensions_AuthKeyIdentifier.h"
#include "L0_X509_AliasKeyTBS_Extensions_ExtendedKeyUsage.h"
#include "L0_X509_Extension.h"

typedef struct aliasKeyTBS_extensions_payload_t_s
{
  key_usage_t aliasKeyTBS_extensions_key_usage;
  aliasKeyTBS_extensions_extendedKeyUsage_t aliasKeyTBS_extensions_extendedKeyUsage;
  aliasKeyTBS_extensions_basicConstraints_t aliasKeyTBS_extensions_basicConstraints;
  aliasKeyTBS_extensions_authKeyID_t aliasKeyTBS_extensions_authKeyID;
  l0_extension_payload_t aliasKeyTBS_extensions_l0;
}
aliasKeyTBS_extensions_payload_t;

uint32_t len_of_aliasKeyTBS_extensions_payload(int32_t version);

typedef aliasKeyTBS_extensions_payload_t aliasKeyTBS_extensions_t;

uint32_t len_of_aliasKeyTBS_extensions(int32_t version);

uint32_t
serialize32_aliasKeyTBS_extensions_payload_backwards(
  aliasKeyTBS_extensions_payload_t x,
  uint8_t *input,
  uint32_t pos
);

uint32_t
serialize32_aliasKeyTBS_extensions_backwards(
  aliasKeyTBS_extensions_payload_t x,
  uint8_t *b,
  uint32_t pos
);

aliasKeyTBS_extensions_payload_t
x509_get_aliasKeyTBS_extensions(
  int32_t ku,
  octet_string_t keyID,
  int32_t version,
  FStar_Bytes_bytes fwid,
  FStar_Bytes_bytes deviceIDPub
);

#if defined(__cplusplus)
}
#endif

#define __L0_X509_AliasKeyTBS_Extensions_H_DEFINED
#endif
