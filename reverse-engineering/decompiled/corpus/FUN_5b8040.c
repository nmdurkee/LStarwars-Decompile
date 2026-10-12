/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b8040; label: FUN_005b8040
 */

void FUN_005b8040(float *param_1,float *param_2)

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
  
  fVar1 = param_1[3] * param_1[3];
  fVar2 = *param_1 * *param_1;
  fVar3 = param_1[1] * param_1[1];
  fVar4 = param_1[2] * param_1[2];
  fVar5 = param_1[1] * *param_1 * 2.0;
  fVar6 = param_1[2] * *param_1 * 2.0;
  fVar7 = *param_1 * param_1[3] * 2.0;
  fVar8 = param_1[1] * param_1[2] * 2.0;
  fVar9 = param_1[1] * param_1[3] * 2.0;
  fVar10 = param_1[2] * param_1[3] * 2.0;
  *param_2 = ((fVar1 + fVar2) - fVar3) - fVar4;
  param_2[4] = fVar5 - fVar10;
  param_2[8] = fVar9 + fVar6;
  param_2[0xc] = 0.0;
  param_2[1] = fVar10 + fVar5;
  fVar1 = fVar1 - fVar2;
  param_2[5] = (fVar3 + fVar1) - fVar4;
  param_2[9] = fVar8 - fVar7;
  param_2[0xd] = 0.0;
  param_2[2] = fVar6 - fVar9;
  param_2[6] = fVar8 + fVar7;
  param_2[10] = (fVar1 - fVar3) + fVar4;
  param_2[0xe] = 0.0;
  param_2[3] = 0.0;
  param_2[7] = 0.0;
  param_2[0xb] = 0.0;
  param_2[0xf] = 1.0;
  return;
}

