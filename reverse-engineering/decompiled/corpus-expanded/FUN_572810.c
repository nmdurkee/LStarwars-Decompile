/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x572810; label: FUN_00572810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00572810(float *param_1,float *param_2,float *param_3,int param_4)

{
  float *pfVar1;
  
  pfVar1 = param_2;
  param_2 = (float *)(-param_2[2] * param_1[2] + -*param_2 * *param_1 + -param_2[1] * param_1[1]);
  if (param_4 == 2) {
    param_2 = (float *)(_DAT_00925018 * 0.015 + (float)param_2);
  }
  else if (param_4 == 1) {
    param_2 = (float *)((float)param_2 - _DAT_00925018 * 0.006);
  }
  *param_3 = *pfVar1 + (float)param_2 * *param_1;
  param_3[1] = param_1[1] * (float)param_2 + pfVar1[1];
  param_3[2] = (float)param_2 * param_1[2] + pfVar1[2];
  return;
}

