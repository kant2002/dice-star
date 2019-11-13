/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.DICE ./src/Minimal.DICE.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "Lib_Buffer.h"

bool Lib_Buffer_uu___is_MUT(Lib_Buffer_buftype projectee)
{
  switch (projectee)
  {
    case Lib_Buffer_MUT:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

bool Lib_Buffer_uu___is_IMMUT(Lib_Buffer_buftype projectee)
{
  switch (projectee)
  {
    case Lib_Buffer_IMMUT:
      {
        return true;
      }
    default:
      {
        return false;
      }
  }
}

/*
 Operator for accessing a buffer: b.(i) 
*/
void *(*Lib_Buffer_op_Array_Access(Lib_Buffer_buftype t, uint32_t len))(void *x0, uint32_t x1)
{
  return Lib_Buffer_index(t, len);
}

