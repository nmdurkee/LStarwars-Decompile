/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54ea40; label: FUN_0054ea40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054ea40(float param_1)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  short sVar8;
  undefined2 uVar9;
  ushort uVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  byte bVar17;
  short sVar18;
  float10 fVar19;
  short local_18;
  byte local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar15 = (int)param_1;
  *(uint *)((int)param_1 + 0xe24) = *(uint *)((int)param_1 + 0xe24) & 0xffffff7f;
  if (DAT_00802874 == -1) {
    return;
  }
  if (*(char *)((int)param_1 + 0x7b5) != DAT_00802874) {
    if (DAT_00802454 == 0) {
      return;
    }
    if (((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) &&
       (*(char *)((int)param_1 + 0xf00) != '\x01')) {
      return;
    }
    iVar15 = FUN_005620f0(param_1);
    if ((iVar15 == 0) && ((DAT_00802838 == -1 || (*(char *)((int)param_1 + 0x7b5) != DAT_00802838)))
       ) {
      if (DAT_00802818 == -1) {
        return;
      }
      if (*(char *)((int)param_1 + 0x7b5) != DAT_00802818) {
        return;
      }
      if (DAT_00804c98 == -1) {
        return;
      }
      if (*(short *)((int)param_1 + 0x7aa) != DAT_00804c98) {
        return;
      }
      if (*(int *)((int)param_1 + 0x798) != 0) {
        return;
      }
    }
    iVar15 = FUN_0054d6a0(PTR_DAT_00802c54,(int)param_1 + 0x80,param_1,0);
    if (iVar15 == 0) {
      return;
    }
    if (((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) &&
       (*(int *)((int)param_1 + 0xefc) != iVar15)) {
      return;
    }
    bVar17 = *(byte *)(iVar15 + 0x1e) >> 2 & 1;
    if ((((bVar17 == 0) || (0.0 < *(float *)(iVar15 + 0x58))) ||
        ((*(float *)(*(int *)((int)param_1 + 0xca4) + 0x28) <= 0.0 &&
         (*(char *)((int)param_1 + 0x281) != '\0')))) &&
       ((bVar17 != 0 ||
        (((*(uint *)(*(int *)((int)param_1 + 0xca4) + 8) & DAT_00802280) == 0 &&
         ((*(int *)((int)param_1 + 0x79c) != 4 || (*(int *)((int)param_1 + 0x7a0) == 0)))))))) {
      FUN_0058bee0(param_1,iVar15 + 0x30,4,0x40000000,0x3f800000,0x40000000);
      return;
    }
    *(undefined1 *)((int)param_1 + 0x7b5) = (undefined1)DAT_00802874;
    *(int *)((int)param_1 + 0x798) = iVar15;
    sVar18 = DAT_00804c88;
    *(undefined4 *)((int)param_1 + 0x77c) = 0;
    *(undefined4 *)((int)param_1 + 0x784) = 0;
    *(short *)((int)param_1 + 0x7aa) = sVar18;
    fVar1 = *(float *)(iVar15 + 0x40);
    *(undefined1 *)((int)param_1 + 0x7b3) = 0;
    *(float *)((int)param_1 + 0x778) = ABS(fVar1 - *(float *)((int)param_1 + 0x194));
    if ((*(byte *)(iVar15 + 0x1e) & 4) == 0) {
      *(uint *)((int)param_1 + 0x7bc) = *(uint *)((int)param_1 + 0x7bc) | 0x100;
      *(short *)((int)param_1 + 0x5a) = *(short *)(iVar15 + 0x20) + -0x8000;
    }
    else {
      *(uint *)((int)param_1 + 0x7bc) = *(uint *)((int)param_1 + 0x7bc) & 0xfffffeff;
      FUN_0058d8e0(param_1);
    }
    FUN_0054a3e0(0,0x3f000000,0,1);
    FUN_0054e8c0();
    fVar19 = (float10)FUN_0054e820();
    fVar1 = _DAT_00925018 * 0.75 + *(float *)((int)param_1 + 0x778);
    *(float *)((int)param_1 + 0x778) = fVar1;
    if ((float)fVar19 < fVar1) {
      *(float *)((int)param_1 + 0x778) = (float)fVar19;
    }
    iVar15 = *(int *)((int)param_1 + 0xca4);
    *(undefined2 *)((int)param_1 + 0x7a8) = 0x2000;
    *(undefined1 *)((int)param_1 + 0x7b4) = 0;
    if ((0.0 < *(float *)(iVar15 + 0x28)) && ((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0)) {
      local_14 = (byte)(int)ROUND((*(float *)(iVar15 + 0x28) /
                                  *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x1c))
                                  * 30.0);
      *(byte *)((int)param_1 + 0x7b4) = local_14;
      if (local_14 != 0) {
        if (0x3c < local_14) {
          *(undefined1 *)((int)param_1 + 0x7b4) = 0x3c;
        }
        uVar16 = FUN_0054b3d0(param_1,iVar15,*(undefined2 *)((int)param_1 + 0x7a6));
        uVar12 = FUN_00550040(uVar16);
        if ((int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f)) < 0x4000) {
          *(short *)((int)param_1 + 0x7a8) = *(short *)((int)param_1 + 0x7a8) + -0x8000;
        }
      }
    }
    FUN_00547930(0x44,(int)param_1 + 400,0,0);
    *(undefined1 *)((int)param_1 + 0xe32) = 0;
    return;
  }
  if (((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) &&
     (*(int *)((int)param_1 + 0xefc) != *(int *)((int)param_1 + 0x798))) {
    *(undefined4 *)(*(int *)((int)param_1 + 0x798) + 0x58) = 0;
    *(undefined1 *)((int)param_1 + 0x7b5) = 0xff;
    return;
  }
  if (*(char *)((int)param_1 + 0x7b3) == '\x01') {
    iVar15 = *(int *)((int)param_1 + 0xca4);
    if ((*(uint *)(iVar15 + 8) & DAT_00802278) != 0) {
      FUN_0054e980();
      return;
    }
    if (*(float *)(iVar15 + 0x28) == 0.0) {
      return;
    }
    if (*(ushort *)(iVar15 + 0x26) < 0x6001) {
      return;
    }
    if (0x9fff < *(ushort *)(iVar15 + 0x26)) {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x7b3) = 0;
    sVar18 = DAT_00804c88;
    *(undefined4 *)((int)param_1 + 0x784) = 0;
    *(uint *)((int)param_1 + 0x7bc) = *(uint *)((int)param_1 + 0x7bc) & 0xfffffeff;
    *(undefined4 *)((int)param_1 + 0x778) = 0x3dcccccd;
    *(short *)((int)param_1 + 0x7aa) = sVar18;
    *(undefined2 *)((int)param_1 + 0x7a8) = 0x2000;
    *(undefined1 *)((int)param_1 + 0x7b4) = 0;
    if (DAT_00802450 != 1) {
      return;
    }
    *(undefined2 *)((int)param_1 + 0x5a) = *(undefined2 *)(*(int *)((int)param_1 + 0x798) + 0x20);
    return;
  }
  *(float *)((int)param_1 + 0x77c) = *(float *)((int)param_1 + 0x77c) + _DAT_00925018;
  if ((*(uint *)(*(int *)((int)param_1 + 0xca4) + 8) & DAT_00802278) != 0) {
    if ((*(byte *)(*(int *)((int)param_1 + 0x798) + 0x1e) & 4) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x798) + 0x58) = 0x3f800000;
    }
    FUN_0054e980();
    FUN_0054a3e0(0,0x3f000000,0,1);
    return;
  }
  iVar13 = *(int *)((int)param_1 + 0x798);
  if ((((*(byte *)(iVar13 + 0x1e) & 1) == 0) || ((*(byte *)(iVar13 + 0x1e) & 2) == 0)) ||
     ((*(char *)(iVar13 + 0x1c) != '\0' &&
      ((*(int *)(iVar13 + 0x54) == 0 || (*(float *)(iVar13 + 0x28) == 2e+06)))))) {
    *(undefined4 *)(iVar13 + 0x58) = 0;
    *(undefined1 *)((int)param_1 + 0x7b5) = 0xff;
    FUN_0054a3e0(0,0x3f000000,0,1);
    return;
  }
  bVar4 = false;
  bVar6 = false;
  bVar7 = false;
  bVar3 = false;
  uVar9 = FUN_0054b3d0(param_1,*(int *)((int)param_1 + 0xca4));
  iVar13 = *(int *)((int)param_1 + 0xca4);
  if ((*(float *)(iVar13 + 0x28) == 0.0) &&
     ((*(byte *)(*(int *)((int)param_1 + 0x798) + 0x1e) & 4) == 0)) {
    if ((*(uint *)(iVar13 + 8) & DAT_00802280) != 0) {
      uVar12 = *(uint *)((int)param_1 + 0x7bc);
      if ((uVar12 & 0x100) == 0) {
        *(uint *)((int)param_1 + 0x7bc) = uVar12 | 0x100;
        *(short *)((int)param_1 + 0x5a) =
             *(short *)(*(int *)((int)param_1 + 0x798) + 0x20) + -0x8000;
      }
      else {
        *(uint *)((int)param_1 + 0x7bc) = uVar12 & 0xfffffeff;
      }
    }
  }
  else {
    *(uint *)((int)param_1 + 0x7bc) = *(uint *)((int)param_1 + 0x7bc) & 0xfffffeff;
  }
  if ((*(float *)(iVar13 + 0x28) != 0.0) || (*(char *)((int)param_1 + 0x1072) != '\0')) {
    uVar12 = FUN_00550040(*(undefined2 *)(*(int *)((int)param_1 + 0x798) + 0x20),uVar9);
    iVar13 = (uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f);
    if ((iVar13 < 0x2001) || ((*(byte *)((int)param_1 + 0x1072) & 2) != 0)) {
      bVar4 = true;
      if ((DAT_00802458 == 0) || ((*(byte *)(*(int *)((int)param_1 + 0x798) + 0x1e) & 4) == 0)) {
        sVar18 = *(short *)(*(int *)((int)param_1 + 0x798) + 0x20);
        goto LAB_0054ed44;
      }
    }
    else if ((iVar13 < 0x6000) && ((*(byte *)((int)param_1 + 0x1072) & 1) == 0)) {
      if ((int)uVar12 < 1) {
        bVar7 = true;
        sVar18 = *(short *)(*(int *)((int)param_1 + 0x798) + 0x20) + -0x4000;
LAB_0054ed44:
        *(short *)((int)param_1 + 0x5a) = sVar18;
      }
      else {
        bVar6 = true;
        *(short *)((int)param_1 + 0x5a) = *(short *)(*(int *)((int)param_1 + 0x798) + 0x20) + 0x4000
        ;
      }
    }
    else {
      bVar3 = true;
      if ((DAT_00802458 == 0) || ((*(byte *)(*(int *)((int)param_1 + 0x798) + 0x1e) & 4) == 0)) {
        sVar18 = *(short *)(*(int *)((int)param_1 + 0x798) + 0x20) + -0x8000;
        goto LAB_0054ed44;
      }
    }
  }
  iVar13 = FUN_0062f100(*(undefined4 *)((int)param_1 + 0x50),(int)param_1 + 8,(int)DAT_00804c94,
                        (int)DAT_00804c88);
  if ((iVar13 != 0) ||
     (iVar13 = FUN_0062f100(*(undefined4 *)((int)param_1 + 0x50),(int)param_1 + 8,(int)DAT_00804c30,
                            (int)DAT_00804c88), iVar13 != 0)) {
    *(short *)((int)param_1 + 0x5a) = *(short *)(*(int *)((int)param_1 + 0x798) + 0x20) + -0x8000;
  }
  *(short *)((int)param_1 + 0x7aa) = DAT_00804c88;
  sVar8 = DAT_00804c90;
  sVar18 = DAT_00804c8c;
  if ((*(uint *)((int)param_1 + 0x7bc) & 0x100) == 0) {
    if (*(byte *)((int)param_1 + 0x7b4) < 0x10) {
      if (bVar3) goto LAB_0054efa2;
      if (*(byte *)((int)param_1 + 0x7b4) < 0x10) {
        if (*(float *)(*(int *)((int)param_1 + 0xca4) + 0x28) == 0.0) {
          if (bVar4) {
LAB_0054ee63:
            if ((DAT_00804c90 == -1) ||
               (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + DAT_00804c90 * 4) == 0)) {
              param_1 = 0.75;
            }
            else {
              *(short *)((int)param_1 + 0x7aa) = DAT_00804c90;
              fVar19 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),(int)sVar8);
              param_1 = (float)fVar19;
              if (param_1 < 0.5) {
                param_1 = 0.5;
              }
            }
            fVar19 = (float10)FUN_0054e820();
            fVar1 = (float)fVar19;
            if (fVar1 <= *(float *)(iVar15 + 0x778)) {
              *(uint *)(iVar15 + 0xe24) = *(uint *)(iVar15 + 0xe24) | 0x80;
              *(short *)(iVar15 + 0x7aa) = DAT_00804c88;
            }
            else {
              fVar5 = _DAT_00925018 * param_1 + *(float *)(iVar15 + 0x778);
              *(float *)(iVar15 + 0x778) = fVar5;
              if (fVar1 < fVar5) {
                *(uint *)(iVar15 + 0xe24) = *(uint *)(iVar15 + 0xe24) | 0x80;
                *(float *)(iVar15 + 0x778) = fVar1;
              }
              *(undefined4 *)(iVar15 + 0x784) = 0;
              if ((DAT_00802458 != 0) && ((*(byte *)(*(int *)(iVar15 + 0x798) + 0x1e) & 4) != 0)) {
                local_18 = (short)(int)ROUND((float)DAT_00802458 * _DAT_00925018);
                *(short *)(iVar15 + 0x5a) = *(short *)(iVar15 + 0x5a) + local_18;
              }
            }
          }
          else if ((((*(byte *)(*(int *)((int)param_1 + 0x798) + 0x1e) & 4) == 0) &&
                   (*(float *)((int)param_1 + 0x778) < 0.1)) &&
                  (fVar1 = _DAT_00925018 * 0.75 + *(float *)((int)param_1 + 0x778),
                  *(float *)((int)param_1 + 0x778) = fVar1, 0.1 < fVar1)) {
            *(undefined4 *)((int)param_1 + 0x778) = 0x3dcccccd;
          }
        }
        else if (bVar4) goto LAB_0054ee63;
      }
    }
  }
  else {
LAB_0054efa2:
    if (0.0 < *(float *)((int)param_1 + 0x778)) {
      if ((DAT_00804c8c == -1) ||
         (*(int *)(*(int *)(*(int *)((int)param_1 + 0x50) + 0xc) + DAT_00804c8c * 4) == 0)) {
        param_1 = 1.0;
      }
      else {
        *(short *)((int)param_1 + 0x7aa) = DAT_00804c8c;
        fVar19 = (float10)FUN_0062f1c0(*(int *)((int)param_1 + 0x50),(int)sVar18);
        param_1 = (float)fVar19;
        if (param_1 < 0.5) {
          param_1 = 0.5;
        }
      }
      fVar1 = *(float *)(iVar15 + 0x778) - _DAT_00925018 * param_1;
      *(float *)(iVar15 + 0x778) = fVar1;
      if (fVar1 < 0.0) {
        *(undefined4 *)(iVar15 + 0x778) = 0;
      }
      if ((DAT_00802458 != 0) && ((*(byte *)(*(int *)(iVar15 + 0x798) + 0x1e) & 4) != 0)) {
        local_18 = (short)(int)ROUND((float)DAT_00802458 * _DAT_00925018);
        *(short *)(iVar15 + 0x5a) = *(short *)(iVar15 + 0x5a) + local_18;
      }
    }
    if (((0.0 < *(float *)(iVar15 + 0x778)) ||
        (iVar13 = *(int *)(iVar15 + 0x798), *(char *)(iVar13 + 0x1c) != '\0')) ||
       ((*(byte *)(iVar13 + 0x1e) & 4) != 0)) {
      *(undefined4 *)(iVar15 + 0x784) = 0;
    }
    else {
      fVar1 = _DAT_00925018 + *(float *)(iVar15 + 0x784);
      *(float *)(iVar15 + 0x784) = fVar1;
      if ((0.5 <= fVar1) &&
         ((((DAT_00804c94 != -1 &&
            (iVar14 = (int)DAT_00804c94,
            *(int *)(*(int *)(*(int *)(iVar15 + 0x50) + 0xc) + iVar14 * 4) != 0)) ||
           ((DAT_00804c30 != -1 &&
            (iVar14 = (int)DAT_00804c30,
            *(int *)(*(int *)(*(int *)(iVar15 + 0x50) + 0xc) + iVar14 * 4) != 0)))) &&
          (iVar14 != -1)))) {
        *(short *)(iVar15 + 0x7aa) = (short)iVar14;
        *(undefined1 *)(iVar15 + 0x7b3) = 1;
        local_c = DAT_00802444;
        local_8 = DAT_00802448;
        local_4 = DAT_0080244c;
        FUN_005b35a0(&local_c,&local_c,*(undefined2 *)(iVar13 + 0x22));
        local_4 = *(float *)(iVar15 + 0x1dc) + local_4;
        FUN_005b3620(&local_c,&local_c,*(undefined2 *)(*(int *)(iVar15 + 0x798) + 0x20));
        FUN_005b37d0(iVar15 + 0x748,*(int *)(iVar15 + 0x798) + 0x10,&local_c);
        *(short *)(iVar15 + 0x5a) = *(short *)(*(int *)(iVar15 + 0x798) + 0x20) + -0x8000;
      }
    }
  }
  if (DAT_00802450 == 0) {
    uVar12 = (uint)*(ushort *)(iVar15 + 0x5a);
    uVar2 = *(ushort *)(iVar15 + 0x7a6);
    if (0x7fff < *(ushort *)(iVar15 + 0x5a)) {
      uVar12 = uVar12 + 0x8000;
    }
    uVar10 = FUN_00550100((uint)uVar2 * 2,uVar12 * 2,0x2000,&local_10);
    uVar10 = uVar10 >> 1;
    *(ushort *)(iVar15 + 0x7a6) = uVar10;
    if (((0 < local_10) && (uVar10 < uVar2)) || ((local_10 < 0 && (uVar2 < uVar10)))) {
      *(short *)(iVar15 + 0x7a8) = *(short *)(iVar15 + 0x7a8) + -0x8000;
    }
  }
  uVar2 = *(ushort *)(iVar15 + 0x7a8);
  fVar1 = *(float *)(iVar15 + 0x778) / 1.5;
  *(undefined2 *)(iVar15 + 0x7a4) = 0;
  local_18 = (short)(int)ROUND(_DAT_00925018 * -65536.0 * (1.0 / (fVar1 + fVar1 + 1.0)));
  uVar10 = uVar2 - local_18;
  *(ushort *)(iVar15 + 0x7a8) = uVar10;
  if (((0.0 < *(float *)(*(int *)(iVar15 + 0xca4) + 0x28)) && (*(char *)(iVar15 + 0x7b4) == '\0'))
     && ((DAT_00802450 == 0 || ((bVar6 || (bVar7)))))) {
    FUN_0054e8c0();
    *(undefined1 *)(iVar15 + 0x7b4) = 10;
    *(undefined2 *)(iVar15 + 0x7a8) = 0x2000;
    uVar12 = FUN_00550040(uVar9,*(undefined2 *)(iVar15 + 0x7a6));
    if (0x3fff < (int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f))) {
      return;
    }
    *(short *)(iVar15 + 0x7a8) = *(short *)(iVar15 + 0x7a8) + -0x8000;
    return;
  }
  if (((0x7fff < uVar2) || (uVar10 < 0x8000)) && (uVar2 <= uVar10)) {
    return;
  }
  if (*(float *)(*(int *)(iVar15 + 0xca4) + 0x28) == 0.0) {
    iVar13 = -10;
  }
  else {
    if ((*(char *)(iVar15 + 0x7b4) == '\0') ||
       ((*(float *)(iVar15 + 0x68) == 0.0 && (*(float *)(iVar15 + 0x70) == 0.0)))) {
      uVar11 = *(undefined2 *)(iVar15 + 0x5a);
    }
    else {
      uVar11 = FUN_005be2d0(*(undefined4 *)(iVar15 + 0x68),*(undefined4 *)(iVar15 + 0x70));
    }
    if (DAT_00802450 == 1) {
      uVar11 = FUN_0054e890();
    }
    if (DAT_00802450 == 0) {
      uVar12 = FUN_00550040(uVar11,uVar9);
      if ((int)((uVar12 ^ (int)uVar12 >> 0x1f) - ((int)uVar12 >> 0x1f)) < 0x4000) {
LAB_0054f40a:
        *(char *)(iVar15 + 0x7b4) = *(char *)(iVar15 + 0x7b4) + '\n';
        if (*(byte *)(iVar15 + 0x7b4) < 0x3d) {
          return;
        }
        *(undefined1 *)(iVar15 + 0x7b4) = 0x3c;
        return;
      }
    }
    else if ((bVar6) || (bVar7)) goto LAB_0054f40a;
    iVar13 = -0x14;
  }
  if ((int)((uint)*(byte *)(iVar15 + 0x7b4) + iVar13) < 0) {
    *(undefined1 *)(iVar15 + 0x7b4) = 0;
    return;
  }
  *(byte *)(iVar15 + 0x7b4) = *(byte *)(iVar15 + 0x7b4) + (char)iVar13;
  return;
}

