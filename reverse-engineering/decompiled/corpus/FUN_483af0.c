/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483af0; label: FUN_00483af0
 */

int FUN_00483af0(int *param_1)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_4;
  
  psVar2 = (short *)&local_4;
  iVar5 = 0;
  if (DAT_007f39e4 == 0) {
    if (((*(byte *)(*param_1 + 3) & 1) != 0) && (DAT_0086e4c4 != DAT_0087aa8c)) {
      return 1;
    }
  }
  else {
    local_4 = CONCAT22(0xffff,DAT_007f17d4);
    if ((param_1[5] == 0) || (param_1[5] != DAT_0087b02c)) {
      psVar2 = &DAT_0095107c;
    }
    sVar1 = *psVar2;
    while ((sVar1 != -1 && (iVar5 < 7))) {
      sVar1 = *psVar2;
      iVar4 = (int)sVar1;
      iVar3 = 0;
      if (0 < iVar5) {
        do {
          if ((short)(&DAT_0087a190)[iVar3] == iVar4) break;
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar5);
      }
      if (((iVar3 == iVar5) &&
          (((DAT_0093b288 == 0 || ((*(byte *)(DAT_0093b288 + iVar4) & 1) == 0)) &&
           (iVar3 = FUN_00594250(iVar4,DAT_00855f0c,DAT_00855f12), iVar3 != -1)))) &&
         (iVar4 = DAT_00855f0c + iVar3 * 0x1c, *(char *)(DAT_00855f0c + 8 + iVar3 * 0x1c) == '\0'))
      {
        (&DAT_0087a190)[iVar5] = sVar1;
        iVar5 = iVar5 + 1;
        if (*(char *)(iVar4 + 9) != '\0') {
          FUN_0055c820(DAT_0093b2d8);
        }
      }
      psVar2 = psVar2 + 1;
      sVar1 = *psVar2;
    }
    (&DAT_0087a190)[iVar5] = 0xffff;
  }
  return iVar5;
}

