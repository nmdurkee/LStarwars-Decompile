/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0550; label: FUN_005c0550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c0550(float *param_1,float *param_2,float *param_3)

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
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  int iVar25;
  
  iVar25 = 2;
  do {
    fVar1 = param_2[1];
    fVar2 = param_3[5];
    iVar25 = iVar25 + -1;
    fVar3 = param_3[1];
    fVar4 = *param_2;
    fVar5 = param_3[9];
    fVar6 = param_2[2];
    fVar7 = param_3[0xd];
    fVar8 = param_2[3];
    fVar9 = param_3[6];
    fVar10 = param_2[1];
    fVar11 = param_3[2];
    fVar12 = *param_2;
    fVar13 = param_3[10];
    fVar14 = param_2[2];
    fVar15 = param_3[0xe];
    fVar16 = param_2[3];
    fVar17 = *param_2;
    fVar18 = param_3[3];
    fVar19 = param_3[7];
    fVar20 = param_2[1];
    fVar21 = param_3[0xb];
    fVar22 = param_2[2];
    fVar23 = param_3[0xf];
    fVar24 = param_2[3];
    *param_1 = param_3[0xc] * param_2[3] +
               param_3[8] * param_2[2] + param_3[4] * param_2[1] + *param_2 * *param_3;
    param_1[1] = fVar7 * fVar8 + fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2;
    param_1[2] = fVar15 * fVar16 + fVar13 * fVar14 + fVar11 * fVar12 + fVar9 * fVar10;
    param_1[3] = fVar23 * fVar24 + fVar21 * fVar22 + fVar19 * fVar20 + fVar17 * fVar18;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
  } while (iVar25 != 0);
  return;
}

