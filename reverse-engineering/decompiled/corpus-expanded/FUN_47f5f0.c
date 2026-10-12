/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47f5f0; label: thunk_FUN_0047ecb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0047ecb0(void)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  int iStack_28;
  int iStack_24;
  int aiStack_20 [8];
  
  if ((0.0 < _DAT_00950780) || (0.0 < _DAT_00950678)) {
    return;
  }
  if (0.0 < DAT_00856924) {
    DAT_00856924 = DAT_00856924 - _DAT_00925018;
  }
  if (0.0 < DAT_0085691c) {
    DAT_0085691c = DAT_0085691c - _DAT_00925018;
  }
  if (0.0 < DAT_00856934) {
    DAT_00856934 = DAT_00856934 - _DAT_00925018;
  }
  if (0.0 < DAT_00856870) {
    DAT_00856870 = DAT_00856870 - _DAT_00925018;
  }
  aiStack_20[2] = 0;
  aiStack_20[0] = 0;
  aiStack_20[4] = 0;
  aiStack_20[6] = 0;
  if (0.0 < DAT_00856928) {
    DAT_00856928 = DAT_00856928 - _DAT_00925018;
  }
  if (0.0 < _DAT_00856920) {
    _DAT_00856920 = _DAT_00856920 - _DAT_00925018;
  }
  if (0.0 < _DAT_00856938) {
    _DAT_00856938 = _DAT_00856938 - _DAT_00925018;
  }
  if (0.0 < _DAT_00856874) {
    _DAT_00856874 = _DAT_00856874 - _DAT_00925018;
  }
  aiStack_20[3] = 0;
  aiStack_20[1] = 0;
  aiStack_20[5] = 0;
  aiStack_20[7] = 0;
  switch(DAT_00879b14) {
  case 0:
    iStack_24 = 0;
    iStack_28 = 0;
    bVar10 = false;
    bVar9 = false;
    bVar8 = false;
    bVar7 = false;
    iVar12 = 0;
    puVar13 = &DAT_009253b8;
    do {
      if ((bVar7) || (bVar8)) break;
      if ((&DAT_0087b6c8)[iVar12] != '\0') {
        uVar4 = *puVar13;
        if ((DAT_008022c4 & uVar4) == 0) {
          if ((DAT_008022c8 & uVar4) == 0) {
            uVar5 = puVar13[2];
            if (((DAT_00802290 & uVar5) == 0) && ((DAT_00802290 & uVar4) == 0)) {
              if (((DAT_00802294 & uVar5) == 0) && ((DAT_00802294 & uVar4) == 0)) {
                if (((DAT_00802298 & uVar5) == 0) && ((DAT_00802298 & uVar4) == 0)) {
                  if (((DAT_0080229c & uVar5) != 0) || ((DAT_0080229c & uVar4) != 0)) {
                    iStack_24 = 1;
                    aiStack_20[iVar12 + 6] = 1;
                  }
                }
                else {
                  iStack_28 = 1;
                  aiStack_20[iVar12 + 4] = 1;
                }
              }
              else {
                bVar10 = true;
                aiStack_20[iVar12] = 1;
              }
            }
            else {
              bVar9 = true;
              aiStack_20[iVar12 + 2] = 1;
            }
          }
          else {
            bVar8 = true;
          }
        }
        else {
          bVar7 = true;
        }
      }
      puVar13 = puVar13 + 0x18;
      iVar12 = iVar12 + 1;
    } while ((int)puVar13 < 0x925478);
    if (DAT_0087950c == 0) {
      if (!bVar7) {
        if (bVar8) {
          FUN_00547930(0x31,0,0,0);
          _DAT_00879510 = 0.0;
          DAT_00879b14 = 4;
          _DAT_00879b18 = 0.6;
          return;
        }
        if (DAT_008794ec == -1) {
          return;
        }
        if (bVar9) {
          if (0 < DAT_00879584) {
            FUN_00547930(0x2f,0,0,0);
            DAT_00879584 = DAT_00879584 + -1;
            return;
          }
          return;
        }
        if (bVar10) {
          if (0 < DAT_00879584) {
            if (DAT_00879584 != 1) {
              return;
            }
            iVar12 = FUN_00594b70(&DAT_00855f24,0x4000000,0x4000000,0,0,0,0);
            if (iVar12 == 0) {
              return;
            }
          }
          FUN_00547930(0x2f,0,0,0);
          DAT_00879584 = DAT_00879584 + 1;
          return;
        }
        return;
      }
      FUN_00547930(0x30,0,0,0);
      DAT_00802af4 = DAT_008794ec;
      if (DAT_00879584 == 0) {
        if (DAT_008794ec != -1) {
          _DAT_00879510 = 0.0;
          DAT_00879588 = (int)*(short *)(*(short *)(DAT_00956290 + 4 + DAT_008794ec * 0x1c) * 0x9c +
                                         0x60 + DAT_00951354);
          DAT_00879b14 = 1;
          _DAT_00879b18 = 0.6;
          return;
        }
        iVar11 = -1;
        iVar12 = -1;
      }
      else {
        if (DAT_00879584 == 1) {
          if (DAT_008794ec == -1) {
            return;
          }
          iVar12 = FUN_0059b6a0(DAT_00956290 + DAT_008794ec * 0x1c,5,4);
          if (iVar12 == -1) {
            return;
          }
          DAT_00879588 = (int)*(short *)(iVar12 * 0x9c + 0x60 + DAT_00951354);
          cVar3 = *(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
          iVar11 = -1;
          iVar12 = -1;
          goto LAB_0047f3a2;
        }
        if (DAT_00879584 != 2) {
          return;
        }
        if (((DAT_008794ec == -1) ||
            (iVar12 = FUN_00594b70(&DAT_00855f24,0x4000000,0x4000000,0,&iStack_24,&iStack_28,0),
            iVar12 < 1)) ||
           (iVar11 = FUN_0059b6a0(DAT_00956290 + DAT_00802af4 * 0x1c,5,5), iVar11 == -1)) {
LAB_0047f2c6:
          FUN_00547930(0x32,0,0,0);
          return;
        }
        if (iVar12 < 2) {
          if (iStack_24 != -1) {
            _DAT_00879510 = 0.0;
            DAT_00879588 = (int)*(short *)(iVar11 * 0x9c + 0x60 + DAT_00951354);
            DAT_00879b14 = 2;
            _DAT_00879b18 = 0.6;
            DAT_0087b6c4 = (short)iStack_24;
            DAT_0087b6c6 = (short)iStack_24;
            return;
          }
          goto LAB_0047f2c6;
        }
        DAT_00879588 = (int)*(short *)(iVar11 * 0x9c + 0x60 + DAT_00951354);
        iVar12 = iStack_24;
        iVar11 = iStack_28;
      }
      cVar3 = *(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78);
LAB_0047f3a2:
      DAT_008795a4 = 1;
      FUN_0047ba10((int)cVar3,iVar12,iVar11);
      FUN_00509830(0x11,0xffffffff,0xffffffff);
      return;
    }
    if (DAT_00879584 == 0) {
      aiStack_20[3] = 0;
    }
    else {
      if (3 < DAT_00879584) {
        aiStack_20[1] = 0;
        aiStack_20[0] = 0;
      }
      if (aiStack_20[2] != 0) {
        DAT_00856934 = 0.1;
      }
    }
    if (aiStack_20[0] != 0) {
      DAT_00856870 = 0.1;
    }
    if (aiStack_20[4] != 0) {
      DAT_00856924 = 0.1;
    }
    if (aiStack_20[6] != 0) {
      DAT_0085691c = 0.1;
    }
    if (aiStack_20[3] != 0) {
      _DAT_00856938 = 0.1;
    }
    if (aiStack_20[1] != 0) {
      _DAT_00856874 = 0.1;
    }
    if (aiStack_20[5] != 0) {
      DAT_00856928 = 0.1;
    }
    if (aiStack_20[7] != 0) {
      _DAT_00856920 = 0.1;
    }
    iVar12 = DAT_00879584;
    if (bVar7) {
      if (DAT_00879584 == 3) {
        if (DAT_007fa1a0 != '\x01') {
          return;
        }
        if ((DAT_0087956c != 0) || (DAT_00879570 != 0)) {
          FUN_00475c60(0,1,0);
          FUN_00475c60(1,1,0);
          DAT_0087956c = 0;
          DAT_00879570 = 0;
          iVar12 = DAT_00879584;
          goto LAB_0047f180;
        }
      }
      else {
        if (DAT_00879584 != 4) goto LAB_0047f188;
        iVar12 = *(int *)(&PTR_DAT_007fa100)[DAT_007fa188];
        if ((iVar12 != 0) && ((&DAT_0086e0f4)[(uint)*(byte *)(iVar12 + 0x7c) * 0xc] != '\0')) {
          FUN_00547930(0x30,0,0,0);
          DAT_00879588 = (int)*(short *)(iVar12 + 0x60);
          DAT_008795a4 = 1;
          FUN_0047ba10(*(undefined1 *)(iVar12 + 0x7c),0xffffffff,0xffffffff);
          FUN_00509830(0x11,0xffffffff,0xffffffff);
          iVar12 = DAT_00879584;
          goto LAB_0047f188;
        }
      }
      FUN_00547930(0x32,0,0,0);
      iVar12 = DAT_00879584;
    }
    else {
      if (bVar8) {
        FUN_00547930(0x31,0,0,0);
        _DAT_00879510 = 0.0;
        _DAT_00879b18 = 0.6;
        DAT_00879b14 = 4;
        iVar12 = DAT_00879584;
        goto LAB_0047f188;
      }
      if (bVar9) {
        if (0 < DAT_00879584) {
          FUN_00547930(0x2f,0,0,0);
          DAT_00879584 = DAT_00879584 + -1;
          iVar12 = DAT_00879584;
        }
        goto LAB_0047f188;
      }
      if (bVar10) {
        if (DAT_00879584 < 4) {
          FUN_00547930(0x2f,0,0,0);
          DAT_00879584 = DAT_00879584 + 1;
          iVar12 = DAT_00879584;
        }
        goto LAB_0047f188;
      }
      bVar2 = (&DAT_007fa189)[DAT_00879584 * 8];
      if (bVar2 < 2) goto LAB_0047f188;
      if (((DAT_00879584 == 3) && (DAT_0087956c == 0)) && (DAT_00879570 == 0)) {
        return;
      }
      if (iStack_28 != 0) {
        FUN_00547930(0x2f,0,0,0);
        iVar12 = DAT_00879584;
        pcVar1 = &DAT_007fa188 + DAT_00879584 * 8;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 < '\0') {
          (&DAT_007fa188)[iVar12 * 8] = bVar2 - 1;
        }
        goto LAB_0047f188;
      }
      if (iStack_24 == 0) goto LAB_0047f188;
      FUN_00547930(0x2f,0,0,0);
      iVar12 = DAT_00879584;
      (&DAT_007fa188)[DAT_00879584 * 8] = (&DAT_007fa188)[DAT_00879584 * 8] + '\x01';
      if ((int)(&DAT_007fa188)[iVar12 * 8] < (int)(uint)bVar2) goto LAB_0047f188;
LAB_0047f180:
      (&DAT_007fa188)[iVar12 * 8] = 0;
    }
LAB_0047f188:
    if (iVar12 != 3) {
      DAT_007fa1a0 = 0;
      return;
    }
    return;
  case 1:
    fVar6 = _DAT_00925018 + _DAT_00879510;
    if (_DAT_00879b18 < fVar6 != (_DAT_00879b18 == fVar6)) {
      _DAT_00879510 = fVar6;
      FUN_0055c650(DAT_00802af4);
      _DAT_00950780 = 1.0;
      DAT_00802e14 = 0;
      DAT_00951b80 = DAT_00879588 * 0x130 + DAT_00951b78;
      DAT_0087b2c0 = 1;
      return;
    }
    break;
  case 2:
  case 3:
    fVar6 = _DAT_00925018 + _DAT_00879510;
    if (_DAT_00879b18 < fVar6 != (_DAT_00879b18 == fVar6)) {
      _DAT_00879510 = fVar6;
      FUN_00489150((int)DAT_0087b6c4,(int)DAT_0087b6c6,
                   (int)*(char *)(DAT_00879588 * 0x130 + 0xa3 + DAT_00951b78),0xffffffff,1);
      _DAT_00950780 = 1.0;
      DAT_0093b29c = 1;
      DAT_0093b2a4 = 1;
      DAT_0087b2c0 = 1;
      DAT_00802e14 = 0;
      DAT_00855f7c = 2;
      DAT_00951b80 = DAT_00879588 * 0x130 + DAT_00951b78;
      return;
    }
    break;
  case 4:
    fVar6 = _DAT_00925018 + _DAT_00879510;
    if (_DAT_00879b18 < fVar6 != (_DAT_00879b18 == fVar6)) {
      _DAT_00879510 = fVar6;
      FUN_00474fd0();
      return;
    }
    break;
  default:
    return;
  }
  _DAT_00879510 = _DAT_00925018 + _DAT_00879510;
  return;
}

