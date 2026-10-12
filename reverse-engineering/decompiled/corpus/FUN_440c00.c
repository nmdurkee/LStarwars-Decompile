/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440c00; label: FUN_00440c00
 */

undefined4 FUN_00440c00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_2 != 0) && (param_1 != 0)) && (DAT_0093b280 != 0)) {
    uVar1 = FUN_0055bc20(param_2);
    return uVar1;
  }
  return 0xffffffff;
}

