/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x438230; label: FUN_00438230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00438230(int param_1,int param_2,int param_3,ushort param_4,int param_5)

{
  float fVar1;
  byte bVar2;
  short sVar3;
  undefined1 *puVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  char cVar11;
  undefined4 ****ppppuVar12;
  undefined4 uVar13;
  int local_4c;
  float local_48;
  int local_44;
  undefined4 ***local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 local_20 [12];
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4c;
  local_4c = param_1;
  if ((((param_2 == 0) || ((*(uint *)(param_2 + 0x1fc) & 1) == 0)) ||
      ((*(uint *)(param_2 + 0x1fc) & 0x1000) == 0)) ||
     ((*(char *)(param_2 + 0x28b) != '\0' || (0.0 < *(float *)(param_2 + 0x1010))))) {
    __security_check_cookie(local_4 ^ (uint)&local_4c);
    return;
  }
  local_30 = DAT_00955570;
  local_24 = DAT_00955574;
  local_3c = 0;
  local_34 = 0;
  local_38 = DAT_00955578;
  local_28 = DAT_0095557c;
  local_40 = DAT_00955580;
  iVar6 = FUN_0054fa60();
  local_2c = param_3;
  DAT_00955570 = 0;
  DAT_00955574 = 0;
  local_48 = (float)iVar6 * 1.5259022e-05;
  DAT_00955578 = 0;
  DAT_0095557c = 0;
  DAT_00955580 = (undefined4 ****)0x0;
  local_44 = DAT_0095556c;
  DAT_0095556c = 0;
  iVar6 = FUN_0047a8d0();
  if (((((iVar6 != 0) && ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) ||
       (((*(uint *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x90) & 0x8000) != 0 ||
        ((cVar11 = *(char *)(param_2 + 0x7b5), cVar11 == '_' || (cVar11 == '`')))))) ||
      ((cVar11 == 'Z' &&
       ((*(char *)(param_2 + 0x7b3) == '\0' ||
        ((param_1 != 0 && ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)))))))) ||
     ((((param_3 != -1 || ((param_4 & 0x200) == 0)) &&
       ((((cVar11 == '\0' &&
          ((*(char *)(param_2 + 0x7b8) == '\x04' || (*(char *)(param_2 + 0x7b8) == '\x03')))) ||
         (cVar11 == '\x0e')) || (cVar11 == '\r')))) ||
      ((*(uint *)(PTR_PTR_007fb0e4 + cVar11 * 0x10 + 0xc) & 4) != 0)))) goto LAB_0043854a;
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 1) == 0)) {
    param_1 = 0;
    local_4c = 0;
  }
  if (*(char *)(param_2 + 0x280) != -1) {
    DAT_00951918 = 0;
  }
  if ((*(char *)(param_2 + 0x7b5) == 'Q') || (*(char *)(param_2 + 0x7b5) == 'L')) {
    param_3 = 0;
  }
  if ((param_1 != 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) {
    FUN_004399e0(param_1,param_2 + 0x80);
  }
  if ((0 < param_3) || (param_3 == -1)) {
    *(uint *)(param_2 + 0xeec) = *(uint *)(param_2 + 0xeec) | 1;
  }
  if ((param_4 & 0x100) != 0) {
    iVar6 = (int)*(char *)(param_2 + 0x7b5);
    if (((((*(uint *)(PTR_PTR_007fb0e4 + iVar6 * 0x10 + 8) & 0x4000000) != 0) ||
         ((*(char *)(param_2 + 0x7b5) != -1 && ((iVar6 == _DAT_00802890 || (iVar6 == DAT_0080288c)))
          ))) && (uVar7 = FUN_00550040(*(undefined2 *)(param_1 + 0x5a),
                                       *(undefined2 *)(param_2 + 0x5a)),
                 0x4000 < (int)((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f)))) &&
       (((DAT_00802844 == -1 || (*(char *)(param_1 + 0x7b5) != DAT_00802844)) ||
        (*(char *)(param_1 + 0x7ae) != '\x06')))) {
      if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
        FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f400000,0);
      }
      if ((DAT_00802820 != -1) && (*(char *)(param_2 + 0x7b5) == DAT_00802820)) {
        FUN_0058dfa0(param_2);
        if (((*(short *)(param_2 + 0x1064) == DAT_007f1878) ||
            (*(short *)(param_2 + 0x1064) == DAT_007f1884)) &&
           ((*(char *)(param_2 + 0x7b5) == '\f' || (*(char *)(param_2 + 0x7b5) == '\x18')))) {
          FUN_00547930(0x4a,param_2 + 0x80,0,0);
        }
      }
      goto LAB_0043854a;
    }
  }
  fVar1 = *(float *)(param_2 + 0xd30);
  if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
    if ((param_4 & 0x100) == 0) {
      FUN_00433be0(param_1,param_2,0,local_44);
    }
    else if ((param_3 == -1) ||
            (((DAT_00802844 != -1 && (*(char *)(param_1 + 0x7b5) == DAT_00802844)) &&
             (*(char *)(param_1 + 0x7ae) == '\x06')))) {
      FUN_00433be0(param_1,param_2,*(undefined1 *)(param_2 + 0xe38),local_44);
    }
    else {
      FUN_00433be0(param_1,param_2,local_2c,local_44);
    }
    goto LAB_0043854a;
  }
  if (param_4 == 0) {
    param_4 = FUN_0058b720(param_1);
  }
  uVar7 = *(uint *)(param_2 + 0xeec) >> 0x1b & 1;
  if ((uVar7 == 0) && (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b160)) {
    if (((param_1 != 0) && ((param_4 & 0x100) != 0)) &&
       ((*(char *)(param_1 + 0x7b5) == '\x05' &&
        ((*(char *)(param_1 + 0x7ae) == '\x06' && (*(char *)(param_2 + 0x280) == -1)))))) {
      param_3 = -1;
    }
  }
  else if ((1 < param_3) || (param_3 < 0)) {
    param_3 = 1;
  }
  if (((*(uint *)(param_2 + 0xeec) & 0x80000) == 0) || (-1 < (char)param_4)) {
    iVar6 = *(int *)(PTR_DAT_00802c54 + 0x128);
    if (iVar6 == DAT_0087b234) {
      if (((DAT_009253a4 == 0) && ((param_4 & 4) != 0)) &&
         ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) {
        param_3 = 0;
      }
      else {
        if (((iVar6 != DAT_0087b234) || (*(short *)(param_2 + 0x1064) != DAT_007f1948)) ||
           ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) goto LAB_00438704;
        if ((local_4c == 0) || ((*(uint *)(*(int *)(local_4c + 0x54) + 4) & 0x2000) != 0)) {
          if (*(char *)(param_2 + 0x378) != '\x02') {
            param_3 = 0;
          }
        }
        else {
          param_3 = 0;
        }
      }
      goto LAB_00438956;
    }
LAB_00438704:
    if (((*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afb4) &&
        (((sVar3 = *(short *)(param_2 + 0x1064), sVar3 == DAT_007f1914 ||
          ((local_4c != 0 && (*(short *)(local_4c + 0x1064) == DAT_007f1914)))) &&
         ((*(byte *)(param_2 + 0x1fc) & 0x80) == 0)))) &&
       ((local_4c == 0 || ((*(byte *)(local_4c + 0x1fc) & 0x80) == 0)))) {
      if ((param_3 == -1) && (sVar3 == DAT_007f1914)) {
        if (*(char *)(param_2 + 0x7b5) == '\x17') {
          if ((sVar3 != DAT_007f1914) || (*(char *)(param_2 + 0x7b5) != '\x17')) goto LAB_0043879e;
          param_3 = -1;
        }
        else {
          param_3 = 0;
        }
      }
      else {
LAB_0043879e:
        if (((local_4c == 0) || (*(short *)(local_4c + 0x1064) != DAT_007f1914)) ||
           (sVar3 != DAT_007f191c)) {
LAB_00438843:
          param_3 = 0;
        }
        else {
          param_3 = -1;
        }
      }
      goto LAB_00438956;
    }
    if ((param_4 & 1) != 0) goto LAB_00438956;
    if ((((param_4 & 2) != 0) && (-1 < (char)*(uint *)(param_2 + 0x1fc))) && (iVar6 != DAT_00951b94)
       ) {
      if (((DAT_007f39e4 != 0) || (uVar7 != 0)) ||
         ((DAT_007f6688 == 0 ||
          ((((local_4c == 0 || (*(char *)(local_4c + 0x280) == -1)) ||
            (*(char *)(param_2 + 0x280) != -1)) ||
           (((*(uint *)(param_2 + 0x1fc) & 2) != 0 ||
            (cVar11 = (char)((longlong)(ulonglong)(*(byte *)(local_4c + 0x1083) + 1) %
                            (longlong)DAT_007f6688), *(char *)(local_4c + 0x1083) = cVar11,
            cVar11 != '\0')))))))) goto LAB_00438843;
LAB_0043894e:
      local_34 = 1;
      goto LAB_00438956;
    }
    uVar5 = param_4 & 4;
    if (((uVar5 != 0) && ((*(uint *)(param_2 + 0x1f8) & 0x400) != 0)) &&
       (((*(uint *)(param_2 + 0x1f8) & 0x10005) == 0 && (iVar6 != DAT_00951b94)))) {
      param_3 = 0;
      goto LAB_00438956;
    }
    if (((((param_4 & 8) != 0) && (uVar5 == 0)) && ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) &&
       ((iVar6 != DAT_00951b94 && (iVar6 != DAT_0087b160)))) {
      param_3 = 0;
      goto LAB_00438956;
    }
    if ((DAT_00855de0 != 0) && ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)) {
      param_3 = 0;
      goto LAB_00438956;
    }
    iVar6 = FUN_0040aa60();
    if (*(int *)(param_2 + 0xca4) == iVar6) {
      param_3 = 0;
      goto LAB_00438956;
    }
    if (((*(uint *)(*(int *)(param_2 + 0x54) + 4) & 0x20000000) != 0) &&
       (*(int *)(param_2 + 0xcd0) == 0)) {
      param_3 = 0;
      goto LAB_00438956;
    }
    if ((((uVar5 == 0) || ((char)*(uint *)(param_2 + 0x1fc) < '\0')) ||
        ((*(uint *)(param_2 + 0xeec) & 0x8000000) != 0)) ||
       ((DAT_007f39e4 != 0 || (DAT_007f6688 == 0)))) goto LAB_00438956;
    if (local_4c != 0) {
      if (((*(uint *)(param_2 + 0x1fc) & 2) == 0) &&
         (cVar11 = (char)((longlong)(ulonglong)(*(byte *)(local_4c + 0x1083) + 1) %
                         (longlong)DAT_007f6688), *(char *)(local_4c + 0x1083) = cVar11,
         cVar11 == '\0')) goto LAB_0043894e;
      goto LAB_00438956;
    }
  }
  else {
    param_3 = 0;
LAB_00438956:
    if (local_4c != 0) {
      *(int *)(param_2 + 0x10a8) = local_4c;
    }
  }
  iVar6 = local_4c;
  if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) && (local_4c != 0)) &&
      ((*(byte *)(local_4c + 0x1fc) & 0x80) != 0)) &&
     (iVar8 = FUN_0052c790(param_2 + 0x2c8,"TakenHitFromPlayer"), iVar8 != 0)) {
    uVar10 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8);
LAB_004389f0:
    FUN_0052cc90(uVar10,param_2,param_2 + 0x2c8,param_2 + 0x2c8,_DAT_00925018);
  }
  else {
    iVar8 = FUN_0052c790(param_2 + 0x2c8,"TakenHit");
    if (iVar8 != 0) {
      uVar10 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8);
      goto LAB_004389f0;
    }
  }
  if (local_24 == 0) {
    if (iVar6 == 0) {
LAB_00438a52:
      if (local_44 == 0) {
        if ((DAT_00951288 == 0) &&
           ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234 || (DAT_009253a4 != 0)))) {
          if ((param_4 & 0x40) == 0) {
            if (iVar6 == 0) goto LAB_00438bc9;
            uVar13 = 0;
            if ((*(byte *)(*(int *)(iVar6 + 0x54) + 4) & 8) == 0) {
              iVar8 = 0;
              uVar10 = 0x4a;
            }
            else {
              iVar8 = FUN_00547820(iVar6,0);
              uVar10 = 0x41;
            }
          }
          else {
            if (iVar6 != 0) {
              if ((*(char *)(iVar6 + 0x7b5) == '&') &&
                 (uVar7 = FUN_0062a6a0(*(undefined4 *)(iVar6 + 0x50),(int)*(short *)(iVar6 + 0x7aa))
                 , (uVar7 & 4) != 0)) {
                FUN_00681f40("WhipHit",param_2 + 0x80);
                goto LAB_00438bc9;
              }
              bVar2 = *(byte *)(iVar6 + 0x280);
              if ((bVar2 == 0) || (bVar2 == 1)) {
                iVar8 = 1 << (bVar2 & 0x1f);
                uVar13 = 0;
                uVar10 = 0x4a;
                goto LAB_00438bc1;
              }
            }
            uVar13 = 0;
            iVar8 = 0;
            uVar10 = 0x4a;
          }
        }
        else {
          if ((iVar6 == 0) || ((bVar2 = *(byte *)(iVar6 + 0x280), bVar2 != 0 && (bVar2 != 1)))) {
            iVar8 = 0;
          }
          else {
            iVar8 = 1 << (bVar2 & 0x1f);
          }
          uVar13 = 0;
          uVar10 = 0x28;
        }
LAB_00438bc1:
        FUN_00547930(uVar10,param_2 + 0x80,iVar8,uVar13);
      }
      else {
        cVar11 = *(char *)(local_44 + 0x101);
        if ((((cVar11 != '\x1b') && (cVar11 != '\x1c')) && (cVar11 != '\x1d')) &&
           ((iVar8 = *(int *)(PTR_DAT_00802c54 + 300), iVar8 != 0 &&
            ((iVar8 == DAT_0087b014 || (iVar8 == DAT_0087af5c)))))) {
          FUN_00681f40("Pod_TuskHit",local_44 + 0x88);
          local_30 = 1;
        }
      }
    }
    else if (*(short *)(iVar6 + 0x1064) == DAT_007f187c) {
      FUN_00681f40("Grv_GuardImpact",param_2 + 0x80);
    }
    else {
      if (*(short *)(iVar6 + 0x1064) != DAT_007f1878) goto LAB_00438a52;
      FUN_00681f40("wpn_bib_stab",param_2 + 0x80);
    }
  }
LAB_00438bc9:
  if ((0.0 < *(float *)(param_2 + 0x1000)) || ((*(uint *)(param_2 + 0xef0) & 0x400000) != 0)) {
    if ((*(uint *)(param_2 + 0xef0) & 0x1000) != 0) {
      FUN_004321a0(param_2,iVar6);
    }
  }
  else if ((*(char *)(param_2 + 0x7b5) == '\x15') && ((*(uint *)(param_2 + 0xeec) & 0x8000000) != 0)
          ) {
    *(undefined4 *)(param_2 + 0x1000) = 0x40200000;
  }
  else if (((*(byte *)(*(int *)(param_2 + 0x54) + 4) & 0x10) == 0) ||
          (((*(char *)(param_2 + 0x107f) != '\0' || ((param_4 & 0x40) == 0)) || (local_48 <= 0.75)))
          ) {
    if ((param_3 != -1) && (0.0 < *(float *)(param_2 + 0x1018))) {
      if (iVar6 == 0) goto LAB_00439889;
      if ((*(byte *)(iVar6 + 0x1fc) & 0x80) == 0) goto LAB_0043981e;
    }
    if ((*(char *)(param_2 + 0x7b5) == '-') && (iVar8 = FUN_0055f210(param_2), iVar8 == 0)) {
      FUN_00590c10(*(undefined4 *)(param_2 + 0x798),1,1);
    }
    FUN_0055e4a0(param_2,0);
    FUN_004a25b0(param_2,1);
    if (*(char *)(param_2 + 0x1082) != '\0') {
      FUN_00433aa0(param_2,0,0);
    }
    if (param_3 == -1) {
      iVar6 = 0;
LAB_00438d6b:
      if ((((DAT_00880564 == 0) || (*(short *)(param_2 + 0x1064) != DAT_007f1948)) ||
          (*(int *)(param_2 + 0xcd0) == 0)) || (*(char *)(param_2 + 0x280) == -1)) {
LAB_00438d9d:
        iVar8 = 0;
      }
      else {
        iVar8 = 1;
      }
      local_44 = iVar8;
      if (((iVar6 < 1) && ((*(uint *)(*(int *)(param_2 + 0x54) + 4) & 0x20000000) != 0)) &&
         ((iVar9 = FUN_004c91e0(param_2), iVar9 == 0 && (iVar8 == 0)))) {
        uVar10 = 0;
        if ((((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) &&
            (*(int **)(param_2 + 0x7fc) != (int *)0x0)) &&
           ((**(int **)(param_2 + 0x7fc) != 0 && (DAT_007f3b14 == -1)))) {
          uVar10 = FUN_0046c6e0(param_2,1);
        }
        if (local_4c == 0) {
          iVar6 = -1;
        }
        else {
          iVar6 = (int)*(char *)(local_4c + 0x280);
        }
        FUN_0046d270(uVar10,0,0,0,param_2 + 0x80,0,0x40000000,iVar6,0x3f800000,0x49f42400,local_4c,1
                     ,0);
        FUN_00432620(param_2,0x4e6e6b28,0);
        *(undefined1 *)(param_2 + 0x107f) = *(undefined1 *)(param_2 + 0x107e);
        FUN_00414ab0(param_2,0x3ecccccd);
      }
      else {
        iVar8 = local_4c;
        if (((*(uint *)(*(int *)(param_2 + 0x54) + 4) & 0x40000000) == 0) ||
           ((0 < iVar6 && (*(char *)(param_2 + 0x7b5) != '\x17')))) {
          if ((iVar6 < 1) &&
             (((*(uint *)(param_2 + 0xeec) & 0x8000000) == 0 ||
              ((DAT_0093b2a4 != 0 && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b148)))))) {
            if (param_5 == 0) {
              if (*(char *)(param_2 + 0x7b5) == ']') {
                thunk_FUN_0049d540(param_2);
                *(undefined1 *)(param_2 + 0x107f) = 1;
              }
              else if (DAT_007f39e4 == 0) {
                if (local_34 == 0) {
LAB_0043903a:
                  if ((((param_4 & 0x200) != 0) ||
                      (((iVar8 == 0 || (*(char *)(param_2 + 0x280) != -1)) ||
                       ((*(uint *)(param_2 + 0xeec) & 0x8000000) != 0)))) ||
                     ((iVar6 = FUN_0054fa60(), 0x7fff < iVar6 ||
                      ((*(byte *)(param_2 + 0x1fc) & 2) != 0)))) goto LAB_00439267;
                  *(undefined1 *)(param_2 + 0x7b5) = 0x5f;
                  *(undefined2 *)(param_2 + 0x7aa) = 0xb8;
                  if (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + 0x2e0) == 0) {
                    *(undefined2 *)(param_2 + 0x7aa) = 5;
                  }
                  *(undefined1 *)(param_2 + 0x107f) = 1;
                  *(undefined4 *)(param_2 + 0x77c) = 0;
                  *(undefined4 *)(param_2 + 0x784) = 0x40000000;
                  local_48 = *(float *)(param_2 + 0x80) - *(float *)(iVar8 + 0x80);
                  uVar5 = FUN_005be2d0(local_48,*(float *)(param_2 + 0x88) -
                                                *(float *)(iVar8 + 0x88));
                  iVar6 = FUN_0054fa60();
                  local_48 = ((float)iVar6 * 1.5259022e-05 * 0.4 + 0.8) * _DAT_007fc04c;
                  *(float *)(param_2 + 0x748) = local_48 * (float)(&DAT_029899a0)[uVar5 >> 1];
                  fVar1 = (float)(&DAT_029899a0)[(int)(uVar5 + 0x4000) >> 1 & 0x7fff];
                  *(ushort *)(param_2 + 0x5a) = uVar5 + 0x8000;
                  *(float *)(param_2 + 0x750) = local_48 * fVar1;
                  cVar11 = *(char *)(iVar8 + 0x280);
                  if ((cVar11 == '\0') || (cVar11 == '\x01')) {
                    *(char *)(param_2 + 0x7bb) = cVar11;
                  }
                  else {
                    *(undefined1 *)(param_2 + 0x7bb) = 0xff;
                  }
                  iVar6 = FUN_0054fa60();
                  if (iVar6 < 0x5555) {
                    *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x100;
                    local_48 = (float)FUN_0054fa60();
                    *(float *)(param_2 + 0x6c) =
                         ((float)(int)local_48 * 1.5259022e-05 * 0.3 + 0.2) * _DAT_007fc050;
                    *(float *)(param_2 + 0x748) = *(float *)(param_2 + 0x748) * 2.0;
                    *(float *)(param_2 + 0x750) = *(float *)(param_2 + 0x750) * 2.0;
                  }
                  else {
                    *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xfffffeff;
                    local_48 = (float)FUN_0054fa60();
                    *(float *)(param_2 + 0x6c) =
                         ((float)(int)local_48 * 1.5259022e-05 * 0.4 + 0.8) * _DAT_007fc050;
                  }
                  FUN_0062e650(param_2 + 8,0xffffffff);
                  FUN_00414ab0(param_2,0x3ecccccd);
                }
                else {
                  iVar6 = FUN_00432330(param_2,local_4c,_DAT_007f668c,param_4);
                  if (iVar6 == 0) {
                    if (DAT_007f39e4 != 0) goto LAB_00439267;
                    goto LAB_0043903a;
                  }
                  *(undefined1 *)(param_2 + 0x107f) = 1;
                  FUN_00414ab0(param_2,0x3ecccccd);
                  if ((iVar6 != 2) || (iVar8 == 0)) goto LAB_004397e4;
                }
                if (((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0) && (local_38 == 0)) {
                  FUN_0054aa10(iVar8);
                }
              }
              else {
LAB_00439267:
                iVar6 = 0;
                uVar7 = 0;
                *(undefined1 *)(param_2 + 0x107f) = 0;
                if (*(char *)(param_2 + 0x280) == -1) {
                  iVar8 = local_4c;
                  if ((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) {
                    if (DAT_00951154 == 0) {
                      iVar6 = FUN_0056e160(0x10);
                      uVar7 = -(uint)(iVar6 != 0) & 0x15e;
                    }
                    else {
                      uVar7 = (uint)*(ushort *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0xee);
                    }
                    iVar6 = FUN_0046c4f0();
                    goto LAB_0043931a;
                  }
                }
                else {
                  if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
                    if (((*(int **)(param_2 + 0x7fc) != (int *)0x0) &&
                        (**(int **)(param_2 + 0x7fc) != 0)) && (DAT_007f3b14 == -1)) {
                      uVar7 = FUN_0046c6e0(param_2,1);
                    }
                    if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
                      if (DAT_0087b980 == 0) {
                        _DAT_0087b92c = 0x3fc00000;
                      }
                      _DAT_0087b94c = 0x3f800000;
                      _DAT_0087b978 = 0x3f800000;
                    }
                  }
LAB_0043931a:
                  iVar8 = local_4c;
                  if ((0 < (int)uVar7) || (iVar6 != 0)) {
                    if ((DAT_00951154 == 0) && ((int)uVar7 < 0x9c4)) {
                      uVar10 = 1;
                    }
                    else {
                      uVar10 = 0;
                    }
                    FUN_0046d270(uVar7,iVar6,0,0,param_2 + 0x80,0,0x40000000,0xffffffff,0x3f800000,
                                 0x49f42400,local_4c,uVar10,DAT_00951154 != 0);
                  }
                }
                puVar4 = *(undefined1 **)(param_2 + 0xcc4);
                if (((puVar4 != (undefined1 *)0x0) &&
                    (iVar6 = *(int *)(PTR_DAT_00802c54 + 300), iVar6 != DAT_0087afd4)) &&
                   ((iVar6 == 0 || ((*(byte *)(iVar6 + 0x7a) & 4) == 0)))) {
                  FUN_004d2350(puVar4,*puVar4);
                }
                ppppuVar12 = (undefined4 ****)local_40;
                if ((undefined4 ****)local_40 == (undefined4 ****)0x0) {
                  if ((iVar8 == 0) || ((param_4 & 0x240) == 0)) {
                    ppppuVar12 = (undefined4 ****)0x0;
                  }
                  else {
                    local_40 = (undefined4 ***)
                               (*(float *)(param_2 + 0x5c) - *(float *)(iVar8 + 0x5c));
                    uVar7 = FUN_005be2d0(local_40,*(float *)(param_2 + 100) -
                                                  *(float *)(iVar8 + 100));
                    local_40 = (undefined4 ***)(uVar7 & 0xffff);
                    ppppuVar12 = &local_40;
                  }
                }
                if (((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b160) && (DAT_00951b50 == 0))
                     && (iVar6 = FUN_005aac00(DAT_0095df4c,"FinalFight",0), iVar6 != 0)) &&
                    (*(float *)(iVar6 + 0x28) == 1.0)) &&
                   ((iVar8 == 0 || ((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0)))) {
                  DAT_00950770 = 1;
                  if (DAT_0093b2a4 != 0) {
                    FUN_0057a5b0(PTR_DAT_00802c54);
                    __security_check_cookie(local_4 ^ (uint)&local_4c);
                    return;
                  }
                  iVar6 = 1;
                  do {
                    _sprintf(local_14,"rock%d",iVar6);
                    iVar9 = FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),local_20,local_14
                                         ,1);
                    if (iVar9 != 0) {
                      FUN_005cfc00(local_20,0);
                    }
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < 0xc);
                  if (((iVar8 == 0) || (*(short *)(iVar8 + 0x1064) != DAT_007f19f0)) ||
                     (*(short *)(param_2 + 0x1064) != DAT_007f19f4)) {
                    FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),
                                 "ep3_darthvader_outro1",1);
                  }
                  else {
                    FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),
                                 "ep3_darthvader_outro2",1);
                  }
LAB_0043854a:
                  __security_check_cookie(local_4 ^ (uint)&local_4c);
                  return;
                }
                if ((local_44 != 0) && (iVar6 = *(int *)(param_2 + 0xcd0), iVar6 != 0)) {
                  FUN_00437770(iVar6,0xffffffff,
                               (-(uint)(*(short *)(iVar6 + 0x1064) != DAT_007f187c) & 0xfffffffb) +
                               4,1,0,0,ppppuVar12);
                  FUN_004364e0(*(undefined4 *)(param_2 + 0xcd0),2,0);
                }
                if (local_28 == 0) {
                  local_44 = 0;
                }
                else {
                  local_44 = 0x3f800000;
                }
                FUN_00437770(param_2,0xffffffff,
                             (-(uint)(*(short *)(param_2 + 0x1064) != DAT_007f187c) & 0xfffffffb) +
                             4,1,local_44,0,ppppuVar12);
                FUN_004364e0(param_2,2,0);
                if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
                  FUN_00549de0(PTR_DAT_008021b4,0x3e4ccccd,0,0);
                }
                if (((((iVar8 != 0) && ((*(byte *)(iVar8 + 0x1fc) & 0x80) != 0)) &&
                     ((*(byte *)(param_2 + 0x1f8) & 1) != 0)) &&
                    (((*(uint *)(*(int *)(param_2 + 0x54) + 4) & 0x80000) == 0 &&
                     (uVar10 = _DAT_007f39e8, (param_4 & 4) != 0)))) ||
                   (((*(byte *)(param_2 + 0x1fc) & 0x80) != 0 &&
                    (uVar10 = _DAT_007f39ec, (param_4 & 2) != 0)))) {
                  FUN_004289a0(&DAT_00856c0c,uVar10);
                }
                local_3c = 2;
              }
            }
            else {
              local_3c = 2;
            }
          }
          else {
            if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
              FUN_0054aae0(param_2,0x3f2a7efa);
            }
            *(char *)(param_2 + 0x107f) = (char)iVar6;
            if (param_3 != 0) {
              iVar6 = param_2 + 0x2c8;
              iVar8 = FUN_0052c790(iVar6,"LostHitPoints");
              if (iVar8 != 0) {
                FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_2,iVar6,iVar6,
                             _DAT_00925018);
              }
              FUN_00414ab0(param_2,0x3ecccccd);
              if (*(short *)(param_2 + 0x1064) == DAT_007f18bc) {
                FUN_005979d0(param_2);
              }
            }
            local_3c = 1;
            FUN_004321a0(param_2,local_4c);
            if ((*(char *)(param_2 + 0x280) != -1) && (0 < param_3)) {
              *(char *)(param_2 + 0xe39) = *(char *)(param_2 + 0xe39) - (char)param_3;
              if (*(char *)(param_2 + 0xe39) == '\0') {
                *(undefined1 *)(param_2 + 0xe39) = 1;
              }
              if (((*(byte *)(*(int *)(param_2 + 0x54) + 4) & 0x20) != 0) &&
                 (*(char *)(param_2 + 0x28c) != '\0')) {
                iVar6 = *(byte *)(param_2 + 0xe39) - 1;
                if (2 < iVar6) {
                  iVar6 = 2;
                }
                if (*(int *)(*(int *)(param_2 + 0x50) + 0x14 +
                            (uint)(byte)(&DAT_007f6702)[-iVar6] * 4) != 0) {
                  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x71,
                               (uint)(byte)(&DAT_007f6702)[-iVar6] * 0x40 + 0x834 + param_2);
                }
              }
            }
            if ((*(short *)(param_2 + 0x1064) == DAT_007f187c) &&
               (*(char *)(param_2 + 0x107f) == '\x01')) {
              FUN_00437770(param_2,4,0xffffffff,1,0,0,0);
            }
          }
        }
        else {
          uVar10 = 0;
          if ((((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) &&
              (*(int **)(param_2 + 0x7fc) != (int *)0x0)) &&
             ((**(int **)(param_2 + 0x7fc) != 0 && (DAT_007f3b14 == -1)))) {
            uVar10 = FUN_0046c6e0(param_2,1);
          }
          if (local_4c == 0) {
            iVar6 = -1;
          }
          else {
            iVar6 = (int)*(char *)(local_4c + 0x280);
          }
          FUN_0046d270(uVar10,0,0,0,param_2 + 0x80,0,0x40000000,iVar6,0x3f800000,0x49f42400,local_4c
                       ,1,0);
          if (*(char *)(param_2 + 0x7b5) != '\x17') {
            FUN_00414ab0(param_2,0x3ecccccd);
          }
          FUN_0055e4a0(param_2,1);
          *(undefined1 *)(param_2 + 0x107f) = *(undefined1 *)(param_2 + 0x107e);
        }
      }
    }
    else {
      if ((*(char *)(param_2 + 0x107f) != '\0') &&
         (((*(byte *)(param_2 + 0x1fc) & 0x80) == 0 || (iVar8 = FUN_0055f1d0(param_2), iVar8 == 0)))
         ) {
        iVar6 = *(char *)(param_2 + 0x107f) - param_3;
        if (iVar6 < 1) goto LAB_00438d6b;
        goto LAB_00438d9d;
      }
      if ((*(short *)(param_2 + 0x1064) == DAT_007f1a20) ||
         (*(short *)(param_2 + 0x1064) == DAT_007f18f0)) {
        FUN_00414ab0(param_2,0x3ecccccd);
      }
      FUN_004321a0(param_2,iVar6);
      if ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0) {
        FUN_0054aae0(param_2,0x3f2a7efa);
      }
    }
LAB_004397e4:
    if (((local_30 == 0) && (local_3c != 2)) && (*(char *)(param_2 + 0x7b5) != '\x17')) {
      FUN_005483e0(param_2);
    }
  }
  else {
    FUN_00432620(param_2,0x40a00000,0);
  }
LAB_0043981e:
  iVar6 = local_4c;
  if ((local_4c != 0) && ((*(byte *)(local_4c + 0x1fc) & 0x80) != 0)) {
    if (local_38 == 0) {
      if (local_3c == 2) {
        FUN_0054aa10();
      }
      else {
        FUN_0054aa70(local_4c);
      }
    }
    if (((((param_4 & 0x4000) == 0) && (local_3c == 2)) &&
        ((cVar11 = *(char *)(iVar6 + 0x280), cVar11 == '\0' || (cVar11 == '\x01')))) &&
       (DAT_0093b324 != 0)) {
      FUN_00476250((int)cVar11,(int)*(char *)(param_2 + 0x280));
    }
  }
LAB_00439889:
  __security_check_cookie(local_4 ^ (uint)&local_4c);
  return;
}

