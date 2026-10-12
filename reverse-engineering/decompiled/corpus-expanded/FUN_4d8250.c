/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8250; label: FUN_004d8250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004d8250(void)

{
  float *in_EAX;
  
  return (float10)(in_EAX[2] * in_EAX[2] + *in_EAX * *in_EAX + in_EAX[1] * in_EAX[1]);
}

