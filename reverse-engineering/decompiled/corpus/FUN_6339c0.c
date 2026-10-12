/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6339c0; label: FUN_006339c0
 */

void FUN_006339c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    do {
      if ((*(int *)(*(int *)(in_ECX + 4) + iVar2 * 4) != 0) &&
         (iVar1 = *(int *)(*(int *)(in_ECX + 4) + iVar2 * 4),
         (~(*(uint *)(iVar1 + 8) >> 7) & 1) != 0)) {
        if (*(int *)(iVar1 + 0xc) != 0) {
          FUN_005d8400(*(undefined4 *)(in_ECX + 0x18),1,&PTR_DAT_0076b270);
        }
        (**(code **)(**(int **)(*(int *)(in_ECX + 4) + iVar2 * 4) + 0x24))(param_1);
        if (*(int *)(*(int *)(*(int *)(in_ECX + 4) + iVar2 * 4) + 0xc) != 0) {
          FUN_005d8440(*(undefined4 *)(in_ECX + 0x18),1);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0xc));
  }
  return;
}

