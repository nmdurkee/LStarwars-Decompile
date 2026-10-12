/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bc9e0; label: FUN_006bc9e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bc9e0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_004f1ff0(param_1);
  iVar1 = *(int *)(in_ECX + 0xe64) + 0xa64 + in_ECX;
  FUN_004f1f10(iVar1,param_1);
  *(int *)(in_ECX + 0xe64) = *(int *)(in_ECX + 0xe64) + iVar2 + 1;
  return iVar1;
}

