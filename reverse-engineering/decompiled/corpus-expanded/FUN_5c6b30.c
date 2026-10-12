/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6b30; label: FUN_005c6b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c6b30(float *param_1,float *param_2)

{
  return (float10)(param_1[2] * param_2[2] + *param_1 * *param_2 + param_1[1] * param_2[1] +
                  param_1[3]);
}

