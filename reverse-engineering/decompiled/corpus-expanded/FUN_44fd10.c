/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44fd10; label: FUN_0044fd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044fd10(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_c;
  uint local_8;
  undefined4 local_4;
  
  iVar4 = 0;
  iVar3 = 0;
  local_c = 0;
  local_4 = 1;
  local_8 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar3 = *piVar2;
    }
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"hitter=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"damage=");
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"opponent");
              if (iVar1 == 0) {
                iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757700);
                if (iVar1 != 0) {
                  FUN_005147c0(param_2,iVar1 + 4);
                  local_8 = FUN_006e6b90();
                  if (((int)local_8 < 0) || (0x10 < (int)local_8)) {
                    local_8 = 0;
                  }
                }
              }
              else if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xe4), piVar2 != (int *)0x0)
                       ) && (*piVar2 != 0)) {
                iVar3 = *piVar2;
                piVar2 = *(int **)(param_3 + 0xd0);
                if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
                  local_c = *piVar2;
                }
              }
            }
            else {
              FUN_005147c0(param_2,iVar1 + 7);
              local_4 = FUN_006e6b90();
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 7), piVar2 == (int *)0x0)) {
            local_c = 0;
          }
          else {
            local_c = *piVar2;
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
      if (local_8 != 0) {
        iVar4 = 0;
        iVar3 = DAT_0093d504;
        if (DAT_0093d500 < 1) {
          return 1;
        }
        do {
          if (((*(byte *)(iVar3 + 0x1fc) & 1) != 0) && (*(byte *)(iVar3 + 0x378) == local_8)) {
            FUN_00438230(local_c,iVar3,local_4,0,0,1);
          }
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 0x10d8;
        } while (iVar4 < DAT_0093d500);
        return 1;
      }
    }
    if (iVar3 != 0) {
      FUN_00438230(local_c,iVar3,local_4,0,0,1);
    }
  }
  return 1;
}

