/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x473f20; label: FUN_00473f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00473f20(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x40;
  }
  return 0;
}

