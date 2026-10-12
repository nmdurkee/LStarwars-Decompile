/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x61fd70; label: FUN_0061fd70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0061fd70(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  FUN_005d0e80(DAT_02912b38);
  iVar1 = FUN_006e6b90();
  iVar1 = iVar1 >> 3;
  FUN_005d0e80(DAT_02912b38);
  FUN_005d0eb0(DAT_02912b38);
  iVar2 = FUN_006e6b90();
  bVar5 = DAT_02912eb8 == 0;
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (bVar5) {
    FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,iVar1 << 4,
                 *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),DAT_02900c70)
    ;
    if (DAT_02912eb8 == 0) {
      FUN_005d0fb0(DAT_02912b38);
      if (DAT_02912eb8 == 0) {
        FUN_005d1060(DAT_02912b38,
                     *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4));
      }
    }
  }
  iVar2 = iVar2 + param_4 * 8;
  FUN_00618310(DAT_02912b38,iVar2,*(undefined4 *)(param_2 + 0x24));
  uVar3 = FUN_006e6b90();
  FUN_00618310(DAT_02912b38,iVar2,*(undefined4 *)(param_2 + 100),uVar3);
  param_4 = param_4 + iVar1;
  FUN_00618920(param_3,param_4,param_5,iVar1,0,0x3f800000);
  if (DAT_02912eb8 == 0) {
    iVar2 = (iVar1 + param_4) * 8 + -8;
    iVar4 = FUN_006e6b90();
    param_4 = param_4 * 8;
    FUN_005db5b0(iVar4 << 4,param_4,iVar4 << 4,iVar2,
                 *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4),DAT_02900c70)
    ;
    if (DAT_02912eb8 == 0) {
      iVar4 = FUN_006e6b90();
      FUN_005db5b0(iVar4 << 4,param_4,iVar4 << 4,iVar2,
                   *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                   DAT_02900c70);
      if (DAT_02912eb8 == 0) {
        iVar4 = FUN_006e6b90();
        FUN_005db5b0(iVar4 << 4,param_4,iVar4 << 4,iVar2,
                     *(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                     DAT_02900c70);
      }
    }
  }
  return iVar1 * 2;
}

