/* Ghidra pseudocode, not original source.
 * ev_f814ac66c7176acc11aba85969a47ad0d72f6a74214126b9ee26f1e14042bc0b
 * Entry: 0x5c1530; label: FUN_005c1530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c1530(void)

{
  int in_EAX;
  
  *(float *)(in_EAX + 8) = -*(float *)(in_EAX + 8);
  *(float *)(in_EAX + 0x18) = -*(float *)(in_EAX + 0x18);
  *(float *)(in_EAX + 0x20) = -*(float *)(in_EAX + 0x20);
  *(float *)(in_EAX + 0x24) = -*(float *)(in_EAX + 0x24);
  *(float *)(in_EAX + 0x2c) = -*(float *)(in_EAX + 0x2c);
  *(float *)(in_EAX + 0x38) = -*(float *)(in_EAX + 0x38);
  return;
}

