/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x452570; label: FUN_00452570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00452570(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  undefined1 uVar9;
  float fVar10;
  
  if ((((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0xd0), piVar3 == (int *)0x0)) ||
      (*piVar3 == 0)) || ((param_1 == 0 || (*(int *)(param_1 + 0x138c) == 0)))) {
    return 1;
  }
  iVar4 = *piVar3;
  if ((param_6 != 0) && (iVar6 = 0, 0 < param_5)) {
    do {
      if ((DAT_009238b0 == (code *)0x0) ||
         (iVar5 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar6 * 4),param_3 + 0x13f), iVar5 == 0)
         ) {
        iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"ignore_radius");
        if (iVar5 == 0) {
          *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
        }
        else {
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"can_go_off_path");
          if (iVar5 == 0) {
            *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
          }
          else {
            iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"hold_special_button");
            if (iVar5 == 0) {
              *(undefined1 *)(param_2 + 0x69) = 1;
            }
            else {
              iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"nearest");
              if (iVar5 == 0) {
                if ((DAT_0093d810 == 0) || (DAT_0093d814 == 0)) {
                  *(int *)(param_2 + 0x6c) = DAT_0093d810;
                }
                else {
                  fVar7 = (float10)FUN_005becc0(*(int *)(param_3 + 0xd0) + 0x5c,DAT_0093d810 + 0x5c,
                                                0);
                  fVar8 = (float10)FUN_005becc0(*(int *)(param_3 + 0xd0) + 0x5c,DAT_0093d814 + 0x5c,
                                                0);
                  if (fVar8 < (float10)(float)fVar7) {
                    *(int *)(param_2 + 0x6c) = DAT_0093d814;
                  }
                  else {
                    *(int *)(param_2 + 0x6c) = DAT_0093d810;
                  }
                }
              }
              else if (*(float *)(param_3 + 0x180) == 0.0) {
                fVar7 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar6 * 4));
                *(float *)(param_3 + 0x180) = (float)fVar7;
              }
            }
          }
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_5);
  }
  if ((*(int *)(param_2 + 0x6c) == 0) && (DAT_0093d810 == 0)) {
    return 0;
  }
  cVar2 = *(char *)(*(int *)(param_3 + 0xd0) + 0x280);
  if (cVar2 != -1) {
    if (0.0 < _DAT_00876ce4) {
      uVar9 = *(undefined1 *)(param_2 + 0x68);
      fVar10 = 0.01;
      goto LAB_00452796;
    }
    if (cVar2 != -1) {
      uVar9 = *(undefined1 *)(param_2 + 0x68);
      fVar10 = (float)(&DAT_00876c98)[cVar2] + *(float *)(param_3 + 0x180);
      goto LAB_00452796;
    }
  }
  uVar9 = *(undefined1 *)(param_2 + 0x68);
  fVar10 = *(float *)(param_3 + 0x180);
LAB_00452796:
  FUN_00534e10(*(int *)(param_3 + 0xd0),DAT_0093d810,uVar9,fVar10);
  if (*(char *)(param_2 + 0x69) != '\0') {
    puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802280;
    puVar1 = (uint *)(*(int *)(iVar4 + 0xca4) + 4);
    *puVar1 = *puVar1 | DAT_00802280;
  }
  return 0;
}

