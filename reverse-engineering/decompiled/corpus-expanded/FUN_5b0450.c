/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0450; label: FUN_005b0450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005b0450(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *param_1 + 0xc;
  }
  return 0;
}

