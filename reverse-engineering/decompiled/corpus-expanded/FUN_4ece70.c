/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ece70; label: FUN_004ece70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ece70(int param_1)

{
  char cVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  byte bVar12;
  bool bVar13;
  float10 extraout_ST0;
  float10 fVar14;
  float10 extraout_ST1;
  int local_18;
  int local_c [2];
  float local_4;
  
  if (DAT_00951b50 == 0) {
    *(undefined2 *)(DAT_0088a628 + 0xe) = 0;
    FUN_005ab050(DAT_0095df4c,"HelpWithDisco",0,DAT_0088aac0);
    FUN_005ab050(DAT_0095df4c,"DiscoComplete",0,DAT_0088aac4);
    FUN_005ab050(DAT_0095df4c,"DiscoState",(float)(int)DAT_0088aaad,DAT_0088aac8);
    piVar5 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00805ebc,"qaz_panel2");
    FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),piVar5,0,0);
    iVar6 = FUN_0058ecf0(DAT_0088a560);
    if (((iVar6 == 0) || (iVar6 = FUN_0058ecf0(DAT_0088a564), iVar6 == 0)) ||
       (*(int *)(*(int *)(*piVar5 + 0x20) + 0xc) != 2)) {
      bVar13 = false;
    }
    else {
      bVar13 = true;
      if (*(float *)(DAT_0088aac4 + 0x28) == 0.0) {
        FUN_005ab050(DAT_0095df4c,"discoflooropen",0x3f800000,0);
        bVar13 = true;
      }
    }
    if (DAT_0088aaad == '\0') {
      *(undefined1 *)(DAT_0088a628 + 0x10) = 0;
      iVar6 = FUN_005cfac0(&DAT_0088a678);
      if (((iVar6 != 0) && (bVar13)) &&
         (((DAT_0093d810 != 0 &&
           (uVar9 = 1 << ((byte)(DAT_0088a6d0 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6) &
                         0x1f),
           (uVar9 & *(uint *)(DAT_0093d810 + 0x2b0)) != 0 ||
           ((int)uVar9 >> 0x1f & *(uint *)(DAT_0093d810 + 0x2b4)) != 0)) ||
          ((DAT_0093d814 != 0 &&
           (uVar9 = 1 << ((byte)(DAT_0088a6d0 - *(int *)(*(int *)(param_1 + 0x2ae8) + 0x38) >> 6) &
                         0x1f),
           (uVar9 & *(uint *)(DAT_0093d814 + 0x2b0)) != 0 ||
           ((int)uVar9 >> 0x1f & *(uint *)(DAT_0093d814 + 0x2b4)) != 0)))))) {
        _DAT_0088aab0 = 0.0;
        DAT_0088aaad = '\x01';
        DAT_0088aaae = FUN_004ece10();
        DAT_0088aaaf = FUN_004ece10();
        if ((DAT_0088aaae != -1) && (DAT_0088aaaf != -1)) {
          (&DAT_0088aa9c)[DAT_0088aaae] = 1;
          (&DAT_0088aa9c)[DAT_0088aaaf] = 1;
        }
      }
LAB_004ed419:
      if (DAT_0088aaad != '\0') goto LAB_004ed426;
    }
    else {
      if (DAT_0088aaad != '\x01') {
        if (DAT_0088aaad == '\x02') {
          *(undefined1 *)(DAT_0088a628 + 0x10) = 1;
          _DAT_0088aab0 = _DAT_00925018 + _DAT_0088aab0;
          if ((_DAT_008002e0 < _DAT_0088aab0) || (!bVar13)) {
            *(undefined1 *)(DAT_0088a628 + 0x10) = 0;
            FUN_004ecb50(param_1);
            return;
          }
        }
        goto LAB_004ed419;
      }
      *(undefined1 *)(DAT_0088a628 + 0x10) = 0;
      if (!bVar13) {
        FUN_004ecb50(param_1);
        goto LAB_004ed419;
      }
      local_18 = -1;
      iVar6 = 0;
      do {
        cVar1 = (&DAT_0088aa9c)[(&DAT_0088aaae)[iVar6]];
        (&DAT_0088aa9c)[(&DAT_0088aaae)[iVar6]] = 1;
        cVar2 = (&DAT_0088aaae)[iVar6];
        local_c[iVar6] = 0;
        pfVar7 = (float *)FUN_005cf9c0(&DAT_0088a794 + cVar2 * 0xc);
        piVar5 = &DAT_0093d7f0;
        do {
          iVar8 = *piVar5;
          if ((((iVar8 != 0) && ((*(uint *)(iVar8 + 0x1fc) & 1) != 0)) &&
              ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0)) &&
             ((*(char *)(iVar8 + 0x281) != '\0' &&
              (fVar3 = *pfVar7 - *(float *)(iVar8 + 0x5c),
              fVar4 = pfVar7[2] - *(float *)(iVar8 + 100),
              fVar3 * fVar3 + fVar4 * fVar4 < _DAT_00800354 * _DAT_00800354)))) {
            bVar13 = iVar8 == DAT_0093d810;
            cVar2 = (&DAT_0088aaae)[iVar6];
            local_c[iVar6] = 1;
            (&DAT_0088aa9c)[cVar2] = 2;
            if (bVar13) {
              local_18 = (int)(&DAT_0088aaae)[iVar6];
            }
            break;
          }
          piVar5 = piVar5 + 1;
        } while ((int)piVar5 < 0x93d810);
        if ((cVar1 != (&DAT_0088aa9c)[(&DAT_0088aaae)[iVar6]]) &&
           ((&DAT_0088aa9c)[(&DAT_0088aaae)[iVar6]] == '\x02')) {
          _DAT_0088aacc = FUN_005d0330(&DAT_0088a914 + (&DAT_0088aaae)[iVar6] * 0xc);
          _DAT_0088aacc = _DAT_0088aacc + 0x30;
          *(ushort *)(DAT_0088a628 + 0xe) =
               *(ushort *)(DAT_0088a628 + 0xe) | (ushort)(1 << ((&DAT_0088aaae)[iVar6] & 0x1fU));
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 2);
      if ((local_c[0] == 0) || (local_c[1] == 0)) {
        _DAT_0088aab0 = _DAT_00925018 + _DAT_0088aab0;
        if (_DAT_00800350 < _DAT_0088aab0) {
          iVar6 = 2;
          _DAT_0088aab0 = 0.0;
          do {
            iVar8 = FUN_004ece10();
            if (iVar8 != -1) {
              (&DAT_0088aa9c)[iVar8] = 0;
            }
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        if ((DAT_0093d814 == 0) && (DAT_0087aad4 != 0)) {
          iVar6 = DAT_0093d7f0;
          if (DAT_0093d810 == DAT_0093d7f0) {
            iVar6 = DAT_0093d7f4;
          }
          if (iVar6 != 0) {
            iVar6 = (int)DAT_0088aaae;
            if (local_18 == iVar6) {
              iVar6 = (int)DAT_0088aaaf;
            }
            else if (local_18 != DAT_0088aaaf) goto LAB_004ed419;
            puVar10 = (undefined4 *)FUN_005cf9c0(&DAT_0088a794 + iVar6 * 0xc);
            if (puVar10 != (undefined4 *)0x0) {
              FUN_005ab050(DAT_0095df4c,"HelpWithDisco",0x3f800000,DAT_0088aac0);
              *(undefined4 *)(DAT_0087aad4 + 0x10) = *puVar10;
              *(undefined4 *)(DAT_0087aad4 + 0x18) = puVar10[2];
            }
          }
        }
        goto LAB_004ed419;
      }
      _DAT_0088aab0 = 0.0;
      (&DAT_0088aa9c)[DAT_0088aaae] = 3;
      (&DAT_0088aa9c)[DAT_0088aaaf] = 3;
      DAT_0088aaae = FUN_004ece10();
      DAT_0088aaaf = FUN_004ece10();
      if ((DAT_0088aaae != -1) && (DAT_0088aaaf != -1)) {
        (&DAT_0088aa9c)[DAT_0088aaae] = 1;
        (&DAT_0088aa9c)[DAT_0088aaaf] = 1;
        goto LAB_004ed419;
      }
      iVar6 = 0;
      DAT_0088aaad = '\x02';
      if ('\0' < DAT_0088aaac) {
        do {
          (&DAT_0088aa9c)[iVar6] = 4;
          iVar6 = iVar6 + 1;
        } while (iVar6 < DAT_0088aaac);
        goto LAB_004ed419;
      }
LAB_004ed426:
      iVar6 = FUN_006e6b90();
      fVar14 = (float10)FUN_0054fb40((float)extraout_ST0,(float)extraout_ST1,
                                     (1.0 - ((float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] + 1.0) *
                                            0.5) * _DAT_008002dc);
      _DAT_0088aab8 = (float)fVar14;
    }
    iVar6 = 0;
    *(undefined2 *)(DAT_0088a628 + 4) = 0;
    *(undefined2 *)(DAT_0088a628 + 6) = 0;
    *(undefined2 *)(DAT_0088a628 + 8) = 0;
    *(undefined2 *)(DAT_0088a628 + 10) = 0;
    *(undefined2 *)(DAT_0088a628 + 0xc) = 0;
    if ('\0' < DAT_0088aaac) {
      do {
        bVar12 = (byte)iVar6;
        switch((&DAT_0088aa9c)[iVar6]) {
        case 0:
          *(ushort *)(DAT_0088a628 + 4) =
               *(ushort *)(DAT_0088a628 + 4) | (ushort)(1 << (bVar12 & 0x1f));
          break;
        case 1:
          *(ushort *)(DAT_0088a628 + 6) =
               *(ushort *)(DAT_0088a628 + 6) | (ushort)(1 << (bVar12 & 0x1f));
          break;
        case 2:
          *(ushort *)(DAT_0088a628 + 8) =
               *(ushort *)(DAT_0088a628 + 8) | (ushort)(1 << (bVar12 & 0x1f));
          break;
        case 3:
          *(ushort *)(DAT_0088a628 + 10) =
               *(ushort *)(DAT_0088a628 + 10) | (ushort)(1 << (bVar12 & 0x1f));
          break;
        case 4:
          *(ushort *)(DAT_0088a628 + 0xc) =
               *(ushort *)(DAT_0088a628 + 0xc) | (ushort)(1 << (bVar12 & 0x1f));
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_0088aaac);
    }
  }
  if (DAT_0087aa20 == '\0') {
    iVar6 = FUN_005cfd60(&DAT_0087aad8);
    if (iVar6 == 0) {
      if (DAT_0087aa20 == '\0') goto LAB_004ed698;
    }
    else {
      puVar10 = (undefined4 *)FUN_005cf9e0(&DAT_0087aad8);
      _DAT_0088aafc = *puVar10;
      _DAT_0088ab08 = 0.05;
      _DAT_0088ab00 = puVar10[1];
      _DAT_0088ab04 = (float)puVar10[2];
      DAT_0087aa20 = '\x01';
    }
  }
  _DAT_0088ab08 = _DAT_0088ab08 - _DAT_00925018;
  if (_DAT_0088ab08 <= 0.0) {
    _DAT_0088ab08 = 0.1;
  }
  iVar6 = FUN_006e6b90();
  local_4 = ((1.0 - ((float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] + 1.0) * 0.5) * 0.01 - 0.005) +
            _DAT_0088ab04;
  iVar6 = FUN_005cf9e0(&DAT_0087aad8);
  *(float *)(iVar6 + 8) = local_4;
  uVar11 = FUN_005cf9e0(&DAT_0087aad8);
  FUN_00681f40("env_curtain_lp",uVar11);
LAB_004ed698:
  FUN_004ec420(param_1);
  return;
}

