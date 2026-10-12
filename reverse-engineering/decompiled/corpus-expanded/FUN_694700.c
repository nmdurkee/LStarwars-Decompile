/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694700; label: FUN_00694700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00694700(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_006946b0(param_1);
  if (iVar1 == 0) {
    iVar1 = *(int *)(in_ECX + 300);
    iVar2 = FUN_004f1ff0(param_1);
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + iVar2 + 1;
    FUN_004f1f10(iVar1,param_1);
  }
  return iVar1;
}

