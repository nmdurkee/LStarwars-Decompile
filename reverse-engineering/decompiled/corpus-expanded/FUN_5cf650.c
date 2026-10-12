/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cf650; label: FUN_005cf650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005cf650(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = param_1;
  piVar1 = (int *)(param_1 + 0x110);
  iVar5 = *(int *)(*piVar1 + 0x70);
  iVar4 = 0;
  param_1 = 0;
  if (0 < *(int *)(*piVar1 + 0x6c)) {
    do {
      if (param_2 == 0) {
        uVar6 = *(undefined4 *)(iVar5 + 0xb4);
        iVar3 = 0;
      }
      else {
        uVar6 = *(undefined4 *)(iVar5 + 0xb4);
        iVar3 = param_2;
      }
      iVar3 = FUN_004f8940(param_3,uVar6,iVar3);
      if (iVar3 == 0) {
        if (in_EAX != (int *)0x0) {
          *in_EAX = iVar2;
          in_EAX[2] = iVar5;
          in_EAX[1] = 0;
          in_EAX = in_EAX + 3;
        }
        if (param_2 != 0) {
          param_2 = param_2 + 0x14;
        }
        param_1 = param_1 + 1;
        if (param_4 <= param_1) {
          return param_1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xd0;
    } while (iVar4 < *(int *)(*(int *)(iVar2 + 0x110) + 0x6c));
  }
  if ((param_5 != 0) && (DAT_0097388c != 0)) {
    FUN_005c1300(param_3);
  }
  return param_1;
}

