/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x5801a0; label: FUN_005801a0
 */

void FUN_005801a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0xf) {
      FUN_004f1f10(DAT_00951cc0,*(undefined4 *)(param_1 + 0x510));
    }
  }
  return;
}

