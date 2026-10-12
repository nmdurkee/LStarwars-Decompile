/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0490; label: FUN_005c0490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c0490(float *param_1,float *param_2,float *param_3)

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
  *param_1 = param_3[8] * param_2[2] + *param_2 * *param_3 + param_3[4] * param_2[1];
  param_1[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  param_1[2] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  param_1[3] = param_2[3];
  return;
}

