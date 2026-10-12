/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a3270; label: FUN_004a3270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a3270(uint param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  float10 fVar13;
  undefined8 uVar14;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  float local_24;
  uint local_1c;
  float local_18;
  int local_14;
  float local_c [2];
  float local_4;
  
  iVar3 = param_1;
  if (*(char *)(param_1 + 0x7b5) == '\x1b') {
    return;
  }
  if ((*(uint *)(param_1 + 0xe20) & 0x20000) != 0) {
    return;
  }
  if ((*(char *)(param_1 + 0x280) != -1) && (DAT_00855de0 != 0)) {
    return;
  }
  if ((*(uint *)(param_1 + 0xe20) & 0x1000000) != 0) {
    return;
  }
  bVar4 = *(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) >> 4;
  if ((bVar4 & 1) != 0) {
    param_2 = 1;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) && ((bVar4 & 1) == 0)) {
    return;
  }
  if (*(char *)(param_1 + 0x281) == '\0') {
    return;
  }
  if ((((*(char *)(param_1 + 0x7b5) != -1) && (iVar6 = FUN_00578790(param_1,0x1b), iVar6 == 0)) &&
      (cVar1 = *(char *)(param_1 + 0x7b5), (*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 4) == 0
      )) && ((cVar1 != '\x06' && (cVar1 != '\a')))) {
    return;
  }
  iVar6 = *(int *)(param_1 + 0x54);
  local_28 = *(uint *)(*(int *)(iVar6 + 0x24) + 0x90);
  local_34 = local_28 & 4;
  local_28 = local_28 & 2;
  if (((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 0x10) == 0) ||
     (local_30 = *(int *)(param_1 + 0xd20), local_30 == 0)) {
    iVar6 = FUN_0041aef0(param_1);
    if (iVar6 != 0) {
      iVar7 = FUN_0054fa60();
      if (iVar7 < 0x8000) {
        local_28 = 1;
        local_34 = 0;
      }
      else {
        local_28 = 0;
        local_34 = 1;
      }
    }
    local_18 = 1.5625;
    local_30 = 0;
    local_1c = 0;
    local_2c = 0;
    bVar2 = false;
    local_14 = 0;
    iVar7 = DAT_0093d504;
    if (DAT_0093d500 < 1) {
      return;
    }
    do {
      if (((((((*(uint *)(iVar7 + 0x1fc) & 1) != 0) && (iVar7 != iVar3)) &&
            ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) &&
           (((*(char *)(iVar7 + 0x28b) == '\0' && (*(char *)(iVar7 + 0x288) != '\0')) &&
            ((cVar1 = *(char *)(iVar7 + 0x7b5), cVar1 != '9' && ((cVar1 != '<' && (cVar1 != ';')))))
            ))) && (cVar1 != '\x17')) &&
         ((((cVar1 != 'A' && (cVar1 != '\x0f')) && (cVar1 != 'G')) && (cVar1 != 'F')))) {
        iVar8 = *(int *)(*(int *)(iVar7 + 0x54) + 0x24);
        uVar10 = *(uint *)(iVar8 + 0x90);
        if ((((((uVar10 & 0x8000) == 0) &&
              ((*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0)) &&
             (((*(uint *)(iVar8 + 0x94) & 0x200) == 0 &&
              (((*(uint *)(iVar7 + 0xef0) & 0x400000) == 0 &&
               ((*(uint *)(iVar7 + 0xef0) & 0x10) == 0)))))) &&
            ((*(int *)(PTR_DAT_00802c54 + 300) == 0 ||
             ((*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087afe0 ||
              (((*(uint *)(iVar7 + 0xeec) & 0x8000000) == 0 && (*(char *)(iVar7 + 0x280) == -1))))))
            )) && (*(short *)(iVar7 + 0x1064) != DAT_007f187c)) {
          if (param_3 == 1) {
            if (*(char *)(iVar7 + 0x280) != -1) goto LAB_004a3825;
            if ((*(byte *)(iVar7 + 0x1f8) & 5) != 0) {
              bVar4 = *(byte *)(iVar3 + 0x28d);
              uVar14 = __allshl();
              bVar12 = ((uint)uVar14 &
                       *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar4 * 8)) == 0 &&
                       ((uint)((ulonglong)uVar14 >> 0x20) &
                       *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar4 * 8)) == 0;
              goto LAB_004a3676;
            }
          }
          else if (param_3 == 2) {
            bVar12 = *(char *)(iVar7 + 0x280) == -1;
LAB_004a3676:
            if (bVar12) goto LAB_004a3825;
          }
          if ((*(uint *)(iVar7 + 0xeec) & 0x8000000) == 0) {
            bVar12 = false;
            param_1 = local_34;
            uVar11 = local_28;
            if ((((local_28 == 0) &&
                 (*(char *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x116) == '\f')) &&
                ((*(byte *)(*(int *)(iVar3 + 0x54) + 4) & 8) != 0)) &&
               (*(short *)(iVar7 + 0x1064) == DAT_007f1884)) {
              uVar11 = 1;
            }
            uVar9 = *(uint *)(*(int *)(iVar7 + 0x54) + 4) & 0x10;
            if (((uVar9 == 0) && ((uVar10 & 0x40) != 0)) &&
               (*(int *)(*(int *)(*(int *)(iVar7 + 0x50) + 0xc) + 0x104) != 0)) {
              bVar12 = true;
            }
            else if ((uVar11 == 0) && (local_34 == 0)) {
              if ((uVar9 == 0) && (*(int *)(*(int *)(*(int *)(iVar7 + 0x50) + 0xc) + 0x104) != 0)) {
                bVar12 = true;
              }
              else {
                iVar8 = *(int *)(*(int *)(iVar7 + 0x50) + 0xc);
                if ((*(int *)(iVar8 + 0xac) == 0) && ((uVar9 == 0 || (*(int *)(iVar8 + 0x14) == 0)))
                   ) goto LAB_004a3825;
              }
            }
            else if ((iVar6 == 0) ||
                    (((iVar8 = FUN_0054fa60(), 0x7fff < iVar8 ||
                      ((*(byte *)(*(int *)(iVar7 + 0x54) + 4) & 0x10) != 0)) ||
                     (*(int *)(*(int *)(*(int *)(iVar7 + 0x50) + 0xc) + 0x104) == 0)))) {
              iVar8 = *(int *)(*(int *)(iVar7 + 0x50) + 0xc);
              if (local_34 == 0) {
                iVar8 = *(int *)(iVar8 + 0x14c);
              }
              else {
                iVar8 = *(int *)(iVar8 + 0x150);
              }
              if (iVar8 == 0) {
                if ((*(byte *)(*(int *)(iVar7 + 0x54) + 4) & 0x10) == 0) goto LAB_004a3825;
                uVar11 = 0;
                param_1 = 0;
                bVar12 = false;
              }
            }
            else {
              bVar12 = true;
            }
            fVar13 = (float10)FUN_005b3c50(iVar3 + 0x80,iVar7 + 0x80,local_c);
            local_24 = (float)fVar13;
            if (*(short *)(iVar7 + 0x1064) == DAT_007f18f4) {
              local_24 = local_24 * 0.33333334;
            }
            if ((local_24 < local_18) &&
               (*(float *)(iVar3 + 0xf30) * local_c[0] + *(float *)(iVar3 + 0xf38) * local_4 < 0.0))
            {
              local_18 = local_24;
              local_2c = param_1;
              local_30 = iVar7;
              local_1c = uVar11;
              bVar2 = bVar12;
            }
          }
        }
      }
LAB_004a3825:
      local_14 = local_14 + 1;
      iVar7 = iVar7 + 0x10d8;
    } while (local_14 < DAT_0093d500);
  }
  else {
    if ((((local_28 == 0) && (*(char *)(*(int *)(iVar6 + 0x24) + 0x116) == '\f')) &&
        ((*(byte *)(iVar6 + 4) & 8) != 0)) && (*(short *)(local_30 + 0x1064) == DAT_007f1884)) {
      local_28 = 1;
    }
    uVar10 = *(uint *)(*(int *)(local_30 + 0x54) + 4) & 0x10;
    local_2c = local_34;
    local_1c = local_28;
    if (((uVar10 == 0) &&
        ((*(byte *)(*(int *)(*(int *)(local_30 + 0x54) + 0x24) + 0x90) & 0x40) != 0)) &&
       (*(int *)(*(int *)(*(int *)(local_30 + 0x50) + 0xc) + 0x104) != 0)) {
      bVar2 = true;
    }
    else {
      param_1 = local_34;
      if (local_28 == 0) {
        if (local_34 != 0) {
LAB_004a3443:
          iVar6 = *(int *)(*(int *)(*(int *)(local_30 + 0x50) + 0xc) + 0x150);
          goto LAB_004a345d;
        }
        if ((uVar10 == 0) && (*(int *)(*(int *)(*(int *)(local_30 + 0x50) + 0xc) + 0x104) != 0)) {
          bVar2 = true;
          goto LAB_004a3842;
        }
        iVar6 = *(int *)(*(int *)(local_30 + 0x50) + 0xc);
        if (*(int *)(iVar6 + 0xac) == 0) {
          if (uVar10 == 0) {
            return;
          }
          if (*(int *)(iVar6 + 0x14) == 0) {
            return;
          }
        }
      }
      else {
        if (local_34 != 0) goto LAB_004a3443;
        iVar6 = *(int *)(*(int *)(*(int *)(local_30 + 0x50) + 0xc) + 0x14c);
LAB_004a345d:
        if (iVar6 == 0) {
          if (uVar10 == 0) {
            return;
          }
          local_28 = 0;
          param_1 = 0;
        }
      }
      bVar2 = false;
      local_2c = param_1;
      local_1c = local_28;
    }
  }
LAB_004a3842:
  if (local_30 == 0) {
    return;
  }
  if (*(char *)(local_30 + 0x7b5) == '\x0f') {
    return;
  }
  *(uint *)(iVar3 + 0xe20) = *(uint *)(iVar3 + 0xe20) | 0x20000;
  *(int *)(iVar3 + 0xd18) = local_30;
  *(undefined1 *)(iVar3 + 0xe2d) = 2;
  FUN_0058bfb0(iVar3,local_30,2,0x3f800000,0,0);
  if ((param_2 == 0) && (iVar6 = FUN_00578790(iVar3,0x1b), iVar6 == 0)) {
    return;
  }
  if ((((*(short *)(iVar3 + 0x1064) == DAT_007f198c) && (DAT_0088a54c != 0)) &&
      (*(int *)(iVar3 + 0xcd0) == 0)) && (DAT_0093b2a4 == 0)) {
    iVar6 = FUN_0062f150(iVar3 + 8,0xb,1,1);
    if ((iVar6 == 0) && (iVar6 = FUN_0062f150(iVar3 + 8,0x27,1,1), iVar6 == 0)) {
      FUN_00681f40("JForcePush",iVar3 + 0x80);
      FUN_00548370(iVar3);
    }
    FUN_0054a8d0(**(undefined4 **)(iVar3 + 0xca4),2,0);
    uVar5 = FUN_005be2d0(*(float *)(local_30 + 0x80) - *(float *)(iVar3 + 0x80),
                         *(float *)(local_30 + 0x88) - *(float *)(iVar3 + 0x88));
    *(uint *)(iVar3 + 0xe20) = *(uint *)(iVar3 + 0xe20) | 0x1000000;
    *(undefined2 *)(iVar3 + 0x5a) = uVar5;
    FUN_00549fd0();
    return;
  }
  *(undefined4 *)(iVar3 + 0x77c) = 0;
  *(int *)(iVar3 + 0x790) = local_30;
  *(undefined4 *)(iVar3 + 0x784) = 0x3e99999a;
  *(undefined1 *)(iVar3 + 0x7b5) = 0x1b;
  *(undefined1 *)(iVar3 + 0x7b3) = 0;
  FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
  *(uint *)(iVar3 + 0xe20) = *(uint *)(iVar3 + 0xe20) & 0xfffffc7f;
  uVar10 = *(uint *)(iVar3 + 0xe20);
  if (bVar2) {
    uVar10 = uVar10 | 0x200;
  }
  else {
    if (((local_1c == 0) && (local_2c == 0)) ||
       (*(uint *)(iVar3 + 0xe20) = uVar10 | 0x80, local_2c == 0)) goto LAB_004a3a22;
    uVar10 = uVar10 | 0x180;
  }
  *(uint *)(iVar3 + 0xe20) = uVar10;
LAB_004a3a22:
  if ((*(uint *)(iVar3 + 0xe20) & 0x400) == 0) {
    FUN_00499500(iVar3,0);
    if ((*(uint *)(iVar3 + 0xe20) & 0x200) == 0) {
      FUN_0055e4a0(local_30,1);
      FUN_0055e4e0(local_30 + 0x6c4);
      if ((*(uint *)(iVar3 + 0xe20) & 0x100) == 0) {
        if ((char)*(uint *)(iVar3 + 0xe20) < '\0') {
          FUN_00681f40("ForceChokeCrunch",local_30 + 0x80);
          *(undefined2 *)(local_30 + 0x7aa) = 0x53;
          *(undefined1 *)(local_30 + 0x7b8) = 3;
        }
        else {
          iVar6 = *(int *)(*(int *)(local_30 + 0x50) + 0xc);
          if ((*(int *)(iVar6 + 0xac) == 0) && (*(int *)(iVar6 + 0x14) != 0)) {
            *(undefined2 *)(local_30 + 0x7aa) = 5;
          }
          else {
            *(undefined2 *)(local_30 + 0x7aa) = 0x2b;
          }
          *(undefined1 *)(local_30 + 0x7b8) = 0;
          if (((*(byte *)(iVar3 + 0x1fc) & 0x80) != 0) && (iVar6 = FUN_0056e160(0x13), iVar6 != 0))
          {
            *(undefined1 *)(local_30 + 0x7b8) = 4;
          }
        }
      }
      else {
        *(undefined2 *)(local_30 + 0x7aa) = 0x54;
        *(undefined1 *)(local_30 + 0x7b8) = 2;
      }
      *(int *)(local_30 + 0x790) = iVar3;
      *(undefined1 *)(local_30 + 0x7b5) = 0x1c;
      FUN_0058d930(local_30,0);
      FUN_00499500(local_30,0);
    }
    else {
      FUN_00681f40("ForceMindTrick",iVar3 + 0x80);
    }
  }
  FUN_00681f40("JForcePush",iVar3 + 0x80);
  FUN_00548370(local_30);
  return;
}

