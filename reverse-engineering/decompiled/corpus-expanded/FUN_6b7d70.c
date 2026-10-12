/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7d70; label: FUN_006b7d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b7d70(void)

{
  float *in_EAX;
  float *in_ECX;
  
  return (float10)(in_ECX[2] * in_EAX[2] + *in_ECX * *in_EAX + in_ECX[1] * in_EAX[1]);
}

