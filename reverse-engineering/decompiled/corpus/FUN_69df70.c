/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69df70; label: FUN_0069df70
 */

int FUN_0069df70(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x58);
  while( true ) {
    if (iVar1 == 4) {
      return 0;
    }
    iVar1 = FUN_0069c090(0,1,0);
    if ((iVar1 < 0) && (iVar1 != -3)) break;
    iVar1 = *(int *)(unaff_ESI + 0x58);
  }
  return iVar1;
}

