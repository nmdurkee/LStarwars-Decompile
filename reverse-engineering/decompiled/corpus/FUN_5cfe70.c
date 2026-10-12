/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfe70; label: FUN_005cfe70
 */

uint FUN_005cfe70(int *param_1)

{
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    return *(uint *)(*(int *)(param_1[1] + 0x40) + 0x44) >> 1 & 1;
  }
  return 1;
}

