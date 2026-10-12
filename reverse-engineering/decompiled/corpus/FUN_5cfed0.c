/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfed0; label: FUN_005cfed0
 */

int FUN_005cfed0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if ((iVar1 == 0) &&
     ((*(int *)(param_1 + 0x110) == 0 ||
      (iVar1 = *(int *)(*(int *)(param_1 + 0x110) + 0x6c), iVar1 == 0)))) {
    iVar1 = 0;
  }
  return iVar1;
}

