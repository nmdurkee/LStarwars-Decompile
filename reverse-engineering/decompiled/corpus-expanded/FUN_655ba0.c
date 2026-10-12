/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655ba0; label: FUN_00655ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655ba0(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    *(undefined2 *)(param_1 + 0x2dc + DAT_029620a4) = param_2;
    *(undefined2 *)(param_1 + 0x2de + DAT_029620a4) = param_3;
    *(undefined4 *)(param_1 + 0x2e0 + DAT_029620a4) = param_4;
    *(undefined4 *)(param_1 + 0x2e4 + DAT_029620a4) = param_5;
  }
  return;
}

