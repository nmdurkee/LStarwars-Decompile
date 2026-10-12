/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c16f0; label: FUN_005c16f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c16f0(float param_1)

{
  float *in_EAX;
  float *in_ECX;
  
  *in_ECX = param_1 * *in_EAX;
  in_ECX[1] = in_EAX[1] * param_1;
  in_ECX[2] = param_1 * in_EAX[2];
  return;
}

