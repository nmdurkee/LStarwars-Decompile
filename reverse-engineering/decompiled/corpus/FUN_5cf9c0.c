/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cf9c0; label: FUN_005cf9c0
 */

int FUN_005cf9c0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return iVar1 + 0x30;
}

