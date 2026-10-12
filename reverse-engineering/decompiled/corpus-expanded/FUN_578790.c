/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x578790; label: FUN_00578790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00578790(int param_1,int param_2)

{
  if ((((DAT_008028b0 != -1) && (param_1 != 0)) && (*(char *)(param_1 + 0x7b5) == DAT_008028b0)) &&
     (*(short *)(param_1 + 0x7aa) == param_2)) {
    return 1;
  }
  return 0;
}

