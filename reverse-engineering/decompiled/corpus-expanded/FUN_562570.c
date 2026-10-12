/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x562570; label: FUN_00562570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00562570(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  bool bVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  undefined4 uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  float10 fVar15;
  undefined4 uVar16;
  undefined4 local_30;
  int local_2c;
  int local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((*(uint *)(param_1 + 0xe24) & 0x1000) != 0) {
    return;
  }
  local_28 = -1;
  iVar8 = FUN_0055f450();
  uVar14 = *(uint *)(param_1 + 0x1fc) >> 7 & 1;
  local_2c = 0;
  if ((uVar14 != 0) || ((*(uint *)(param_1 + 0xeec) & 0x100) != 0)) {
    if ((DAT_00804c80 == -1) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c80 * 4) == 0)) {
      if ((((param_4 & 2) != 0) && (DAT_00804c78 != -1)) &&
         (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c78 * 4) != 0)) {
        local_2c = 2;
      }
    }
    else {
      local_2c = 1;
    }
  }
  if (0.0 < *(float *)(param_1 + 0xd28)) {
    *(float *)(param_1 + 0xd28) = *(float *)(param_1 + 0xd28) - _DAT_00925018;
  }
  if (0.0 < *(float *)(param_1 + 0xd68)) {
    *(float *)(param_1 + 0xd68) = *(float *)(param_1 + 0xd68) - _DAT_00925018;
  }
  cVar2 = *(char *)(param_1 + 0x7b5);
  if (cVar2 == -1) {
LAB_00562b11:
    if ((DAT_00802838 == -1) || (cVar2 != DAT_00802838)) {
      if ((char)param_4 < '\0') {
        return;
      }
      if (DAT_00802838 == -1) {
        return;
      }
      if (0.0 < *(float *)(param_1 + 0x103c)) {
        return;
      }
      if (param_2 == 0) {
        if ((*(uint *)(param_1 + 0xeec) & 0x100) == 0) {
          return;
        }
        if (local_2c == 0) {
          return;
        }
      }
      if ((*(char *)(param_1 + 0x281) == '\0') && (*(float *)(param_1 + 0xd24) <= 0.0)) {
        return;
      }
      if ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x1000) == 0) {
        return;
      }
      if ((param_4 & 4) != 0) {
        if (0.0 < *(float *)(param_1 + 0xd68)) {
          return;
        }
        if ((*(char *)(param_1 + 0x286) != '\0') && (*(float *)(param_1 + 0xd38) != 0.0)) {
          return;
        }
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x7bc);
      if ((uVar3 & 0x1000) != 0) {
        *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x8000;
      }
      if (((*(uint *)(param_1 + 0xe20) & 0x100000) != 0) && (param_3 == 0)) {
        *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xffefffff;
      }
      if (*(float *)(param_1 + 0x6c) < 0.0) {
        *(undefined4 *)(param_1 + 0xd1c) = 0;
      }
      cVar2 = *(char *)(param_1 + 0x7b8);
      if (((cVar2 == '\x05') && (*(char *)(param_1 + 0xe32) == '\x02')) &&
         (0.0 < *(float *)(param_1 + 0xd64))) {
        fVar1 = *(float *)(param_1 + 0xd64) - _DAT_00925018;
        *(float *)(param_1 + 0xd64) = fVar1;
        if (fVar1 < 0.0 != (fVar1 == 0.0)) {
          *(undefined1 *)(param_1 + 0xe32) = 3;
        }
      }
      fVar1 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
      *(float *)(param_1 + 0x77c) = fVar1;
      if ((((cVar2 == '\b') && ((uVar3 & 0x8000) == 0)) &&
          ((iVar8 = *(int *)(*(int *)(param_1 + 0x50) + 0xc),
           *(int *)(iVar8 + *(short *)(param_1 + 0x7aa) * 4) != 0 &&
           ((*(float *)(param_1 + 0x784) < fVar1 != (*(float *)(param_1 + 0x784) == fVar1) &&
            (DAT_00804cec != -1)))))) && (*(int *)(iVar8 + DAT_00804cec * 4) != 0)) {
        *(uint *)(param_1 + 0x7bc) = uVar3 | 0x8000;
      }
      if (((((cVar2 == '\b') || (cVar2 == '\x02')) || (cVar2 == '\0')) &&
          ((fVar1 = *(float *)(param_1 + 0x77c), !NAN(fVar1) && 2.0 < fVar1 != (fVar1 == 2.0) &&
           (*(float *)(param_1 + 0x90) < *(float *)(param_1 + 0x60) !=
            (*(float *)(param_1 + 0x90) == *(float *)(param_1 + 0x60)))))) &&
         (*(char *)(param_1 + 0x281) == '\0')) {
        *(undefined4 *)(param_1 + 0xd28) = 0;
        *(undefined4 *)(param_1 + 0xdac) = 0x3e4ccccd;
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        return;
      }
      if (cVar2 == '\x05') {
        if (((*(byte *)(param_1 + 0x281) & 1) == 0) &&
           (((uVar14 != 0 || (*(char *)(param_1 + 0x1078) == '\0')) ||
            (*(char *)(param_1 + 0xe32) != '\x03')))) {
LAB_00562ccf:
          if (((cVar2 != '\x04') && (cVar2 != '\x03')) ||
             (fVar1 = *(float *)(param_1 + 0x77c), NAN(fVar1) || 2.5 < fVar1 == (fVar1 == 2.5))) {
            if (((param_5 != 0) && (-1.25 < *(float *)(param_1 + 0x6c))) &&
               (((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\0' ||
                 ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) != 0)) &&
                ((((cVar2 == '\0' && ((*(uint *)(param_1 + 0x7bc) & 0x8000) == 0)) &&
                  (*(byte *)(param_1 + 0x7b9) < 2)) &&
                 ((DAT_00804cd8 != -1 &&
                  (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cd8 * 4) != 0)))))))
               ) {
              *(undefined4 *)(param_1 + 0x790) = 0;
              *(undefined4 *)(param_1 + 0x794) = 0;
              FUN_0049d9f0(param_1,0,*(undefined4 *)(param_1 + 0x1e0));
              return;
            }
            if (((((DAT_009505d0 != 0) && ((param_4 & 0x10) != 0)) &&
                 ((param_5 != 0 &&
                  ((-1.25 < *(float *)(param_1 + 0x6c) &&
                   ((*(uint *)(param_1 + 0x7bc) & 0x8000) == 0)))))) &&
                (((cVar2 == '\0' &&
                  ((*(char *)(param_1 + 0x7b9) == '\x02' ||
                   ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x98) & 0x20) != 0)))) ||
                 ((cVar2 == '\x01' || (cVar2 == '\x02')))))) &&
               (((DAT_00804ce0 != -1 &&
                 (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804ce0 * 4) != 0)) &&
                (iVar8 = FUN_005624d0(param_1,_DAT_00802da0), iVar8 != 0)))) {
              FUN_00548540(0,param_1,0,0);
              if ((*(char *)(param_1 + 0x7b8) != '\x01') && (*(char *)(param_1 + 0x7b8) != '\x02'))
              {
                return;
              }
              FUN_0062e650(param_1 + 8,0xffffffff);
              if (*(char *)(param_1 + 0x7b8) != '\x02') {
                return;
              }
              if ((*(uint *)(param_1 + 0x7bc) & 0x2000) != 0) {
                return;
              }
              *(short *)(param_1 + 0x27a) = *(short *)(param_1 + 0x27a) + -0x8000;
              *(short *)(param_1 + 0x58) = *(short *)(param_1 + 0x58) + -0x8000;
              *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
              return;
            }
            if (param_2 == 0) {
              return;
            }
            if ((param_4 & 8) == 0) {
              return;
            }
            if (*(char *)(param_1 + 0x7b8) != '\0') {
              return;
            }
            if (1 < *(byte *)(param_1 + 0x7b9)) {
              return;
            }
            if (*(float *)(param_1 + 0x6c) <= -1.25) {
              return;
            }
            if ((DAT_00802828 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802828)) {
              return;
            }
            iVar8 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
            if ((*(uint *)(iVar8 + 0x94) & 0x2000) != 0) {
              *(undefined4 *)(param_1 + 0xd64) = 0;
              *(undefined1 *)(param_1 + 0x7b5) = 0xff;
              *(undefined1 *)(param_1 + 0xe32) = 1;
              FUN_0058d480(param_1,1);
              return;
            }
            if (((param_4 & 0x110) == 0) && ((*(uint *)(iVar8 + 0x90) & 0x40400000) == 0)) {
              return;
            }
            if ((param_4 & 0x100) == 0) {
              if ((param_4 & 0x200) == 0) {
                if ((DAT_009505cc == 0) && (*(float *)(param_1 + 0x6c) <= 0.0)) {
                  *(undefined4 *)(param_1 + 0x6c) = 0;
                  goto LAB_005638c3;
                }
                uVar11 = *(undefined4 *)(iVar8 + 0x40);
              }
              else {
                uVar11 = *(undefined4 *)(iVar8 + 0x34);
              }
              uVar16 = 0;
            }
            else {
              uVar16 = 1;
              uVar11 = _DAT_00802d94;
            }
            FUN_00561ca0(param_1,uVar11,uVar16);
LAB_005638c3:
            if (((DAT_009505e8 != (code *)0x0) && (iVar8 = (*DAT_009505e8)(param_1), iVar8 != 0)) &&
               (iVar8 = FUN_0049d6d0(param_1), iVar8 != 0)) {
              return;
            }
            *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x4000;
            *(char *)(param_1 + 0x7b9) = *(char *)(param_1 + 0x7b9) + '\x01';
            if (((param_4 & 0x110) == 0) &&
               (uVar14 = *(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90),
               (uVar14 & 0x400000) == 0)) {
              if ((uVar14 & 0x40000000) != 0) {
                *(undefined1 *)(param_1 + 0x7b8) = 8;
                sVar7 = DAT_00804ce8;
                iVar8 = (int)DAT_00804ce8;
                *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffff7fff;
                *(short *)(param_1 + 0x7aa) = sVar7;
                fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar8,0,0,1);
                *(float *)(param_1 + 0x784) = (float)fVar15;
              }
            }
            else {
              *(undefined1 *)(param_1 + 0x7b8) = 0;
              if (((DAT_00804bf8 == -1) ||
                  (sVar7 = DAT_00804bf8,
                  *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804bf8 * 4) == 0)) &&
                 (((((DAT_00955584 == (code *)0x0 || (iVar8 = (*DAT_00955584)(param_1), iVar8 == 0))
                    || (DAT_00804cfc == -1)) ||
                   (sVar7 = DAT_00804cfc,
                   *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cfc * 4) == 0)) &&
                  ((DAT_00804bf4 == -1 ||
                   (sVar7 = DAT_00804bf4,
                   *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804bf4 * 4) == 0))))))
              {
                sVar7 = DAT_00804bec;
              }
              *(short *)(param_1 + 0x7aa) = sVar7;
            }
            *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x100000;
            *(undefined4 *)(param_1 + 0x77c) = 0;
            FUN_00547f30(param_1,1);
            if ((param_4 & 0x10) != 0) {
              return;
            }
            *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x1000;
            return;
          }
        }
      }
      else if ((*(char *)(param_1 + 0x281) == '\0') || (*(float *)(param_1 + 0x77c) < 0.1))
      goto LAB_00562ccf;
      bVar4 = false;
      if (uVar14 != 0) {
        *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) | 0x800;
      }
      if (((((param_3 != 0) && ((*(uint *)(param_1 + 0xe20) & 0x100000) == 0)) && (cVar2 != '\x03'))
          && ((cVar2 != '\x04' && (cVar2 != '\x05')))) && (cVar2 != '\b')) {
        if ((((cVar2 == '\x01') && (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) &&
            (((*(uint *)(param_1 + 0xe20) & 0x200000) != 0 &&
             (uVar14 = FUN_00550040(*(undefined2 *)(param_1 + 0x5a),*(undefined2 *)(param_1 + 0xe0c)
                                   ),
             0x6aaa < (int)((uVar14 ^ (int)uVar14 >> 0x1f) - ((int)uVar14 >> 0x1f)))))) ||
           ((((*(char *)(param_1 + 0x7b8) == '\x02' &&
              (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28))) &&
             ((*(uint *)(param_1 + 0xe20) & 0x200000) != 0)) &&
            (uVar14 = FUN_00550040(*(undefined2 *)(param_1 + 0x5a),*(undefined2 *)(param_1 + 0xe0c))
            , (int)((uVar14 ^ (int)uVar14 >> 0x1f) - ((int)uVar14 >> 0x1f)) < 0x1555)))) {
          local_28 = 1;
        }
        bVar4 = true;
      }
      cVar2 = *(char *)(param_1 + 0x7b8);
      local_30 = 0;
      if (cVar2 == '\x03') {
        if (((DAT_0080288c == -1) || (DAT_00804cdc == -1)) ||
           (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cdc * 4) == 0)) {
          if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0) {
            FUN_0058e4e0(param_1,*(undefined4 *)(param_1 + 0x790),_DAT_00804dc8,_DAT_00804dc8);
          }
          cVar2 = *(char *)(param_1 + 0x7b8);
LAB_005635da:
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          *(undefined4 *)(param_1 + 0xd28) = 0x3e4ccccd;
          if (cVar2 == '\x05') {
            *(undefined4 *)(param_1 + 0xd68) = _DAT_009505c8;
          }
        }
        else {
          FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f19999a,0);
          *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_0080288c;
          iVar8 = (int)DAT_00804cdc;
          *(short *)(param_1 + 0x7aa) = DAT_00804cdc;
          fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar8,0,0,1);
          *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
          *(float *)(param_1 + 0x77c) = (float)fVar15;
          *(undefined4 *)(param_1 + 0xd28) = 0;
          if (!bVar4) {
            FUN_0062e650(param_1 + 8,0xffffffff);
          }
          local_30 = 1;
          if (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0) &&
             (fVar15 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                             (int)*(short *)(param_1 + 0x7aa),0),
             fVar15 == (float10)0.0)) {
            FUN_0058e4e0(param_1,*(undefined4 *)(param_1 + 0x790),_DAT_00804dc8,_DAT_00804dc8);
          }
        }
      }
      else if (((cVar2 == '\x04') && (_DAT_00802890 != -1)) &&
              ((DAT_00804ce4 != -1 &&
               (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804ce4 * 4) != 0)))) {
        FUN_00549de0(PTR_DAT_008021b4,0x3f000000,0,param_1 + 0x80);
        FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f400000,0);
        *(char *)(param_1 + 0xe40) = (char)param_7;
        if (DAT_009505e4 != (code *)0x0) {
          uVar5 = (*DAT_009505e4)(param_1,param_7);
          *(undefined1 *)(param_1 + 0xe40) = uVar5;
        }
        *(undefined1 *)(param_1 + 0x7b5) = DAT_00802890;
        iVar8 = (int)DAT_00804ce4;
        *(short *)(param_1 + 0x7aa) = DAT_00804ce4;
        fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar8,0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar15;
        if ((float)fVar15 <= 0.0) {
          *(undefined4 *)(param_1 + 0x77c) = 0x3f400000;
        }
        *(undefined4 *)(param_1 + 0xd28) = 0;
        if (!bVar4) {
          FUN_0062e650(param_1 + 8,0xffffffff);
          FUN_0062e690(param_1 + 2000,0xffffffff);
        }
        local_30 = 2;
      }
      else if (((cVar2 == '\x02') && (DAT_00802888 != -1)) &&
              ((DAT_00804c08 != -1 &&
               (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c08 * 4) != 0)))) {
        if ((*(uint *)(param_1 + 0x7bc) & 0x2000) == 0) {
          *(short *)(param_1 + 0x27a) = *(short *)(param_1 + 0x27a) + -0x8000;
          *(short *)(param_1 + 0x58) = *(short *)(param_1 + 0x58) + -0x8000;
          *(short *)(param_1 + 0x5a) = *(short *)(param_1 + 0x5a) + -0x8000;
          if (!bVar4) {
            FUN_0062e650(param_1 + 8,0xffffffff);
          }
        }
        *(undefined4 *)(param_1 + 0xd28) = 0;
        if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) == 0.0) {
          *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802888;
          if ((((*(uint *)(param_1 + 0x7bc) & 0x2000) == 0) || (DAT_00804c7c == -1)) ||
             (sVar7 = DAT_00804c7c,
             *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c7c * 4) == 0)) {
            sVar7 = DAT_00804c08;
          }
          *(short *)(param_1 + 0x7aa) = sVar7;
          fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar7,0,0,1);
          *(float *)(param_1 + 0x77c) = (float)fVar15;
        }
        else {
LAB_00563469:
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        }
      }
      else if ((((cVar2 == '\x01') && (DAT_00802884 != -1)) && (DAT_00804c7c != -1)) &&
              (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c7c * 4) != 0)) {
        *(undefined4 *)(param_1 + 0xd28) = 0;
        if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) != 0.0) goto LAB_00563469;
        *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802884;
        sVar7 = DAT_00804c7c;
LAB_005631c6:
        *(short *)(param_1 + 0x7aa) = sVar7;
LAB_005631cd:
        fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                       (int)*(short *)(param_1 + 0x7aa),0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar15;
LAB_005635be:
        if (!bVar4) {
          FUN_0062e650(param_1 + 8,0xffffffff);
        }
      }
      else if (((cVar2 == '\b') && (DAT_00802898 != -1)) &&
              (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cf0 * 4) != 0)) {
        FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3ecccccd,0);
        *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802898;
        *(undefined1 *)(param_1 + 0x7b3) = 0;
        iVar8 = (int)DAT_00804cf0;
        *(short *)(param_1 + 0x7aa) = DAT_00804cf0;
        fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar8,0,0,1);
        *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
        *(float *)(param_1 + 0x77c) = (float)fVar15;
        *(undefined4 *)(param_1 + 0xd28) = 0;
        if (!bVar4) {
          FUN_0062e650(param_1 + 8,0xffffffff);
        }
        local_30 = 4;
        *(undefined1 *)(param_1 + 0x7b1) = 0;
        if ((param_3 == 0) || ((*(uint *)(param_1 + 0xe20) & 0x100000) != 0)) {
          if ((param_6 != 0) &&
             ((DAT_00804cf4 != -1 &&
              (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cf4 * 4) != 0)))) {
            *(undefined1 *)(param_1 + 0x7b1) = 2;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x7b1) = 1;
        }
      }
      else {
        if (cVar2 == '\0') {
          if (((1 < *(byte *)(param_1 + 0x7b9)) && (DAT_00802880 != -1)) &&
             (((uVar14 = *(uint *)(param_1 + 0x7bc) >> 0xe & 1, uVar14 == 0 &&
               ((DAT_00804bfc != -1 &&
                (piVar13 = (int *)(*(int *)(param_1 + 0x50) + 0xc),
                *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804bfc * 4) != 0)))) ||
              ((uVar14 != 0 &&
               (((DAT_00804bfc != -1 &&
                 (piVar13 = (int *)(*(int *)(param_1 + 0x50) + 0xc),
                 *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804bfc * 4) != 0)) ||
                ((DAT_00804c00 != -1 &&
                 (piVar13 = (int *)(*(int *)(param_1 + 0x50) + 0xc),
                 *(int *)(*piVar13 + DAT_00804c00 * 4) != 0)))))))))) {
            *(undefined4 *)(param_1 + 0xd28) = 0;
            if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) != 0.0) goto LAB_00563469;
            if (*(float *)(param_1 + 0xdac) < 0.2) {
              *(undefined1 *)(param_1 + 0x7b5) = (undefined1)DAT_00802880;
              if (((uVar14 == 0) || (DAT_00804c00 == -1)) ||
                 (*(int *)(*piVar13 + DAT_00804c00 * 4) == 0)) {
                sVar7 = DAT_00804bfc;
                if (((DAT_00955584 == (code *)0x0) ||
                    (iVar8 = (*DAT_00955584)(param_1), sVar7 = DAT_00804bfc, iVar8 == 0)) ||
                   ((DAT_00804d04 == -1 ||
                    (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804d04 * 4) == 0))))
                goto LAB_005631c6;
                *(short *)(param_1 + 0x7aa) = DAT_00804d04;
              }
              else {
                *(short *)(param_1 + 0x7aa) = DAT_00804c00;
              }
              goto LAB_005631cd;
            }
            FUN_005621a0(param_1,0xffffffff);
            goto LAB_005635fb;
          }
        }
        else if (((cVar2 != '\x06') && (cVar2 != '\a')) && (cVar2 != '\t')) goto LAB_005635da;
        if (((DAT_0080287c == -1) || (DAT_00804bf0 == -1)) ||
           ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804bf0 * 4) == 0 ||
            (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) != 0.0)))) goto LAB_005635da;
        if (*(float *)(param_1 + 0xdac) < 0.2) {
          *(char *)(param_1 + 0x7b5) = (char)DAT_0080287c;
          sVar7 = DAT_00804bf0;
          if ((((DAT_00955584 != (code *)0x0) &&
               (iVar8 = (*DAT_00955584)(param_1), sVar7 = DAT_00804bf0, iVar8 != 0)) &&
              (DAT_00804d00 != -1)) &&
             (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804d00 * 4) != 0)) {
            sVar7 = DAT_00804d00;
          }
          *(short *)(param_1 + 0x7aa) = sVar7;
          if (((DAT_00950c4c != (code *)0x0) && (iVar8 = (*DAT_00950c4c)(param_1), iVar8 != 0)) &&
             ((DAT_00804cd0 != -1 &&
              (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cd0 * 4) != 0)))) {
            *(short *)(param_1 + 0x7aa) = DAT_00804cd0;
          }
          fVar15 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),
                                         (int)*(short *)(param_1 + 0x7aa),0,0,1);
          *(float *)(param_1 + 0x77c) = (float)fVar15;
          if (*(byte *)(param_1 + 0x7b9) < 2) {
            uVar11 = 0x3e4ccccd;
          }
          else {
            uVar11 = 0;
          }
          *(undefined4 *)(param_1 + 0xd28) = uVar11;
          goto LAB_005635be;
        }
        FUN_005621a0(param_1,0xffffffff);
      }
LAB_005635fb:
      FUN_00548020(param_1,local_30,0);
      if (!bVar4) {
        return;
      }
      FUN_0055d8c0(param_1);
    }
  }
  else {
    iVar9 = (int)cVar2;
    if (((iVar9 == DAT_0080287c) || (iVar9 == DAT_00802880)) ||
       ((iVar9 == DAT_00802884 || (iVar9 == DAT_00802888)))) {
LAB_0056269d:
      if (iVar9 == DAT_0080288c) goto LAB_005626a5;
LAB_0056274f:
      if (iVar9 == DAT_00802898) {
        fVar15 = (float10)FUN_0062f220(*(undefined4 *)(param_1 + 0x50),
                                       (int)*(short *)(param_1 + 0x7aa));
        fVar1 = (float)fVar15;
        if (((0.0 < fVar1) &&
            (pfVar10 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
            pfVar10 != (float *)0x0)) && (fVar1 < *pfVar10 != (fVar1 == *pfVar10))) {
          *(undefined1 *)(param_1 + 0x7b3) = 1;
        }
      }
    }
    else {
      if (iVar9 != DAT_0080288c) {
        if ((iVar9 != _DAT_00802890) && (iVar9 != DAT_00802898)) goto LAB_00562b11;
        goto LAB_0056269d;
      }
LAB_005626a5:
      if ((*(byte *)(param_1 + 0x7bc) & 0x40) != 0) goto LAB_0056274f;
      fVar15 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),
                                     (int)*(short *)(param_1 + 0x7aa),0);
      fVar1 = (float)fVar15;
      if (((0.0 < fVar1) &&
          (pfVar10 = (float *)FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0),
          pfVar10 != (float *)0x0)) && (fVar1 < *pfVar10 != (fVar1 == *pfVar10))) {
        if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0) {
          FUN_0058e4e0(param_1,*(undefined4 *)(param_1 + 0x790),_DAT_00804dc8,_DAT_00804dc8);
        }
        else {
          FUN_0058e360(param_1,1);
        }
      }
    }
    iVar9 = (int)*(char *)(param_1 + 0x7b5);
    if ((((iVar9 != DAT_00802898) || (*(char *)(param_1 + 0x7b3) != '\x01')) ||
        (*(char *)(param_1 + 0x7b1) != '\x01')) &&
       ((((param_2 == 0 || ((DAT_0080288c != -1 && (iVar9 == DAT_0080288c)))) ||
         ((_DAT_00802890 != -1 && (iVar9 == _DAT_00802890)))) ||
        ((DAT_00802898 != -1 && (iVar9 == DAT_00802898)))))) {
      if (((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) ||
           ((iVar9 != DAT_0080287c || (sVar7 = *(short *)(param_1 + 0x7aa), sVar7 == -1)))) ||
          ((sVar7 != DAT_00804c10 && (sVar7 != DAT_00804c14)))) &&
         ((((DAT_0080288c == -1 || (iVar9 != DAT_0080288c)) &&
           (((_DAT_00802890 == -1 || (iVar9 != _DAT_00802890)) &&
            (((DAT_00802898 == -1 || (iVar9 != DAT_00802898)) ||
             (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x80000) != 0 &&
              ((*(char *)(param_1 + 0x7b3) != '\x01' || (*(char *)(param_1 + 0x7b1) != '\0')))))))))
           ) && ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28) &&
                 ((*(uint *)(param_1 + 0xe24) & 0x800) == 0)))))) {
LAB_00562983:
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        return;
      }
      if (iVar9 == DAT_00802898) {
        if (param_2 == 0) {
          if (((param_5 != 0) && (DAT_00804cf4 != -1)) &&
             (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cf4 * 4) != 0)) {
            *(undefined1 *)(param_1 + 0x7b1) = 2;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x7b1) = 1;
        }
      }
      fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
      *(float *)(param_1 + 0x77c) = fVar1;
      if (fVar1 < 0.0 == (fVar1 == 0.0)) {
        if (iVar9 != _DAT_00802890) {
          return;
        }
        iVar9 = FUN_0062c350(0x41c80000,_DAT_00925018);
        FUN_00562010(param_1,&local_24,&local_18);
        uVar11 = FUN_0062c350(0x41a00000,_DAT_00925018,0,0);
        FUN_0062c680(*(undefined4 *)(iVar8 + 0x134),param_7,&local_24,uVar11);
        if (iVar9 < 1) {
          return;
        }
        do {
          iVar12 = FUN_0054fa60();
          fVar1 = (float)iVar12 * 1.5259022e-05;
          local_c = fVar1 * (local_18 - local_24) + local_24;
          local_8 = local_20 + fVar1 * (local_14 - local_20);
          local_4 = local_1c + (local_10 - local_1c) * fVar1;
          FUN_0062c680(*(undefined4 *)(iVar8 + 0x134),param_7,&local_c,1,0,0);
          iVar9 = iVar9 + -1;
        } while (0 < iVar9);
        return;
      }
      if (DAT_009505d8 != (code *)0x0) {
        (*DAT_009505d8)(param_1);
      }
      if (*(char *)(param_1 + 0x7b5) != DAT_00802898) {
        if (((DAT_0080288c != -1) && (*(char *)(param_1 + 0x7b5) == DAT_0080288c)) &&
           (((*(byte *)(param_1 + 0x7bc) & 0x40) == 0 &&
            ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) != 0)))) {
          FUN_0058e360(param_1,1);
        }
        if (((*(char *)(param_1 + 0x7b5) == DAT_0080288c) ||
            (*(char *)(param_1 + 0x7b5) == _DAT_00802890)) && (param_6 != 0)) {
          FUN_0058e3b0(param_1);
          return;
        }
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        return;
      }
      if (*(char *)(param_1 + 0x7b1) == '\x02') {
        *(undefined1 *)(param_1 + 0xe3b) = 0;
        uVar6 = FUN_0054b3d0(param_1,*(undefined4 *)(param_1 + 0xca4));
        *(undefined2 *)(param_1 + 0x27a) = uVar6;
        *(undefined2 *)(param_1 + 0x5a) = uVar6;
        *(undefined2 *)(param_1 + 0x58) = uVar6;
        FUN_004b11b0(param_1,(int)DAT_00804cf4);
        *(undefined4 *)(param_1 + 0xd58) = 0x3dcccccd;
        return;
      }
      if (*(char *)(param_1 + 0x7b1) != '\x01') goto LAB_00562983;
    }
  }
  if ((DAT_009505d4 != (code *)0x0) && (iVar8 = (*DAT_009505d4)(param_1), iVar8 != 0)) {
    return;
  }
  if ((DAT_00802868 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802868)) {
    if ((DAT_00802864 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802864)) {
      FUN_0058d930(param_1,0);
    }
  }
  else {
    FUN_0058d480(param_1,0);
  }
  if (*(char *)(param_1 + 0x281) != '\0') {
    *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) | 0x20000000;
  }
  if (*(float *)(param_1 + 0xd28) <= 0.0) {
    *(undefined1 *)(param_1 + 0x7b9) = 0;
  }
  if ((local_2c == 0) ||
     (((*(float *)(param_1 + 0xd48) <= 0.0 && (local_28 != 1)) &&
      ((*(uint *)(param_1 + 0xeec) & 0x100) == 0)))) {
    if ((param_4 & 4) == 0) {
      *(undefined1 *)(param_1 + 0x7b8) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x7b8) = 5;
    }
    sVar7 = DAT_00804bec;
    if (((DAT_00955584 != (code *)0x0) &&
        (iVar8 = (*DAT_00955584)(param_1), sVar7 = DAT_00804bec, iVar8 != 0)) &&
       ((DAT_00804cf8 != -1 &&
        (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cf8 * 4) != 0)))) {
      sVar7 = DAT_00804cf8;
    }
    *(short *)(param_1 + 0x7aa) = sVar7;
    if (((DAT_00950c4c != (code *)0x0) && (iVar8 = (*DAT_00950c4c)(param_1), iVar8 != 0)) &&
       ((DAT_00804cd0 != -1 &&
        (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cd0 * 4) != 0)))) {
      *(short *)(param_1 + 0x7aa) = DAT_00804cd0;
    }
    *(undefined4 *)(param_1 + 0x78c) = *(undefined4 *)(param_1 + 0x17c);
    if ((param_4 & 1) == 0) {
      *(undefined1 *)(param_1 + 0x7b9) = 0;
    }
    *(char *)(param_1 + 0x7b9) = *(char *)(param_1 + 0x7b9) + '\x01';
    if (*(byte *)(param_1 + 0x7b9) < 2) {
      if (((param_4 & 0x40) != 0) &&
         ((*(short *)(param_1 + 0x7aa) == -1 ||
          (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0
          )))) {
        *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c0c;
      }
      *(undefined4 *)(param_1 + 0x6c) =
           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x2c);
      if (*(char *)(param_1 + 0x7b8) != '\x05') {
        FUN_0062e650(param_1 + 8,(int)*(short *)(param_1 + 0x7aa));
      }
      if ((param_4 & 0x101) != 0x100) goto LAB_00563da1;
    }
    else {
      if (((((DAT_00955584 == (code *)0x0) || (iVar8 = (*DAT_00955584)(param_1), iVar8 == 0)) ||
           (DAT_00804cfc == -1)) ||
          (sVar7 = DAT_00804cfc,
          *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804cfc * 4) == 0)) &&
         ((DAT_00804bf4 == -1 ||
          (sVar7 = DAT_00804bf4,
          *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804bf4 * 4) == 0)))) {
        sVar7 = DAT_00804bec;
      }
      *(short *)(param_1 + 0x7aa) = sVar7;
      *(undefined4 *)(param_1 + 0x6c) =
           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x38);
      FUN_0062e650(param_1 + 8,(int)sVar7);
      *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffbfff;
      if ((param_4 & 0x100) == 0) goto LAB_00563da1;
    }
    FUN_00561ca0(param_1,_DAT_00802d94,1);
  }
  else {
    if ((local_2c == 1) && (iVar8 = FUN_00562310(param_1), iVar8 != 0)) {
      return;
    }
    *(undefined1 *)(param_1 + 0x7b8) = 1;
    iVar8 = (int)DAT_00804c78;
    *(short *)(param_1 + 0x7aa) = DAT_00804c78;
    FUN_0062e650(param_1 + 8,iVar8);
    *(undefined4 *)(param_1 + 0x6c) =
         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x38);
  }
LAB_00563da1:
  uVar5 = (undefined1)DAT_00802838;
  *(undefined4 *)(param_1 + 0x77c) = 0;
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffeefff;
  *(undefined1 *)(param_1 + 0x7b5) = uVar5;
  if (((*(char *)(param_1 + 0x7b8) == '\x01') && (DAT_00804c78 != -1)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c78 * 4) != 0)) {
    *(short *)(param_1 + 0x7aa) = DAT_00804c78;
  }
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x100000;
  *(undefined4 *)(param_1 + 0xd48) = 0;
  *(undefined1 *)(param_1 + 0x281) = 0;
  *(undefined2 *)(param_1 + 0x1050) = 0;
  if ((param_4 & 4) != 0) {
    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x48);
    *(float *)(param_1 + 0xd64) = fVar1;
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
      *(float *)(param_1 + 0xd64) = fVar1 * 1.5;
    }
    *(undefined1 *)(param_1 + 0xe32) = 1;
  }
  *(undefined4 *)(param_1 + 0xd2c) = 0;
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffff7fff;
  *(undefined4 *)(param_1 + 0xd1c) = 0;
  FUN_00547f30(param_1,1 < *(byte *)(param_1 + 0x7b9));
  if ((*(char *)(param_1 + 0x283) == '\x01') &&
     (*(float *)(param_1 + 0x17c) < *(float *)(param_1 + 0x220))) {
    FUN_0042f950(param_1,param_1 + 0x80);
    return;
  }
  return;
}

