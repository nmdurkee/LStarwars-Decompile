/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48f6c0; label: FUN_0048f6c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048f6c0(int param_1,undefined4 *param_2)

{
  if (*(int *)(param_1 + 0x128) == DAT_00951b88) {
    *param_2 = 0;
    return;
  }
  if (*(int *)(param_1 + 0x128) == DAT_00951b9c) {
    *param_2 = 0x12;
  }
  return;
}

