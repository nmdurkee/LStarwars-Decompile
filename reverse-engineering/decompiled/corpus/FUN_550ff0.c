/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550ff0; label: FUN_00550ff0
 */

undefined4
FUN_00550ff0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = (*param_4 - *param_3) * (param_1[1] - param_3[1]) -
          (*param_1 - *param_3) * (param_4[1] - param_3[1]);
  fVar4 = *param_2 - *param_1;
  fVar3 = fVar4 * (param_4[1] - param_3[1]) - (param_2[1] - param_1[1]) * (*param_4 - *param_3);
  fVar1 = fVar4 * (param_1[1] - param_3[1]) - (param_2[1] - param_1[1]) * (*param_1 - *param_3);
  if (fVar2 == 0.0) {
    if (fVar3 != 0.0) goto LAB_005510b1;
    if ((fVar1 == 0.0) && (fVar3 == 0.0)) {
      return 0;
    }
  }
  if (fVar3 == 0.0) {
    return 0;
  }
LAB_005510b1:
  if (fVar3 != 0.0) {
    fVar2 = fVar2 / fVar3;
    fVar1 = fVar1 / fVar3;
    if (param_5 != (float *)0x0) {
      *param_5 = *param_1 + fVar2 * fVar4;
      param_5[1] = (param_2[1] - param_1[1]) * fVar2 + param_1[1];
    }
    if (param_6 != (float *)0x0) {
      *param_6 = (*param_4 - *param_3) * fVar1 + *param_3;
      param_6[1] = (param_4[1] - param_3[1]) * fVar1 + param_3[1];
    }
    if (0.0 <= fVar2) {
      if ((1.0 < fVar2) || (NAN(fVar1) || 0.0 < fVar1 == (fVar1 == 0.0))) {
        return 0;
      }
      if (fVar1 <= 1.0) {
        return 1;
      }
    }
  }
  return 0;
}

