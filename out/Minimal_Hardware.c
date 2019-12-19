/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml ./src/Minimal.DICE.fst -cc clang -no-prefix Hacl.Frodo.Random -bundle Hacl.Spec.*,Spec.*[rename=Hacl_Spec] -bundle Lib.*[rename=Hacl_Lib] -drop Lib.IntVector.Intrinsics -fparentheses -fno-shadow -fcurly-braces -bundle LowStar.* -bundle Prims,C.Failure,C,C.String,C.Loops,Spec.Loops,C.Endianness,FStar.*[rename=Hacl_Kremlib] -bundle Meta.* -minimal -add-include "kremlin/internal/types.h" -add-include "kremlin/lowstar_endianness.h" -add-include <string.h> -drop WasmSupport -tmpdir ./out -I ./src -add-include "kremlin/internal/compat.h" -I /home/zhetao/Sources/kremlin/include -I /home/zhetao/Sources/kremlin/kremlib/dist/generic -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -I /home/zhetao/Sources/kremlin/kremlib -o dice.exe
  F* version: 71c0a6aa
  KreMLin version: fe104c22
 */

#include "Minimal_Hardware.h"

Spec_Hash_Definitions_hash_alg Minimal_Hardware_alg = Spec_Hash_Definitions_SHA2_256;

uint32_t Minimal_Hardware_digest_len = (uint32_t)32U;

uint32_t Minimal_Hardware_cdi_len = (uint32_t)32U;

#define FStar_Pervasives_Mkdtuple3 0

typedef uint8_t FStar_Pervasives_dtuple3_____________tags;

typedef void **FStar_Pervasives_dtuple3____________;

