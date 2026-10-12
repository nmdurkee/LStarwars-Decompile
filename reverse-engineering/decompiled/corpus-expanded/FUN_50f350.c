/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50f350; label: FUN_0050f350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050f350(int param_1)

{
  if ((*(int *)(param_1 + 100) == 0) && (*(int *)(param_1 + 0x68) == 0)) {
    return;
  }
  DAT_00800940 = DAT_00800958;
  FUN_00509ab0();
  return;
}

