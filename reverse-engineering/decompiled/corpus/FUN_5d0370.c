/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0370; label: FUN_005d0370
 */

int FUN_005d0370(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    return *(int *)(*(int *)(param_1 + 4) + 0x40);
  }
  if (*(int *)(param_1 + 8) != 0) {
    return *(int *)(param_1 + 8) + 0x40;
  }
  return 0;
}

