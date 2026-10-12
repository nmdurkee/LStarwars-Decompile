/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x678010; label: FUN_00678010
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00678010(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = -param_2[2] * param_1[2] + -*param_2 * *param_1 + -param_2[1] * param_1[1] + 0.0003;
  *param_3 = *param_2 + fVar1 * *param_1;
  param_3[1] = param_1[1] * fVar1 * _DAT_02947c00 + param_2[1];
  param_3[2] = fVar1 * param_1[2] + param_2[2];
  return;
}

