/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4cdfe0; label: FUN_004cdfe0
 */

void FUN_004cdfe0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    FUN_0055aa60(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_007fd1e4,
                 *(undefined4 *)(param_1 + 0x510),DAT_00880608,0x40);
  }
  return;
}

