/* Ghidra pseudocode, not original source.
 * ev_34a04326d91df5bb42d5c22e728fef19b8a2cbdf7cdfa233c070a8d9e179de50
 * Entry: 0x7438d0; label: FUN_007438d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_007438d0(void)

{
  int in_EAX;
  int in_EDX;
  
  return -1 < *(short *)(in_EDX + 0x1c + in_EAX * 0xc);
}

