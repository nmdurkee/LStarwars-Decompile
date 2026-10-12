/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x559430; label: FUN_00559430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00559430(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0093b1f0 = PTR_s_GizObstacle_00802710;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0093b1f0;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0093b204 = 0;
  _DAT_0093b210 = 0;
  _DAT_0093b230 = 0;
  _DAT_0093b238 = 0;
  DAT_0093b1f4 = &DAT_007516c0;
  _DAT_0093b1f8 = 0x70;
  _DAT_0093b1fc = FUN_005586f0;
  _DAT_0093b200 = FUN_00558710;
  _DAT_0093b208 = FUN_00558070;
  _DAT_0093b20c = FUN_00558670;
  _DAT_0093b214 = FUN_00558770;
  _DAT_0093b218 = FUN_00558780;
  _DAT_0093b21c = FUN_00558830;
  _DAT_0093b220 = FUN_00558880;
  _DAT_0093b224 = &LAB_00557580;
  _DAT_0093b228 = FUN_00559300;
  _DAT_0093b22c = FUN_00557630;
  _DAT_0093b234 = FUN_00557670;
  _DAT_0093b23c = FUN_00558ba0;
  _DAT_0093b240 = &LAB_00558c60;
  _DAT_0093b244 = &LAB_00559010;
  _DAT_0093b248 = FUN_00558890;
  _DAT_0093b24c = FUN_005588b0;
  _DAT_0093b250 = FUN_005589b0;
  _DAT_0093b254 = &LAB_005577e0;
  _DAT_0093b258 = FUN_005574b0;
  _DAT_0093b25c = FUN_00557100;
  _DAT_0093b260 = FUN_005573e0;
  _DAT_0093b264 = &LAB_00557430;
  DAT_00802644 = param_1;
  return &DAT_0093b1f0;
}

