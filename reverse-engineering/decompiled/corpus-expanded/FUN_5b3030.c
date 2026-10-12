/* Ghidra pseudocode, not original source.
 * ev_df5c673f7183b1518088ca9cd8af579ccab356651c4ba255b050ca30730f3d2f
 * Entry: 0x5b3030; label: FUN_005b3030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b3030(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_ECX;
  float *in_EDX;
  
  fVar1 = in_ECX[1];
  fVar2 = in_ECX[2];
  fVar3 = in_ECX[3];
  fVar4 = in_EDX[1];
  fVar5 = in_EDX[2];
  fVar6 = in_EDX[3];
  *param_1 = (*in_EDX - *in_ECX) * param_2 + *in_ECX;
  param_1[1] = (fVar4 - fVar1) * param_2 + fVar1;
  param_1[2] = (fVar5 - fVar2) * param_2 + fVar2;
  param_1[3] = (fVar6 - fVar3) * param_2 + fVar3;
  return;
}

