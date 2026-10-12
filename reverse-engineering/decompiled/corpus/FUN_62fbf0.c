/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x62fbf0; label: FUN_0062fbf0
 */

void FUN_0062fbf0(short *param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,int param_8,int param_9,undefined4 param_10,
                 float param_11,undefined4 param_12,int param_13,undefined4 param_14,
                 undefined4 param_15,undefined4 param_16,undefined4 param_17)

{
  undefined4 uVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  undefined1 *puVar9;
  float fVar10;
  bool bVar11;
  float local_154;
  undefined4 local_150;
  int local_14c;
  float local_148;
  int local_144;
  int iStack_140;
  int local_138;
  undefined4 local_134;
  int local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined1 auStack_104 [192];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_154;
  local_138 = param_4;
  local_130 = param_6;
  local_124 = param_7;
  local_120 = param_8;
  local_14c = param_9;
  local_154 = param_11;
  local_150 = param_15;
  local_12c = param_16;
  local_128 = param_17;
  local_148 = 0.0;
  local_144 = 0;
  DAT_02913108 = 0;
  if (param_1 == (short *)0x0) {
    __security_check_cookie(local_4 ^ (uint)&local_154);
    return;
  }
  if (param_3 == (undefined4 *)0x0) goto LAB_0062fe29;
  sVar2 = *(short *)((int)param_3 + 0x42);
  if (sVar2 == -1) {
    cVar7 = *(char *)((int)param_3 + 0x31);
    if (cVar7 == '\0') {
LAB_0062fdf2:
      if (((*(short *)((int)param_3 + 0x36) < 0) ||
          (iVar8 = (int)*(short *)((int)param_3 + 0x36), *(int *)(DAT_029130e4 + 8) <= iVar8)) ||
         (*(int *)(*(int *)(param_1 + 6) + iVar8 * 4) == 0)) goto LAB_0062fe29;
      bVar11 = (*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4) & 0x220) == 0;
    }
    else {
      if (-1 < *(short *)((int)param_3 + 0x32)) {
        iVar8 = (int)*(short *)((int)param_3 + 0x32);
        if (((iVar8 < *(int *)(DAT_029130e4 + 8)) &&
            (*(int *)(*(int *)(param_1 + 6) + iVar8 * 4) != 0)) && (-1 < *(short *)(param_3 + 0xd)))
        {
          iVar5 = (int)*(short *)(param_3 + 0xd);
          if ((iVar5 < *(int *)(DAT_029130e4 + 8)) &&
             (*(int *)(*(int *)(param_1 + 6) + iVar5 * 4) != 0)) {
            if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4) & 0x220) == 0) {
              bVar11 = (*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar5 * 4) + 4) & 0x220) == 0;
              goto LAB_0062fe1f;
            }
            goto LAB_0062fe21;
          }
          cVar7 = *(char *)((int)param_3 + 0x31);
        }
      }
      if (cVar7 == '\0') goto LAB_0062fdf2;
      if (((*(short *)(param_3 + 0xd) < 0) ||
          (iVar8 = (int)*(short *)(param_3 + 0xd), *(int *)(DAT_029130e4 + 8) <= iVar8)) ||
         (*(int *)(*(int *)(param_1 + 6) + iVar8 * 4) == 0)) {
        if (cVar7 != '\0') {
          if (((-1 < *(short *)((int)param_3 + 0x32)) &&
              (iVar8 = (int)*(short *)((int)param_3 + 0x32), iVar8 < *(int *)(DAT_029130e4 + 8))) &&
             (*(int *)(*(int *)(param_1 + 6) + iVar8 * 4) != 0)) {
            bVar11 = (*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4) & 0x220) == 0;
            goto LAB_0062fe1f;
          }
          if (cVar7 != '\0') goto LAB_0062fe29;
        }
        goto LAB_0062fdf2;
      }
      bVar11 = (*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4) & 0x220) == 0;
    }
LAB_0062fe1f:
    if (!bVar11) {
LAB_0062fe21:
      local_144 = 1;
    }
  }
  else if (-1 < *(short *)((int)param_3 + 0x3a)) {
    iVar8 = (int)*(short *)((int)param_3 + 0x3a);
    if (((iVar8 < *(int *)(DAT_029130e4 + 8)) && (*(int *)(*(int *)(param_1 + 6) + iVar8 * 4) != 0))
       && ((-1 < sVar2 &&
           ((iVar5 = (int)sVar2, iVar5 < *(int *)(DAT_029130e4 + 8) &&
            (*(int *)(*(int *)(param_1 + 6) + iVar5 * 4) != 0)))))) {
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4) & 0x220) == 0) {
        bVar11 = (*(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar5 * 4) + 4) & 0x220) == 0;
        goto LAB_0062fe1f;
      }
      goto LAB_0062fe21;
    }
  }
LAB_0062fe29:
  local_134 = 0;
  if (param_4 == 0) goto LAB_0063062d;
  iVar8 = *(int *)(param_1 + 2);
  local_110 = *(undefined4 *)(iVar8 + 0x1ac);
  local_10c = *(undefined4 *)(iVar8 + 0x1b0);
  local_108 = *(undefined4 *)(iVar8 + 0x1b4);
  local_11c = *(undefined4 *)(iVar8 + 0x1b8);
  local_118 = *(undefined4 *)(iVar8 + 0x1bc);
  local_114 = *(undefined4 *)(iVar8 + 0x1c0);
  if (((param_9 == 0) || ((*(uint *)(param_9 + 0x1f8) & 0x200) == 0)) &&
     (iVar8 = FUN_006042e0(&local_110,&local_11c,param_4,0,0), iVar8 == 0)) {
    if (local_144 == 0) goto LAB_0063062d;
    bVar11 = true;
    local_144 = 1;
    FUN_0062f910(*(undefined4 *)(param_1 + 2));
  }
  else {
    bVar11 = false;
    local_144 = 0;
  }
  iStack_140 = (*(code *)PTR_FUN_0080fb94)(param_1,local_44,param_10);
  if (iStack_140 < 1) goto LAB_0063062d;
  if (!bVar11) {
    if (((param_3 == (undefined4 *)0x0) || (DAT_029130f8 != 0)) || (DAT_02913100 != 0)) {
LAB_00630066:
      local_148 = 0.0;
    }
    else {
      if ((*(char *)((int)param_3 + 0x31) != '\0') && (-1 < *(short *)((int)param_3 + 0x32))) {
        iVar8 = (int)*(short *)((int)param_3 + 0x32);
        if ((iVar8 < *(int *)(DAT_029130e4 + 8)) &&
           ((((iVar5 = *(int *)(param_1 + 8), *(int *)(iVar5 + iVar8 * 4) != 0 &&
              (-1 < *(short *)(param_3 + 0xd))) &&
             (iVar6 = (int)*(short *)(param_3 + 0xd), iVar6 < *(int *)(DAT_029130e4 + 8))) &&
            (*(int *)(iVar5 + iVar6 * 4) != 0)))) {
          local_148 = (float)param_3[2] / (float)param_3[3];
          local_148 = (float)FUN_005d3dc0(iStack_140,local_44,*(undefined4 *)(iVar5 + iVar8 * 4),
                                          param_3[4],*(undefined4 *)(iVar5 + iVar6 * 4),param_3[5],
                                          local_148);
          goto LAB_0063006e;
        }
      }
      cVar7 = *(char *)((int)param_3 + 0x31);
      if (cVar7 == '\0') {
LAB_0063001f:
        if (((*(short *)((int)param_3 + 0x36) < 0) ||
            (iVar8 = (int)*(short *)((int)param_3 + 0x36), *(int *)(DAT_029130e4 + 8) <= iVar8)) ||
           (puVar4 = (undefined4 *)(*(int *)(param_1 + 8) + iVar8 * 4),
           *(int *)(*(int *)(param_1 + 8) + iVar8 * 4) == 0)) goto LAB_00630066;
        uVar1 = *param_3;
      }
      else {
        if (((*(short *)(param_3 + 0xd) < 0) ||
            (iVar8 = (int)*(short *)(param_3 + 0xd), *(int *)(DAT_029130e4 + 8) <= iVar8)) ||
           (puVar4 = (undefined4 *)(*(int *)(param_1 + 8) + iVar8 * 4),
           *(int *)(*(int *)(param_1 + 8) + iVar8 * 4) == 0)) {
          if (cVar7 != '\0') {
            if (((-1 < *(short *)((int)param_3 + 0x32)) &&
                (iVar8 = (int)*(short *)((int)param_3 + 0x32), iVar8 < *(int *)(DAT_029130e4 + 8)))
               && (puVar4 = (undefined4 *)(*(int *)(param_1 + 8) + iVar8 * 4),
                  *(int *)(*(int *)(param_1 + 8) + iVar8 * 4) != 0)) {
              uVar1 = param_3[4];
              goto LAB_00630044;
            }
            if (cVar7 != '\0') goto LAB_00630066;
          }
          goto LAB_0063001f;
        }
        uVar1 = param_3[5];
      }
LAB_00630044:
      local_148 = (float)FUN_005d3a20(iStack_140,local_44,*puVar4,uVar1);
    }
  }
LAB_0063006e:
  fVar10 = local_154;
  if (((param_3 == (undefined4 *)0x0) || (DAT_029130fc != 0)) || (DAT_02913100 != 0))
  goto LAB_00630395;
  sVar2 = *(short *)((int)param_3 + 0x42);
  if (sVar2 == -1) {
    cVar7 = *(char *)((int)param_3 + 0x31);
    if (cVar7 == '\0') {
LAB_00630322:
      if (((*(short *)((int)param_3 + 0x36) < 0) ||
          (iVar8 = (int)*(short *)((int)param_3 + 0x36), *(int *)(DAT_029130e4 + 8) <= iVar8)) ||
         (puVar4 = (undefined4 *)(*(int *)(param_1 + 6) + iVar8 * 4),
         *(int *)(*(int *)(param_1 + 6) + iVar8 * 4) == 0)) goto LAB_00630395;
      uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4);
      if ((uVar3 & 0x20) == 0) {
        uVar1 = *param_3;
LAB_0063036e:
        FUN_005f38c0(*(undefined4 *)(param_1 + 2),*puVar4,uVar1,param_12,local_154,local_150);
        goto LAB_006303b3;
      }
      puVar9 = &LAB_0062f4f0;
      if ((uVar3 & 0x200) == 0) {
        puVar9 = &LAB_0062f4c0;
      }
      uVar1 = *param_3;
    }
    else {
      if (-1 < *(short *)((int)param_3 + 0x32)) {
        iVar8 = (int)*(short *)((int)param_3 + 0x32);
        if (((iVar8 < *(int *)(DAT_029130e4 + 8)) &&
            (*(int *)(*(int *)(param_1 + 6) + iVar8 * 4) != 0)) &&
           ((-1 < *(short *)(param_3 + 0xd) &&
            ((iVar5 = (int)*(short *)(param_3 + 0xd), iVar5 < *(int *)(DAT_029130e4 + 8) &&
             (*(int *)(*(int *)(param_1 + 6) + iVar5 * 4) != 0)))))) {
          if (((*(byte *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4) & 0x20) == 0) &&
             ((*(byte *)(*(int *)(*(int *)(param_1 + 4) + iVar5 * 4) + 4) & 0x20) == 0)) {
            local_154 = (float)param_3[2] / (float)param_3[3];
            FUN_005f38f0(*(undefined4 *)(param_1 + 2),
                         *(undefined4 *)(*(int *)(param_1 + 6) + iVar8 * 4),param_3[4],
                         *(undefined4 *)(*(int *)(param_1 + 6) + iVar5 * 4),param_3[5],local_154,
                         param_12,fVar10,local_150);
          }
          else {
            local_154 = (float)param_3[2] / (float)param_3[3];
            FUN_005ebd20(*(undefined4 *)(param_1 + 2),
                         *(undefined4 *)(*(int *)(param_1 + 6) + iVar8 * 4),param_3[4],
                         *(undefined4 *)(*(int *)(param_1 + 6) + iVar5 * 4),param_3[5],local_154,
                         param_12,fVar10,local_150,&LAB_0062f520,local_14c);
          }
          goto LAB_006303b3;
        }
      }
      if (cVar7 == '\0') goto LAB_00630322;
      if (((*(short *)(param_3 + 0xd) < 0) ||
          (iVar8 = (int)*(short *)(param_3 + 0xd), *(int *)(DAT_029130e4 + 8) <= iVar8)) ||
         (puVar4 = (undefined4 *)(*(int *)(param_1 + 6) + iVar8 * 4),
         *(int *)(*(int *)(param_1 + 6) + iVar8 * 4) == 0)) {
        if (cVar7 != '\0') {
          if (((-1 < *(short *)((int)param_3 + 0x32)) &&
              (iVar8 = (int)*(short *)((int)param_3 + 0x32), iVar8 < *(int *)(DAT_029130e4 + 8))) &&
             (puVar4 = (undefined4 *)(*(int *)(param_1 + 6) + iVar8 * 4),
             *(int *)(*(int *)(param_1 + 6) + iVar8 * 4) != 0)) {
            uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4);
            if ((uVar3 & 0x20) == 0) {
              uVar1 = param_3[4];
              goto LAB_0063036e;
            }
            puVar9 = &LAB_0062f4f0;
            if ((uVar3 & 0x200) == 0) {
              puVar9 = &LAB_0062f4c0;
            }
            uVar1 = param_3[4];
            goto LAB_00630292;
          }
          if (cVar7 != '\0') goto LAB_00630395;
        }
        goto LAB_00630322;
      }
      uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + iVar8 * 4) + 4);
      if ((uVar3 & 0x20) == 0) {
        uVar1 = param_3[5];
        goto LAB_0063036e;
      }
      puVar9 = &LAB_0062f4f0;
      if ((uVar3 & 0x200) == 0) {
        puVar9 = &LAB_0062f4c0;
      }
      uVar1 = param_3[5];
    }
LAB_00630292:
    FUN_005eb880(*(undefined4 *)(param_1 + 2),*puVar4,uVar1,param_12,local_154,local_150,puVar9,
                 local_14c);
  }
  else {
    if (-1 < *(short *)((int)param_3 + 0x3a)) {
      iVar8 = (int)*(short *)((int)param_3 + 0x3a);
      if ((((iVar8 < *(int *)(DAT_029130e4 + 8)) &&
           (iVar5 = *(int *)(param_1 + 6), *(int *)(iVar5 + iVar8 * 4) != 0)) && (-1 < sVar2)) &&
         ((iVar6 = (int)sVar2, iVar6 < *(int *)(DAT_029130e4 + 8) &&
          (*(int *)(iVar5 + iVar6 * 4) != 0)))) {
        FUN_005f38f0(*(undefined4 *)(param_1 + 2),*(undefined4 *)(iVar5 + iVar8 * 4),param_3[4],
                     *(undefined4 *)(iVar5 + iVar6 * 4),param_3[4],param_3[0x11],param_12,local_154,
                     local_150);
        goto LAB_006303b3;
      }
    }
LAB_00630395:
    FUN_005d36d0(*(undefined4 *)(param_1 + 2),param_12,local_154,local_150);
  }
LAB_006303b3:
  iVar5 = local_120;
  FUN_0062e1e0(param_1,local_138,local_150,local_124,local_120);
  iVar8 = local_14c;
  DAT_02913108 = 1;
  if (((iVar5 != 0) && (param_13 == 0)) && ((param_2 != 0 && (*(int *)(param_2 + 0x28) != 0)))) {
    FUN_0062c7e0(param_1,param_2,param_3,iVar5,local_14c,
                 *(undefined4 *)(*param_1 * 0x4c + 0x28 + *(int *)(DAT_029130e4 + 0x20)),0,param_14,
                 local_12c,local_128);
  }
  iVar5 = local_14c;
  if ((iVar8 == 0) || ((*(uint *)(iVar8 + 0x1f8) & 0x200) == 0)) {
    fVar10 = 1.4013e-45;
  }
  else {
    fVar10 = 0.0;
  }
  local_154 = fVar10;
  if ((local_14c != 0) && (*(int *)(DAT_029130e4 + 0x34) != 0)) {
    (**(code **)(DAT_029130e4 + 0x34))(local_14c);
  }
  if (local_144 == 0) {
    if ((iVar5 != 0) && ((*(uint *)(iVar5 + 0x1f8) & 0x20000) != 0)) {
      if (DAT_02913114 != (code *)0x0) {
        (*DAT_02913114)();
      }
      FUN_0062fac0(*(undefined4 *)(param_1 + 2),local_138,iStack_140,local_44,local_150,local_148,
                   fVar10);
      if (DAT_02913118 != (code *)0x0) {
        (*DAT_02913118)();
      }
    }
    local_134 = FUN_005f4ff0(*(undefined4 *)(param_1 + 2),local_138,iStack_140,local_44,local_150,
                             local_148,fVar10);
    if ((iVar5 != 0) && (*(ushort *)(iVar5 + 0x28e) != 0)) {
      if (0x10 < *(ushort *)(iVar5 + 0x28e)) {
        *(undefined2 *)(iVar5 + 0x28e) = 0x10;
      }
      FUN_005d49b0(*(undefined4 *)(param_1 + 2),local_138,local_150,*(undefined2 *)(iVar5 + 0x28e),
                   auStack_104,0);
      iVar8 = 0;
      if (*(short *)(iVar5 + 0x28e) != 0) {
        puVar9 = auStack_104;
        do {
          FUN_00684c90(*(undefined2 *)(local_14c + 0x290),puVar9,1,0,0);
          iVar8 = iVar8 + 1;
          puVar9 = puVar9 + 0xc;
        } while (iVar8 < (int)(uint)*(ushort *)(local_14c + 0x28e));
      }
      *(undefined2 *)(local_14c + 0x28e) = 0;
      fVar10 = local_154;
    }
    iVar8 = local_14c;
    if (local_130 != 0) {
      *(undefined1 *)(*(int *)(param_1 + 2) + 0x1a0) = 1;
      if ((local_14c == 0) || ((*(uint *)(local_14c + 0x1f8) & 0x1000) == 0)) {
        DAT_009738ec = 1;
      }
      FUN_005d4690(local_134);
      FUN_005f4ff0(*(undefined4 *)(param_1 + 2),local_130,iStack_140,local_44,local_150,local_148,
                   fVar10);
      FUN_005d46b0();
      if ((iVar8 == 0) || ((*(uint *)(iVar8 + 0x1f8) & 0x1000) == 0)) {
        DAT_009738ec = 0;
      }
    }
  }
  else {
    FUN_0062f940();
  }
LAB_0063062d:
  DAT_029130f8 = 0;
  DAT_029130fc = 0;
  DAT_02913100 = 0;
  if ((param_3 != (undefined4 *)0x0) && (DAT_02913104 == 0)) {
    *(undefined2 *)((int)param_3 + 0x42) = 0xffff;
  }
  DAT_02913104 = 0;
  __security_check_cookie(local_4 ^ (uint)&local_154);
  return;
}

