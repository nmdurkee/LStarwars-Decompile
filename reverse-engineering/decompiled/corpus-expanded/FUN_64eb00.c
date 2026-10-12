/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64eb00; label: FUN_0064eb00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064eb00(float param_1)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  undefined4 *puVar4;
  float fVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 extraout_ECX;
  undefined4 *_Dst;
  int iVar8;
  bool bVar9;
  float *pfVar10;
  float local_70;
  float local_6c;
  int local_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float afStack_4c [4];
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  _DAT_02920a90 = _DAT_02920a90 + param_1;
  if (900.0 < _DAT_02920a90) {
    FUN_0064a850();
  }
  FUN_0064d9d0();
  DAT_0291f780 = 0;
  FUN_0064daa0(param_1);
  local_68 = 0;
  _Dst = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if ((*(byte *)(_Dst + 0x51) & 1) != 0) {
        pfVar10 = (float *)(_Dst + 0xc);
        _Dst[0x10] = *_Dst;
        _Dst[0x11] = _Dst[1];
        _Dst[0x12] = _Dst[2];
        _Dst[0x13] = _Dst[3];
        _Dst[0x14] = _Dst[4];
        _Dst[0x15] = _Dst[5];
        _Dst[0x16] = _Dst[6];
        _Dst[0x17] = _Dst[7];
        _Dst[0x18] = _Dst[8];
        _Dst[0x19] = _Dst[9];
        _Dst[0x1a] = _Dst[10];
        _Dst[0x1b] = _Dst[0xb];
        _Dst[0x1c] = *pfVar10;
        _Dst[0x1d] = _Dst[0xd];
        _Dst[0x1e] = _Dst[0xe];
        _Dst[0x1f] = _Dst[0xf];
        uVar7 = _Dst[0x51];
        _Dst[0x3f] = param_1 + (float)_Dst[0x3f];
        if ((uVar7 & 2) == 0) {
          local_70 = param_1;
          if ((_Dst[0x42] & 0x400) == 0) {
            if ((float)_Dst[0x3d] < param_1 != ((float)_Dst[0x3d] == param_1)) {
              if ((float)_Dst[0x37] <= (float)_Dst[0x38]) {
                uVar7 = uVar7 & 0xffffff9f;
              }
              else {
                uVar7 = uVar7 & 0xffffffbf | 0x20;
              }
              _Dst[0x51] = uVar7;
              if ((uVar7 & 4) != 0) {
                if ((((_Dst[0x42] & 0x80000) != 0) && ((uVar7 & 0x10) != 0)) && (DAT_0291f780 < 4))
                {
                  (&DAT_0292095c)[DAT_0291f780] = *(undefined2 *)(_Dst + 0x80);
                  DAT_0291f780 = DAT_0291f780 + 1;
                }
                if ((_Dst[0x42] & 0x100) == 0) {
                  local_70 = param_1 - (float)_Dst[0x3d];
                  pfVar1 = (float *)(_Dst + 0x20);
                  *pfVar10 = (float)_Dst[0x29];
                  _Dst[0xd] = _Dst[0x2a];
                  _Dst[0xe] = _Dst[0x2b];
                  FUN_006781e0(_Dst + 0x2c,pfVar1,pfVar1);
                  if ((*(byte *)(_Dst + 0x42) & 0x80) != 0) {
                    FUN_0064a740(_Dst);
                  }
                  if ((_Dst[0x42] & 0x100000) != 0) {
                    FUN_0064a7c0(_Dst);
                  }
                  fVar2 = *pfVar1 * (float)_Dst[0x3b];
                  *pfVar1 = fVar2;
                  fVar5 = (float)_Dst[0x22] * (float)_Dst[0x3b];
                  _Dst[0x22] = fVar5;
                  local_6c = fVar5;
                  if (0.5 < (float)_Dst[0x2d]) {
                    local_6c = (float)_Dst[0x21] * (float)_Dst[0x3b];
                    _Dst[0x21] = local_6c;
                    if (_DAT_008102e0 <= fVar5 * fVar5 + local_6c * local_6c + fVar2 * fVar2) {
                      bVar9 = (_Dst[0x51] & 0x100) == 0;
                    }
                    else {
                      _Dst[0x51] = _Dst[0x51] | 2;
                      if ((code *)_Dst[0x72] != (code *)0x0) {
                        (*(code *)_Dst[0x72])(_Dst);
                      }
                      if (((*(byte *)(_Dst + 0x42) & 1) != 0) || ((_Dst[0x51] & 0x10) != 0))
                      goto LAB_0064edc1;
                      bVar9 = (_Dst[0x51] & 0x100) == 0;
                    }
                    goto LAB_0064edbf;
                  }
                }
                else {
                  _Dst[0x51] = _Dst[0x51] | 2;
                  if ((code *)_Dst[0x72] != (code *)0x0) {
                    (*(code *)_Dst[0x72])(_Dst);
                  }
                  if ((*(byte *)(_Dst + 0x42) & 1) == 0) {
                    bVar9 = (*(byte *)(_Dst + 0x51) & 0x10) == 0;
LAB_0064edbf:
                    if (bVar9) goto LAB_0064edda;
                  }
LAB_0064edc1:
                  FUN_0064ac90(_Dst,0);
                }
LAB_0064edda:
                if (_Dst[0x7c] != -1) {
                  local_6c = -NAN;
                  FUN_006424c0();
                  FUN_005b6490(extraout_ECX,_Dst + 0x2c);
                  FUN_00690490(&local_6c,_Dst[0x7c],_Dst + 0x29,0,0,1,_Dst[0x7f]);
                  FUN_00655ad0(local_6c,afStack_4c + 3);
                }
                if (_Dst[0x7e] != -1) {
                  FUN_0064b370(_Dst[0x7e],_Dst + 0x29,1);
                }
                if ((code *)_Dst[0x6e] != (code *)0x0) {
                  (*(code *)_Dst[0x6e])(_Dst);
                }
              }
              if (DAT_008102ec != 0) {
                FUN_00642570(_Dst,_DAT_008102dc);
              }
              if (((*(byte *)(_Dst + 0x51) & 4) != 0) && ((float)_Dst[0x3d] <= local_70)) {
                local_70 = 0.0;
              }
            }
            _Dst[0x3d] = (float)_Dst[0x3d] - local_70;
          }
          if (0.0 < local_70) {
            if ((code *)_Dst[0x6c] == (code *)0x0) {
              *pfVar10 = (float)_Dst[0x20] * local_70 + *pfVar10;
              _Dst[0xd] = (float)_Dst[0x21] * local_70 + (float)_Dst[0xd];
              _Dst[0x21] = (float)_Dst[0x3a] * local_70 + (float)_Dst[0x21];
              _Dst[0xe] = local_70 * (float)_Dst[0x22] + (float)_Dst[0xe];
            }
            else {
              (*(code *)_Dst[0x6c])(_Dst,local_70);
            }
          }
          if ((((_Dst[0x51] & 0x100) == 0) && ((float)_Dst[0x3c] != 2e+06)) &&
             ((float)_Dst[0xd] < (float)_Dst[0x3c])) {
            _Dst[0x51] = _Dst[0x51] | 0x100;
          }
          uVar7 = (uint)_Dst[0x51] >> 5 & 3;
          _Dst[0x23] = *pfVar10 - (float)_Dst[0x37];
          _Dst[0x26] = (float)_Dst[0x37] + *pfVar10;
          _Dst[0x24] = (float)_Dst[0xd] - (float)_Dst[0x37];
          _Dst[0x27] = (float)_Dst[0xd] + (float)_Dst[0x37];
          _Dst[0x25] = (float)_Dst[0xe] - (float)_Dst[0x37];
          _Dst[0x28] = (float)_Dst[0x37] + (float)_Dst[0xe];
          if (uVar7 == 1) {
            fVar2 = (float)_Dst[0x3e];
            _Dst[0x3e] = fVar2 + param_1;
            local_6c = ((fVar2 + param_1) / _DAT_008102e4) * (float)_Dst[0x37];
            _Dst[0x38] = local_6c;
            if ((float)_Dst[0x37] < local_6c) {
              fVar2 = (float)_Dst[0x37];
              _Dst[0x51] = _Dst[0x51] & 0xffffff9f;
LAB_0064f075:
              _Dst[0x38] = fVar2;
            }
          }
          else if (uVar7 == 2) {
            local_6c = (float)_Dst[0x3e] - param_1;
            _Dst[0x3e] = local_6c;
            if (0.0 < local_6c) {
              fVar2 = (local_6c / _DAT_008102e4) * (float)_Dst[0x37];
              goto LAB_0064f075;
            }
            FUN_0064ac90(_Dst,0);
          }
          if ((*(byte *)(_Dst + 0x42) & 0x80) != 0) {
            iVar8 = 0;
            do {
              uVar6 = FUN_006e6b90();
              cVar3 = *(char *)((int)_Dst + iVar8 + 0x142);
              if (cVar3 == '\x01') {
                FUN_005b4dd0(_Dst,uVar6);
              }
              else if (cVar3 == '\x02') {
                FUN_005b5060(_Dst,uVar6);
              }
              else if (cVar3 == '\x03') {
                FUN_005b5240(_Dst,uVar6);
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 2);
          }
          if ((_Dst[0x42] & 0x100000) != 0) {
            local_6c = (float)_Dst[0x49];
            if (local_6c != 0.0) {
              uVar6 = FUN_006e6b90();
              FUN_005b4dd0(_Dst,uVar6);
            }
            local_6c = (float)_Dst[0x4a];
            if (local_6c != 0.0) {
              uVar6 = FUN_006e6b90();
              FUN_005b5060(_Dst,uVar6);
            }
            local_6c = (float)_Dst[0x4b];
            if (local_6c != 0.0) {
              uVar6 = FUN_006e6b90();
              FUN_005b5240(_Dst,uVar6);
            }
          }
          if ((_Dst[0x42] & 0x800) != 0) {
            fStack_58 = -(float)_Dst[0x20];
            fStack_54 = -(float)_Dst[0x21];
            fStack_50 = -(float)_Dst[0x22];
            afStack_4c[3] = (float)_DAT_008065c0;
            uStack_3c = _DAT_008065c4;
            uStack_38 = _DAT_008065c8;
            uStack_34 = _DAT_008065cc;
            uStack_30 = _DAT_008065d0;
            uStack_2c = _DAT_008065d4;
            uStack_28 = _DAT_008065d8;
            uStack_24 = _DAT_008065dc;
            uStack_20 = _DAT_008065e0;
            uStack_1c = _DAT_008065e4;
            uStack_18 = _DAT_008065e8;
            uStack_14 = _DAT_008065ec;
            uStack_10 = _DAT_008065f0;
            uStack_c = _DAT_008065f4;
            uStack_8 = _DAT_008065f8;
            uStack_4 = _DAT_008065fc;
            FUN_005b6a80(afStack_4c + 3,&fStack_58);
            FUN_004ef660(_Dst,afStack_4c + 3,0x30);
          }
        }
        if ((*(byte *)(_Dst + 0x51) & 1) != 0) {
          if (((*(byte *)(_Dst + 0x42) & 2) != 0) && ((code *)_Dst[0x6f] != (code *)0x0)) {
            (*(code *)_Dst[0x6f])(_Dst);
          }
          if ((*(byte *)(_Dst + 0x51) & 1) != 0) {
            if ((code *)_Dst[0x71] != (code *)0x0) {
              (*(code *)_Dst[0x71])(_Dst);
            }
            if (0.0 < (float)_Dst[0x40]) {
              local_6c = (float)_Dst[0x40] - param_1;
              _Dst[0x40] = local_6c;
              if (local_6c < 0.0 != (local_6c == 0.0)) {
                FUN_0064ac90(_Dst,0);
              }
            }
          }
        }
        if (((_Dst[0x42] & 0x20000) != 0) && (_Dst[0x76] != 0)) {
          afStack_4c[3] = (float)_DAT_008065c0;
          uStack_3c = _DAT_008065c4;
          uStack_38 = _DAT_008065c8;
          uStack_34 = _DAT_008065cc;
          uStack_30 = _DAT_008065d0;
          uStack_2c = _DAT_008065d4;
          uStack_28 = _DAT_008065d8;
          uStack_24 = _DAT_008065dc;
          uStack_20 = _DAT_008065e0;
          uStack_1c = _DAT_008065e4;
          uStack_18 = _DAT_008065e8;
          uStack_14 = _DAT_008065ec;
          uStack_10 = _DAT_008065f0;
          uStack_c = _DAT_008065f4;
          uStack_8 = _DAT_008065f8;
          uStack_4 = _DAT_008065fc;
          fStack_64 = -(float)_Dst[0x20];
          fStack_60 = -(float)_Dst[0x21];
          fStack_5c = -(float)_Dst[0x22];
          FUN_005b6a30(afStack_4c + 3,&fStack_64);
          FUN_00655ad0(*(undefined4 *)_Dst[0x76],afStack_4c + 3);
          FUN_00655940(*(undefined4 *)_Dst[0x76],*pfVar10,_Dst[0xd],_Dst[0xe]);
          if ((((_Dst[0x42] & 0x200000) != 0) && ((*(byte *)(_Dst + 0x51) & 2) != 0)) ||
             ((_Dst[0x42] & 0x1000) != 0)) {
            FUN_006552c0(_Dst[0x76]);
          }
        }
        if (param_1 != 0.0) {
          uVar7 = _Dst[0x42];
          if (((((uVar7 & 0x40000) != 0) && (iVar8 = _Dst[0x78], iVar8 != -1)) &&
              (((uVar7 & 0x200000) == 0 || ((*(byte *)(_Dst + 0x51) & 2) == 0)))) &&
             ((uVar7 & 0x1000) == 0)) {
            uVar6 = FUN_006e6b90(param_1,0,0,0,_Dst[0x7f]);
            FUN_00684d30(iVar8,pfVar10,uVar6);
          }
          uVar7 = _Dst[0x42];
          if (((((uVar7 & 0x40000) != 0) && (iVar8 = _Dst[0x79], iVar8 != -1)) &&
              (((uVar7 & 0x200000) == 0 || ((*(byte *)(_Dst + 0x51) & 2) == 0)))) &&
             ((uVar7 & 0x1000) == 0)) {
            uVar6 = FUN_006e6b90(param_1,0,0,0,_Dst[0x7f]);
            FUN_00684d30(iVar8,pfVar10,uVar6);
          }
        }
        puVar4 = (undefined4 *)_Dst[0x77];
        if (puVar4 != (undefined4 *)0x0) {
          if ((_Dst[0x42] & 0x1000) == 0) {
            uVar6 = *puVar4;
          }
          else {
            pfVar10 = afStack_4c;
            afStack_4c[0] = 10000.0;
            afStack_4c[1] = 10000.0;
            afStack_4c[2] = 10000.0;
            uVar6 = *puVar4;
          }
          FUN_00635840(uVar6,pfVar10);
        }
        if ((code *)_Dst[0x6b] != (code *)0x0) {
          (*(code *)_Dst[0x6b])(_Dst);
        }
        *(undefined1 *)(_Dst + 0x82) = 0;
        if ((*(byte *)(_Dst + 0x51) & 1) == 0) {
          FUN_0064ac90(_Dst,0);
          _memset(_Dst,0,0x220);
        }
      }
      local_68 = local_68 + 1;
      _Dst = _Dst + 0x88;
    } while (local_68 < DAT_0081020c);
  }
  return;
}

