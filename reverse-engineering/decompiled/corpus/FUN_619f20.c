/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619f20; label: FUN_00619f20
 */

void FUN_00619f20(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  iVar1 = *(int *)(in_EAX + 0x154);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x4c + in_EAX) == '\0') {
      *(int *)(in_EAX + 0x154) = iVar1 + -1;
      *(undefined1 *)(iVar1 + 0x4b + in_EAX) = 0;
    }
    else {
      iVar2 = iVar1 + -1;
      *(int *)(in_EAX + 0x154) = iVar2;
      if (iVar2 < 0xff) {
        puVar3 = (undefined1 *)(iVar1 + 0x4c + in_EAX);
        puVar4 = (undefined1 *)(iVar1 + 0x4b + in_EAX);
        for (iVar2 = 0xff - iVar2; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        return;
      }
    }
  }
  return;
}

