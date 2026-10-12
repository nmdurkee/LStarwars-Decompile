/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0fa0; label: FUN_005c0fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c0fa0(float *param_1,float *param_2,float *param_3,float param_4)

{
  if (param_2[3] * param_3[3] +
      param_2[2] * param_3[2] + param_2[1] * param_3[1] + *param_2 * *param_3 < 0.0) {
    *param_1 = param_4 * (*param_2 + *param_3) - *param_2;
    param_1[1] = (param_2[1] + param_3[1]) * param_4 - param_2[1];
    param_1[2] = (param_2[2] + param_3[2]) * param_4 - param_2[2];
    param_1[3] = (param_2[3] + param_3[3]) * param_4 - param_2[3];
    return;
  }
  *param_1 = *param_2 + param_4 * (*param_3 - *param_2);
  param_1[1] = (param_3[1] - param_2[1]) * param_4 + param_2[1];
  param_1[2] = (param_3[2] - param_2[2]) * param_4 + param_2[2];
  param_1[3] = (param_3[3] - param_2[3]) * param_4 + param_2[3];
  return;
}

