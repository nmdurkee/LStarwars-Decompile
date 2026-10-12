/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b4b90; label: FUN_005b4b90
 */

float * FUN_005b4b90(float *param_1,float *param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005c0240(param_2[2] * param_2[2] +
                                *param_2 * *param_2 + param_2[1] * param_2[1]);
  *param_1 = (float)fVar1;
  fVar1 = (float10)FUN_005c0240(param_2[6] * param_2[6] +
                                param_2[4] * param_2[4] + param_2[5] * param_2[5]);
  param_1[1] = (float)fVar1;
  fVar1 = (float10)FUN_005c0240(param_2[10] * param_2[10] +
                                param_2[8] * param_2[8] + param_2[9] * param_2[9]);
  param_1[2] = (float)fVar1;
  return param_1;
}

