/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x7442c0; label: FUN_007442c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_007442c0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) == 0;
}

