/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f650; label: FUN_0055f650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055f650(int param_1)

{
  if (*(int *)(param_1 + 0x13c) != 0) {
    if ((DAT_00951c34 == 0) && (*(int *)(*(int *)(param_1 + 0x13c) + 0x110) == 0)) {
      FUN_005d9030();
      FUN_005eeb30(*(undefined4 *)(param_1 + 0x13c));
      FUN_0055f560(param_1,0);
    }
    FUN_00601df0(*(undefined4 *)(param_1 + 0x13c));
    if (*(int *)(*(int *)(param_1 + 0x13c) + 0x110) != 0) {
      FUN_0055f560(param_1,0);
    }
  }
  return;
}

