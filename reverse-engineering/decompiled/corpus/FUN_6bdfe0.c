/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bdfe0; label: FUN_006bdfe0
 */

int FUN_006bdfe0(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = param_1;
    if (iVar1 == 0) {
      return 0;
    }
    param_1 = *(int *)(iVar1 + 0x3c);
  } while (*(int *)(iVar1 + 0x3c) != 0);
  return iVar1;
}

