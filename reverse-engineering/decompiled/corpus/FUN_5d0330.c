/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0330; label: FUN_005d0330
 */

int FUN_005d0330(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0xc4);
      if ((iVar2 == -1) || (iVar2 == 0)) {
        return iVar1 + 0x40;
      }
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x40);
    if (*(int *)(iVar2 + 0x48) != 0) {
      return *(int *)(iVar2 + 0x48);
    }
  }
  return iVar2;
}

