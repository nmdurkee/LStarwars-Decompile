/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd840; label: FUN_006bd840
 */

void FUN_006bd840(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    in_ECX[1] = 0;
  }
  if (in_ECX[1] < *in_ECX) {
    while (in_ECX[1] < *in_ECX) {
      iVar1 = (**(code **)(*(int *)in_ECX[in_ECX[1] * 2 + 3] + 0x14))(param_1);
      if (iVar1 != 0) {
        return;
      }
      in_ECX[1] = in_ECX[1] + 1;
      param_1 = 0;
    }
  }
  return;
}

