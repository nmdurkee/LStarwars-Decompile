/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c07c0; label: FUN_005c07c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c07c0(float *param_1,float param_2)

{
  *param_1 = param_2 * *param_1;
  param_1[1] = param_1[1] * param_2;
  param_1[2] = param_2 * param_1[2];
  param_1[4] = param_1[4] * param_2;
  param_1[5] = param_2 * param_1[5];
  param_1[6] = param_1[6] * param_2;
  param_1[8] = param_2 * param_1[8];
  param_1[9] = param_1[9] * param_2;
  param_1[10] = param_2 * param_1[10];
  return;
}

