/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440970; label: FUN_00440970
 */

float10 FUN_00440970(void)

{
  int in_stack_00000014;
  
  if ((*(byte *)(in_stack_00000014 + 0x9c) & 8) != 0) {
    return (float10)1;
  }
  return (float10)0;
}

