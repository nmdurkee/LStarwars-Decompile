/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440c70; label: FUN_00440c70
 */

float10 FUN_00440c70(void)

{
  int iVar1;
  int in_stack_00000014;
  
  if ((in_stack_00000014 != -1) && (DAT_0093d810 != 0)) {
    iVar1 = FUN_0055bc80(DAT_0093d810,in_stack_00000014);
    if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

