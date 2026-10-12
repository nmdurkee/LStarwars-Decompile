/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b34e0; label: FUN_005b34e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b34e0(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_1;
  fVar2 = *param_3;
  *param_1 = fVar1 * fVar2;
  param_1[1] = fVar1 * fVar2 * param_3[4];
  param_1[2] = param_3[8] * *param_1;
  return;
}

