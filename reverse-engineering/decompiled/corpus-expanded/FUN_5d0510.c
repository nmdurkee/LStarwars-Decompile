/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d0510; label: FUN_005d0510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0510(int param_1,int param_2,undefined1 param_3)

{
  *(undefined1 *)(param_2 + *(int *)(param_1 + 4)) = param_3;
  return;
}

