/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x6355b0; label: FUN_006355b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006355b0(int param_1,undefined *param_2)

{
  if (param_1 < 0x10) {
    (&PTR_DAT_0080fe20)[param_1] = param_2;
  }
  return;
}

