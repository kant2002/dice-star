/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __Spec_Hash_Incremental_H
#define __Spec_Hash_Incremental_H

#include "Spec_Agile_Hash.h"
#include "Spec_Hash_PadFinish.h"
#include "Spec_Hash_Definitions.h"
#include "Lib_ByteSequence.h"
#include "Prims.h"
#include "FStar.h"


Prims_list__Lib_IntTypes_sec_int_t____
*Spec_Hash_Incremental_update_last(
  Spec_Hash_Definitions_hash_alg a,
  Prims_list__Lib_IntTypes_sec_int_t____ *hash1,
  Prims_int prevlen,
  Prims_list__Lib_IntTypes_sec_int_t____ *input
);

Prims_list__Lib_IntTypes_sec_int_t____
*Spec_Hash_Incremental_hash_incremental(
  Spec_Hash_Definitions_hash_alg a,
  Prims_list__Lib_IntTypes_sec_int_t____ *input
);

#define __Spec_Hash_Incremental_H_DEFINED
#endif
