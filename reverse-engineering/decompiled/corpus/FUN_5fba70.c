/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fba70; label: FUN_005fba70
 */

void FUN_005fba70(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    FUN_005f8470(*(int *)(in_ECX + 0x30),0xffffffff,0xffffffff,0xffffffff);
  }
  if (*(int *)(in_ECX + 0x28) != 0) {
    FUN_005f8470(*(int *)(in_ECX + 0x28),0xffffffff,0xffffffff,0xffffffff);
  }
  piVar2 = (int *)(in_ECX + 0x38);
  iVar1 = 2;
  do {
    if (*piVar2 != 0) {
      FUN_005f8470(*piVar2,*(undefined2 *)(*(int *)(in_ECX + 0x30) + 4),
                   *(undefined2 *)(*(int *)(in_ECX + 0x30) + 6),0xffffffff);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

