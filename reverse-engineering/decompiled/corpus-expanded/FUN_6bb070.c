/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bb070; label: FUN_006bb070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bb070(float *param_1,float param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_88;
  float local_84;
  int local_78;
  int local_74;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_38;
  float local_30;
  float local_28;
  float local_20;
  float local_18;
  
  local_78 = 0;
  local_44 = 0x3f800000;
  local_74 = 0;
  local_54 = 0x3f800000;
  iVar7 = 0x7000;
  do {
    if (local_78 < 4) {
      fVar2 = (float)(&DAT_029899a0)[local_74 >> 1 & 0x7fff];
    }
    else {
      fVar2 = (float)(&DAT_029899a0)[iVar7 + 0x1000 >> 1 & 0x7fff];
    }
    fVar2 = fVar2 * param_2;
    iVar6 = iVar7;
    if (local_78 < 3) {
      iVar6 = local_74 + 0x1000;
    }
    fVar5 = param_2 * (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
    fVar8 = (float10)FUN_005c0240(param_2 * param_2 - fVar2 * fVar2);
    local_88 = (float)(fVar8 * (float10)param_3);
    fVar8 = (float10)FUN_005c0240(param_2 * param_2 - fVar5 * fVar5);
    local_84 = (float)(fVar8 * (float10)param_3);
    if (4 < local_78) {
      local_88 = -local_88;
    }
    if (3 < local_78) {
      local_84 = -local_84;
    }
    fVar3 = param_1[1];
    fVar4 = param_1[1];
    iVar6 = 0x6000;
    local_4c = fVar3 + local_88;
    do {
      local_50 = *param_1 + fVar2 * (float)(&DAT_029899a0)[iVar6 + -0x2000 >> 1 & 0x7fff];
      local_48 = param_1[2] + (float)(&DAT_029899a0)[iVar6 + -0x6000 >> 1 & 0x7fff] * fVar2;
      local_60 = *param_1 + fVar5 * (float)(&DAT_029899a0)[iVar6 + -0x2000 >> 1 & 0x7fff];
      local_58 = (float)(&DAT_029899a0)[iVar6 + -0x6000 >> 1 & 0x7fff] * fVar5 + param_1[2];
      local_5c = fVar4 + local_84;
      local_40 = local_50;
      local_38 = local_48;
      local_30 = local_60;
      local_28 = local_58;
      FUN_006ba7d0(&local_50,&local_60,param_4);
      if (iVar7 != 0x7000) {
        local_60 = *param_1 + fVar2 * (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
        local_58 = fVar2 * (float)(&DAT_029899a0)[iVar6 + -0x4000 >> 1 & 0x7fff] + param_1[2];
        local_5c = fVar3 + local_88;
        local_20 = local_60;
        local_18 = local_58;
        FUN_006ba7d0(&local_50,&local_60,param_4);
      }
      iVar1 = iVar6 + -0x4000;
      iVar6 = iVar6 + 0x2000;
    } while (iVar1 < 0x10000);
    local_78 = local_78 + 1;
    local_74 = local_74 + 0x1000;
    iVar7 = iVar7 + -0x1000;
  } while (-0x1000 < iVar7);
  return;
}

