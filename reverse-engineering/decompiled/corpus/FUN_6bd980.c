/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd980; label: FUN_006bd980
 */

undefined4 FUN_006bd980(int *param_1)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  
  if (param_1[1] != 0) {
    iVar1 = 0;
    if (0 < *in_ECX) {
      piVar2 = in_ECX + 3;
      do {
        if (*(int *)(*piVar2 + 4) == *param_1) {
          return 1;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 2;
      } while (iVar1 < *in_ECX);
    }
  }
  return 0;
}

