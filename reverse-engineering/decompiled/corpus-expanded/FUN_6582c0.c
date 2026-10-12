/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x6582c0; label: FUN_006582c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006582c0(int param_1)

{
  if (((-1 < param_1) && (param_1 < DAT_02962098)) && (*(int *)(DAT_0296209c + param_1 * 4) != 0)) {
    return *(undefined4 *)(DAT_0296209c + param_1 * 4);
  }
  return 0;
}

