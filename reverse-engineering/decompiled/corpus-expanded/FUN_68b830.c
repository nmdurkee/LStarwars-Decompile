/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68b830; label: FUN_0068b830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068b830(int param_1)

{
  param_1 = param_1 * 0x50;
  *(undefined4 *)(param_1 + 4 + DAT_02962a14) = 0;
  DAT_029629fc = *(undefined4 *)(param_1 + 0x4c + DAT_02962a14);
  *(undefined4 *)(param_1 + 0x4c + DAT_02962a14) = 0;
  DAT_029629e0 = DAT_029629e0 + -1;
  if (*(char *)(param_1 + 0x27 + DAT_02962a14) == '\x03') {
    *(undefined4 *)(DAT_02962a1c + *(short *)(param_1 + 0x40 + DAT_02962a14) * 4) = 0;
    DAT_02962a20 = DAT_02962a20 + -1;
  }
  FUN_00689f70();
  return;
}

