/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b11e0; label: FUN_005b11e0
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

