/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619800; label: FUN_00619800
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00619800(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float local_c;
  double local_8;
  
  FUN_005d0e80(DAT_02912b38);
  iVar2 = FUN_006e6b90();
  iVar2 = iVar2 >> 3;
  fVar4 = (float10)FUN_005d0e80(DAT_02912b38);
  local_8 = (double)(fVar4 * (float10)0.125);
  FUN_005d0eb0(DAT_02912b38);
  local_c = (float)FUN_006e6b90();
  bVar3 = DAT_02912eb8 == 0;
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (((bVar3) &&
      (FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,iVar2 * 8,
                    *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                    (&DAT_02900c70)[DAT_02912e90]), DAT_02912eb8 == 0)) &&
     (FUN_005d0fb0(DAT_02912b38), DAT_02912eb8 == 0)) {
    FUN_005d1060(DAT_02912b38,*(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4))
    ;
  }
  FUN_00618310(DAT_02912b38,(int)local_c + param_4 * 8,*(undefined4 *)(param_2 + 0x24));
  uVar5 = _DAT_02912e9c;
  uVar6 = _DAT_02912ea0;
  uVar1 = _DAT_02912e98;
  if (*(int *)(param_2 + 8) != 7) {
    uVar5 = 0;
    uVar6 = _DAT_02912ea4;
    uVar1 = 0;
  }
  FUN_00618180(uVar1,uVar5,uVar6,&local_c);
  local_8 = (double)(longlong)ROUND(local_c * 255.0);
  FUN_00618920(param_5 + -0x2d + param_3,param_4,0x28,iVar2,0,0x3f800000);
  return iVar2;
}

