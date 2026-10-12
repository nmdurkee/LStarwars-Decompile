/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x5026f0; label: FUN_005026f0
 */

void FUN_005026f0(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *unaff_EDI;
  
  uVar5 = 0;
  if ((short)unaff_EDI[1] != 0) {
    iVar6 = 0;
    iVar4 = 0;
    do {
      iVar2 = *param_1;
      iVar3 = *unaff_EDI;
      *(undefined1 *)(iVar2 + iVar6 + 0xc) = 0;
      bVar1 = *(byte *)(iVar3 + iVar4 + 0x58);
      if (((bVar1 & 4) != 0) && ((bVar1 & 2) != 0)) {
        *(byte *)(iVar2 + iVar6 + 0xd) = bVar1 & 1;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x5c;
      iVar6 = iVar6 + 0x10;
    } while (uVar5 < *(ushort *)(unaff_EDI + 1));
  }
  return;
}

