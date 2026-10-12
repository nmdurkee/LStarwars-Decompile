/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x677fb0; label: FUN_00677fb0
 */

void FUN_00677fb0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = -param_2[2] * param_1[2] + -*param_2 * *param_1 + -param_2[1] * param_1[1] + 0.0003;
  *param_3 = *param_2 + fVar1 * *param_1;
  param_3[1] = param_1[1] * fVar1 + param_2[1];
  param_3[2] = fVar1 * param_1[2] + param_2[2];
  return;
}

