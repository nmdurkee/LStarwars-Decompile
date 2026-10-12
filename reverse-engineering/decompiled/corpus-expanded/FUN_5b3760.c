/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b3760; label: FUN_005b3760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b3760(float *param_1,float param_2,int param_3)

{
  float fVar1;
  
  fVar1 = (float)(&DAT_029899a0)[param_3 >> 1 & 0x7fff];
  *param_1 = param_2 * (float)(&DAT_029899a0)[param_3 + 0x4000 >> 1 & 0x7fff];
  param_1[1] = 0.0;
  param_1[2] = -param_2 * fVar1;
  return;
}

