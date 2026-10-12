/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x555580; label: FUN_00555580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00555580(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x5c;
  }
  return 0;
}

