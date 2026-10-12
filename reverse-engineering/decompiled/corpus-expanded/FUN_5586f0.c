/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x5586f0; label: FUN_005586f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_005586f0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xef);
  }
  return 0;
}

