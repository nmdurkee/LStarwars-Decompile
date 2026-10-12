/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfd90; label: FUN_005cfd90
 */

void FUN_005cfd90(int *param_1,int param_2)

{
  uint *puVar1;
  
  if (*param_1 != 0) {
    if (param_1[1] != 0) {
      puVar1 = (uint *)(*(int *)(param_1[1] + 0x40) + 0x44);
      *puVar1 = *puVar1 ^ (param_2 * 8 ^ *(uint *)(*(int *)(param_1[1] + 0x40) + 0x44)) & 8;
      return;
    }
    if (param_1[2] != 0) {
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[2] + 0xb8);
        *puVar1 = *puVar1 | 0x80;
        return;
      }
      puVar1 = (uint *)(param_1[2] + 0xb8);
      *puVar1 = *puVar1 & 0xffffff7f;
    }
  }
  return;
}

