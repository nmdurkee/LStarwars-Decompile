/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440a00; label: FUN_00440a00
 */

float10 FUN_00440a00(void)

{
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) &&
     (((DAT_0093d810 != 0 && (*(int *)(in_stack_00000014 + 0x38) == DAT_0093d810)) ||
      ((DAT_0093d814 != 0 && (*(int *)(in_stack_00000014 + 0x38) == DAT_0093d814)))))) {
    return (float10)1;
  }
  return (float10)0;
}

