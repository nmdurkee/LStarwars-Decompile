/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0420; label: FUN_005d0420
 */

int FUN_005d0420(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    return *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x40) + 0x48);
  }
  if (((*(int *)(param_1 + 8) == 0) || (iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc4), iVar1 == -1)
      ) || (iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

