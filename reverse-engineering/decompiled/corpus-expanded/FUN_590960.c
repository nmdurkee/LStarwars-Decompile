/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x590960; label: FUN_00590960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00590960(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf0);
  }
  return 0;
}

