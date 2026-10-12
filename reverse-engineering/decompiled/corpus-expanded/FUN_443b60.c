/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443b60; label: FUN_00443b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443b60(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_0055a320(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014);
    return (float10)iVar1;
  }
  return (float10)0;
}

