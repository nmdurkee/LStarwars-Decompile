/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b3510; label: FUN_005b3510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b3510(float *param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  
  *param_1 = *(float *)(param_3 + 4) * param_1[1];
  fVar1 = *(float *)(param_3 + 0x14) * param_1[1];
  param_1[1] = fVar1;
  param_1[2] = fVar1 * *(float *)(param_3 + 0x24);
  return;
}

