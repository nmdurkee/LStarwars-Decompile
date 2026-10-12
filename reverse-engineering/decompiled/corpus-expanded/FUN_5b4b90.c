/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b4b90; label: FUN_005b4b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

