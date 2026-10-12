/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c0000; label: FUN_006c0000
 */

void FUN_006c0000(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

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
  float local_54;
  
  fVar9 = 1.0 - param_6;
  fVar10 = fVar9 * fVar9 * fVar9;
  fVar11 = param_6 * 3.0 * fVar9 * fVar9;
  fVar9 = param_6 * param_6 * 3.0 * fVar9;
  param_6 = param_6 * param_6 * param_6;
  fVar1 = param_4[1];
  fVar2 = param_4[2];
  fVar3 = param_5[1];
  fVar4 = param_5[2];
  fVar5 = param_3[1];
  fVar6 = param_3[2];
  fVar7 = param_2[1];
  fVar8 = param_2[2];
  *param_1 = fVar10 * *param_2 + fVar11 * *param_3 + fVar9 * *param_5 + param_6 * *param_4;
  param_1[1] = fVar7 * fVar10 + fVar5 * fVar11 + fVar3 * fVar9 + fVar1 * param_6;
  param_1[2] = fVar10 * fVar8 + fVar11 * fVar6 + fVar9 * fVar4 + param_6 * fVar2;
  param_1[3] = local_54;
  return;
}

