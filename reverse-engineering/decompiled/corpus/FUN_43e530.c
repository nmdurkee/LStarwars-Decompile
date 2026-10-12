/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43e530; label: FUN_0043e530
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043e530(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint uVar8;
  undefined *puVar9;
  undefined2 uVar10;
  int iVar11;
  uint *puVar12;
  short sVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  int iVar17;
  int *piVar18;
  int *piVar19;
  float10 fVar20;
  undefined8 uVar21;
  float local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  int *local_440;
  int *local_43c;
  int local_438;
  int *local_434;
  int *local_430;
  uint local_42c;
  uint local_428;
  float local_424 [2];
  float local_41c;
  float local_418;
  float local_414;
  float local_410;
  undefined1 local_40c [12];
  int local_400 [64];
  int local_300 [64];
  int local_200 [64];
  int local_100 [64];
  
  local_444 = 0;
  local_448 = 0;
  local_44c = 0;
  local_438 = 0;
  local_42c = 0;
  local_428 = 0;
  DAT_00876cd0 = 0;
  iVar17 = 0;
  if (DAT_0093d810 != 0) {
    iVar17 = DAT_0093d810;
  }
  iVar11 = 0;
  if (DAT_0093d814 != 0) {
    iVar11 = DAT_0093d814;
  }
  FUN_00518210(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar17,iVar11);
  iVar17 = 0;
  if (0 < DAT_0093d500) {
    puVar12 = (uint *)(DAT_0093d504 + 0xef0);
    do {
      if (((puVar12[-0x33d] & 0x1000) != 0) && (*(char *)((int)puVar12 + -0xc65) == '\0')) {
        *puVar12 = *puVar12 & 0xffff7fff;
        puVar12[1] = puVar12[1] & 0xfffc3fff;
        *(undefined1 *)((int)puVar12 + 0x182) = 0;
        if (*(char *)((int)puVar12 + 0x11) == '\0') {
          if ((float)puVar12[5] <= 0.0) {
            puVar12[3] = 0;
            *(undefined1 *)(puVar12 + 4) = 0;
          }
          else {
            puVar12[5] = (uint)((float)puVar12[5] - _DAT_00925018);
          }
        }
        else {
          *(char *)((int)puVar12 + 0x11) = *(char *)((int)puVar12 + 0x11) + -1;
        }
        if ((char)puVar12[0x66] != '\0') {
          *(char *)(puVar12 + 0x66) = (char)puVar12[0x66] + -1;
        }
        if ((puVar12[-0x290] & 0x4000) == 0) {
          puVar12[-0x32c] = 0;
        }
        else {
          puVar12[-0x32c] = _DAT_007f6740;
        }
        if ((DAT_00855de0 != 0) && ((puVar12[-0x33d] & 0x100) != 0)) {
          *(uint *)(puVar12[-0x93] + 4) = *(uint *)(puVar12[-0x93] + 4) & DAT_00802274;
          *(uint *)(puVar12[-0x93] + 8) = *(uint *)(puVar12[-0x93] + 8) & DAT_00802274;
        }
        if (puVar12[-0xc] != 0) {
          fVar1 = (float)puVar12[-0xb] - _DAT_00925018;
          puVar12[-0xb] = (uint)fVar1;
          if (fVar1 < 0.0 != (fVar1 == 0.0)) {
            puVar12[-0xb] = 0;
            puVar12[-0xc] = 0;
          }
        }
      }
      iVar17 = iVar17 + 1;
      puVar12 = puVar12 + 0x436;
    } while (iVar17 < DAT_0093d500);
  }
  iVar6 = DAT_0087af98;
  iVar11 = DAT_00876cd8;
  puVar9 = PTR_DAT_00802c54;
  iVar17 = DAT_007f39e4;
  local_430 = local_200;
  local_440 = local_400;
  local_43c = local_300;
  local_434 = local_100;
  DAT_00876ce8 = 0;
  DAT_00876cc8 = 0;
  bVar7 = true;
  iVar14 = 0;
  do {
    iVar4 = *(int *)((int)&DAT_0093d7f0 + iVar14);
    if ((((((iVar4 != 0) && ((*(uint *)(iVar4 + 0x1fc) & 1) != 0)) &&
          ((*(uint *)(iVar4 + 0x1fc) & 0x1000) != 0)) &&
         (((*(char *)(iVar4 + 0x28b) == '\0' || (0.0 < *(float *)(iVar4 + 0x1010))) &&
          (((*(byte *)(iVar4 + 0xef3) & 1) == 0 && (iVar17 != 0)))))) &&
        ((iVar6 == 0 || (*(int *)(puVar9 + 300) != iVar6)))) && (DAT_00876ccc == 0)) {
      if (((*(char *)(iVar4 + 0x1082) == '\x05') ||
          ((((DAT_0093b2a4 != 0 || (*(int *)(puVar9 + 0x128) == DAT_00951b94)) &&
            ((*(uint *)(*(int *)(iVar4 + 0x54) + 4) & 0x204) != 0)) &&
           (*(int *)(iVar4 + 0xcd0) == 0)))) &&
         (((iVar11 == 0 || (*(char *)(iVar11 + 0x280) == -1)) ||
          ((*(byte *)(iVar11 + 0xef3) & 1) != 0)))) {
        DAT_00876cc8 = 1;
      }
      if ((*(uint *)(*(int *)(iVar4 + 0x54) + 4) & 0x80000) == 0) {
        bVar7 = false;
      }
    }
    *(undefined4 *)((int)&DAT_00876c98 + iVar14) = 0x3f000000;
    iVar14 = iVar14 + 4;
  } while (iVar14 < 0x20);
  if (((iVar17 != 0) && ((iVar6 == 0 || (*(int *)(puVar9 + 300) != iVar6)))) &&
     ((bVar7 && (DAT_00876ccc == 0)))) {
    DAT_00876cc8 = 1;
  }
  FUN_00401e40(*(undefined4 *)(puVar9 + 0x4678));
  fVar1 = _DAT_007f6744;
  iVar17 = 0;
  local_454 = _DAT_007f6744 * 0.0 + 0.0;
  do {
    if ((iVar17 < 2) && (DAT_0093d810 == DAT_0093d7f4)) {
      iVar11 = DAT_0093d7f4;
      if (iVar17 != 0) {
        iVar11 = DAT_0093d7f0;
      }
    }
    else {
      iVar11 = (&DAT_0093d7f0)[iVar17];
    }
    if ((((((iVar11 != 0) && ((*(uint *)(iVar11 + 0x1fc) & 1) != 0)) &&
          ((*(uint *)(iVar11 + 0x1fc) & 0x1000) != 0)) &&
         ((*(char *)(iVar11 + 0x28b) == '\0' || (0.0 < *(float *)(iVar11 + 0x1010))))) &&
        (*(char *)(iVar11 + 0x7b5) != '\x17')) && (*(char *)(iVar11 + 0x7b5) != 'Z')) {
      if ((DAT_00876cc8 != 0) && ((*(uint *)(iVar11 + 0x4b0) & 0x4000) != 0)) {
        DAT_00876cc8 = 0;
      }
      if (((((-0.85 < *(float *)(iVar11 + 0xc5c)) && (*(float *)(iVar11 + 0xc5c) < 0.85)) &&
           (-0.85 < *(float *)(iVar11 + 0xc60))) && (*(float *)(iVar11 + 0xc60) < 0.85)) ||
         (((*(byte *)(iVar11 + 0x7c5) & 2) != 0 || (_DAT_00876ce4 <= 0.0)))) {
        if ((*(uint *)(iVar11 + 0x1f8) & 1) == 0) {
          if ((*(uint *)(iVar11 + 0x1f8) & 4) == 0) {
            local_448 = local_448 + 1;
            *local_43c = iVar11;
            local_43c = local_43c + 1;
          }
          else {
            local_438 = local_438 + 1;
            *local_434 = iVar11;
            local_434 = local_434 + 1;
          }
        }
        else {
          local_44c = local_44c + 1;
          *local_440 = iVar11;
          local_440 = local_440 + 1;
        }
      }
      else {
        *(uint *)(iVar11 + 0x4b0) = *(uint *)(iVar11 + 0x4b0) & 0xffffefff;
        *(undefined4 *)(iVar11 + 0x3a8) = 0x4e6e6b28;
        *(undefined4 *)(iVar11 + 0x3b8) = 0x4e6e6b28;
        *(undefined4 *)(iVar11 + 0x39c) = 0;
        *(undefined4 *)(iVar11 + 0x3a4) = 0;
        *(undefined4 *)(iVar11 + 0x3ac) = 0;
        *(undefined4 *)(iVar11 + 0x3b4) = 0;
      }
    }
    iVar11 = (&DAT_0093d7f0)[iVar17];
    if (iVar11 != 0) {
      uVar15 = *(uint *)(iVar11 + 0x1fc);
      if (((((uVar15 & 1) != 0) && ((uVar15 & 0x1000) != 0)) &&
          ((*(char *)(iVar11 + 0x28b) == '\0' || (0.0 < *(float *)(iVar11 + 0x1010))))) &&
         (((*(byte *)(iVar11 + 0xef3) & 1) == 0 && (-1 < (char)uVar15)))) {
        (&DAT_00876c98)[*(char *)(iVar11 + 0x280)] = local_454;
        local_454 = local_454 + fVar1;
      }
    }
    iVar17 = iVar17 + 1;
  } while (iVar17 < 8);
  local_450 = 0;
  iVar17 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      *(undefined4 *)(iVar17 + 0x10d4) = 0;
      if (((((*(uint *)(iVar17 + 0x1fc) & 1) == 0) || ((*(uint *)(iVar17 + 0x1fc) & 0x1000) == 0))
          || (*(char *)(iVar17 + 0x28b) != '\0')) ||
         (cVar3 = *(char *)(iVar17 + 0x7b5), cVar3 == ';')) {
LAB_0043f8e1:
        if (((((*(uint *)(iVar17 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar17 + 0x28b) != '\0')) ||
            (*(int *)(iVar17 + 0xeac) != 0)) ||
           ((*(uint *)(*(int *)(*(int *)(iVar17 + 0x54) + 0x24) + 0x90) & 0x8000) != 0)) {
          if (*(float *)(iVar17 + 0x1010) <= 0.0) {
            *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) & 0xffffdfff;
            *(undefined4 *)(iVar17 + 0x39c) = 0;
            *(undefined4 *)(iVar17 + 0x3ac) = 0;
          }
          else {
            *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) | 0x2000;
          }
        }
        else {
          local_444 = local_444 + 1;
          *local_430 = iVar17;
          local_430 = local_430 + 1;
          *(ushort *)(iVar17 + 0x292) = (short)DAT_0093d500 - (ushort)*(byte *)(iVar17 + 0x28d);
          *(undefined2 *)(iVar17 + 0x294) = 0;
          if (((*(uint *)(iVar17 + 0x1fc) & 2) == 0) &&
             ((*(uint *)(iVar17 + 0xef0) & 0x80000000) == 0)) {
            if (-1 < (char)*(uint *)(iVar17 + 0x1fc)) {
              if ((int)*(uint *)(iVar17 + 0x4b0) < 0) {
                *(ushort *)(iVar17 + 0x292) = *(ushort *)(iVar17 + 0x292) | 0x4000;
              }
              if ((*(uint *)(iVar17 + 0x4b0) & 0x40000000) != 0) {
                *(ushort *)(iVar17 + 0x292) = *(ushort *)(iVar17 + 0x292) | 0x2000;
              }
              if ((*(byte *)(iVar17 + 0x4b4) & 1) != 0) {
                *(ushort *)(iVar17 + 0x292) = *(ushort *)(iVar17 + 0x292) | 0x1000;
              }
              if ((*(byte *)(*(int *)(iVar17 + 0xca4) + 0x5a) & 2) != 0) {
                *(ushort *)(iVar17 + 0x292) = *(ushort *)(iVar17 + 0x292) | 0x800;
              }
              if (((*(byte *)(iVar17 + 0x42e) & 1) == 0) || (*(int *)(iVar17 + 0x424) == 0)) {
                *(ushort *)(iVar17 + 0x292) = *(ushort *)(iVar17 + 0x292) | 0x400;
              }
              if (*(float *)(iVar17 + 0x48c) == 0.0) {
                local_424[0] = *(float *)(iVar17 + 0x47c) - *(float *)(iVar17 + 0x5c);
                local_41c = *(float *)(iVar17 + 0x484) - *(float *)(iVar17 + 100);
                fVar1 = *(float *)(iVar17 + 1000) + 1.0;
                if (local_424[0] * local_424[0] + local_41c * local_41c < fVar1 * fVar1) {
                  *(ushort *)(iVar17 + 0x292) = *(ushort *)(iVar17 + 0x292) | 0x200;
                }
              }
            }
          }
          else {
            *(undefined2 *)(iVar17 + 0x292) = 0x8000;
          }
          *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) | 0x2000;
          if ((*(int *)(iVar17 + 0x10a4) != 0) &&
             ((*(byte *)(*(int *)(iVar17 + 0x10a4) + 0x1fc) & 1) == 0)) {
            *(undefined4 *)(iVar17 + 0x10a4) = 0;
          }
          iVar11 = *(int *)(iVar17 + 0x3ac);
          if ((iVar11 != 0) &&
             (((*(byte *)(iVar11 + 0x1fc) & 1) == 0 ||
              ((*(uint *)(*(int *)(iVar11 + 4) + 0x1e8) & 0x2000) == 0)))) {
            *(undefined4 *)(iVar17 + 0x3ac) = 0;
            *(undefined4 *)(iVar17 + 0x3b0) = 0x4e6e6b28;
          }
          if ((((*(uint *)(iVar17 + 0xef0) & 0x8000000) != 0) || (DAT_00876cf4 != 0)) ||
             (iVar11 = FUN_0047a8d0(), iVar11 != 0)) {
            uVar21 = __allshl();
            *(uint *)(iVar17 + 0xeb8) = *(uint *)(iVar17 + 0xeb8) | (uint)uVar21;
            *(uint *)(iVar17 + 0xebc) =
                 *(uint *)(iVar17 + 0xebc) | (uint)((ulonglong)uVar21 >> 0x20);
            if (DAT_0093d814 != 0) {
              uVar21 = __allshl();
              *(uint *)(iVar17 + 0xeb8) = *(uint *)(iVar17 + 0xeb8) | (uint)uVar21;
              *(uint *)(iVar17 + 0xebc) =
                   *(uint *)(iVar17 + 0xebc) | (uint)((ulonglong)uVar21 >> 0x20);
            }
          }
          if ((*(byte *)(iVar17 + 0x1fc) & 0x80) != 0) {
            if (DAT_00876cd4 == 0) {
              if (*(char *)(iVar17 + 0x281) != '\0') {
                fVar1 = *(float *)(*(int *)(iVar17 + 0xca4) + 0x28);
                fVar2 = *(float *)(*(int *)(*(int *)(iVar17 + 0x54) + 0x24) + 0x14);
                goto LAB_0043fb4f;
              }
            }
            else if (*(char *)(iVar17 + 0x281) != '\0') {
              fVar1 = *(float *)(*(int *)(iVar17 + 0xca4) + 0x28);
              fVar2 = *(float *)(*(int *)(*(int *)(iVar17 + 0x54) + 0x24) + 0x18);
LAB_0043fb4f:
              if (fVar2 < fVar1) {
                *(uint *)(iVar17 + 0xeec) = *(uint *)(iVar17 + 0xeec) | 0x800;
              }
            }
          }
        }
      }
      else if (DAT_00876580 == 0) {
        if (DAT_007f39e4 != 0) {
          if ((*(char *)(iVar17 + 0x281) == '\0') &&
             ((*(uint *)(*(int *)(iVar17 + 0x54) + 4) & 0x2000) == 0)) goto LAB_0043eb2d;
          uVar16 = 1;
          goto LAB_0043eb34;
        }
        if (((*(char *)(iVar17 + 0x281) == '\0') &&
            ((*(uint *)(*(int *)(iVar17 + 0x54) + 4) & 0x2000) == 0)) &&
           ((cVar3 != 'D' && (cVar3 != 'K')))) {
          uVar16 = 0;
        }
        else {
          uVar16 = 1;
        }
        if (cVar3 != '\x17') goto LAB_0043eb34;
        if ((*(byte *)(iVar17 + 0xef4) & 8) != 0) {
          FUN_005371a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar17,iVar17 + 0x2c8,uVar16,
                       *(undefined4 *)(iVar17 + 0x10b8));
        }
      }
      else {
        if (((*(char *)(iVar17 + 0x281) == '\0') &&
            ((*(uint *)(*(int *)(iVar17 + 0x54) + 4) & 0x2000) == 0)) && (cVar3 != 'K')) {
LAB_0043eb2d:
          uVar16 = 0;
        }
        else {
          uVar16 = 1;
        }
LAB_0043eb34:
        uVar15 = *(uint *)(iVar17 + 0x1f8);
        if ((uVar15 & 0x400) != 0) {
          if ((uVar15 & 0x10000) == 0) {
            if ((uVar15 & 1) == 0) {
              if ((uVar15 & 4) == 0) goto LAB_0043eb5d;
              local_438 = local_438 + 1;
              *local_434 = iVar17;
              local_434 = local_434 + 1;
            }
            else {
              local_44c = local_44c + 1;
              *local_440 = iVar17;
              local_440 = local_440 + 1;
            }
          }
          else {
            local_44c = local_44c + 1;
            *local_440 = iVar17;
            local_440 = local_440 + 1;
LAB_0043eb5d:
            local_448 = local_448 + 1;
            *local_43c = iVar17;
            local_43c = local_43c + 1;
          }
        }
        if ((*(uint *)(iVar17 + 0x1f8) & 0x40000) == 0) {
          if (**(int **)(iVar17 + 0xca4) == 0) {
            (*(int **)(iVar17 + 0xca4))[3] = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 0x10) = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 0x14) = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 0x18) = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 0x1c) = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 0x20) = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 4) = 0;
            *(undefined4 *)(*(int *)(iVar17 + 0xca4) + 8) = 0;
          }
          local_428 = local_428 | *(uint *)(iVar17 + 0x2ac);
          local_42c = local_42c | *(uint *)(iVar17 + 0x2a8);
          uVar15 = *(uint *)(iVar17 + 0xef4) >> 3 & 1;
          if (uVar15 != 0) {
            uVar5 = *(uint *)(iVar17 + 0xeec);
            uVar8 = (uVar5 & 0x200) * 2;
            *(uint *)(iVar17 + 0xeec) = uVar8 | uVar5 & 0xfffffbdf;
            *(undefined4 *)(iVar17 + 0xea0) = 0;
            if ((uVar5 & 0x8000) != 0) {
              *(uint *)(iVar17 + 0xeec) = uVar8 | uVar5 & 0xffff7bdf;
              *(undefined4 *)(iVar17 + 0xe58) = *(undefined4 *)(iVar17 + 0xe4c);
              *(undefined4 *)(iVar17 + 0xe5c) = *(undefined4 *)(iVar17 + 0xe50);
              *(undefined4 *)(iVar17 + 0xe60) = *(undefined4 *)(iVar17 + 0xe54);
            }
            *(uint *)(iVar17 + 0xeec) = *(uint *)(iVar17 + 0xeec) & 0xfffcffff;
          }
          if (((DAT_00876580 == 0) || ((*(byte *)(iVar17 + 0x1fc) & 0x80) == 0)) ||
             (*(char *)(iVar17 + 0x7b5) == DAT_00802874)) {
            FUN_00537370(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar17,iVar17 + 0x2c8,uVar16,
                         *(undefined4 *)(iVar17 + 0x10b8),0,uVar15);
          }
          else {
            uVar5 = *(uint *)(iVar17 + 0x4bc);
            *(uint *)(iVar17 + 0x4bc) = uVar5 & 0xfffffff7;
            FUN_00537370(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar17,iVar17 + 0x2c8,uVar16,
                         *(undefined4 *)(iVar17 + 0x10b8),0,uVar15);
            *(uint *)(iVar17 + 0x4bc) = uVar5;
          }
          if ((*(byte *)(iVar17 + 0x1fc) & 0x80) == 0) {
            if (*(char *)(iVar17 + 0x7b5) == ']') {
              FUN_0049d520(iVar17,*(undefined4 *)(iVar17 + 0x3d0));
            }
            if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0cc) &&
                (*(short *)(iVar17 + 0x1064) == DAT_007f19e0)) &&
               (((*(uint *)(iVar17 + 0xeec) & 0x8000000) != 0 &&
                ((*(float *)(iVar17 + 0x1028) != 1e+09 && (*(char *)(iVar17 + 0xe32) == '\0')))))) {
              *(undefined1 *)(iVar17 + 0xe32) = 1;
            }
            if (((*(char *)(iVar17 + 0x280) != -1) && (*(char *)(iVar17 + 0xe32) != '\0')) &&
               ((*(uint *)(iVar17 + 0x4bc) & DAT_00950d5c) == 0)) {
              *(undefined1 *)(iVar17 + 0xe32) = 0;
            }
            if (((*(char *)(iVar17 + 0x7b5) == 'K') && (*(int *)(iVar17 + 0xcbc) != 0)) &&
               ((*(byte *)(*(int *)(iVar17 + 0xcbc) + 0xc) & 0x10) != 0)) {
              puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 4);
              *puVar12 = *puVar12 | DAT_00802280;
            }
            iVar11 = *(int *)(iVar17 + 0x424);
            if (iVar11 == 0) {
              uVar15 = 0;
            }
            else {
              uVar15 = *(uint *)(iVar11 + (uint)*(byte *)(iVar17 + 0x428) * 4) &
                       *(uint *)(iVar17 + 0x4bc);
            }
            if ((DAT_00950d54 & uVar15) != 0) {
              FUN_0043b410();
              goto LAB_0043f08d;
            }
            if (((*(char *)(iVar17 + 0x401) != '\0') || ((*(byte *)(iVar17 + 0x42e) & 1) == 0)) ||
               (*(float *)(iVar17 + 0x1d8) <= _DAT_007f673c)) goto LAB_0043f08d;
            if (((*(short *)(iVar17 + 0x27e) == -1) || (iVar11 == 0)) ||
               ((*(uint *)(iVar11 + 8) & DAT_00950d50) == 0)) {
              if (((*(uint *)(iVar17 + 0x4bc) & (DAT_00950d58 | DAT_00950d5c)) == 0) ||
                 (*(char *)(iVar17 + 0xe32) != '\0')) {
                *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) | 0x400000;
              }
              else {
                puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 8);
                *puVar12 = *puVar12 | DAT_00802278;
                *(undefined4 *)(iVar17 + 0x1d8) = 0;
              }
              goto LAB_0043f08d;
            }
            if ((*(byte *)(*(int *)(iVar17 + 0x54) + 4) & 0x88) != 0) {
              puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 8);
              *puVar12 = *puVar12 | DAT_0080227c;
              *(undefined4 *)(iVar17 + 0x1d8) = 0;
              FUN_0055dd70(iVar17,0,5,0,0x3f800000);
              goto LAB_0043f08d;
            }
            if (DAT_0093b2a4 != 0) {
              fVar1 = *(float *)(iVar17 + 0xda4) - _DAT_00925018;
              *(float *)(iVar17 + 0xda4) = fVar1;
              if (fVar1 <= 0.0) {
                FUN_0055eaa0(iVar17,1,0);
                if (*(short *)(iVar17 + 0x1064) == DAT_007f1900) {
                  FUN_0055eaa0(iVar17,1,0);
                }
                if (*(char *)(iVar17 + 0x288) == '\0') {
                  *(undefined4 *)(iVar17 + 0xda4) = 0;
                }
                else {
                  *(undefined4 *)(iVar17 + 0xda4) = 0x3e800000;
                }
              }
              goto LAB_0043f08d;
            }
LAB_0043f480:
            if ((*(uint *)(iVar17 + 0x4b0) & 0x400000) != 0) {
              FUN_0051b7f0(iVar17 + 0x2c8);
            }
          }
          else {
LAB_0043f08d:
            if ((DAT_0093b2a4 == 0) || ((*(uint *)(iVar17 + 0x1f8) & 0x400) != 0))
            goto LAB_0043f480;
            if (((*(byte *)(iVar17 + 0x1fc) & 0x80) == 0) && (*(char *)(iVar17 + 0x7b5) != '\v')) {
              if ((((DAT_007f3964 != 1) || (DAT_00951288 != 0)) ||
                  ((DAT_0093b324 == 0 && (DAT_007f3968 == 0)))) ||
                 (((*(char *)(iVar17 + 0x288) != '\0' || ((*(byte *)(iVar17 + 0x7c5) & 2) != 0)) ||
                  (_DAT_00876ce4 <= 0.0)))) {
                uVar15 = *(uint *)(iVar17 + 0x4b0);
                if ((uVar15 & 0x100000) == 0) {
                  if (((uVar15 & 0x400000) == 0) ||
                     (((uVar15 & 0x200000) == 0 &&
                      ((*(int *)(iVar17 + 0x424) == 0 ||
                       (*(short *)(*(int *)(iVar17 + 0x424) + 0x14) == 0)))))) {
                    *(uint *)(iVar17 + 0xef0) = *(uint *)(iVar17 + 0xef0) & 0xffffffbf;
                    *(undefined2 *)(iVar17 + 0x1066) = 0xffff;
                    *(undefined2 *)(iVar17 + 0x1068) = 0xffff;
                    *(undefined4 *)(iVar17 + 0xf08) = 0;
                    *(undefined1 *)(iVar17 + 0x1089) = 0;
                  }
                  else if ((*(uint *)(iVar17 + 0xef0) & 0x40) == 0) {
                    if ((_DAT_00950d7c & *(uint *)(iVar17 + 0x4c0)) == 0) {
                      if (((*(short *)(iVar17 + 0x1066) == -1) ||
                          (*(uint *)(iVar17 + 0xf08) != *(uint *)(iVar17 + 0x4c0))) ||
                         (*(short *)(iVar17 + 0x1066) == DAT_007f1900)) {
                        *(undefined2 *)(iVar17 + 0x1066) = *(undefined2 *)(iVar17 + 0x1064);
                        if (*(int *)(iVar17 + 0xcbc) == 0) {
                          *(undefined2 *)(iVar17 + 0x1068) = 0xffff;
                        }
                        else {
                          uVar10 = FUN_004cc920(*(int *)(iVar17 + 0xcbc));
                          *(undefined2 *)(iVar17 + 0x1068) = uVar10;
                        }
                        *(undefined4 *)(iVar17 + 0xda4) = 0;
                        *(undefined1 *)(iVar17 + 0x1081) = *(undefined1 *)(iVar17 + 0x405);
                        *(undefined4 *)(iVar17 + 0xf08) = *(undefined4 *)(iVar17 + 0x4c0);
                        *(undefined1 *)(iVar17 + 0x1089) = *(undefined1 *)(iVar17 + 0x405);
                      }
                      fVar1 = *(float *)(iVar17 + 0xda4) - _DAT_00925018;
                      *(float *)(iVar17 + 0xda4) = fVar1;
                      if (fVar1 <= 0.0) {
                        FUN_0055eaa0(iVar17,1,0);
                        if (*(short *)(iVar17 + 0x1064) == DAT_007f1900) {
                          FUN_0055eaa0(iVar17,1,0);
                        }
                        if (*(char *)(iVar17 + 0x288) == '\0') {
                          uVar16 = 0;
                        }
                        else {
                          uVar16 = 0x3e800000;
                        }
                        *(undefined4 *)(iVar17 + 0xda4) = uVar16;
                        if ((*(short *)(iVar17 + 0x1066) == *(short *)(iVar17 + 0x1064)) &&
                           (iVar11 = FUN_004cc920(*(undefined4 *)(iVar17 + 0xcbc)),
                           *(short *)(iVar17 + 0x1068) == iVar11)) {
                          FUN_0055eaa0(iVar17,0xffffffff,0);
                          if (*(short *)(iVar17 + 0x1064) == DAT_007f1900) {
                            FUN_0055eaa0(iVar17,0xffffffff,0);
                          }
                          *(undefined2 *)(iVar17 + 0x1066) = *(undefined2 *)(iVar17 + 0x1064);
                          uVar10 = FUN_004cc920(*(undefined4 *)(iVar17 + 0xcbc));
                          *(undefined2 *)(iVar17 + 0x1068) = uVar10;
                          *(undefined1 *)(iVar17 + 0x405) = *(undefined1 *)(iVar17 + 0x1089);
                          FUN_0051b7f0(iVar17 + 0x2c8);
                          *(char *)(iVar17 + 0x1089) = *(char *)(iVar17 + 0x405);
                          if (*(char *)(iVar17 + 0x1081) == *(char *)(iVar17 + 0x405)) {
                            *(uint *)(iVar17 + 0xef0) = *(uint *)(iVar17 + 0xef0) | 0x40;
                          }
                        }
                      }
                    }
                  }
                  else if (*(int *)(iVar17 + 0xf08) != *(int *)(iVar17 + 0x4c0)) {
                    *(undefined2 *)(iVar17 + 0x1066) = 0xffff;
                    *(undefined2 *)(iVar17 + 0x1068) = 0xffff;
                    *(uint *)(iVar17 + 0xef0) = *(uint *)(iVar17 + 0xef0) & 0xffffffbf;
                    *(undefined4 *)(iVar17 + 0xf08) = 0;
                  }
                }
                else {
                  *(undefined1 *)(iVar17 + 0x404) = 0xff;
                  *(undefined2 *)(iVar17 + 0x1066) = 0xffff;
                  *(undefined4 *)(iVar17 + 0xf08) = 0;
                }
              }
              else {
                local_418 = *(float *)(DAT_0093d810 + 0x1b4);
                local_414 = *(float *)(DAT_0093d810 + 0x1b8);
                local_410 = *(float *)(DAT_0093d810 + 0x1bc);
                if (((*(float *)(DAT_0093d810 + 0x5c) == local_418) &&
                    (*(float *)(DAT_0093d810 + 0x60) == local_414)) &&
                   (*(float *)(DAT_0093d810 + 100) == local_410)) {
                  local_410 = local_410 + 0.01;
                }
                *(float *)(iVar17 + 0x8c) = local_418;
                *(float *)(iVar17 + 0x5c) = local_418;
                *(float *)(iVar17 + 0x90) = local_414;
                *(float *)(iVar17 + 0x60) = local_414;
                *(float *)(iVar17 + 0x94) = local_410;
                *(float *)(iVar17 + 100) = local_410;
                *(undefined4 *)(iVar17 + 0x68) = DAT_0093b0cc;
                *(undefined4 *)(iVar17 + 0x6c) = DAT_0093b0d0;
                *(undefined4 *)(iVar17 + 0x70) = DAT_0093b0d4;
                *(undefined2 *)(iVar17 + 0x27a) = *(undefined2 *)(DAT_0093d810 + 0x27a);
                FUN_0041af70(iVar17);
                *(undefined4 *)(iVar17 + 0x1d8) = 0;
                FUN_005728a0(iVar17);
                FUN_00572660(iVar17,1);
                FUN_0055d2b0(iVar17);
                FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5c,iVar17 + 0x80);
              }
            }
          }
          uVar15 = *(uint *)(iVar17 + 0x1fc);
          bVar7 = false;
          if (((char)uVar15 < '\0') && ((uVar15 & 0x100) == 0)) {
            if ((*(uint *)(*(int *)(iVar17 + 0x54) + 4) & 0x10000000) == 0) {
              *(uint *)(iVar17 + 0xef0) = *(uint *)(iVar17 + 0xef0) & 0xfffffffb;
              *(uint *)(iVar17 + 0x1fc) = uVar15 & 0xfffffdff;
            }
            else {
              *(uint *)(iVar17 + 0xef0) = *(uint *)(iVar17 + 0xef0) & 0xfffffffb;
              *(uint *)(iVar17 + 0x1fc) = uVar15 | 0x200;
            }
          }
          else {
            *(uint *)(iVar17 + 0x1fc) = uVar15 & 0xfffffdff;
            if (((*(byte *)(iVar17 + 0xeec) & 0x80) != 0) && (*(int *)(iVar17 + 0x3ac) != 0)) {
              iVar11 = FUN_005806a0(0,PTR_DAT_00802c54);
              bVar7 = true;
              if (*(float *)(iVar17 + 0x3b0) < *(float *)(iVar11 + 0x14) * *(float *)(iVar11 + 0x10)
                 ) {
                FUN_005b3800(local_424,*(int *)(iVar17 + 0x3ac) + 0x80,iVar17 + 0x80);
                if (*(float *)(iVar17 + 0x3b0) == 0.0) {
                  fVar1 = 0.0;
                }
                else {
                  fVar1 = 1.0 / *(float *)(iVar17 + 0x3b0);
                }
                FUN_005b3830(local_424,local_424,fVar1);
                FUN_005b3620(local_40c,&DAT_0080250c,*(undefined2 *)(iVar17 + 0x5a));
                fVar20 = (float10)FUN_005b39e0(local_424,local_40c);
                if (0.5 <= *(float *)(iVar17 + 0x3b0)) {
                  iVar11 = 0x2000;
                  if (1.0 <= *(float *)(iVar17 + 0x3b0)) {
                    iVar11 = 0xaaa;
                  }
                }
                else {
                  iVar11 = 0x3555;
                }
                if ((float)(&DAT_029899a0)[iVar11 + 0x4000 >> 1] < (float)fVar20) {
                  puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 8);
                  *puVar12 = *puVar12 | DAT_0080227c;
                  *(undefined4 *)(iVar17 + 0xea0) = **(undefined4 **)(iVar17 + 0x3ac);
                }
              }
            }
            if (((DAT_0093b2a4 != 0) && ((*(uint *)(iVar17 + 0x1f8) & 0x400) == 0)) &&
               (*(short *)(iVar17 + 0x1064) == DAT_007f1900)) {
              puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 8);
              *puVar12 = *puVar12 | DAT_0080228c;
            }
            if ((((*(byte *)(iVar17 + 0xeec) & 2) != 0) &&
                ((((*(uint *)(iVar17 + 0x1f8) & 0x400) != 0 || (DAT_00876cc8 == 0)) ||
                 ((*(byte *)(iVar17 + 0xef3) & 1) != 0)))) &&
               (((iVar11 = FUN_0055bc80(iVar17,0), iVar11 != 0 ||
                 (sVar13 = *(short *)(iVar17 + 0x1064), sVar13 == DAT_007f1968)) ||
                ((sVar13 == DAT_007f187c || ((sVar13 == DAT_007f1878 || (sVar13 == DAT_007f1884)))))
                ))) {
              if (((*(byte *)(iVar17 + 0xeec) & 1) != 0) ||
                 ((*(int *)(iVar17 + 0x3ac) != 0 || ((*(uint *)(iVar17 + 0xe20) & 0x80000) != 0))))
              {
                *(undefined4 *)(iVar17 + 0xecc) = _DAT_007f6730;
              }
              if (0.0 < *(float *)(iVar17 + 0xecc)) {
                bVar7 = true;
                if (((*(uint *)(iVar17 + 0xe20) & 0x10000) != 0) &&
                   ((*(uint *)(iVar17 + 0xe20) & 0x80000) != 0)) {
                  puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 8);
                  *puVar12 = *puVar12 | DAT_0080227c;
                }
              }
            }
            if (((*(uint *)(iVar17 + 0xeec) & 0x20000000) != 0) &&
               (bVar7 = true, (*(byte *)(iVar17 + 0xe22) & 1) != 0)) {
              puVar12 = (uint *)(*(int *)(iVar17 + 0xca4) + 8);
              *puVar12 = *puVar12 | DAT_0080227c;
              *(uint *)(iVar17 + 0xeec) = *(uint *)(iVar17 + 0xeec) & 0xdfffffff;
            }
            if ((((*(short *)(iVar17 + 0x1064) == DAT_007f18c8) ||
                 (*(short *)(iVar17 + 0x1064) == DAT_007f18cc)) &&
                ((*(byte *)(iVar17 + 0x1fc) & 0x80) == 0)) && (*(char *)(iVar17 + 0x280) != -1)) {
              bVar7 = true;
            }
            if (((*(uint *)(iVar17 + 0xeec) & 8) == 0) ||
               ((!bVar7 && ((*(uint *)(iVar17 + 0xeec) & 0x30) == 0)))) {
              iVar11 = *(int *)(iVar17 + 0xca4);
              if (((*(uint *)(iVar11 + 8) & DAT_0080227c) == 0) &&
                 ((((*(byte *)(iVar17 + 0xe22) & 1) != 0 && (*(char *)(iVar17 + 0x7b5) != '\x06'))
                  && (uVar15 = DAT_00802280, *(char *)(iVar17 + 0xe33) == '\0'))))
              goto LAB_0043f7f5;
            }
            else if ((((*(byte *)(iVar17 + 0xe22) & 1) == 0) && (*(char *)(iVar17 + 0x7b5) != '\a'))
                    && (*(char *)(iVar17 + 0xe33) == '\0')) {
              iVar11 = *(int *)(iVar17 + 0xca4);
              uVar15 = DAT_0080227c;
LAB_0043f7f5:
              *(uint *)(iVar11 + 8) = *(uint *)(iVar11 + 8) | uVar15;
            }
          }
          iVar11 = *(int *)(*(int *)(iVar17 + 0x54) + 0x24);
          if (((*(uint *)(iVar11 + 0x94) & 0x10000000) != 0) &&
             ((*(byte *)(iVar17 + 0x1fc) & 0x80) == 0)) {
            iVar6 = *(int *)(iVar17 + 0xca4);
            bVar7 = *(float *)(iVar6 + 0x28) <= *(float *)(iVar11 + 0x18) - 0.01;
            if (*(char *)(iVar17 + 0xe32) == '\x01') {
              if (bVar7) {
                fVar1 = *(float *)(iVar17 + 0xde8) + _DAT_00925018;
                *(float *)(iVar17 + 0xde8) = fVar1;
                if (fVar1 <= 0.1) goto LAB_0043f8b3;
                *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | DAT_00802278;
              }
            }
            else if (!bVar7) {
              fVar1 = *(float *)(iVar17 + 0xde8) + _DAT_00925018;
              *(float *)(iVar17 + 0xde8) = fVar1;
              if (fVar1 <= 1.0) goto LAB_0043f8b3;
              *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) | DAT_00802278;
            }
            *(undefined4 *)(iVar17 + 0xde8) = 0;
          }
LAB_0043f8b3:
          if (*(undefined4 **)(iVar17 + 0x3ac) != (undefined4 *)0x0) {
            FUN_0058bfb0(iVar17,**(undefined4 **)(iVar17 + 0x3ac),2,0x3f800000,0,0);
          }
          goto LAB_0043f8e1;
        }
        if ((((*(uint *)(iVar17 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar17 + 0x28b) != '\0')) ||
           ((*(int *)(iVar17 + 0xeac) != 0 ||
            ((*(uint *)(*(int *)(*(int *)(iVar17 + 0x54) + 0x24) + 0x90) & 0x8000) != 0)))) {
          if (*(float *)(iVar17 + 0x1010) <= 0.0) {
            *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) & 0xffffdfff;
            *(undefined4 *)(iVar17 + 0x39c) = 0;
            *(undefined4 *)(iVar17 + 0x3ac) = 0;
          }
          else {
            *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) | 0x2000;
          }
        }
        else {
          local_444 = local_444 + 1;
          *local_430 = iVar17;
          local_430 = local_430 + 1;
          sVar13 = (short)DAT_0093d500 - (ushort)*(byte *)(iVar17 + 0x28d);
          *(uint *)(iVar17 + 0x4b0) = *(uint *)(iVar17 + 0x4b0) | 0x2000;
          *(short *)(iVar17 + 0x292) = sVar13;
          *(undefined2 *)(iVar17 + 0x294) = 0;
        }
        if ((*(int *)(iVar17 + 0x10a4) != 0) &&
           ((*(byte *)(*(int *)(iVar17 + 0x10a4) + 0x1fc) & 1) == 0)) {
          *(undefined4 *)(iVar17 + 0x10a4) = 0;
        }
        iVar11 = *(int *)(iVar17 + 0x3ac);
        if ((iVar11 != 0) &&
           (((*(byte *)(iVar11 + 0x1fc) & 1) == 0 ||
            ((*(uint *)(*(int *)(iVar11 + 4) + 0x1e8) & 0x2000) == 0)))) {
          *(undefined4 *)(iVar17 + 0x3b0) = 0x4e6e6b28;
          *(undefined4 *)(iVar17 + 0x3ac) = 0;
        }
        if ((*(byte *)(iVar17 + 0xef4) & 8) != 0) {
          FUN_005371a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar17,iVar17 + 0x2c8,uVar16,
                       *(undefined4 *)(iVar17 + 0x10b8));
        }
      }
      local_450 = local_450 + 1;
      iVar17 = iVar17 + 0x10d8;
    } while (local_450 < DAT_0093d500);
  }
  _DAT_00876ce0 = 1e+09;
  _DAT_0092387c = local_448;
  _DAT_00923880 = local_44c;
  DAT_00876ce8 = local_438;
  iVar17 = local_44c;
  if (0 < local_438) {
    piVar18 = local_100;
    piVar19 = local_400 + local_44c;
    for (iVar17 = local_438; iVar17 != 0; iVar17 = iVar17 + -1) {
      *piVar19 = *piVar18;
      piVar18 = piVar18 + 1;
      piVar19 = piVar19 + 1;
    }
    iVar17 = local_438 + local_44c;
  }
  if (DAT_007f672c != 0) {
    _DAT_00876ce0 = ((float)(iVar17 * iVar17) * _DAT_00925018) / (float)DAT_007f672c;
  }
  FUN_0062ab90(*(undefined4 *)(PTR_DAT_00802c54 + 0x298c),DAT_007f672c,local_448,local_300,iVar17,
               local_400,(float)*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xce));
  if (DAT_00876cf0 == 0) {
    FUN_00519e00(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_444,local_200,0,_DAT_00925018);
  }
  else {
    FUN_0043af40();
  }
  if (DAT_00876cc8 != 0) {
    if (DAT_0093d7f0 != 0) {
      *(uint *)(DAT_0093d7f0 + 0x4b0) = *(uint *)(DAT_0093d7f0 + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d7f4 != 0) {
      *(uint *)(DAT_0093d7f4 + 0x4b0) = *(uint *)(DAT_0093d7f4 + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d7f8 != 0) {
      *(uint *)(DAT_0093d7f8 + 0x4b0) = *(uint *)(DAT_0093d7f8 + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d7fc != 0) {
      *(uint *)(DAT_0093d7fc + 0x4b0) = *(uint *)(DAT_0093d7fc + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d800 != 0) {
      *(uint *)(DAT_0093d800 + 0x4b0) = *(uint *)(DAT_0093d800 + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d804 != 0) {
      *(uint *)(DAT_0093d804 + 0x4b0) = *(uint *)(DAT_0093d804 + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d808 != 0) {
      *(uint *)(DAT_0093d808 + 0x4b0) = *(uint *)(DAT_0093d808 + 0x4b0) & 0xffffbfff;
    }
    if (DAT_0093d80c != 0) {
      *(uint *)(DAT_0093d80c + 0x4b0) = *(uint *)(DAT_0093d80c + 0x4b0) & 0xffffbfff;
    }
  }
  FUN_00439a50(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_444,local_200,local_448,local_300,
               local_44c,local_400,local_42c,local_428,_DAT_00925018);
  FUN_005acf30(*(undefined4 *)(PTR_DAT_00802c54 + 0x46b8),local_448,local_300,local_44c,local_400);
  FUN_0043d590();
  return;
}

