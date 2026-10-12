/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74e0e0; label: FUN_0074e0e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0074e0e0(int param_1)

{
  short *psVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  
  FUN_005d8400(0,3,&DAT_007ea410);
  if (DAT_00854698 == 123456.0) {
    puVar15 = &DAT_009736e8;
    puVar16 = &DAT_00854698;
    for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
      *puVar16 = *puVar15;
      puVar15 = puVar15 + 1;
      puVar16 = puVar16 + 1;
    }
  }
  if (DAT_00854694 == 0) goto LAB_0074e90b;
  if (DAT_00854690 == -1) {
    if (_DAT_0297dba0 == 0.0) goto LAB_0074e90b;
    _DAT_02983a38 = 0;
    DAT_00854690 = FUN_006550b0();
    if (DAT_00854690 == -1) goto LAB_0074e90b;
    uVar8 = FUN_00658470("DAVE_RAIN",0);
    *(undefined2 *)(DAT_00854690 * 0x330 + 0x182 + DAT_029620a4) = uVar8;
    *(undefined1 *)(DAT_00854690 * 0x330 + 0x2f6 + DAT_029620a4) = 0;
    iVar11 = DAT_00854690 * 0x330 + DAT_029620a4;
    if (*(short *)(iVar11 + 0x182) != -1) {
      FUN_00683e90(iVar11,0x280);
      *(undefined2 *)(DAT_00854690 * 0x330 + 0x18a + DAT_029620a4) = 0;
      FUN_00600260(*(undefined4 *)
                    (DAT_0296209c + *(short *)(DAT_00854690 * 0x330 + 0x182 + DAT_029620a4) * 4));
    }
    if (DAT_00854690 == -1) goto LAB_0074e90b;
  }
  if ((_DAT_0297dba0 == 0.0) &&
     (FUN_00683e90(DAT_00854690 * 0x330 + DAT_029620a4,0),
     *(short *)(DAT_00854690 * 0x330 + 0x180 + DAT_029620a4) == 0)) {
    DAT_00854690 = -1;
  }
  else if ((DAT_00854690 != -1) && (_DAT_0297dba0 != 0.0)) {
    iVar11 = DAT_00854690 * 0x330 + DAT_029620a4;
    if (*(short *)(DAT_00854690 * 0x330 + 0x18c + DAT_029620a4) < *(short *)(iVar11 + 0x180)) {
      FUN_00683560(iVar11);
    }
    if (((1.0 < ABS(DAT_00973718 - _DAT_008546c8)) || (1.0 < ABS(DAT_0097371c - _DAT_008546cc))) ||
       (1.0 < ABS(DAT_00973720 - _DAT_008546d0))) {
      fVar2 = (DAT_00973718 + DAT_00973708 * 3.5) - _DAT_008546c8;
      fVar3 = _DAT_008546b8 * 3.5;
      uVar12 = 0;
      fVar7 = (DAT_0097370c * 3.5 + DAT_0097371c) - _DAT_008546cc;
      fVar4 = _DAT_008546bc * 3.5;
      fVar6 = (DAT_00973710 * 3.5 + DAT_00973720) - _DAT_008546d0;
      fVar5 = _DAT_008546c0 * 3.5;
      _DAT_008546c8 = DAT_00973718;
      _DAT_008546cc = DAT_0097371c;
      _DAT_008546d0 = DAT_00973720;
      if (0 < (int)*(short *)(DAT_00854690 * 0x330 + 0x180 + DAT_029620a4) << 5) {
        do {
          uVar13 = uVar12 & 0x8000001f;
          if ((int)uVar13 < 0) {
            uVar13 = (uVar13 - 1 | 0xffffffe0) + 1;
          }
          pfVar14 = (float *)((uVar13 + 1) * 0x20 +
                             *(int *)(DAT_029620a4 + 0x100 +
                                     (DAT_00854690 * 0xcc +
                                     ((int)(uVar12 + ((int)uVar12 >> 0x1f & 0x1fU)) >> 5)) * 4));
          uVar12 = uVar12 + 1;
          *pfVar14 = *pfVar14 + (fVar2 - fVar3);
          pfVar14[1] = pfVar14[1] + (fVar7 - fVar4);
          pfVar14[2] = (fVar6 - fVar5) + pfVar14[2];
          _DAT_008546c8 = DAT_00973718;
          _DAT_008546cc = DAT_0097371c;
          _DAT_008546d0 = DAT_00973720;
        } while ((int)uVar12 < *(short *)(DAT_00854690 * 0x330 + 0x180 + DAT_029620a4) * 0x20);
      }
    }
    if ((0 < *(short *)(DAT_00854690 * 0x330 + 0x180 + DAT_029620a4)) && (param_1 == 0)) {
      if (0.25 <= _DAT_0297dba0) {
        iVar11 = 0x10;
      }
      else {
        iVar11 = FUN_006e6b90();
        if (iVar11 == 0) {
          iVar11 = 1;
        }
      }
      _DAT_02983a3c = _DAT_02983a3c + 0x2db;
      _DAT_02983a28 = _DAT_02983a28 + 0x377;
      iVar9 = FUN_005be2d0(_DAT_009736fc,DAT_0097370c);
      DAT_02983a34 = 0x4000 - iVar9;
      iVar9 = FUN_005be2d0(-DAT_00973708,-DAT_00973710);
      DAT_02983a2c = iVar9 + -0x8000;
      DAT_02983a30 = (int)(DAT_02983a34 * 0xf + (DAT_02983a34 * 0xf >> 0x1f & 7U)) >> 3;
      if (DAT_02983a30 < 0x4001) {
        if (DAT_02983a30 < -0x4000) {
          DAT_02983a30 = -0x4000;
        }
      }
      else {
        DAT_02983a30 = 0x4000;
      }
      if (0 < iVar11) {
        do {
          iVar9 = DAT_00854690 * 0x330 + DAT_029620a4;
          if (*(short *)(iVar9 + 0x180) * 0x20 <=
              (int)*(short *)(DAT_00854690 * 0x330 + 0x18a + DAT_029620a4)) {
            *(undefined2 *)(iVar9 + 0x18a) = 0;
          }
          uVar12 = (uint)*(short *)(DAT_00854690 * 0x330 + 0x18a + DAT_029620a4);
          uVar13 = uVar12 & 0x8000001f;
          if ((int)uVar13 < 0) {
            uVar13 = (uVar13 - 1 | 0xffffffe0) + 1;
          }
          pfVar14 = (float *)((uVar13 + 1) * 0x20 +
                             *(int *)(DAT_029620a4 + 0x100 +
                                     (((int)(uVar12 + ((int)uVar12 >> 0x1f & 0x1fU)) >> 5) +
                                     DAT_00854690 * 0xcc) * 4));
          pfVar14[3] = _DAT_008108e4 + _DAT_0296205c;
          pfVar14[7] = 106.666664;
          fVar2 = (float)(&DAT_029899a0)[DAT_02983a30 + 0x4000 >> 1 & 0x7fff];
          FUN_005b9e50();
          iVar9 = FUN_006e6b90();
          iVar10 = FUN_005b9e50();
          fVar2 = ((float)iVar10 / ((1.0 - fVar2) * 3.0 + 1.0)) * 3.0517578e-05;
          fVar2 = ((float)(&DAT_029899a0)[DAT_02983a30 + 0x4000 >> 1 & 0x7fff] * 0.25 + 0.75) *
                  (fVar2 * 8.0 + fVar2 * fVar2);
          fVar3 = fVar2 * 0.25 + 1.0 + (float)(&DAT_029899a0)[DAT_02983a30 >> 1 & 0x7fff];
          iVar10 = FUN_005b9e50();
          pfVar14[4] = ((float)(&DAT_029899a0)[DAT_02983a34 + 0x4000 >> 1 & 0x7fff] * 3.0 +
                       (float)iVar10 / 131070.0) - 0.25;
          pfVar14[5] = -15.0;
          iVar10 = FUN_005b9e50();
          pfVar14[6] = ((float)(&DAT_029899a0)[DAT_02983a34 + 0x4000 >> 1 & 0x7fff] * 3.0 +
                       (float)iVar10 / 131070.0) - 0.25;
          *pfVar14 = ((DAT_00973718 +
                      fVar2 * (float)(&DAT_029899a0)[DAT_02983a2c + iVar9 >> 1 & 0x7fff]) -
                     ((float)(&DAT_029899a0)[DAT_02983a30 + 0x4000 >> 1 & 0x7fff] * 0.75 + 0.25) *
                     (float)(&DAT_029899a0)[DAT_02983a2c >> 1 & 0x7fff] * 2.0) +
                     (fVar3 * pfVar14[4]) / pfVar14[5];
          pfVar14[1] = DAT_0097371c + fVar3;
          pfVar14[2] = (fVar3 * pfVar14[6]) / pfVar14[5] +
                       ((DAT_00973720 +
                        (float)(&DAT_029899a0)[DAT_02983a2c + 0x4000 + iVar9 >> 1 & 0x7fff] * fVar2)
                       - (float)(&DAT_029899a0)[DAT_02983a2c + 0x4000 >> 1 & 0x7fff] * 2.0 *
                         ((float)(&DAT_029899a0)[DAT_02983a30 + 0x4000 >> 1 & 0x7fff] * 0.75 + 0.25)
                       );
          pfVar14[4] = pfVar14[4] + (DAT_00973718 - _DAT_008546c8) * 60.0;
          pfVar14[5] = (DAT_0097371c - _DAT_008546cc) * 60.0 + pfVar14[5];
          pfVar14[6] = (DAT_00973720 - _DAT_008546d0) * 60.0 + pfVar14[6];
          psVar1 = (short *)(DAT_00854690 * 0x330 + 0x18a + DAT_029620a4);
          *psVar1 = *psVar1 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
LAB_0074e90b:
  puVar15 = &DAT_009736e8;
  puVar16 = &DAT_00854698;
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar16 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar16 = puVar16 + 1;
  }
  FUN_005d8440(0,3);
  return;
}

