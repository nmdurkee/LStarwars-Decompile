/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fd9f0; label: FUN_005fd9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fd9f0(int param_1)

{
  if (param_1 != 0) {
    FUN_006e5590(0,*(undefined4 *)(param_1 + 8),0,0x20);
    FUN_006e4980(4,*(undefined4 *)(param_1 + 0xc),*(int *)(param_1 + 4) * 2);
  }
  return;
}

