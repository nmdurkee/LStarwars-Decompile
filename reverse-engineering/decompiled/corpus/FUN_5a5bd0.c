/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a5bd0; label: FUN_005a5bd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a5bd0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float *pfVar5;
  float fVar6;
  bool bVar7;
  float fVar8;
  undefined1 uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  float *pfVar18;
  undefined4 *puVar19;
  float *pfVar20;
  float10 fVar21;
  int local_7c;
  int local_74;
  int local_70;
  float local_50 [4];
  float local_40 [4];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  bVar7 = false;
  if (((param_1 != 0) && (*(int *)(param_1 + 0x46c0) != 0)) && (*(int *)(param_1 + 0x46bc) != 0)) {
    _DAT_00805b1c = 0.25;
    local_7c = 0;
    if (0 < *(int *)(param_1 + 0x46c0)) {
      local_70 = 0;
      do {
        iVar17 = *(int *)(param_1 + 0x46bc) + local_70;
        iVar10 = FUN_005cfd60(iVar17 + 0x24);
        *(uint *)(iVar17 + 200) =
             *(uint *)(iVar17 + 200) ^ (iVar10 << 0x12 ^ *(uint *)(iVar17 + 200)) & 0x40000;
        if ((*(uint *)(iVar17 + 200) & 0x40000) != 0) {
          FUN_00558480(*(undefined4 *)(iVar17 + 0x58));
          uVar15 = *(uint *)(iVar17 + 200);
          if (((uVar15 & 1) != 0) && ((char)uVar15 < '\0')) {
            *(uint *)(iVar17 + 200) = uVar15 & 0xffffff3f;
          }
          if ((char)*(uint *)(iVar17 + 200) < '\0') {
            *(uint *)(iVar17 + 200) = *(uint *)(iVar17 + 200) | 0x40;
          }
          uVar15 = *(uint *)(iVar17 + 200);
          if ((uVar15 & 0x2000100) == 0) {
            iVar10 = *(int *)(iVar17 + 0x54);
            if (iVar10 != 0) {
              if ((uVar15 & 0x200) == 0) {
                iVar10 = 1;
                if (((byte)(uVar15 >> 0xc) & 7) != 1 && (uVar15 >> 0xc & 7) != 0) {
                  local_74 = 0xc;
LAB_005a61b5:
                  pfVar18 = *(float **)(iVar17 + 0x58);
                  fVar1 = *(float *)(local_74 + *(int *)(iVar17 + 0x54)) - *pfVar18;
                  iVar11 = local_74 + *(int *)(iVar17 + 0x54);
                  fVar2 = *(float *)(iVar11 + 4) - pfVar18[1];
                  fVar3 = *(float *)(iVar11 + 8) - pfVar18[2];
                  if (((*(float *)(iVar17 + 0x40) * *(float *)(iVar17 + 0x40) <=
                        fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) ||
                      (iVar14 = FUN_005a5ac0(param_1,iVar17,iVar11,local_7c), iVar14 != 0)) ||
                     ((bVar7 = true, (*(uint *)(iVar17 + 200) & 0x10000000) != 0 ||
                      (iVar11 = FUN_005a5960(param_1,iVar17,iVar11,local_7c), iVar11 != 0))))
                  goto LAB_005a6262;
                  *(uint *)(iVar17 + 200) = *(uint *)(iVar17 + 200) | 0x200;
                  if ((*(uint *)(iVar17 + 200) & 0x20000000) != 0) {
                    *(uint *)(iVar17 + 200) = *(uint *)(iVar17 + 200) | 0x10000000;
                  }
                  *(float *)(iVar17 + 0xa4) = *pfVar18;
                  iVar11 = 0;
                  *(float *)(iVar17 + 0xac) = pfVar18[2];
                  if (*(char *)(iVar17 + 0xd1) != '\0') {
                    puVar19 = (undefined4 *)(iVar17 + 0x74);
                    do {
                      puVar12 = (undefined4 *)FUN_005cf9e0(puVar19 + -6);
                      *puVar19 = *puVar12;
                      puVar19[1] = puVar12[1];
                      puVar19[2] = puVar12[2];
                      iVar11 = iVar11 + 1;
                      puVar19 = puVar19 + 3;
                    } while (iVar11 < (int)(uint)*(byte *)(iVar17 + 0xd1));
                  }
                  *(uint *)(iVar17 + 200) =
                       *(uint *)(iVar17 + 200) ^ (iVar10 << 0xf ^ *(uint *)(iVar17 + 200)) & 0x38000
                  ;
                  *(float *)(iVar17 + 8) = _DAT_00925018;
                  goto LAB_005a62b7;
                }
LAB_005a6285:
                if (!bVar7) {
                  if ((*(uint *)(iVar17 + 200) & 0x20000000) != 0) {
                    *(uint *)(iVar17 + 200) = *(uint *)(iVar17 + 200) & 0xeffc7fff;
                  }
                  if ((*(uint *)(iVar17 + 200) & 0x40000000) == 0) {
                    *(undefined1 *)(iVar17 + 0xd0) = 0;
                  }
                }
              }
              else {
                if (*(float *)(iVar17 + 8) <= _DAT_00805b1c) {
                  pfVar18 = *(float **)(iVar17 + 0x58);
                  iVar11 = FUN_006e6b90();
                  fVar1 = (float)(&DAT_029899a0)[iVar11 >> 1 & 0x7fff];
                  *pfVar18 = *(float *)(iVar17 + 0xa4) +
                             fVar1 * (*(float *)(iVar10 + (uVar15 >> 0xf & 7) * 0xc) -
                                     *(float *)(iVar17 + 0xa4));
                  pfVar18[1] = (*(float *)(*(int *)(iVar17 + 0x54) + 4 +
                                          (*(uint *)(iVar17 + 200) >> 0xf & 7) * 0xc) -
                               *(float *)(iVar17 + 0xa8)) * fVar1 + *(float *)(iVar17 + 0xa8);
                  pfVar18[2] = (*(float *)(*(int *)(iVar17 + 0x54) + 8 +
                                          (*(uint *)(iVar17 + 200) >> 0xf & 7) * 0xc) -
                               *(float *)(iVar17 + 0xac)) * fVar1 + *(float *)(iVar17 + 0xac);
                  FUN_005ea660(iVar17 + 0x24);
                  iVar10 = 0;
                  if (*(char *)(iVar17 + 0xd1) != '\0') {
                    pfVar18 = (float *)(iVar17 + 0x7c);
                    do {
                      iVar11 = FUN_005d0370(pfVar18 + -8);
                      uVar15 = *(uint *)(iVar17 + 200) >> 0xf & 7;
                      fVar2 = *(float *)(*(int *)(iVar17 + 0x54) + 8 + uVar15 * 0xc);
                      fVar3 = *pfVar18;
                      *(float *)(iVar11 + 0x30) =
                           (*(float *)(*(int *)(iVar17 + 0x54) + uVar15 * 0xc) - pfVar18[-2]) *
                           fVar1 + pfVar18[-2];
                      *(float *)(iVar11 + 0x38) = fVar1 * (fVar2 - fVar3) + *pfVar18;
                      FUN_005ea660(pfVar18 + -8);
                      iVar10 = iVar10 + 1;
                      pfVar18 = pfVar18 + 3;
                    } while (iVar10 < (int)(uint)*(byte *)(iVar17 + 0xd1));
                  }
                  *(float *)(iVar17 + 8) = *(float *)(iVar17 + 8) + _DAT_00925018;
                  goto LAB_005a5e21;
                }
                FUN_005a5b70(iVar17,uVar15 >> 0xf & 7);
              }
            }
LAB_005a62b7:
            uVar15 = *(uint *)(iVar17 + 200);
            uVar16 = uVar15 >> 6 & 1;
            if ((uVar16 == 0) &&
               (((((uVar15 & 2) != 0 && ((uVar15 & 1) == 0)) ||
                 (**(float **)(iVar17 + 0x58) != *(float *)(iVar17 + 0xa4))) ||
                ((*(float **)(iVar17 + 0x58))[2] != *(float *)(iVar17 + 0xac))))) {
              *(undefined4 *)(iVar17 + 0xa0) = 0;
              *(undefined4 *)(iVar17 + 0x98) = 0;
              *(undefined4 *)(iVar17 + 0x94) = 0;
              *(undefined4 *)(iVar17 + 0x8c) = 0;
            }
            if ((((uVar15 & 1) != 0) || ((uVar15 & 8) != 0)) || (uVar16 != 0)) {
              if (((uVar15 & 1) != 0) || (uVar16 != 0)) {
                cVar4 = *(char *)(iVar17 + 0x10);
                uVar16 = (uint)cVar4;
                if (((int)*(char *)(iVar17 + 0x11) == uVar16) &&
                   (((int)*(char *)(iVar17 + 0x12) == uVar16 &&
                    ((int)*(char *)(iVar17 + 0x13) == uVar16)))) {
                  if ((uVar16 < 0x20) && ((*(uint *)(&DAT_008034cc + uVar16 * 0xc) & 0x20000) != 0))
                  {
                    uVar15 = uVar15 | 0x40;
                  }
                  else {
                    uVar15 = uVar15 & 0xffffffbf;
                  }
                  *(uint *)(iVar17 + 200) = uVar15;
                }
                iVar10 = *(int *)(iVar17 + 0x30);
                if (iVar10 == 0) {
                  if (((cVar4 == *(char *)(iVar17 + 0x11)) && (cVar4 == *(char *)(iVar17 + 0x12)))
                     && (cVar4 == *(char *)(iVar17 + 0x13))) {
                    fVar1 = *(float *)(&DAT_008034c8 + cVar4 * 0xc);
                    *(float *)(iVar17 + 0x98) = fVar1 * *(float *)(iVar17 + 0x98);
                    *(float *)(iVar17 + 0xa0) = fVar1 * *(float *)(iVar17 + 0xa0);
                  }
                  else {
                    *(undefined4 *)(iVar17 + 0x98) = 0;
                    *(undefined4 *)(iVar17 + 0x8c) = 0;
                    *(undefined4 *)(iVar17 + 0xa0) = 0;
                    *(undefined4 *)(iVar17 + 0x94) = 0;
                  }
                }
                else {
                  if ((*(byte *)(iVar17 + 200) & 0x40) == 0) {
                    *(undefined4 *)(iVar17 + 0xa0) = 0;
                    *(undefined4 *)(iVar17 + 0x98) = 0;
                  }
                  if (ABS(*(float *)(iVar10 + 0xf18)) <= ABS(*(float *)(iVar10 + 0xf20))) {
                    *(undefined4 *)(iVar17 + 0x8c) = 0;
                    *(undefined4 *)(iVar17 + 0x98) = 0;
                    *(float *)(iVar17 + 0xa0) = _DAT_00925018 * *(float *)(iVar10 + 0xf20);
                  }
                  else {
                    *(float *)(iVar17 + 0x98) = _DAT_00925018 * *(float *)(iVar10 + 0xf18);
                    *(undefined4 *)(iVar17 + 0x94) = 0;
                    *(undefined4 *)(iVar17 + 0xa0) = 0;
                  }
                }
                fVar21 = (float10)FUN_0054fb40(*(undefined4 *)(iVar17 + 0x8c),
                                               *(undefined4 *)(iVar17 + 0x98),_DAT_00805b10);
                *(float *)(iVar17 + 0x8c) = (float)fVar21;
                fVar21 = (float10)FUN_0054fb40(*(undefined4 *)(iVar17 + 0x94),
                                               *(undefined4 *)(iVar17 + 0xa0),_DAT_00805b10);
                *(float *)(iVar17 + 0x94) = (float)fVar21;
                fVar1 = (30.0 / (1.0 / _DAT_00925018)) * 1e-05;
                if (*(float *)(iVar17 + 0x8c) == 0.0) {
                  if (ABS((float)fVar21) <= fVar1) {
                    *(undefined4 *)(iVar17 + 0x94) = 0;
                    *(undefined4 *)(iVar17 + 0xa0) = 0;
LAB_005a660c:
                    *(uint *)(iVar17 + 200) = *(uint *)(iVar17 + 200) & 0xffffff3f;
                  }
                }
                else if (ABS(*(float *)(iVar17 + 0x8c)) <= fVar1) {
                  *(undefined4 *)(iVar17 + 0x8c) = 0;
                  *(undefined4 *)(iVar17 + 0x98) = 0;
                  goto LAB_005a660c;
                }
              }
              if ((*(byte *)(iVar17 + 200) & 8) == 0) {
                *(undefined4 *)(iVar17 + 0x9c) = 0;
              }
              else {
                *(undefined4 *)(iVar17 + 0x98) = 0;
                *(float *)(iVar17 + 0x9c) = _DAT_00805b0c * _DAT_00925018;
                *(undefined4 *)(iVar17 + 0xa0) = 0;
                *(undefined4 *)(iVar17 + 0x8c) = 0;
                fVar21 = (float10)FUN_0054fb40(*(undefined4 *)(iVar17 + 0x90),
                                               *(undefined4 *)(iVar17 + 0x9c),_DAT_00805b10);
                *(float *)(iVar17 + 0x90) = (float)fVar21;
                *(undefined4 *)(iVar17 + 0x94) = 0;
              }
            }
          }
        }
LAB_005a5e21:
        local_70 = local_70 + 0xd4;
        local_7c = local_7c + 1;
      } while (local_7c < *(int *)(param_1 + 0x46c0));
    }
    iVar10 = 0;
    if (0 < *(int *)(param_1 + 0x46c0)) {
      iVar17 = 0;
      do {
        uVar15 = *(uint *)(*(int *)(param_1 + 0x46bc) + 200 + iVar17);
        iVar11 = *(int *)(param_1 + 0x46bc) + iVar17;
        if ((((uVar15 & 0x40000) != 0) && ((uVar15 & 0x6000100) == 0)) && ((uVar15 & 0x69) != 0)) {
          FUN_005a54b0(param_1,iVar11,iVar10,iVar11 + 0x8c);
        }
        iVar10 = iVar10 + 1;
        iVar17 = iVar17 + 0xd4;
      } while (iVar10 < *(int *)(param_1 + 0x46c0));
    }
    iVar10 = 0;
    if (0 < *(int *)(param_1 + 0x46c0)) {
      iVar17 = 0;
      do {
        uVar15 = *(uint *)(*(int *)(param_1 + 0x46bc) + 200 + iVar17);
        pfVar18 = (float *)(*(int *)(param_1 + 0x46bc) + iVar17);
        if ((((uVar15 & 0x40000) != 0) && ((uVar15 & 0x2000000) == 0)) &&
           ((iVar11 = FUN_005cfd60(pfVar18 + 9), iVar11 != 0 && (((uint)pfVar18[0x32] & 0x4d) != 0))
           )) {
          pfVar5 = (float *)pfVar18[0x16];
          local_c = *pfVar5;
          local_4 = pfVar5[2];
          local_8 = (pfVar5[1] - ABS(pfVar18[0x2d])) - _DAT_00805b14;
          local_2c = local_8 + 0.025;
          local_20 = local_8 + 0.025;
          local_14 = local_8 + 0.025;
          local_8 = local_8 + 0.025;
          local_30 = local_c - (_DAT_00805b18 + ABS(pfVar18[0x2c]));
          local_28 = local_4 - (ABS(pfVar18[0x2e]) + _DAT_00805b18);
          local_24 = ABS(pfVar18[0x2f]) + _DAT_00805b18 + local_c;
          local_1c = local_4 - (ABS(pfVar18[0x2e]) + _DAT_00805b18);
          local_18 = ABS(pfVar18[0x2f]) + _DAT_00805b18 + local_c;
          local_10 = _DAT_00805b18 + ABS(pfVar18[0x31]) + local_4;
          local_c = local_c - (_DAT_00805b18 + ABS(pfVar18[0x2c]));
          local_4 = _DAT_00805b18 + ABS(pfVar18[0x31]) + local_4;
          FUN_0067c8e0(pfVar18[0xd],0);
          pfVar5 = pfVar18 + 7;
          if ((*pfVar5 == 0.0) && (pfVar18[8] == 0.0)) {
            fVar21 = (float10)FUN_005506f0(0,&local_30,0x3dcccccd,0xffffffff);
            local_50[0] = (float)fVar21;
            uVar9 = FUN_0067a600();
            *(undefined1 *)(pfVar18 + 4) = uVar9;
            uVar9 = FUN_0067a670();
            *(undefined1 *)(pfVar18 + 5) = uVar9;
            fVar21 = (float10)FUN_005506f0(0,&local_24,0x3dcccccd,0xffffffff);
            local_50[1] = (float)fVar21;
            uVar9 = FUN_0067a600();
            *(undefined1 *)((int)pfVar18 + 0x11) = uVar9;
            uVar9 = FUN_0067a670();
            *(undefined1 *)((int)pfVar18 + 0x15) = uVar9;
            fVar21 = (float10)FUN_005506f0(0,&local_18,0x3dcccccd,0xffffffff);
            local_50[2] = (float)fVar21;
            uVar9 = FUN_0067a600();
            *(undefined1 *)((int)pfVar18 + 0x12) = uVar9;
            uVar9 = FUN_0067a670();
            *(undefined1 *)((int)pfVar18 + 0x16) = uVar9;
          }
          else {
            FUN_0067a6d0();
            fVar21 = (float10)FUN_005506f0(0,&local_30,0x3dcccccd,0xffffffff);
            local_50[0] = (float)fVar21;
            uVar9 = FUN_0067a600();
            *(undefined1 *)(pfVar18 + 4) = uVar9;
            uVar9 = FUN_0067a670();
            *(undefined1 *)(pfVar18 + 5) = uVar9;
            FUN_0067a6d0();
            fVar21 = (float10)FUN_005506f0(0,&local_24,0x3dcccccd,0xffffffff);
            local_50[1] = (float)fVar21;
            uVar9 = FUN_0067a600();
            *(undefined1 *)((int)pfVar18 + 0x11) = uVar9;
            uVar9 = FUN_0067a670();
            *(undefined1 *)((int)pfVar18 + 0x15) = uVar9;
            FUN_0067a6d0();
            fVar21 = (float10)FUN_005506f0(0,&local_18,0x3dcccccd,0xffffffff);
            local_50[2] = (float)fVar21;
            uVar9 = FUN_0067a600();
            *(undefined1 *)((int)pfVar18 + 0x12) = uVar9;
            uVar9 = FUN_0067a670();
            *(undefined1 *)((int)pfVar18 + 0x16) = uVar9;
            FUN_0067a6d0();
          }
          fVar21 = (float10)FUN_005506f0(0,&local_c,0x3dcccccd,0xffffffff);
          local_50[3] = (float)fVar21;
          uVar9 = FUN_0067a600();
          *(undefined1 *)((int)pfVar18 + 0x13) = uVar9;
          uVar9 = FUN_0067a670();
          *(undefined1 *)((int)pfVar18 + 0x17) = uVar9;
          FUN_0067c8e0(pfVar18[0xd],1);
          FUN_005a4eb0(param_1,pfVar18,iVar10,pfVar5);
          fVar1 = *pfVar5;
          if ((fVar1 == 0.0) && (pfVar18[8] == 0.0)) {
            pfVar18[8] = 0.0;
          }
          else {
            pfVar18[8] = fVar1;
            FUN_005a56f0(param_1,pfVar18,&local_30,local_40);
            iVar11 = 0;
            do {
              if (*(float *)((int)local_40 + iVar11) != -10000.0) {
                *(undefined4 *)((int)local_50 + iVar11) = *(undefined4 *)((int)local_40 + iVar11);
              }
              iVar11 = iVar11 + 4;
            } while (iVar11 < 0x10);
          }
          fVar8 = _DAT_00805a74;
          fVar2 = pfVar18[0x16];
          fVar3 = pfVar18[1] - _DAT_00805a74;
          if (((((local_50[0] < fVar3) && (local_50[1] < fVar3)) && (local_50[2] < fVar3)) &&
              (local_50[3] < fVar3)) ||
             (((fVar3 = _DAT_00805a74 + pfVar18[1], fVar3 < local_50[0] && (fVar3 < local_50[1])) &&
              ((fVar3 < local_50[2] && (fVar3 < local_50[3])))))) {
            fVar6 = (local_50[1] + local_50[0] + local_50[2] + local_50[3]) * 0.25 + _DAT_00805a74;
            pfVar18[1] = fVar6;
            fVar3 = *(float *)((int)fVar2 + 4);
            pfVar18[0x32] = (float)((uint)pfVar18[0x32] | 8);
            *pfVar18 = (fVar3 + pfVar18[0x2d]) - fVar6;
          }
          if (fVar1 != 0.0) {
            fVar1 = *(float *)((int)fVar1 + 0xc0) + *(float *)((int)fVar2 + 4);
            pfVar18[1] = fVar1;
            *pfVar18 = (pfVar18[0x2d] + *(float *)((int)fVar2 + 4)) - fVar1;
          }
          if (*pfVar18 <= fVar8 + 0.0) {
            if (((uint)pfVar18[0x32] & 8) != 0) {
              pfVar18[3] = pfVar18[1];
              pfVar18[0x32] = (float)((uint)pfVar18[0x32] & 0xfffffff7 | 0x800);
            }
          }
          else {
            pfVar18[0x32] = (float)((uint)pfVar18[0x32] | 8);
          }
          uVar15 = 0;
          if ((*(char *)(pfVar18 + 5) == '\b') || (*(char *)(pfVar18 + 4) == '\x0e')) {
            uVar15 = 1;
          }
          if ((*(char *)((int)pfVar18 + 0x15) == '\b') || (*(char *)((int)pfVar18 + 0x11) == '\x0e')
             ) {
            uVar15 = uVar15 + 1;
          }
          if ((*(char *)((int)pfVar18 + 0x16) == '\b') || (*(char *)((int)pfVar18 + 0x12) == '\x0e')
             ) {
            uVar15 = uVar15 + 1;
          }
          if ((*(char *)((int)pfVar18 + 0x17) == '\b') || (*(char *)((int)pfVar18 + 0x13) == '\x0e')
             ) {
            uVar15 = uVar15 + 1;
          }
          if (uVar15 < 4) {
            pfVar18[0x32] = (float)((uint)pfVar18[0x32] | 0x400);
          }
        }
        iVar10 = iVar10 + 1;
        iVar17 = iVar17 + 0xd4;
      } while (iVar10 < *(int *)(param_1 + 0x46c0));
    }
    local_7c = 0;
    if (0 < *(int *)(param_1 + 0x46c0)) {
      local_70 = 0;
      do {
        pfVar18 = (float *)(*(int *)(param_1 + 0x46bc) + local_70);
        fVar1 = pfVar18[0x32];
        if ((((uint)fVar1 & 0x40000) != 0) && (((uint)fVar1 & 0x2000100) == 0)) {
          if ((((uint)fVar1 & 0x400) == 0) && (((uint)fVar1 & 1) != 0)) {
            uVar13 = FUN_00547820(pfVar18[0xc],0);
            FUN_00547930(0x48,pfVar18[0x16],uVar13);
          }
          fVar1 = pfVar18[0x32];
          uVar15 = (uint)fVar1 >> 10 & 1;
          if ((uVar15 == 0) && (((uint)fVar1 & 0x800) == 0)) {
            if (((uint)fVar1 & 1) != 0) {
              if ((((uint)fVar1 & 2) == 0) && (pfVar18[0xc] != 0.0)) {
                uVar13 = FUN_00547820(pfVar18[0xc],0);
                FUN_00547930(0x47,(int)pfVar18[0xc] + 0x80,uVar13);
              }
              if ((((DAT_0080398c != -1) && (pfVar18[0xc] != 0.0)) &&
                  (uVar15 = *(uint *)((int)pfVar18[0xc] + 0x1fc), (uVar15 & 1) != 0)) &&
                 ((char)uVar15 < '\0')) {
                FUN_00576960(DAT_0080398c);
              }
            }
          }
          else {
            pfVar5 = (float *)pfVar18[0x16];
            if (uVar15 != 0) {
              *pfVar5 = pfVar18[0x29];
              pfVar5[2] = pfVar18[0x2b];
              pfVar18[0x32] = (float)((uint)pfVar18[0x32] & 0xffffff3f);
              pfVar18[0x26] = 0.0;
              pfVar18[5] = pfVar18[6];
              pfVar18[0x28] = 0.0;
              pfVar18[0x23] = 0.0;
              pfVar18[0x25] = 0.0;
              FUN_005ea660(pfVar18 + 9);
              iVar10 = 0;
              if (*(char *)((int)pfVar18 + 0xd1) != '\0') {
                pfVar20 = pfVar18 + 0x17;
                do {
                  iVar17 = FUN_005cfac0(pfVar20);
                  if (iVar17 != 0) {
                    iVar17 = FUN_005d0370(pfVar20);
                    if ((float *)(iVar17 + 0x30) != (float *)0x0) {
                      *(float *)(iVar17 + 0x30) = pfVar18[0x29];
                      *(float *)(iVar17 + 0x38) = pfVar18[0x2b];
                      FUN_005ea660(pfVar20);
                    }
                  }
                  iVar10 = iVar10 + 1;
                  pfVar20 = pfVar20 + 3;
                } while (iVar10 < (int)(uint)*(byte *)((int)pfVar18 + 0xd1));
              }
              pfVar18[0x32] = (float)((uint)pfVar18[0x32] & 0xfffffbfe);
            }
            if (((uint)pfVar18[0x32] & 0x800) != 0) {
              pfVar18[0x27] = 0.0;
              pfVar18[0x24] = 0.0;
              pfVar18[0x32] = (float)((uint)pfVar18[0x32] & 0xfffff7f7);
              pfVar18[1] = pfVar18[3];
              fVar1 = pfVar18[3] - pfVar18[0x2d];
              pfVar5[1] = fVar1;
              *pfVar18 = (fVar1 + pfVar18[0x2d]) - pfVar18[1];
              FUN_005ea660(pfVar18 + 9);
            }
          }
        }
        local_70 = local_70 + 0xd4;
        local_7c = local_7c + 1;
      } while (local_7c < *(int *)(param_1 + 0x46c0));
    }
    iVar10 = 0;
    if (0 < *(int *)(param_1 + 0x46c0)) {
      iVar17 = 0;
      do {
        uVar15 = *(uint *)(*(int *)(param_1 + 0x46bc) + 200 + iVar17);
        iVar11 = *(int *)(param_1 + 0x46bc) + iVar17;
        if ((uVar15 & 0x40000) != 0) {
          iVar14 = *(int *)(iVar11 + 0x30);
          if (iVar14 != 0) {
            if ((*(int *)(iVar11 + 0x34) == -1) || ((uVar15 & 9) == 0)) {
              *(uint *)(iVar14 + 0xef0) = *(uint *)(iVar14 + 0xef0) & 0xfffffffe;
            }
            else {
              *(uint *)(iVar14 + 0xef0) = *(uint *)(iVar14 + 0xef0) | 1;
              FUN_0058b3b0(iVar11 + 0x24,*(undefined2 *)(iVar11 + 0x34));
            }
          }
          uVar15 = *(uint *)(iVar11 + 200);
          if (((uVar15 & 0x20) == 0) && ((uVar15 & 0x200) == 0)) {
            iVar14 = 0;
            if ((*(char *)(iVar11 + 0x14) == '\b') || (*(char *)(iVar11 + 0x10) == '\x0e')) {
              iVar14 = 1;
            }
            if ((*(char *)(iVar11 + 0x15) == '\b') || (*(char *)(iVar11 + 0x11) == '\x0e')) {
              iVar14 = iVar14 + 1;
            }
            if ((*(char *)(iVar11 + 0x16) == '\b') || (*(char *)(iVar11 + 0x12) == '\x0e')) {
              iVar14 = iVar14 + 1;
            }
            if ((*(char *)(iVar11 + 0x17) == '\b') || (*(char *)(iVar11 + 0x13) == '\x0e')) {
              iVar14 = iVar14 + 1;
            }
            if (iVar14 == 4) {
              puVar19 = *(undefined4 **)(iVar11 + 0x58);
              *(undefined4 *)(iVar11 + 0x18) = *(undefined4 *)(iVar11 + 0x14);
              *(undefined4 *)(iVar11 + 0xa4) = *puVar19;
              *(undefined4 *)(iVar11 + 0xa8) = puVar19[1];
              *(undefined4 *)(iVar11 + 0xac) = puVar19[2];
            }
          }
          uVar15 = (uVar15 * 2 ^ uVar15) & 2 ^ uVar15;
          *(uint *)(iVar11 + 200) = (uVar15 & 8) * 2 | uVar15 & 0xffffffea;
          *(undefined4 *)(iVar11 + 0x30) = 0;
        }
        iVar10 = iVar10 + 1;
        iVar17 = iVar17 + 0xd4;
      } while (iVar10 < *(int *)(param_1 + 0x46c0));
    }
  }
  return;
LAB_005a6262:
  local_74 = local_74 + 0xc;
  iVar10 = iVar10 + 1;
  if ((int)(*(uint *)(iVar17 + 200) >> 0xc & 7) <= iVar10) goto LAB_005a6285;
  goto LAB_005a61b5;
}

