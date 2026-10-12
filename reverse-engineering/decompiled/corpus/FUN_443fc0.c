/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443fc0; label: FUN_00443fc0
 */

undefined4
FUN_00443fc0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_24;
  int local_20;
  int local_1c;
  float local_18;
  int local_14;
  undefined1 local_c [12];
  
  local_18 = 1e+09;
  local_24 = 0;
  local_20 = 0;
  local_1c = -1;
  bVar1 = false;
  local_14 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
       (*piVar3 != 0)) {
      local_20 = *piVar3;
    }
    iVar5 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"type=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"opponent=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"maxrange=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"ifCanTakeover");
              if (iVar2 != 0) {
                bVar1 = true;
              }
            }
            else {
              fVar6 = (float10)FUN_005147c0(param_2,iVar2 + 9);
              local_18 = (float)fVar6 * (float)fVar6;
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 9), piVar3 == (int *)0x0)) {
            local_24 = 0;
          }
          else {
            local_24 = *piVar3;
          }
        }
        else {
          local_14 = iVar2 + 5;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
      if ((local_14 != 0) || (local_24 != 0)) {
        iVar5 = 0;
        if (0 < DAT_0093b278) {
          iVar2 = 0;
          do {
            if (local_1c != -1) break;
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0xc + DAT_0093b274),local_14);
            if (iVar4 == 0) {
              local_1c = iVar5;
            }
            iVar5 = iVar5 + 1;
            iVar2 = iVar2 + 0x4c;
          } while (iVar5 < DAT_0093b278);
        }
        iVar5 = 0;
        if (0 < DAT_0093d500) {
          iVar2 = 0;
          do {
            iVar4 = iVar2 + DAT_0093d504;
            if (((((*(uint *)(iVar4 + 0x1fc) & 1) != 0) &&
                 ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
                (*(short *)(iVar4 + 0x1064) == local_1c)) &&
               (((*(int *)(iVar4 + 0xea4) == 0 || (*(int *)(iVar4 + 0xea4) == local_20)) &&
                ((*(int *)(iVar4 + 0xcd0) == 0 ||
                 ((*(char *)(*(int *)(iVar4 + 0xcd0) + 0x7b5) != ';' &&
                  (*(char *)(iVar4 + 0x7b5) == ';')))))))) {
              FUN_005b3800(local_c,iVar4 + 0x80,*(int *)(param_3 + 0xd0) + 0x80);
              fVar6 = (float10)FUN_005b3b00(local_c);
              if ((float)fVar6 < local_18) {
                local_24 = iVar4;
                local_18 = (float)fVar6;
              }
            }
            iVar5 = iVar5 + 1;
            iVar2 = iVar2 + 0x10d8;
          } while (iVar5 < DAT_0093d500);
        }
        if (local_24 == 0) {
          *(undefined4 *)(local_20 + 0xea4) = 0;
          return 1;
        }
        if (bVar1) {
          if (*(int *)(local_24 + 0xcd0) != 0) {
            return 1;
          }
          if ((*(byte *)(*(int *)(*(int *)(local_24 + 0x54) + 0x24) + 0x90) & 0x40) == 0) {
            return 1;
          }
          if ((*(byte *)(*(int *)(local_20 + 0x54) + 4) & 0x10) != 0) {
            return 1;
          }
        }
        iVar5 = *(int *)(local_20 + 0xea4);
        if (((iVar5 != 0) && (*(int *)(iVar5 + 0xea4) != 0)) &&
           (*(int *)(iVar5 + 0xea4) == local_20)) {
          *(undefined4 *)(iVar5 + 0xea4) = 0;
        }
        *(int *)(local_20 + 0xea4) = local_24;
        *(int *)(local_24 + 0xea4) = local_20;
      }
    }
  }
  return 1;
}

