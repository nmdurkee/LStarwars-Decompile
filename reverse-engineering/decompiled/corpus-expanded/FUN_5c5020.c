/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c5020; label: FUN_005c5020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c5020(float *param_1)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined1 local_80 [48];
  undefined1 local_50 [16];
  undefined1 local_40 [48];
  undefined1 local_10 [16];
  
  FUN_005b5e90(local_80,*(int *)(in_ECX + 0x1c) + 4);
  FUN_005b5e90(local_40,*(int *)(in_ECX + 0x1c) + 0x44);
  FUN_005b3f50(&local_94,local_50,*(int *)(in_ECX + 0x1c) + 0x44);
  if (local_8c < 0.0) {
    FUN_005b3f50(&local_94,local_10,*(int *)(in_ECX + 0x1c) + 4);
    local_94 = local_94 * -1.0;
    local_90 = local_90 * -1.0;
    local_8c = local_8c * -1.0;
  }
  local_84 = 1.0 / local_88;
  FUN_005b3e20(&local_94,&local_94,local_84);
  local_94 = _DAT_00806b74 * local_94;
  local_90 = _DAT_00806b74 * local_90;
  local_8c = _DAT_00806b7c * local_8c;
  FUN_005b3e20(&local_94,&local_94,*(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0x88));
  fVar1 = -_DAT_00806b78;
  fVar2 = fVar1;
  if ((fVar1 <= local_94) && (fVar2 = local_94, _DAT_00806b78 < local_94)) {
    local_94 = _DAT_00806b78;
    fVar2 = local_94;
  }
  local_94 = fVar2;
  if ((local_90 < fVar1) || (fVar1 = _DAT_00806b78, _DAT_00806b78 < local_90)) {
    local_90 = fVar1;
  }
  *param_1 = local_94;
  param_1[1] = local_90;
  param_1[2] = local_8c;
  param_1[3] = 0.0;
  return;
}

