/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c0330; label: thunk_FUN_005b5300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_005b5300(float *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)(&DAT_029899a0)[*param_2 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[*param_2 >> 1 & 0x7fff];
  fVar3 = (float)(&DAT_029899a0)[param_2[1] + 0x4000 >> 1 & 0x7fff];
  fVar4 = (float)(&DAT_029899a0)[param_2[1] >> 1 & 0x7fff];
  fVar5 = (float)(&DAT_029899a0)[param_2[2] + 0x4000 >> 1 & 0x7fff];
  fVar6 = (float)(&DAT_029899a0)[param_2[2] >> 1 & 0x7fff];
  *param_1 = fVar3 * fVar5;
  param_1[1] = fVar6 * fVar3;
  param_1[2] = -fVar4;
  param_1[3] = 0.0;
  param_1[4] = fVar2 * fVar4 * fVar5 - fVar6 * fVar1;
  param_1[5] = fVar6 * fVar2 * fVar4 + fVar5 * fVar1;
  param_1[6] = fVar3 * fVar2;
  param_1[7] = 0.0;
  param_1[8] = fVar5 * fVar4 * fVar1 + fVar6 * fVar2;
  param_1[9] = fVar4 * fVar1 * fVar6 - fVar5 * fVar2;
  param_1[10] = fVar3 * fVar1;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = 0.0;
  param_1[0xf] = 1.0;
  return;
}

