/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655c00; label: FUN_00655c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00655c00(int param_1)

{
  if (param_1 == -1) {
    return 0;
  }
  return (int)*(short *)(param_1 * 0x330 + 0x180 + DAT_029620a4);
}

