/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53dd10; label: FUN_0053dd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0053dd10(float *param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  if (0.0 <= (param_1[2] - in_ECX[2]) * in_EAX[2] +
             (*param_1 - *in_ECX) * *in_EAX + (param_1[1] - in_ECX[1]) * in_EAX[1]) {
    return 1;
  }
  return 0;
}

