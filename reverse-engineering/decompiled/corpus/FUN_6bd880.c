/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd880; label: FUN_006bd880
 */

int FUN_006bd880(undefined4 param_1,code *param_2)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  iVar1 = FUN_006bd840(param_1);
  while ((iVar2 = iVar1, iVar2 != 0 && (iVar1 = (*param_2)(iVar2), iVar1 == 0))) {
    if (iVar2 == 0) {
      in_ECX[1] = 0;
    }
    iVar1 = 0;
    if (in_ECX[1] < *in_ECX) {
      while ((in_ECX[1] < *in_ECX &&
             (iVar1 = (**(code **)(*(int *)in_ECX[in_ECX[1] * 2 + 3] + 0x14))(iVar2), iVar1 == 0)))
      {
        in_ECX[1] = in_ECX[1] + 1;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

