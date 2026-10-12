/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b7ea0; label: FUN_005b7ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b7ea0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;
  float local_10 [4];
  
  local_10[0] = 1.4013e-45;
  local_10[1] = 2.8026e-45;
  fVar1 = *param_1 + param_1[5] + param_1[10];
  local_10[2] = 0.0;
  if (0.0 < fVar1) {
    fVar5 = (float10)FUN_005c0240(fVar1 + 1.0);
    param_2[3] = (float)fVar5 * 0.5;
    fVar1 = 0.5 / (float)fVar5;
    *param_2 = fVar1 * (param_1[6] - param_1[9]);
    param_2[1] = (param_1[8] - param_1[2]) * fVar1;
    param_2[2] = (param_1[1] - param_1[4]) * fVar1;
    return;
  }
  uVar4 = (uint)(*param_1 < param_1[5]);
  if (param_1[uVar4 * 5] < param_1[10]) {
    uVar4 = 2;
  }
  fVar2 = local_10[uVar4];
  fVar3 = local_10[(int)fVar2];
  fVar5 = (float10)FUN_005c0240((param_1[uVar4 * 5] -
                                (param_1[(int)fVar3 * 5] + param_1[(int)fVar2 * 5])) + 1.0);
  fVar1 = (float)fVar5;
  local_10[uVar4] = fVar1 * 0.5;
  if (fVar1 != 0.0) {
    fVar1 = 0.5 / fVar1;
  }
  local_10[3] = (param_1[(int)fVar3 + (int)fVar2 * 4] - param_1[(int)fVar2 + (int)fVar3 * 4]) *
                fVar1;
  local_10[(int)fVar2] = (param_1[uVar4 + (int)fVar2 * 4] + param_1[(int)fVar2 + uVar4 * 4]) * fVar1
  ;
  local_10[(int)fVar3] = (param_1[uVar4 + (int)fVar3 * 4] + param_1[(int)fVar3 + uVar4 * 4]) * fVar1
  ;
  *param_2 = local_10[0];
  param_2[1] = local_10[1];
  param_2[2] = local_10[2];
  param_2[3] = local_10[3];
  return;
}

