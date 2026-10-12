/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619d70; label: FUN_00619d70
 */

void FUN_00619d70(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x150) < 4) {
    *(int *)(unaff_ESI + 0x14c) = *(int *)(unaff_ESI + 0x14c) + 1;
    iVar1 = FUN_004f1ff0((&DAT_02912118)[*(int *)(unaff_ESI + 0x150)]);
    if (iVar1 <= *(int *)(unaff_ESI + 0x14c)) {
      *(undefined4 *)(unaff_ESI + 0x14c) = 0;
    }
  }
  return;
}

