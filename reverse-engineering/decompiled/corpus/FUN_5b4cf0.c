/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b4cf0; label: FUN_005b4cf0
 */

void FUN_005b4cf0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)(&DAT_029899a0)[param_2 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_2 >> 1 & 0x7fff];
  fVar3 = *(float *)(param_1 + 4);
  fVar4 = *(float *)(param_1 + 0x14);
  fVar5 = *(float *)(param_1 + 0x24);
  fVar6 = *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 4) = fVar1 * fVar3 - fVar2 * *(float *)(param_1 + 8);
  *(float *)(param_1 + 8) = *(float *)(param_1 + 8) * fVar1 + fVar2 * fVar3;
  *(float *)(param_1 + 0x14) = fVar4 * fVar1 - *(float *)(param_1 + 0x18) * fVar2;
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) * fVar1 + fVar2 * fVar4;
  *(float *)(param_1 + 0x24) = fVar5 * fVar1 - fVar2 * *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 0x28) = fVar1 * *(float *)(param_1 + 0x28) + fVar5 * fVar2;
  *(float *)(param_1 + 0x34) = fVar6 * fVar1 - *(float *)(param_1 + 0x38) * fVar2;
  *(float *)(param_1 + 0x38) = fVar6 * fVar2 + *(float *)(param_1 + 0x38) * fVar1;
  return;
}

