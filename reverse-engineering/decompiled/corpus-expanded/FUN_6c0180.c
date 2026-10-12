/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0180; label: FUN_006c0180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c0180(float *param_1,float *param_2,float *param_3,float *param_4,undefined4 param_5,
                 undefined4 param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float local_78;
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
  
  local_78 = (param_1[2] - DAT_00973720) * (param_1[2] - DAT_00973720) +
             (*param_1 - DAT_00973718) * (*param_1 - DAT_00973718) +
             (param_1[1] - DAT_0097371c) * (param_1[1] - DAT_0097371c);
  fVar1 = (param_3[2] - DAT_00973720) * (param_3[2] - DAT_00973720) +
          (*param_3 - DAT_00973718) * (*param_3 - DAT_00973718) +
          (param_3[1] - DAT_0097371c) * (param_3[1] - DAT_0097371c);
  if (fVar1 < local_78) {
    local_78 = fVar1;
  }
  if (local_78 < 5.5) {
    local_78 = 5.5;
  }
  if ((_DAT_00820118 * local_78 <
       (param_3[2] - param_1[2]) * (param_3[2] - param_1[2]) +
       (*param_3 - *param_1) * (*param_3 - *param_1) +
       (param_3[1] - param_1[1]) * (param_3[1] - param_1[1])) && (DAT_02974ca0 < 0x10)) {
    DAT_02974ca0 = DAT_02974ca0 + 1;
    fVar1 = (*param_2 + *param_4) * 0.5;
    fVar2 = (param_2[1] + param_4[1]) * 0.5;
    fVar3 = (param_2[2] + param_4[2]) * 0.5;
    local_60 = (*param_1 + *param_2) * 0.5;
    local_5c = (param_1[1] + param_2[1]) * 0.5;
    local_58 = (param_2[2] + param_1[2]) * 0.5;
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
    FUN_006c0180(param_1,&local_60,&local_20,&local_40,param_5,param_6);
    FUN_006c0180(&local_20,&local_30,param_3,&local_50,param_5,param_6);
    DAT_02974ca0 = DAT_02974ca0 + -1;
    return;
  }
  FUN_006ba7d0(param_1,param_3,param_6);
  return;
}

