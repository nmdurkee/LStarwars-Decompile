/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x440120; label: FUN_00440120
 */

undefined4 FUN_00440120(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if (DAT_00923904 != (code *)0x0) {
    puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2);
    if (puVar1 != (undefined4 *)0x0) {
      return *puVar1;
    }
  }
  return 0;
}

