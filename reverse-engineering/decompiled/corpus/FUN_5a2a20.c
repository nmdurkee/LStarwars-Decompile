/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a2a20; label: FUN_005a2a20
 */

void FUN_005a2a20(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_005a2210(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 != -1) {
      *(undefined4 *)(DAT_00956620 + 0x46fc + iVar1 * 4) = *(undefined4 *)(DAT_00956620 + 0x46f8);
    }
  }
  return;
}

