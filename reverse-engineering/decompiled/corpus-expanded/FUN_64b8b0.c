/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b8b0; label: FUN_0064b8b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0064b8b0(int param_1,int param_2)

{
  if ((&DAT_0291f7b4)[param_1 * 0x1b] != param_2) {
    if ((&DAT_0291f7b4)[param_1 * 0x1b] != -1) {
      DAT_02920a98 = DAT_02920a98 + -1;
      (&DAT_0291f7b4)[param_1 * 0x1b] = 0xffffffff;
    }
    FUN_00684ee0(&DAT_0291f7f0 + param_1 * 0x1b,param_2,(&DAT_0291f7a8)[param_1 * 0x1b],
                 (&DAT_0291f7ac)[param_1 * 0x1b],(&DAT_0291f7b0)[param_1 * 0x1b]);
    (&DAT_0291f7b4)[param_1 * 0x1b] = param_2;
  }
  return param_1;
}

