/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c640; label: FUN_0069c640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

longlong FUN_0069c640(int param_1,int param_2)

{
  uint *puVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  
  if (((1 < *(int *)(param_1 + 0x58)) && (*(int *)(param_1 + 4) != 0)) &&
     (param_2 < *(int *)(param_1 + 0x34))) {
    if (-1 < param_2) {
      puVar1 = (uint *)(*(int *)(param_1 + 0x38) + param_2 * 8);
      return CONCAT44((*(int *)(*(int *)(param_1 + 0x38) + 0xc + param_2 * 8) - puVar1[1]) -
                      (uint)(puVar1[2] < *puVar1),puVar1[2] - *puVar1);
    }
    lVar2 = 0;
    lVar4 = 0;
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x34)) {
      do {
        lVar4 = FUN_0069c640(param_1,iVar3);
        lVar4 = lVar4 + lVar2;
        iVar3 = iVar3 + 1;
        lVar2 = lVar4;
      } while (iVar3 < *(int *)(param_1 + 0x34));
    }
    return lVar4;
  }
  return -0x83;
}

