/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfef0; label: FUN_005cfef0
 */

undefined4 FUN_005cfef0(int param_1,int *param_2,int param_3)

{
  if (*(int *)(param_1 + 0x28) != 0) {
    *param_2 = param_1;
    param_2[1] = *(int *)(param_1 + 0x28);
    param_2[2] = 0;
    return 1;
  }
  if (*(int *)(*(int *)(param_1 + 0x110) + 0x6c) != 0) {
    *param_2 = param_1;
    param_2[1] = 0;
    param_2[2] = *(int *)(*(int *)(param_1 + 0x110) + 0x70);
    return 1;
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  if (param_3 != 0) {
    FUN_005c1300();
  }
  return 0;
}

