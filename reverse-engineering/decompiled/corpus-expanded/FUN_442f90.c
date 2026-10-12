/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442f90; label: FUN_00442f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

