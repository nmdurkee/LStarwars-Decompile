/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b32d0; label: FUN_005b32d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b32d0(float *param_1,float param_2,int param_3)

{
  *param_1 = param_2 * *(float *)(param_3 + 0x20);
  param_1[1] = *(float *)(param_3 + 0x24) * param_2;
  param_1[2] = param_2 * *(float *)(param_3 + 0x28);
  return;
}

