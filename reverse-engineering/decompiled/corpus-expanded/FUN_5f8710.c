/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8710; label: FUN_005f8710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8710(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) + -1;
  return;
}

