/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b7f0; label: FUN_0058b7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058b7f0(int param_1)

{
  if (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x2000000) == 0) &&
     (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x800) == 0 ||
      (*(char *)(param_1 + 0x280) != -1)))) {
    return 0;
  }
  return 1;
}

