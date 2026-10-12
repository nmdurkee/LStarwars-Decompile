/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x48b540; label: FUN_0048b540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048b540(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 fVar15;
  float fVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  float fStack_3c;
  float local_38;
  float fStack_34;
  int local_30;
  int local_2c;
  float fStack_28;
  float fStack_24;
  float local_20;
  int local_1c;
  float fStack_18;
  int local_14;
  float local_10;
  undefined4 local_c;
  uint uStack_4;
  
  local_2c = 2;
  local_1c = 0;
  local_14 = 0;
  if ((DAT_00803784 == 0xffffffff) || (DAT_00803784 != DAT_0095121c)) {
    FUN_00573ca0(DAT_00803784,DAT_00951ba0,&PTR_DAT_007f17d8,&DAT_007f1808);
  }
  local_c = FUN_006d61a0();
  if ((DAT_00803784 == 0xffffffff) ||
     ((*(byte *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) & 1) == 0)) {
    DAT_00951288 = 0;
  }
  else {
    DAT_00951288 = 1;
  }
  if ((DAT_00803784 == 0xffffffff) ||
     ((*(byte *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) & 4) == 0)) {
    DAT_00951154 = 0;
  }
  else {
    DAT_00951154 = 1;
  }
  if ((DAT_00951288 == 0) || (_DAT_00951228 = 1, DAT_00951154 != 0)) {
    _DAT_00951228 = 0;
  }
  DAT_007fa5f0 = 0;
  DAT_0087b2e0 = 0;
  DAT_0087b2dc = 0;
  DAT_0087aa30 = 0;
  FUN_00548fb0(&DAT_0092505c,0);
  if (((((DAT_00803784 == 0xffffffff) || (DAT_00803784 == DAT_0095121c)) ||
       ((*(byte *)(DAT_00951354 + 0x7a + DAT_00803784 * 0x9c) & 2) != 0)) || (DAT_0087b71c != 0)) ||
     ((((DAT_00951364 == 0 || (DAT_0095121c != *(byte *)(DAT_00951364 + 0x7c))) &&
       (DAT_00951b60 == 0)) &&
      ((DAT_0093b338 == 0 || ((DAT_00951b7c != DAT_00951b88 && (DAT_00951b7c != DAT_00951b98))))))))
  {
    if ((DAT_0093b2a8 == 0) || ((*(byte *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) & 2) == 0)) {
      if ((((DAT_0095121c == 0xffffffff) || (DAT_00951b7c == 0)) ||
          ((*(uint *)(DAT_00951b7c + 100) & 0x400) == 0)) ||
         (((*(short *)(DAT_00803784 * 0x9c + 0x7a + DAT_00951354) == 2 || (DAT_00951364 == 0)) ||
          (DAT_00803784 == *(byte *)(DAT_00951364 + 0x7c))))) {
        local_2c = 0;
      }
      else {
        local_2c = 2;
      }
    }
    else {
      local_2c = 1;
    }
    if ((DAT_00803784 != 0xffffffff) && (DAT_00803784 == DAT_0095121c)) {
      local_1c = 1;
    }
  }
  DAT_00951b60 = 0;
  if (((local_1c != 0) || (DAT_0087b51c != 0)) || (DAT_007fac04 == 0)) {
    FUN_0048afe0(0);
    _DAT_00950678 = 0x3f800000;
    return;
  }
  _DAT_0087b2e4 = 1;
  puVar10 = &DAT_00806680;
  puVar11 = DAT_00925164;
  for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  FUN_00603cc0(DAT_00925164);
  _DAT_0087a99c = 0.0;
  if (local_2c == 2) {
    _DAT_0087a940 = 1.0;
  }
  else {
    _DAT_0087a940 = 0.1;
  }
  _DAT_0087aa90 = _DAT_0087a940;
  local_1c = 0;
  _DAT_00925018 = _DAT_0092501c;
  _DAT_00950760 = 0x3f800000;
  local_20 = 0.0;
  fVar12 = (float10)FUN_00547ab0(&DAT_008668cc);
  local_10 = (float)fVar12;
  if (DAT_0087b2c0 == 0) {
    FUN_00564780();
  }
  FUN_0054c030(&PTR_DAT_007fd2b4,DAT_00803784,1);
  if ((DAT_00951364 == 0) || (*(byte *)(DAT_00951364 + 0x7c) != DAT_00803784)) {
    local_30 = 2;
  }
  else {
    local_30 = 0;
  }
  local_38 = 0.0;
  DAT_0087b2e0 = 1;
  FUN_0055f470(DAT_00803784,DAT_0095121c);
  FUN_00548f10(1);
  if (((local_2c == 2) && (DAT_007fa5fc != 0)) &&
     ((DAT_008668d2 != '\0' && ((DAT_02962034 == 0 && (DAT_02962038 == 0)))))) {
    if ((DAT_0093b324 == 0) &&
       ((DAT_00803784 != 0xffffffff &&
        (cVar1 = *(char *)(DAT_00803784 * 0x9c + 0x86 + DAT_00951354), cVar1 != -1)))) {
      uVar2 = FUN_00694320(1,(&PTR_s_Ep1_TextCrawl_0075a24f_1_007faa80)[cVar1]);
      FUN_00694240(1,uVar2);
      iVar9 = FUN_00694320(1,0);
      if (iVar9 != -1) {
        FUN_00696a30(1);
      }
    }
    else {
      FUN_00548ae0(DAT_00951b88,0,&DAT_008668cc);
    }
    FUN_00698e70();
  }
  FUN_004fecf0(FUN_0048afe0,0,0,0);
  iVar9 = 0;
  do {
    if ((DAT_007fa5f0 != 0) && (_DAT_0087aa90 <= 0.0)) {
      _DAT_00950678 = 0x3f800000;
      _DAT_00950760 = 0;
      FUN_00693fd0(0);
      FUN_00548e90();
      FUN_00652ad0();
      FUN_00547a30(local_10);
      _DAT_0087b2e4 = 0;
      if (DAT_0087b2e0 != 0) {
        DAT_0087b2e0 = 0;
        DAT_0087b2dc = 1;
      }
      FUN_006d6170(local_c);
      return;
    }
    FUN_006d6170(0);
    FUN_006dd390();
    FUN_006d3420();
    FUN_004f3e20();
    FUN_00603cc0(&DAT_009736e8);
    DAT_00926bd0 = 1;
    FUN_0054b090();
    fStack_24 = 0.0;
    if (local_2c == 2) {
      if (((((DAT_007fa5f0 != 0) && (_DAT_0087a940 == _DAT_0087aa90)) &&
           (_DAT_0087a99c < _DAT_007fa5f8)) && (iVar9 == 0)) &&
         ((iVar3 = FUN_00698990(), iVar3 == 0 || (_DAT_007fa5f4 <= _DAT_0087a99c)))) {
        if (((DAT_009253b8 & DAT_00802274) == 0) &&
           (((DAT_00925418 & DAT_00802274) == 0 && (iVar3 = FUN_006d6c40(1), iVar3 == 0)))) {
          fStack_24 = 1.4013e-45;
        }
        else {
          iVar9 = 1;
          local_1c = 1;
        }
        local_20 = _DAT_00925018 + local_20;
      }
    }
    else if (DAT_007fa5f0 != 0) {
      iVar9 = 1;
      local_1c = 1;
    }
    FUN_00548fe0(&DAT_00925028);
    _DAT_0086e4e8 = _DAT_00925018 + _DAT_0086e4e8;
    _DAT_0087a99c = _DAT_00925018 + _DAT_0087a99c;
    if (local_30 == 0) {
      if ((DAT_0087aa30 == 2) ||
         (((DAT_0087aa30 != 0 && (iVar3 = FUN_0062df80(DAT_00802bd8), iVar3 != 0)) &&
          (iVar3 = FUN_0062df80(DAT_00802bdc), iVar3 != 0)))) {
        local_30 = 1;
      }
    }
    else if (local_30 == 1) {
      local_38 = _DAT_00925018 + local_38;
      if ((local_38 <= 0.6) || (DAT_0087aa30 == 2)) {
        if (3.9499998 <= local_38) {
          local_38 = 3.9499998;
          local_30 = 2;
        }
      }
      else {
        local_38 = 0.6;
      }
    }
    if (local_2c == 2) {
      if ((DAT_007fa5f0 != 0) &&
         (((fVar16 = _DAT_0087aa90, _DAT_0087aa90 <= 0.0 ||
           ((_DAT_007fa5f8 < _DAT_0087a99c == (_DAT_007fa5f8 == _DAT_0087a99c) && (iVar9 == 0)))) ||
          (fVar16 = _DAT_0087aa90 - _DAT_00925018, _DAT_0087aa90 = 0.0, 0.0 <= fVar16)))) {
        _DAT_0087aa90 = fVar16;
      }
      fStack_18 = (_DAT_0087aa90 / _DAT_0087a940) * local_10;
      FUN_00547a30(fStack_18);
      if (DAT_007fa5f0 == 0) {
        fStack_18 = 1.0;
      }
      else {
        fStack_18 = _DAT_0087aa90 / _DAT_0087a940;
      }
      fStack_18 = fStack_18 * _DAT_00925018;
      FUN_00564ac0(fStack_18);
      FUN_005647e0(1);
    }
    else if (((DAT_007fa5f0 != 0) && (local_30 == 2)) &&
            ((fVar16 = _DAT_0087aa90, _DAT_0087aa90 <= 0.0 ||
             (fVar16 = _DAT_0087aa90 - _DAT_00925018, _DAT_0087aa90 = 0.0, 0.0 <= fVar16)))) {
      _DAT_0087aa90 = fVar16;
    }
    if (DAT_02962034 == 0) {
      FUN_00698e70();
      FUN_00695950(_DAT_00925018);
    }
    FUN_00695950(_DAT_00925018);
    FUN_005d4290(1);
    if (local_2c == 2) {
      uVar4 = FUN_006e6b90();
      uVar5 = FUN_006e6b90();
      uVar6 = FUN_006e6b90();
      uVar7 = FUN_006e6b90();
      uStack_4 = FUN_006e6b90();
      uVar8 = FUN_006e6b90();
      FUN_005feab0(0xf00,((uVar6 & 0xff | 0xffff8000) << 8 | uVar5 & 0xff) << 8 | uVar4 & 0xff,
                   ((uVar8 & 0xff | 0xffff8000) << 8 | uStack_4 & 0xff) << 8 | uVar7 & 0xff,
                   0x3f800000);
      if ((DAT_0087b2c0 != 0) || (0.5 <= _DAT_0087a99c)) {
        fStack_18 = 1.0;
      }
      else {
        fStack_18 = _DAT_0087a99c + _DAT_0087a99c;
      }
      FUN_00564af0(fStack_18,1);
      if (DAT_007fa5f0 == 0) {
        fStack_3c = 1.0;
LAB_0048c0eb:
        FUN_0054c0c0(_DAT_00925018,0,fStack_3c,0);
        FUN_0050e6a0();
      }
      else if ((0.1 <= _DAT_0087aa90) &&
              (fStack_3c = (_DAT_0087aa90 - 0.1) / (_DAT_0087a940 - 0.1), 0.0 < fStack_3c))
      goto LAB_0048c0eb;
      if (fStack_24 != 0.0) {
        fVar12 = (float10)FUN_005b7d30(local_20,0x3f800000);
        fStack_18 = (float)(int)ROUND(fVar12 * (float10)65536.0);
        uVar2 = FUN_006e6b90();
        FUN_0050e6a0();
        FUN_0050c780(*(undefined4 *)(DAT_00926c20 + DAT_00880c68 * 4),0,_DAT_007fa600,0x3f800000,
                     _DAT_007fa604,_DAT_007fa604,_DAT_007fa604,0,0xff,0xff,0xff,uVar2);
      }
LAB_0048bf03:
      if (local_14 != 0) goto LAB_0048bf0a;
    }
    else {
      FUN_005feab0(0xf00,0x80000000,0x80000000,0x3f800000);
      if (local_2c == 1) {
        FUN_00564af0(0x3f800000,1);
      }
      if (_DAT_0087a940 != _DAT_0087aa90) goto LAB_0048bf03;
      FUN_005b7d30(_DAT_0087a99c,0x3f800000);
      iVar9 = FUN_006e6b90();
      fStack_18 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff] * 0.15;
      if ((DAT_00951364 != 0) && (DAT_00803784 == *(byte *)(DAT_00951364 + 0x7c))) {
        if ((DAT_0087aa30 != 0) && ((0.0 < local_38 && (local_38 < 3.9499998)))) {
          fStack_34 = 0.1425;
          fStack_28 = 0.4;
          if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
            fStack_34 = 0.106875;
            fStack_28 = 0.35;
          }
          iVar9 = 0;
          do {
            fVar15 = (float10)0;
            fVar12 = (float10)fStack_18;
            fVar13 = (float10)fStack_28;
            if (iVar9 == 0) {
              if (local_38 < 3.6999998) {
                fVar14 = (float10)local_38;
LAB_0048bdb0:
                if ((float10)0.6 <= fVar14) {
                  fStack_24 = fStack_34;
                  if ((float10)3.1 <= fVar14) {
                    fVar14 = (float10)1 -
                             (fVar14 - (float10)3.0999999046325684) / (float10)0.5999999046325684;
                  }
                  else {
                    fVar14 = (float10)1;
                  }
                  fVar14 = (float10)(float)fVar14;
                }
                else {
                  fStack_24 = (float)((float10)0.30000001192092896 + (float10)fStack_34);
                  fVar14 = (float10)fStack_34;
                  fVar15 = fVar13;
                  iVar3 = FUN_006e6b90();
                  fVar13 = fVar12;
                  fVar12 = fVar14;
                  fStack_24 = (float)((float10)fStack_24 +
                                     (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] *
                                     (extraout_ST1 - (float10)fStack_24));
                  fVar14 = extraout_ST0;
                }
                DAT_0093b28c = 1;
                if (iVar9 == 0) {
                  fVar12 = fVar12 + (float10)0.8500000238418579;
                  uVar18 = 0xa6;
                  uVar17 = 0x3e2a3d70;
                  uVar2 = DAT_00802bd8;
                  fVar16 = -fStack_24;
                }
                else {
                  fVar12 = (float10)0.8500000238418579 - fVar12;
                  uVar18 = 0xa5;
                  uVar17 = 0xbe2a3d70;
                  uVar2 = DAT_00802bdc;
                  fVar16 = fStack_24;
                }
                fStack_3c = (float)(fVar12 * fVar14);
                FUN_0055b830(uVar2,fVar16,uVar17,(float)fVar15,(float)fVar13,uVar18,(float)fVar14,
                             fStack_3c,1,0);
              }
            }
            else {
              fVar14 = (float10)(local_38 - 0.25);
              if (fVar14 < fVar15 == (fVar14 == fVar15)) goto LAB_0048bdb0;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 2);
        }
        goto LAB_0048bf03;
      }
      local_14 = 1;
LAB_0048bf0a:
      FUN_005f3950();
      FUN_005b10a0();
      FUN_005b1180();
      FUN_005d4290(1);
    }
    (**(code **)(*DAT_0095e418 + 0x28))(0);
    FUN_005f3950();
    if (((DAT_007fa5f0 != 0) && (_DAT_0087aa90 < 0.1)) &&
       ((DAT_009507a0 == -1 || (DAT_009507a0 == 3)))) {
      fStack_28 = 2.8026e-45;
      FUN_005b1220(&fStack_28,0);
      FUN_00565be0(1);
      FUN_00565ba0();
    }
    FUN_0065f4d0();
    fVar12 = (float10)FUN_004fd050();
    _DAT_00925018 = (float)fVar12;
    FUN_0065f4e0();
    iVar9 = local_1c;
  } while( true );
}

