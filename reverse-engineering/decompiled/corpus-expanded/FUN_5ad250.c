/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad250; label: FUN_005ad250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_005ad250(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0x106);
  }
  return 0;
}

