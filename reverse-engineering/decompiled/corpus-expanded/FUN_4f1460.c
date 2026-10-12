/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1460; label: FUN_004f1460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f1460(undefined4 *param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    param_2 = param_1;
  }
  return *param_2;
}

