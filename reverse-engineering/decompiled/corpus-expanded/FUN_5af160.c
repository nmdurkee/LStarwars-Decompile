/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5af160; label: FUN_005af160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_005af160(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    _sprintf(&DAT_0095e0ec,"%s%d",PTR_s_portal__00805f94,(int)*(char *)(*param_1 + 0x1a));
    return &DAT_0095e0ec;
  }
  return (undefined *)0x0;
}

