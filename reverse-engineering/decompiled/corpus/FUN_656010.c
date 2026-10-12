/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x656010; label: FUN_00656010
 */

void FUN_00656010(int param_1)

{
  if (*(int *)(param_1 + 0x1cc) == 0) {
    DAT_029620a8 = *(int *)(param_1 + 0x1c8);
    if (DAT_029620a8 != 0) {
      *(undefined4 *)(DAT_029620a8 + 0x1cc) = 0;
      *(undefined4 *)(param_1 + 0x1c8) = 0;
      *(undefined4 *)(param_1 + 0x1cc) = 0;
      return;
    }
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x1cc) + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
    if (*(int *)(param_1 + 0x1c8) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0x1c8) + 0x1cc) = *(undefined4 *)(param_1 + 0x1cc);
    }
  }
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  return;
}

