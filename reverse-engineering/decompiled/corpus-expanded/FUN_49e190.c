/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49e190; label: FUN_0049e190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0049e190(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if (((((*(byte *)(*(int *)(unaff_ESI + 0x54) + 4) & 8) == 0) &&
       (*(short *)(unaff_ESI + 0x1064) != DAT_007f187c)) &&
      (*(short *)(unaff_ESI + 0x1064) != DAT_007f1878)) ||
     (((iVar1 = *(int *)(*(int *)(unaff_ESI + 0x50) + 0xc), *(int *)(iVar1 + 0x68) == 0 &&
       (*(int *)(iVar1 + 0x6c) == 0)) && (*(int *)(iVar1 + 0x70) == 0)))) {
    return 0;
  }
  iVar2 = 0;
  iVar1 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((iVar1 != unaff_ESI) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar1 + 0x28b) == '\0' &&
          ((*(char *)(iVar1 + 0x7b5) == '&' && (*(int *)(iVar1 + 0x790) == unaff_ESI)))))) {
        if (*(short *)(iVar1 + 0x1064) != DAT_007f1884) {
          return iVar1;
        }
        if (*(short *)(iVar1 + 0x7aa) != 0x56) {
          return iVar1;
        }
        if ((*(byte *)(iVar1 + 0x7bc) & 0x40) == 0) {
          return iVar1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return 0;
}

