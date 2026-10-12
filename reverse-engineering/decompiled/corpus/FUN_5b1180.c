/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5b1180; label: FUN_005b1180
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

