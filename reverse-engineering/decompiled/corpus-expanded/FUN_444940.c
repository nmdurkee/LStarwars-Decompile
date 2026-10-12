/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x444940; label: FUN_00444940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00444940(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  int local_48;
  int local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  int aiStack_28 [10];
  
  iVar10 = 0;
  local_3c = 0.0;
  local_38 = 0.0;
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  if (param_6 == 0) {
    return 1;
  }
  if ((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
      ((*(byte *)(piVar2 + 0x7f) & 1) != 0)) && (*piVar2 != 0)) {
    local_48 = *piVar2;
  }
  if (0 < param_5) {
    do {
      iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"neutral");
      if (iVar7 == 0) {
        local_40 = 0;
      }
      else {
        iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"goodie");
        if ((iVar7 == 0) ||
           (iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"goody"), iVar7 == 0)) {
          local_40 = 0xffffffff;
        }
        else {
          iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"baddie");
          if ((iVar7 == 0) ||
             (iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"baddy"), iVar7 == 0)) {
            local_40 = 1;
          }
          else {
            iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"goodiebaddie");
            if ((iVar7 == 0) ||
               (iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"goodybaddy"), iVar7 == 0
               )) {
              local_40 = 2;
            }
            else {
              iVar7 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar10 * 4),"default");
              if (iVar7 == 0) {
                local_40 = 3;
              }
              else {
                iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),&DAT_0075772c);
                if (iVar7 == 0) {
                  iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"character=");
                  if (iVar7 == 0) {
                    iVar7 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar10 * 4),"range=");
                    if (iVar7 != 0) {
                      fVar11 = (float10)FUN_005147c0(param_2,iVar7 + 6);
                      local_3c = (float)fVar11 * (float)fVar11;
                    }
                  }
                  else {
                    local_48 = FUN_00440120(param_1,iVar7 + 10);
                  }
                }
                else if ((((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) &&
                         (cVar6 = (*DAT_00923884)(iVar7 + 5), cVar6 != -1)) &&
                        ((iVar7 = (*DAT_00923894)(cVar6), iVar7 != -1 && (local_44 < 10)))) {
                  aiStack_28[local_44] = iVar7;
                  local_44 = local_44 + 1;
                }
              }
            }
          }
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_5);
    if ((0 < local_44) || (0.0 < local_3c)) {
      iVar10 = 0;
      if (DAT_0093d500 < 1) {
        return 1;
      }
      iVar7 = 0;
      do {
        uVar3 = *(uint *)(iVar7 + 0x1fc + DAT_0093d504);
        iVar1 = iVar7 + DAT_0093d504;
        bVar5 = false;
        if ((((uVar3 & 1) == 0) || ((uVar3 & 0x1000) == 0)) ||
           ((*(uint *)(iVar1 + 0x1f8) & 0x400) == 0)) goto LAB_00444eb2;
        iVar9 = 0;
        if (0 < local_44) {
          do {
            if ((int)*(short *)(iVar1 + 0x1064) == aiStack_28[iVar9]) {
              bVar5 = true;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < local_44);
        }
        if ((0.0 < local_3c) && (local_48 != 0)) {
          FUN_005b3800(&local_34,local_48 + 0x5c,iVar1 + 0x5c);
          local_38 = local_2c * local_2c + local_34 * local_34 + local_30 * local_30;
        }
        if (((!bVar5) || ((local_3c <= local_38 && (local_3c != 0.0)))) &&
           ((local_44 != 0 || (local_3c <= local_38)))) goto LAB_00444eb2;
        uVar3 = *(uint *)(iVar1 + 0x1f8);
        uVar8 = uVar3 & 0xfffefffa;
        *(uint *)(iVar1 + 0x1f8) = uVar8;
        switch(local_40) {
        case 0:
          uVar8 = uVar8 | 4;
          break;
        case 1:
switchD_00444de5_caseD_1:
          uVar8 = uVar8 | 1;
          break;
        case 2:
          uVar8 = uVar8 | 0x10000;
          break;
        case 3:
          if (((uVar3 & 0x400) != 0) && (*(byte *)(iVar1 + 0x400) != 0xff)) {
            uVar4 = *(uint *)(*(short *)((uint)*(byte *)(iVar1 + 0x400) * 0xa4 +
                                         *(int *)(param_1 + 0x18) + 0x4e) * 0x4c + 4 +
                             *(int *)(DAT_029130e4 + 0x20));
            if ((uVar4 & 0x200) != 0) {
              uVar8 = uVar8 | 4;
              break;
            }
            if ((uVar4 & 4) != 0) goto switchD_00444de5_caseD_1;
          }
        default:
          goto switchD_00444de5_default;
        }
        *(uint *)(iVar1 + 0x1f8) = uVar8;
switchD_00444de5_default:
        uVar8 = *(uint *)(iVar1 + 0x1f8);
        *(uint *)(iVar1 + 0x4bc) = *(uint *)(iVar1 + 0x4bc) & ~(DAT_00950d60 | _DAT_00950d64);
        uVar4 = _DAT_00950d64;
        if (((uVar8 & 1) != 0) || (uVar4 = DAT_00950d60, (uVar8 & 4) == 0)) {
          *(uint *)(iVar1 + 0x4bc) = *(uint *)(iVar1 + 0x4bc) | uVar4;
        }
        if ((uVar3 & 0x10005 & uVar8) == 0) {
          *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) & 0xfffff7ff;
          *(undefined4 *)(iVar1 + 0xec4) = 0;
          *(undefined4 *)(iVar1 + 0x3ac) = 0;
          *(undefined4 *)(iVar1 + 0xec0) = 0;
        }
LAB_00444eb2:
        iVar10 = iVar10 + 1;
        iVar7 = iVar7 + 0x10d8;
        if (DAT_0093d500 <= iVar10) {
          return 1;
        }
      } while( true );
    }
  }
  if (local_48 == 0) {
    return 1;
  }
  uVar3 = *(uint *)(local_48 + 0x1f8);
  uVar8 = uVar3 & 0xfffefffa;
  *(uint *)(local_48 + 0x1f8) = uVar8;
  switch(local_40) {
  case 0:
    uVar8 = uVar8 | 4;
    break;
  case 1:
    uVar8 = uVar8 | 1;
    break;
  case 2:
    uVar8 = uVar8 | 0x10000;
    break;
  case 3:
    if (((uVar3 & 0x400) != 0) && (*(byte *)(local_48 + 0x400) != 0xff)) {
      uVar4 = *(uint *)(*(short *)((uint)*(byte *)(local_48 + 0x400) * 0xa4 +
                                   *(int *)(param_1 + 0x18) + 0x4e) * 0x4c + 4 +
                       *(int *)(DAT_029130e4 + 0x20));
      if ((uVar4 & 0x200) == 0) {
        if ((uVar4 & 4) != 0) {
          *(uint *)(local_48 + 0x1f8) = uVar8 | 1;
        }
      }
      else {
        *(uint *)(local_48 + 0x1f8) = uVar8 | 4;
      }
    }
  default:
    goto switchD_00444bc4_default;
  }
  *(uint *)(local_48 + 0x1f8) = uVar8;
switchD_00444bc4_default:
  uVar8 = *(uint *)(local_48 + 0x1f8);
  *(uint *)(local_48 + 0x4bc) = *(uint *)(local_48 + 0x4bc) & ~(DAT_00950d60 | _DAT_00950d64);
  uVar4 = _DAT_00950d64;
  if (((uVar8 & 1) != 0) || (uVar4 = DAT_00950d60, (uVar8 & 4) == 0)) {
    *(uint *)(local_48 + 0x4bc) = *(uint *)(local_48 + 0x4bc) | uVar4;
  }
  if ((uVar3 & 0x10005 & uVar8) != 0) {
    return 1;
  }
  *(undefined4 *)(local_48 + 0xec4) = 0;
  *(uint *)(local_48 + 0x4b0) = *(uint *)(local_48 + 0x4b0) & 0xfffff7ff;
  *(undefined4 *)(local_48 + 0x3ac) = 0;
  *(undefined4 *)(local_48 + 0xec0) = 0;
  return 1;
}

