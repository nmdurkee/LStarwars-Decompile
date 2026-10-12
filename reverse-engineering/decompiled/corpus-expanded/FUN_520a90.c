/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x520a90; label: FUN_00520a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00520a90(float param_1,float *param_2,float *param_3,float param_4,float param_5,
                 byte param_6,float *param_7)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_38;
  int local_34;
  int local_30;
  float *local_2c;
  float local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_4;
  
  iVar9 = *(int *)((int)param_1 + 0x15c);
  if (iVar9 != 0) {
    local_20 = iVar9;
    FUN_00520a00(&local_38,param_3);
    iVar8 = local_30;
    local_2c = (float *)(iVar9 + 0x1c);
    local_c = (*(float *)(local_38 + 4) - *(float *)(local_30 + 4)) / *(float *)(iVar9 + 0x1c);
    local_4 = (*(float *)(local_38 + 0xc) - *(float *)(local_30 + 0xc)) / *(float *)(iVar9 + 0x1c);
    if ((param_6 & 2) != 0) {
      param_4 = *local_2c * param_4;
    }
    param_4 = (*param_2 - *(float *)(local_30 + 4)) * local_c +
              (param_2[2] - *(float *)(local_30 + 0xc)) * local_4 + param_4;
    if ((*local_2c < param_4) || (param_4 < 0.0)) {
      local_24 = -1;
      local_28 = -3.4028235e+38;
      local_34 = local_38;
      if (param_4 < 0.0) {
        local_34 = local_30;
      }
      local_10 = (float)(uint)*(byte *)(local_34 + 0x28);
      iVar9 = 0;
      if (local_10 != 0.0) {
        iVar2 = *(int *)(local_34 + 0x34);
        do {
          if (local_20 != *(int *)(iVar2 + iVar9 * 4)) {
            iVar7 = FUN_00520a00(&local_1c,param_3);
            iVar3 = *(int *)(*(int *)(local_34 + 0x34) + iVar9 * 4);
            local_14 = *(float *)(iVar3 + 0x1c);
            local_c = (*(float *)(local_1c + 4) - *(float *)(local_18 + 4)) / local_14;
            local_4 = (*(float *)(local_1c + 0xc) - *(float *)(local_18 + 0xc)) / local_14;
            if (((*(uint *)(iVar3 + iVar7 * 4) & 0xc0000000) == 0) &&
               (local_14 = *param_3 * local_c + param_3[2] * local_4, local_28 < local_14)) {
              local_28 = local_14;
              local_24 = iVar9;
            }
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)local_10);
        if (local_24 != -1) {
          local_10 = *local_2c;
          iVar9 = *(int *)(iVar2 + local_24 * 4);
          if (0.0 <= param_4) {
            param_4 = param_4 - local_10;
          }
          else {
            param_4 = param_4 + *(float *)(iVar9 + 0x1c);
          }
          FUN_00520a00(&local_38,param_3);
          local_2c = (float *)(iVar9 + 0x1c);
          local_c = (*(float *)(local_38 + 4) - *(float *)(local_30 + 4)) / *(float *)(iVar9 + 0x1c)
          ;
          local_4 = (*(float *)(local_38 + 0xc) - *(float *)(local_30 + 0xc)) /
                    *(float *)(iVar9 + 0x1c);
          iVar8 = local_30;
        }
      }
    }
    param_4 = param_4 / *local_2c;
    fVar4 = 0.0;
    if ((0.0 < param_4) && (fVar4 = param_4, 1.0 <= param_4)) {
      fVar4 = 1.0;
    }
    fVar1 = *local_2c;
    fVar5 = *(float *)(iVar8 + 0x10) * (1.0 - fVar4) + *(float *)(local_38 + 0x10) * fVar4;
    if ((param_6 & 1) != 0) {
      param_5 = fVar5 * param_5;
    }
    fVar6 = -fVar5;
    param_1 = fVar6;
    if (fVar6 < param_5) {
      param_1 = param_5;
    }
    if ((param_1 < fVar5) && (fVar5 = param_5, param_5 <= fVar6)) {
      fVar5 = fVar6;
    }
    *param_7 = local_4 * fVar5 + fVar4 * fVar1 * local_c + *(float *)(iVar8 + 4);
    param_7[1] = *(float *)(local_38 + 8) * fVar4 + *(float *)(iVar8 + 8) * (1.0 - fVar4);
    param_7[2] = (*(float *)(iVar8 + 0xc) + fVar4 * fVar1 * local_4) - fVar5 * local_c;
    return;
  }
  iVar9 = *(int *)((int)param_1 + 0xd0);
  *param_7 = *(float *)(iVar9 + 0x5c);
  param_7[1] = *(float *)(iVar9 + 0x60);
  param_7[2] = *(float *)(iVar9 + 100);
  return;
}

