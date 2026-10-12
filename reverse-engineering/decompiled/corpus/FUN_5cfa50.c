/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfa50; label: FUN_005cfa50
 */

undefined4 FUN_005cfa50(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      return *(undefined4 *)(*(int *)(param_1 + 8) + 0xb4);
    }
    if (*(int *)(param_1 + 4) != 0) {
      return *(undefined4 *)(*(int *)(param_1 + 4) + 0x44);
    }
  }
  return 0;
}

