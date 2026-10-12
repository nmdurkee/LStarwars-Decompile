/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x744290; label: FUN_00744290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00744290(void)

{
  int *in_ECX;
  
  return CONCAT31((int3)((uint)*in_ECX >> 8),*(char *)(*in_ECX + 0x1b4) != '\0');
}

