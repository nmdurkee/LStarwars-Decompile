/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464ae0; label: FUN_00464ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464ae0(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar4 = 0;
  iVar3 = -1;
  local_4 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"AUTOSTART");
        if (iVar1 == 0) {
          iVar3 = 0;
        }
        else {
          iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"PROXIMITY");
          if (iVar1 == 0) {
            iVar3 = 1;
          }
          else {
            iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"PROXIMITYGROUND");
            if (iVar1 == 0) {
              iVar3 = 2;
            }
            else {
              iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"NOTRIGGER");
              if (iVar1 == 0) {
                iVar3 = 3;
              }
              else {
                iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"TECHNOONLY");
                if (iVar1 == 0) {
                  iVar3 = 4;
                }
                else {
                  iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"INBOXANDGROUND");
                  if (iVar1 == 0) {
                    iVar3 = 6;
                  }
                  else {
                    iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"INBOX");
                    if (iVar1 == 0) {
                      iVar3 = 5;
                    }
                    else {
                      iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"PUSHONLY");
                      if (iVar1 == 0) {
                        iVar3 = 7;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        local_4 = FUN_004f1ff0("name=");
        local_4 = local_4 + iVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
    if ((((local_4 != 0) && (iVar3 != -1)) &&
        (piVar2 = (int *)FUN_0055a020(*param_1,DAT_00802644,local_4), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      *(char *)(*piVar2 + 0x91) = (char)iVar3;
    }
  }
  return;
}

