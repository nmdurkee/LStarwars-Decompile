/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bf470; label: FUN_005bf470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bf470(float *param_1,float *param_2,float param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_005c0240((param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
                                (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]) +
                                (*param_1 - *param_2) * (*param_1 - *param_2));
  if ((float10)param_3 < fVar1) {
    return 0;
  }
  return 1;
}

