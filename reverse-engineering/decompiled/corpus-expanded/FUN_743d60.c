/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x743d60; label: FUN_00743d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00743d60(void)

{
  int in_ECX;
  
  switch((*(int *)(in_ECX + 4) << 4) >> 0x1c) {
  case 1:
    FUN_00741f90();
    return;
  case 2:
    FUN_00741fd0();
    return;
  case 3:
    FUN_00743bf0();
    return;
  default:
    return;
  }
}

