/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619a40; label: FUN_00619a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00619a40(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  FUN_005d0e80(DAT_02912b38);
  iVar1 = FUN_006e6b90();
  iVar1 = iVar1 >> 3;
  FUN_005d0e80(DAT_02912b38);
  FUN_005d0eb0(DAT_02912b38);
  iVar2 = FUN_006e6b90();
  bVar3 = DAT_02912eb8 == 0;
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (bVar3) {
    FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,iVar1 * 8,*(undefined4 *)(param_2 + 0x30),
                 (&DAT_02900c70)[DAT_02912e90]);
    if (DAT_02912eb8 == 0) {
      FUN_005d0fb0(DAT_02912b38);
      if (DAT_02912eb8 == 0) {
        FUN_005d1060(DAT_02912b38,
                     *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4));
      }
    }
  }
  FUN_00618310(DAT_02912b38,iVar2 + param_4 * 8,*(undefined4 *)(param_2 + 0x24));
  local_30 = ((param_3 - iVar1) + param_5) * 0x10 + -0x10;
  local_1c = param_4 * 8 + 0x10;
  local_14 = local_1c + (iVar1 + -3) * 8;
  local_20 = (iVar1 + -3) * 0x10 + local_30;
  local_2c = local_14 + local_1c >> 1;
  if ((*(byte *)(param_2 + 0x11) & 1) == 0) {
    local_28 = (local_20 + local_30 >> 1) + local_30 >> 1;
    local_24 = local_2c + local_14 >> 1;
    if (DAT_02912eb8 == 0) {
      local_18 = local_28;
      local_10 = local_30;
      local_c = local_2c;
      FUN_005dc200(&local_30,0,5,*(undefined4 *)(param_2 + 0x28),DAT_02900c70);
    }
  }
  else {
    local_28 = (local_20 + local_30 >> 1) + local_30 >> 1;
    local_24 = local_2c + local_14 >> 1;
    if (DAT_02912eb8 == 0) {
      local_18 = local_20;
      local_20 = local_28;
      iVar2 = local_1c;
      local_1c = local_14;
      local_14 = iVar2;
      FUN_005dc2f0(&local_30,0,4,*(undefined4 *)(param_2 + 0x28),DAT_02900c70);
      return iVar1;
    }
  }
  return iVar1;
}

