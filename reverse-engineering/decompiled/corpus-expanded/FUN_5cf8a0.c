/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cf8a0; label: FUN_005cf8a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005cf8a0(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_4;
  
  iVar2 = param_1;
  iVar5 = 0;
  local_4 = 0;
  if (param_1 == 0) {
    FUN_005c1300();
    return 0;
  }
  if (*(int *)(param_1 + 0x110) == 0) {
    piVar1 = (int *)(param_1 + 0x24);
    iVar4 = *(int *)(param_1 + 0x28);
    param_1 = 0;
    if (0 < *piVar1) {
      do {
        iVar3 = FUN_004f8a70(*(undefined4 *)(iVar4 + 0x44),param_3);
        if (iVar3 != 0) {
          *param_2 = iVar2;
          param_2[1] = iVar4;
          iVar5 = iVar5 + 1;
          param_2[2] = -(uint)(*(int *)(iVar2 + 0x110) != 0) & local_4;
          param_2 = param_2 + 3;
          if (param_4 <= iVar5) {
            return iVar5;
          }
        }
        local_4 = local_4 + 0xd0;
        param_1 = param_1 + 1;
        iVar4 = iVar4 + 0x4c;
      } while (param_1 < *(int *)(iVar2 + 0x24));
    }
    if ((param_5 != 0) && (DAT_0097388c != 0)) {
      FUN_005c1300(param_3);
    }
    return iVar5;
  }
  iVar2 = FUN_005cf810(param_1,param_3,param_4,param_5);
  return iVar2;
}

