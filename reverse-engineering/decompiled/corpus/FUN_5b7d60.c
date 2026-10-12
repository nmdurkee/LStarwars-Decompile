/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b7d60; label: FUN_005b7d60
 */

void FUN_005b7d60(float *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = (float)(&DAT_029899a0)[param_2 / 2 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_2 / 2 >> 1 & 0x7fff];
  fVar3 = (float)(&DAT_029899a0)[param_3 / 2 >> 1 & 0x7fff];
  fVar4 = (float)(&DAT_029899a0)[param_3 / 2 + 0x4000 >> 1 & 0x7fff];
  fVar5 = (float)(&DAT_029899a0)[param_4 / 2 + 0x4000 >> 1 & 0x7fff];
  fVar6 = (float)(&DAT_029899a0)[param_4 / 2 >> 1 & 0x7fff];
  fVar7 = fVar4 * fVar5;
  fVar8 = fVar6 * fVar3;
  param_1[3] = fVar2 * fVar8 + fVar1 * fVar7;
  *param_1 = fVar7 * fVar2 - fVar8 * fVar1;
  fVar3 = fVar3 * fVar5;
  fVar6 = fVar6 * fVar4;
  param_1[1] = fVar3 * fVar1 + fVar6 * fVar2;
  param_1[2] = fVar6 * fVar1 - fVar3 * fVar2;
  return;
}

