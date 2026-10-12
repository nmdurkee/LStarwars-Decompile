/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x489150; label: FUN_00489150
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00489150(int param_1,undefined4 param_2,uint param_3)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  int iVar8;
  undefined **ppuVar9;
  int iVar10;
  int local_2b4 [2];
  short local_2ac [340];
  uint local_4;
  
  iVar4 = DAT_0087b02c;
  local_4 = DAT_00829570 ^ (uint)local_2b4;
  if ((((PTR_DAT_00802c54 == (undefined *)0x0) || (*(int *)(PTR_DAT_00802c54 + 300) == 0)) ||
      (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)) || (DAT_0087950c == 0)) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(&DAT_007fa138 + DAT_007fa190 * 0xc);
  }
  DAT_0087b2c4 = 0;
  DAT_0087a904 = 0;
  DAT_0087a954 = 0;
  if (param_1 == -1) {
    param_2 = 0xffffffff;
  }
  local_2b4[0] = param_1;
  local_2b4[1] = param_2;
  if (((DAT_007f39e4 == 0) || (DAT_0087b02c == 0)) || (param_3 != *(byte *)(DAT_0087b02c + 0x7c))) {
    iVar10 = 0;
    if ((*(byte *)(param_3 * 0x9c + 0x7a + DAT_00951354) & 5) == 5) {
      do {
        if (local_2b4[iVar10] != -1) {
          FUN_004890e0();
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < 2);
      FUN_00594b70(&DAT_00855f24,0x4000000,0x4000000,local_2ac,0,0,DAT_0087a9c8 != 0);
      iVar10 = 0;
      iVar4 = DAT_0087b02c;
      sVar2 = local_2ac[0];
      while (DAT_0087b02c = iVar4, sVar2 != -1) {
        FUN_004890e0();
        iVar10 = iVar10 + 1;
        iVar4 = DAT_0087b02c;
        sVar2 = local_2ac[iVar10];
      }
      if (DAT_0087b2c4 == 1) {
        DAT_0093d592 = DAT_0093d590;
      }
      _DAT_0093d594 = 0xffff;
    }
    else {
      do {
        if ((*(int *)((int)local_2b4 + iVar10) != -1) ||
           (*(int *)((int)&DAT_0093d7f0 + iVar10) != 0)) {
          FUN_004890e0();
        }
        iVar10 = iVar10 + 4;
      } while (iVar10 < 8);
      if (DAT_0087b2c4 == 1) {
        DAT_0093d592 = DAT_0093d590;
        _DAT_0093d594 = 0xffff;
      }
      else {
        (&DAT_0093d590)[DAT_0087b2c4] = 0xffff;
      }
    }
  }
  else {
    FUN_004890e0();
    FUN_004890e0();
    FUN_004890e0();
    FUN_004890e0();
    FUN_004890e0();
    FUN_004890e0();
  }
  if (((param_3 != 0xffffffff) && ((uVar7 & 8) == 0)) &&
     (psVar6 = *(short **)(param_3 * 0x9c + 0x98 + DAT_00951354), psVar6 != (short *)0x0)) {
    sVar2 = *psVar6;
    while (sVar2 != -1) {
      FUN_004890e0();
      DAT_0087a904 = DAT_0087a904 + 1;
      psVar1 = psVar6 + 1;
      psVar6 = psVar6 + 1;
      sVar2 = *psVar1;
    }
  }
  if (((DAT_007f39e4 == 0) || (iVar4 == 0)) ||
     (iVar10 = DAT_0087a954, param_3 != *(byte *)(iVar4 + 0x7c))) {
    uVar3 = *(ushort *)(DAT_00951354 + 0x7a + param_3 * 0x9c);
    if ((uVar3 & 1) == 0) {
      iVar4 = FUN_0055be20(&DAT_0087a840,0,0,1,0);
      if ((DAT_007f39e4 == 0) && (DAT_00876580 == 0)) {
        iVar10 = FUN_004890e0();
        if (iVar10 != 0) {
          DAT_0087a954 = DAT_0087a954 + 1;
        }
        iVar10 = FUN_004890e0();
        if (iVar10 != 0) {
          DAT_0087a954 = DAT_0087a954 + 1;
        }
      }
      iVar10 = DAT_0087a954;
      if (DAT_0093b280 != 0) {
        iVar10 = 0;
        if (0 < DAT_0093b26c) {
          iVar8 = 0;
          do {
            iVar5 = FUN_0055be20(&DAT_0087a840,*(undefined4 *)(DAT_0093b280 + 4 + iVar8),
                                 *(undefined4 *)(DAT_0093b280 + 8 + iVar8),0,1);
            if (iVar5 == 0) {
              if (((iVar4 == 0) ||
                  ((DAT_007f39e4 != 0 && ((*(byte *)(DAT_0093b280 + 4 + iVar8) & 0x80) != 0)))) &&
                 (iVar5 = FUN_0055bef0(*(undefined4 *)(DAT_0093b280 + 4 + iVar8),
                                       *(undefined4 *)(DAT_0093b280 + 8 + iVar8),1,0,1), iVar5 != -1
                 )) {
                iVar4 = 1;
              }
              else {
                iVar5 = FUN_0055bef0(*(undefined4 *)(DAT_0093b280 + 4 + iVar8),
                                     *(undefined4 *)(DAT_0093b280 + 8 + iVar8),0,0,1);
                if (iVar5 == -1) goto LAB_004896b4;
              }
              iVar5 = FUN_004890e0();
              if (iVar5 != 0) {
                DAT_0087a954 = DAT_0087a954 + 1;
              }
            }
LAB_004896b4:
            iVar10 = iVar10 + 1;
            iVar8 = iVar8 + 0xc;
          } while (iVar10 < DAT_0093b26c);
        }
        iVar4 = FUN_00488ed0();
        iVar10 = DAT_0087a954;
        if (((iVar4 == 0) &&
            (iVar4 = FUN_00488f60(&DAT_0087a840), iVar10 = DAT_0087a954, iVar4 != -1)) &&
           (iVar4 = FUN_004890e0(), iVar10 = DAT_0087a954, iVar4 != 0)) {
          DAT_0087a954 = DAT_0087a954 + 1;
          iVar10 = DAT_0087a954;
        }
      }
    }
    else if ((uVar3 & 4) == 0) {
      if (((DAT_0093d592 == -1) ||
          ((*(uint *)(DAT_0093d592 * 0x4c + 4 + DAT_0093b274) & 0x2000) == 0)) ||
         (iVar4 = FUN_00594960((int)DAT_0093d592), iVar4 == 0)) {
        DAT_0093d592 = DAT_0093d590;
      }
      iVar4 = 0;
      if (DAT_007f39e4 != 0) {
        local_2ac[2] = DAT_007f1a24;
        local_2ac[0] = DAT_007f1a1c;
        local_2ac[1] = DAT_007f1960;
        local_2ac[5] = DAT_007f1a28;
        local_2ac[3] = DAT_007f19a4;
        local_2ac[4] = DAT_007f1970;
        local_2ac[8] = DAT_007f1a2c;
        local_2ac[6] = DAT_007f196c;
        local_2ac[7] = DAT_007f1964;
        local_2ac[0xb] = DAT_007f1a9c;
        local_2ac[9] = DAT_007f195c;
        local_2ac[10] = DAT_007f1b2c;
        local_2ac[0xe] = DAT_007f19e4;
        local_2ac[0xc] = DAT_007f1b34;
        local_2ac[0xd] = DAT_007f1a00;
        local_2ac[0x11] = DAT_007f1b3c;
        local_2ac[0xf] = DAT_007f19e8;
        local_2ac[0x10] = DAT_007f1b1c;
        local_2ac[0x14] = DAT_007f1a98;
        local_2ac[0x12] = DAT_007f1b44;
        local_2ac[0x13] = DAT_007f1b40;
        iVar4 = 0x15;
      }
      local_2ac[iVar4] = -1;
      iVar10 = DAT_0087a954;
      if (local_2ac[0] != -1) {
        psVar6 = local_2ac;
        do {
          iVar4 = FUN_004890e0();
          if (iVar4 != 0) {
            iVar10 = iVar10 + 1;
          }
          psVar1 = psVar6 + 1;
          psVar6 = psVar6 + 1;
        } while (*psVar1 != -1);
      }
    }
    else if (((DAT_0093d592 == -1) ||
             ((*(uint *)(DAT_0093d592 * 0x4c + 4 + DAT_0093b274) & 0x4000000) == 0)) ||
            (iVar4 = FUN_00594960((int)DAT_0093d592), iVar10 = DAT_0087a954, iVar4 == 0)) {
      DAT_0093d592 = DAT_0093d590;
      iVar10 = DAT_0087a954;
    }
  }
  DAT_0087a954 = iVar10;
  if (PTR_DAT_007f17d8 != (undefined *)0x0) {
    ppuVar9 = &PTR_DAT_007f17dc;
    psVar6 = (short *)PTR_DAT_007f17d8;
    do {
      if ((*psVar6 != -1) && (iVar4 = 0, 0 < DAT_0087b2c4)) {
        do {
          if (*(short *)(&DAT_0087a840 + iVar4) == *psVar6) {
            if (((short *)*ppuVar9 != (short *)0x0) && (*(short *)*ppuVar9 != -1)) {
              FUN_004890e0();
            }
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_0087b2c4);
      }
      psVar6 = (short *)ppuVar9[1];
      ppuVar9 = ppuVar9 + 2;
    } while (psVar6 != (short *)0x0);
  }
  __security_check_cookie(local_4 ^ (uint)local_2b4);
  return;
}

