/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd7a0; label: FUN_006bd7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bd7a0(int param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  *in_ECX = iVar1 + 1;
  in_ECX[iVar1 * 2 + 2] = param_1;
  in_ECX[iVar1 * 2 + 3] = param_2;
  *(int *)(param_2 + 8) = *in_ECX;
  return;
}

