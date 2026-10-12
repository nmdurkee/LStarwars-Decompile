/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408af0; label: FUN_00408af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x00408ec4) */
/* WARNING: Removing unreachable block (ram,0x00409067) */
/* WARNING: Removing unreachable block (ram,0x0040908c) */
/* WARNING: Removing unreachable block (ram,0x004090ad) */
/* WARNING: Removing unreachable block (ram,0x00408ed8) */
/* WARNING: Removing unreachable block (ram,0x004090d2) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00408af0(void)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  bool bVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  float *pfVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  float *_Dst;
  float *pfVar20;
  int iVar21;
  float *pfVar22;
  float10 fVar23;
  float fVar24;
  float *local_11c;
  float local_114;
  float *local_10c;
  undefined1 local_104;
  undefined4 local_100 [2];
  undefined4 local_f8;
  int local_f4;
  int local_f0;
  float local_ec [3];
  undefined1 local_e0 [4];
  undefined1 local_dc [4];
  float local_d8;
  float local_d4;
  float local_d0;
  undefined1 local_cc [12];
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  
  _Dst = (float *)&DAT_00854e38;
  local_f0 = 0;
  do {
    uVar2 = *(ushort *)((int)_Dst + 0x1ea);
    if ((uVar2 & 1) != 0) {
      if ((uVar2 & 4) == 0) {
        fVar24 = _Dst[1];
        iVar19 = 0;
        bVar10 = false;
        bVar11 = false;
        local_f4 = 0;
        if ((fVar24 != 0.0) && (*(float *)((int)fVar24 + 0x21c) < -100.0)) {
          bVar10 = true;
        }
        fVar4 = *_Dst;
        if ((((((fVar4 == 0.0) || ((*(uint *)((int)fVar4 + 0x1fc) & 0x1000) == 0)) ||
              (*(char *)((int)fVar4 + 0x28b) != '\0')) ||
             ((*(byte *)((int)fVar4 + 0xe20) & 0x20) != 0)) ||
            ((fVar24 != 0.0 && (*(char *)((int)fVar24 + 0x7b5) == '\x17')))) ||
           (((uVar2 & 2) != 0 &&
            ((**(int **)((int)fVar4 + 0xca4) != 0 &&
             ((*(uint *)(**(int **)((int)fVar4 + 0xca4) + 0x78) & DAT_00802280) != 0)))))) {
LAB_00409929:
          bVar10 = true;
        }
        else {
          *(ushort *)((int)_Dst + 0x1ea) = uVar2 | 2;
          local_c0 = *(float *)((int)fVar4 + 0x80);
          local_bc = *(float *)((int)fVar4 + 0x84);
          local_b8 = *(float *)((int)fVar4 + 0x88);
          local_10c = (float *)0x1;
          if ((fVar24 == 0.0) ||
             (((*(uint *)((int)fVar24 + 0x1fc) & 0x1000) == 0 ||
              (*(char *)((int)fVar24 + 0x28b) != '\0')))) {
            bVar10 = true;
          }
          else {
            if (*(short *)((int)fVar24 + 0x1064) == DAT_007f1914) {
              if (*(char *)(_Dst + 0x7a) == '\0') {
                iVar21 = 0;
                local_114 = 1e+09;
                do {
                  fVar23 = (float10)FUN_005b3c50(&local_c0,
                                                 (&DAT_007f1024)[iVar21] * 0x40 + 0x834 +
                                                 (int)_Dst[1],local_100);
                  if ((float)fVar23 < local_114) {
                    iVar19 = iVar21;
                    local_114 = (float)fVar23;
                  }
                  iVar21 = iVar21 + 1;
                } while (iVar21 < 4);
                *(char *)(*(byte *)(_Dst + 0x7a) + 0x1d8 + (int)_Dst) = (char)iVar19;
                *(char *)(_Dst + 0x7a) = *(char *)(_Dst + 0x7a) + '\x01';
              }
              bVar1 = *(byte *)(_Dst + 0x7a);
              fVar24 = _Dst[1];
              uVar15 = (uint)*(byte *)((int)_Dst + bVar1 + 0x1d7);
              iVar19 = (&DAT_007f1024)[uVar15] * 0x40 + 0x834 + (int)fVar24;
              if (bVar1 < 2) {
                uVar17 = uVar15 + 1 & 0x80000003;
                uVar18 = uVar15 + 3 & 0x80000003;
                iVar21 = (&DAT_007f1024)[uVar18];
                iVar5 = (&DAT_007f1024)[uVar18 + 3 & 0x80000003];
                iVar14 = FUN_00551170(&local_c0,iVar19,
                                      (&DAT_007f1024)[uVar17] * 0x40 + 0x834 + (int)fVar24,
                                      (&DAT_007f1024)[uVar15 + 2 & 0x80000003] * 0x40 + 0x834 +
                                      (int)fVar24,local_dc,local_e0);
                if (iVar14 == 0) {
                  iVar19 = FUN_00551170(&local_c0,iVar19,iVar21 * 0x40 + 0x834 + (int)fVar24,
                                        iVar5 * 0x40 + 0x834 + (int)fVar24,local_dc,local_e0);
                  if (iVar19 != 0) {
                    *(char *)(*(byte *)(_Dst + 0x7a) + 0x1d8 + (int)_Dst) = (char)uVar18;
                    *(char *)(_Dst + 0x7a) = *(char *)(_Dst + 0x7a) + '\x01';
                  }
                }
                else {
                  local_104 = (undefined1)uVar17;
                  *(undefined1 *)(*(byte *)(_Dst + 0x7a) + 0x1d8 + (int)_Dst) = local_104;
                  *(char *)(_Dst + 0x7a) = *(char *)(_Dst + 0x7a) + '\x01';
                }
              }
              else {
                uVar17 = (uint)*(byte *)((int)_Dst + bVar1 + 0x1d6);
                uVar18 = uVar15 + 1 & 0x80000003;
                if (uVar18 == uVar17) {
                  uVar18 = uVar15 + 3 & 0x80000003;
                  local_11c = (float *)0xffffffff;
                }
                else {
                  local_11c = (float *)0x1;
                }
                iVar21 = (&DAT_007f1024)[uVar18];
                iVar5 = (&DAT_007f1024)[uVar17];
                FUN_005b3800(local_100,&local_c0,iVar19);
                uVar12 = FUN_005be2d0(local_100[0],local_f8);
                FUN_005b3800(local_100,iVar21 * 0x40 + 0x834 + (int)fVar24,iVar19);
                uVar13 = FUN_005be2d0(local_100[0],local_f8);
                iVar21 = FUN_005be5b0(uVar13,uVar12);
                if ((*(byte *)(_Dst + 0x7a) < 0xf) && (0 < iVar21 * (int)local_11c)) {
                  *(char *)(*(byte *)(_Dst + 0x7a) + 0x1d8 + (int)_Dst) = (char)uVar18;
                  *(char *)(_Dst + 0x7a) = *(char *)(_Dst + 0x7a) + '\x01';
                  if (*(char *)(_Dst + 0x7a) == '\x0f') {
                    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1e8) {
                      fVar24 = _Dst[1];
                      uVar12 = 0x42700000;
                    }
                    else {
                      fVar24 = _Dst[1];
                      uVar12 = 0x41f00000;
                    }
                    FUN_00432620(fVar24,uVar12,0);
                    FUN_00681f40("AT_AT_FALL",(int)_Dst[1] + 0x80);
                    bVar10 = true;
                  }
                }
                else {
                  FUN_005b3800(local_100,iVar19,iVar5 * 0x40 + 0x834 + (int)fVar24);
                  uVar13 = FUN_005be2d0(local_100[0],local_f8);
                  iVar19 = FUN_005be5b0(uVar13,uVar12);
                  if (iVar19 * (int)local_11c < 0) {
                    *(undefined1 *)(*(byte *)(_Dst + 0x7a) + 0x1d8 + (int)_Dst) = 0xff;
                    *(char *)(_Dst + 0x7a) = *(char *)(_Dst + 0x7a) + -1;
                  }
                }
              }
            }
            else if (*(short *)((int)fVar24 + 0x1064) == DAT_007f191c) {
              *(undefined1 *)((int)fVar24 + 0x7b5) = 0x34;
              *(undefined4 *)((int)_Dst[1] + 0x77c) = 0;
            }
            if (*(byte *)(_Dst + 0x7a) == 0) {
              fVar24 = _Dst[1];
              local_b4 = *(float *)((int)fVar24 + 0x80);
              local_b0 = *(undefined4 *)((int)fVar24 + 0x84);
              local_ac = *(undefined4 *)((int)fVar24 + 0x88);
              local_10c = (float *)0x2;
            }
            else {
              iVar19 = *(byte *)(_Dst + 0x7a) - 1;
              if (-1 < iVar19) {
                fVar24 = _Dst[1];
                local_10c = (float *)0x1;
                pfVar16 = &local_b4;
                do {
                  uVar15 = (uint)*(byte *)((int)_Dst + iVar19 + 0x1d8);
                  if (*(int *)(*(int *)((int)fVar24 + 0x50) + 0x14 + uVar15 * 4) != 0) {
                    iVar21 = (&DAT_007f1024)[uVar15] * 0x40 + 0x834 + (int)fVar24;
                    *pfVar16 = *(float *)((&DAT_007f1024)[uVar15] * 0x40 + 0x834 + (int)fVar24);
                    pfVar16[1] = *(float *)(iVar21 + 4);
                    pfVar16[2] = *(float *)(iVar21 + 8);
                    local_10c = (float *)((int)local_10c + 1);
                    pfVar16 = pfVar16 + 3;
                  }
                  iVar19 = iVar19 + -1;
                } while (-1 < iVar19);
              }
            }
            if (!bVar10) {
              if ((*(uint *)(*(int *)(*(int *)((int)*_Dst + 0x54) + 0x24) + 0x90) & 0x400) == 0)
              goto LAB_00409929;
              fVar23 = (float10)FUN_005b3c50(&local_c0,&local_b4,local_100);
              fVar24 = (float)fVar23;
              iVar19 = FUN_0067b430(&local_b4,local_100,0,0x3f800000,0,DAT_0095100c | 0x1f);
              if (iVar19 == 0) {
                local_114 = 0.0;
                if (0 < DAT_0093d500) {
                  iVar19 = 0;
                  do {
                    uVar15 = *(uint *)(DAT_0093d504 + 0x1fc + iVar19);
                    fVar4 = (float)(DAT_0093d504 + iVar19);
                    if (((((((uVar15 & 1) != 0) && ((uVar15 & 0x1000) != 0)) &&
                          (*(char *)((int)fVar4 + 0x28b) == '\0')) &&
                         (((*(byte *)((int)fVar4 + 0xe20) & 0x20) == 0 && (-1 < (char)uVar15)))) &&
                        (((*(int *)(PTR_DAT_00802c54 + 300) == 0 ||
                          ((*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087afb4 ||
                           (sVar3 = *(short *)((int)fVar4 + 0x1064), sVar3 == DAT_007f1914)))) ||
                         ((sVar3 == DAT_007f191c ||
                          ((sVar3 == DAT_007f18f4 || (sVar3 == DAT_007f18f8)))))))) &&
                       ((((*(int *)((int)fVar4 + 0x1040) == 0 ||
                          ((fVar6 = *(float *)(*(int *)((int)fVar4 + 0x1040) + 4), fVar6 != _Dst[1]
                           && (fVar6 != *_Dst)))) && (fVar4 != *_Dst)) && (fVar4 != _Dst[1])))) {
                      fVar23 = (float10)FUN_005bf910(&local_c0,&local_b4,
                                                     (float *)((int)fVar4 + 0x80),&local_d8);
                      fVar6 = *(float *)((int)fVar4 + 0x1e0) + *(float *)((int)fVar4 + 0x1dc);
                      if ((((float)fVar23 < fVar6 * fVar6) &&
                          (local_d4 < *(float *)((int)fVar4 + 0x84) + *(float *)((int)fVar4 + 0x1e0)
                          )) && (*(float *)((int)fVar4 + 0x84) - *(float *)((int)fVar4 + 0x1e0) <
                                 local_d4)) {
                        local_ec[0] = *(float *)((int)fVar4 + 0x80) - local_d8;
                        local_ec[2] = *(float *)((int)fVar4 + 0x88) - local_d0;
                        if (local_ec[0] * local_ec[0] + local_ec[2] * local_ec[2] <
                            *(float *)((int)fVar4 + 0x1dc) * *(float *)((int)fVar4 + 0x1dc))
                        goto LAB_00409258;
                      }
                    }
                    local_114 = (float)((int)local_114 + 1);
                    iVar19 = iVar19 + 0x10d8;
                  } while ((int)local_114 < DAT_0093d500);
                }
                fVar4 = _Dst[1];
                if ((fVar4 != 0.0) && ((*(uint *)((int)fVar4 + 0x1fc) & 0x1000) != 0)) {
                  if (*(short *)((int)fVar4 + 0x1064) != DAT_007f1914) {
                    *(uint *)((int)fVar4 + 0xef4) = *(uint *)((int)fVar4 + 0xef4) | 0x200;
                    FUN_0052c790((int)_Dst[1] + 0x2c8,"BeingTowed");
                    *(float *)((int)_Dst[1] + 0x3ac) = *_Dst;
                    FUN_00499500(_Dst[1],(int)*_Dst + 0x80);
                    fVar4 = _Dst[1];
                    if (((*(uint *)((int)fVar4 + 0xef0) & 0x8000) != 0) &&
                       ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)((int)fVar4 + 0x7b5) * 0x10 + 8) & 1)
                        == 0)) {
                      *(short *)((int)fVar4 + 0x5a) = *(short *)((int)fVar4 + 0x5a) + -0x8000;
                    }
                    *(undefined1 *)((int)_Dst[1] + 0x407) = 1;
                    *(uint *)((int)_Dst[1] + 0xef0) = *(uint *)((int)_Dst[1] + 0xef0) | 0x8000;
                  }
                  if (_DAT_007f1054 * _DAT_007f1054 < fVar24) {
                    local_11c = (float *)0x3f800000;
                    if (_DAT_007f1050 * _DAT_007f1050 < fVar24) {
                      local_11c = (float *)(fVar24 / (_DAT_007f1050 * _DAT_007f1050));
                    }
                    FUN_005b3830(local_100,local_100,_DAT_00925018);
                    FUN_005b3830(local_ec,local_100,(float)local_11c * _DAT_007f1048);
                    FUN_005b3830(local_cc,local_100,(float)local_11c * _DAT_007f104c);
                    if ((_Dst[0x71] == 1e+09) && (*(short *)((int)_Dst[1] + 0x1064) != DAT_007f1914)
                       ) {
                      iVar19 = (int)_Dst[1] + 0x68;
                      local_ec[1] = 0.0;
                      FUN_005b37d0(iVar19,iVar19,local_ec);
                      if (_Dst[0x72] <= _DAT_007f1054) {
                        _Dst[0x75] = 0.0;
                      }
                      else {
                        _Dst[0x75] = _Dst[0x75] + _DAT_00925018;
                        *(uint *)((int)_Dst[1] + 0xef4) = *(uint *)((int)_Dst[1] + 0xef4) | 0x20;
                      }
                      if (((*(short *)((int)_Dst[1] + 0x1064) == DAT_007f18f4) ||
                          (*(short *)((int)_Dst[1] + 0x1064) == DAT_007f18f8)) && (1.0 < _Dst[0x75])
                         ) {
                        bVar11 = true;
                        bVar10 = true;
                      }
                    }
                    FUN_005b3800((int)*_Dst + 0x68,(int)*_Dst + 0x68,local_cc);
                    if (bVar10) goto LAB_00409931;
                  }
                }
                _Dst[0x72] = 0.0;
                if (_Dst[0x71] == 1e+09) {
                  iVar19 = 0;
                  *(undefined1 *)((int)_Dst + 0x1e7) = local_10c._0_1_;
                  if (0 < (int)local_10c) {
                    local_11c = _Dst + 0x62;
                    pfVar22 = &local_c0;
                    pfVar16 = _Dst + 2;
                    do {
                      fVar24 = pfVar22[1];
                      *pfVar16 = *pfVar22;
                      fVar4 = pfVar22[2];
                      pfVar16[1] = fVar24;
                      pfVar16[2] = fVar4;
                      if (iVar19 < (int)local_10c + -1) {
                        fVar23 = (float10)FUN_005becc0(pfVar22 + 3,pfVar22,local_100);
                        *local_11c = (float)fVar23;
                        _Dst[0x72] = (float)fVar23 + _Dst[0x72];
                      }
                      local_11c = local_11c + 1;
                      iVar19 = iVar19 + 1;
                      pfVar16 = pfVar16 + 3;
                      pfVar22 = pfVar22 + 3;
                    } while (iVar19 < (int)local_10c);
                  }
                }
                else {
                  local_114 = _DAT_007f1034 * _DAT_00925018;
                  _Dst[2] = local_c0;
                  local_114 = local_114 + _Dst[0x71];
                  _Dst[3] = local_bc;
                  iVar19 = 0;
                  _Dst[0x71] = local_114;
                  _Dst[4] = local_b8;
                  *(undefined1 *)((int)_Dst + 0x1e7) = 1;
                  if (0 < (int)local_10c + -1) {
                    pfVar22 = &local_b4;
                    pfVar16 = _Dst + 0x62;
                    do {
                      fVar23 = (float10)FUN_005becc0(pfVar22,pfVar22 + -3,local_100);
                      fVar24 = (float)fVar23;
                      if (fVar24 < local_114 == (fVar24 == local_114)) {
                        _Dst[iVar19 + 0x62] = local_114;
                        _Dst[0x72] = local_114 + _Dst[0x72];
                        fVar23 = (float10)FUN_004087a0(local_114,fVar24);
                        FUN_005b3830(local_100,local_100,(float)fVar23);
                        FUN_005b37d0(_Dst + (uint)*(byte *)((int)_Dst + 0x1e7) * 3 + 2,
                                     _Dst + (uint)*(byte *)((int)_Dst + 0x1e7) * 3 + -1,local_100);
                        *(char *)((int)_Dst + 0x1e7) = *(char *)((int)_Dst + 0x1e7) + '\x01';
                        break;
                      }
                      fVar4 = *pfVar22;
                      *pfVar16 = fVar24;
                      pfVar20 = _Dst + (uint)*(byte *)((int)_Dst + 0x1e7) * 3 + 2;
                      _Dst[0x72] = _Dst[0x72] + fVar24;
                      *pfVar20 = fVar4;
                      pfVar20[1] = pfVar22[1];
                      local_114 = local_114 - fVar24;
                      pfVar20[2] = pfVar22[2];
                      *(char *)((int)_Dst + 0x1e7) = *(char *)((int)_Dst + 0x1e7) + '\x01';
                      if (iVar19 == (int)local_10c + -2) {
                        _Dst[0x71] = 1e+09;
                        FUN_00681f40("TowCable_Latch",pfVar22);
                      }
                      iVar19 = iVar19 + 1;
                      pfVar16 = pfVar16 + 1;
                      pfVar22 = pfVar22 + 3;
                    } while (iVar19 < (int)local_10c + -1);
                  }
                }
                if (((*_Dst != 0.0) && (_Dst[1] != 0.0)) &&
                   (iVar19 = 0, *(char *)((int)_Dst + 0x1e7) != '\0')) {
                  do {
                    if (iVar19 == 0) {
                      fVar24 = *_Dst;
                      _Dst[0x32] = *(float *)((int)fVar24 + 0x68);
                      _Dst[0x33] = *(float *)((int)fVar24 + 0x6c);
                      _Dst[0x34] = *(float *)((int)fVar24 + 0x70);
                    }
                    else {
                      fVar24 = _Dst[1];
                      pfVar16 = _Dst + iVar19 * 3 + 0x32;
                      *pfVar16 = *(float *)((int)fVar24 + 0x68);
                      pfVar16[1] = *(float *)((int)fVar24 + 0x6c);
                      pfVar16[2] = *(float *)((int)fVar24 + 0x70);
                    }
                    iVar19 = iVar19 + 1;
                  } while (iVar19 < (int)(uint)*(byte *)((int)_Dst + 0x1e7));
                }
              }
              else {
LAB_00409258:
                bVar10 = true;
                local_f4 = 1;
              }
            }
          }
        }
LAB_00409931:
        if (bVar10) {
          FUN_00408960(local_f4);
        }
        if (bVar11) {
          FUN_00408a40();
        }
      }
      else {
        iVar19 = 0;
        _Dst[0x72] = 0.0;
        local_f4 = 1;
        if (*(char *)((int)_Dst + 0x1e7) != '\0') {
          local_10c = _Dst + 0x62;
          pfVar16 = _Dst;
          do {
            pfVar20 = pfVar16 + 3;
            pfVar22 = pfVar16 + 2;
            fVar23 = (float10)FUN_005506f0(0,pfVar22,0x40a00000,0xffffffff);
            fVar6 = _DAT_00925018;
            fVar4 = _DAT_007f105c;
            fVar24 = (float)fVar23;
            if (fVar24 == 2e+06) {
              fVar24 = *pfVar20;
            }
            fVar7 = pfVar16[0x32] - _DAT_00925018 * _DAT_007f105c * pfVar16[0x32];
            pfVar16[0x32] = fVar7;
            fVar9 = pfVar16[0x33] - _DAT_007f1058 * fVar6;
            pfVar16[0x33] = fVar9;
            fVar8 = pfVar16[0x34] - fVar6 * fVar4 * pfVar16[0x34];
            pfVar16[0x34] = fVar8;
            *pfVar22 = *pfVar22 + fVar6 * fVar7;
            fVar4 = *pfVar20 + fVar6 * fVar9;
            *pfVar20 = fVar4;
            pfVar16[4] = pfVar16[4] + fVar6 * fVar8;
            if (fVar24 <= fVar4) {
              local_f4 = 0;
            }
            else {
              *pfVar20 = fVar24;
              fVar24 = _DAT_007f1060;
              pfVar16[0x32] = fVar7 - _DAT_007f1060 * fVar7 * fVar6;
              pfVar16[0x34] = fVar8 - fVar24 * fVar8 * fVar6;
            }
            if (iVar19 < (int)(*(byte *)((int)_Dst + 0x1e7) - 1)) {
              fVar23 = (float10)FUN_005becc0(pfVar16 + 5,pfVar22,local_100);
              *local_10c = (float)fVar23;
              _Dst[0x72] = (float)fVar23 + _Dst[0x72];
            }
            local_10c = local_10c + 1;
            iVar19 = iVar19 + 1;
            pfVar16 = pfVar20;
          } while (iVar19 < (int)(uint)*(byte *)((int)_Dst + 0x1e7));
          if (local_f4 == 0) goto LAB_00409958;
        }
        fVar24 = *_Dst;
        if ((fVar24 != 0.0) && (*(float **)((int)fVar24 + 0x1040) == _Dst)) {
          *(undefined4 *)((int)fVar24 + 0x1040) = 0;
        }
        _memset(_Dst,0,0x1ec);
      }
    }
LAB_00409958:
    local_f0 = local_f0 + 1;
    _Dst = _Dst + 0x7b;
    if (7 < local_f0) {
      return;
    }
  } while( true );
}

