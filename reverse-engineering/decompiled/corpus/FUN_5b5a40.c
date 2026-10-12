/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b5a40; label: FUN_005b5a40
 */

void FUN_005b5a40(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = -param_2[0xc];
  fVar3 = -param_2[0xd];
  fVar4 = -param_2[0xe];
  fVar1 = param_2[1];
  param_1[1] = param_2[4];
  param_1[4] = fVar1;
  fVar1 = param_2[2];
  param_1[2] = param_2[8];
  param_1[8] = fVar1;
  fVar1 = param_2[6];
  param_1[6] = param_2[9];
  param_1[9] = fVar1;
  *param_1 = *param_2;
  param_1[5] = param_2[5];
  param_1[10] = param_2[10];
  param_1[0xc] = fVar3 * param_1[4] + fVar2 * *param_1 + fVar4 * param_1[8];
  param_1[0xd] = fVar2 * param_1[1] + param_1[5] * fVar3 + fVar4 * fVar1;
  param_1[0xe] = fVar4 * param_1[10] + fVar2 * param_1[2] + param_1[6] * fVar3;
  param_1[0xb] = 0.0;
  param_1[7] = 0.0;
  param_1[3] = 0.0;
  param_1[0xf] = 1.0;
  return;
}

