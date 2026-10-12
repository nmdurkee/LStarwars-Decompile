/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0370; label: FUN_005b0370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_005b0370(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x128) != 0)) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xe9);
  }
  return 0;
}

