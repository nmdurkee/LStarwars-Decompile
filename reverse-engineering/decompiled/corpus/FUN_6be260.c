/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6be260; label: FUN_006be260
 */

int FUN_006be260(code *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))(param_1);
  while ((iVar1 != 0 && (iVar2 = (*param_1)(iVar1), iVar2 == 0))) {
    iVar1 = (**(code **)(*in_ECX + 0x14))(iVar1);
  }
  return iVar1;
}

