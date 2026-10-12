/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a0120; label: FUN_006a0120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a0120(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
  }
  return 0xffffffff;
}

