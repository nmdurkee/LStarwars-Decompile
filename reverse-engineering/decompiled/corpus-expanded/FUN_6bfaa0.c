/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bfaa0; label: FUN_006bfaa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_006bfaa0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  float local_19c;
  float local_198;
  int local_194;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  local_19c = 0.5;
  local_198 = 0.25;
  local_194 = 0;
  do {
    fVar1 = 1.0 - local_19c;
    fVar2 = *param_3 * local_19c + fVar1 * *param_5;
    fVar3 = param_3[1] * local_19c + param_5[1] * fVar1;
    fVar4 = param_3[2] * local_19c + fVar1 * param_5[2];
    local_60 = *param_2 * local_19c + fVar1 * *param_3;
    local_5c = param_2[1] * local_19c + param_3[1] * fVar1;
    local_58 = param_2[2] * local_19c + fVar1 * param_3[2];
    local_50 = *param_5 * local_19c + fVar1 * *param_4;
    local_4c = param_5[1] * local_19c + fVar1 * param_4[1];
    local_48 = local_19c * param_5[2] + fVar1 * param_4[2];
    local_40 = local_60 * local_19c + fVar1 * fVar2;
    local_3c = local_5c * local_19c + fVar3 * fVar1;
    local_38 = local_58 * local_19c + fVar1 * fVar4;
    local_30 = local_19c * fVar2 + fVar1 * local_50;
    local_2c = fVar3 * local_19c + local_4c * fVar1;
    local_28 = local_19c * fVar4 + fVar1 * local_48;
    local_20 = local_40 * local_19c + fVar1 * local_30;
    local_1c = local_3c * local_19c + local_2c * fVar1;
    local_18 = local_19c * local_38 + fVar1 * local_28;
    local_14 = 1.0;
    fVar5 = (float10)FUN_006bf350(param_2,&local_60,&local_20,&local_40);
    fVar1 = param_6 - (float)fVar5;
    if (fVar1 < 0.0) {
      fVar1 = -fVar1;
    }
    if (fVar1 <= _DAT_0081f9f8) break;
    if ((float)fVar5 <= param_6) {
      local_19c = local_19c - local_198;
    }
    else {
      local_19c = local_198 + local_19c;
    }
    local_194 = local_194 + 1;
    local_198 = local_198 * 0.5;
  } while (local_194 < 0x100);
  *param_1 = local_20;
  param_1[1] = local_1c;
  param_1[2] = local_18;
  param_1[3] = local_14;
  return 1;
}

