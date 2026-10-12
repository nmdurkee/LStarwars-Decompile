/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a1f10; label: FUN_005a1f10
 */

void FUN_005a1f10(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x10) {
      FUN_004f1f10(DAT_00956624 + 0x14,*(undefined4 *)(param_1 + 0x510));
    }
  }
  return;
}

