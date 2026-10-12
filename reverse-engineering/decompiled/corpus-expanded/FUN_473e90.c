/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x473e90; label: FUN_00473e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00473e90(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xfd);
  }
  return 0;
}

