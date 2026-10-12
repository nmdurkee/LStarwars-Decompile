/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b4dd0; label: FUN_005b4dd0
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

