/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50d3c0; label: FUN_0050d3c0
 */

int FUN_0050d3c0(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = param_1;
  iVar6 = FUN_004f5240();
  bVar10 = iVar6 == 0;
  bVar3 = *(byte *)(param_1 + param_2);
  while ((0x7f < bVar3 && (bVar3 < 0xc0))) {
    pbVar2 = (byte *)(param_1 + -1 + param_2);
    param_2 = param_2 + -1;
    bVar3 = *pbVar2;
  }
  bVar3 = *(byte *)(param_1 + param_2);
  if (((((bVar3 == 0x20) && (cVar4 = *(char *)(param_1 + 1 + param_2), cVar4 != '!')) &&
       (cVar4 != '?')) && ((cVar4 != ';' && (cVar4 != ':')))) ||
     (((bVar3 == 0x2e && (*(char *)(param_1 + 1 + param_2) != '.')) ||
      ((bVar3 == 0x2d || (bVar3 == 0x2c)))))) {
    return param_2;
  }
  bVar9 = bVar3 < 0x80;
  param_1 = 0;
  iVar7 = FUN_004f1ff0(iVar5);
  iVar6 = param_2;
  iVar8 = param_2;
  while( true ) {
    param_1 = param_1 + 1;
    if ((((bVar10) && (10 < param_1)) && (!bVar9)) || (0x14 < param_1)) {
      if (*(char *)(iVar5 + param_2) == '~') {
        if ((0 < param_2) && (*(char *)(iVar5 + -1 + param_2) == '~')) {
          return param_2 + -1;
        }
      }
      else if (((0 < param_2) && (*(char *)(iVar5 + -1 + param_2) == '~')) &&
              ((1 < param_2 && (*(char *)(iVar5 + -2 + param_2) != '~')))) {
        param_2 = param_2 + -1;
      }
      return param_2;
    }
    if (iVar6 < iVar7 + -1) {
      iVar6 = iVar6 + 1;
    }
    bVar3 = *(byte *)(iVar5 + iVar6);
    while ((0x7f < bVar3 && (bVar3 < 0xc0))) {
      pbVar2 = (byte *)(iVar5 + 1 + iVar6);
      iVar6 = iVar6 + 1;
      bVar3 = *pbVar2;
    }
    if (0 < iVar8) {
      iVar8 = iVar8 + -1;
    }
    bVar3 = *(byte *)(iVar8 + iVar5);
    while ((0x7f < bVar3 && (bVar3 < 0xc0))) {
      iVar1 = iVar8 + -1;
      iVar8 = iVar8 + -1;
      bVar3 = *(byte *)(iVar1 + iVar5);
    }
    bVar3 = *(byte *)(iVar5 + iVar6);
    if (((((bVar3 == 0x20) && (cVar4 = *(char *)(iVar5 + 1 + iVar6), cVar4 != '!')) &&
         (cVar4 != '?')) && ((cVar4 != ';' && (cVar4 != ':')))) ||
       (((bVar3 == 0x2e && (*(char *)(iVar5 + 1 + iVar6) != '.')) ||
        ((bVar3 == 0x2d || (bVar3 == 0x2c)))))) {
      return iVar6;
    }
    if ((bVar10) && (((bVar3 < 0x80 && (!bVar9)) || ((0x7f < bVar3 && (bVar9)))))) break;
    bVar3 = *(byte *)(iVar8 + iVar5);
    if ((((bVar3 == 0x20) && (cVar4 = *(char *)(iVar8 + 1 + iVar5), cVar4 != '!')) && (cVar4 != '?')
        ) && ((cVar4 != ';' && (cVar4 != ':')))) {
      return iVar8;
    }
    if ((bVar3 == 0x2e) && (*(char *)(iVar8 + 1 + iVar5) != '.')) {
      return iVar8;
    }
    if (bVar3 == 0x2d) {
      return iVar8;
    }
    if (bVar3 == 0x2c) {
      return iVar8;
    }
    if ((bVar10) && (((bVar3 < 0x80 && (!bVar9)) || ((0x7f < bVar3 && (bVar9)))))) {
      iVar6 = iVar8 + 1;
      if (*(char *)(iVar6 + iVar5) == '~') {
        if ((0 < iVar6) && (*(char *)(iVar8 + iVar5) == '~')) {
          return iVar8;
        }
      }
      else if ((((0 < iVar6) && (*(char *)(iVar8 + iVar5) == '~')) && (1 < iVar6)) &&
              (*(char *)(iVar8 + -1 + iVar5) != '~')) {
        iVar6 = iVar8;
      }
      return iVar6;
    }
  }
  if (*(char *)(iVar5 + iVar6) == '~') {
    if (iVar6 < 1) {
      return iVar6;
    }
    if (*(char *)(iVar5 + -1 + iVar6) != '~') {
      return iVar6;
    }
    return iVar6 + -1;
  }
  if (iVar6 < 1) {
    return iVar6;
  }
  if (*(char *)(iVar5 + -1 + iVar6) != '~') {
    return iVar6;
  }
  if (iVar6 < 2) {
    return iVar6;
  }
  if (*(char *)(iVar5 + -2 + iVar6) == '~') {
    return iVar6;
  }
  return iVar6 + -1;
}

