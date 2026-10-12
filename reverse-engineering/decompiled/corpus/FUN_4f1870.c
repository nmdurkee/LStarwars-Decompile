/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1870; label: FUN_004f1870
 */

int FUN_004f1870(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if (iVar1 < *(int *)(in_ECX + 0x1c)) {
    iVar2 = iVar1 * 0xc;
    puVar3 = (undefined4 *)(*(int *)(in_ECX + 0x14) + iVar2);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    *(undefined2 *)(iVar2 + 2 + *(int *)(in_ECX + 0x14)) = param_1;
    *(undefined2 *)(iVar2 + *(int *)(in_ECX + 0x14)) = 0xffff;
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    return iVar1;
  }
  return 0;
}

