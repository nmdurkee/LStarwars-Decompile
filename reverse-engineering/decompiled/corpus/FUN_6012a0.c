/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x6012a0; label: FUN_006012a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006012a0(float param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  _DAT_028571e8 = _DAT_028571e8 + param_1;
  if (DAT_0080e9e4 != 0) {
    iVar5 = 0;
    if (0 < DAT_009739b8) {
      do {
        iVar1 = (&DAT_009739bc)[iVar5];
        if ((*(int *)(*(int *)(iVar1 + 0x78) + 0x158) != 0) &&
           (iVar4 = 0, 0 < *(int *)(iVar1 + 0x4c))) {
          do {
            iVar3 = 4;
            puVar2 = (undefined4 *)(*(int *)(*(int *)(iVar1 + 0x50) + iVar4 * 4) + 0x1d4);
            do {
              puVar2[-1] = 0;
              iVar3 = iVar3 + -1;
              *puVar2 = 0;
              puVar2 = puVar2 + 2;
            } while (iVar3 != 0);
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(int *)(iVar1 + 0x4c));
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_009739b8);
    }
    DAT_0080e9e4 = 0;
  }
  return;
}

