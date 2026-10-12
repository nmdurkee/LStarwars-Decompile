/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x658490; label: FUN_00658490
 */

int FUN_00658490(int param_1,byte param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return -1;
  }
  iVar3 = DAT_0296209c;
  if (((param_2 < 8) && ((&DAT_02924b10)[(char)param_2] != 0)) && (iVar4 = 1, 1 < DAT_02962098)) {
    do {
      if (((*(int *)(iVar3 + iVar4 * 4) != 0) &&
          (iVar2 = *(int *)(iVar3 + iVar4 * 4), *(byte *)(iVar2 + 0x11) == param_2)) &&
         (iVar2 = FUN_004f8b10(iVar2,param_1), iVar3 = DAT_0296209c, iVar2 == 0)) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_02962098);
  }
  iVar4 = 1;
  if (1 < DAT_02962098) {
    do {
      if (*(int *)(iVar3 + iVar4 * 4) != 0) {
        iVar2 = *(int *)(iVar3 + iVar4 * 4);
        cVar1 = *(char *)(iVar2 + 0x11);
        if ((((cVar1 == '\0') && (DAT_02924b10 != 0)) || ((cVar1 == '\x01' && (DAT_02924b14 != 0))))
           && (iVar2 = FUN_004f8b10(iVar2,param_1), iVar3 = DAT_0296209c, iVar2 == 0)) {
          return iVar4;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_02962098);
  }
  return -1;
}

