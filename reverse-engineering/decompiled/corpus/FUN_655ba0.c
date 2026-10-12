/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x655ba0; label: FUN_00655ba0
 */

void FUN_00655ba0(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    *(undefined2 *)(param_1 + 0x2dc + DAT_029620a4) = param_2;
    *(undefined2 *)(param_1 + 0x2de + DAT_029620a4) = param_3;
    *(undefined4 *)(param_1 + 0x2e0 + DAT_029620a4) = param_4;
    *(undefined4 *)(param_1 + 0x2e4 + DAT_029620a4) = param_5;
  }
  return;
}

