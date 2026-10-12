/* Ghidra analysis pseudocode, not original source.
 * ev_6ec8aea645f94e3276e7ac0037e639f8d50e0230e3ad74bacc489d09a6610266
 * Entry: 0x5b3690; label: FUN_005b3690
 */

void FUN_005b3690(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)(&DAT_029899a0)[param_3 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_3 >> 1 & 0x7fff];
  fVar3 = *param_2;
  *param_1 = fVar1 * fVar3 - fVar2 * param_2[1];
  param_1[1] = fVar3 * fVar2 + fVar1 * param_2[1];
  param_1[2] = param_2[2];
  return;
}

