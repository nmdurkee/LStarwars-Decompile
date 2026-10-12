/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0dd0; label: FUN_005b0dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005b0dd0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return (uint)*(ushort *)(*param_1 + 0x1a);
  }
  return 0xffffffff;
}

