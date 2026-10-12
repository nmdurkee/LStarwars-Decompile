/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x633440; label: FUN_00633440
 */

undefined4 * FUN_00633440(size_t param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint _Size;
  
  iVar3 = (int)((param_1 - 1) + ((int)(param_1 - 1) >> 0x1f & 0x1fU)) >> 5;
  puVar4 = *(undefined4 **)(in_ECX + 0x1c + iVar3 * 4);
  if (puVar4 == (undefined4 *)0x0) {
    puVar1 = *(uint **)(in_ECX + 8);
    _Size = (iVar3 + 1) * 0x20;
    puVar4 = (undefined4 *)0x0;
    if (_Size < **(int **)(in_ECX + 0xc) - *puVar1) {
      *puVar1 = *puVar1 + 0xf & 0xfffffff0;
      piVar2 = *(int **)(in_ECX + 8);
      puVar4 = (undefined4 *)*piVar2;
      *piVar2 = *piVar2 + _Size;
      _memset(puVar4,0,_Size);
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + _Size;
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + (iVar3 + 1) * -0x20;
      *(undefined4 *)(in_ECX + 0x10) = **(undefined4 **)(in_ECX + 8);
    }
    return puVar4;
  }
  *(undefined4 *)(in_ECX + 0x1c + iVar3 * 4) = *puVar4;
  if (param_2 != 0) {
    _memset(puVar4,0,param_1);
  }
  return puVar4;
}

