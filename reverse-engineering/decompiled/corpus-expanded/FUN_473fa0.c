/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x473fa0; label: FUN_00473fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00473fa0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(param_2 + 4) = 0xffffffff;
    *(undefined4 *)(param_2 + 8) = 0xffffffff;
  }
  return;
}

