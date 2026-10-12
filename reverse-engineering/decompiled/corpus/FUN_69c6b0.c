/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69c6b0; label: FUN_0069c6b0
 */

longlong FUN_0069c6b0(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  if (((1 < *(int *)(param_1 + 0x58)) && (*(int *)(param_1 + 4) != 0)) &&
     (param_2 < *(int *)(param_1 + 0x34))) {
    if (-1 < param_2) {
      return CONCAT44(*(undefined4 *)(*(int *)(param_1 + 0x44) + 0xc + param_2 * 0x10),
                      *(undefined4 *)(*(int *)(param_1 + 0x44) + 8 + param_2 * 0x10));
    }
    lVar1 = 0;
    lVar3 = 0;
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x34)) {
      do {
        lVar3 = FUN_0069c6b0(param_1,iVar2);
        lVar3 = lVar3 + lVar1;
        iVar2 = iVar2 + 1;
        lVar1 = lVar3;
      } while (iVar2 < *(int *)(param_1 + 0x34));
    }
    return lVar3;
  }
  return -0x83;
}

