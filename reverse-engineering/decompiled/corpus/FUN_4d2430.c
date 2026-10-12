/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d2430; label: FUN_004d2430
 */

int FUN_004d2430(void)

{
  char in_AL;
  int iVar1;
  float *unaff_ESI;
  int unaff_EDI;
  float10 fVar2;
  
  if (unaff_EDI != 0) {
    if (in_AL == '\0') {
      if (unaff_ESI != (float *)0x0) {
        *unaff_ESI = *(float *)(unaff_EDI + 0xa8);
      }
      return unaff_EDI + 0x4c;
    }
    if (in_AL == '\x01') {
      if (unaff_ESI != (float *)0x0) {
        fVar2 = (float10)FUN_005d02e0(*(int *)(unaff_EDI + 0x1c) + 4);
        *unaff_ESI = (float)fVar2;
      }
      iVar1 = FUN_005cf9e0(*(int *)(unaff_EDI + 0x1c) + 4);
      return iVar1;
    }
    if (in_AL == '\x02') {
      if (unaff_ESI != (float *)0x0) {
        *unaff_ESI = *(float *)(unaff_EDI + 0x58);
      }
      return unaff_EDI + 0x28;
    }
  }
  return 0;
}

