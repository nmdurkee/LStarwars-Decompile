/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440b50; label: FUN_00440b50
 */

undefined4 FUN_00440b50(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (DAT_00923904 != (code *)0x0)) {
    uVar1 = (*DAT_00923904)(param_1,param_2);
    return uVar1;
  }
  return 0;
}

