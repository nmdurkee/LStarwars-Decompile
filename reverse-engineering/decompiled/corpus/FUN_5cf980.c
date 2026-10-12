/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cf980; label: FUN_005cf980
 */

undefined4 FUN_005cf980(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    if ((*(int *)(param_1 + 4) != 0) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 4) + 0x40) + 0x48) != 0)) {
      return 1;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc4);
    if ((iVar1 != -1) && (iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

