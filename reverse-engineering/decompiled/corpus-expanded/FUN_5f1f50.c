/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f1f50; label: FUN_005f1f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f1f50(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (((param_1 < 1) || (iVar1 = *(int *)(param_1 * 4 + -4 + DAT_0097157c), iVar1 == 0)) ||
       (*(int *)(iVar1 + 0x18) != -1)) {
      iVar1 = FUN_006057c0(param_1);
      if (iVar1 != 0) {
        FUN_005f7b40(iVar1);
      }
      FUN_005f8ed0(*(undefined4 *)(param_1 * 4 + -4 + DAT_0097157c));
    }
    *(undefined4 *)(param_1 * 4 + -4 + DAT_0097157c) = 0;
  }
  return;
}

