/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b8400; label: FUN_006b8400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8400(float *param_1,float param_2)

{
  float *in_ECX;
  
  param_2 = 1.0 / param_2;
  *param_1 = param_2 * *in_ECX;
  param_1[1] = in_ECX[1] * param_2;
  param_1[2] = param_2 * in_ECX[2];
  return;
}

