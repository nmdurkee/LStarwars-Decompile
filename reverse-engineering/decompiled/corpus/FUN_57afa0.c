/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57afa0; label: FUN_0057afa0
 */

void FUN_0057afa0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x10) {
      FUN_004f1f10(DAT_00951c4c + 0xf4,*(undefined4 *)(param_1 + 0x510));
    }
  }
  return;
}

