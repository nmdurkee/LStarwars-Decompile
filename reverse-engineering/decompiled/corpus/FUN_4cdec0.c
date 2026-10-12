/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cdec0; label: FUN_004cdec0
 */

void FUN_004cdec0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_005cf5b0(*(undefined4 *)(DAT_00880610 + 0x13c),DAT_00880608 + 0x50,
                 *(undefined4 *)(param_1 + 0x510),1);
  }
  return;
}

