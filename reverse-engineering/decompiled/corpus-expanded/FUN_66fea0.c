/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66fea0; label: FUN_0066fea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

