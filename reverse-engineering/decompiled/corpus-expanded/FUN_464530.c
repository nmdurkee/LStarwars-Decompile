/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464530; label: FUN_00464530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464530(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar4 = 0;
  iVar3 = 0;
  uVar2 = 0xffffffff;
  local_4 = 1;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"type=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"FALSE");
          if (iVar1 != 0) {
            local_4 = 0;
          }
        }
        else {
          uVar2 = FUN_00559e20(*param_1,iVar1 + 5);
        }
      }
      else {
        iVar3 = iVar1 + 5;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
    if ((iVar3 != 0) && (iVar3 = FUN_0055a020(*param_1,uVar2,iVar3), iVar3 != 0)) {
      FUN_0055a2b0(*param_1,iVar3,local_4,1);
    }
  }
  return;
}

