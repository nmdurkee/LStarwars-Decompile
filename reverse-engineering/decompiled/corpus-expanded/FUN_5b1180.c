/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1180; label: FUN_005b1180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1180(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x24);
  if (((iVar1 != -1) && (DAT_0095e414 == 0)) && (*(int *)(in_ECX + 0x14 + iVar1 * 4) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x005b11a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(in_ECX + 0x14 + iVar1 * 4) + 0x10))();
    return;
  }
  return;
}

