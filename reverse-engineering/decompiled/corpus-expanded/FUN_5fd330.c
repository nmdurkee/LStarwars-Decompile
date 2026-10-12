/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd330; label: FUN_005fd330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fd330(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  _DAT_0080e190 = 0x3f800000;
  puVar5 = &DAT_0280d340;
  for (iVar4 = 0x10; uVar3 = _DAT_0280d364, uVar2 = _DAT_0280d348, uVar1 = DAT_0280d344, iVar4 != 0;
      iVar4 = iVar4 + -1) {
    *puVar5 = *param_1;
    param_1 = param_1 + 1;
    puVar5 = puVar5 + 1;
  }
  DAT_0280d344 = _DAT_0280d350;
  _DAT_0280d350 = uVar1;
  _DAT_0280d348 = _DAT_0280d360;
  _DAT_0280d360 = uVar2;
  _DAT_0280d364 = _DAT_0280d358;
  _DAT_0280d358 = uVar3;
  puVar5 = &DAT_0280d340;
  puVar6 = &DAT_0097baf0;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}

