/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6990; label: FUN_005c6990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c6990(float *param_1,float *param_2)

{
  return (float10)(param_1[2] * param_2[2] + *param_1 * *param_2 + param_1[1] * param_2[1]);
}

