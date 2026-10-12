/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bc740; label: FUN_006bc740
 */

undefined4 FUN_006bc740(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0x2a8)) {
    iVar2 = in_ECX + 0x2ac;
    do {
      iVar1 = FUN_004f8b10(param_1,iVar2);
      if (iVar1 == 0) {
        return *(undefined4 *)(iVar3 * 0xa8 + 0x34c + in_ECX);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xa8;
    } while (iVar3 < *(int *)(in_ECX + 0x2a8));
  }
  return 0;
}

