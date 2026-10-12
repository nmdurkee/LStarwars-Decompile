/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b5160; label: FUN_005b5160
 */

void FUN_005b5160(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)(&DAT_029899a0)[param_2 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_2 >> 1 & 0x7fff];
  fVar3 = *param_1;
  fVar4 = param_1[4];
  fVar5 = param_1[8];
  fVar6 = param_1[0xc];
  *param_1 = fVar1 * fVar3 - fVar2 * param_1[1];
  param_1[1] = fVar1 * param_1[1] + fVar2 * fVar3;
  param_1[4] = fVar4 * fVar1 - param_1[5] * fVar2;
  param_1[5] = param_1[5] * fVar1 + fVar2 * fVar4;
  param_1[8] = fVar5 * fVar1 - param_1[9] * fVar2;
  param_1[9] = param_1[9] * fVar1 + fVar2 * fVar5;
  param_1[0xc] = fVar6 * fVar1 - fVar2 * param_1[0xd];
  param_1[0xd] = fVar6 * fVar2 + param_1[0xd] * fVar1;
  return;
}

