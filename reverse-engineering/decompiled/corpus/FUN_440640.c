/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x440640; label: FUN_00440640
 */

int FUN_00440640(void)

{
  int iVar1;
  int in_ECX;
  int in_EDX;
  
  iVar1 = 0;
  if ((in_ECX != 0) && (*(char *)(in_ECX + 0x10) != '\0')) {
    iVar1 = *(int *)(in_EDX + 0x28) + (uint)**(byte **)(in_ECX + 0x14) * 0x3c;
  }
  return iVar1;
}

