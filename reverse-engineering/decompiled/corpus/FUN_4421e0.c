/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4421e0; label: FUN_004421e0
 */

undefined4 FUN_004421e0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((((param_2 != 0) && (param_1 != 0)) && (DAT_00923904 != (code *)0x0)) &&
     (puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2), puVar1 != (undefined4 *)0x0)) {
    return *puVar1;
  }
  return 0;
}

