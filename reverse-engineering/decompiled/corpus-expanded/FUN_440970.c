/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440970; label: FUN_00440970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440970(void)

{
  int in_stack_00000014;
  
  if ((*(byte *)(in_stack_00000014 + 0x9c) & 8) != 0) {
    return (float10)1;
  }
  return (float10)0;
}

