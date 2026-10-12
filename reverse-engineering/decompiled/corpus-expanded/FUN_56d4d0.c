/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d4d0; label: FUN_0056d4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d4d0(void)

{
  int in_EAX;
  
  *(byte *)(in_EAX + 0x34) = *(byte *)(in_EAX + 0x34) | 3;
  *(float *)(in_EAX + 0x28) = *(float *)(in_EAX + 0x1c) + *(float *)(in_EAX + 0x14);
  *(float *)(in_EAX + 0x2c) = *(float *)(in_EAX + 0x20) * *(float *)(in_EAX + 0x20);
  return;
}

