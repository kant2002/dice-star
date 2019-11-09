/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -no-prefix Minimal.Main ./src/Minimal.Main.fst -skip-compilation -tmpdir ./out -I ./src -I /home/zhetao/Sources/hacl-star/specs -I /home/zhetao/Sources/hacl-star/specs/lemmas -I /home/zhetao/Sources/hacl-star/code/hash -I /home/zhetao/Sources/hacl-star/code/hkdf -I /home/zhetao/Sources/hacl-star/code/hmac -I /home/zhetao/Sources/hacl-star/code/curve25519 -I /home/zhetao/Sources/hacl-star/code/ed25519 -I /home/zhetao/Sources/hacl-star/lib -I /home/zhetao/Sources/hacl-star/providers/evercrypt -warn-error +11
  F* version: 953b2211
  KreMLin version: e324b7e6
 */

#include "kremlib.h"
#ifndef __Lib_LoopCombinators_H
#define __Lib_LoopCombinators_H




extern void
*Lib_LoopCombinators_repeat_left(
  Prims_int lo,
  Prims_int hi,
  void *(*a)(Prims_int x0, void *x1),
  void *f
);

extern void
*Lib_LoopCombinators_repeat_left_all_ml(
  Prims_int lo,
  Prims_int hi,
  void *(*a)(Prims_int x0, void *x1),
  void *f
);

extern void
*Lib_LoopCombinators_repeat_right(
  Prims_int lo,
  Prims_int hi,
  void *(*a)(Prims_int x0, void *x1),
  void *f
);

extern void
*Lib_LoopCombinators_repeat_right_all_ml(
  Prims_int lo,
  Prims_int hi,
  void *(*a)(Prims_int x0, void *x1),
  void *f
);

extern void
*Lib_LoopCombinators_repeat_gen(Prims_int n1, void *(*a)(Prims_int x0, void *x1), void *f);

extern void
*Lib_LoopCombinators_repeat_gen_all_ml(
  Prims_int n1,
  void *(*a)(Prims_int x0, void *x1),
  void *f
);

extern void
*Lib_LoopCombinators_repeat_gen_inductive(
  Prims_int n1,
  void *(*a)(Prims_int x0, void *x1),
  void *pred
);

#define __Lib_LoopCombinators_H_DEFINED
#endif
