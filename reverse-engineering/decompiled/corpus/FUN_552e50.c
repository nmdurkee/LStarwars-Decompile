/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x552e50; label: FUN_00552e50
 */

undefined4 FUN_00552e50(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_005cfac0(param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_005d6170();
      FUN_005c0500(param_2,param_2,uVar2);
      uVar2 = FUN_005f33b0(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}

