/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441d50; label: FUN_00441d50
 */

undefined4 FUN_00441d50(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 != 0) && (DAT_00923904 != (code *)0x0)) {
    puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2);
    if (puVar1 != (undefined4 *)0x0) {
      return *puVar1;
    }
  }
  return 0;
}

