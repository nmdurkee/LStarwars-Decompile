/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5efb60; label: FUN_005efb60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005efb60(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + param_2 * 4), -1 < iVar1)) {
    FUN_005e5630(iVar1);
    *(undefined4 *)(param_1 + param_2 * 4) = 0xffffffff;
  }
  return;
}

