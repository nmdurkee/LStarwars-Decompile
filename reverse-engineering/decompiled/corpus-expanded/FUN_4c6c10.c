/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c6c10; label: thunk_FUN_004c58e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_004c58e0(void)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  int iVar11;
  bool bVar12;
  float10 extraout_ST0;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST1;
  float fStack_30;
  float fStack_2c;
  undefined *puStack_28;
  undefined4 *puStack_24;
  undefined *puStack_20;
  undefined *puStack_1c;
  float fStack_10;
  undefined *puStack_c;
  short sStack_4;
  
  fStack_10 = 0.0;
  if (_DAT_0088048c <= 0.0) {
    _DAT_0088048c = 0.0;
  }
  else {
    fStack_10 = _DAT_0088048c / _DAT_007fcb6c;
    _DAT_0088048c = _DAT_0088048c - _DAT_00925018;
  }
  iVar7 = FUN_006e6b90();
  fVar6 = _DAT_008800a4;
  fVar1 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
  switch(DAT_008801ac) {
  case 0:
    puStack_1c = DAT_0088047c;
    puStack_24 = (undefined4 *)&DAT_008800bc;
    puStack_20 = &DAT_0087bd98;
    fVar4 = _DAT_007fcb74;
    break;
  case 1:
    puStack_1c = DAT_00880478;
    puStack_24 = (undefined4 *)&DAT_0087bdec;
    puStack_20 = &DAT_0087be60;
    fVar4 = _DAT_007fcb7c;
    break;
  case 2:
    puStack_1c = DAT_00880480;
    puStack_24 = (undefined4 *)&DAT_0087bf00;
    puStack_20 = &DAT_0087bf38;
    fVar4 = _DAT_007fcb78;
    break;
  default:
    return;
  case 4:
    puStack_1c = DAT_00880488;
    puStack_24 = (undefined4 *)&DAT_0087ff98;
    puStack_20 = &DAT_0087c488;
    fVar4 = _DAT_007fcb84;
    break;
  case 5:
    puStack_1c = &DAT_0087c578;
    puStack_24 = &DAT_0087bed4;
    puStack_20 = &DAT_0087be08;
    fVar4 = _DAT_007fcb88;
  }
  iVar7 = 0;
  fVar13 = extraout_ST0;
  fVar14 = extraout_ST1;
  do {
    if (DAT_0087bb84 == 1) {
      bVar12 = iVar7 == 6;
LAB_004c5a7c:
      if (!bVar12) goto LAB_004c5a82;
switchD_004c5ba7_caseD_3:
    }
    else {
      if (DAT_0087bb84 == 2) {
        bVar12 = iVar7 == 0;
        goto LAB_004c5a7c;
      }
LAB_004c5a82:
      puStack_28 = (undefined *)0x0;
      fVar5 = _DAT_0087bd7c;
      if ((iVar7 == 0) || (fVar5 = _DAT_0087bd94, iVar7 == 6)) {
LAB_004c5ad3:
        fStack_2c = fVar5 * _DAT_0087bbc4 * fVar4;
        fStack_30 = fVar5 * fVar6;
      }
      else {
        if (DAT_0087bb84 == 1) {
          if (iVar7 == 5) goto LAB_004c5ad3;
        }
        else if ((DAT_0087bb84 == 2) && (fVar5 = _DAT_0087bd7c, iVar7 == 1)) goto LAB_004c5ad3;
        if (iVar7 == 2) {
          fStack_2c = _DAT_0087bbc4 * _DAT_0087bed0 * fVar4;
          fStack_30 = _DAT_00880410;
        }
        else if (iVar7 == 3) {
          if (fVar14 <= fVar13) {
            puStack_28 = (undefined *)((int)ROUND(-fStack_10 * 65536.0) & 0xffff);
          }
          fStack_2c = _DAT_007fcb70 * (1.0 - (fVar1 + 1.0) * 0.5) +
                      _DAT_0087bbc4 * _DAT_008801cc * fVar4;
          fStack_30 = _DAT_00880414;
        }
        else if (iVar7 == 4) {
          fStack_2c = _DAT_0087bbc4 * _DAT_0087bb70 * fVar4;
          fStack_30 = _DAT_00880418;
        }
        else {
          fStack_2c = _DAT_0087bbc4 * fVar4;
          fStack_30 = fVar6;
        }
      }
      puVar10 = puStack_28;
      iVar11 = puStack_24[iVar7];
      switch(DAT_008801ac) {
      case 0:
        if (puStack_1c[iVar11 * 0x74 + 99] == '\x01') {
          if (fVar13 <= fVar14) {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            puStack_28 = (undefined *)
                         ((int)ROUND(fVar14 * (float10)0.25 * (float10)65536.0) & 0xffff);
          }
          else {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            fVar14 = fVar14 * (float10)0.25 * (float10)65536.0;
            if (iVar7 == 3) {
              puStack_c._0_2_ = (short)(int)ROUND(fVar14);
              puStack_28 = (undefined *)(uint)(ushort)((short)puStack_28 + (short)puStack_c);
            }
            else {
              puStack_28 = (undefined *)((int)ROUND(fVar14) & 0xffff);
            }
          }
        }
        if (puStack_1c[iVar11 * 0x74 + 99] != '\x01') {
          puStack_28 = (undefined *)0x0;
        }
        iVar11 = (int)puStack_28 + _DAT_008804a0;
        if (puStack_1c[puStack_24[iVar7] * 0x74 + 99] == '\x01') {
          FUN_004c51f0(&DAT_0087c000,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,
                       iVar11,0);
        }
        else {
          FUN_004c51f0(&DAT_0087bb88,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,
                       iVar11,0);
          FUN_004c51f0(&DAT_0087c15c,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,
                       iVar11,0);
        }
        break;
      case 1:
        fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,_DAT_007fcc80);
        uVar9 = (int)ROUND((float)(&DAT_029899a0)
                                  [(int)(((int)ROUND((fVar14 / (float10)_DAT_007fcc80) *
                                                     (float10)65536.0) & 0xffffU) + 0x4000) >> 1 &
                                   0x7fff] * 4369.0) & 0xffff;
        if (puStack_1c[iVar11 * 0x74 + 99] != '\x01') {
          uVar9 = 0;
        }
        FUN_004c5020(puStack_20 + iVar7 * 0xc,fStack_2c,fStack_30,0,_DAT_008804a0 + uVar9,0);
        break;
      case 2:
        if (puStack_1c[iVar11 * 0x74 + 99] == '\x01') {
          if (fVar13 <= fVar14) {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            puStack_28 = (undefined *)
                         ((int)ROUND(fVar14 * (float10)0.25 * (float10)65536.0) & 0xffff);
          }
          else {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            fVar14 = fVar14 * (float10)0.25 * (float10)65536.0;
            if (iVar7 == 3) {
              puStack_c._0_2_ = (short)(int)ROUND(fVar14);
              puStack_28 = (undefined *)(uint)(ushort)((short)puStack_28 + (short)puStack_c);
            }
            else {
              puStack_28 = (undefined *)((int)ROUND(fVar14) & 0xffff);
            }
          }
          if (puStack_1c[iVar11 * 0x74 + 99] != '\x01') {
            puStack_28 = (undefined *)0x0;
          }
          iVar11 = (int)puStack_28 + _DAT_008804a0;
          FUN_004c51f0(&DAT_008800e8,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,
                       iVar11,0);
          FUN_004c5300(fStack_2c,0x3f800000,1,fStack_30,0,iVar11,0);
        }
        else {
          if (puStack_1c[iVar11 * 0x74 + 99] != '\x01') {
            puStack_28 = (undefined *)0x0;
          }
          iVar11 = (int)puStack_28 + _DAT_008804a0;
          FUN_004c51f0(&DAT_008800e8,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,
                       iVar11,0);
          uVar9 = (uint)*(ushort *)(puStack_1c + puStack_24[iVar7] * 0x74 + 0x60);
          if (((((&DAT_0086e4c8)[(int)uVar9 >> 5] &
                1 << ((byte)*(ushort *)(puStack_1c + puStack_24[iVar7] * 0x74 + 0x60) & 0x1f)) == 0)
              && (7 < uVar9)) &&
             (((&DAT_007f3da3)[uVar9 * 0x20] != -1 &&
              ((&DAT_0086e0fa)[(char)(&DAT_007f3da3)[uVar9 * 0x20] * 0xc] == '\0')))) {
            iVar8 = FUN_005cfac0(&DAT_0087c268 + puStack_24[iVar7] * 0xc);
            if (iVar8 != 0) {
              FUN_004c51f0(&DAT_0087c268 + puStack_24[iVar7] * 0xc,puStack_20 + iVar7 * 0xc,
                           fStack_2c,0x3f800000,fStack_30,0,iVar11,0);
            }
          }
          else {
            FUN_004c5300(fStack_2c,0x3f800000,1,fStack_30,0,iVar11,0);
          }
        }
        break;
      default:
        goto switchD_004c5ba7_caseD_3;
      case 4:
        if (puStack_1c[iVar11 * 0x74 + 99] == '\x01') {
          if (fVar13 <= fVar14) {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            puStack_28._0_2_ = (short)(int)ROUND(fVar14 * (float10)0.25 * (float10)65536.0);
          }
          else {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            fVar14 = fVar14 * (float10)0.25 * (float10)65536.0;
            if (iVar7 == 3) {
              puStack_c._0_2_ = (short)(int)ROUND(fVar14);
              puStack_28._0_2_ = (short)puStack_28 + (short)puStack_c;
            }
            else {
              puStack_28._0_2_ = (short)(int)ROUND(fVar14);
            }
          }
          iVar8 = DAT_007fcc7c * 0x10000;
          puStack_28 = (undefined *)
                       (uint)(ushort)((short)puStack_28 +
                                     ((short)((ulonglong)((longlong)iVar8 * 0xb60b60b7) >> 0x28) -
                                     ((short)(char)((char)(iVar8 / 0x1680000) +
                                                   (char)(iVar8 >> 0x1f)) >> 0xf)) +
                                     *(short *)(puStack_1c + puStack_24[iVar7] * 0x74 + 0x60) *
                                     0x1249);
        }
        if (puStack_1c[iVar11 * 0x74 + 99] != '\x01') {
          puStack_28 = (undefined *)0x0;
        }
        FUN_004c53d0(puStack_20 + iVar7 * 0xc,fStack_2c,fStack_30,0,_DAT_008804a0 + (int)puStack_28,
                     0);
        break;
      case 5:
        uVar3 = *(ushort *)(puStack_1c + iVar11 * 0x74 + 0x60);
        if ((DAT_0088049c == (int *)0x0) || (iVar8 = FUN_0057e720((uint)uVar3), iVar8 == 0)) {
          puStack_28 = &DAT_0087bef0;
          puStack_c = &DAT_0087c4fc;
        }
        else {
          iVar8 = *(short *)(*DAT_0088049c + (uint)uVar3 * 0x44) * 0x130 + DAT_00951b78;
          uVar9 = (uint)*(char *)(iVar8 + 0xa3);
          bVar2 = *(byte *)(iVar8 + 0xa2);
          if (bVar2 == 0xff) {
            if (((uVar9 == 0xffffffff) || (DAT_0087b020 == 0)) ||
               (uVar9 != *(byte *)(DAT_0087b020 + 0x7c))) goto LAB_004c62ba;
            puStack_28 = &DAT_0087c520;
          }
          else if ((bVar2 & 1) == 0) {
LAB_004c62ba:
            puStack_28 = &DAT_008800e8;
          }
          else {
            puStack_28 = &DAT_0087c520;
          }
          puStack_c = &DAT_0087c250;
          fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
          sStack_4 = (short)(int)ROUND(fVar14 * (float10)0.25 * (float10)-65536.0);
          puVar10 = (undefined *)(uint)(ushort)(uVar3 * 0x1555 - sStack_4);
        }
        if (puStack_1c[iVar11 * 0x74 + 99] != '\x01') {
          puVar10 = (undefined *)0x0;
        }
        iVar11 = (int)puVar10 + _DAT_008804a0;
        FUN_004c51f0(puStack_28,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,iVar11,0);
        FUN_004c51f0(puStack_c,puStack_20 + iVar7 * 0xc,fStack_2c,0x3f800000,fStack_30,0,iVar11,0);
      }
    }
    iVar7 = iVar7 + 1;
    if (6 < iVar7) {
      return;
    }
    fVar14 = (float10)0;
    fVar13 = (float10)_DAT_0088048c;
  } while( true );
}

