/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x477d60; label: FUN_00477d60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00477d60(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float fVar10;
  char cVar11;
  float *pfVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  float10 fVar16;
  int local_14c;
  float local_13c;
  uint local_138;
  byte *local_134;
  uint auStack_120 [72];
  
  local_13c = 0.0;
  local_138 = 0;
  iVar5 = FUN_00574e20();
  bVar14 = iVar5 == 0xe;
  if ((bVar14) && (_DAT_00879b44 <= 0.0)) {
    if (_DAT_00879b04 <= 0.0) {
      if (0.0 < _DAT_00879b08) {
        local_13c = _DAT_00879b08;
        local_138 = (uint)(ushort)(*(short *)(PTR_DAT_008021b4 + 0x1fc) + DAT_008794ea);
      }
    }
    else if (_DAT_00879b08 <= 0.0) {
      local_13c = _DAT_00879b04;
      local_138 = (uint)(ushort)(*(short *)(PTR_DAT_008021b4 + 0x1fc) + DAT_008794e8);
    }
    else {
      local_13c = (_DAT_00879b04 + _DAT_00879b08) * 0.5;
      iVar5 = FUN_00550040(DAT_008794e8,DAT_008794ea);
      local_138 = (int)ROUND((double)DAT_008794e8 + (double)iVar5 * 0.5 +
                             (double)*(int *)(PTR_DAT_008021b4 + 0x1fc)) & 0xffff;
    }
  }
  if ((*(int *)(param_1 + 0x2984) == 0) || (*(int *)(param_1 + 0x2ae0) == 0)) {
    return;
  }
  fVar10 = 0.0;
  if (((bVar14) && (fVar10 = _DAT_00879b38, _DAT_00879b38 < 1.0)) &&
     (fVar10 = _DAT_00925018 + _DAT_00925018 + _DAT_00879b38, 1.0 < fVar10)) {
    _DAT_00879b38 = 1.0;
    fVar10 = _DAT_00879b38;
  }
  _DAT_00879b38 = fVar10;
  if ((_DAT_00879b44 <= 0.0) ||
     (_DAT_00879b44 = _DAT_00879b44 - _DAT_00925018, fVar10 = 0.0, 0.0 < _DAT_00879b44)) {
    fVar10 = _DAT_00879b40;
  }
  _DAT_00879b40 = fVar10;
  FUN_00681f40("ui_hover_lp",&DAT_007f9334);
  local_14c = 0;
  if (0 < DAT_00951360) {
    pfVar12 = (float *)(*(int *)(param_1 + 0x2ae0) + 0x74);
    local_134 = &DAT_0086e0f9;
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0x2984) + local_14c * 4);
      if (iVar5 != 0) {
        bVar1 = *local_134;
        bVar2 = *(byte *)(iVar5 + 8);
        auStack_120[local_14c] = (uint)bVar1;
        if ((uint)bVar2 < (uint)bVar1) {
          auStack_120[local_14c] = (uint)bVar2;
        }
        pfVar12[-0x1a] = 1.0;
        fVar10 = pfVar12[-1];
        fVar16 = (float10)FUN_0054fb40(*pfVar12,(0.0 - pfVar12[-2]) * 5.0,0x41200000);
        *pfVar12 = (float)fVar16;
        fVar16 = (float10)FUN_0054fb40(pfVar12[1],(0.0 - fVar10) * 5.0,0x41200000);
        uVar4 = *(undefined2 *)(pfVar12 + -0x10);
        bVar15 = local_14c == DAT_00879b34;
        pfVar12[1] = (float)fVar16;
        pfVar12[-2] = *pfVar12 * _DAT_00925018 + pfVar12[-2];
        pfVar12[-1] = (float)fVar16 * _DAT_00925018 + pfVar12[-1];
        if (bVar15) {
          if (0.0 < local_13c) {
            uVar3 = FUN_00550100(*(undefined2 *)((int)pfVar12 + -0x3a),local_138 + 0x8000,
                                 (int)ROUND(pfVar12[-0x1a] * 32768.0) & 0xffff,0);
            *(undefined2 *)((int)pfVar12 + -0x3a) = uVar3;
          }
          *(char *)((int)pfVar12 + -0x37) = (char)auStack_120[local_14c];
          if (((bVar14) && ((int)(uint)*(byte *)(iVar5 + 8) <= (int)auStack_120[local_14c])) &&
             (((DAT_0087b6c8 != '\0' && ((DAT_009253b4 & DAT_00802278) != 0)) ||
              ((DAT_0087b6c9 != '\0' && ((DAT_00925414 & DAT_00802278) != 0)))))) {
            *(undefined1 *)((int)pfVar12 + -0x37) = 1;
          }
        }
        else if (auStack_120[local_14c] == 0) {
          *(undefined1 *)((int)pfVar12 + -0x37) = 0;
          *(undefined1 *)(pfVar12 + -0xe) = 0;
        }
        else {
          *(char *)((int)pfVar12 + -0x37) = (char)auStack_120[local_14c];
        }
        uVar6 = FUN_00550070(*(undefined2 *)(pfVar12 + -0x10),*(undefined2 *)((int)pfVar12 + -0x3a),
                             0x40400000);
        *(short *)(pfVar12 + -0x10) = (short)uVar6;
        FUN_00550040(uVar4,uVar6);
        iVar7 = FUN_006e6b90();
        if (iVar7 < -0x10000) {
          iVar7 = -0x10000;
        }
        else if (0x10000 < iVar7) {
          iVar7 = 0x10000;
        }
        iVar7 = (int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3;
        if (iVar7 < -0x11c7) {
          iVar7 = -0x11c7;
        }
        else if (0x11c7 < iVar7) {
          iVar7 = 0x11c7;
        }
        uVar3 = FUN_00550070(*(undefined2 *)((int)pfVar12 + -0x3e),iVar7,0x41000000);
        iVar7 = 0;
        bVar15 = local_14c == DAT_00879b34;
        *(undefined2 *)((int)pfVar12 + -0x3e) = uVar3;
        if (((bVar15) && (0.0 < local_13c)) &&
           (uVar8 = FUN_00550040(uVar4,*(undefined2 *)(pfVar12 + -0x10)),
           (float)(int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f)) / _DAT_00925018 <
           32768.0)) {
          iVar7 = FUN_006e6b90();
        }
        uVar4 = FUN_00550070(*(undefined2 *)(pfVar12 + -0xf),-iVar7,0x40400000);
        uVar8 = auStack_120[local_14c];
        iVar7 = 0;
        *(undefined2 *)(pfVar12 + -0xf) = uVar4;
        if (*(char *)(iVar5 + 8) != '\0') {
          iVar13 = 0;
          do {
            *(undefined1 *)(*(int *)(iVar5 + 4) + 0x66 + iVar13) = 0;
            iVar9 = FUN_005cfac0(*(int *)(iVar5 + 4) + iVar13);
            if ((iVar9 != 0) && (FUN_005cfc00(*(int *)(iVar5 + 4) + iVar13,0), iVar7 < (int)uVar8))
            {
              *(undefined1 *)(*(int *)(iVar5 + 4) + 0x66 + iVar13) = 1;
            }
            iVar7 = iVar7 + 1;
            iVar13 = iVar13 + 0x68;
          } while (iVar7 < (int)(uint)*(byte *)(iVar5 + 8));
        }
        fVar10 = (float)FUN_006e6b90();
        pfVar12[-0x18] = fVar10;
        if (0x10000 < (int)fVar10) {
          pfVar12[-0x18] = (float)((int)fVar10 + -0x10000);
        }
        fVar10 = (float)FUN_006e6b90();
        pfVar12[-0x16] = fVar10;
        if (0x10000 < (int)fVar10) {
          pfVar12[-0x16] = (float)((int)fVar10 + -0x10000);
        }
        fVar10 = (float)FUN_006e6b90();
        pfVar12[-0x14] = fVar10;
        if (0x10000 < (int)fVar10) {
          pfVar12[-0x14] = (float)((int)fVar10 + -0x10000);
        }
        fVar10 = (float)FUN_006e6b90();
        pfVar12[-0x12] = fVar10;
        if (0x10000 < (int)fVar10) {
          pfVar12[-0x12] = (float)((int)fVar10 + -0x10000);
        }
        FUN_00477b90(param_1);
      }
      local_134 = local_134 + 0xc;
      local_14c = local_14c + 1;
      pfVar12 = pfVar12 + 0x1f;
    } while (local_14c < DAT_00951360);
  }
  iVar5 = *(int *)(param_1 + 0x2ae0);
  iVar7 = 0;
  if (0 < DAT_00951360) {
    do {
      if (*(int *)(*(int *)(param_1 + 0x2984) + iVar7 * 4) != 0) {
        bVar1 = *(byte *)(iVar5 + 0x3c);
        if (bVar1 != *(byte *)(iVar5 + 0x3d)) {
          iVar13 = FUN_006e6b90();
          iVar9 = FUN_006e6b90();
          if (iVar9 != iVar13) {
            if (bVar1 < *(byte *)(iVar5 + 0x3d)) {
              cVar11 = bVar1 + 1;
LAB_0047839d:
              *(char *)(iVar5 + 0x3c) = cVar11;
            }
            else if (*(byte *)(iVar5 + 0x3d) < bVar1) {
              cVar11 = bVar1 - 1;
              goto LAB_0047839d;
            }
            if (iVar7 == DAT_0087954c) {
              FUN_00681f40("LegoForm",iVar5);
            }
            FUN_0054a910(0,0,1,0);
          }
        }
        if ((0 < (int)auStack_120[iVar7]) && (*(char *)(iVar5 + 0x3c) != '\0')) {
          FUN_0055e660(iVar5 + 0x40,*(undefined4 *)(iVar5 + 100),iVar5 + 0x4c,iVar5 + 0x58,0,0,
                       0x40200000,5);
          FUN_005185e0(iVar5 + 0x40,*(undefined4 *)(iVar5 + 100));
        }
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x7c;
    } while (iVar7 < DAT_00951360);
  }
  return;
}

