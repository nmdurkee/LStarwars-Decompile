/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x655f00; label: FUN_00655f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00655f00(int param_1,undefined1 param_2)

{
  if (param_1 != -1) {
    *(undefined1 *)(param_1 * 0x330 + 0x2f7 + DAT_029620a4) = param_2;
  }
  return;
}

