/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfde0; label: FUN_005cfde0
 */

uint FUN_005cfde0(int *param_1)

{
  if (*param_1 != 0) {
    if (param_1[1] != 0) {
      return *(uint *)(*(int *)(param_1[1] + 0x40) + 0x44) >> 3 & 1;
    }
    if (param_1[2] != 0) {
      return *(uint *)(param_1[2] + 0xb8) & 0x80;
    }
  }
  return 0;
}

