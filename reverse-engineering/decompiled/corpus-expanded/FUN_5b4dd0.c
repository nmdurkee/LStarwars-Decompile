/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b4dd0; label: FUN_005b4dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b4dd0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (float)(&DAT_029899a0)[param_2 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_2 >> 1 & 0x7fff];
  fVar3 = *(float *)(param_1 + 0x10);
  fVar4 = *(float *)(param_1 + 0x14);
  fVar5 = *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x10) = fVar2 * *(float *)(param_1 + 0x20) + fVar1 * fVar3;
  *(float *)(param_1 + 0x14) = fVar4 * fVar1 + *(float *)(param_1 + 0x24) * fVar2;
  *(float *)(param_1 + 0x18) = fVar5 * fVar1 + *(float *)(param_1 + 0x28) * fVar2;
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) * fVar1 - fVar2 * fVar3;
  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * fVar1 - fVar2 * fVar4;
  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) * fVar1 - fVar5 * fVar2;
  return;
}

