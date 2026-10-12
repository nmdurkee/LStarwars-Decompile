/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x431740; label: FUN_00431740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00431740(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  float fVar5;
  undefined4 uVar6;
  float fVar7;
  bool bVar8;
  bool bVar9;
  undefined2 uVar10;
  undefined *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  float *pfVar16;
  int iVar17;
  undefined4 *puVar18;
  float10 fVar19;
  uint local_a0;
  uint local_9c;
  uint local_90;
  int local_8c;
  uint local_88;
  undefined4 local_84;
  float local_80;
  undefined4 local_7c;
  undefined4 local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54 [12];
  undefined1 local_48 [12];
  undefined1 local_3c [12];
  undefined4 local_30 [12];
  
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x200000) != 0) {
    sVar4 = *(short *)(param_1 + 0x1064);
    fVar3 = *(float *)(param_1 + 0x60) - *(float *)(param_1 + 0x90);
    fVar5 = fVar3 / _DAT_00925018;
    if (sVar4 == DAT_007f1814) {
      puVar11 = &DAT_007f6594;
    }
    else if (sVar4 == DAT_007f1818) {
      puVar11 = &DAT_007f65c4;
    }
    else if (sVar4 == DAT_007f181c) {
      puVar11 = &DAT_007f65f4;
    }
    else {
      puVar11 = &DAT_007f6624;
      if (sVar4 != DAT_007f1848) {
        puVar11 = &DAT_007f6654;
      }
    }
    local_8c = 4;
    pfVar16 = (float *)(param_1 + 0x728);
    puVar18 = local_30;
    do {
      FUN_005b3620(puVar18,((int)puVar11 - (int)local_30) + (int)puVar18,
                   *(undefined2 *)(param_1 + 0x27a));
      FUN_005b37d0(puVar18,puVar18,param_1 + 0x19c);
      fVar19 = (float10)FUN_005506f0(0,puVar18,0x40a00000,0xffffffff);
      fVar1 = (float)fVar19;
      if (fVar1 == 2e+06) {
        *pfVar16 = *(float *)(param_1 + 0x1a0);
        pfVar16[1] = fVar3 / _DAT_00925018;
      }
      else {
        fVar2 = *pfVar16;
        *pfVar16 = fVar3 + fVar2;
        fVar7 = _DAT_00925018 * -5.0 + pfVar16[1];
        pfVar16[1] = fVar7;
        fVar2 = fVar7 * _DAT_00925018 + fVar3 + fVar2;
        *pfVar16 = fVar2;
        if (fVar2 < fVar1) {
          *pfVar16 = fVar1;
          pfVar16[1] = fVar5;
        }
        fVar1 = *(float *)(param_1 + 0x1a0) -
                (*(float *)(param_1 + 0x1dc) + *(float *)(param_1 + 0x1dc));
        if (fVar1 <= *pfVar16) {
          fVar1 = *(float *)(param_1 + 0x1dc) * 3.0 + *(float *)(param_1 + 0x1a0);
          if (fVar1 < *pfVar16) {
            *pfVar16 = fVar1;
            pfVar16[1] = fVar5;
          }
        }
        else {
          *pfVar16 = fVar1;
          pfVar16[1] = fVar5;
        }
      }
      local_78 = *puVar18;
      local_8c = local_8c + -1;
      local_74 = *pfVar16;
      local_70 = puVar18[2];
      pfVar16 = pfVar16 + 2;
      puVar18 = puVar18 + 3;
    } while (local_8c != 0);
    local_80 = DAT_0093b0d0;
    local_84 = DAT_0093b0cc;
    local_7c = DAT_0093b0d4;
    uVar12 = 0;
    puVar18 = local_30 + 2;
    pfVar16 = (float *)(param_1 + 0x728);
    local_8c = 0;
    do {
      uVar12 = uVar12 + 1;
      uVar13 = uVar12 & 0x80000003;
      if ((int)uVar13 < 0) {
        uVar13 = (uVar13 - 1 | 0xfffffffc) + 1;
      }
      uVar15 = uVar13 + 1 & 0x80000003;
      if ((int)uVar15 < 0) {
        uVar15 = (uVar15 - 1 | 0xfffffffc) + 1;
      }
      local_78 = puVar18[-2];
      local_74 = *pfVar16;
      local_70 = *puVar18;
      local_6c = local_30[uVar13 * 3];
      local_68 = *(undefined4 *)(param_1 + 0x728 + uVar13 * 8);
      local_64 = local_30[uVar13 * 3 + 2];
      local_60 = local_30[uVar15 * 3];
      local_5c = *(undefined4 *)(param_1 + 0x728 + uVar15 * 8);
      local_58 = local_30[uVar15 * 3 + 2];
      FUN_005b3800(local_54,&local_6c,&local_78);
      FUN_005b3800(local_3c,&local_60,&local_78);
      FUN_005b3920(local_54,local_54,local_3c);
      FUN_005b37d0(&local_84,&local_84,local_54);
      pfVar16 = pfVar16 + 2;
      puVar18 = puVar18 + 3;
    } while ((int)uVar12 < 4);
    FUN_005b3830(&local_84,&local_84,0x3e800000);
    if (0.0 < local_80) {
      FUN_005b3b30(param_1 + 0xc98,&local_84);
    }
  }
  if ((*(byte *)(param_1 + 0x1fc) & 4) == 0) {
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x200000) == 0) {
      pfVar16 = (float *)(param_1 + 0xf24);
      if (((*pfVar16 == 0.0) && (*(float *)(param_1 + 0xf28) == 1.0)) &&
         (*(float *)(param_1 + 0xf2c) == 0.0)) {
        *(undefined2 *)(param_1 + 0x1058) = 0;
        *(undefined2 *)(param_1 + 0x1056) = 0;
        goto LAB_00431b15;
      }
    }
    else {
      pfVar16 = (float *)(param_1 + 0xc98);
    }
    FUN_0054fec0(pfVar16,param_1 + 0x1056,param_1 + 0x1058);
  }
LAB_00431b15:
  DAT_0092b0c4 = *(ushort *)(param_1 + 0x1056);
  DAT_0092b0c0 = *(ushort *)(param_1 + 0x1058);
  local_9c = (uint)DAT_0092b0c0;
  iVar14 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  uVar12 = *(uint *)(iVar14 + 0x90);
  local_a0 = (uint)DAT_0092b0c4;
  if (((uVar12 & 0x200) == 0) || (*(char *)(param_1 + 0x7b5) != '3')) {
    bVar8 = false;
  }
  else {
    bVar8 = true;
  }
  if (((uVar12 & 0x10000000) == 0) || (local_8c = 1, *(char *)(param_1 + 0x7b5) != 'D')) {
    local_8c = 0;
  }
  if ((*(char *)(param_1 + 0x7b5) != 'F') || (bVar9 = true, *(char *)(param_1 + 0x7b3) != '\0')) {
    bVar9 = false;
  }
  iVar17 = 0;
  if ((*(char *)(param_1 + 0x107a) == '\x02') &&
     (((uVar13 = *(uint *)(*(int *)(param_1 + 0x54) + 4), (uVar13 & 0x100) != 0 ||
       ((uVar12 & 0x200000) != 0)) || (bVar8)))) {
    if ((uVar13 & 0x2000) == 0) {
      fVar19 = (float10)*(float *)(iVar14 + 0x28);
    }
    else {
      fVar19 = (float10)FUN_00498590(param_1,0);
    }
    fVar3 = (float)fVar19;
    if (fVar3 <= 0.0) {
      if (*(char *)(param_1 + 0x281) == '\0') {
        iVar14 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
        uVar12 = *(uint *)(iVar14 + 0x90);
        if (((uVar12 & 0x200000) == 0) && (!bVar8)) {
          if (((((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x100) != 0) &&
               ((*(float *)(iVar14 + 0x28) == 0.0 && ((uVar12 & 0x100) != 0)))) &&
              (*(float *)(param_1 + 0x21c) != 2e+06)) &&
             (*(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c) <
              *(float *)(param_1 + 0x1e0))) {
            iVar17 = 1;
          }
          goto LAB_00431d9f;
        }
      }
      iVar17 = 1;
    }
    else if (*(float *)(param_1 + 0x21c) == 2e+06) {
      local_9c = 0;
      local_a0 = 0;
      iVar17 = 2;
    }
    else {
      fVar5 = *(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c);
      if (fVar3 <= fVar5) {
        if (fVar3 * 2.5 <= fVar5) {
          fVar3 = 0.0;
        }
        else {
          fVar3 = 1.0 - (fVar5 - fVar3) / (fVar3 * 2.5 - fVar3);
        }
      }
      else {
        fVar3 = 1.0;
      }
      iVar14 = FUN_00550040(0,DAT_0092b0c4);
      local_a0 = (int)ROUND((float)iVar14 * fVar3) & 0xffff;
      iVar14 = FUN_00550040(0,DAT_0092b0c0);
      iVar17 = 2;
      local_9c = (int)ROUND((float)iVar14 * fVar3) & 0xffff;
    }
LAB_00431d9f:
    if ((*(short *)(param_1 + 0x1064) == DAT_007f18f4) && (DAT_00951288 == 0)) {
      iVar14 = FUN_00550040(0,DAT_0092b0c4);
      local_a0 = (int)ROUND((double)iVar14 * 0.5) & 0xffff;
      iVar14 = FUN_00550040(0,DAT_0092b0c0);
      local_9c = (int)ROUND((double)iVar14 * 0.5) & 0xffff;
    }
  }
  if (((((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) ||
       (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) <= 0.0)) ||
      ((*(char *)(param_1 + 0x283) != '\a' && (*(char *)(param_1 + 0x283) != '\x10')))) ||
     (*(char *)(param_1 + 0x280) != -1)) {
    bVar8 = false;
  }
  else {
    bVar8 = true;
  }
  if (param_2 == 1) {
    *(ushort *)(param_1 + 0x1052) = (ushort)local_a0;
    *(ushort *)(param_1 + 0x1054) = (ushort)local_9c;
    if (iVar17 != 0) {
      if (local_8c != 0) {
        if ((*(short *)(param_1 + 0x7aa) != 6) && (*(short *)(param_1 + 0x7aa) != 5)) {
          *(undefined2 *)(param_1 + 0x278) = *(undefined2 *)(param_1 + 0x7a4);
          *(undefined2 *)(param_1 + 0x27c) = *(undefined2 *)(param_1 + 0x7a8);
          return;
        }
        *(undefined2 *)(param_1 + 0x278) = 0;
        *(undefined2 *)(param_1 + 0x27c) = 0;
        return;
      }
      if (bVar9) {
        FUN_005b3800(local_48,*(int *)(param_1 + 0x798) + 0x30,param_1 + 0x80);
        FUN_0054fec0(local_48,param_1 + 0x278,param_1 + 0x27c);
        return;
      }
      if (bVar8) {
        *(undefined2 *)(param_1 + 0x278) = *(undefined2 *)(param_1 + 0x105c);
        *(undefined2 *)(param_1 + 0x27c) = *(undefined2 *)(param_1 + 0x105e);
        return;
      }
      if ((iVar17 == 2) || (DAT_029959a0 < *(float *)(param_1 + 0xf28))) {
        *(ushort *)(param_1 + 0x278) = (ushort)local_a0;
        *(ushort *)(param_1 + 0x27c) = (ushort)local_9c;
        return;
      }
    }
    *(undefined2 *)(param_1 + 0x27c) = 0;
    *(undefined2 *)(param_1 + 0x278) = 0;
    return;
  }
  if (param_2 != 2) {
    return;
  }
  if (*(short *)(param_1 + 0x1052) != *(short *)(param_1 + 0x1056)) {
    uVar10 = FUN_00550070(*(short *)(param_1 + 0x1052),local_a0,0x41000000);
    *(undefined2 *)(param_1 + 0x1052) = uVar10;
  }
  if (*(short *)(param_1 + 0x1054) != *(short *)(param_1 + 0x1058)) {
    uVar10 = FUN_00550070(*(short *)(param_1 + 0x1054),local_9c,0x41000000);
    *(undefined2 *)(param_1 + 0x1054) = uVar10;
  }
  if (*(char *)(param_1 + 0x107a) != '\x02') {
    return;
  }
  if (local_8c == 0) {
    if (bVar9) {
      FUN_005b3800(local_48,*(int *)(param_1 + 0x798) + 0x30,param_1 + 0x80);
      FUN_0054fec0(local_48,&local_90,&local_88);
      goto LAB_00432117;
    }
    if (bVar8) {
      local_88 = (uint)*(ushort *)(param_1 + 0x105e);
      local_90 = (uint)*(ushort *)(param_1 + 0x105c);
      goto LAB_00432117;
    }
    if ((iVar17 != 2) && ((iVar17 == 0 || (*(float *)(param_1 + 0xf28) <= DAT_029959a0)))) {
      local_88 = 0;
      local_90 = 0;
      goto LAB_00432117;
    }
  }
  else {
    if ((*(short *)(param_1 + 0x7aa) == 6) || (*(short *)(param_1 + 0x7aa) == 5)) {
      local_90 = 0;
      *(undefined2 *)(param_1 + 0x278) = 0;
      local_88 = 0;
      *(undefined2 *)(param_1 + 0x27c) = 0;
      goto LAB_00432117;
    }
    local_a0._0_2_ = *(ushort *)(param_1 + 0x7a4);
    local_9c._0_2_ = *(ushort *)(param_1 + 0x7a8);
  }
  local_88 = (uint)(ushort)local_9c;
  local_90 = (uint)(ushort)local_a0;
LAB_00432117:
  if ((*(short *)(param_1 + 0x1064) == DAT_007f18f4) && (DAT_00951288 == 0)) {
    uVar6 = 0x40400000;
  }
  else {
    uVar6 = 0x41000000;
  }
  if (*(short *)(param_1 + 0x278) != (short)local_90) {
    uVar10 = FUN_00550070(*(short *)(param_1 + 0x278),local_90,uVar6);
    *(undefined2 *)(param_1 + 0x278) = uVar10;
  }
  if (*(short *)(param_1 + 0x27c) != (short)local_88) {
    uVar10 = FUN_00550070(*(short *)(param_1 + 0x27c),local_88,uVar6);
    *(undefined2 *)(param_1 + 0x27c) = uVar10;
  }
  return;
}

