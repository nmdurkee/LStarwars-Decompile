/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57b290; label: FUN_0057b290
 */

void FUN_0057b290(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 < 0x40) {
      FUN_004f1f10(DAT_00951c4c + 0x104,*(undefined4 *)(param_1 + 0x510));
      *(undefined1 *)(DAT_00951c4c + 0xee) = 1;
    }
  }
  return;
}

