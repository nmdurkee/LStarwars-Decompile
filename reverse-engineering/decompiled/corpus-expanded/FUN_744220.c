/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x744220; label: FUN_00744220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00744220(void)

{
  int *in_ECX;
  
  return *(uint *)(*in_ECX + 0x13c) >> 0x12 & 1;
}

