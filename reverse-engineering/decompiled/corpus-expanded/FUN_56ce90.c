/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56ce90; label: FUN_0056ce90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056ce90(void)

{
  int in_EAX;
  
  *(byte *)(in_EAX + 0x20) = *(byte *)(in_EAX + 0x20) | 3;
  return;
}

