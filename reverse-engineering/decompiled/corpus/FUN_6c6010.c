/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6010; label: FUN_006c6010
 */

void FUN_006c6010(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_006c5f80(param_1);
  iVar2 = *(int *)(in_ECX + 0x18);
  if (iVar2 < 1) {
    iVar2 = *(int *)(in_ECX + 0xc);
    if ((iVar2 < 0) || (DAT_02973ba4 <= iVar2)) {
      iVar2 = 0;
    }
    else {
      iVar2 = DAT_02973b8c + iVar2 * 0xc;
    }
    iVar2 = *(int *)(iVar2 + 4);
  }
  if ((0 < param_2) && (param_2 < iVar2)) {
    iVar1 = *(int *)(in_ECX + 0xc);
    if ((-1 < iVar1) && (iVar1 < DAT_02973ba4)) {
      FUN_006b7c40(*(undefined4 *)(DAT_02973b8c + iVar1 * 0xc),iVar2);
      return;
    }
    FUN_006b7c40(uRam00000000,iVar2);
  }
  return;
}

