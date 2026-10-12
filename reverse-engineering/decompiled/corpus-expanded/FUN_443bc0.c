/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443bc0; label: FUN_00443bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443bc0(void)

{
  int in_stack_00000014;
  
  if (in_stack_00000014 == 0) {
    return (float10)0;
  }
  if ((*(byte *)(in_stack_00000014 + 10) & 2) != 0) {
    return (float10)1.0;
  }
  return (float10)0.0;
}

