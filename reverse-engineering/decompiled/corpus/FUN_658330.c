/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x658330; label: FUN_00658330
 */

int FUN_00658330(int param_1,byte param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return -1;
  }
  iVar3 = DAT_0296209c;
  iVar5 = DAT_02962098;
  if (((param_2 < 8) && ((&DAT_02924b10)[(char)param_2] != 0)) && (iVar4 = 1, 1 < DAT_02962098)) {
    do {
      if (((iVar4 != param_3) && (*(int *)(iVar3 + iVar4 * 4) != 0)) &&
         ((iVar2 = *(int *)(iVar3 + iVar4 * 4), *(byte *)(iVar2 + 0x11) == param_2 &&
          (iVar2 = FUN_004f8b10(iVar2,param_1), iVar3 = DAT_0296209c, iVar5 = DAT_02962098,
          iVar2 == 0)))) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  iVar4 = 1;
  if (1 < iVar5) {
    do {
      if ((iVar4 != param_3) && (*(int *)(iVar3 + iVar4 * 4) != 0)) {
        iVar2 = *(int *)(iVar3 + iVar4 * 4);
        cVar1 = *(char *)(iVar2 + 0x11);
        if ((((cVar1 == '\0') && (DAT_02924b10 != 0)) || ((cVar1 == '\x01' && (DAT_02924b14 != 0))))
           && (iVar2 = FUN_004f8b10(iVar2,param_1), iVar3 = DAT_0296209c, iVar5 = DAT_02962098,
              iVar2 == 0)) {
          return iVar4;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  iVar4 = 1;
  if (1 < iVar5) {
    do {
      if ((((iVar4 != param_3) && (*(int *)(iVar3 + iVar4 * 4) != 0)) &&
          (iVar2 = *(int *)(iVar3 + iVar4 * 4), (&DAT_02924b10)[*(char *)(iVar2 + 0x11)] != 0)) &&
         (iVar2 = FUN_004f8b10(iVar2,param_1), iVar3 = DAT_0296209c, iVar5 = DAT_02962098,
         iVar2 == 0)) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  return -1;
}

