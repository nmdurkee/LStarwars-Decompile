/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d0e0; label: FUN_0056d0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056d0e0(int *param_1)

{
  if (((*(byte *)(*param_1 + 0x20) & 2) != 0) && ((*(byte *)(*param_1 + 0x20) & 1) != 0)) {
    return 1;
  }
  return 0;
}

