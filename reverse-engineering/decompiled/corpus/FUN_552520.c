/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x552520; label: FUN_00552520
 */

void FUN_00552520(float *param_1,uint param_2,float *param_3)

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
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  
  FUN_005b3b30(param_3,param_3);
  fVar13 = (float10)(float)(&DAT_029899a0)[(int)((param_2 & 0xffff) + 0x4000) >> 1 & 0x7fff];
  fVar17 = (float10)1 - fVar13;
  fVar14 = (float10)*param_3 * fVar17;
  fVar1 = param_3[1];
  fVar2 = param_3[2];
  fVar15 = (float10)(float)(&DAT_029899a0)[param_2 >> 1 & 0x7fff];
  fVar3 = param_3[2];
  fVar4 = param_3[1];
  fVar5 = param_3[1];
  fVar16 = (float10)param_3[2] * (float10)fVar5 * fVar17;
  fVar6 = *param_3;
  fVar7 = param_3[1];
  fVar8 = *param_1;
  fVar9 = *param_1;
  fVar10 = param_1[1];
  fVar11 = param_3[2];
  fVar12 = param_3[2];
  *param_1 = (float)(((float10)(double)(fVar15 * (float10)fVar4) +
                     (float10)(double)((float10)fVar3 * fVar14)) * (float10)param_1[2] +
                    (float10)(float)(((float10)fVar1 * fVar14 - fVar15 * (float10)fVar2) *
                                     (float10)param_1[1] +
                                    (float10)(float)((float10)*param_1 *
                                                     (fVar13 + (float10)*param_3 * fVar14) +
                                                    (float10)0.0)));
  param_1[1] = (float)((fVar16 - (float10)fVar6 * fVar15) * (float10)param_1[2] +
                      (float10)(float)((float10)param_1[1] *
                                       (fVar13 + (float10)fVar7 * (float10)fVar5 * fVar17) +
                                      (float10)(float)((float10)fVar8 *
                                                       (fVar15 * (float10)fVar2 +
                                                       (float10)fVar1 * fVar14) + (float10)0)));
  param_1[2] = (float)((float10)param_1[2] * ((float10)fVar12 * (float10)fVar11 * fVar17 + fVar13) +
                      (float10)(float)(((float10)fVar6 * fVar15 + fVar16) * (float10)fVar10 +
                                      (float10)(float)(((float10)(double)((float10)fVar3 * fVar14) -
                                                       (float10)(double)(fVar15 * (float10)fVar4)) *
                                                       (float10)fVar9 + (float10)0)));
  return;
}

