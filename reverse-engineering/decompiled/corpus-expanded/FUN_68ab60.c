/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68ab60; label: FUN_0068ab60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068ab60(undefined4 param_1,int param_2)

{
  if (DAT_02921884 != -1) {
    *(undefined4 *)(DAT_02921884 * 0x50 + 0x44 + DAT_02962a14) = *(undefined4 *)(param_2 + 0x54);
  }
  FUN_00689f70();
  return;
}

