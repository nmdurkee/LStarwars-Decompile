/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0aa0; label: FUN_005b0aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_005b0aa0(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return "Played";
  }
  if (param_2 != 1) {
    return "Unknown!";
  }
  return "Playing";
}

