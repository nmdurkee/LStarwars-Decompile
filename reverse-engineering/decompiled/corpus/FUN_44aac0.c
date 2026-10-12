/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x44aac0; label: FUN_0044aac0
 */

undefined4
FUN_0044aac0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_4;
  
  local_4 = 0.0;
  iVar4 = -1;
  if (((param_3 == 0) || (piVar2 = *(int **)(param_3 + 0xd0), piVar2 == (int *)0x0)) ||
     (*piVar2 == 0)) {
    return 1;
  }
  iVar3 = *piVar2;
  if (param_6 != 0) {
    iVar5 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8b10("speed=TIPTOE",*(undefined4 *)(param_4 + iVar5 * 4));
          if (iVar1 == 0) {
            iVar4 = 2;
          }
          else {
            iVar1 = FUN_004f8b10("speed=WALK",*(undefined4 *)(param_4 + iVar5 * 4));
            if (iVar1 == 0) {
              iVar4 = 1;
            }
            else {
              iVar1 = FUN_004f8b10("speed=RUN",*(undefined4 *)(param_4 + iVar5 * 4));
              if (iVar1 == 0) {
                iVar4 = 0;
              }
              else {
                fVar6 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar5 * 4));
                local_4 = (float)fVar6;
              }
            }
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
    if (iVar3 != 0) {
      if (iVar4 == 2) {
        local_4 = *(float *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x14);
      }
      else if (iVar4 == 1) {
        local_4 = *(float *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x18);
      }
      else if (iVar4 == 0) {
        local_4 = *(float *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x1c);
        *(undefined4 *)(iVar3 + 0xdc8) = 0x3f800000;
      }
      *(undefined4 *)(iVar3 + 0x68) = 0;
      *(undefined4 *)(iVar3 + 0x6c) = 0;
      *(float *)(iVar3 + 0x70) = local_4;
      FUN_005b3620(iVar3 + 0x68,iVar3 + 0x68,*(undefined2 *)(iVar3 + 0x58));
      return 1;
    }
  }
  return 1;
}

