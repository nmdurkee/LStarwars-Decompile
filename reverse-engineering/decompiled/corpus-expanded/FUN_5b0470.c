/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0470; label: FUN_005b0470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b0470(undefined4 *param_1)

{
  if (((*(byte *)((int)*param_1 + 10) & 1) != 0) && (*(float *)*param_1 <= 0.0)) {
    return 1;
  }
  return 0;
}

