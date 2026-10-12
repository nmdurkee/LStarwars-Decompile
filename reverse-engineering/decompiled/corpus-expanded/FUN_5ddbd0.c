/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5ddbd0; label: FUN_005ddbd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ddbd0(int param_1,uint param_2)

{
  if ((param_1 == 0) || (7 < param_2)) {
    DAT_0297dc38 = 0;
  }
  else if (-1 < *(int *)(param_1 + param_2 * 4)) {
    *(uint *)(param_1 + 0x20) = param_2;
    DAT_0297dc38 = param_1;
    return;
  }
  return;
}

