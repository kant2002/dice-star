/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __Lib_Buffer_H
#define __Lib_Buffer_H




#define Lib_Buffer_MUT 0
#define Lib_Buffer_IMMUT 1

typedef uint8_t Lib_Buffer_buftype;

bool Lib_Buffer_uu___is_MUT(Lib_Buffer_buftype projectee);

bool Lib_Buffer_uu___is_IMMUT(Lib_Buffer_buftype projectee);

extern void
*Lib_Buffer_sub(Lib_Buffer_buftype t, uint32_t a, void *len, uint32_t b, uint32_t start);

extern void *Lib_Buffer_index(Lib_Buffer_buftype t, uint32_t a, void *len, uint32_t b);

/*
 Operator for accessing a buffer: b.(i) 
*/
void *(*Lib_Buffer_op_Array_Access(Lib_Buffer_buftype t, uint32_t len))(void *x0, uint32_t x1);

extern void Lib_Buffer_recall(Lib_Buffer_buftype t, uint32_t a, void *len);

extern void Lib_Buffer_copy(Lib_Buffer_buftype t, uint32_t a, void **len, void *o);

extern void
Lib_Buffer_update_sub(
  Lib_Buffer_buftype t,
  uint32_t a,
  void **len,
  uint32_t dst,
  uint32_t start,
  void *n1
);

extern void
Lib_Buffer_concat2(
  Lib_Buffer_buftype t0,
  Lib_Buffer_buftype t1,
  uint32_t a,
  void *len0,
  uint32_t s0,
  void *len1,
  void **s1
);

extern void
Lib_Buffer_concat3(
  Lib_Buffer_buftype t0,
  Lib_Buffer_buftype t1,
  Lib_Buffer_buftype t2,
  uint32_t a,
  void *len0,
  uint32_t s0,
  void *len1,
  uint32_t s1,
  void *len2,
  void **s2
);

extern void
Lib_Buffer_loop_nospec(uint32_t h0, uint32_t a, void **len, void (*n1)(uint32_t x0));

extern void
Lib_Buffer_loop_nospec2(
  uint32_t h0,
  uint32_t a1,
  uint32_t a2,
  void **len1,
  void **len2,
  void (*n1)(uint32_t x0)
);

extern void
Lib_Buffer_loop_nospec3(
  uint32_t h0,
  uint32_t a1,
  uint32_t a2,
  uint32_t a3,
  void **len1,
  void **len2,
  void **len3,
  void (*n1)(uint32_t x0)
);

extern void
Lib_Buffer_loop_range_nospec(
  uint32_t h0,
  uint32_t a,
  uint32_t len,
  void **start,
  void (*n1)(uint32_t x0)
);

extern void Lib_Buffer_loop(uint32_t h0, void (*n1)(uint32_t x0));

extern void
Lib_Buffer_mapT(Lib_Buffer_buftype t, uint32_t a, void **b, void *(*clen)(void *x0), void *o);

extern void
Lib_Buffer_map2T(
  Lib_Buffer_buftype t,
  uint32_t a1,
  void **a2,
  void *(*b)(void *x0, void *x1),
  void *clen,
  void *o
);

extern void
Lib_Buffer_mapiT(
  Lib_Buffer_buftype t,
  uint32_t a,
  void **b,
  void *(*clen)(uint32_t x0, void *x1),
  void *o
);

extern void
Lib_Buffer_map_blocks_multi(
  Lib_Buffer_buftype t,
  uint32_t a,
  uint32_t h0,
  void *blocksize,
  void **nb,
  void (*inp)(uint32_t x0)
);

extern void
Lib_Buffer_map_blocks(
  Lib_Buffer_buftype t,
  uint32_t a,
  uint32_t h0,
  void *len,
  void **blocksize,
  void (*inp)(uint32_t x0),
  void (*output)(uint32_t x0)
);

#define __Lib_Buffer_H_DEFINED
#endif
