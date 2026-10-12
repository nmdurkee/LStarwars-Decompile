/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619d10; label: FUN_00619d10
 */

void FUN_00619d10(void)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  bool bVar3;
  bool bVar4;
  
  *(int *)(in_EAX + 0x150) = *(int *)(in_EAX + 0x150) + 1;
  iVar1 = *(int *)(in_EAX + 0x150);
  if ((*(byte *)(in_EAX + 0x164) & 2) == 0) {
    bVar4 = SBORROW4(iVar1,3);
    iVar2 = -3;
    bVar3 = iVar1 == 3;
  }
  else {
    bVar4 = SBORROW4(iVar1,5);
    iVar2 = -5;
    bVar3 = iVar1 == 5;
  }
  if (!bVar3 && bVar4 == iVar1 + iVar2 < 0) {
    *(undefined4 *)(in_EAX + 0x150) = 0;
  }
  return;
}

