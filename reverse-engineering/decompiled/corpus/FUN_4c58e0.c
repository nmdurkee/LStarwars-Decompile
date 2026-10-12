/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c58e0; label: FUN_004c58e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c58e0(void)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  int iVar11;
  bool bVar12;
  float10 extraout_ST0;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST1;
  float local_30;
  float local_2c;
  undefined *local_28;
  undefined4 *local_24;
  undefined *local_20;
  undefined *local_1c;
  float local_10;
  undefined *local_c;
  short local_4;
  
  local_10 = 0.0;
  if (_DAT_0088048c <= 0.0) {
    _DAT_0088048c = 0.0;
  }
  else {
    local_10 = _DAT_0088048c / _DAT_007fcb6c;
    _DAT_0088048c = _DAT_0088048c - _DAT_00925018;
  }
  iVar7 = FUN_006e6b90();
  fVar6 = _DAT_008800a4;
  fVar1 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
  switch(DAT_008801ac) {
  case 0:
    local_1c = DAT_0088047c;
    local_24 = (undefined4 *)&DAT_008800bc;
    local_20 = &DAT_0087bd98;
    fVar4 = _DAT_007fcb74;
    break;
  case 1:
    local_1c = DAT_00880478;
    local_24 = (undefined4 *)&DAT_0087bdec;
    local_20 = &DAT_0087be60;
    fVar4 = _DAT_007fcb7c;
    break;
  case 2:
    local_1c = DAT_00880480;
    local_24 = (undefined4 *)&DAT_0087bf00;
    local_20 = &DAT_0087bf38;
    fVar4 = _DAT_007fcb78;
    break;
  default:
    return;
  case 4:
    local_1c = DAT_00880488;
    local_24 = (undefined4 *)&DAT_0087ff98;
    local_20 = &DAT_0087c488;
    fVar4 = _DAT_007fcb84;
    break;
  case 5:
    local_1c = &DAT_0087c578;
    local_24 = &DAT_0087bed4;
    local_20 = &DAT_0087be08;
    fVar4 = _DAT_007fcb88;
  }
  iVar7 = 0;
  fVar13 = extraout_ST0;
  fVar14 = extraout_ST1;
  do {
    if (DAT_0087bb84 == 1) {
      bVar12 = iVar7 == 6;
LAB_004c5a7c:
      if (!bVar12) goto LAB_004c5a82;
switchD_004c5ba7_caseD_3:
    }
    else {
      if (DAT_0087bb84 == 2) {
        bVar12 = iVar7 == 0;
        goto LAB_004c5a7c;
      }
LAB_004c5a82:
      local_28 = (undefined *)0x0;
      fVar5 = _DAT_0087bd7c;
      if ((iVar7 == 0) || (fVar5 = _DAT_0087bd94, iVar7 == 6)) {
LAB_004c5ad3:
        local_2c = fVar5 * _DAT_0087bbc4 * fVar4;
        local_30 = fVar5 * fVar6;
      }
      else {
        if (DAT_0087bb84 == 1) {
          if (iVar7 == 5) goto LAB_004c5ad3;
        }
        else if ((DAT_0087bb84 == 2) && (fVar5 = _DAT_0087bd7c, iVar7 == 1)) goto LAB_004c5ad3;
        if (iVar7 == 2) {
          local_2c = _DAT_0087bbc4 * _DAT_0087bed0 * fVar4;
          local_30 = _DAT_00880410;
        }
        else if (iVar7 == 3) {
          if (fVar14 <= fVar13) {
            local_28 = (undefined *)((int)ROUND(-local_10 * 65536.0) & 0xffff);
          }
          local_2c = _DAT_007fcb70 * (1.0 - (fVar1 + 1.0) * 0.5) +
                     _DAT_0087bbc4 * _DAT_008801cc * fVar4;
          local_30 = _DAT_00880414;
        }
        else if (iVar7 == 4) {
          local_2c = _DAT_0087bbc4 * _DAT_0087bb70 * fVar4;
          local_30 = _DAT_00880418;
        }
        else {
          local_2c = _DAT_0087bbc4 * fVar4;
          local_30 = fVar6;
        }
      }
      puVar10 = local_28;
      iVar11 = local_24[iVar7];
      switch(DAT_008801ac) {
      case 0:
        if (local_1c[iVar11 * 0x74 + 99] == '\x01') {
          if (fVar13 <= fVar14) {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            local_28 = (undefined *)((int)ROUND(fVar14 * (float10)0.25 * (float10)65536.0) & 0xffff)
            ;
          }
          else {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            fVar14 = fVar14 * (float10)0.25 * (float10)65536.0;
            if (iVar7 == 3) {
              local_c._0_2_ = (short)(int)ROUND(fVar14);
              local_28 = (undefined *)(uint)(ushort)((short)local_28 + (short)local_c);
            }
            else {
              local_28 = (undefined *)((int)ROUND(fVar14) & 0xffff);
            }
          }
        }
        if (local_1c[iVar11 * 0x74 + 99] != '\x01') {
          local_28 = (undefined *)0x0;
        }
        iVar11 = (int)local_28 + _DAT_008804a0;
        if (local_1c[local_24[iVar7] * 0x74 + 99] == '\x01') {
          FUN_004c51f0(&DAT_0087c000,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0)
          ;
        }
        else {
          FUN_004c51f0(&DAT_0087bb88,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0)
          ;
          FUN_004c51f0(&DAT_0087c15c,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0)
          ;
        }
        break;
      case 1:
        fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,_DAT_007fcc80);
        uVar9 = (int)ROUND((float)(&DAT_029899a0)
                                  [(int)(((int)ROUND((fVar14 / (float10)_DAT_007fcc80) *
                                                     (float10)65536.0) & 0xffffU) + 0x4000) >> 1 &
                                   0x7fff] * 4369.0) & 0xffff;
        if (local_1c[iVar11 * 0x74 + 99] != '\x01') {
          uVar9 = 0;
        }
        FUN_004c5020(local_20 + iVar7 * 0xc,local_2c,local_30,0,_DAT_008804a0 + uVar9,0);
        break;
      case 2:
        if (local_1c[iVar11 * 0x74 + 99] == '\x01') {
          if (fVar13 <= fVar14) {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            local_28 = (undefined *)((int)ROUND(fVar14 * (float10)0.25 * (float10)65536.0) & 0xffff)
            ;
          }
          else {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            fVar14 = fVar14 * (float10)0.25 * (float10)65536.0;
            if (iVar7 == 3) {
              local_c._0_2_ = (short)(int)ROUND(fVar14);
              local_28 = (undefined *)(uint)(ushort)((short)local_28 + (short)local_c);
            }
            else {
              local_28 = (undefined *)((int)ROUND(fVar14) & 0xffff);
            }
          }
          if (local_1c[iVar11 * 0x74 + 99] != '\x01') {
            local_28 = (undefined *)0x0;
          }
          iVar11 = (int)local_28 + _DAT_008804a0;
          FUN_004c51f0(&DAT_008800e8,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0)
          ;
          FUN_004c5300(local_2c,0x3f800000,1,local_30,0,iVar11,0);
        }
        else {
          if (local_1c[iVar11 * 0x74 + 99] != '\x01') {
            local_28 = (undefined *)0x0;
          }
          iVar11 = (int)local_28 + _DAT_008804a0;
          FUN_004c51f0(&DAT_008800e8,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0)
          ;
          uVar9 = (uint)*(ushort *)(local_1c + local_24[iVar7] * 0x74 + 0x60);
          if (((((&DAT_0086e4c8)[(int)uVar9 >> 5] &
                1 << ((byte)*(ushort *)(local_1c + local_24[iVar7] * 0x74 + 0x60) & 0x1f)) == 0) &&
              (7 < uVar9)) &&
             (((&DAT_007f3da3)[uVar9 * 0x20] != -1 &&
              ((&DAT_0086e0fa)[(char)(&DAT_007f3da3)[uVar9 * 0x20] * 0xc] == '\0')))) {
            iVar8 = FUN_005cfac0(&DAT_0087c268 + local_24[iVar7] * 0xc);
            if (iVar8 != 0) {
              FUN_004c51f0(&DAT_0087c268 + local_24[iVar7] * 0xc,local_20 + iVar7 * 0xc,local_2c,
                           0x3f800000,local_30,0,iVar11,0);
            }
          }
          else {
            FUN_004c5300(local_2c,0x3f800000,1,local_30,0,iVar11,0);
          }
        }
        break;
      default:
        goto switchD_004c5ba7_caseD_3;
      case 4:
        if (local_1c[iVar11 * 0x74 + 99] == '\x01') {
          if (fVar13 <= fVar14) {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            local_28._0_2_ = (short)(int)ROUND(fVar14 * (float10)0.25 * (float10)65536.0);
          }
          else {
            fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
            fVar14 = fVar14 * (float10)0.25 * (float10)65536.0;
            if (iVar7 == 3) {
              local_c._0_2_ = (short)(int)ROUND(fVar14);
              local_28._0_2_ = (short)local_28 + (short)local_c;
            }
            else {
              local_28._0_2_ = (short)(int)ROUND(fVar14);
            }
          }
          iVar8 = DAT_007fcc7c * 0x10000;
          local_28 = (undefined *)
                     (uint)(ushort)((short)local_28 +
                                   ((short)((ulonglong)((longlong)iVar8 * 0xb60b60b7) >> 0x28) -
                                   ((short)(char)((char)(iVar8 / 0x1680000) + (char)(iVar8 >> 0x1f))
                                   >> 0xf)) +
                                   *(short *)(local_1c + local_24[iVar7] * 0x74 + 0x60) * 0x1249);
        }
        if (local_1c[iVar11 * 0x74 + 99] != '\x01') {
          local_28 = (undefined *)0x0;
        }
        FUN_004c53d0(local_20 + iVar7 * 0xc,local_2c,local_30,0,_DAT_008804a0 + (int)local_28,0);
        break;
      case 5:
        uVar3 = *(ushort *)(local_1c + iVar11 * 0x74 + 0x60);
        if ((DAT_0088049c == (int *)0x0) || (iVar8 = FUN_0057e720((uint)uVar3), iVar8 == 0)) {
          local_28 = &DAT_0087bef0;
          local_c = &DAT_0087c4fc;
        }
        else {
          iVar8 = *(short *)(*DAT_0088049c + (uint)uVar3 * 0x44) * 0x130 + DAT_00951b78;
          uVar9 = (uint)*(char *)(iVar8 + 0xa3);
          bVar2 = *(byte *)(iVar8 + 0xa2);
          if (bVar2 == 0xff) {
            if (((uVar9 == 0xffffffff) || (DAT_0087b020 == 0)) ||
               (uVar9 != *(byte *)(DAT_0087b020 + 0x7c))) goto LAB_004c62ba;
            local_28 = &DAT_0087c520;
          }
          else if ((bVar2 & 1) == 0) {
LAB_004c62ba:
            local_28 = &DAT_008800e8;
          }
          else {
            local_28 = &DAT_0087c520;
          }
          local_c = &DAT_0087c250;
          fVar14 = (float10)FUN_005b7d30(_DAT_0092505c,0x40800000);
          local_4 = (short)(int)ROUND(fVar14 * (float10)0.25 * (float10)-65536.0);
          puVar10 = (undefined *)(uint)(ushort)(uVar3 * 0x1555 - local_4);
        }
        if (local_1c[iVar11 * 0x74 + 99] != '\x01') {
          puVar10 = (undefined *)0x0;
        }
        iVar11 = (int)puVar10 + _DAT_008804a0;
        FUN_004c51f0(local_28,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0);
        FUN_004c51f0(local_c,local_20 + iVar7 * 0xc,local_2c,0x3f800000,local_30,0,iVar11,0);
      }
    }
    iVar7 = iVar7 + 1;
    if (6 < iVar7) {
      return;
    }
    fVar14 = (float10)0;
    fVar13 = (float10)_DAT_0088048c;
  } while( true );
}

