/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e4bb0; label: FUN_004e4bb0
 */

void FUN_004e4bb0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)((int)&DAT_0087a9a8 + iVar1) == param_1) {
      if (*(int *)((int)&DAT_0087a7f0 + iVar1) != 0) {
        FUN_004364e0(*(int *)((int)&DAT_0087a7f0 + iVar1),4,0);
        *(undefined4 *)((int)&DAT_0087a7f0 + iVar1) = 0;
      }
      *(undefined4 *)((int)&DAT_0087a9a8 + iVar1) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x20);
  return;
}

