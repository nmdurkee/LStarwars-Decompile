/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c4d0; label: FUN_0069c4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069c4d0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x48) != 0) && (*(int *)(param_1 + 4) != 0)) {
    if (2 < *(int *)(param_1 + 0x58)) {
      FUN_006a1ae0(param_1 + 0x1e0);
      FUN_006a1630(param_1 + 0x250);
      *(undefined4 *)(param_1 + 0x58) = 2;
    }
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x34)) {
      iVar2 = 0;
      do {
        iVar1 = FUN_006a1470(*(int *)(param_1 + 0x48) + iVar2,param_2);
        if (iVar1 != 0) {
          FUN_0069c4d0(param_1,0);
          return 0xffffff7d;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar3 < *(int *)(param_1 + 0x34));
    }
    return 0;
  }
  return 0xffffff7d;
}

