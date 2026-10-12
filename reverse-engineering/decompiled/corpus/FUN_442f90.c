/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x442f90; label: FUN_00442f90
 */

float10 FUN_00442f90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (((param_1 != 0) && (iVar1 = *(int *)(param_2 + 0xa0), iVar1 != 0)) &&
     (((iVar2 = *(int *)(param_1 + 0x138c), iVar2 != 0 &&
       ((*(int *)(iVar1 + 0x38) != 0 &&
        (uVar3 = 1 << ((byte)(iVar1 - *(int *)(*(int *)(iVar1 + 0x38) + 0x38) >> 6) & 0x1f),
        (uVar3 & *(uint *)(iVar2 + 0x2b0)) != 0 ||
        ((int)uVar3 >> 0x1f & *(uint *)(iVar2 + 0x2b4)) != 0)))) ||
      ((iVar2 = *(int *)(param_1 + 0x1390), iVar2 != 0 &&
       ((*(int *)(iVar1 + 0x38) != 0 &&
        (uVar3 = 1 << ((byte)(iVar1 - *(int *)(*(int *)(iVar1 + 0x38) + 0x38) >> 6) & 0x1f),
        (uVar3 & *(uint *)(iVar2 + 0x2b0)) != 0 ||
        ((int)uVar3 >> 0x1f & *(uint *)(iVar2 + 0x2b4)) != 0)))))))) {
    return (float10)1;
  }
  return (float10)0;
}

