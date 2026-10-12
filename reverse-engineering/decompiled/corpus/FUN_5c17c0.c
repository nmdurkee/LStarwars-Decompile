/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c17c0; label: FUN_005c17c0
 */

void FUN_005c17c0(float *param_1)

{
  float *in_ECX;
  
  if (param_1[3] * in_ECX[3] + param_1[1] * in_ECX[1] + param_1[2] * in_ECX[2] + *param_1 * *in_ECX
      < 0.0) {
    *in_ECX = 0.0 - *in_ECX;
    in_ECX[1] = 0.0 - in_ECX[1];
    in_ECX[2] = 0.0 - in_ECX[2];
    in_ECX[3] = 0.0 - in_ECX[3];
  }
  return;
}

