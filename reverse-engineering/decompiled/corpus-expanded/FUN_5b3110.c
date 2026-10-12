/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b3110; label: FUN_005b3110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b3110(float *param_1,float *param_2,float *param_3)

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
  float fVar14;
  float fVar15;
  
  fVar15 = param_3[0xb] * param_2[2] + param_3[7] * param_2[1] + param_3[3] * *param_2 +
           param_3[0xf];
  if (fVar15 == 0.0) {
    fVar15 = 0.0;
  }
  else {
    fVar15 = 1.0 / fVar15;
  }
  fVar1 = param_3[1];
  fVar2 = *param_2;
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[9];
  fVar6 = param_2[2];
  fVar7 = param_3[0xd];
  fVar8 = param_3[2];
  fVar9 = *param_2;
  fVar10 = param_3[6];
  fVar11 = param_2[1];
  fVar12 = param_3[10];
  fVar13 = param_2[2];
  fVar14 = param_3[0xe];
  *param_1 = (param_3[8] * param_2[2] + *param_2 * *param_3 + param_3[4] * param_2[1] + param_3[0xc]
             ) * fVar15;
  param_1[1] = fVar15 * (fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7);
  param_1[2] = (fVar12 * fVar13 + fVar10 * fVar11 + fVar8 * fVar9 + fVar14) * fVar15;
  return;
}

