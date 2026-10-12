/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d0ff0; label: FUN_004d0ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004d0ff0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xe8);
  }
  return 0;
}

