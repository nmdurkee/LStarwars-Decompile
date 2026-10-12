/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746760; label: FUN_00746760
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

