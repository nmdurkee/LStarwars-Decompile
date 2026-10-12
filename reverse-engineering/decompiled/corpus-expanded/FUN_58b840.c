/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b840; label: FUN_0058b840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058b840(int param_1)

{
  if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x800000) != 0) &&
     (*(char *)(param_1 + 0x283) == '\x06')) {
    return 1;
  }
  return 0;
}

