/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c74e0; label: FUN_006c74e0
 */

void FUN_006c74e0(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  
  for (iVar1 = *in_ECX; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    iVar3 = 0;
    if (0 < *(int *)(iVar1 + 0x10)) {
      iVar2 = 0;
      do {
        FUN_006ba8a0(*(int *)(iVar1 + 0x14) + iVar2,0x3f000000,0xffffffff);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x10;
      } while (iVar3 < *(int *)(iVar1 + 0x10));
    }
  }
  return;
}

