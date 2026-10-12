/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655fe0; label: FUN_00655fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655fe0(int param_1)

{
  if (DAT_029620a8 != 0) {
    *(int *)(DAT_029620a8 + 0x1cc) = param_1;
  }
  *(int *)(param_1 + 0x1c8) = DAT_029620a8;
  DAT_029620a8 = param_1;
  return;
}

