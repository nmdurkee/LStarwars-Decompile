/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fcc10; label: FUN_005fcc10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fcc10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00986930;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  _DAT_00986970 = *param_3;
  _DAT_00986974 = param_3[1];
  _DAT_00986978 = param_3[2];
  _DAT_0098697c = *param_1;
  _DAT_00986980 = param_1[1];
  _DAT_00986984 = param_1[2];
  DAT_009868c0 = DAT_009868c0 + 1;
  _DAT_009868c4 = _DAT_009868c4 + 1;
  _DAT_009868d4 = 0;
  return;
}

