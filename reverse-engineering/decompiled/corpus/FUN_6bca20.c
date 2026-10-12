/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bca20; label: FUN_006bca20
 */

void FUN_006bca20(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  piVar2 = (int *)(in_ECX + 0xe68);
  do {
    if (*piVar2 == 0) {
      iVar3 = FUN_004f1ff0(param_1);
      iVar1 = *(int *)(in_ECX + 0xe64) + 0xa64 + in_ECX;
      FUN_004f1f10(iVar1,param_1);
      *(int *)(in_ECX + 0xe64) = *(int *)(in_ECX + 0xe64) + iVar3 + 1;
      *(int *)(in_ECX + 0xe68 + iVar4 * 4) = iVar1;
      return;
    }
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar4 < 0x20);
  return;
}

