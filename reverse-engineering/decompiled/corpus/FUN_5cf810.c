/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cf810; label: FUN_005cf810
 */

int FUN_005cf810(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = param_1;
  piVar1 = (int *)(param_1 + 0x110);
  iVar4 = 0;
  iVar5 = *(int *)(*piVar1 + 0x70);
  param_1 = 0;
  if (0 < *(int *)(*piVar1 + 0x6c)) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(iVar5 + 0xb4),param_2);
      if (iVar3 != 0) {
        *in_EAX = iVar2;
        in_EAX[2] = iVar5;
        in_EAX[1] = 0;
        iVar4 = iVar4 + 1;
        in_EAX = in_EAX + 3;
        if (param_3 <= iVar4) {
          return iVar4;
        }
      }
      param_1 = param_1 + 1;
      iVar5 = iVar5 + 0xd0;
    } while (param_1 < *(int *)(*(int *)(iVar2 + 0x110) + 0x6c));
  }
  if ((param_4 != 0) && (DAT_0097388c != 0)) {
    FUN_005c1300(param_2);
  }
  return iVar4;
}

