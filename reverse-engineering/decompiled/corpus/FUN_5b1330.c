/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b1330; label: FUN_005b1330
 */

void FUN_005b1330(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  iVar2 = *piVar1;
  if ((*(byte *)(piVar1 + 4) & 1) == 0) {
    piVar1[1] = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 8) = 0x40000000;
  }
  else {
    piVar1[1] = 0x3f800000;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 8) = 0xbfaaaaab;
  }
  do {
    iVar3 = FUN_0054fa60();
    **(int **)(in_ECX + 4) = 1 << ((byte)((int)(iVar3 + (iVar3 >> 0x1f & 0x3fffU)) >> 0xe) & 0x1f);
  } while (**(int **)(in_ECX + 4) == iVar2);
  return;
}

