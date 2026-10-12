/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b11e0; label: FUN_005b11e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b11e0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 0x14))();
  (**(code **)(*param_1 + 4))();
  *(int **)(in_ECX + 0x14 + iVar1 * 4) = param_1;
  return 1;
}

