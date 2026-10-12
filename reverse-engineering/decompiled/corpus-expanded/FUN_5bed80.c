/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bed80; label: FUN_005bed80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bed80(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  if (param_3 != (float *)0x0) {
    *param_3 = *param_1 - *param_2;
    param_3[1] = 0.0;
    fVar1 = param_1[2] - param_2[2];
    param_3[2] = fVar1;
    FUN_005c0240(*param_3 * *param_3 + 0.0 + fVar1 * fVar1);
    return;
  }
  FUN_005c0240((param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
               (*param_1 - *param_2) * (*param_1 - *param_2) + 0.0);
  return;
}

