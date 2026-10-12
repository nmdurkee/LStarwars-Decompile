/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cf5b0; label: FUN_005cf5b0
 */

undefined4 FUN_005cf5b0(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if ((param_1 != 0) && (param_3 != 0)) {
    if (*(int *)(param_1 + 0x110) != 0) {
      uVar1 = FUN_005cf510(param_1,param_2,param_3,1);
      return uVar1;
    }
    iVar4 = *(int *)(param_1 + 0x28);
    if (0 < *(int *)(param_1 + 0x24)) {
      do {
        iVar2 = FUN_004f8b10(param_3,*(undefined4 *)(iVar4 + 0x44));
        if (iVar2 == 0) {
          param_2[1] = iVar4;
          *param_2 = param_1;
          param_2[2] = 0;
          return 1;
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x4c;
      } while (iVar3 < *(int *)(param_1 + 0x24));
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    return 0;
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  return 0;
}

