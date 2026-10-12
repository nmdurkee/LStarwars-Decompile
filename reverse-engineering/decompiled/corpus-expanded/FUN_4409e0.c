/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x4409e0; label: FUN_004409e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004409e0(void)

{
  int in_stack_00000014;
  
  if (((in_stack_00000014 != 0) && (DAT_0093d810 != 0)) &&
     (*(int *)(in_stack_00000014 + 0x38) == DAT_0093d810)) {
    return (float10)1;
  }
  return (float10)0;
}

