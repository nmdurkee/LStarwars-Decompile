/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cf9e0; label: FUN_005cf9e0
 */

int FUN_005cf9e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x40);
    iVar2 = *(int *)(iVar1 + 0x48);
    if (iVar2 == 0) {
      return iVar1 + 0x30;
    }
  }
  else {
    iVar2 = *(int *)(iVar1 + 0xc4);
    if ((iVar2 == -1) || (iVar2 == 0)) {
      return iVar1 + 0x70;
    }
  }
  return iVar2 + 0x30;
}

