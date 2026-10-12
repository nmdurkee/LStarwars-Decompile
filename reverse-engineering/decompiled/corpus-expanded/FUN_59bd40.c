/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59bd40; label: FUN_0059bd40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059bd40(int param_1,int param_2)

{
  uint *puVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  undefined1 uVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  bool bVar13;
  float10 fVar14;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  float local_10;
  float local_c;
  float fStack_8;
  int local_4;
  
  if (DAT_00951288 != 0) {
    return;
  }
  if (*(char *)(param_1 + 0x280) == -1) {
    return;
  }
  local_4 = (int)*(char *)(param_1 + 0x7b5);
  local_c = *(float *)(param_1 + 0xdc4);
  iVar10 = FUN_0059bb30(param_1,&local_20,&local_18,&local_14);
  if (iVar10 == 0) {
    bVar6 = false;
    local_1c = 0;
    if ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) ||
       ((DAT_00802854 != -1 && (*(char *)(param_1 + 0x7b5) == DAT_00802854)))) {
      local_10 = *(float *)(param_1 + 0xdc4) - _DAT_00925018;
      *(float *)(param_1 + 0xdc4) = local_10;
      if (local_10 < 0.0) {
        *(undefined4 *)(param_1 + 0xdc4) = 0;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xdc4) = 0;
    }
  }
  else {
    cVar3 = *(char *)(param_1 + 0x285);
    local_20 = local_20 + 0x8000;
    bVar6 = true;
    local_1c = 1;
    if (((cVar3 < '\0') || ('\x1f' < cVar3)) ||
       ((*(uint *)(&DAT_008034cc + cVar3 * 0xc) & 0x20000) == 0)) {
      if ((*(char *)(param_1 + 0x281) == '\0') &&
         (iVar10 = FUN_0055d130(param_1,0x3fa00000,0), iVar10 == 0)) {
        *(undefined4 *)(param_1 + 0xdc4) = 0x3c23d70a;
      }
      else {
        if (_DAT_00925018 <= 0.033333335) {
          fVar2 = (1.0 / _DAT_00925018) / 30.0;
          fVar2 = (fVar2 + fVar2) * _DAT_00925018;
        }
        else {
          fVar2 = _DAT_00925018 + _DAT_00925018;
        }
        *(float *)(param_1 + 0xdc4) = fVar2 + *(float *)(param_1 + 0xdc4);
        fVar2 = *(float *)(param_1 + 0xdc4);
        if (!NAN(fVar2) && 0.25 < fVar2 != (fVar2 == 0.25)) {
          *(undefined4 *)(param_1 + 0xdc4) = 0x3ecccccd;
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xdc4) = 0x3ecccccd;
    }
  }
  iVar10 = (int)*(char *)(param_1 + 0x7b5);
  if ((*(uint *)(PTR_PTR_007fb0e4 + iVar10 * 0x10 + 8) & 0x2000) == 0) {
    if ((((*(char *)(param_1 + 0x281) == '\0') &&
         (iVar10 = FUN_0055d130(param_1,0x3fa00000,0), iVar10 == 0)) ||
        (*(char *)(param_1 + 0x7b5) != -1)) ||
       ((param_2 != 0 &&
        ((DAT_00804c64 == -1 ||
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c64 * 4) == 0)))))) {
      if ((DAT_00802838 == -1) ||
         ((*(char *)(param_1 + 0x7b5) != DAT_00802838 || (*(char *)(param_1 + 0x7b8) != '\t')))) {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
      iVar10 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
      if (((((((*(uint *)(iVar10 + 0x90) & 0x8000000) != 0) && (DAT_00802870 != -1)) &&
            (*(short *)(param_1 + 0x27e) == -1)) &&
           ((0x1f < local_18 || ((*(uint *)(&DAT_008034cc + local_18 * 0xc) & 0x10581) == 0)))) &&
          ((*(float *)(iVar10 + 0x1c) == *(float *)(*(int *)(param_1 + 0xca4) + 0x28) || (bVar6))))
         && (((local_1c != 0 &&
              (0x6aaa < (int)((local_14 ^ (int)local_14 >> 0x1f) - ((int)local_14 >> 0x1f)))) &&
             ((iVar10 = *(int *)(*(int *)(param_1 + 0x54) + 0x24),
              (*(float *)(iVar10 + 0x1c) + *(float *)(iVar10 + 0x18)) * 0.5 <
              *(float *)(param_1 + 0x22c) &&
              ((((((*(char *)(param_1 + 0x281) == '\0' &&
                   (0.15 < *(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c))) &&
                  (DAT_00802838 != -1)) && (*(char *)(param_1 + 0x7b5) == DAT_00802838)) &&
                (((*(char *)(param_1 + 0x7b8) == '\0' && (*(byte *)(param_1 + 0x7b9) < 2)) ||
                 (*(char *)(param_1 + 0x7b8) == '\t')))) &&
               ((-1.25 < *(float *)(param_1 + 0x6c) &&
                (fVar2 = *(float *)(param_1 + 0x77c), !NAN(fVar2) && 0.25 < fVar2 != (fVar2 == 0.25)
                )))))))))) {
        *(char *)(param_1 + 0x7b5) = (char)DAT_00802870;
        FUN_0062e650(param_1 + 8,0xffffffff);
        iVar10 = (int)DAT_00804c84;
        *(short *)(param_1 + 0x7aa) = DAT_00804c84;
        fVar14 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar10,0,0,0);
        local_c = (float)fVar14;
        *(float *)(param_1 + 0x77c) = local_c;
        if (local_c <= 0.0) {
          *(undefined4 *)(param_1 + 0x77c) = 0x3e99999a;
        }
        *(undefined1 *)(param_1 + 0x7b1) = 0;
        *(undefined2 *)(param_1 + 0x5a) = (undefined2)local_20;
        *(undefined4 *)(param_1 + 0x68) = DAT_0093b0cc;
        *(undefined4 *)(param_1 + 0x6c) = DAT_0093b0d0;
        *(undefined4 *)(param_1 + 0x70) = DAT_0093b0d4;
      }
    }
    else {
      fVar2 = *(float *)(param_1 + 0xdc4);
      if (!NAN(fVar2) && 0.25 < fVar2 != (fVar2 == 0.25)) {
        if (((local_18 == 0x1e) || (local_18 == 0x1f)) ||
           ((*(uint *)(param_1 + 0xef4) & 0x20000) != 0)) {
          if (DAT_00802850 != -1) {
            iVar10 = FUN_00555fb0(PTR_DAT_00802c54,param_1 + 0x80,1);
            if (iVar10 != 0) {
              if ((((*(byte *)(iVar10 + 0xac) & 8) == 0) || (DAT_0087baf0 != 0)) &&
                 ((*(char *)(iVar10 + 0x89) == -1 && (*(float *)(iVar10 + 0x90) <= 0.0)))) {
                iVar12 = 0;
                do {
                  iVar4 = (&DAT_0093d7f0)[iVar12];
                  if (((iVar4 != 0) && (iVar4 != param_1)) &&
                     ((*(char *)(iVar4 + 0x7b5) == DAT_00802850 &&
                      (*(int *)(iVar4 + 0x798) == iVar10)))) break;
                  iVar4 = (&DAT_0093d7f4)[iVar12];
                  if ((((iVar4 != 0) && (iVar4 != param_1)) &&
                      (*(char *)(iVar4 + 0x7b5) == DAT_00802850)) &&
                     (*(int *)(iVar4 + 0x798) == iVar10)) {
                    iVar12 = iVar12 + 1;
                    break;
                  }
                  iVar4 = (&DAT_0093d7f8)[iVar12];
                  if (((iVar4 != 0) && (iVar4 != param_1)) &&
                     ((*(char *)(iVar4 + 0x7b5) == DAT_00802850 &&
                      (*(int *)(iVar4 + 0x798) == iVar10)))) {
                    iVar12 = iVar12 + 2;
                    break;
                  }
                  iVar4 = (&DAT_0093d7fc)[iVar12];
                  if (((iVar4 != 0) && (iVar4 != param_1)) &&
                     ((*(char *)(iVar4 + 0x7b5) == DAT_00802850 &&
                      (*(int *)(iVar4 + 0x798) == iVar10)))) {
                    iVar12 = iVar12 + 3;
                    break;
                  }
                  iVar12 = iVar12 + 4;
                } while (iVar12 < 8);
                if (iVar12 == 8) {
                  *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802850;
                  *(int *)(param_1 + 0x798) = iVar10;
                  *(char *)(param_1 + 0x7b6) = (char)local_18;
                  FUN_0058d930(param_1,0);
                  FUN_004399e0(param_1,param_1 + 0x80);
                }
              }
              goto LAB_0059c366;
            }
          }
          if (((DAT_00802854 != -1) && (DAT_0095629c != (code *)0x0)) &&
             (iVar10 = (*DAT_0095629c)(param_1), iVar10 != 0)) {
            iVar10 = FUN_00558570(*(undefined4 *)(PTR_DAT_00802c54 + 0x46a4),param_1 + 0x80,param_1,
                                  &fStack_8,7);
            if ((iVar10 != 0) && (fStack_8 < 6.25)) {
              uVar8 = (undefined1)DAT_00802854;
              *(undefined4 *)(param_1 + 0x768) = 0x3f400000;
              *(undefined1 *)(param_1 + 0x7b5) = uVar8;
              *(int *)(param_1 + 0x798) = iVar10;
              *(char *)(param_1 + 0x7b6) = (char)local_18;
              FUN_0058d930(param_1,0);
              FUN_0054a3e0(0,0x3f000000,0,1);
              FUN_004399e0(param_1,param_1 + 0x80);
            }
          }
        }
        else if ((*(short *)(param_1 + 0x27e) == -1) &&
                (local_c < *(float *)(param_1 + 0xdc4) != (local_c == *(float *)(param_1 + 0xdc4))))
        {
          *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_0080284c;
        }
        else {
          *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_0080284c;
        }
LAB_0059c366:
        if (*(char *)(param_1 + 0x7b5) != -1) {
          *(short *)(param_1 + 0x7aa) = DAT_00804c64;
          FUN_0059bcc0(param_1);
        }
      }
    }
  }
  else if ((DAT_00802870 == -1) || (iVar10 != DAT_00802870)) {
    if (bVar6) {
      *(undefined2 *)(param_1 + 0x7a6) = (undefined2)local_20;
    }
    if (*(float *)(param_1 + 0xdc4) <= 0.0) {
      if ((DAT_00802854 == -1) || (iVar10 != DAT_00802854)) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      }
      else {
        FUN_0054a3e0(0,0x3f000000,0,1);
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      }
    }
  }
  else {
    uVar11 = *(uint *)(*(int *)(param_1 + 0xca4) + 8);
    if ((DAT_00802278 & uVar11) == 0) {
      if ((DAT_0080227c & uVar11) != 0) {
        *(undefined1 *)(param_1 + 0x7b1) = 3;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x7b1) = 1;
    }
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
       || (iVar10 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0), iVar10 != 0)) {
      local_10 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
      *(float *)(param_1 + 0x77c) = local_10;
      if (local_10 <= 0.0) {
        if (*(char *)(param_1 + 0x7b1) == '\x01') {
          FUN_00561ba0(param_1,9);
          *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
          *(undefined4 *)(param_1 + 0x788) = 0x3f99999a;
          *(undefined2 *)(param_1 + 0x58) = *(undefined2 *)(param_1 + 0x5a);
          *(undefined2 *)(param_1 + 0x27a) = *(undefined2 *)(param_1 + 0x5a);
          FUN_00548370(param_1);
        }
        else if (((*(char *)(param_1 + 0x7b1) == '\x03') && (DAT_00804cd8 != -1)) &&
                (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cd8 * 4) != 0)) {
          *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
          *(undefined2 *)(param_1 + 0x58) = *(undefined2 *)(param_1 + 0x5a);
          *(undefined2 *)(param_1 + 0x27a) = *(undefined2 *)(param_1 + 0x5a);
          FUN_0049d9f0(param_1,0x3f800000,0);
          FUN_00548370(param_1);
        }
        else {
          FUN_00561d20(param_1);
        }
      }
    }
  }
  if ((DAT_00802854 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802854)) {
    if ((DAT_00802850 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802850)) {
      if (((DAT_0080284c != -1) && (*(char *)(param_1 + 0x7b5) == DAT_0080284c)) &&
         (iVar10 = FUN_005a4e60(param_1), iVar10 == 0)) {
        if ((((DAT_00802840 == -1) || (DAT_00804c58 == -1)) ||
            (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c58 * 4) == 0)) ||
           ((int)((local_14 ^ (int)local_14 >> 0x1f) - ((int)local_14 >> 0x1f)) < 0x71c8)) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        }
        else {
          *(char *)(param_1 + 0x7b5) = (char)DAT_00802840;
          *(short *)(param_1 + 0x7aa) = DAT_00804c58;
        }
      }
    }
    else {
      if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0) goto LAB_0059c7bf;
      iVar10 = FUN_00554e30(*(undefined4 *)(param_1 + 0x798),(int)*(char *)(param_1 + 0x7b6));
      if (iVar10 == 0) {
        iVar10 = FUN_0054fa60();
        if (iVar10 < 0x800) {
          FUN_00554d70(param_1,*(int *)(param_1 + 0x798));
        }
        else {
          puVar1 = (uint *)(*(int *)(param_1 + 0x798) + 0x84);
          *puVar1 = *puVar1 & 0xfffffcff;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
          iVar10 = FUN_0054fa60(0);
          local_c = (float)iVar10 * 1.5259022e-05 * 0.4;
          FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),local_c);
        }
        FUN_00547930(0x38,param_1 + 0x80,0,0);
      }
    }
    goto LAB_0059c900;
  }
  iVar10 = *(int *)(param_1 + 0xca4);
  bVar7 = false;
  bVar6 = false;
  bVar13 = false;
  if ((*(uint *)(iVar10 + 8) & DAT_00802278) != 0) {
LAB_0059c7bf:
    FUN_00561ba0(param_1,0);
    *(undefined4 *)(param_1 + 0xdc4) = 0;
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
    return;
  }
  if (*(float *)(iVar10 + 0x28) <= 0.0) {
    *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c68;
    local_c = *(float *)(param_1 + 0x768) - _DAT_00925018;
    *(float *)(param_1 + 0x768) = local_c;
    if (local_c < 0.0 != (local_c == 0.0)) {
      FUN_0054a3e0(0,0x3f000000,0,1);
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
    goto LAB_0059c900;
  }
  uVar9 = FUN_0054b3d0(param_1,iVar10);
  uVar11 = FUN_00550040(uVar9,*(undefined2 *)(param_1 + 0x7a6));
  iVar10 = (uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f);
  if (iVar10 < 0x31c7) {
    bVar7 = true;
    *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c6c;
  }
  else {
    if (iVar10 < 0x4e39) {
      *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c68;
      goto LAB_0059c900;
    }
    *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c70;
  }
  *(undefined4 *)(param_1 + 0x768) = 0x3f400000;
  if (*(char *)(param_1 + 0x7b6) == '\x1e') {
    if (bVar7) goto LAB_0059c6d3;
LAB_0059c625:
    iVar10 = *(int *)(param_1 + 0x798);
    bVar13 = *(int *)(*(int *)(iVar10 + 0x34) + 0xc) != 0;
    bVar6 = !bVar13;
    uVar5 = 0xbf800000;
  }
  else {
    if (bVar7) goto LAB_0059c625;
LAB_0059c6d3:
    iVar10 = *(int *)(param_1 + 0x798);
    if (*(int *)(*(int *)(iVar10 + 0x34) + 0xc) == 2) {
      uVar5 = 0x3f800000;
      bVar6 = true;
    }
    else {
      uVar5 = 0x3f800000;
      bVar13 = true;
    }
  }
  FUN_00558530(iVar10,param_1,uVar5);
  if ((bVar6) && (iVar10 = FUN_0062c350(0x40400000,_DAT_00925018), 0 < iVar10)) {
    FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),1,0);
  }
  else if (bVar13) {
    iVar10 = FUN_0054fa60(0);
    local_c = (float)iVar10 * 1.5259022e-05 * 0.3;
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),local_c);
  }
LAB_0059c900:
  if ((*(char *)(param_1 + 0x7b5) != local_4) &&
     ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x2000) != 0)) {
    FUN_0058d930(param_1,0);
    if ((DAT_00802870 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802870)) {
      FUN_00548370(param_1);
    }
    else {
      FUN_00548020(param_1,0,0);
    }
    if (local_1c != 0) {
      *(undefined2 *)(param_1 + 0x7a6) = (undefined2)local_20;
    }
  }
  return;
}

