/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fb960; label: FUN_005fb960
 */

void FUN_005fb960(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    piVar1 = *(int **)((int)&DAT_00986a88 + iVar2);
    if ((piVar1 != (int *)0x0) && (piVar1[2] != 0)) {
      if (*(int *)(*piVar1 + 0x28) == 0) {
        (**(code **)(*(int *)piVar1[2] + 8))((int *)piVar1[2]);
      }
      *(undefined4 *)(*(int *)((int)&DAT_00986a88 + iVar2) + 8) = 0;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 != 0x400);
  return;
}

