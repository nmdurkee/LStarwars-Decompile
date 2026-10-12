/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746760; label: FUN_00746760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746760(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = in_ECX + 0x8a0 + *(int *)(in_ECX + 0x940) * 0x14;
  *(int *)(in_ECX + 0x940) = *(int *)(in_ECX + 0x940) + 1;
  iVar2 = FUN_004f1ff0(param_1);
  FUN_004ef660(iVar1,param_1,iVar2 + 1);
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  return;
}

