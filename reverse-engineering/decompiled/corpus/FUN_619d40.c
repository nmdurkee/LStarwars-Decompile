/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619d40; label: FUN_00619d40
 */

void FUN_00619d40(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x150) < 4) {
    piVar1 = (int *)(unaff_ESI + 0x14c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      iVar2 = FUN_004f1ff0((&DAT_02912118)[*(int *)(unaff_ESI + 0x150)]);
      *(int *)(unaff_ESI + 0x14c) = iVar2 + -1;
    }
  }
  return;
}

