/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6a99e0; label: FUN_006a99e0
 */

undefined4 FUN_006a99e0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (0 < *(int *)(param_1 + 8)) {
    iVar1 = FUN_006a98d0(param_1,param_2);
    if (-1 < iVar1) {
      return *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar1 * 4);
    }
  }
  return 0xffffffff;
}

