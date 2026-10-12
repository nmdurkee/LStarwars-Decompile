/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440f10; label: FUN_00440f10
 */

undefined4 FUN_00440f10(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (DAT_00923904 != (code *)0x0)) {
    uVar1 = (*DAT_00923904)(param_1,param_2);
    return uVar1;
  }
  return 0;
}

