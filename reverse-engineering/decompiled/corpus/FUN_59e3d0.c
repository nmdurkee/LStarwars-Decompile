/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59e3d0; label: FUN_0059e3d0
 */

void FUN_0059e3d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (DAT_0095642c < 0x10) {
    iVar3 = (-1 - param_1) * 0x70;
    iVar2 = iVar3;
    iVar5 = DAT_009562f8;
    do {
      iVar1 = (int)*(short *)(iVar2 + iVar5);
      if (iVar1 == param_1) {
        return;
      }
      if (*(short *)(iVar2 + iVar5) < 0) {
        FUN_0059e3d0(iVar1);
        iVar5 = DAT_009562f8;
      }
      else {
        *(int *)(&DAT_009563d0 + DAT_0095642c * 4) = iVar1;
        (&DAT_009562e8)[DAT_0095642c] = *(undefined1 *)(iVar5 + iVar3 + 0x60 + iVar4);
        DAT_0095642c = DAT_0095642c + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 2;
    } while (DAT_0095642c < 0x10);
  }
  return;
}

