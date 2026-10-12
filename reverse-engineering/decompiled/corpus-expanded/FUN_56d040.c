/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d040; label: FUN_0056d040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0056d040(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf8);
  }
  return 0;
}

