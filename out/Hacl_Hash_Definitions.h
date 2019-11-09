/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __Hacl_Hash_Definitions_H
#define __Hacl_Hash_Definitions_H

#include "Spec_Hash_Definitions.h"


uint32_t Hacl_Hash_Definitions_word_len(Spec_Hash_Definitions_hash_alg a);

uint32_t Hacl_Hash_Definitions_block_len(Spec_Hash_Definitions_hash_alg a);

uint32_t Hacl_Hash_Definitions_hash_word_len(Spec_Hash_Definitions_hash_alg a);

uint32_t Hacl_Hash_Definitions_hash_len(Spec_Hash_Definitions_hash_alg a);

#define __Hacl_Hash_Definitions_H_DEFINED
#endif
