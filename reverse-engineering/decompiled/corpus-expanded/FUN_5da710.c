/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da710; label: FUN_005da710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005da710(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_004fb750(param_1);
  *(undefined4 *)(param_2 + 0x58) = uVar1;
  FUN_004fb750(param_1);
  uVar1 = FUN_004f0360(param_1);
  *(undefined4 *)(param_2 + 0x5c) = uVar1;
  return;
}

