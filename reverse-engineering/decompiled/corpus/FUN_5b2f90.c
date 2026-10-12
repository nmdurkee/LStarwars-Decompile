/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b2f90; label: FUN_005b2f90
 */

void FUN_005b2f90(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_ECX;
  
  fVar1 = in_ECX[1];
  fVar2 = in_ECX[2];
  fVar3 = in_ECX[3];
  *param_1 = 0.0 - *in_ECX;
  param_1[1] = 0.0 - fVar1;
  param_1[2] = 0.0 - fVar2;
  param_1[3] = 0.0 - fVar3;
  return;
}

