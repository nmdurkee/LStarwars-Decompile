/* Ghidra analysis pseudocode, not original source.
 * ev_ce999f6f93348d1bea0c268e5ec4785c76bf2f100732e1944453dc4f4dda8e73
 * Entry: 0x6d9540; label: FUN_006d9540
 */

void FUN_006d9540(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_02975144;
  bVar1 = false;
  iVar4 = 0;
  if (0 < param_2) {
    do {
      iVar3 = (int)*(short *)(param_1 + iVar4 * 2);
      if (iVar3 - 10U < 4) {
        bVar1 = true;
        *(undefined1 *)(iVar3 * 0x17c + 0x4e5c + iVar2) = 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
    if (bVar1) {
      return;
    }
  }
  iVar4 = 10;
  if (*(int *)(iVar2 + 0x6608) != 0) {
    iVar4 = 0xb;
  }
  *(undefined1 *)(iVar4 * 0x17c + 0x4e5c + iVar2) = 1;
  return;
}

