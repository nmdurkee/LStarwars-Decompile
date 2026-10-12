/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x561d20; label: FUN_00561d20
 */

void FUN_00561d20(int param_1)

{
  if (DAT_00802838 != -1) {
    *(char *)(param_1 + 0x7b5) = (char)DAT_00802838;
    *(undefined1 *)(param_1 + 0x7b8) = 0;
    *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c0c;
    *(undefined1 *)(param_1 + 0x7b9) = 2;
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffeafff | 0x8000;
    *(undefined4 *)(param_1 + 0xd1c) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0xd1c) = 0;
  return;
}

