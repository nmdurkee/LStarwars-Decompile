/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c5190; label: FUN_006c5190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006c5190(int param_1,float *param_2,undefined4 *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  float *pfVar6;
  float10 fVar7;
  float fVar8;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  int local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  undefined4 local_c4;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float *local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60 [6];
  undefined4 local_48;
  undefined4 local_44;
  float local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  
  local_b4 = 3.4028235e+38;
  local_f8 = 0;
  local_100 = 0;
  if ((((*(char *)(param_1 + 0x7b) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) ||
      (*(char *)(param_1 + 0x53) == '\0')) || (*(float *)(param_1 + 0x124) == 0.0)) {
    local_40[3] = -*param_2;
    local_40[0] = 1.0;
    local_40[1] = 0.0;
    local_40[2] = 0.0;
    local_24 = -param_2[1];
    local_30 = 0;
    local_28 = 0;
    local_2c = 0x3f800000;
    local_94 = -param_2[2];
    local_20 = 0;
    local_1c = 0;
    local_18 = 0x3f800000;
    local_d4 = in_ECX;
    local_14 = local_94;
    iVar5 = FUN_006c0e40(param_1 + 0x20,param_1 + 0x30,param_2,_DAT_0081f9b4 * _DAT_0081f9d8 + 0.01,
                         local_60,local_60 + 4);
    if (iVar5 != 0) {
      local_f4 = 0;
      _DAT_02973be0 = local_60[0];
      _DAT_02973be4 = local_60[1];
      _DAT_02973be8 = local_60[2];
      _DAT_02973bec = local_60[3];
      _DAT_02973bd0 = local_60[4];
      _DAT_02973bd4 = local_60[5];
      _DAT_02973bd8 = local_48;
      _DAT_02973bdc = local_44;
      do {
        local_84 = local_40 + local_f4 * 4 + 3;
        pfVar6 = local_60 + 2;
        local_fc = 2;
        do {
          pfVar1 = pfVar6 + -2;
          local_78 = local_40[local_f4 * 4 + 2] * *pfVar6 +
                     *pfVar1 * local_40[local_f4 * 4] + local_40[local_f4 * 4 + 1] * pfVar6[-1] +
                     *local_84;
          local_80 = local_78 * local_40[local_f4 * 4];
          local_7c = local_40[local_f4 * 4 + 1] * local_78;
          local_78 = local_78 * local_40[local_f4 * 4 + 2];
          local_f0 = *pfVar1 - local_80;
          local_ec = pfVar6[-1] - local_7c;
          local_e8 = *pfVar6 - local_78;
          local_e4 = local_c4;
          local_d0 = local_f0;
          local_cc = local_ec;
          local_c8 = local_e8;
          FUN_005d6430(&local_f0,&local_f0,1,0);
          FUN_005d6430(&local_a0,pfVar1,1,0);
          local_70 = local_a0 - local_f0;
          local_6c = local_9c - local_ec;
          local_68 = local_98 - local_e8;
          fVar7 = (float10)FUN_005c0240(local_68 * local_68 +
                                        local_70 * local_70 + local_6c * local_6c);
          fVar2 = (float)fVar7;
          if ((fVar2 < _DAT_0081f9e4) && (fVar2 < local_b4)) {
            local_b0 = *pfVar1;
            local_f8 = local_f4 + 1;
            local_ac = pfVar6[-1];
            local_a8 = *pfVar6;
            local_b4 = fVar2;
          }
          pfVar6 = pfVar6 + 4;
          local_fc = local_fc + -1;
        } while (local_fc != 0);
        local_f4 = local_f4 + 1;
        in_ECX = local_d4;
      } while (local_f4 < 3);
    }
    local_d0 = local_b0 - *param_2;
    local_cc = local_ac - param_2[1];
    local_c8 = local_a8 - param_2[2];
    if (local_f8 == 1) {
      *param_3 = 0x3f800000;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0x3f800000;
      param_3[3] = -*param_2;
      fVar2 = local_cc;
      fVar8 = local_c8;
    }
    else {
      fVar2 = local_d0;
      if (local_f8 == 2) {
        *param_3 = 0;
        param_3[1] = 0x3f800000;
        param_3[3] = 0x3f800000;
        param_3[2] = 0;
        param_3[3] = -param_2[1];
        fVar8 = -local_c8;
      }
      else {
        if (local_f8 != 3) goto LAB_006c56ca;
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0x3f800000;
        param_3[3] = 0x3f800000;
        param_3[3] = -param_2[2];
        fVar8 = local_cc;
      }
    }
    local_100 = FUN_005be3b0(fVar2,fVar8);
LAB_006c56ca:
    if ((*(char *)(param_1 + 0x7b) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) {
      *(int *)(in_ECX + 0x18) = local_f8;
      *(undefined4 *)(in_ECX + 0x20) = *param_3;
      *(undefined4 *)(in_ECX + 0x24) = param_3[1];
      *(undefined4 *)(in_ECX + 0x28) = param_3[2];
      *(undefined4 *)(in_ECX + 0x2c) = param_3[3];
      *(int *)(in_ECX + 0x70) = local_100;
      *(int *)(in_ECX + 0x74) = local_100;
      *(undefined4 *)(in_ECX + 0x78) = 0;
      return local_f8;
    }
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0x3f800000;
    *(undefined4 *)(in_ECX + 0x3c) = 0x3f800000;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x70) = 0;
    *(undefined4 *)(in_ECX + 0x74) = 0;
    *(undefined4 *)(in_ECX + 0x78) = 0;
    return local_f8;
  }
  iVar5 = *(int *)(in_ECX + 0x18);
  *param_3 = *(undefined4 *)(in_ECX + 0x20);
  param_3[1] = *(undefined4 *)(in_ECX + 0x24);
  param_3[2] = *(undefined4 *)(in_ECX + 0x28);
  param_3[3] = *(undefined4 *)(in_ECX + 0x2c);
  iVar3 = FUN_006c0d20(param_1 + 0x20,param_1 + 0x30,param_3,&local_b0);
  if (iVar3 == 0) {
    *(undefined4 *)(in_ECX + 0x78) = 0;
    return iVar5;
  }
  local_f0 = local_b0 - *param_2;
  local_ec = local_ac - param_2[1];
  local_e8 = local_a8 - param_2[2];
  fVar2 = local_ec;
  fVar8 = local_e8;
  if (iVar5 != 1) {
    fVar2 = local_f0;
    if (iVar5 == 2) {
      fVar8 = -local_e8;
    }
    else {
      fVar8 = local_ec;
      if (iVar5 != 3) goto LAB_006c52c3;
    }
  }
  local_100 = FUN_005be3b0(fVar2,fVar8);
LAB_006c52c3:
  uVar4 = *(int *)(in_ECX + 0x74) - local_100 & 0xffff;
  if (0x7fff < uVar4) {
    uVar4 = uVar4 - 0x10000;
  }
  *(uint *)(in_ECX + 0x78) = uVar4;
  *(int *)(in_ECX + 0x74) = local_100;
  return iVar5;
}

