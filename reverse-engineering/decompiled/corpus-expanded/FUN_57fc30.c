/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57fc30; label: FUN_0057fc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057fc30(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = param_1[2] * param_2[2] + param_1[1] * param_2[1] + *param_1 * *param_2;
  fVar1 = fVar1 + fVar1;
  *param_3 = *param_2 - fVar1 * *param_1;
  param_3[1] = param_2[1] - fVar1 * param_1[1];
  param_3[2] = param_2[2] - param_1[2] * fVar1;
  return;
}

