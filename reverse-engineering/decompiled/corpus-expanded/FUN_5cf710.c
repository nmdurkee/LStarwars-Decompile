/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cf710; label: FUN_005cf710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005cf710(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint local_4;
  
  iVar1 = param_1;
  iVar4 = 0;
  local_4 = 0;
  if (param_1 == 0) {
    FUN_005c1300();
    return 0;
  }
  if (*(int *)(param_1 + 0x110) == 0) {
    piVar3 = (int *)(param_1 + 0x24);
    iVar5 = *(int *)(param_1 + 0x28);
    param_1 = 0;
    if (0 < *piVar3) {
      do {
        if (param_3 == 0) {
          uVar6 = *(undefined4 *)(iVar5 + 0x44);
          iVar2 = 0;
        }
        else {
          uVar6 = *(undefined4 *)(iVar5 + 0x44);
          iVar2 = param_3;
        }
        iVar2 = FUN_004f8940(param_4,uVar6,iVar2);
        piVar3 = param_2;
        if (iVar2 == 0) {
          if (param_2 != (int *)0x0) {
            *param_2 = iVar1;
            param_2[1] = iVar5;
            piVar3 = param_2 + 3;
            param_2[2] = -(uint)(*(int *)(iVar1 + 0x110) != 0) & local_4;
          }
          if (param_3 != 0) {
            param_3 = param_3 + 0x14;
          }
          param_1 = param_1 + 1;
          if (param_5 <= param_1) {
            return param_1;
          }
        }
        local_4 = local_4 + 0xd0;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x4c;
        param_2 = piVar3;
      } while (iVar4 < *(int *)(iVar1 + 0x24));
    }
    if ((param_6 != 0) && (DAT_0097388c != 0)) {
      FUN_005c1300(param_4);
    }
    return param_1;
  }
  iVar1 = FUN_005cf650(param_1,param_3,param_4,param_5,param_6);
  return iVar1;
}

