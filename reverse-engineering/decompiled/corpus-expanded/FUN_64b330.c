/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b330; label: FUN_0064b330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064b330(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  if ((param_1 != -1) && ((&DAT_0291f7b4)[param_1 * 0x1b] != -1)) {
    (&DAT_0291f7d8)[param_1 * 0x36] = param_4;
    (&DAT_0291f7d6)[param_1 * 0x36] = param_3;
    (&DAT_0291f7d4)[param_1 * 0x36] = param_2;
  }
  return;
}

