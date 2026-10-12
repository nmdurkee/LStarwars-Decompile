/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fcbc0; label: FUN_005fcbc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fcbc0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00986930;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  _DAT_00986970 = *param_2;
  _DAT_00986974 = param_2[1];
  _DAT_00986978 = param_2[2];
  DAT_009868c0 = DAT_009868c0 + 1;
  _DAT_009868c4 = _DAT_009868c4 + 1;
  _DAT_009868d4 = 0;
  return;
}

