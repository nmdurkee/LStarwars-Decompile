/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a640; label: FUN_0042a640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0042a640(int param_1)

{
  if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b134) &&
      (*(float *)(param_1 + 0x21c) != 2e+06)) && (*(float *)(param_1 + 0xf28) < _DAT_02997610)) {
    return 1;
  }
  return 0;
}

