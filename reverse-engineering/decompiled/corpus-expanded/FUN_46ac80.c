/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46ac80; label: FUN_0046ac80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ac80(int param_1)

{
  float fVar1;
  int iVar2;
  
  if (*(float *)(param_1 + 0xdec) <= 0.0) {
    return;
  }
  fVar1 = *(float *)(param_1 + 0xdec) - _DAT_00925018;
  *(float *)(param_1 + 0xdec) = fVar1;
  if (fVar1 < 0.0 != (fVar1 == 0.0)) {
    FUN_00547930(0x52,0,0,0);
    return;
  }
  FUN_00547930(0x51,0,0,0);
  iVar2 = FUN_0054fa60(0);
  FUN_0054ac00(param_1,(float)iVar2 * 1.5259022e-05 * 0.5);
  return;
}

