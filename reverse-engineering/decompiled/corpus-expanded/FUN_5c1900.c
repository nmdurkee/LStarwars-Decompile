/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c1900; label: FUN_005c1900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c1900(void)

{
  float *in_EAX;
  float *in_ECX;
  
  return (float10)(in_ECX[2] * in_EAX[2] + *in_ECX * *in_EAX + in_ECX[1] * in_EAX[1]);
}

