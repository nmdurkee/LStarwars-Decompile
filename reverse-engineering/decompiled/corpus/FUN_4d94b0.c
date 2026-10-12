/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d94b0; label: FUN_004d94b0
 */

int FUN_004d94b0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(DAT_00882a6c + 0xa694);
  do {
    if (*piVar2 == 0) {
      return iVar1 * 0xa0 + 0xa600 + DAT_00882a6c;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x28;
  } while (iVar1 < 0x10);
  return 0;
}

