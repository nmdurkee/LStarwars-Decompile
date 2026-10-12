/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd760; label: FUN_006bd760
 */

int FUN_006bd760(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))(0);
  iVar2 = 0;
  for (; iVar1 != 0; iVar1 = (**(code **)(*in_ECX + 0x14))(iVar1)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

