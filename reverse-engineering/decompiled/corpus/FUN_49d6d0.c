/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49d6d0; label: FUN_0049d6d0
 */

undefined4 FUN_0049d6d0(int param_1)

{
  if (DAT_00802818 != -1) {
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0x4f;
    *(undefined4 *)(param_1 + 0x784) = 0x3ecccccd;
    *(undefined2 *)(param_1 + 0x7aa) = 0x93;
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    *(undefined4 *)(param_1 + 0x798) = 0;
    return 1;
  }
  return 0;
}

