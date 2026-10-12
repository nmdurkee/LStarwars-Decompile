/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b3710; label: FUN_005b3710
 */

void FUN_005b3710(float *param_1,float param_2,int param_3)

{
  float fVar1;
  
  fVar1 = (float)(&DAT_029899a0)[param_3 + 0x4000 >> 1 & 0x7fff];
  *param_1 = param_2 * (float)(&DAT_029899a0)[param_3 >> 1 & 0x7fff];
  param_1[1] = 0.0;
  param_1[2] = param_2 * fVar1;
  return;
}

