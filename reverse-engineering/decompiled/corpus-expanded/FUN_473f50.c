/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x473f50; label: FUN_00473f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_00473f50(int *param_1)

{
  return *(byte *)(*param_1 + 99) >> 1 & 1;
}

