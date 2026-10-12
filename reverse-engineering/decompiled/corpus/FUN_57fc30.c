/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57fc30; label: FUN_0057fc30
 */

void FUN_0057fc30(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2;
  fVar1 = fVar1 + fVar1;
  *param_3 = *param_2 - fVar1 * *param_1;
  param_3[1] = param_2[1] - fVar1 * param_1[1];
  param_3[2] = param_2[2] - param_1[2] * fVar1;
  return;
}

