/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5efb90; label: FUN_005efb90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005efb90(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (7 < param_2) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1 + param_2 * 4);
  if (-1 < iVar1) {
    FUN_005e5630(iVar1);
  }
  iVar1 = FUN_005f8d60(param_3,param_4,param_5);
  *(int *)(param_1 + param_2 * 4) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + param_2 * 4) = 0xffffffff;
  }
  return *(undefined4 *)(param_1 + param_2 * 4);
}

