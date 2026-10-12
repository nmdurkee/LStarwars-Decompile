/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68af70; label: FUN_0068af70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068af70(undefined4 param_1,int param_2)

{
  DAT_00810a88 = *(undefined4 *)(param_2 + 0xc);
  if (DAT_02921884 != -1) {
    *(undefined1 *)(DAT_02921884 * 0x50 + 0x27 + DAT_02962a14) = *(undefined1 *)(param_2 + 0xc);
  }
  FUN_00689f70();
  return;
}

