/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x633810; label: FUN_00633810
 */

void FUN_00633810(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    do {
      if ((*(int *)(*(int *)(in_ECX + 4) + iVar1 * 4) != 0) &&
         ((~(*(uint *)(*(int *)(*(int *)(in_ECX + 4) + iVar1 * 4) + 8) >> 2) & 1) != 0)) {
        (**(code **)(**(int **)(*(int *)(in_ECX + 4) + iVar1 * 4) + 0x10))(param_1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0xc));
  }
  return;
}

