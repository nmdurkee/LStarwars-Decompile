/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d81f0; label: FUN_004d81f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d81f0(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *param_1 = *in_ECX - *in_EAX;
  param_1[1] = in_ECX[1] - in_EAX[1];
  param_1[2] = in_ECX[2] - in_EAX[2];
  return;
}

