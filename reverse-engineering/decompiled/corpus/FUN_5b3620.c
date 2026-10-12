/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b3620; label: FUN_005b3620
 */

void FUN_005b3620(float *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)(&DAT_029899a0)[param_3 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_3 >> 1 & 0x7fff];
  fVar3 = *param_2;
  *param_1 = fVar2 * param_2[2] + fVar1 * fVar3;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2] * fVar1 - fVar3 * fVar2;
  return;
}

