/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449e60; label: FUN_00449e60
 */

undefined4 FUN_00449e60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar4 = 0;
  if (0x20 < param_1) {
    param_1 = 0x20;
  }
  iVar3 = 0;
  if (0 < param_1) {
    do {
      iVar1 = *(int *)(unaff_EDI + iVar3 * 4);
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x68) & 0x40) != 0)) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1);
    if (iVar4 != 0) {
      iVar3 = FUN_0054fa60();
      iVar3 = iVar3 / ((int)(0xffff / (longlong)iVar4) + 1);
      uVar2 = *(undefined4 *)(unaff_EDI + iVar3 * 4);
      *(undefined4 *)(unaff_EDI + iVar3 * 4) = 0;
      return uVar2;
    }
  }
  return 0;
}

