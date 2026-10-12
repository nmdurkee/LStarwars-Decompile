/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x5528b0; label: FUN_005528b0
 */

void FUN_005528b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x110) == 0)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    if (iVar2 != 0) {
      iVar3 = iVar2 * 0x50 + *(int *)(param_1 + 0x20) + 0x48;
      do {
        iVar1 = *(int *)(iVar3 + -0x50);
        iVar3 = iVar3 + -0x50;
        iVar2 = iVar2 + -1;
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)(iVar1 + 0x40);
        }
      } while (iVar2 != 0);
    }
  }
  return;
}

