/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b11b0; label: FUN_005b11b0
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

