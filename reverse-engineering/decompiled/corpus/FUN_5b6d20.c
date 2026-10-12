/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b6d20; label: FUN_005b6d20
 */

void FUN_005b6d20(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float10 fVar4;
  
  fVar4 = (float10)FUN_005c0240(param_1[2] * param_1[2] +
                                *param_1 * *param_1 + param_1[1] * param_1[1]);
  fVar1 = (float)((float10)1 / fVar4);
  *param_1 = fVar1 * *param_1;
  param_1[1] = fVar1 * param_1[1];
  param_1[2] = fVar1 * param_1[2];
  fVar4 = (float10)FUN_005c0240(param_1[6] * param_1[6] +
                                param_1[4] * param_1[4] + param_1[5] * param_1[5]);
  fVar1 = (float)((float10)1 / fVar4);
  fVar3 = fVar1 * param_1[6] * param_1[1] - param_1[5] * fVar1 * param_1[2];
  param_1[8] = fVar3;
  fVar2 = fVar1 * param_1[4] * param_1[2] - *param_1 * fVar1 * param_1[6];
  param_1[9] = fVar2;
  fVar1 = *param_1 * param_1[5] * fVar1 - param_1[1] * fVar1 * param_1[4];
  param_1[10] = fVar1;
  param_1[4] = param_1[2] * fVar2 - fVar1 * param_1[1];
  param_1[5] = *param_1 * param_1[10] - param_1[2] * fVar3;
  param_1[6] = param_1[8] * param_1[1] - *param_1 * param_1[9];
  return;
}

