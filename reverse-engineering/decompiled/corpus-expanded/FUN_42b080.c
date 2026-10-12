/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42b080; label: FUN_0042b080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b080(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  
  iVar4 = 0;
  DAT_0086e4e0 = 0;
  DAT_0086e4e2 = 0;
  _DAT_008765a4 = 0;
  _DAT_008765a8 = 0;
  _DAT_008765ac = 0;
  _DAT_008765b0 = 0;
  _DAT_008765b4 = 0;
  _DAT_008765b8 = 0;
  _DAT_008765bc = 0;
  iVar2 = FUN_0059a190(&DAT_0086e0f4);
  if (iVar2 != 0) {
    FUN_00594a90((int)DAT_007f195c);
  }
  iVar2 = 0;
  if (DAT_00855f12 != 0) {
    iVar5 = 0;
    do {
      if (*(char *)(iVar5 + 9 + DAT_00855f0c) != '\0') {
        _DAT_008765ac = _DAT_008765ac + DAT_0093b2d8;
        iVar3 = FUN_00594960((int)*(short *)(iVar5 + DAT_00855f0c));
        if (iVar3 != 0) {
          FUN_0055c820(DAT_0093b2d8);
        }
      }
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 0x1c;
    } while (iVar2 < (int)(uint)DAT_00855f12);
  }
  if (0 < DAT_00951360) {
    pcVar6 = &DAT_0086e0f5;
    iVar2 = DAT_00951354;
    do {
      if (((iVar2 != DAT_00951364) && (uVar1 = *(ushort *)(iVar2 + 0x7a), (uVar1 & 0x22) == 0)) &&
         ((uVar1 & 0x2000) == 0)) {
        if ((uVar1 & 0x100) == 0) {
          if ((uVar1 & 4) == 0) {
            _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2e8;
            if ((*pcVar6 != '\0') &&
               (FUN_0055c820(DAT_0093b2e8), (*(ushort *)(iVar2 + 0x7a) & 0x800) == 0)) {
              FUN_0055c8a0();
            }
            if ((*(byte *)(iVar2 + 0x7a) & 0x10) == 0) goto LAB_0042b2c2;
            _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2f0;
            if (pcVar6[3] != '\0') {
              FUN_0055c820(DAT_0093b2f0);
              FUN_0055c8a0();
            }
            _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2f4;
            if (DAT_0093b314 == 0) {
              if (pcVar6[1] == '\0') goto LAB_0042b26c;
LAB_0042b272:
              FUN_0055c820(DAT_0093b2f4);
              FUN_0055c8a0();
            }
            else {
              if (pcVar6[1] != '\0') {
                FUN_0055c820(DAT_0093b2f4);
                FUN_0055c8a0();
              }
              _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2f4;
LAB_0042b26c:
              if (pcVar6[2] != '\0') goto LAB_0042b272;
            }
            _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2f8;
            if (pcVar6[5] != '\0') {
              FUN_0055c820(DAT_0093b2f8);
            }
            _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2ec;
            if (pcVar6[6] == '\0') goto LAB_0042b2c2;
            FUN_0055c820(DAT_0093b2ec);
            iVar5 = DAT_0093b320;
            goto LAB_0042b2bb;
          }
          _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2e4;
          if ((float)*(ushort *)(iVar2 + 0x84) <= *(float *)(pcVar6 + 7)) goto LAB_0042b2c2;
          FUN_0055c820(DAT_0093b2e4);
        }
        else {
          _DAT_008765a8 = _DAT_008765a8 + DAT_0093b2e0;
          if (*pcVar6 == '\0') goto LAB_0042b2c2;
          FUN_0055c820(DAT_0093b2e0);
          iVar5 = DAT_0093b318;
LAB_0042b2bb:
          if (iVar5 == 0) goto LAB_0042b2c2;
        }
        FUN_0055c8a0();
      }
LAB_0042b2c2:
      iVar4 = iVar4 + 1;
      pcVar6 = pcVar6 + 0xc;
      iVar2 = iVar2 + 0x9c;
    } while (iVar4 < DAT_00951360);
  }
  if ((DAT_009553d4 != 0) &&
     (iVar5 = 0, iVar2 = DAT_0093b2fc, iVar4 = DAT_009553d4, *(char *)(DAT_009553d4 + 0x1c) != '\0')
     ) {
    do {
      _DAT_008765b0 = _DAT_008765b0 + iVar2;
      if ((&DAT_0086e5ac)[iVar5] != '\0') {
        FUN_0055c820(iVar2);
        FUN_0055c8a0();
        iVar2 = DAT_0093b2fc;
        iVar4 = DAT_009553d4;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(byte *)(iVar4 + 0x1c));
  }
  iVar2 = 0;
  if (0 < DAT_00956294) {
    pcVar6 = &DAT_0086e45c;
    do {
      _DAT_008765a4 = _DAT_008765a4 + DAT_0093b2dc;
      if ((*pcVar6 != '\0') && (FUN_0055c820(DAT_0093b2dc), DAT_0093b31c != 0)) {
        FUN_0055c8a0();
      }
      iVar2 = iVar2 + 1;
      pcVar6 = pcVar6 + 0xc;
    } while (iVar2 < DAT_00956294);
  }
  uVar7 = 0;
  iVar2 = DAT_0093b300;
  do {
    _DAT_008765b4 = _DAT_008765b4 + iVar2;
    if (((&DAT_0086e4c8)[uVar7 >> 5] & 1 << ((byte)uVar7 & 0x1f)) != 0) {
      FUN_0055c820(iVar2);
      iVar2 = DAT_0093b300;
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 0x2c);
  iVar2 = 0;
  if (0 < DAT_00880150) {
    do {
      iVar5 = FUN_00576480((int)(short)(&DAT_007fcb18)[iVar2]);
      iVar4 = DAT_0093b304;
      if ((iVar5 != 0) && (*(int *)(iVar5 + 4) != 0)) {
        _DAT_008765b8 = _DAT_008765b8 + DAT_0093b304;
        uVar7 = __allshl();
        if ((uVar7 & (&DAT_0086e49c)[(int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5]) != 0) {
          FUN_0055c820(iVar4);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_00880150);
  }
  iVar4 = 0;
  iVar2 = DAT_0093b308;
  if (0 < DAT_0093b310) {
    do {
      _DAT_008765bc = _DAT_008765bc + iVar2;
      uVar7 = __allshl();
      if ((uVar7 & (&DAT_0086e4c0)[(int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5]) != 0) {
        FUN_0055c820(iVar2);
        FUN_0055c8a0();
        iVar2 = DAT_0093b308;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < DAT_0093b310);
  }
  return;
}

