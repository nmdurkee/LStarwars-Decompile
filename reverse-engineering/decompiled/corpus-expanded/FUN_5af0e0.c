/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af0e0; label: FUN_005af0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005af0e0(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x13c) != 0)) {
    return *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x6c);
  }
  return 0;
}

