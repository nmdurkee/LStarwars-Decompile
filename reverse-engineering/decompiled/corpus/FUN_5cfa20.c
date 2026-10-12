/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfa20; label: FUN_005cfa20
 */

int FUN_005cfa20(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 4);
  }
  return iVar1;
}

