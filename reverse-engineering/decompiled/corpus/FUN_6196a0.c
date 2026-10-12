/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x6196a0; label: FUN_006196a0
 */

int FUN_006196a0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  FUN_005d0e80(DAT_02912b38);
  iVar1 = FUN_006e6b90();
  FUN_005d0e80(DAT_02912b38);
  FUN_005d0eb0(DAT_02912b38);
  iVar2 = FUN_006e6b90();
  bVar3 = DAT_02912eb8 == 0;
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (((bVar3) &&
      (FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,iVar1 * 8,
                    *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                    (&DAT_02900c70)[DAT_02912e90]), DAT_02912eb8 == 0)) &&
     (FUN_005d0fb0(DAT_02912b38), DAT_02912eb8 == 0)) {
    FUN_005d1060(DAT_02912b38,*(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4))
    ;
  }
  if (*(char *)(param_2 + 0x12) == '\x10') {
    iVar2 = iVar2 + param_4 * 8;
  }
  else {
    iVar2 = iVar2 + param_4 * 8;
    if (*(char *)(param_2 + 0x12) != ' ') {
      FUN_00618310(DAT_02912b38,iVar2,*(undefined4 *)(param_2 + 0x24));
      return iVar1;
    }
  }
  FUN_00618310(DAT_02912b38,iVar2,*(undefined4 *)(param_2 + 0x24));
  return iVar1;
}

