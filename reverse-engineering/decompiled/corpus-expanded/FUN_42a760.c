/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a760; label: FUN_0042a760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0042a760(int param_1)

{
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) &&
     (*(short *)(param_1 + 0x1064) == DAT_007f1948)) {
    return (float10)2.0;
  }
  return (float10)0;
}

