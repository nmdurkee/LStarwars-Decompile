/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8750; label: FUN_005f8750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005f8750(void)

{
  int in_EAX;
  int in_EDX;
  
  return -1 < *(short *)(in_EDX + 0x1c + in_EAX * 0xc);
}

