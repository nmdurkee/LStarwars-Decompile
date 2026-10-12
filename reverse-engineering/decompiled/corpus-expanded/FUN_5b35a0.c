/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b35a0; label: FUN_005b35a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b35a0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)(&DAT_029899a0)[param_3 + 0x4000 >> 1 & 0x7fff];
  fVar2 = (float)(&DAT_029899a0)[param_3 >> 1 & 0x7fff];
  fVar3 = (float)param_2[1];
  *param_1 = *param_2;
  param_1[1] = fVar1 * fVar3 - fVar2 * (float)param_2[2];
  param_1[2] = fVar3 * fVar2 + fVar1 * (float)param_2[2];
  return;
}

