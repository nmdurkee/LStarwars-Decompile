/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ece10; label: FUN_004ece10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004ece10(void)

{
  int iVar1;
  int in_EDX;
  int iVar2;
  int unaff_EDI;
  int aiStack_40 [16];
  
  iVar2 = 0;
  iVar1 = 0;
  if (0 < DAT_0088aaac) {
    do {
      if ((iVar1 != in_EDX) && ((char)(&DAT_0088aa9c)[iVar1] == unaff_EDI)) {
        aiStack_40[iVar2] = iVar1;
        iVar2 = iVar2 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0088aaac);
    if (iVar2 != 0) {
      iVar1 = FUN_005b9e90(0);
      return aiStack_40[iVar1 % iVar2];
    }
  }
  return -1;
}

