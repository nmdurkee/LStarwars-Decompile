/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54a1c0; label: FUN_0054a1c0
 */

undefined4 FUN_0054a1c0(void)

{
  int *piVar1;
  char cVar2;
  int *in_EAX;
  int *piVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  if (((in_EAX == (int *)0x0) || (cVar2 = *(char *)(unaff_ESI + 1), cVar2 == -1)) ||
     ((*(ushort *)(cVar2 * 0x13c + 0x68 + *in_EAX) & 0x800) == 0)) {
    return 0;
  }
  if ((DAT_009253a0 != (int *)0x0) && (*DAT_009253a0 != 0)) {
    piVar3 = DAT_009253a0 + 1;
    do {
      if ((((short)*piVar3 != -1) && ((short)*piVar3 == unaff_EDI)) &&
         (((short)cVar2 == *(short *)((int)piVar3 + 2) &&
          (((float)piVar3[1] < *(float *)(unaff_ESI + 0x2c) !=
            ((float)piVar3[1] == *(float *)(unaff_ESI + 0x2c)) &&
           (*(float *)(unaff_ESI + 0x2c) <= (float)piVar3[2])))))) {
        return 0;
      }
      piVar1 = piVar3 + 3;
      piVar3 = piVar3 + 4;
    } while (*piVar1 != 0);
  }
  return 1;
}

