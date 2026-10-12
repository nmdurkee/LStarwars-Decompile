/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619ee0; label: FUN_00619ee0
 */

void FUN_00619ee0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x154) + 1;
  iVar2 = FUN_004f1ff0(unaff_ESI + 0x4c);
  if (iVar2 < iVar1) {
    uVar3 = FUN_004f1ff0(unaff_ESI + 0x4c);
    *(undefined4 *)(unaff_ESI + 0x154) = uVar3;
    return;
  }
  *(int *)(unaff_ESI + 0x154) = iVar1;
  return;
}

