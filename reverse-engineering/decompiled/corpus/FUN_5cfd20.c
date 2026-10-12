/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfd20; label: FUN_005cfd20
 */

uint FUN_005cfd20(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      return *(uint *)(param_1[1] + 0x48) & 0x200;
    }
    if (param_1[2] != 0) {
      return *(uint *)(param_1[2] + 0xb8) & 0x200;
    }
  }
  return 0;
}

