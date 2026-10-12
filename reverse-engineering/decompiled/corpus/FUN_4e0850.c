/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e0850; label: FUN_004e0850
 */

int FUN_004e0850(void)

{
  int iVar1;
  int in_EDX;
  int iVar2;
  int unaff_EDI;
  int aiStack_40 [16];
  
  iVar2 = 0;
  iVar1 = 0;
  if (0 < DAT_0088947c) {
    do {
      if ((iVar1 != in_EDX) && ((char)(&DAT_0088946c)[iVar1] == unaff_EDI)) {
        aiStack_40[iVar2] = iVar1;
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0088947c);
    if (iVar2 != 0) {
      iVar1 = FUN_005b9e90(0);
      return aiStack_40[iVar1 % iVar2];
    }
  }
  return -1;
}

