/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7d90; label: FUN_006b7d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006b7d90(void)

{
  float *in_EAX;
  
  return (float10)(in_EAX[2] * in_EAX[2] + *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1]);
}

