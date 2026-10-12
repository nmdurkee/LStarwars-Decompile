/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b2f0; label: FUN_0064b2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064b2f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_1 != -1) && ((&DAT_0291f7b4)[param_1 * 0x1b] != -1)) {
    (&DAT_0291f7a8)[param_1 * 0x1b] = param_2;
    (&DAT_0291f7ac)[param_1 * 0x1b] = param_3;
    (&DAT_0291f7b0)[param_1 * 0x1b] = param_4;
  }
  return;
}

