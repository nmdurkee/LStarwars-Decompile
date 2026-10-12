/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfd60; label: FUN_005cfd60
 */

uint FUN_005cfd60(int *param_1)

{
  if (*param_1 != 0) {
    if (param_1[1] != 0) {
      return *(uint *)(*(int *)(param_1[1] + 0x40) + 0x44) & 1;
    }
    if (param_1[2] != 0) {
      return *(uint *)(param_1[2] + 0xb8) >> 1 & 1;
    }
  }
  return 0;
}

