/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650a90; label: FUN_00650a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650a90(int param_1,undefined2 param_2)

{
  if (DAT_02962020 != 0x200) {
    *(undefined2 *)(&DAT_02921260 + DAT_02962020 * 2) = param_2;
    DAT_02962020 = DAT_02962020 + 1;
    *(short *)(&DAT_02920d8a + param_1 * 8) = *(short *)(&DAT_02920d8a + param_1 * 8) + 1;
    *(undefined2 *)(&DAT_02920d8c + param_1 * 8) = 0;
  }
  return;
}

