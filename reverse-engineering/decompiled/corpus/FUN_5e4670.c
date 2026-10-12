/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e4670; label: FUN_005e4670
 */

void FUN_005e4670(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  iVar6 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
  iVar6 = FUN_006e6b90();
  fVar2 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
  iVar6 = FUN_006e6b90();
  fVar3 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
  iVar6 = FUN_006e6b90();
  fVar4 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
  fVar5 = fVar2 * param_1[2] + fVar1 * param_1[1];
  param_1[1] = param_1[1] * fVar2 - fVar1 * param_1[2];
  param_1[2] = fVar4 * fVar5 - fVar3 * *param_1;
  *param_1 = fVar5 * fVar3 + fVar4 * *param_1;
  return;
}

