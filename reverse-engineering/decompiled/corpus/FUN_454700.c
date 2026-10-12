/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x454700; label: FUN_00454700
 */

undefined4
FUN_00454700(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  undefined1 local_4;
  
  local_20 = 0;
  local_18 = 0;
  local_c = local_c & 0xffffff00;
  local_10 = local_10 & 0xffffff00;
  local_14 = local_14 & 0xffffff00;
  local_8 = 0;
  local_1c = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
       (*piVar1 != 0)) {
      local_1c = *piVar1;
    }
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8b10("mypos",*(undefined4 *)(param_4 + iVar3 * 4));
        if ((iVar2 == 0) && (local_1c != 0)) {
          local_8 = local_1c + 0x80;
        }
        else {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"total=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"count=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"messageval=");
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&DAT_00758410);
                if (iVar2 == 0) {
                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"Green=");
                  if (iVar2 == 0) {
                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"Blue=");
                    if (iVar2 != 0) {
                      fVar4 = (float10)FUN_005147c0(param_2,iVar2 + 5);
                      local_4 = (undefined1)(int)ROUND(fVar4);
                      local_14 = CONCAT31(local_14._1_3_,local_4);
                    }
                  }
                  else {
                    fVar4 = (float10)FUN_005147c0(param_2,iVar2 + 6);
                    local_4 = (undefined1)(int)ROUND(fVar4);
                    local_10 = CONCAT31(local_10._1_3_,local_4);
                  }
                }
                else {
                  fVar4 = (float10)FUN_005147c0(param_2,iVar2 + 4);
                  local_4 = (undefined1)(int)ROUND(fVar4);
                  local_c = CONCAT31(local_c._1_3_,local_4);
                }
              }
              else {
                iVar2 = FUN_005aac00(DAT_0095df4c,iVar2 + 0xb,0);
                if (iVar2 != 0) {
                  local_20 = FUN_006e6b90();
                }
              }
            }
            else {
              FUN_005147c0(param_2,iVar2 + 6);
              local_20 = FUN_006e6b90();
            }
          }
          else {
            FUN_005147c0(param_2,iVar2 + 6);
            local_18 = FUN_006e6b90();
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
      if ((local_20 != 0) && (local_20 <= local_18)) {
        FUN_00561940(local_8,local_20,local_18,local_c,local_10,local_14,0x3f400000);
      }
    }
  }
  return 1;
}

