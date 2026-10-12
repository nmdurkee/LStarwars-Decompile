/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x470920; label: FUN_00470920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00470920(int param_1)

{
  return ~(*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) >> 0xf) & 1;
}

