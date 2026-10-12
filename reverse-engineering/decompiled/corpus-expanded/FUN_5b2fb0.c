/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b2fb0; label: FUN_005b2fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b2fb0(float *param_1)

{
  float *in_ECX;
  
  return (float10)(param_1[3] * in_ECX[3] + param_1[1] * in_ECX[1] +
                  param_1[2] * in_ECX[2] + *param_1 * *in_ECX);
}

