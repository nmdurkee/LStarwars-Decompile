/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56a860; label: FUN_0056a860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056a860(int param_1)

{
  if (param_1 == 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(param_1 + 0x50bc);
}

