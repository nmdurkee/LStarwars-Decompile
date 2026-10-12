/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x47cdd0; label: FUN_0047cdd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047cdd0(int param_1)

{
  int *piVar1;
  uint *puVar2;
  char cVar3;
  short sVar4;
  bool bVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  short *psVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  float10 fVar17;
  float local_c;
  int local_4;
  
  iVar7 = FUN_00574e20();
  if (DAT_00879b78 == 0) {
    FUN_00474d80();
    DAT_00879b78 = DAT_00879b78 + 1;
  }
  iVar8 = FUN_0050b310();
  if (iVar8 == 0) {
    if (((iVar7 == 0xc) || (iVar7 == 0xd)) || (iVar7 == 0xe)) {
      _DAT_00879b30 = 1.0;
    }
  }
  else {
    _DAT_0087b928 = 0;
    _DAT_0087b970 = 0;
    _DAT_0087b9a0 = 0;
    _DAT_00879b30 = 1.0;
  }
  FUN_005b7d30(_DAT_00925030,0x3f000000);
  _DAT_007f9328 = FUN_006e6b90();
  if (iVar7 == 8) {
    _DAT_00879550 = 1.0;
  }
  else if ((0.0 < _DAT_00879550) &&
          (_DAT_00879550 = _DAT_00879550 - _DAT_00925018 * 0.333, _DAT_00879550 < 0.0)) {
    _DAT_00879550 = 0.0;
  }
  fVar17 = (float10)FUN_0054fad0(_DAT_00879b24,_DAT_00879b28,_DAT_00925018 * 20.0);
  _DAT_00879b24 = (float)fVar17;
  if (_DAT_00879b28 == _DAT_00879b24) {
    iVar7 = FUN_0054fa60();
    _DAT_00879b28 = ((float)iVar7 * 1.5259022e-05 + (float)iVar7 * 1.5259022e-05) - 1.0;
  }
  if (0.0 < _DAT_00879b30) {
    _DAT_00879b30 = _DAT_00879b30 - _DAT_00925018;
  }
  FUN_00419fb0();
  bVar5 = false;
  iVar7 = -1;
  if (DAT_00880474 == 0) {
    iVar8 = FUN_00574e20();
    if (iVar8 != 0xc) {
      if (((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
         ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
          ((((cVar3 = *(char *)(DAT_0093d7f0 + 0x7b5), cVar3 == -1 || (cVar3 == '1')) ||
            (cVar3 == '2')) && (*(char *)(DAT_0093d7f0 + 0x285) == '\x0e')))))) {
        bVar5 = true;
      }
      if (((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
         ((*(char *)(DAT_0093d7f4 + 0x281) != '\0' &&
          ((((cVar3 = *(char *)(DAT_0093d7f4 + 0x7b5), cVar3 == -1 || (cVar3 == '1')) ||
            (cVar3 == '2')) && (*(char *)(DAT_0093d7f4 + 0x285) == '\x0e')))))) {
        bVar5 = true;
      }
    }
  }
  else {
    _DAT_0087b940 = 0x3f800000;
  }
  if (DAT_0087a928 == '\0') {
    if (DAT_0087a9cc <= 0.0) {
      iVar8 = FUN_00574e20();
      if ((iVar8 == -1) && (bVar5)) {
        _memcpy(&DAT_00856c18,&DAT_008668c8,0x7e4c);
        DAT_00880474 = 1;
        FUN_00496740();
        FUN_005765b0();
        FUN_00509830(0xd,0xffffffff,0xffffffff);
        _DAT_0087bd78 = 0;
        _DAT_0087b74c = 0;
        _DAT_0087c570 = 0x3f800000;
        DAT_0087b748 = 0;
      }
    }
    else {
      iVar8 = FUN_0050b310();
      if (iVar8 == 0) {
        DAT_0087a9cc = DAT_0087a9cc - _DAT_00925018;
      }
    }
  }
  else if (!bVar5) {
    DAT_0087a928 = '\0';
  }
  bVar5 = false;
  iVar8 = FUN_00424750(DAT_00856980);
  if (iVar8 != 0) {
    if (((((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
         (*(char *)(DAT_0093d7f0 + 0x281) != '\0')) &&
        (((cVar3 = *(char *)(DAT_0093d7f0 + 0x7b5), cVar3 == -1 || (cVar3 == '1')) || (cVar3 == '2')
         ))) && (*(char *)(DAT_0093d7f0 + 0x285) == '\x0f')) {
      bVar5 = true;
    }
    if ((((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
        ((*(char *)(DAT_0093d7f4 + 0x281) != '\0' &&
         (((cVar3 = *(char *)(DAT_0093d7f4 + 0x7b5), cVar3 == -1 || (cVar3 == '1')) ||
          (cVar3 == '2')))))) && (*(char *)(DAT_0093d7f4 + 0x285) == '\x0f')) {
      bVar5 = true;
    }
  }
  if (DAT_0087a929 == '\0') {
    if (DAT_0087a9d0 <= 0.0) {
      iVar8 = FUN_00574e20();
      if ((iVar8 == -1) && (bVar5)) {
        _memcpy(&DAT_0085ea78,&DAT_008668c8,0x7e4c);
        FUN_00496740();
        FUN_00509830(0xc,0xffffffff,0xffffffff);
        FUN_005765b0();
        _DAT_008569a8 = 0;
        DAT_008569ac = 0;
        DAT_00856900 = 0;
      }
    }
    else {
      iVar8 = FUN_0050b310();
      if (iVar8 == 0) {
        DAT_0087a9d0 = DAT_0087a9d0 - _DAT_00925018;
      }
    }
  }
  else if (!bVar5) {
    DAT_0087a929 = '\0';
  }
  FUN_00425910(DAT_00856980,param_1);
  bVar5 = false;
  iVar8 = FUN_0058a960(0);
  if (iVar8 != 0) {
    if (((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
       ((*(char *)(DAT_0093d7f0 + 0x281) != '\0' &&
        ((((cVar3 = *(char *)(DAT_0093d7f0 + 0x7b5), cVar3 == -1 || (cVar3 == '1')) ||
          (cVar3 == '2')) && (*(char *)(DAT_0093d7f0 + 0x285) == '\x14')))))) {
      bVar5 = true;
    }
    if (((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
       ((*(char *)(DAT_0093d7f4 + 0x281) != '\0' &&
        ((((cVar3 = *(char *)(DAT_0093d7f4 + 0x7b5), cVar3 == -1 || (cVar3 == '1')) ||
          (cVar3 == '2')) && (*(char *)(DAT_0093d7f4 + 0x285) == '\x14')))))) {
      bVar5 = true;
    }
  }
  if (DAT_0087a92b == '\0') {
    if (_DAT_0087a9d8 <= 0.0) {
      iVar8 = FUN_00574e20();
      if ((iVar8 == -1) && (bVar5)) {
        FUN_00496740();
        FUN_00509830(8,0xffffffff,0xffffffff);
        FUN_005765b0();
      }
    }
    else {
      iVar8 = FUN_0050b310();
      if (iVar8 == 0) {
        _DAT_0087a9d8 = _DAT_0087a9d8 - _DAT_00925018;
      }
    }
  }
  else if (!bVar5) {
    DAT_0087a92b = '\0';
  }
  fVar17 = (float10)0;
  if (fVar17 == (float10)_DAT_00950780) {
    iVar8 = 0;
    if (-1 < DAT_007f9f70) {
      psVar13 = &DAT_007f9f70;
      iVar9 = 0;
      do {
        if (8 < *psVar13) break;
        if ((*(int *)((int)&DAT_007f9f88 + iVar9) != 0) &&
           (iVar9 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),
                                 *(int *)((int)&DAT_007f9f88 + iVar9),
                                 *(undefined2 *)((int)&DAT_007f9f72 + iVar9),0), iVar9 != 0)) {
          iVar7 = (int)(&DAT_007f9f70)[iVar8 * 0x14];
          break;
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar8 * 0x28;
        psVar13 = &DAT_007f9f70 + iVar8 * 0x14;
      } while (-1 < (&DAT_007f9f70)[iVar8 * 0x14]);
    }
    iVar8 = 0;
    if (-1 < DAT_007f9f70) {
      psVar13 = &DAT_007f9f70;
      iVar9 = 0;
      do {
        sVar4 = *psVar13;
        if (8 < sVar4) break;
        if (*(int **)((int)&DAT_007f9f88 + iVar9) != (int *)0x0) {
          if ((sVar4 == iVar7) || (iVar7 == -1)) {
            if (((&DAT_007f9f7c)[iVar9] != '\0') ||
               (iVar11 = FUN_0059b840((int)sVar4,0xffffffff,DAT_0095136c), iVar11 != 0)) {
              puVar2 = (uint *)(**(int **)((int)&DAT_007f9f88 + iVar9) + 0x9c);
              *puVar2 = *puVar2 & 0xfffffff7;
            }
          }
          else {
            puVar2 = (uint *)(**(int **)((int)&DAT_007f9f88 + iVar9) + 0x9c);
            *puVar2 = *puVar2 | 8;
          }
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar8 * 0x28;
        psVar13 = &DAT_007f9f70 + iVar8 * 0x14;
      } while (-1 < (&DAT_007f9f70)[iVar8 * 0x14]);
    }
    iVar9 = FUN_0058a960(DAT_009553d4);
    if (iVar9 != 0) {
      DAT_007fa0bc = 1;
      FUN_005cfc00(&DAT_007f9f8c + iVar8 * 0x28,1);
    }
    FUN_00474e50(param_1);
    uVar12 = 0;
    if (_DAT_00879574 == 0.0) {
      DAT_00879554 = iVar7;
    }
    if ((DAT_00879554 != -1) && (DAT_00879554 == iVar7)) {
      uVar12 = 0x3f800000;
    }
    fVar17 = (float10)FUN_0054fad0(_DAT_00879574,uVar12,_DAT_00925018 + _DAT_00925018);
  }
  else {
    DAT_00879554 = -1;
  }
  uVar15 = 0xffffffff;
  _DAT_00879574 = (float)fVar17;
  iVar7 = 0x3c;
  puVar16 = &DAT_007f9f84;
  do {
    FUN_0059b700(*puVar16,&local_4);
    if (local_4 == DAT_007fa210) {
      (&DAT_007f9349)[iVar7 * DAT_007fa214] = 1;
    }
    puVar16 = puVar16 + 10;
    iVar7 = iVar7 + 0x3c;
  } while ((int)puVar16 < 0x7fa074);
  iVar7 = 0;
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    iVar8 = 0;
    do {
      if (((*(int *)((int)&DAT_007f9388 + iVar8) != 0) &&
          (*(int *)((int)&DAT_007f938c + iVar8) != 0)) &&
         (iVar8 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),
                               *(int *)((int)&DAT_007f938c + iVar8),1,0), iVar8 != 0)) {
        uVar15 = (uint)*(byte *)((&DAT_007f9388)[iVar7 * 0xf] + 0x7c);
        break;
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar7 * 0x3c;
    } while ((&PTR_s_negotiations_007f9368)[iVar7 * 0xf] != (undefined *)0x0);
  }
  iVar7 = 0;
  if (uVar15 == 0xffffffff) {
    if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
      iVar8 = 0;
      do {
        if ((*(int *)((int)&DAT_007f938c + iVar8) != 0) &&
           (((iVar9 = FUN_0059b840((int)*(char *)(*(int *)((int)&DAT_007f9388 + iVar8) + 0x86),
                                   *(undefined1 *)(*(int *)((int)&DAT_007f9388 + iVar8) + 0x7c),
                                   DAT_0095136c), iVar9 != 0 ||
             ((*(int *)((int)&DAT_007f939c + iVar8) != 0 &&
              (iVar9 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),
                                    *(int *)((int)&DAT_007f939c + iVar8),0,0), iVar9 != 0)))) ||
            ((&DAT_007f9385)[iVar8] == '\x01')))) {
          puVar2 = (uint *)(**(int **)((int)&DAT_007f938c + iVar8) + 0x9c);
          *puVar2 = *puVar2 & 0xfffffff7;
          FUN_005cfc00(&DAT_007f9390 + iVar8,1);
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar7 * 0x3c;
      } while ((&PTR_s_negotiations_007f9368)[iVar7 * 0xf] != (undefined *)0x0);
    }
  }
  else if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    iVar8 = 0;
    do {
      if (((*(int **)((int)&DAT_007f938c + iVar8) != (int *)0x0) &&
          (*(int *)((int)&DAT_007f9388 + iVar8) != 0)) &&
         (*(byte *)(*(int *)((int)&DAT_007f9388 + iVar8) + 0x7c) != uVar15)) {
        puVar2 = (uint *)(**(int **)((int)&DAT_007f938c + iVar8) + 0x9c);
        *puVar2 = *puVar2 | 8;
      }
      iVar7 = iVar7 + 1;
      iVar8 = iVar7 * 0x3c;
    } while ((&PTR_s_negotiations_007f9368)[iVar7 * 0xf] != (undefined *)0x0);
  }
  iVar7 = FUN_00574e20();
  fVar6 = 0.0;
  if ((_DAT_00950780 == 0.0) && (iVar7 == -1)) {
    uVar14 = 0xffffffff;
    if (((DAT_00879554 == -1) || (_DAT_00879574 <= 0.0)) && (uVar15 != 0xffffffff)) {
      uVar14 = uVar15;
    }
    if (_DAT_00879508 == 0.0) {
      DAT_008795a0 = uVar14;
      DAT_00879b00 = uVar14;
    }
    if ((DAT_00879b00 != 0xffffffff) && (DAT_00879b00 == uVar14)) {
      fVar6 = 1.0;
    }
    fVar17 = (float10)FUN_0054fad0(_DAT_00879508,fVar6,_DAT_00925018 + _DAT_00925018);
    _DAT_00879508 = (float)fVar17;
  }
  else {
    DAT_00879554 = -1;
    DAT_00879b00 = 0xffffffff;
    DAT_00879558 = -1;
    DAT_0087954c = 0xffffffff;
    _DAT_00879508 = fVar6;
    _DAT_00879518 = fVar6;
    _DAT_00879574 = fVar6;
    _DAT_00879594 = fVar6;
  }
  iVar7 = 0;
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    iVar8 = 0;
    do {
      if ((((*(int *)((int)&DAT_007f9388 + iVar8) != 0) &&
           (*(int *)((int)&DAT_007f93a0 + iVar8) != 0)) &&
          ((iVar9 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),
                                 *(int *)((int)&DAT_007f93a0 + iVar8),1,0), iVar9 != 0 &&
           (iVar8 = FUN_0055a360(*(undefined4 *)(param_1 + 0x2ac8),
                                 *(undefined4 *)((int)&DAT_007f93a0 + iVar8)), iVar8 != 0)))) &&
         ((((DAT_0093d7f0 != 0 && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
           (fVar17 = (float10)FUN_005b3c50(DAT_0093d7f0 + 0x5c,iVar8,0), fVar17 < (float10)0.25)) ||
          (((DAT_0093d7f4 != 0 && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
           (fVar17 = (float10)FUN_005b3c50(DAT_0093d7f4 + 0x5c,iVar8,0), fVar17 < (float10)0.25)))))
         ) break;
      iVar7 = iVar7 + 1;
      iVar8 = iVar7 * 0x3c;
    } while ((&PTR_s_negotiations_007f9368)[iVar7 * 0xf] != (undefined *)0x0);
  }
  if ((DAT_00879578 == 0) ||
     (iVar7 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_00879578,1,0),
     uVar15 = DAT_00879b34, iVar7 == 0)) {
    uVar15 = 0xffffffff;
  }
  local_c = 0.0;
  if (DAT_0087a92c == '\0') {
    if (0.0 < _DAT_0087a9dc) {
      _DAT_0087a9dc = _DAT_0087a9dc - _DAT_00925018;
    }
  }
  else if (uVar15 == 0xffffffff) {
    DAT_0087a92c = '\0';
  }
  if (_DAT_00950780 == 0.0) {
    if (DAT_0087a92c == '\0') {
      uVar14 = 0xffffffff;
      if (((((DAT_00879554 == -1) || (_DAT_00879574 <= 0.0)) &&
           ((DAT_00879b00 == 0xffffffff || (_DAT_00879508 <= 0.0)))) && (uVar15 != 0xffffffff)) &&
         ((((DAT_0093d7f0 != 0 && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) &&
           (*(float *)(*(int *)(DAT_0093d7f0 + 0xca4) + 0x28) == 0.0)) ||
          (((DAT_0093d7f4 != 0 && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) &&
           (*(float *)(*(int *)(DAT_0093d7f4 + 0xca4) + 0x28) == 0.0)))))) {
        uVar14 = DAT_00879b34;
      }
      if (_DAT_00879518 == 0.0) {
        if (DAT_0087954c != uVar14) {
          _DAT_00879568 = local_c;
        }
        DAT_0087954c = uVar14;
        if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
          piVar10 = &DAT_007f9388;
          do {
            if ((*piVar10 != 0) && (*(byte *)(*piVar10 + 0x7c) == uVar14)) break;
            piVar1 = piVar10 + 7;
            piVar10 = piVar10 + 0xf;
          } while (*piVar1 != 0);
        }
      }
      if ((DAT_0087954c != 0xffffffff) && (DAT_0087954c == uVar14)) {
        _DAT_00879568 = _DAT_00925018 + _DAT_00879568;
        local_c = 1.0;
      }
      iVar7 = FUN_00574e20();
      if (iVar7 == 0xe) {
        local_c = 1.0;
      }
      fVar17 = (float10)FUN_0054fad0(_DAT_00879518,local_c,_DAT_00925018 + _DAT_00925018);
      _DAT_00879518 = (float)fVar17;
      if (_DAT_007f9364 < _DAT_00879568 != (_DAT_007f9364 == _DAT_00879568)) {
        FUN_00496740();
        FUN_005765b0();
        FUN_00509830(0xe,0xffffffff,0xffffffff);
        FUN_006514b0("JForcePush",0,0x3fc00000);
      }
    }
  }
  else {
    DAT_0087954c = 0xffffffff;
    _DAT_00879518 = local_c;
    _DAT_00879568 = local_c;
  }
  FUN_00477d60(param_1);
  iVar7 = FUN_0058eaa0(PTR_DAT_00802c54,DAT_0093d7f0,2,DAT_0087baf0);
  fVar17 = (float10)0;
  if (fVar17 == (float10)_DAT_00950780) {
    iVar9 = 0;
    iVar8 = -1;
    if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
      piVar10 = &DAT_007f939c;
      do {
        if (iVar8 != -1) break;
        if (((((*piVar10 != 0) &&
              (iVar11 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),*piVar10,0,0), iVar11 == 0))
             && (DAT_0093d7f0 != 0)) &&
            (((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0 &&
             (*(char *)(DAT_0093d7f0 + 0x7b5) != '-')))) &&
           (((*(byte *)(*(int *)*piVar10 + 0x7a) & 4) != 0 ||
            ((iVar7 != 0 && (iVar7 == *(int *)*piVar10)))))) {
          iVar8 = iVar9;
        }
        iVar9 = iVar9 + 1;
        piVar1 = piVar10 + 2;
        piVar10 = piVar10 + 0xf;
      } while (*piVar1 != 0);
    }
    if (DAT_0087a96c != (int *)0x0) {
      if ((iVar8 == -1) &&
         (iVar9 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,0,0), iVar9 == 0)) {
        if (((DAT_0093d7f0 != 0) &&
            (((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0 &&
             (*(char *)(DAT_0093d7f0 + 0x7b5) != '-')))) &&
           (((*(byte *)(DAT_0087a7e0 + 0x7a) & 4) != 0 || ((iVar7 != 0 && (iVar7 == DAT_0087a7e0))))
           )) {
          iVar8 = 999;
        }
        if (160.0 <= (double)DAT_0086e4e2) {
          if ((*(byte *)(*DAT_0087a96c + 0x7a) & 1) == 0) {
            FUN_0055a250(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,1,0);
          }
        }
        else {
          FUN_0055a2b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,0,0);
          uVar12 = FUN_006e6b90();
          FUN_00474df0(uVar12);
        }
      }
      else {
        iVar7 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,0,0);
        if (iVar7 != 0) {
          DAT_0086e4e4 = DAT_0086e4e4 | 0x80;
        }
      }
    }
    uVar12 = 0;
    if (_DAT_00879594 == 0.0) {
      DAT_00879558 = iVar8;
    }
    if ((DAT_00879558 != -1) && (DAT_00879558 == iVar8)) {
      uVar12 = 0x3f800000;
    }
    fVar17 = (float10)FUN_0054fad0(_DAT_00879594,uVar12,_DAT_00925018 + _DAT_00925018);
  }
  else {
    DAT_00879558 = -1;
  }
  _DAT_00879594 = (float)fVar17;
  if (DAT_00879b50 != (code *)0x0) {
    (*DAT_00879b50)(param_1);
  }
  if ((((DAT_00879554 != -1) || (DAT_00879b00 != 0xffffffff)) || (DAT_0087954c != 0xffffffff)) ||
     ((DAT_00879558 != -1 || ((iVar7 = FUN_00574e20(), iVar7 != -1 && (iVar7 != 0xd)))))) {
    FUN_005765b0();
  }
  iVar7 = FUN_00574e20();
  if ((iVar7 == -1) && (iVar7 = FUN_0055f1a0(), iVar7 == 0)) {
    FUN_004a4900(0,&DAT_007fa1b4,_DAT_007fa1c0,4);
    return;
  }
  FUN_004a48f0();
  return;
}

