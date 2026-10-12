/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440be0; label: FUN_00440be0
 */

float10 FUN_00440be0(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) && ((*(ushort *)(in_stack_00000014 + 0x13a) & 0x30) == 0)) {
    return (float10)1;
  }
  return (float10)0;
}

