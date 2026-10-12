/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b5160; label: FUN_005b5160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

