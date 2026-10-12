/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af1a0; label: FUN_005af1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005af1a0(int *param_1)

{
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && ((*(byte *)(*param_1 + 0x1c) & 1) != 0)) {
    return 1;
  }
  return 0;
}

