/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cffb0; label: FUN_005cffb0
 */

int FUN_005cffb0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[1] == 0) {
    if (param_1[2] != 0) {
      return *(int *)(param_1[2] + 0xc0);
    }
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x1c);
    iVar2 = 0;
    if (0 < iVar1) {
      iVar3 = *(int *)(*param_1 + 0x20);
      do {
        if (iVar3 == *(int *)(param_1[1] + 0x40)) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x50;
      } while (iVar2 < iVar1);
    }
  }
  return -1;
}

