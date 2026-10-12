/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd8f0; label: FUN_006bd8f0
 */

int FUN_006bd8f0(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *in_ECX) {
    do {
      iVar1 = FUN_006bd6a0(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *in_ECX);
  }
  return 0;
}

