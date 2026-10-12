/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f4a0; label: FUN_0061f4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0061f4a0(void)

{
  int in_EAX;
  
  return (*(uint *)(in_EAX + 0x1c) & DAT_02912ec8) != 0;
}

