/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440ad0; label: FUN_00440ad0
 */

float10 FUN_00440ad0(void)

{
  int iVar1;
  undefined4 in_stack_00000014;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&local_c,in_stack_00000014,1);
  iVar1 = FUN_005cfac0(&local_c);
  if (iVar1 != 0) {
    iVar1 = FUN_005cfd60(&local_c);
    return (float10)iVar1;
  }
  return (float10)0;
}

