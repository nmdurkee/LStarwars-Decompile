/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x451d50; label: FUN_00451d50
 */

undefined4
FUN_00451d50(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined4 local_10;
  int local_8;
  float local_4;
  
  local_4 = 1.5;
  iVar5 = 0;
  iVar4 = 0;
  bVar1 = true;
  local_10 = 0;
  local_8 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
       (*piVar3 != 0)) {
      iVar4 = *piVar3;
    }
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"locator=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"radius=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
              if (iVar2 == 0) {
                bVar1 = false;
              }
              else {
                iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"type=CHOKE");
                if (iVar2 == 0) {
                  local_10 = 1;
                }
                else {
                  iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"type=DROID");
                  if (iVar2 == 0) {
                    local_10 = 2;
                  }
                  else {
                    iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"type=ComboOpponent");
                    if (iVar2 == 0) {
                      local_10 = 3;
                    }
                  }
                }
              }
            }
            else {
              fVar6 = (float10)FUN_005147c0(param_2,iVar2 + 7);
              local_4 = (float)fVar6;
            }
          }
          else {
            iVar2 = FUN_0051ac10(param_1,iVar2 + 8);
            if (iVar2 != 0) {
              local_8 = iVar2 + 0x10;
            }
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *piVar3;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
      iVar2 = local_8;
      if (!bVar1) {
        FUN_004a48f0();
        return 1;
      }
    }
    if ((iVar4 != 0) || (iVar2 != 0)) {
      FUN_004a4900(iVar4,iVar2,local_4,local_10);
      return 1;
    }
  }
  return 1;
}

