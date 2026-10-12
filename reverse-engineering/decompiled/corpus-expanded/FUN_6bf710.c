/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bf710; label: FUN_006bf710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bf710(float *param_1,float *param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
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
  
  fVar1 = 1.0 - param_5;
  fVar2 = *param_2 * param_5 + fVar1 * *param_4;
  fVar3 = param_2[1] * param_5 + param_4[1] * fVar1;
  fVar4 = param_5 * param_2[2] + fVar1 * param_4[2];
  local_60 = *param_1 * param_5 + fVar1 * *param_2;
  local_5c = param_1[1] * param_5 + param_2[1] * fVar1;
  local_58 = param_1[2] * param_5 + fVar1 * param_2[2];
  local_50 = *param_4 * param_5 + fVar1 * *param_3;
  local_4c = param_4[1] * param_5 + param_3[1] * fVar1;
  local_48 = param_4[2] * param_5 + fVar1 * param_3[2];
  local_40 = local_60 * param_5 + fVar1 * fVar2;
  local_3c = local_5c * param_5 + fVar3 * fVar1;
  local_38 = local_58 * param_5 + fVar1 * fVar4;
  local_30 = param_5 * fVar2 + fVar1 * local_50;
  local_2c = fVar3 * param_5 + local_4c * fVar1;
  local_28 = param_5 * fVar4 + fVar1 * local_48;
  local_20 = local_40 * param_5 + fVar1 * local_30;
  local_1c = local_3c * param_5 + local_2c * fVar1;
  local_18 = param_5 * local_38 + fVar1 * local_28;
  FUN_006bf350(param_1,&local_60,&local_20,&local_40);
  return;
}

