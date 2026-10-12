/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f2040; label: FUN_005f2040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f2040(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  if (-1 < *in_ECX) {
    piVar1 = (int *)(in_ECX[1] + 0x24 + *in_ECX * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  in_ECX[1] = param_3;
  iVar2 = FUN_005c51c0(param_1,param_2);
  *in_ECX = iVar2;
  return;
}

