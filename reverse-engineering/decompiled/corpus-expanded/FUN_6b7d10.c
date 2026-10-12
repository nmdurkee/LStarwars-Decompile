/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7d10; label: FUN_006b7d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b7d10(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *param_1 = *in_ECX - *in_EAX;
  param_1[1] = in_ECX[1] - in_EAX[1];
  param_1[2] = in_ECX[2] - in_EAX[2];
  return;
}

