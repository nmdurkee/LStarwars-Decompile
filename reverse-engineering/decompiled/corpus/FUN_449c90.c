/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449c90; label: FUN_00449c90
 */

undefined4 FUN_00449c90(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 0x144) != 0)) {
    puVar1 = (uint *)(*(int *)(param_3 + 0x144) + 0x50);
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  return 1;
}

