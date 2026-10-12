/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b3300; label: FUN_005b3300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b3300(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar13 = 1.0 / (param_3[0xb] * param_2[2] + param_3[7] * param_2[1] + param_3[3] * *param_2);
  fVar1 = param_3[1];
  fVar2 = *param_2;
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[9];
  fVar6 = param_2[2];
  fVar7 = param_3[2];
  fVar8 = *param_2;
  fVar9 = param_3[6];
  fVar10 = param_2[1];
  fVar11 = param_3[10];
  fVar12 = param_2[2];
  *param_1 = (param_3[8] * param_2[2] + *param_2 * *param_3 + param_3[4] * param_2[1]) * fVar13;
  param_1[1] = fVar13 * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2);
  param_1[2] = (fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8) * fVar13;
  return;
}

