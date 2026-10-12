/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0de0; label: FUN_005c0de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c0de0(float *param_1,float *param_2)

{
  return (float10)((param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) +
                  (*param_1 - *param_2) * (*param_1 - *param_2) +
                  (param_1[1] - param_2[1]) * (param_1[1] - param_2[1]));
}

