/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x6336f0; label: FUN_006336f0
 */

uint FUN_006336f0(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 1;
  if (0 < *(int *)(in_ECX + 0xc)) {
    do {
      if ((*(int *)(*(int *)(in_ECX + 4) + iVar3 * 4) != 0) &&
         ((~*(uint *)(*(int *)(*(int *)(in_ECX + 4) + iVar3 * 4) + 8) & 1) != 0)) {
        uVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + iVar3 * 4) + 8))(param_1);
        uVar2 = uVar2 & uVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(in_ECX + 0xc));
  }
  return uVar2;
}

