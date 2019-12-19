/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml ./src/Minimal.DICE.fst -cc clang -no-prefix Hacl.Frodo.Random -bundle Hacl.Spec.*,Spec.*[rename=Hacl_Spec] -bundle Lib.*[rename=Hacl_Lib] -drop Lib.IntVector.Intrinsics -fparentheses -fno-shadow -fcurly-braces -bundle LowStar.* -bundle Prims,C.Failure,C,C.String,C.Loops,Spec.Loops,C.Endianness,FStar.*[rename=Hacl_Kremlib] -bundle Meta.* -minimal -add-include "kremlin/internal/types.h" -add-include "kremlin/lowstar_endianness.h" -add-include <string.h> -drop WasmSupport -tmpdir ./out -I ./src -add-include "kremlin/internal/compat.h" -I /home/zhetao/Sources/kremlin/include -I /home/zhetao/Sources/kremlin/kremlib/dist/generic -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -I /home/zhetao/Sources/kremlin/kremlib -o dice.exe
  F* version: 71c0a6aa
  KreMLin version: fe104c22
 */

#include "Minimal_Loader.h"

uint32_t Minimal_Loader___proj__Mkheader_t__item__version(Minimal_Loader_header_t projectee)
{
  return projectee.version;
}

uint32_t
Minimal_Loader___proj__Mkheader_t__item__binary_size(Minimal_Loader_header_t projectee)
{
  return projectee.binary_size;
}

Lib_IntTypes_sec_int_t____
*Minimal_Loader___proj__Mkheader_t__item__binary_hash(Minimal_Loader_header_t projectee)
{
  return projectee.binary_hash;
}

Lib_IntTypes_sec_int_t____
*Minimal_Loader___proj__Mkheader_t__item__header_sig(Minimal_Loader_header_t projectee)
{
  return projectee.header_sig;
}

Lib_IntTypes_sec_int_t____
*Minimal_Loader___proj__Mkheader_t__item__binary(Minimal_Loader_header_t projectee)
{
  return projectee.binary;
}

Lib_IntTypes_sec_int_t____
*Minimal_Loader___proj__Mkheader_t__item__header_raw(Minimal_Loader_header_t projectee)
{
  return projectee.header_raw;
}

Lib_IntTypes_sec_int_t____
*Minimal_Loader___proj__Mkheader_t__item__header_pubkey(Minimal_Loader_header_t projectee)
{
  return projectee.header_pubkey;
}

uint32_t Minimal_Loader___proj__Mklayer_t__item__size(Minimal_Loader_layer_t projectee)
{
  return projectee.size;
}

Lib_IntTypes_sec_int_t____
*Minimal_Loader___proj__Mklayer_t__item__binary(Minimal_Loader_layer_t projectee)
{
  return projectee.binary;
}

Minimal_Loader_entry_t
Minimal_Loader___proj__Mklayer_t__item__entry(Minimal_Loader_layer_t projectee)
{
  return projectee.entry;
}

bool Minimal_Loader_verify_header(Minimal_Loader_header_t header)
{
  KRML_CHECK_SIZE(sizeof (Lib_IntTypes_sec_int_t____), (uint32_t)32U);
  Lib_IntTypes_sec_int_t____ rhDigest[32U];
  for (uint32_t _i = 0U; _i < (uint32_t)32U; ++_i)
    rhDigest[_i]
    = Lib_IntTypes_mk_int(Lib_IntTypes_U8, Lib_IntTypes_SEC, (krml_checked_int_t)0x00);
  Hacl_Hash_SHA2_hash_256(header.header_raw, Minimal_Loader_header_len, rhDigest);
  bool b = Hacl_Ed25519_verify(header.header_pubkey, (uint32_t)32U, rhDigest, header.header_sig);
  return b;
}

Minimal_Loader_layer_t Minimal_Loader_load_layer()
{
  Minimal_Loader_header_t header = Minimal_Loader_load_header();
  KRML_CHECK_SIZE(sizeof (Lib_IntTypes_sec_int_t____), header.binary_size);
  Lib_IntTypes_sec_int_t____
  *buf = KRML_HOST_MALLOC(sizeof (Lib_IntTypes_sec_int_t____) * header.binary_size);
  for (uint32_t _i = 0U; _i < header.binary_size; ++_i)
    buf[_i] = Lib_IntTypes_mk_int(Lib_IntTypes_U8, Lib_IntTypes_SEC, (krml_checked_int_t)0x00);
  Minimal_Loader_layer_t
  layer = { .size = header.binary_size, .binary = buf, .entry = Minimal_Loader_entry };
  bool verify_result = Minimal_Loader_verify_header(header);
  if (!verify_result)
  {
    exit((int32_t)-1);
  }
  return layer;
}

