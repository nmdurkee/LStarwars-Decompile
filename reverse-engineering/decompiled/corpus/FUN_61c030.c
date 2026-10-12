/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61c030; label: FUN_0061c030
 */

int FUN_0061c030(undefined4 param_1,float param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  float10 fVar10;
  float local_20 [4];
  float afStack_10 [2];
  double local_8;
  
  iVar5 = (int)param_2;
  fVar1 = 0.5 / *(float *)((int)param_2 + 0x68);
  iVar9 = *(int *)((int)param_2 + 100);
  *(int *)((int)param_2 + 0x1c) = param_3;
  *(int *)((int)param_2 + 0x20) = param_4;
  fVar2 = *(float *)((int)param_2 + 0x4c + iVar9 * 4) - fVar1;
  fVar1 = *(float *)((int)param_2 + 0x54 + iVar9 * 4) - fVar1;
  fVar3 = 1.0 / *(float *)((int)param_2 + 0x68);
  param_2 = fVar2;
  if (fVar2 < 0.0) {
    param_2 = 0.0;
  }
  fVar4 = 1.0 - fVar3;
  if ((param_2 <= fVar4) && (fVar4 = fVar2, fVar2 < 0.0)) {
    param_2 = 0.0;
    fVar4 = param_2;
  }
  local_20[0] = fVar1;
  if (fVar1 < 0.0) {
    local_20[0] = 0.0;
  }
  fVar2 = 1.0 - fVar3;
  if ((local_20[0] <= fVar2) && (fVar2 = fVar1, fVar1 < 0.0)) {
    local_20[0] = 0.0;
    fVar2 = local_20[0];
  }
  pfVar8 = (float *)(iVar5 + 0x54);
  iVar6 = 0;
  do {
    fVar1 = (pfVar8[-2] - fVar4) / fVar3;
    *(float *)((int)&local_8 + iVar6) = fVar1;
    param_2 = fVar1;
    if (fVar1 < 0.0) {
      param_2 = 0.0;
    }
    if (param_2 <= 1.0) {
      param_2 = fVar1;
      if (fVar1 < 0.0) {
        param_2 = 0.0;
      }
    }
    else {
      param_2 = 1.0;
    }
    *(float *)((int)&local_8 + iVar6) = param_2;
    fVar1 = (*pfVar8 - fVar2) / fVar3;
    *(float *)((int)afStack_10 + iVar6) = fVar1;
    param_2 = fVar1;
    if (fVar1 < 0.0) {
      param_2 = 0.0;
    }
    if (param_2 <= 1.0) {
      param_2 = fVar1;
      if (fVar1 < 0.0) {
        param_2 = 0.0;
      }
    }
    else {
      param_2 = 1.0;
    }
    iVar7 = iVar6 + 4;
    *(float *)((int)afStack_10 + iVar6) = param_2;
    pfVar8 = pfVar8 + 1;
    iVar6 = iVar7;
  } while (iVar7 < 8);
  local_20[1] = -1.1708845e-38;
  local_20[0] = -1.1708845e-38;
  local_20[2] = fVar3;
  local_20[3] = fVar3;
  local_20[iVar9] = -2.3509886e-38;
  if (DAT_02912eb8 == 0) {
    FUN_005dba30(param_3 << 4,param_4 * 8,param_5 << 4,param_5 * 8,fVar4,fVar2,local_20[2] + fVar4,
                 fVar2 + fVar3,0x80808080,*(undefined4 *)(iVar5 + 0x60));
  }
  iVar9 = 0;
  do {
    if (DAT_02912eb8 == 0) {
      local_20[3] = (float)param_4;
      iVar6 = FUN_006e6b90(*(undefined4 *)((int)local_20 + iVar9),DAT_02900c70);
      local_20[3] = (float)FUN_006e6b90((param_3 + param_5) * 0x10 + -0x10,iVar6 * 8);
      iVar6 = FUN_006e6b90();
      FUN_005db5b0(param_3 << 4,iVar6 * 8);
      if (DAT_02912eb8 == 0) {
        iVar6 = FUN_006e6b90();
        FUN_005db5b0(iVar6 << 4,param_4 * 8);
      }
    }
    iVar9 = iVar9 + 4;
  } while (iVar9 < 8);
  FUN_005d0e80();
  iVar9 = FUN_006e6b90();
  fVar10 = (float10)FUN_005d0e80(DAT_02912b38);
  local_8 = (double)(fVar10 * (float10)0.125);
  FUN_005d0eb0();
  iVar6 = FUN_006e6b90();
  if (((DAT_02912eb8 == 0) &&
      (FUN_005db880(param_3 << 4,(param_4 + param_5) * 8,param_5 << 4,(iVar9 >> 3) * 8,
                    *(undefined4 *)(iVar5 + 0x30 + (*(byte *)(iVar5 + 0x11) & 1) * 4),
                    (&DAT_02900c70)[DAT_02912e90]), DAT_02912eb8 == 0)) &&
     (FUN_005d0fb0(), DAT_02912eb8 == 0)) {
    FUN_005d1060(DAT_02912b38,*(undefined4 *)(iVar5 + 0x28 + (*(byte *)(iVar5 + 0x11) & 1) * 4));
  }
  FUN_00618310(DAT_02912b38,iVar6 + (param_4 + param_5) * 8,"%1.03f,%1.03f",
               (double)(*(float *)(iVar5 + 0x4c + *(int *)(iVar5 + 100) * 4) * 256.0),
               (double)(*(float *)(iVar5 + 0x54 + *(int *)(iVar5 + 100) * 4) * 256.0));
  return (iVar9 >> 3) + param_5;
}

