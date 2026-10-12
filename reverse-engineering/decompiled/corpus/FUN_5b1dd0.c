/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b1dd0; label: FUN_005b1dd0
 */

void FUN_005b1dd0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (0 < *(int *)(param_3 + 0x46d4))) &&
     (iVar3 = 0, 0 < *(int *)(param_3 + 0x46d4))) {
    iVar2 = 0;
    do {
      iVar1 = (int)*(short *)(*(int *)(param_3 + 0x46d8) + 6 + iVar2);
      if (iVar1 != -1) {
        *(int *)(param_1 + *param_2 * 4) = iVar1;
        *param_2 = *param_2 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < *(int *)(param_3 + 0x46d4));
  }
  return;
}

