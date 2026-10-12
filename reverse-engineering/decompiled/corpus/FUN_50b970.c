/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50b970; label: FUN_0050b970
 */

int FUN_0050b970(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (int)(param_2 + (param_2 >> 0x1f & 3U)) >> 2;
  iVar3 = 0x5c0999;
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar3 = iVar3 + *(int *)(param_1 + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return iVar3;
}

