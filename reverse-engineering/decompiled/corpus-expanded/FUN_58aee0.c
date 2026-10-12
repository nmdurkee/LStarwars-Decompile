/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58aee0; label: FUN_0058aee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0058aee0(int param_1)

{
  if (param_1 != -1) {
    return (int)*(short *)(param_1 * 0x10 + 8 + DAT_009553dc);
  }
  return -1;
}

