/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfcc0; label: FUN_005cfcc0
 */

void FUN_005cfcc0(int *param_1,int param_2)

{
  uint *puVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[1] + 0x48);
        *puVar1 = *puVar1 | 0x200;
        return;
      }
      puVar1 = (uint *)(param_1[1] + 0x48);
      *puVar1 = *puVar1 & 0xfffffdff;
      return;
    }
    if (param_1[2] != 0) {
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[2] + 0xb8);
        *puVar1 = *puVar1 | 0x200;
        return;
      }
      puVar1 = (uint *)(param_1[2] + 0xb8);
      *puVar1 = *puVar1 & 0xfffffdff;
    }
  }
  return;
}

