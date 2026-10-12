/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x561d20; label: FUN_00561d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

