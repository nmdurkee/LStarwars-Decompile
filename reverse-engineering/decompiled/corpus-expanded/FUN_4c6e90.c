/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c6e90; label: FUN_004c6e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c6e90(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_2c;
  int local_28;
  int local_24;
  int local_8;
  int local_4;
  
  iVar7 = DAT_008801ac;
  iVar6 = -1;
  bVar4 = false;
  FUN_004c1080();
  if (0.0 <= _DAT_008800e4) {
    _DAT_008800e4 = _DAT_008800e4 - _DAT_00925018;
    _DAT_0087bd78 = 0;
  }
  if (DAT_00880494 != 0) {
    _DAT_0087bd78 = 0;
  }
  _DAT_008804c8 = 0;
  FUN_005765b0();
  _DAT_0087be5c = 0x3e4ccccd;
  iVar5 = iVar6;
  iVar8 = iVar7;
  if (_DAT_008800e4 < 0.0) {
    DAT_008804c4 = 0;
    if ((local_28 == 0) || (DAT_008801ac < 1)) {
      if ((local_24 == 0) || (4 < DAT_008801ac)) {
        iVar5 = DAT_008801ac;
        if ((local_8 == 0) && (iVar5 = iVar6, local_4 != 0)) {
          bVar4 = true;
        }
      }
      else {
        iVar8 = DAT_008801ac + 1;
      }
    }
    else {
      iVar8 = DAT_008801ac + -1;
    }
  }
  if (iVar8 != iVar7) {
    DAT_008804c0 = 0;
    DAT_00880490 = DAT_008801ac;
    if (iVar8 < 0) {
      DAT_008801ac = 0;
    }
    else {
      DAT_008801ac = iVar8;
      if (5 < iVar8) {
        DAT_008801ac = 5;
      }
    }
    _DAT_008800e4 = 0.125;
    if (DAT_008804c4 == 0) {
      DAT_008804c4 = 1;
      FUN_00547930(0x2f,&DAT_0088045c,0,0);
    }
    _DAT_0087bd78 = 0;
    FUN_0054a3e0(PTR_DAT_008021b4,0x3e99999a,0,1);
  }
  if (iVar5 != -1) {
    iVar7 = DAT_008801ac;
    if (iVar5 != DAT_008801ac) {
      DAT_008801ac = iVar5;
      if (DAT_008804c4 == 0) {
        DAT_008804c4 = 1;
        FUN_00547930(0x2f,&DAT_0088045c,0,0);
      }
      _DAT_0087bd78 = 0;
      iVar7 = DAT_008801ac;
    }
    _DAT_008800e4 = 0.125;
    DAT_008801ac = -1;
    DAT_008804c0 = 1;
    DAT_00880490 = iVar7;
    FUN_00547930(0x30,0,0,0);
    FUN_0054a3e0(PTR_DAT_008021b4,0x3f19999a,0,1);
    _DAT_0087bd78 = 0;
  }
  iVar7 = DAT_008801ac;
  if (bVar4) {
    _DAT_008800e4 = 0.125;
    DAT_00880494 = 1;
    DAT_008801ac = -1;
    DAT_008804c0 = 0;
    DAT_00880490 = iVar7;
    FUN_00547930(0x31,0,0,0);
  }
  iVar6 = DAT_00880490;
  iVar7 = DAT_008801ac;
  fVar10 = (float10)0;
  fVar9 = (float10)_DAT_008800e4;
  if (fVar9 < fVar10) {
    DAT_0087c574 = 0;
LAB_004c739b:
    if (DAT_008804c0 == 0) goto LAB_004c74aa;
  }
  else {
    if ((DAT_00880490 == DAT_008801ac) && (DAT_0087c574 == 0)) goto LAB_004c739b;
    if (DAT_008804c0 == 0) {
      fVar9 = (float10)16384.0;
      iVar5 = FUN_006e6b90();
      fVar10 = (float10)0.5;
      fVar1 = (float)(fVar9 - ((float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] + fVar9) *
                              fVar10);
      iVar5 = FUN_006e6b90();
      fVar2 = (float)(extraout_ST0 -
                     ((float10)(float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] + extraout_ST0) *
                     extraout_ST1);
      if (iVar6 != -1) {
        local_2c = fVar1;
        if (1.0 <= fVar1) {
          local_2c = 1.0;
        }
        if (0.0 <= local_2c) {
          if (1.0 <= fVar1) {
            fVar1 = 1.0;
          }
        }
        else {
          fVar1 = (float)fVar10;
        }
        *(float *)(&DAT_0087c548 + iVar6 * 4) =
             ((float)(&DAT_0087fff0)[iVar6] - *(float *)(&DAT_0087ffcc + iVar6 * 4)) * fVar1 +
             *(float *)(&DAT_0087ffcc + iVar6 * 4);
        local_2c = fVar2;
        if (1.0 <= fVar2) {
          local_2c = 1.0;
        }
        if (0.0 <= local_2c) {
          if (1.0 <= fVar2) {
            fVar2 = 1.0;
          }
        }
        else {
          fVar2 = (float)fVar10;
        }
        *(float *)(&DAT_0087bf1c + iVar6 * 4) =
             (*(float *)(&DAT_0087ff78 + iVar6 * 4) - (float)(&DAT_0087c508)[iVar6]) * fVar2 +
             (float)(&DAT_0087c508)[iVar6];
      }
      if ((iVar7 != -1) && (iVar6 != -1)) {
        local_2c = fVar1;
        if (1.0 <= fVar1) {
          local_2c = 1.0;
        }
        if (0.0 <= local_2c) {
          if (1.0 <= fVar1) {
            fVar1 = 1.0;
          }
        }
        else {
          fVar1 = (float)fVar10;
        }
        *(float *)(&DAT_0087c548 + iVar7 * 4) =
             (*(float *)(&DAT_0087ffcc + iVar7 * 4) - (float)(&DAT_0087fff0)[iVar7]) * fVar1 +
             (float)(&DAT_0087fff0)[iVar7];
        local_2c = fVar2;
        if (1.0 <= fVar2) {
          local_2c = 1.0;
        }
        if (0.0 <= local_2c) {
          if (1.0 <= fVar2) {
            fVar2 = 1.0;
          }
        }
        else {
          fVar2 = (float)fVar10;
        }
        *(float *)(&DAT_0087bf1c + iVar7 * 4) =
             ((float)(&DAT_0087c508)[iVar7] - *(float *)(&DAT_0087ff78 + iVar7 * 4)) * fVar2 +
             *(float *)(&DAT_0087ff78 + iVar7 * 4);
      }
      goto LAB_004c74aa;
    }
  }
  if (fVar9 < fVar10 != (fVar9 == fVar10)) {
    _DAT_0087bbc4 = (float)fVar10;
    DAT_008801ac = DAT_00880490;
    _DAT_008800e4 = 0.125;
    DAT_008800f8 = DAT_008800f8 + 1;
    cVar3 = (&DAT_0087bffa)[DAT_00880490 * 0x74];
    (&DAT_008801c0)[DAT_008800f8] = DAT_008800a0;
    DAT_008804c0 = 0;
    DAT_0087bbbc = 1;
    if (cVar3 == '\x03') {
      _DAT_007fcbf4 = 0x41414141;
      _DAT_007fcbf8 = 0x4141;
      DAT_00880154 = DAT_00880154 + 1;
      _DAT_0087bbb4 = 0xb;
      DAT_0087c544 = 0;
      DAT_00880490 = -1;
      DAT_008800a0 = FUN_004c41a0;
      DAT_0087ffe8 = 0;
      (&DAT_0087c4e0)[DAT_00880154] = DAT_008800e0;
      DAT_008800e0 = FUN_004c4f40;
      DAT_0087bf8c = (code *)&LAB_004c5650;
    }
    else {
      DAT_00880154 = DAT_00880154 + 1;
      DAT_008800a0 = (code *)&LAB_004c39a0;
      (&DAT_0087c4e0)[DAT_00880154] = DAT_008800e0;
      DAT_008800e0 = FUN_004c64f0;
      DAT_0087bf8c = thunk_FUN_004c58e0;
    }
  }
LAB_004c74aa:
  if ((DAT_00880494 != 0) && ((float10)_DAT_008800e4 < fVar10)) {
    DAT_008800a0 = (code *)0x0;
    return 5;
  }
  return 7;
}

