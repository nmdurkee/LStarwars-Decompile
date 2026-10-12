/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8230; label: FUN_004d8230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004d8230(void)

{
  float *in_EAX;
  float *in_ECX;
  
  return (float10)(in_ECX[2] * in_EAX[2] + *in_ECX * *in_EAX + in_ECX[1] * in_EAX[1]);
}

