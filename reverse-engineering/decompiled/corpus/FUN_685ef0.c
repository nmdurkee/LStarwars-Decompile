/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x685ef0; label: FUN_00685ef0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00685ef0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  float10 fVar12;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  int local_14;
  int local_c;
  int local_8;
  int local_4;
  
  iVar10 = DAT_029620a8;
  do {
    do {
      iVar6 = iVar10;
      if (iVar6 == 0) {
        return;
      }
      fVar12 = (float10)0;
      local_1c = (float)fVar12;
      iVar4 = *(int *)(DAT_0296209c + *(short *)(iVar6 + 0x182) * 4);
      local_18 = (float)fVar12;
      local_4 = *(int *)(iVar6 + 0x1c8);
      local_20 = 1.0;
      local_14 = 0;
      fVar5 = _DAT_0296205c;
      if (*(char *)(iVar4 + 0x2f1) == '\x04') {
        fVar5 = _DAT_02962060;
      }
      iVar10 = local_4;
    } while (*(short *)(iVar6 + 0x1d8) != 0);
    if (DAT_02962080 != 0) {
      fVar12 = (float10)FUN_005becc0(iVar6 + 400,DAT_02962080,0);
    }
    fVar1 = (float)fVar12;
    *(float *)(iVar6 + 0x31c) = fVar1;
    if (*(char *)(iVar6 + 0x184) != '\0') {
      if (((fVar1 < *(float *)(iVar4 + 0x34)) ||
          ((0.0 < *(float *)(iVar4 + 0x38) && (*(float *)(iVar4 + 0x38) < fVar1)))) &&
         ((*(char *)(iVar4 + 0x2f3) == '\0' && (*(char *)(iVar4 + 0x2f1) != '\x04')))) {
        *(undefined1 *)(iVar6 + 0x184) = 0;
      }
      if (((DAT_029620b4 != 0) && (*(short *)(iVar6 + 0x2f0) != 0)) &&
         (*(short *)(iVar6 + 0x2f0) != DAT_029620b4)) {
        *(undefined1 *)(iVar6 + 0x184) = 0;
      }
      if ((_DAT_0081090c & (int)*(char *)(iVar6 + 0x1da)) == 0) {
        *(undefined1 *)(iVar6 + 0x184) = 0;
      }
    }
    iVar10 = DAT_02947b74;
    if (*(float *)(iVar4 + 0x40) == 0.0) {
      if (*(float *)(iVar4 + 0x3c) == 0.0) {
        fVar2 = *(float *)(iVar4 + 0x38);
      }
      else {
        fVar2 = *(float *)(iVar4 + 0x3c);
      }
    }
    else {
      fVar2 = *(float *)(iVar4 + 0x40);
    }
    if (fVar1 < fVar2) {
      iVar8 = *(int *)(iVar4 + 0x3e0);
      if ((iVar8 != -1) && (-1 < iVar8)) {
        iVar8 = *(int *)(iVar8 * 0x40 + 4 + DAT_02947b74) << 0x11;
        uVar9 = iVar8 >> 0x11;
        if ((uVar9 < 0x640) && (iVar8 = (int)(uVar9 + (iVar8 >> 0x1f & 0xfU)) >> 4, iVar8 < 100)) {
          *(ushort *)(&DAT_02921760 + iVar8 * 2) =
               *(ushort *)(&DAT_02921760 + iVar8 * 2) | (ushort)(1 << ((byte)uVar9 & 0xf));
        }
      }
      iVar8 = *(int *)(iVar4 + 0x3ec);
      if ((iVar8 != -1) && (-1 < iVar8)) {
        iVar8 = *(int *)(iVar8 * 0x40 + 4 + iVar10) << 0x11;
        uVar9 = iVar8 >> 0x11;
        if ((uVar9 < 0x640) && (iVar8 = (int)(uVar9 + (iVar8 >> 0x1f & 0xfU)) >> 4, iVar8 < 100)) {
          *(ushort *)(&DAT_02921760 + iVar8 * 2) =
               *(ushort *)(&DAT_02921760 + iVar8 * 2) | (ushort)(1 << ((byte)uVar9 & 0xf));
        }
      }
      iVar8 = *(int *)(iVar4 + 0x3f8);
      if ((iVar8 != -1) && (-1 < iVar8)) {
        iVar8 = *(int *)(iVar8 * 0x40 + 4 + iVar10) << 0x11;
        uVar9 = iVar8 >> 0x11;
        if ((uVar9 < 0x640) && (iVar8 = (int)(uVar9 + (iVar8 >> 0x1f & 0xfU)) >> 4, iVar8 < 100)) {
          *(ushort *)(&DAT_02921760 + iVar8 * 2) =
               *(ushort *)(&DAT_02921760 + iVar8 * 2) | (ushort)(1 << ((byte)uVar9 & 0xf));
        }
      }
      iVar8 = *(int *)(iVar4 + 0x404);
      if ((iVar8 != -1) && (-1 < iVar8)) {
        iVar10 = *(int *)(iVar8 * 0x40 + 4 + iVar10) << 0x11;
        uVar9 = iVar10 >> 0x11;
        if ((uVar9 < 0x640) && (iVar10 = (int)(uVar9 + (iVar10 >> 0x1f & 0xfU)) >> 4, iVar10 < 100))
        {
          *(ushort *)(&DAT_02921760 + iVar10 * 2) =
               *(ushort *)(&DAT_02921760 + iVar10 * 2) | (ushort)(1 << ((byte)uVar9 & 0xf));
        }
      }
      local_20 = (fVar2 - *(float *)(iVar6 + 0x31c)) / fVar2;
    }
    if (((*(char *)(iVar6 + 0x2f5) != '\0') && (*(char *)(iVar6 + 0x184) != '\0')) &&
       (*(float *)(iVar6 + 0x31c) < fVar2)) {
      piVar11 = (int *)(iVar4 + 0x3e0);
      iVar10 = 4;
      do {
        if ((*piVar11 != -1) && (piVar11[1] == 4)) {
          FUN_00650f20(*piVar11,iVar6 + 400,local_20,0x3f800000);
        }
        piVar11 = piVar11 + 3;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    if (*(char *)(iVar4 + 0x2f) == '\0') {
      *(undefined1 *)(iVar6 + 0x184) = 0;
    }
    if (*(char *)(iVar4 + 0x2f) == '\x02') {
      *(undefined1 *)(iVar6 + 0x184) = 1;
    }
    if (*(char *)(iVar6 + 0x2f4) == '\0') {
      *(undefined1 *)(iVar6 + 0x184) = 0;
    }
    if (*(char *)(iVar6 + 0x2f4) == '\x02') {
      *(undefined1 *)(iVar6 + 0x184) = 1;
    }
    if ((*(char *)(iVar6 + 0x184) != '\0') && (*(short *)(iVar6 + 0x18c) == 0)) {
      FUN_00683e90(iVar6,(int)*(short *)(iVar4 + 0x14));
      uVar7 = FUN_006e6b90();
      FUN_00683e90(iVar6,uVar7);
    }
    fVar1 = fVar5 - *(float *)(iVar6 + 800);
    *(float *)(iVar6 + 0x19c) = *(float *)(iVar6 + 0x1b4) * fVar1;
    *(float *)(iVar6 + 0x1a0) = *(float *)(iVar6 + 0x1b8) * fVar1;
    *(float *)(iVar6 + 0x1a4) = fVar1 * *(float *)(iVar6 + 0x1bc);
    fVar1 = (float)(int)*(short *)(iVar4 + 0x16);
    if (0.0 < fVar1) {
      if (DAT_029620b8 == 0) {
        fVar3 = _DAT_00810908;
        if (*(float *)(iVar4 + 0x2f4) < _DAT_00810908) {
          fVar3 = *(float *)(iVar4 + 0x2f4);
        }
        local_1c = 1.0 / (fVar1 / fVar3);
      }
      else {
        local_1c = 1.0 / (fVar1 / _DAT_00810908);
      }
    }
    local_28 = *(float *)(iVar6 + 0x324) + local_1c;
    if (local_28 < _DAT_008108e4 + fVar5) {
      do {
        local_14 = local_14 + 1;
        if (99 < local_14) break;
        local_c = 0;
        if (*(float *)(iVar6 + 0x1e4) < local_28 != (*(float *)(iVar6 + 0x1e4) == local_28)) {
          do {
            if ((*(float *)(iVar6 + 0x1e0) < local_28 == (*(float *)(iVar6 + 0x1e0) == local_28)) ||
               (local_c = local_c + 1, 99 < local_c)) break;
            local_18 = 0.0;
            if (*(float *)(iVar6 + 0x1e4) < *(float *)(iVar6 + 0x1e0) ==
                (*(float *)(iVar6 + 0x1e4) == *(float *)(iVar6 + 0x1e0))) {
              *(undefined4 *)(iVar6 + 0x1dc) = *(undefined4 *)(iVar6 + 0x1e0);
              fVar12 = (float10)FUN_005b9d90(&DAT_00810900);
              local_18 = (float)(fVar12 * (float10)*(float *)(iVar4 + 0x28) +
                                (float10)*(float *)(iVar4 + 0x24));
              *(float *)(iVar6 + 0x1e0) = local_18 + *(float *)(iVar6 + 0x1e4);
              if (*(char *)(iVar6 + 0x184) == '\x02') {
                *(undefined1 *)(iVar6 + 0x184) = 0;
              }
              if (((*(char *)(iVar6 + 0x2f5) != '\0') && (*(char *)(iVar6 + 0x184) != '\0')) &&
                 (*(float *)(iVar6 + 0x31c) < fVar2)) {
                piVar11 = (int *)(iVar4 + 0x3e0);
                iVar10 = 4;
                do {
                  if ((*piVar11 != -1) && (piVar11[1] == 2)) {
                    FUN_00650f20(*piVar11,iVar6 + 400,local_20,0x3f800000);
                  }
                  piVar11 = piVar11 + 3;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
              }
            }
            else {
              fVar12 = (float10)FUN_005b9d90(&DAT_00810900);
              *(float *)(iVar6 + 0x1e4) =
                   (float)((float10)*(float *)(iVar4 + 0x1c) + (float10)*(float *)(iVar6 + 0x1e0) +
                          fVar12 * (float10)*(float *)(iVar4 + 0x20));
              if ((0 < *(int *)(iVar6 + 0x1d4)) &&
                 (iVar10 = *(int *)(iVar6 + 0x1d4) + -1, *(int *)(iVar6 + 0x1d4) = iVar10,
                 iVar10 == 0)) {
                local_8 = (int)*(short *)(iVar6 + 0x32a);
                FUN_00683f50(&local_8);
                *(undefined1 *)(iVar6 + 0x2f5) = 0;
                local_28 = local_28 + 99999.0;
              }
              if ((*(int *)(iVar6 + 0x1d4) < 0) &&
                 (iVar10 = *(int *)(iVar6 + 0x1d4) + 1, *(int *)(iVar6 + 0x1d4) = iVar10,
                 iVar10 == 0)) {
                *(undefined1 *)(iVar6 + 0x2f4) = 0;
                *(undefined1 *)(iVar6 + 0x184) = 0;
              }
              if (((*(char *)(iVar6 + 0x2f5) != '\0') && (*(char *)(iVar6 + 0x184) != '\0')) &&
                 (*(float *)(iVar6 + 0x31c) < fVar2)) {
                piVar11 = (int *)(iVar4 + 0x3e0);
                iVar10 = 4;
                do {
                  if ((*piVar11 != -1) && (piVar11[1] == 1)) {
                    FUN_00650f20(*piVar11,iVar6 + 400,local_20,0x3f800000);
                  }
                  piVar11 = piVar11 + 3;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
              }
            }
          } while (*(float *)(iVar6 + 0x1e4) < local_28 != (*(float *)(iVar6 + 0x1e4) == local_28));
        }
        if (local_18 <= 0.0) {
          if ((0 < *(short *)(iVar6 + 0x180)) && (*(char *)(iVar6 + 0x184) != '\0')) {
            iVar10 = (**(code **)(iVar6 + 0x1c0))(iVar6,iVar4,local_28);
            if ((*(char *)(iVar4 + 0x2f0) != '\0') && ((local_14 == 1 && (iVar10 != 0)))) {
              FUN_00656080(iVar10,local_28,iVar4,iVar6,0);
            }
            if ((*(char *)(iVar6 + 0x2f5) != '\0') && (*(float *)(iVar6 + 0x31c) < fVar2)) {
              piVar11 = (int *)(iVar4 + 0x3e0);
              iVar10 = 4;
              do {
                if ((*piVar11 != -1) && (piVar11[1] == 3)) {
                  FUN_00650f20(*piVar11,iVar6 + 400,local_20,0x3f800000);
                }
                piVar11 = piVar11 + 3;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
          }
        }
        else {
          local_28 = *(float *)(iVar6 + 0x1e0) - local_1c;
        }
        *(float *)(iVar6 + 0x324) = local_28;
        local_28 = local_28 + local_1c;
      } while (local_28 < _DAT_008108e4 + fVar5);
    }
    iVar10 = local_4;
    if (*(char *)(iVar6 + 0x184) == '\0') {
      if ((((((*(char *)(iVar6 + 0x2f4) != '\0') && (*(int *)(iVar6 + 0x2d4) == -1)) &&
            (*(float *)(iVar4 + 0x34) < *(float *)(iVar6 + 0x31c) !=
             (*(float *)(iVar4 + 0x34) == *(float *)(iVar6 + 0x31c)))) &&
           ((*(float *)(iVar4 + 0x38) == 0.0 ||
            (*(float *)(iVar6 + 0x31c) <= *(float *)(iVar4 + 0x38))))) &&
          ((DAT_029620b4 == 0 ||
           ((*(short *)(iVar6 + 0x2f0) == 0 || (*(short *)(iVar6 + 0x2f0) == DAT_029620b4)))))) &&
         ((_DAT_0081090c & (int)*(char *)(iVar6 + 0x1da)) != 0)) {
        *(undefined1 *)(iVar6 + 0x184) = 1;
      }
      iVar10 = local_4;
      if ((*(char *)(iVar6 + 0x184) == '\0') && (iVar10 = local_4, *(short *)(iVar6 + 0x18c) != 0))
      {
        FUN_00683e90(iVar6,0);
        iVar10 = local_4;
      }
    }
  } while( true );
}

