/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x408a40; label: FUN_00408a40
 */

void FUN_00408a40(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  float10 fVar3;
  
  *(undefined1 *)(unaff_EDI + 0x7b5) = 0x3d;
  *(undefined2 *)(unaff_EDI + 0x7aa) = 0x85;
  fVar3 = (float10)FUN_0062e040((int)*(short *)(unaff_EDI + 0x1064),0x85,0,0,1);
  *(uint *)(unaff_EDI + 0xef4) = *(uint *)(unaff_EDI + 0xef4) | 0x800000;
  *(float *)(unaff_EDI + 0x784) = (float)fVar3;
  *(undefined4 *)(unaff_EDI + 0x77c) = 0;
  FUN_004e8650();
  iVar2 = 0;
  if (0 < DAT_0093d500) {
    piVar1 = (int *)(DAT_0093d504 + 0x1040);
    do {
      if (((((piVar1[-0x391] & 0x1000U) != 0) && (*(char *)((int)piVar1 + -0xdb5) == '\0')) &&
          (*piVar1 != 0)) && (*(int *)(*piVar1 + 4) == unaff_EDI)) {
        FUN_00408960(1);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x436;
    } while (iVar2 < DAT_0093d500);
  }
  return;
}

