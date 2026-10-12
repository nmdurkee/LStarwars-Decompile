/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c1950; label: FUN_005c1950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1950(void)

{
  uint *in_EAX;
  uint *in_ECX;
  
  *in_ECX = *in_EAX & 0x7fffffff;
  in_ECX[1] = in_EAX[1] & 0x7fffffff;
  in_ECX[2] = in_EAX[2] & 0x7fffffff;
  in_ECX[3] = in_EAX[3] & 0x7fffffff;
  return;
}

