/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440a60; label: FUN_00440a60
 */

float10 FUN_00440a60(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if (in_stack_00000014 != 0) {
    iVar1 = FUN_0055a1b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014,1,1);
    if (iVar1 == 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

