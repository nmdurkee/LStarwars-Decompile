/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6bf350; label: FUN_006bf350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006bf350(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
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
  
  fVar1 = (*param_2 + *param_4) * 0.5;
  fVar2 = (param_2[1] + param_4[1]) * 0.5;
  fVar3 = (param_2[2] + param_4[2]) * 0.5;
  local_60 = (*param_1 + *param_2) * 0.5;
  local_5c = (param_2[1] + param_1[1]) * 0.5;
  local_58 = (param_1[2] + param_2[2]) * 0.5;
  local_50 = (*param_3 + *param_4) * 0.5;
  local_4c = (param_4[1] + param_3[1]) * 0.5;
  local_48 = (param_4[2] + param_3[2]) * 0.5;
  local_40 = (fVar1 + local_60) * 0.5;
  local_3c = (local_5c + fVar2) * 0.5;
  local_38 = (local_58 + fVar3) * 0.5;
  local_30 = (local_50 + fVar1) * 0.5;
  local_2c = (local_4c + fVar2) * 0.5;
  local_28 = (fVar3 + local_48) * 0.5;
  local_20 = (local_30 + local_40) * 0.5;
  local_1c = (local_2c + local_3c) * 0.5;
  local_18 = (local_28 + local_38) * 0.5;
  fVar1 = (*param_1 + *param_3) * 0.5 - local_20;
  fVar2 = (param_3[1] + param_1[1]) * 0.5 - local_1c;
  fVar3 = (param_1[2] + param_3[2]) * 0.5 - local_18;
  fVar4 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2);
  if ((_DAT_0081f9f8 <= (float)fVar4) && (DAT_02973ae8 < DAT_0081f9fc)) {
    DAT_02973ae8 = DAT_02973ae8 + 1;
    fVar4 = (float10)FUN_006bf350(param_1,&local_60,&local_20,&local_40);
    fVar5 = (float10)FUN_006bf350(&local_20,&local_30,param_3,&local_50);
    DAT_02973ae8 = DAT_02973ae8 + -1;
    return (float10)(float)(fVar5 + (float10)(float)fVar4);
  }
  fVar4 = (float10)FUN_005c0240((param_1[2] - param_3[2]) * (param_1[2] - param_3[2]) +
                                (*param_1 - *param_3) * (*param_1 - *param_3) +
                                (param_1[1] - param_3[1]) * (param_1[1] - param_3[1]));
  return (float10)(float)fVar4;
}

