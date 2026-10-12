/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x6132f0; label: FUN_006132f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006132f0(undefined2 param_1,float param_2,float param_3)

{
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_LAB_0076ac5c;
  if (param_2 < 0.1) {
    param_2 = 0.1;
  }
  if ((0.0 < param_3) && (param_3 < 0.1)) {
    param_3 = 0.1;
  }
  *(short *)(in_ECX + 3) = (short)_DAT_0080f284;
  _DAT_0080f284 = _DAT_0080f284 + 1;
  *(undefined2 *)((int)in_ECX + 0xe) = param_1;
  *(undefined2 *)(in_ECX + 5) = 0;
  *(undefined2 *)((int)in_ECX + 0x16) = 0;
  param_2._0_2_ = (undefined2)(int)ROUND(param_2 * 1000.0);
  *(undefined2 *)(in_ECX + 4) = param_2._0_2_;
  param_2._0_2_ = (undefined2)(int)ROUND(param_3 * 1000.0);
  *(undefined2 *)((int)in_ECX + 0x12) = param_2._0_2_;
  return;
}

