/* Automatically generated by the Kremlin tool */



#ifndef __L0_X509_Base_H
#define __L0_X509_Base_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include "LowStar_Printf.h"
#include <string.h>


#include "ASN1_X509.h"

typedef struct deviceIDCSR_ingredients_t_s
{
  int32_t deviceIDCSR_ku;
  int32_t deviceIDCSR_version;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes deviceIDCSR_s_common;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes deviceIDCSR_s_org;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes deviceIDCSR_s_country;
}
deviceIDCSR_ingredients_t;

typedef struct aliasKeyCRT_ingredients_t_s
{
  int32_t aliasKeyCrt_version;
  octet_string_t aliasKeyCrt_serialNumber;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes aliasKeyCrt_i_common;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes aliasKeyCrt_i_org;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes aliasKeyCrt_i_country;
  FStar_Bytes_bytes aliasKeyCrt_notBefore;
  FStar_Bytes_bytes aliasKeyCrt_notAfter;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes aliasKeyCrt_s_common;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes aliasKeyCrt_s_org;
  Prims_dtuple2__uint32_t_FStar_Bytes_bytes aliasKeyCrt_s_country;
  int32_t aliasKeyCrt_ku;
  int32_t aliasKeyCrt_l0_version;
}
aliasKeyCRT_ingredients_t;

#if defined(__cplusplus)
}
#endif

#define __L0_X509_Base_H_DEFINED
#endif
