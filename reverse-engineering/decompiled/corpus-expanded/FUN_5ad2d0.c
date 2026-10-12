/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad2d0; label: FUN_005ad2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005ad2d0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *param_1 + 8;
  }
  return 0;
}

