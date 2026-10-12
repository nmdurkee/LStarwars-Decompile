/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b6490; label: FUN_005b6490
 */

void FUN_005b6490(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  
  param_1[4] = *param_2;
  param_1[5] = param_2[1];
  fVar1 = param_2[2];
  param_1[6] = fVar1;
  *param_1 = param_1[10] * param_1[5] - param_1[9] * fVar1;
  param_1[1] = param_1[6] * param_1[8] - param_1[10] * param_1[4];
  fVar1 = param_1[9] * param_1[4] - param_1[8] * param_1[5];
  param_1[2] = fVar1;
  fVar5 = (float10)FUN_005c0240(*param_1 * *param_1 + param_1[1] * param_1[1] + fVar1 * fVar1);
  if ((float)fVar5 == 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = 1.0 / (float)fVar5;
  }
  fVar3 = fVar1 * *param_1;
  *param_1 = fVar3;
  fVar4 = param_1[1] * fVar1;
  param_1[1] = fVar4;
  fVar2 = param_1[2];
  param_1[2] = fVar2 * fVar1;
  param_1[8] = param_1[6] * fVar4 - param_1[5] * fVar2 * fVar1;
  param_1[9] = param_1[2] * param_1[4] - param_1[6] * fVar3;
  param_1[10] = fVar3 * param_1[5] - param_1[4] * fVar4;
  return;
}

