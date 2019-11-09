/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __C_H
#define __C_H




extern void portable_exit(int32_t uu____53);

extern char char_of_uint8(uint8_t uu____83);

extern uint8_t uint8_of_char(char uu____93);

bool uu___is_EXIT_SUCCESS(exit_code projectee);

bool uu___is_EXIT_FAILURE(exit_code projectee);

extern void print_bytes(uint8_t *b, uint32_t len);

#define __C_H_DEFINED
#endif
