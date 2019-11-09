/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __FStar_H
#define __FStar_H

#include "Prims.h"


#define Prims_Nil 0
#define Prims_Cons 1

typedef uint8_t Prims_list__bool_tags;

Prims_int FStar_UInt_logand(Prims_pos n, Prims_int a, Prims_int b);

Prims_int FStar_UInt_logor(Prims_pos n, Prims_int a, Prims_int b);

Prims_int FStar_Int_op_At_Percent(Prims_int v1, Prims_int p);

Prims_int FStar_Int_logand(Prims_pos n1, Prims_int a, Prims_int b);

Prims_int FStar_Int_logor(Prims_pos n1, Prims_int a, Prims_int b);

extern Prims_int FStar_Int128_v(FStar_Int128_t x);

extern Prims_int FStar_UInt64_v(uint64_t x);

extern Prims_int FStar_UInt32_v(uint32_t x);

extern Prims_int FStar_UInt8_v(uint8_t x);

extern Prims_int FStar_Int8_v(int8_t x);

extern Prims_int FStar_Int32_v(int32_t x);

extern Prims_int FStar_UInt16_v(uint16_t x);

extern Prims_int FStar_Int16_v(int16_t x);

extern Prims_int FStar_Int64_v(int64_t x);

#define __FStar_H_DEFINED
#endif
