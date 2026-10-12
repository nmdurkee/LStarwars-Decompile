/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8620; label: FUN_005a8620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8620(int *param_1,int param_2)

{
  *param_1 = param_2;
  if (param_2 != 0) {
    *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 2);
    *(undefined1 *)((int)param_1 + 5) = *(undefined1 *)(param_2 + 3);
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  return;
}

