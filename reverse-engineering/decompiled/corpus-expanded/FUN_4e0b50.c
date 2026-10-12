/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e0b50; label: FUN_004e0b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e0b50(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  float *pfVar10;
  byte bVar11;
  int *piVar12;
  bool bVar13;
  undefined4 uVar14;
  int local_18;
  int local_c;
  int local_8 [2];
  
  iVar8 = *DAT_0087a96c;
  iVar7 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a96c,0,0);
  if (iVar7 == 0) {
    if ((*(byte *)(iVar8 + 0x94) & 1) == 0) {
      FUN_0055a250(*(undefined4 *)(param_1 + 0x2ac8),DAT_0087a970,1,1);
      iVar8 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_00882b6c,0,0);
      if ((iVar8 != 0) &&
         (iVar8 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),DAT_00882b70,0,0), iVar8 != 0)) {
        uVar14 = *(undefined4 *)(param_1 + 0x2ac8);
        goto LAB_004e0bfa;
      }
    }
  }
  else {
    uVar14 = *(undefined4 *)(param_1 + 0x2ac8);
LAB_004e0bfa:
    FUN_0055a2b0(uVar14,DAT_0087a970,0,1);
  }
  DAT_00882b74[5] = 0;
  FUN_005ab050(DAT_0095df4c,"NextDiscoTile",0,DAT_00889488);
  FUN_005ab050(DAT_0095df4c,"DiscoComplete",0,DAT_0088948c);
  if (DAT_0088947d == '\0') {
    iVar8 = *(int *)(param_1 + 0x2ae8);
    if ((((*(int *)(iVar8 + 0x138c) != 0) && (DAT_008890a8 != 0)) &&
        (uVar9 = 1 << ((byte)(DAT_008890a8 - *(int *)(iVar8 + 0x38) >> 6) & 0x1f),
        (uVar9 & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b0)) != 0 ||
        ((int)uVar9 >> 0x1f & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b4)) != 0)) ||
       (((*(int *)(iVar8 + 0x1390) != 0 && (DAT_008890a8 != 0)) &&
        (uVar9 = 1 << ((byte)(DAT_008890a8 - *(int *)(iVar8 + 0x38) >> 6) & 0x1f),
        (uVar9 & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b0)) != 0 ||
        ((int)uVar9 >> 0x1f & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b4)) != 0)))) {
      *(undefined1 *)(DAT_00882b74 + 6) = 0;
      _DAT_00889480 = 0.0;
      DAT_0088947d = '\x01';
      DAT_0088947e = FUN_004e0850();
      DAT_0088947f = FUN_004e0850();
      if ((DAT_0088947e != -1) && (DAT_0088947f != -1)) {
        (&DAT_0088946c)[DAT_0088947e] = 1;
        (&DAT_0088946c)[DAT_0088947f] = 1;
      }
    }
  }
  else if (DAT_0088947d == '\x01') {
    iVar7 = 0;
    local_18 = -1;
    iVar8 = 2;
    do {
      cVar1 = (&DAT_0088946c)[(&DAT_0088947e)[iVar7]];
      (&DAT_0088946c)[(&DAT_0088947e)[iVar7]] = 1;
      cVar2 = (&DAT_0088947e)[iVar7];
      local_8[iVar7] = 0;
      pfVar10 = (float *)FUN_005cf9c0(&DAT_0088916c + cVar2 * 0xc);
      piVar12 = &DAT_0093d7f0;
      do {
        iVar3 = *piVar12;
        if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 1) != 0)) &&
           (((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0 &&
            ((*(char *)(iVar3 + 0x281) != '\0' &&
             (fVar4 = *pfVar10 - *(float *)(iVar3 + 0x5c),
             fVar5 = pfVar10[1] - *(float *)(iVar3 + 0x60),
             fVar6 = pfVar10[2] - *(float *)(iVar3 + 100),
             fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5 < _DAT_00800054 * _DAT_00800054)))))) {
          bVar13 = iVar3 == DAT_0093d810;
          cVar2 = (&DAT_0088947e)[iVar7];
          local_8[iVar7] = 1;
          (&DAT_0088946c)[cVar2] = 2;
          if (bVar13) {
            local_18 = (int)(&DAT_0088947e)[iVar7];
          }
          break;
        }
        piVar12 = piVar12 + 1;
      } while ((int)piVar12 < 0x93d810);
      if ((cVar1 != (&DAT_0088946c)[(&DAT_0088947e)[iVar7]]) &&
         ((&DAT_0088946c)[(&DAT_0088947e)[iVar7]] == '\x02')) {
        DAT_00882b74[5] = DAT_00882b74[5] | (ushort)(1 << ((&DAT_0088947e)[iVar7] & 0x1fU));
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
    if ((local_8[0] == 0) || (local_8[1] == 0)) {
      _DAT_00889480 = _DAT_00925018 + _DAT_00889480;
      if (_DAT_00800050 < _DAT_00889480) {
        _DAT_00889480 = 0.0;
        do {
          iVar7 = FUN_004e0850();
          if (iVar7 != -1) {
            (&DAT_0088946c)[iVar7] = 0;
          }
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      if (DAT_0093d814 == 0) {
        iVar8 = DAT_0093d7f0;
        if (DAT_0093d810 == DAT_0093d7f0) {
          iVar8 = DAT_0093d7f4;
        }
        if (iVar8 != 0) {
          local_c = (int)DAT_0088947e;
          if (local_18 == local_c) {
            local_c = (int)DAT_0088947f;
          }
          else if (local_18 != DAT_0088947f) goto LAB_004e1013;
          local_c = local_c + 1;
          FUN_005ab050(DAT_0095df4c,"NextDiscoTile",(float)local_c,DAT_00889488);
        }
      }
    }
    else {
      _DAT_00889480 = 0.0;
      (&DAT_0088946c)[DAT_0088947e] = 3;
      (&DAT_0088946c)[DAT_0088947f] = 3;
      DAT_0088947e = FUN_004e0850();
      DAT_0088947f = FUN_004e0850();
      if ((DAT_0088947e == -1) || (DAT_0088947f == -1)) {
        iVar8 = 0;
        DAT_0088947d = '\x02';
        if ('\0' < DAT_0088947c) {
          do {
            (&DAT_0088946c)[iVar8] = 0;
            iVar8 = iVar8 + 1;
          } while (iVar8 < DAT_0088947c);
        }
      }
      else {
        (&DAT_0088946c)[DAT_0088947e] = 1;
        (&DAT_0088946c)[DAT_0088947f] = 1;
      }
    }
  }
  else if (DAT_0088947d == '\x02') {
    FUN_005ab050(DAT_0095df4c,"DiscoComplete",0x3f800000,DAT_0088948c);
    *(undefined1 *)(DAT_00882b74 + 6) = 1;
    iVar8 = *(int *)(param_1 + 0x2ae8);
    if ((((*(int *)(iVar8 + 0x138c) != 0) && (DAT_008890a8 != 0)) &&
        (uVar9 = 1 << ((byte)(DAT_008890a8 - *(int *)(iVar8 + 0x38) >> 6) & 0x1f),
        (uVar9 & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b0)) != 0 ||
        ((int)uVar9 >> 0x1f & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b4)) != 0)) ||
       (((*(int *)(iVar8 + 0x1390) != 0 && (DAT_008890a8 != 0)) &&
        (uVar9 = 1 << ((byte)(DAT_008890a8 - *(int *)(iVar8 + 0x38) >> 6) & 0x1f),
        (uVar9 & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b0)) != 0 ||
        ((int)uVar9 >> 0x1f & *(uint *)(*(int *)(iVar8 + 0x138c) + 0x2b4)) != 0)))) {
      iVar8 = 0;
      if ('\0' < DAT_0088947c) {
        do {
          (&DAT_0088946c)[iVar8] = 4;
          iVar8 = iVar8 + 1;
        } while (iVar8 < DAT_0088947c);
      }
      _DAT_00889480 = _DAT_00925018 + _DAT_00889480;
      if (_DAT_00889480 <= 20.0) goto LAB_004e1013;
    }
    FUN_004e06e0(param_1);
    return;
  }
LAB_004e1013:
  iVar8 = 0;
  DAT_00882b74[4] = 0;
  *DAT_00882b74 = 0;
  DAT_00882b74[1] = 0;
  DAT_00882b74[2] = 0;
  DAT_00882b74[3] = 0;
  if ('\0' < DAT_0088947c) {
    do {
      bVar11 = (byte)iVar8;
      switch((&DAT_0088946c)[iVar8]) {
      case 0:
        *DAT_00882b74 = *DAT_00882b74 | (ushort)(1 << (bVar11 & 0x1f));
        break;
      case 1:
        DAT_00882b74[1] = DAT_00882b74[1] | (ushort)(1 << (bVar11 & 0x1f));
        break;
      case 2:
        DAT_00882b74[2] = DAT_00882b74[2] | (ushort)(1 << (bVar11 & 0x1f));
        break;
      case 3:
        DAT_00882b74[4] = DAT_00882b74[4] | (ushort)(1 << (bVar11 & 0x1f));
        break;
      case 4:
        DAT_00882b74[3] = DAT_00882b74[3] | (ushort)(1 << (bVar11 & 0x1f));
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < DAT_0088947c);
  }
  FUN_004e08b0(param_1);
  return;
}

