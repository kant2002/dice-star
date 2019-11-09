/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __Spec_Agile_Hash_H
#define __Spec_Agile_Hash_H

#include "Spec_Hash_Definitions.h"
#include "Lib_ByteSequence.h"


extern Prims_list__Lib_IntTypes_sec_int_t____
*Spec_Agile_Hash_init(Spec_Hash_Definitions_hash_alg a);

extern Prims_list__Lib_IntTypes_sec_int_t____
*Spec_Agile_Hash_update(
  Spec_Hash_Definitions_hash_alg a,
  Prims_list__Lib_IntTypes_sec_int_t____ *x0,
  Prims_list__Lib_IntTypes_sec_int_t____ *x1
);

typedef struct
K___FStar_Seq_Base_seq__Lib_IntTypes_sec_int_t_____FStar_Seq_Base_seq__Lib_IntTypes_sec_int_t_____s
{
  Prims_list__Lib_IntTypes_sec_int_t____ *fst;
  Prims_list__Lib_IntTypes_sec_int_t____ *snd;
}
K___FStar_Seq_Base_seq__Lib_IntTypes_sec_int_t_____FStar_Seq_Base_seq__Lib_IntTypes_sec_int_t____;

extern K___FStar_Seq_Base_seq__Lib_IntTypes_sec_int_t_____FStar_Seq_Base_seq__Lib_IntTypes_sec_int_t____
Spec_Agile_Hash_split_block(
  Spec_Hash_Definitions_hash_alg a,
  Prims_list__Lib_IntTypes_sec_int_t____ *blocks,
  Prims_int n1
);

extern Prims_list__Lib_IntTypes_sec_int_t____
*Spec_Agile_Hash_update_multi(
  Spec_Hash_Definitions_hash_alg a,
  Prims_list__Lib_IntTypes_sec_int_t____ *hash,
  Prims_list__Lib_IntTypes_sec_int_t____ *blocks
);

extern Prims_list__Lib_IntTypes_sec_int_t____
*Spec_Agile_Hash_hash(
  Spec_Hash_Definitions_hash_alg a,
  Prims_list__Lib_IntTypes_sec_int_t____ *input
);

#define __Spec_Agile_Hash_H_DEFINED
#endif
