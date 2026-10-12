/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0cc0; label: FUN_005c0cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c0cc0(float *param_1,float *param_2,float *param_3)

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
  float fVar16;
  float fVar17;
  float fVar18;
  
  fVar1 = param_3[4];
  fVar2 = *param_2;
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[6];
  fVar6 = param_2[2];
  fVar7 = param_3[8];
  fVar8 = *param_2;
  fVar9 = param_3[9];
  fVar10 = param_2[1];
  fVar11 = param_3[10];
  fVar12 = param_2[2];
  fVar13 = param_3[0xc];
  fVar14 = *param_2;
  fVar15 = param_3[0xd];
  fVar16 = param_2[1];
  fVar17 = param_3[0xe];
  fVar18 = param_2[2];
  *param_1 = param_3[2] * param_2[2] + *param_2 * *param_3 + param_3[1] * param_2[1];
  param_1[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
  param_1[2] = fVar11 * fVar12 + fVar9 * fVar10 + fVar7 * fVar8;
  param_1[3] = fVar17 * fVar18 + fVar15 * fVar16 + fVar13 * fVar14;
  return;
}

