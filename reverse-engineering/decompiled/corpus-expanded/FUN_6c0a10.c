/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0a10; label: FUN_006c0a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006c0a10(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_14;
  
  fVar3 = (float10)FUN_005c0240(param_2[2] * param_2[2] +
                                *param_2 * *param_2 + param_2[1] * param_2[1]);
  fVar2 = 1.0 / (float)fVar3;
  fVar1 = fVar2 * param_2[1] * (param_3[1] - param_1[1]) + fVar2 * *param_2 * (*param_3 - *param_1)
          + fVar2 * param_2[2] * (param_3[2] - param_1[2]);
  if (fVar1 < 0.0 == (fVar1 == 0.0)) {
    if (fVar1 < (float)fVar3) {
      local_20 = *param_1 + fVar1 * fVar2 * *param_2;
      local_1c = param_1[1] + fVar2 * param_2[1] * fVar1;
      local_28 = param_1[2] + fVar2 * param_2[2] * fVar1;
    }
    else {
      local_20 = *param_1 + *param_2;
      local_1c = param_1[1] + param_2[1];
      local_28 = param_1[2] + param_2[2];
    }
    local_30 = local_20;
    local_2c = local_1c;
  }
  else {
    local_30 = *param_1;
    local_2c = param_1[1];
    local_28 = param_1[2];
    local_14 = param_1[3];
  }
  fVar3 = (float10)FUN_005c0240((local_28 - param_3[2]) * (local_28 - param_3[2]) +
                                (local_30 - *param_3) * (local_30 - *param_3) +
                                (local_2c - param_3[1]) * (local_2c - param_3[1]));
  if (param_4 != (float *)0x0) {
    *param_4 = local_30;
    param_4[1] = local_2c;
    param_4[2] = local_28;
    param_4[3] = local_14;
  }
  return (float10)(float)fVar3;
}

