/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c17c0; label: FUN_005c17c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

