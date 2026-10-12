/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b33c0; label: FUN_005b33c0
 */

void FUN_005b33c0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *param_2 - param_3[0xc];
  fVar2 = param_2[1] - param_3[0xd];
  fVar3 = param_2[2] - param_3[0xe];
  *param_1 = fVar2 * param_3[1] + fVar1 * *param_3 + fVar3 * param_3[2];
  param_1[1] = param_3[6] * fVar3 + param_3[4] * fVar1 + param_3[5] * fVar2;
  param_1[2] = fVar3 * param_3[10] + param_3[9] * fVar2 + param_3[8] * fVar1;
  return;
}

