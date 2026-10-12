/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x477630; label: FUN_00477630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477630(int *param_1,int param_2,float param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 extraout_ST1;
  float local_10;
  int local_8;
  float local_4;
  
  if ((0.0 < param_3) && (-0.0 <= param_4)) {
    local_4 = 0.0;
    local_8 = 1;
    do {
      iVar4 = (int)(short)(&DAT_0087b6c4)[local_8];
      iVar1 = FUN_00594250(iVar4,*param_1,*(undefined2 *)((int)param_1 + 6));
      if (iVar1 != -1) {
        iVar2 = FUN_00594960(iVar4);
        if (iVar2 == 0) {
          iVar4 = -1;
        }
        iVar2 = 0xa6 - (uint)(local_8 != 0);
        if ((param_2 == 0) || ((&DAT_0087b6c8)[local_8] == '\0')) {
          iVar1 = *param_1 + iVar1 * 0x1c;
          FUN_0055b830(iVar4,*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),0,
                       (float)param_1[4] * _DAT_007fc318 * param_4,iVar2,param_3,param_3,1,0);
        }
        else {
          local_4 = local_4 - 0.0025;
          local_10 = _DAT_007f9360;
          if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
            local_10 = _DAT_007f9360 * 0.875;
          }
          fVar5 = (float10)(float)param_1[4] / (float10)0.675000011920929;
          local_10 = (float)((float10)local_10 * fVar5);
          fVar6 = (float10)0;
          if ((float10)(float)(&DAT_00879b0c)[local_8] <= fVar6) {
            if ((&DAT_0087955c)[local_8] != 0) {
              local_10 = (float)fVar6;
            }
          }
          else {
            fVar5 = fVar6;
            iVar3 = FUN_006e6b90();
            local_10 = (float)((extraout_ST0 -
                               ((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + extraout_ST0)
                               * (float10)0.5) * (float10)local_10);
            fVar6 = extraout_ST1;
          }
          if (fVar6 < (float10)(local_10 * param_4)) {
            iVar1 = *param_1 + iVar1 * 0x1c;
            FUN_0055b830(iVar4,(float)(fVar5 * (float10)0.009999999776482582) *
                               (float)(&DAT_029899a0)[(ushort)(&DAT_00879b58)[local_8 * 2] >> 1] +
                               *(float *)(iVar1 + 0x14),
                         *(float *)(iVar1 + 0x18) +
                         (float)(fVar5 * (float10)0.009999999776482582) *
                         (float)(&DAT_029899a0)[(ushort)(&DAT_00879b5a)[local_8 * 2] >> 1],local_4,
                         local_10 * param_4,iVar2,param_3,param_3,1,0);
          }
        }
      }
      local_8 = local_8 + -1;
    } while (-1 < local_8);
    return;
  }
  return;
}

