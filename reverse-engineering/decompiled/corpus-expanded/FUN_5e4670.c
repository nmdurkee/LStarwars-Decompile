/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4670; label: FUN_005e4670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

