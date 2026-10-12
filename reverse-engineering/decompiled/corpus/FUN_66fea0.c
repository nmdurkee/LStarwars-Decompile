/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x66fea0; label: FUN_0066fea0
 */

void FUN_0066fea0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = DAT_0292186c;
  iVar8 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff];
  iVar8 = FUN_006e6b90();
  fVar2 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff];
  iVar8 = FUN_006e6b90();
  fVar3 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff];
  iVar8 = FUN_006e6b90();
  fVar4 = param_1[2] - *(float *)(iVar7 + 0x24);
  fVar6 = *param_1 - *(float *)(iVar7 + 0x1c);
  fVar5 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff] * fVar4 - fVar3 * fVar6;
  *param_1 = (float)(&DAT_029899a0)[iVar8 >> 1 & 0x7fff] * fVar6 + fVar3 * fVar4;
  param_1[2] = fVar1 * ((*(float *)(iVar7 + 0x50) + param_1[1]) - *(float *)(iVar7 + 0x20)) +
               fVar2 * fVar5;
  param_1[1] = ((*(float *)(iVar7 + 0x50) + param_1[1]) - *(float *)(iVar7 + 0x20)) * fVar2 -
               fVar5 * fVar1;
  return;
}

