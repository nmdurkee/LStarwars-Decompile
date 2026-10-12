/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x626320; label: FUN_00626320
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00626320(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  undefined4 local_10 [2];
  double local_8;
  
  fVar3 = (float)param_4;
  *(int *)(param_2 + 0x20) = param_4;
  local_10[0] = 0xff000000;
  local_10[1] = 0xffffffff;
  *(int *)(param_2 + 0x1c) = param_3;
  iVar4 = FUN_0061ec40();
  *(uint *)(param_2 + 0x54) =
       *(uint *)(param_2 + 0x54) ^ (iVar4 * 2 ^ *(uint *)(param_2 + 0x54)) & 2;
  if ((DAT_02912eb8 == 0) && (FUN_005d0fb0(DAT_02912b38), DAT_02912eb8 == 0)) {
    FUN_005d1060(DAT_02912b38,*(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4))
    ;
  }
  fVar7 = (float10)FUN_005d0e80(DAT_02912b38);
  fVar1 = (float)(((float10)1 / (float10)_DAT_0080f564) * fVar7 * (float10)1.25);
  fVar8 = (float10)FUN_005d0e80(DAT_02912b38);
  fVar9 = (float10)FUN_005d0eb0(DAT_02912b38);
  fVar10 = (float10)_DAT_0080f564;
  fVar7 = (float10)fVar1;
  if (param_1 != 0) {
    if (param_1 != DAT_02912eac) {
      param_1 = FUN_0061f050();
      fVar7 = extraout_ST0;
    }
    if (param_1 != 0) {
      FUN_006187a0((float)param_3,fVar3,(float)param_5,(float)fVar7);
      fVar7 = (float10)fVar1;
    }
  }
  iVar4 = 0;
  if (0 < *(int *)(param_2 + 100)) {
    local_8 = (double)(fVar7 - (float10)2.0);
    do {
      if (DAT_02912eb8 == 0) {
        uVar5 = FUN_006e6b90();
        uVar6 = FUN_006e6b90(0xff000000,DAT_02900c70);
        uVar6 = FUN_006e6b90(uVar5,uVar6);
        FUN_005db5b0(uVar5,uVar6);
        fVar7 = (float10)fVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_2 + 100));
  }
  *(float *)(param_2 + 0x58) = (float)(fVar7 - (float10)2.0);
  *(float *)(param_2 + 0x5c) =
       (float)((float10)param_3 + (float10)*(int *)(param_2 + 100) * (fVar7 - (float10)2.0)) + 1.0;
  *(float *)(param_2 + 0x60) = fVar3 + 1.0;
  if (*(int *)(param_2 + 0x4c) != 0) {
    if (DAT_02912eb8 == 0) {
      uVar5 = FUN_006e6b90(0xff000000,(&DAT_02900c70)[DAT_02912e94]);
      uVar5 = FUN_006e6b90(uVar5);
      uVar5 = FUN_006e6b90(uVar5);
      uVar5 = FUN_006e6b90(uVar5);
      FUN_005dbbf0(uVar5);
    }
    uVar2 = *(uint *)(param_2 + 0x54);
    if ((uVar2 & 1) == 0) {
      if (DAT_02912eb8 == 0) {
        uVar5 = FUN_006e6b90();
        uVar6 = FUN_006e6b90(uVar5,local_10[uVar2 >> 1 & 1],DAT_02900c70);
        uVar5 = FUN_006e6b90(uVar5,uVar6);
        FUN_005db5b0(uVar5);
        if (DAT_02912eb8 == 0) {
          uVar5 = FUN_006e6b90();
          uVar6 = FUN_006e6b90(local_10[*(uint *)(param_2 + 0x54) >> 1 & 1],DAT_02900c70);
          uVar6 = FUN_006e6b90(uVar5,uVar6);
          FUN_005db5b0(uVar5,uVar6);
        }
      }
    }
    else if (DAT_02912eb8 == 0) {
      uVar5 = FUN_006e6b90();
      uVar6 = FUN_006e6b90(uVar5,local_10[uVar2 >> 1 & 1],DAT_02900c70);
      uVar5 = FUN_006e6b90(uVar5,uVar6);
      FUN_005db5b0(uVar5);
    }
  }
  fVar1 = *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58) + 2.0;
  FUN_00618550(DAT_02912b38,fVar1,
               (float)(((float10)1 / fVar10) * (fVar9 + (float10)(double)(fVar8 * (float10)0.125)))
               + fVar3,0x10,fVar1,(float)param_5 - (*(float *)(param_2 + 0x58) - 2.0),
               *(undefined4 *)(param_2 + 0x24));
  FUN_006e6b90();
  return;
}

