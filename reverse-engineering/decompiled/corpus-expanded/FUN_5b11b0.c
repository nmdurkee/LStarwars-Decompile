/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b11b0; label: FUN_005b11b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b11b0(char param_1)

{
  int iVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 0x10) = (int)param_1;
  iVar1 = *(int *)(in_ECX + 0x24);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if ((iVar1 != -1) && (*(int *)(in_ECX + 0x14 + iVar1 * 4) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x14 + iVar1 * 4) + 8))();
  }
  return;
}

