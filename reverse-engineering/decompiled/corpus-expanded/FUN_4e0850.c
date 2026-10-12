/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e0850; label: FUN_004e0850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

