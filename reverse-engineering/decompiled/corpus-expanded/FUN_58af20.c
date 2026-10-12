/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58af20; label: FUN_0058af20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0058af20(int param_1,uint param_2)

{
  if (param_1 == -1) {
    return 0;
  }
  if (param_2 != 0) {
    return *(ushort *)(param_1 * 0x10 + 10 + DAT_009553dc) & param_2;
  }
  return (uint)*(ushort *)(param_1 * 0x10 + 10 + DAT_009553dc);
}

