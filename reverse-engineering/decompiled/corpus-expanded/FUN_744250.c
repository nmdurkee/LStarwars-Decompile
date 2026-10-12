/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x744250; label: FUN_00744250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00744250(void)

{
  int *in_ECX;
  
  if (((*(uint *)(*in_ECX + 0x13c) & 0x30000) != 0) &&
     ((*(uint *)(*in_ECX + 0x13c) & 0x400000) != 0)) {
    return 1;
  }
  return 0;
}

