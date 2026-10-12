/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x655940; label: FUN_00655940
 */

void FUN_00655940(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    *(undefined4 *)(param_1 + 400 + DAT_029620a4) = param_2;
    *(undefined4 *)(param_1 + 0x194 + DAT_029620a4) = param_3;
    *(undefined4 *)(param_1 + 0x198 + DAT_029620a4) = param_4;
    *(undefined4 *)(param_1 + 0x300 + DAT_029620a4) = 0;
  }
  return;
}

