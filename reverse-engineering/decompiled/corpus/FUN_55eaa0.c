/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55eaa0; label: FUN_0055eaa0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055eaa0(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  uint local_20;
  int local_1c;
  uint local_18;
  int iStack_14;
  undefined4 local_c;
  
  local_c = *(undefined4 *)(param_1 + 0xda4);
  iVar6 = FUN_0055f450();
  _DAT_0093d82c = 0;
  if ((DAT_00951364 != 0) && (*(int *)(iVar6 + 300) == DAT_00951364)) {
    _DAT_0093d82c = 0;
    return;
  }
  if (_DAT_00950780 != 0.0) {
    _DAT_0093d82c = 0;
    return;
  }
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x100) != 0) {
    _DAT_0093d82c = 0;
    return;
  }
  if (*(int *)(param_1 + 0xcd0) != 0) {
    _DAT_0093d82c = 0;
    return;
  }
  if (DAT_0093b2a4 == 0) {
    _DAT_0093d82c = 0;
    return;
  }
  if ((((DAT_00855de0 != 0) && ((char)*(uint *)(param_1 + 0x1fc) < '\0')) &&
      ((*(uint *)(param_1 + 0x1fc) & 0x100) == 0)) || (*(char *)(param_1 + 0x28b) != '\0')) {
LAB_0055f188:
    *(undefined4 *)(param_1 + 0xda4) = _DAT_00802be8;
    return;
  }
  iVar6 = *(int *)(param_1 + 0xca4);
  iVar7 = FUN_0040aa60();
  if (iVar6 == iVar7) goto LAB_0055f188;
  sVar2 = *(short *)(param_1 + 0x1064);
  if (param_2 != 0) {
    local_20 = 0;
    local_18 = 0;
    if (param_2 < 1) {
      local_20 = 1;
    }
    else {
      local_18 = 1;
    }
    goto LAB_0055ec9e;
  }
  uVar9 = DAT_00802288;
  uVar11 = DAT_0080228c;
  if (DAT_0093d830 != 0) {
    uVar9 = DAT_00802288 & ~DAT_008022c0;
    uVar11 = DAT_0080228c & ~DAT_008022c0;
  }
  local_18 = *(uint *)(iVar6 + 8) & uVar11;
  local_20 = *(uint *)(iVar6 + 8) & uVar9;
  if (local_20 == 0) {
    if (local_18 == 0) goto LAB_0055ebf3;
  }
  else if (local_18 != 0) {
    local_18 = 0;
    local_20 = 0;
LAB_0055ebf3:
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      local_18 = *(uint *)(iVar6 + 4) & uVar11;
      local_20 = *(uint *)(iVar6 + 4) & uVar9;
      if (local_20 == 0) {
        if (local_18 != 0) goto LAB_0055ec47;
        *(undefined4 *)(param_1 + 0xda4) = _DAT_00802be8;
      }
      else if (local_18 == 0) {
LAB_0055ec47:
        fVar3 = *(float *)(param_1 + 0xda4) - _DAT_00925018;
        *(float *)(param_1 + 0xda4) = fVar3;
        if (0.0 < fVar3) {
          local_18 = 0;
          local_20 = 0;
        }
        else {
          *(undefined4 *)(param_1 + 0xda4) = _DAT_00802bec;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0xda4) = _DAT_00802be8;
        local_18 = 0;
        local_20 = 0;
      }
    }
  }
  local_c = *(undefined4 *)(param_1 + 0xda4);
  if ((local_20 == 0) && (local_18 == 0)) {
    return;
  }
LAB_0055ec9e:
  bVar5 = false;
  if ((DAT_0093d834 == (code *)0x0) ||
     (iVar6 = (*DAT_0093d834)(param_1,local_20,param_3), iVar6 == 0)) {
    iVar6 = *(int *)(DAT_029130e4 + 0x10);
    iVar7 = 0;
    local_1c = 0;
    if (0 < iVar6) {
      psVar10 = *(short **)(DAT_029130e4 + 0x18);
      do {
        local_1c = iVar7;
        if (*(short *)(param_1 + 0x1064) == *psVar10) break;
        iVar7 = iVar7 + 1;
        psVar10 = psVar10 + 0x2a;
        local_1c = iVar7;
      } while (iVar7 < iVar6);
    }
    if (local_1c != iVar6) {
      iStack_14 = 0;
      do {
        if (local_20 == 0) {
          local_1c = local_1c + 1;
          if (local_1c == iVar6) {
            local_1c = 0;
          }
        }
        else {
          local_1c = local_1c + -1;
          if (local_1c == -1) {
            local_1c = iVar6 + -1;
          }
        }
        iVar7 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x18) + local_1c * 0x54);
        iStack_14 = iStack_14 + 1;
        iVar6 = FUN_00594250(iVar7,0,0);
        if (((*(byte *)(*(int *)(DAT_029130e4 + 0x18) + 2 + local_1c * 0x54) & 1) != 0) &&
           ((((iVar6 != -1 ||
              (iVar12 = iVar7 * 0x120, (*(uint *)(iVar12 + 0x90 + DAT_0093b284) & 0x80000000) != 0))
             || ((*(byte *)(iVar12 + 0x97 + DAT_0093b284) & 1) != 0)) ||
            (((DAT_00951288 != 0 && (DAT_00951154 != 0)) &&
             ((iVar8 = FUN_0056e0f0(0x100), iVar8 != 0 &&
              ((*(uint *)(iVar12 + 0x94 + DAT_0093b284) & 0x2000000) != 0)))))))) {
          iVar12 = iVar7 * 0x4c;
          if (DAT_00951288 == 0) {
            if (((*(uint *)(DAT_0093b274 + 4 + iVar12) & 0x2000) == 0) &&
               ((*(byte *)(iVar7 * 0x120 + 0x90 + DAT_0093b284) & 0x40) == 0)) {
LAB_0055ef4e:
              if ((DAT_00951154 == 0) || (DAT_00951288 == 0)) {
LAB_0055ef66:
                iVar8 = iVar7 * 0x120 + DAT_0093b284;
                if ((*(uint *)(iVar8 + 0x90) & 0x80000000) == 0) {
                  if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) || (iVar6 != -1)) ||
                     ((*(byte *)(iVar8 + 0x97) & 1) != 0)) {
                    if ((*(byte *)(iVar8 + 0x97) & 1) != 0) goto LAB_0055efcd;
                    if (iVar6 != -1) {
                      iVar6 = FUN_00594960(iVar7);
                      goto LAB_0055efc6;
                    }
                  }
                }
                else if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
                  iVar6 = FUN_0056e0f0(0x100);
LAB_0055efc6:
                  if (iVar6 != 0) goto LAB_0055efcd;
                }
              }
              else {
LAB_0055efcd:
                if ((((*(float *)(param_1 + 0x21c) == 2e+06) ||
                     (*(float *)(param_1 + 0x224) == 2e+06)) ||
                    (*(code **)(*(int *)(param_1 + 0x54) + 0x18) == FUN_004b3350)) ||
                   (fVar3 = *(float *)(DAT_0093b274 + 0x38 + iVar12) -
                            *(float *)(DAT_0093b274 + 0x34 + iVar12),
                   fVar4 = *(float *)(param_1 + 0x224) - *(float *)(param_1 + 0x21c),
                   fVar4 < fVar3 == (fVar4 == fVar3))) {
                  bVar5 = true;
                }
                else {
                  FUN_00547930(0x32,param_1 + 0x80,0,0);
                }
              }
            }
          }
          else {
            uVar9 = *(uint *)(DAT_0093b274 + 4 + iVar12);
            if ((((uVar9 & 0x2000) != 0) ||
                (((DAT_00951154 != 0 && ((uVar9 & 0x4000000) != 0)) ||
                 ((*(uint *)(iVar7 * 0x120 + 0x90 + DAT_0093b284) & 0x80000000) != 0)))) ||
               (((DAT_00951154 != 0 && (iVar8 = FUN_0056e0f0(0x100), iVar8 != 0)) &&
                ((*(uint *)(iVar7 * 0x120 + 0x94 + DAT_0093b284) & 0x2000000) != 0)))) {
              if (DAT_00951154 == 0) goto LAB_0055ef66;
              iVar8 = FUN_00574d00(iVar7);
              if (iVar8 == -1) {
                if (((*(uint *)(iVar7 * 0x120 + 0x90 + DAT_0093b284) & 0x80000000) != 0) ||
                   (((DAT_00951154 != 0 && (iVar8 = FUN_0056e0f0(0x100), iVar8 != 0)) &&
                    ((*(uint *)(iVar7 * 0x120 + 0x94 + DAT_0093b284) & 0x2000000) != 0))))
                goto LAB_0055ee8a;
              }
              else if ((DAT_0095136c != 0) && (*(char *)(DAT_0095136c + 4 + iVar8 * 0xc) != '\0')) {
LAB_0055ee8a:
                cVar1 = *(char *)(param_1 + 0x283);
                if ((cVar1 < '\0') ||
                   ((('\x10' < cVar1 || (((&DAT_0080364c)[cVar1 * 0xc] & 1) == 0)) ||
                    (0.0 < *(float *)(iVar7 * 0x120 + 0x28 + DAT_0093b284))))) goto LAB_0055ef4e;
              }
            }
          }
        }
        iVar6 = *(int *)(DAT_029130e4 + 0x10);
      } while (((iStack_14 <= iVar6) && (!bVar5)) && (iVar7 != *(short *)(param_1 + 0x1064)));
      if ((iStack_14 < *(int *)(DAT_029130e4 + 0x10)) && (bVar5)) {
        if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
           (FUN_00576960(DAT_00803998), DAT_00951288 == 0)) {
          FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
        }
        FUN_0041bc20(param_1,iVar7,(int)sVar2,1);
        if (DAT_0093d7f4 == 0) {
          iVar6 = -1;
        }
        else {
          iVar6 = (int)*(short *)(DAT_0093d7f4 + 0x1064);
        }
        if (DAT_0093d7f0 == 0) {
          iVar7 = -1;
        }
        else {
          iVar7 = (int)*(short *)(DAT_0093d7f0 + 0x1064);
        }
        FUN_0055e1b0(0,iVar7,iVar6);
        if (DAT_0093d838 != (code *)0x0) {
          (*DAT_0093d838)(param_1,local_20);
        }
        *(undefined4 *)(param_1 + 0xda4) = local_c;
        if (param_3 != 0) {
          if (local_20 == 0) {
            if (local_18 != 0) {
              FUN_00547930(0x24,param_1 + 0x80,0,0);
              return;
            }
          }
          else {
            FUN_00547930(0x23,param_1 + 0x80,0,0);
          }
        }
      }
    }
  }
  return;
}

