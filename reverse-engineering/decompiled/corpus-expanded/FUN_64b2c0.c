/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b2c0; label: FUN_0064b2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064b2c0(int param_1)

{
  if ((param_1 != -1) && ((&DAT_0291f7b4)[param_1 * 0x1b] != -1)) {
    DAT_02920a98 = DAT_02920a98 + -1;
    (&DAT_0291f7b4)[param_1 * 0x1b] = 0xffffffff;
  }
  return;
}

