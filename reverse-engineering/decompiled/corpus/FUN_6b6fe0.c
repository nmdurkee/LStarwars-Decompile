/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6fe0; label: FUN_006b6fe0
 */

void FUN_006b6fe0(int param_1,int *param_2,int param_3,int param_4,float *param_5,int param_6,
                 float param_7,float param_8)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  float local_7c;
  float local_78;
  int local_74;
  int local_70;
  int local_6c;
  uint local_68;
  int local_64;
  int local_60;
  float local_5c;
  float local_58;
  undefined4 uStack_54;
  undefined8 local_50;
  double local_48;
  
  local_5c = 3.1415927 / (float)param_4;
  iVar8 = 0;
  if (0 < param_6) {
    do {
      local_50 = (double)(param_5[iVar8] * 40.743668 - 0.5);
      local_70 = (int)ROUND(local_50);
      iVar3 = iVar8 + 1;
      param_5[iVar8] =
           (param_5[iVar8] * 40.743668 - (float)local_70) *
           (*(float *)(&DAT_0081f4ac + local_70 * 4) - *(float *)(&DAT_0081f4a8 + local_70 * 4)) +
           *(float *)(&DAT_0081f4a8 + local_70 * 4);
      iVar8 = iVar3;
    } while (iVar3 < param_6);
  }
  iVar8 = 0;
  if (0 < param_3) {
    local_60 = param_6 >> 1;
    local_50 = (double)(CONCAT44(local_50._4_4_,param_6) & 0xffffffff00000001);
    iVar3 = 0;
    piVar4 = param_2;
    do {
      local_64 = *piVar4;
      local_78 = 0.70710677;
      local_7c = 0.70710677;
      fVar1 = (float)local_64 * local_5c * 40.743668;
      local_48 = (double)fVar1;
      local_6c = (int)ROUND((double)(fVar1 - 0.5));
      fVar2 = (fVar1 - (float)local_6c) *
              (*(float *)(&DAT_0081f4ac + local_6c * 4) - *(float *)(&DAT_0081f4a8 + local_6c * 4))
              + *(float *)(&DAT_0081f4a8 + local_6c * 4);
      _local_58 = CONCAT44((int)((ulonglong)(double)(fVar1 - 0.5) >> 0x20),fVar2);
      pfVar5 = param_5;
      iVar7 = local_60;
      do {
        pfVar6 = pfVar5 + 2;
        iVar7 = iVar7 + -1;
        local_7c = (*pfVar5 - fVar2) * local_7c;
        local_78 = (pfVar5[1] - fVar2) * local_78;
        pfVar5 = pfVar6;
      } while (iVar7 != 0);
      if ((int)local_50 == 0) {
        local_7c = local_7c * local_7c * (fVar2 + 1.0);
      }
      else {
        local_7c = (*pfVar6 - fVar2) * local_7c;
        local_7c = local_7c * local_7c;
        fVar2 = fVar2 * fVar2;
      }
      dVar9 = _frexp((double)(local_7c + local_78 * local_78 * (1.0 - fVar2)),&local_74);
      fVar1 = (float)dVar9 * 64.0 - 32.0;
      local_70 = (int)ROUND(fVar1 - 0.5);
      local_68 = (uint)ROUND((((fVar1 - (float)local_70) *
                               (*(float *)(&DAT_0081f6b4 + local_70 * 4) -
                               *(float *)(&DAT_0081f6b0 + local_70 * 4)) +
                              *(float *)(&DAT_0081f6b0 + local_70 * 4)) * param_7 *
                              *(float *)(&DAT_0081f7b8 + (local_74 + param_6) * 4) - param_8) * -8.0
                             - 0.5);
      if ((int)local_68 < 0) {
        fVar1 = 1.0;
      }
      else if ((int)local_68 < 0x460) {
        fVar1 = *(float *)(&DAT_0081f8d0 + (local_68 & 0x1f) * 4) *
                *(float *)(&DAT_0081f840 + ((int)local_68 >> 5) * 4);
      }
      else {
        fVar1 = 0.0;
      }
      do {
        iVar8 = iVar8 + 1;
        *(float *)(iVar3 + param_1) = *(float *)(iVar3 + param_1) * fVar1;
        iVar3 = iVar8 * 4;
        piVar4 = param_2 + iVar8;
      } while (param_2[iVar8] == local_64);
    } while (iVar8 < param_3);
  }
  return;
}

