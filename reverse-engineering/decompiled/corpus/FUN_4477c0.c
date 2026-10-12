/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x4477c0; label: FUN_004477c0
 */

undefined4
FUN_004477c0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int local_28;
  int aiStack_20 [8];
  
  local_28 = 0;
  if (((param_3 == 0) || (piVar5 = *(int **)(param_3 + 0xd0), piVar5 == (int *)0x0)) ||
     (*piVar5 == 0)) {
    return 1;
  }
  iVar1 = *piVar5;
  if (param_6 != 0) {
    iVar7 = 0;
    param_3 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + param_3 * 4),"opponent=droid");
        iVar3 = local_28;
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + param_3 * 4),"opponent=nearest_enemy");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + param_3 * 4),"opponent=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + param_3 * 4),"last_attacker");
              if (iVar2 == 0) {
                iVar3 = *(int *)(iVar1 + 0x10a8);
              }
              else {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + param_3 * 4),"opponentType");
                if (iVar2 != 0) {
                  uVar6 = 0xff;
                  if ((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) {
                    uVar6 = (*DAT_00923884)(iVar2 + 0xd);
                    uVar6 = uVar6 & 0xff;
                    if (uVar6 != 0xff) {
                      uVar6 = (*DAT_00923894)(uVar6);
                    }
                  }
                  iVar4 = 0;
                  iVar2 = DAT_0093d504;
                  if (0 < DAT_0093d500) {
                    do {
                      iVar3 = iVar2;
                      if ((int)*(short *)(iVar2 + 0x1064) == uVar6) break;
                      iVar4 = iVar4 + 1;
                      iVar2 = iVar2 + 0x10d8;
                      iVar3 = local_28;
                    } while (iVar4 < DAT_0093d500);
                  }
                }
              }
            }
            else {
              iVar3 = FUN_00440120(param_1,iVar2 + 9);
            }
          }
          else {
            *(undefined4 *)(iVar1 + 0x10a4) = 0;
          }
        }
        else {
          piVar5 = &DAT_0093d7f4;
          do {
            iVar2 = piVar5[-1];
            if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 1) != 0)) &&
                (((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0 &&
                 (((*(char *)(iVar2 + 0x28b) == '\0' || (0.0 < *(float *)(iVar2 + 0x1010))) &&
                  ((*(byte *)(iVar2 + 0xef3) & 1) == 0)))))) &&
               ((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x10) != 0)) {
              aiStack_20[iVar7] = iVar2;
              iVar7 = iVar7 + 1;
            }
            iVar2 = *piVar5;
            if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 1) != 0)) &&
                (((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0 &&
                 ((*(char *)(iVar2 + 0x28b) == '\0' || (0.0 < *(float *)(iVar2 + 0x1010))))))) &&
               (((*(byte *)(iVar2 + 0xef3) & 1) == 0 &&
                ((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x10) != 0)))) {
              aiStack_20[iVar7] = iVar2;
              iVar7 = iVar7 + 1;
            }
            iVar2 = piVar5[1];
            if (((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 1) != 0)) &&
                 ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0)) &&
                ((*(char *)(iVar2 + 0x28b) == '\0' || (0.0 < *(float *)(iVar2 + 0x1010))))) &&
               (((*(byte *)(iVar2 + 0xef3) & 1) == 0 &&
                ((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x10) != 0)))) {
              aiStack_20[iVar7] = iVar2;
              iVar7 = iVar7 + 1;
            }
            iVar2 = piVar5[2];
            if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x1fc) & 1) != 0)) &&
                (((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0 &&
                 (((*(char *)(iVar2 + 0x28b) == '\0' || (0.0 < *(float *)(iVar2 + 0x1010))) &&
                  ((*(byte *)(iVar2 + 0xef3) & 1) == 0)))))) &&
               ((*(byte *)(*(int *)(iVar2 + 0x54) + 4) & 0x10) != 0)) {
              aiStack_20[iVar7] = iVar2;
              iVar7 = iVar7 + 1;
            }
            piVar5 = piVar5 + 4;
          } while ((int)piVar5 < 0x93d814);
          if (iVar7 != 0) {
            DAT_00876d98 = (DAT_00876d98 + 1) % iVar7;
            iVar3 = aiStack_20[DAT_00876d98];
          }
        }
        local_28 = iVar3;
        param_3 = param_3 + 1;
      } while (param_3 < param_5);
    }
    *(int *)(iVar1 + 0x10a4) = local_28;
  }
  return 1;
}

