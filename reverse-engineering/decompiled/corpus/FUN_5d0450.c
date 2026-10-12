/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0450; label: FUN_005d0450
 */

undefined4 FUN_005d0450(int param_1,int param_2)

{
  if (((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 4) != *(int *)(param_2 + 4))) &&
     ((*(int *)(param_1 + 8) == 0 || (*(int *)(param_1 + 8) != *(int *)(param_2 + 8))))) {
    return 0;
  }
  return 1;
}

