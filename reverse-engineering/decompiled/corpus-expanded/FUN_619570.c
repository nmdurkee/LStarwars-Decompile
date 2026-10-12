/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619570; label: FUN_00619570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619570(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  
  if ((*(byte *)(param_1 + 0x11) & 2) != 0) {
    param_2 = param_2 * 0x10;
    iVar2 = in_ECX * 8;
    iVar5 = param_3 * 0x10;
    if (DAT_02912eb8 == 0) {
      iVar1 = iVar2 + in_EAX * 8;
      iVar3 = ((int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2) + param_2;
      FUN_005db5b0(param_2,iVar2,iVar3,iVar1,*(undefined4 *)(param_1 + 0x28),
                   (&DAT_02900c70)[DAT_02912e90]);
      if (DAT_02912eb8 == 0) {
        iVar4 = iVar5 / 2 + param_2;
        FUN_005db5b0(iVar3,iVar2,iVar4,iVar1,*(undefined4 *)(param_1 + 0x28),
                     (&DAT_02900c70)[DAT_02912e90]);
        if (DAT_02912eb8 == 0) {
          iVar3 = ((int)(param_3 * 0x30 + (param_3 * 0x30 >> 0x1f & 3U)) >> 2) + param_2;
          FUN_005db5b0(iVar4,iVar2,iVar3,iVar1,*(undefined4 *)(param_1 + 0x28),
                       (&DAT_02900c70)[DAT_02912e90]);
          if (DAT_02912eb8 == 0) {
            FUN_005db5b0(iVar3,iVar2,param_2 + iVar5,iVar1,*(undefined4 *)(param_1 + 0x28),
                         (&DAT_02900c70)[DAT_02912e90]);
          }
        }
      }
    }
  }
  return;
}

