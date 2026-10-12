/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69f520; label: FUN_0069f520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069f520(int param_1,int param_2)

{
  param_2 = *(int *)(param_1 + 8) + param_2;
  if (*(int *)(param_1 + 4) < param_2) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 8) = param_2;
  return 0;
}

