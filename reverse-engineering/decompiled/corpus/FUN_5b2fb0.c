/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b2fb0; label: FUN_005b2fb0
 */

float10 FUN_005b2fb0(float *param_1)

{
  float *in_ECX;
  
  return (float10)(param_1[3] * in_ECX[3] + param_1[1] * in_ECX[1] +
                  param_1[2] * in_ECX[2] + *param_1 * *in_ECX);
}

