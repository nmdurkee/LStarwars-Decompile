/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655dd0; label: FUN_00655dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655dd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    *(undefined4 *)(param_1 + 0x2d0 + DAT_029620a4) = param_2;
    *(undefined4 *)(param_1 + 0x2d4 + DAT_029620a4) = param_3;
    *(undefined4 *)(param_1 + 0x2d8 + DAT_029620a4) = param_4;
  }
  return;
}

