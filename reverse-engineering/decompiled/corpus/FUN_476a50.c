/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x476a50; label: FUN_00476a50
 */

undefined4 FUN_00476a50(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  if (DAT_00951b6c != '\0') {
    iVar4 = 0;
    DAT_00879598 = 0;
    if ('\0' < DAT_00951b6d) {
      do {
        (&DAT_0087a840)[iVar4] = (&DAT_00951928)[iVar4];
        iVar2 = FUN_00594960((int)(short)(&DAT_00951928)[iVar4]);
        if (iVar2 != 0) {
          *(undefined4 *)(&DAT_008795a8 + DAT_00879598 * 2) = (&DAT_00951928)[iVar4];
          DAT_00879598 = DAT_00879598 + 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_00951b6d);
    }
    iVar4 = DAT_00879598;
    (&DAT_008795a8)[DAT_00879598 * 2] = 0xffff;
    if (3 < iVar4) {
      iVar4 = 0x40;
      do {
        iVar2 = FUN_0054fa60();
        iVar2 = iVar2 / ((int)(0xffff / (longlong)(DAT_00879598 + -2)) + 1);
        iVar3 = FUN_0054fa60();
        iVar3 = (iVar3 / ((int)(0xffff / (longlong)(DAT_00879598 + -3)) + 1) + iVar2) %
                (DAT_00879598 + -2);
        uVar1 = *(undefined4 *)(&DAT_008795b0 + iVar2 * 4);
        *(undefined4 *)(&DAT_008795a8 + (iVar2 + 2) * 2) =
             *(undefined4 *)(&DAT_008795b0 + iVar3 * 4);
        *(undefined4 *)(&DAT_008795b0 + iVar3 * 4) = uVar1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    DAT_0093b29c = 1;
    DAT_0093b2a4 = 1;
    uVar1 = 1;
  }
  return uVar1;
}

