/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449e60; label: FUN_00449e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

