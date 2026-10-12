/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd930; label: FUN_006bd930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bd930(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < *in_ECX) {
    do {
      iVar1 = FUN_006bd6f0(param_1,param_2 + iVar2 * 4,param_3 - iVar2);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + iVar1;
    } while (iVar3 < *in_ECX);
  }
  return iVar2;
}

