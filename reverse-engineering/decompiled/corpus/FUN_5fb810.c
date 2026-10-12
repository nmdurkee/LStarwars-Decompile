/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fb810; label: FUN_005fb810
 */

void FUN_005fb810(void)

{
  int *piVar1;
  int *in_ECX;
  
  if ((*in_ECX != 0) && (*(int *)(*in_ECX + 0x28) != 0)) {
    in_ECX[2] = 0;
  }
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[2] = 0;
  }
  if ((*in_ECX != 0) && ((char)in_ECX[1] != '\0')) {
    FUN_005f7b40(*in_ECX);
  }
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  *(undefined2 *)(in_ECX + 5) = 0;
  *(undefined2 *)((int)in_ECX + 0x16) = 0;
  return;
}

