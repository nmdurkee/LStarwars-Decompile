/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x476840; label: FUN_00476840
 */

void FUN_00476840(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  
  iVar3 = (int)*(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
  iVar6 = 0;
  DAT_00879598 = 0;
  FUN_00489150(param_1);
  iVar5 = iVar3 * 0x9c;
  if ((*(byte *)(iVar5 + 0x7a + DAT_00951354) & 5) == 5) {
    if (0 < DAT_0087b2c4) {
      do {
        iVar3 = (int)*(short *)(&DAT_0087a840 + iVar6);
        if (((((*(uint *)(iVar3 * 0x4c + 4 + DAT_0093b274) & 0x4000000) != 0) &&
             (iVar5 = FUN_00594250(iVar3,DAT_00855f24,DAT_00855f2a), iVar5 != -1)) &&
            (iVar3 != DAT_0093d590)) &&
           ((iVar3 != DAT_0093d592 && (iVar3 = FUN_00594960(iVar3), iVar3 != 0)))) {
          *(undefined4 *)(&DAT_008795a8 + DAT_00879598 * 2) = (&DAT_0087a840)[iVar6];
          DAT_00879598 = DAT_00879598 + 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_0087b2c4);
    }
  }
  else {
    iVar6 = DAT_0087a954 + DAT_0087a904;
    iVar4 = 0;
    if (0 < iVar6) {
      psVar7 = (short *)&DAT_0087a848;
      do {
        iVar2 = (int)*psVar7;
        if (iVar2 == -1) break;
        if (iVar3 == -1) {
LAB_0047698b:
          iVar2 = FUN_00594960(iVar2);
          if (iVar2 != 0) {
            *(undefined4 *)(&DAT_008795a8 + DAT_00879598 * 2) = *(undefined4 *)psVar7;
            DAT_00879598 = DAT_00879598 + 1;
          }
        }
        else if ((*(byte *)(iVar5 + 0x7a + DAT_00951354) & 1) == 0) {
          if ((*(uint *)(iVar2 * 0x4c + 4 + DAT_0093b274) & 0x2000) == 0) goto LAB_0047698b;
        }
        else if ((*(uint *)(iVar2 * 0x4c + 4 + DAT_0093b274) & 0x2000) != 0) goto LAB_0047698b;
        iVar4 = iVar4 + 1;
        psVar7 = psVar7 + 2;
      } while (iVar4 < iVar6);
    }
  }
  iVar3 = DAT_00879598;
  (&DAT_008795a8)[DAT_00879598 * 2] = 0xffff;
  if (3 < iVar3) {
    iVar3 = 0x40;
    do {
      iVar5 = FUN_0054fa60();
      iVar5 = iVar5 / ((int)(0xffff / (longlong)(DAT_00879598 + -2)) + 1);
      iVar6 = FUN_0054fa60();
      iVar6 = (iVar6 / ((int)(0xffff / (longlong)(DAT_00879598 + -3)) + 1) + iVar5) %
              (DAT_00879598 + -2);
      uVar1 = *(undefined4 *)(&DAT_008795b0 + iVar5 * 4);
      *(undefined4 *)(&DAT_008795a8 + (iVar5 + 2) * 2) = *(undefined4 *)(&DAT_008795b0 + iVar6 * 4);
      *(undefined4 *)(&DAT_008795b0 + iVar6 * 4) = uVar1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

