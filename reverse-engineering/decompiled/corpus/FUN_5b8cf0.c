/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b8cf0; label: FUN_005b8cf0
 */

void FUN_005b8cf0(float *param_1,float *param_2,float *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  float local_38;
  
  fVar7 = *param_3;
  fVar11 = param_3[1];
  fVar13 = param_3[2];
  fVar15 = param_3[3];
  fVar8 = *param_2;
  fVar12 = param_2[1];
  fVar14 = param_2[2];
  fVar16 = param_2[3];
  local_38 = fVar15 * fVar16 + fVar11 * fVar12 + fVar13 * fVar14 + fVar7 * fVar8;
  if (local_38 < 0.0) {
    local_38 = -local_38;
    fVar7 = 0.0 - fVar7;
    fVar11 = 0.0 - fVar11;
    fVar13 = 0.0 - fVar13;
    fVar15 = 0.0 - fVar15;
  }
  if (local_38 <= 0.85) {
    if (0.995 <= local_38) {
      local_38 = 0.995;
    }
    fVar8 = local_38 * 0.22340366 * local_38 + 2.2184808;
    fVar3 = (float10)FUN_005c0240(fVar8 - local_38 * 2.4418843);
    fVar4 = (float10)FUN_005c0240(local_38 * 2.4418843 + fVar8);
    fVar5 = (float10)local_38;
    fVar6 = (float10)FUN_005c0240((float)((float10)1 - fVar5 * fVar5));
    fVar8 = (float)((float10)1 / fVar6);
    fVar3 = (float10)(float)((float10)0.6391287446022034 * fVar5 +
                            ((float10)(double)fVar3 - fVar4) + (float10)1.5707963705062866);
    fVar12 = (float)(fVar3 * ((float10)1 - (float10)param_4) - (float10)1.5707963705062866);
    fVar12 = fVar12 * fVar12;
    fVar14 = (float)(fVar3 * (float10)param_4 - (float10)1.5707963705062866);
    fVar14 = fVar14 * fVar14;
    fVar16 = param_2[1];
    fVar1 = param_2[2];
    fVar2 = param_2[3];
    fVar12 = fVar8 * ((fVar12 * (fVar12 * (fVar12 * 2.3154014e-05 - 0.0013853709) + 0.041663583) -
                      0.49999905) * fVar12 + 0.99999994);
    fVar8 = fVar8 * (((fVar14 * (fVar14 * 2.3154014e-05 - 0.0013853709) + 0.041663583) * fVar14 -
                     0.49999905) * fVar14 + 0.99999994);
    *param_1 = fVar12 * *param_2 + fVar8 * fVar7;
    param_1[1] = fVar12 * fVar16 + fVar8 * fVar11;
    param_1[2] = fVar12 * fVar1 + fVar8 * fVar13;
    param_1[3] = fVar12 * fVar2 + fVar8 * fVar15;
    return;
  }
  fVar8 = (fVar7 - fVar8) * param_4 + fVar8;
  fVar12 = (fVar11 - fVar12) * param_4 + fVar12;
  fVar14 = (fVar13 - fVar14) * param_4 + fVar14;
  fVar16 = (fVar15 - fVar16) * param_4 + fVar16;
  auVar9._0_4_ = fVar14 * fVar14 + fVar8 * fVar8;
  auVar9._4_4_ = fVar16 * fVar16 + fVar12 * fVar12;
  auVar9._8_4_ = fVar8 * fVar8 + fVar14 * fVar14;
  auVar9._12_4_ = fVar12 * fVar12 + fVar16 * fVar16;
  auVar10._4_4_ = auVar9._0_4_ + auVar9._4_4_;
  auVar10._0_4_ = auVar9._4_4_ + auVar9._0_4_;
  auVar10._8_4_ = auVar9._12_4_ + auVar9._8_4_;
  auVar10._12_4_ = auVar9._8_4_ + auVar9._12_4_;
  auVar10 = rsqrtps(auVar9,auVar10);
  *param_1 = auVar10._0_4_ * fVar8;
  param_1[1] = auVar10._4_4_ * fVar12;
  param_1[2] = auVar10._8_4_ * fVar14;
  param_1[3] = auVar10._12_4_ * fVar16;
  return;
}

