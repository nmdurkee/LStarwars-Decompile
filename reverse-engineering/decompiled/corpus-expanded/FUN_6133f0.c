/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x6133f0; label: FUN_006133f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006133f0(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_11c;
  int *local_118;
  undefined4 local_114;
  int iStack_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_11c;
  local_114 = param_2;
  local_11c = param_4;
  local_108 = param_5;
  local_10c = param_6;
  _memset(local_104,0,0x100);
  for (piVar1 = *(int **)(param_3 + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    if ((piVar1[7] & 0x80000000U) == 0) {
      if (piVar1[9] == (uint)*(ushort *)(local_118 + 3)) {
        iStack_110 = FUN_006be710(piVar1[3]);
        iVar3 = piVar1[6];
        if (iVar3 < 1) {
          iVar3 = *(int *)(iStack_110 + 4);
        }
        if (param_4 == 0) {
          (**(code **)(*param_1 + 4))(iVar3,1);
        }
        else {
          if (param_1[2] == 2) {
            (**(code **)(*piVar1 + 4))(param_4,piVar1[3],local_104,0x100);
          }
          (**(code **)(iStack_110 + 8))(param_1,local_104,iVar3);
          if (param_1[2] == 1) {
            (**(code **)(*piVar1 + 8))(param_4,piVar1[3],local_104,0x100,local_10c);
          }
        }
      }
    }
    else {
      uVar2 = FUN_006be7f0(piVar1[3]);
      iVar3 = (**(code **)*piVar1)(param_4);
      if ((DAT_02900a38 != 0) && (iVar3 == 0)) {
        iVar3 = local_11c;
      }
      iVar4 = FUN_006c66c0(param_1,iVar3);
      param_4 = local_11c;
      if (iVar4 != 0) {
        (**(code **)(*local_118 + 4))(param_1,local_114,uVar2,iVar3,local_108,0);
        param_4 = local_11c;
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_11c);
  return;
}

