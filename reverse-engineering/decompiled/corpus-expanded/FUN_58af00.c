/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58af00; label: FUN_0058af00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0058af00(int param_1)

{
  if (param_1 != -1) {
    return (float10)*(float *)(param_1 * 0x10 + 0xc + DAT_009553dc);
  }
  return (float10)0;
}

