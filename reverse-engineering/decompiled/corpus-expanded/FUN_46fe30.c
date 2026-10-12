/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46fe30; label: FUN_0046fe30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0046fe30(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0x104);
  }
  return 0;
}

