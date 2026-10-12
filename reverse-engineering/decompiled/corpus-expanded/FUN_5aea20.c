/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5aea20; label: FUN_005aea20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005aea20(int param_1)

{
  if (param_1 != 0) {
    if (*(float *)(param_1 + 0x40) < 0.0) {
      return 1;
    }
    if (0.0 < *(float *)(param_1 + 0x40)) {
      return 0;
    }
  }
  return 0xffffffff;
}

