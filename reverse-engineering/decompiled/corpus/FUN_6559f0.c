/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x6559f0; label: FUN_006559f0
 */

void FUN_006559f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    *(undefined4 *)(param_1 + 0x1a8 + DAT_029620a4) = param_2;
    *(undefined4 *)(param_1 + 0x1ac + DAT_029620a4) = param_3;
    *(undefined4 *)(param_1 + 0x1b0 + DAT_029620a4) = param_4;
  }
  return;
}

