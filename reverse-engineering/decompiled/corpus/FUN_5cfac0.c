/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfac0; label: FUN_005cfac0
 */

undefined4 FUN_005cfac0(int param_1)

{
  if ((param_1 != 0) && ((*(int *)(param_1 + 4) != 0 || (*(int *)(param_1 + 8) != 0)))) {
    return 1;
  }
  return 0;
}

