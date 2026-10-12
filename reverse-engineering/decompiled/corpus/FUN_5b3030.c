/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b3030; label: FUN_005b3030
 */

void FUN_005b3030(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_ECX;
  float *in_EDX;
  
  fVar1 = in_ECX[1];
  fVar2 = in_ECX[2];
  fVar3 = in_ECX[3];
  fVar4 = in_EDX[1];
  fVar5 = in_EDX[2];
  fVar6 = in_EDX[3];
  *param_1 = (*in_EDX - *in_ECX) * param_2 + *in_ECX;
  param_1[1] = (fVar4 - fVar1) * param_2 + fVar1;
  param_1[2] = (fVar5 - fVar2) * param_2 + fVar2;
  param_1[3] = (fVar6 - fVar3) * param_2 + fVar3;
  return;
}

