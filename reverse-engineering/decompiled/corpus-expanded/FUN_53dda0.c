/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53dda0; label: FUN_0053dda0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0053dda0(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  return (float10)((param_1[2] - in_ECX[2]) * in_EAX[2] +
                  (*param_1 - *in_ECX) * *in_EAX + (param_1[1] - in_ECX[1]) * in_EAX[1]);
}

