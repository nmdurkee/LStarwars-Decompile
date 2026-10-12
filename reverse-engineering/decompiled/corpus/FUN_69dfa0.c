/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69dfa0; label: FUN_0069dfa0
 */

int FUN_0069dfa0(void)

{
  int iVar1;
  int unaff_ESI;
  
  do {
    if (*(int *)(unaff_ESI + 0x58) == 4) {
      iVar1 = FUN_006a2db0(unaff_ESI + 0x1e0,0);
      if (iVar1 != 0) {
        return 0;
      }
    }
    iVar1 = FUN_0069c090(0,1,0);
  } while ((-1 < iVar1) || (iVar1 == -3));
  return iVar1;
}

