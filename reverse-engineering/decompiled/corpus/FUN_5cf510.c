/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cf510; label: FUN_005cf510
 */

undefined4 FUN_005cf510(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x110) + 0x70);
  iVar3 = 0;
  if (0 < *(int *)(*(int *)(param_1 + 0x110) + 0x6c)) {
    do {
      iVar1 = FUN_004f8b10(param_3,*(undefined4 *)(iVar2 + 0xb4));
      if (iVar1 == 0) {
        param_2[2] = iVar2;
        *param_2 = param_1;
        param_2[1] = 0;
        return 1;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xd0;
    } while (iVar3 < *(int *)(*(int *)(param_1 + 0x110) + 0x6c));
  }
  iVar2 = 0;
  if ((param_4 != 0) && (DAT_0097388c != 0)) {
    iVar2 = FUN_005c1300(param_3);
  }
  *param_2 = iVar2;
  param_2[1] = iVar2;
  param_2[2] = iVar2;
  return 0;
}

