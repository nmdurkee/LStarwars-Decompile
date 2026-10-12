/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ac620; label: FUN_004ac620
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ac620(float param_1)

{
  float fVar1;
  char cVar2;
  char cVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  ushort uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  short sVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  ushort in_FPUControlWord;
  float10 fVar18;
  float local_5c;
  undefined4 *local_58;
  uint local_54;
  uint local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  double local_2c;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar6 = param_1;
  local_58 = *(undefined4 **)((int)param_1 + 0xca4);
  local_48 = param_1;
  uVar11 = FUN_0062f1a0((int)param_1 + 8);
  local_40 = 0.0;
  local_2c = (double)CONCAT44(local_2c._4_4_,uVar11);
  local_30 = 0;
  local_3c = 0;
  FUN_004cd9a0(fVar6,&local_58,&local_48);
  local_4c = ((float)local_58[10] /
             *(float *)(*(int *)(*(int *)((int)local_48 + 0x54) + 0x24) + 0x1c)) *
             *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
  if ((((*(uint *)((int)fVar6 + 0xe20) & 0x20) != 0) && (*(char *)((int)fVar6 + 0x7b5) != '#')) &&
     (*(char *)((int)fVar6 + 0x7b5) != '$')) {
    FUN_00499170(fVar6,0,&param_1);
    if (param_1 == 0.0) {
      return;
    }
    uVar9 = *(undefined2 *)((int)param_1 + 0x27a);
    *(undefined2 *)((int)fVar6 + 0x27a) = uVar9;
    *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
    *(undefined2 *)((int)fVar6 + 0x58) = uVar9;
    *(undefined4 *)((int)fVar6 + 0x68) = *(undefined4 *)((int)param_1 + 0x68);
    *(undefined4 *)((int)fVar6 + 0x6c) = *(undefined4 *)((int)param_1 + 0x6c);
    *(undefined4 *)((int)fVar6 + 0x70) = *(undefined4 *)((int)param_1 + 0x70);
    uVar11 = *(undefined4 *)((int)param_1 + 0xdc8);
    *(undefined2 *)((int)fVar6 + 0xe18) = 0;
    *(undefined2 *)((int)fVar6 + 0xe1c) = 0;
    *(undefined4 *)((int)fVar6 + 0xdc8) = uVar11;
    *(undefined2 *)((int)fVar6 + 0xe1a) = 0;
    *(undefined2 *)((int)fVar6 + 0x27c) = 0;
    *(undefined2 *)((int)fVar6 + 0x278) = 0;
    return;
  }
  *(uint *)((int)fVar6 + 0xe20) = *(uint *)((int)fVar6 + 0xe20) & 0xefffffff;
  iVar12 = FUN_0055e600(fVar6);
  if ((iVar12 != 0) || ((*(uint *)((int)fVar6 + 0xef0) & 0x8000) != 0)) {
    *(uint *)((int)fVar6 + 0xef0) = *(uint *)((int)fVar6 + 0xef0) | 0x4000;
  }
  if (*(char *)((int)fVar6 + 0x7b5) == '5') {
    if (*(char *)((int)fVar6 + 0x281) == '\0') {
      FUN_00681f40("GrapWindLp",(int)fVar6 + 0x80);
    }
    else {
      *(undefined1 *)((int)fVar6 + 0x7b5) = 0xff;
    }
  }
  local_5c = 8.0;
  uVar7 = FUN_0054b3d0(fVar6,local_58);
  *(uint *)((int)fVar6 + 0xe20) = *(uint *)((int)fVar6 + 0xe20) | 0x200000;
  local_54 = (uint)uVar7;
  *(ushort *)((int)fVar6 + 0xe0c) = uVar7;
  if (*(float *)((int)fVar6 + 0xd48) <= 0.0) {
    if ((((*(int *)((int)fVar6 + 0x50) != 0) &&
         ((iVar12 = *(int *)(*(int *)((int)fVar6 + 0x50) + 0xc), *(int *)(iVar12 + 0x30) != 0 ||
          (*(int *)(iVar12 + 0x1dc) != 0)))) &&
        ((*(char *)((int)fVar6 + 0x7b5) == -1 || (*(char *)((int)fVar6 + 0x7b5) == '\x01')))) &&
       ((0.0 < (float)local_58[10] &&
        (uVar13 = FUN_00550040(*(undefined2 *)((int)fVar6 + 0x5a),local_54),
        0x6aaa < (int)((uVar13 ^ (int)uVar13 >> 0x1f) - ((int)uVar13 >> 0x1f)))))) {
      *(ushort *)((int)fVar6 + 0xe08) = uVar7;
      *(undefined4 *)((int)fVar6 + 0xd48) = 0x3e4ccccd;
    }
  }
  else {
    if (0.0 < (float)local_58[10]) {
      *(ushort *)((int)fVar6 + 0xe08) = uVar7;
    }
    param_1 = *(float *)((int)fVar6 + 0xd48) - _DAT_00925018;
    *(float *)((int)fVar6 + 0xd48) = param_1;
    if (param_1 < 0.0 != (param_1 == 0.0)) {
      *(undefined2 *)((int)fVar6 + 0x5a) = *(undefined2 *)((int)fVar6 + 0xe08);
    }
  }
  cVar2 = *(char *)((int)fVar6 + 0x7b5);
  if ((cVar2 == '3') &&
     ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x200) != 0)) {
    *(undefined1 *)((int)fVar6 + 0x107a) = 2;
  }
  else if ((cVar2 == 'C') && (*(char *)((int)fVar6 + 0x7b6) == '\x05')) {
    FUN_0056c040(fVar6);
  }
  else if ((*(uint *)(*(int *)((int)fVar6 + 0x54) + 4) & 0x100100) == 0x100000) {
    if (*(char *)((int)fVar6 + 0x7b8) == '\x01') {
      *(undefined2 *)((int)fVar6 + 0x278) = 0;
      *(undefined2 *)((int)fVar6 + 0x27c) = 0;
    }
    else {
      *(undefined1 *)((int)fVar6 + 0x107a) = 0;
      if (cVar2 == 'G') {
        local_50 = (uint)*(ushort *)((int)fVar6 + 0x7a4);
        iVar12 = *(int *)((int)fVar6 + 0x798);
        if ((iVar12 != 0) && ((*(byte *)(iVar12 + 0x68) & 1) != 0)) {
          param_1 = (float)(uint)in_FPUControlWord;
          local_38 = (int)ROUND((float)*(ushort *)(iVar12 + 0x60) *
                                (*(float *)((int)fVar6 + 0x77c) / 1.5));
          local_50 = (uint)(ushort)(*(ushort *)((int)fVar6 + 0x7a4) - (short)local_38);
        }
      }
      else {
        local_50 = 0;
      }
      uVar8 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0x278),local_50,0x41000000);
      uVar9 = *(undefined2 *)((int)fVar6 + 0x27c);
      *(undefined2 *)((int)fVar6 + 0x278) = uVar8;
      uVar11 = 0;
LAB_004aca59:
      uVar9 = FUN_00550070(uVar9,uVar11,0x41000000);
      *(undefined2 *)((int)fVar6 + 0x27c) = uVar9;
    }
  }
  else if ((*(short *)((int)fVar6 + 0x1064) == DAT_007f1974) ||
          (*(short *)((int)fVar6 + 0x1064) == DAT_007f1978)) {
    *(undefined1 *)((int)fVar6 + 0x107a) = 2;
    if ((float)local_58[10] <= 0.0) {
      local_44 = 0;
      local_50 = 0;
    }
    else {
      uVar11 = FUN_006e6b90();
      FUN_005b35a0(&local_18,&DAT_00802500,uVar11);
      FUN_005b3620(&local_18,&local_18,uVar7);
      FUN_0054fec0(&local_18,&local_50,&local_44);
    }
    uVar9 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0x278),local_50,0x41000000);
    *(undefined2 *)((int)fVar6 + 0x278) = uVar9;
    uVar9 = *(undefined2 *)((int)fVar6 + 0x27c);
    uVar11 = local_44;
    goto LAB_004aca59;
  }
  cVar2 = *(char *)((int)fVar6 + 0x7b5);
  local_34 = *(undefined4 *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 0xc);
  if ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x40) == 0) {
    if ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x4000) != 0) {
      *(short *)((int)fVar6 + 0x5a) = *(short *)(PTR_DAT_008021b4 + 0x1fc) + -0x8000;
      goto LAB_004acaed;
    }
    if ((*(short *)((int)fVar6 + 0x1064) == DAT_007f1974) ||
       (*(short *)((int)fVar6 + 0x1064) == DAT_007f1978)) {
      if (*(int *)(PTR_DAT_00802c54 + 0x46ec) != 0) {
        pfVar14 = (float *)FUN_004707a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x46ec),0);
        param_1 = *pfVar14 - *(float *)((int)fVar6 + 0x80);
        uVar9 = FUN_005be2d0(param_1,pfVar14[2] - *(float *)((int)fVar6 + 0x88));
        *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
      }
      goto LAB_004acaed;
    }
    uVar13 = *(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x94);
    if (((((((((uVar13 & 2) != 0) || (cVar2 == '=')) || (cVar2 == '\x15')) ||
           ((cVar2 == 'Z' || (cVar2 == '\x0f')))) || ((cVar2 == '\x1f' || (cVar2 == '<')))) ||
         ((((cVar2 == '\x17' && ((*(byte *)((int)fVar6 + 0xef8) & 1) == 0)) || (cVar2 == 'A')) ||
          (cVar2 == '\v')))) ||
        ((((cVar2 == '\0' &&
           (((cVar3 = *(char *)((int)fVar6 + 0x7b8), cVar3 == '\x06' || (cVar3 == '\a')) ||
            (cVar3 == '\t')))) && ((*(uint *)((int)fVar6 + 0x7bc) & 0x8000) == 0)) || (cVar2 == 'G')
         ))) || (((((cVar2 == ')' &&
                    (*(int *)(*(int *)(*(int *)((int)fVar6 + 0x50) + 0xc) + 0x15c) == 0)) &&
                   ((uVar13 & 0x100000) == 0)) ||
                  (((*(uint *)((int)fVar6 + 0xef0) & 0x2000000) == 0 &&
                   (iVar12 = FUN_0062f1a0((int)fVar6 + 8), iVar12 == 5)))) ||
                 ((cVar2 = *(char *)((int)fVar6 + 0x7b5), cVar2 == '5' ||
                  ((cVar2 == 'F' &&
                   ((*(char *)((int)fVar6 + 0x7b3) == '\x01' || (DAT_00802450 == 1))))))))))
    goto LAB_004acaed;
    if (((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) &&
       ((cVar2 == '\x1b' && ((*(uint *)((int)fVar6 + 0xe20) & 0x200) == 0)))) {
      if (*(char *)((int)fVar6 + 0x7b3) == '\x01') {
        local_40 = 0.333;
        *(ushort *)((int)fVar6 + 0x5a) = (ushort)local_54;
      }
      else {
        FUN_00499500(fVar6,0);
        local_40 = 0.333;
      }
      goto LAB_004acaed;
    }
    if (cVar2 != '\x1c') {
      if ((cVar2 == '\x16') || (cVar2 == '\x1b')) {
LAB_004ad0ff:
        FUN_00499500(fVar6,0);
      }
      else if (cVar2 == '\"') {
        if (DAT_0087b8cc != 0) {
          FUN_00499500(fVar6,DAT_0087b8cc);
        }
      }
      else if (cVar2 == '\x1d') {
        iVar12 = *(int *)((int)fVar6 + 0xcb8);
        if ((iVar12 != 0) && ((*(byte *)(iVar12 + 0x144) & 1) != 0)) {
          param_1 = *(float *)(iVar12 + 0x30) - *(float *)((int)fVar6 + 0x80);
          uVar9 = FUN_005be2d0(param_1,*(float *)(iVar12 + 0x38) - *(float *)((int)fVar6 + 0x88));
          *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
        }
      }
      else if ((cVar2 == '\b') || (cVar2 == '\x12')) {
        if ((*(uint *)((int)fVar6 + 0x1f8) & 0x40000) == 0) {
          *(undefined2 *)((int)fVar6 + 0x5a) = *(undefined2 *)((int)fVar6 + 0xe0a);
        }
      }
      else if (cVar2 == '-') {
        if ((*(uint *)((int)fVar6 + 0x1f8) & 0x40000) == 0) {
          FUN_0058f1f0(fVar6,0,&local_18);
          if ((*(byte *)(*(int *)((int)fVar6 + 0x798) + 0x72) & 0x20) != 0) {
            FUN_0058f3f0(fVar6,*(int *)((int)fVar6 + 0x798));
          }
          param_1 = local_18 - *(float *)((int)fVar6 + 0x5c);
          uVar9 = FUN_005be2d0(param_1,local_10 - *(float *)((int)fVar6 + 100));
          *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
        }
      }
      else if ((cVar2 == '\x10') && ((*(byte *)((int)fVar6 + 0x7bc) & 0x40) == 0)) {
        iVar12 = FUN_00499500(fVar6,0);
        if (iVar12 != 0) {
          *(short *)((int)fVar6 + 0x5a) = *(short *)((int)fVar6 + 0x5a) + -0x8000;
        }
      }
      else {
        if (cVar2 == '3') goto LAB_004aca93;
        if (cVar2 == '\x05') {
          if ((*(byte *)((int)fVar6 + 0x7bc) & 0xc) == 0) {
            FUN_00499500(fVar6,0);
          }
        }
        else if (cVar2 == '&') {
          if (((*(char *)((int)fVar6 + 0x7b7) == -1) &&
              (iVar12 = FUN_00499500(fVar6,0), iVar12 != 0)) &&
             ((*(byte *)((int)fVar6 + 0x7bc) & 0x80) != 0)) {
            *(short *)((int)fVar6 + 0x5a) = *(short *)((int)fVar6 + 0x5a) + -0x8000;
          }
        }
        else {
          if (cVar2 == 'X') {
            iVar12 = FUN_00599830(fVar6,local_54);
            goto LAB_004acc90;
          }
          uVar13 = *(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8);
          local_34 = *(undefined4 *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 0xc);
          if ((uVar13 & 0x2000) == 0) {
            if ((cVar2 == '\n') &&
               (((sVar10 = *(short *)((int)fVar6 + 0x7aa), sVar10 == 0x5a || (sVar10 == 0x5b)) ||
                (sVar10 == 0x5c)))) {
              param_1 = *(float *)((int)fVar6 + 0xc80) - *(float *)((int)fVar6 + 0x5c);
              sVar10 = FUN_005be2d0(param_1,*(float *)((int)fVar6 + 0xc88) -
                                            *(float *)((int)fVar6 + 100));
              *(short *)((int)fVar6 + 0x5a) = sVar10;
              if (*(short *)((int)fVar6 + 0x7aa) == 0x5a) {
                *(short *)((int)fVar6 + 0x5a) = sVar10 + 0x4000;
              }
              else if (*(short *)((int)fVar6 + 0x7aa) == 0x5b) {
                *(short *)((int)fVar6 + 0x5a) = sVar10 + -0x4000;
              }
              else {
                *(short *)((int)fVar6 + 0x5a) = sVar10 + -0x8000;
              }
            }
            else if (cVar2 == '\f') {
              if (*(char *)((int)fVar6 + 0xe2f) == '\0') {
                iVar12 = *(int *)((int)fVar6 + 0xd08);
                if (iVar12 == 0) {
                  iVar12 = *(int *)((int)fVar6 + 0xcf8);
                  if (iVar12 == 0) {
                    iVar12 = *(int *)((int)fVar6 + 0xcb4);
                    if ((iVar12 != 0) && ((*(byte *)(iVar12 + 0x144) & 1) != 0)) {
                      pfVar14 = (float *)(iVar12 + 0x30);
                      goto LAB_004ad001;
                    }
                  }
                  else if (((*(uint *)(iVar12 + 0x1fc) & 0x1000) != 0) &&
                          (*(char *)(iVar12 + 0x28b) == '\0')) {
                    pfVar14 = (float *)(iVar12 + 0x5c);
LAB_004ad001:
                    if (pfVar14 != (float *)0x0) {
                      param_1 = *pfVar14 - *(float *)((int)fVar6 + 0x5c);
                      uVar9 = FUN_005be2d0(param_1,pfVar14[2] - *(float *)((int)fVar6 + 100));
                      *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
                    }
                  }
                }
                else if (*(char *)(iVar12 + 0x100) != '\0') {
                  pfVar14 = (float *)(iVar12 + 0x88);
                  goto LAB_004ad001;
                }
              }
            }
            else if (cVar2 == '\x18') {
              iVar12 = *(int *)((int)fVar6 + 0xd04);
              if (iVar12 == 0) {
                iVar12 = *(int *)((int)fVar6 + 0xcfc);
                if (iVar12 == 0) {
                  iVar12 = *(int *)((int)fVar6 + 0xcb0);
                  if ((iVar12 != 0) && ((*(byte *)(iVar12 + 0x144) & 1) != 0)) {
                    pfVar14 = (float *)(iVar12 + 0x30);
                    goto LAB_004ad0b2;
                  }
                }
                else if (((*(uint *)(iVar12 + 0x1fc) & 0x1000) != 0) &&
                        (*(char *)(iVar12 + 0x28b) == '\0')) {
                  pfVar14 = (float *)(iVar12 + 0x5c);
LAB_004ad0b2:
                  if (pfVar14 != (float *)0x0) {
                    param_1 = *pfVar14 - *(float *)((int)fVar6 + 0x5c);
                    uVar9 = FUN_005be2d0(param_1,pfVar14[2] - *(float *)((int)fVar6 + 100));
                    *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
                  }
                }
              }
              else if (*(char *)(iVar12 + 0x100) != '\0') {
                pfVar14 = (float *)(iVar12 + 0x88);
                goto LAB_004ad0b2;
              }
            }
            else {
              if ((cVar2 == '%') && (*(short *)((int)fVar6 + 0x7aa) != 0x58)) goto LAB_004ad0ff;
              if ((cVar2 == '\0') && (*(char *)((int)fVar6 + 0x7b8) == '\x03')) {
                FUN_00499500(fVar6,0);
              }
              else if (*(int *)((int)fVar6 + 0xeac) == 0) {
                if ((local_58[0x15] == 0) || ((uVar13 & 1) != 0)) {
                  if ((*(char *)((int)fVar6 + 0x280) == -1) ||
                     (*(char *)((int)fVar6 + 0x280) != DAT_007f3b14)) {
                    if ((((0.0 < (float)local_58[10]) &&
                         ((((uVar13 & 1) == 0 || (iVar12 = FUN_00599960(fVar6), iVar12 != 0)) ||
                          ((*(char *)((int)fVar6 + 0x7b5) == ' ' &&
                           ((*(uint *)((int)fVar6 + 0xeec) & 0x100) != 0)))))) &&
                        (((*(float *)((int)fVar6 + 0xd48) <= 0.0 &&
                          (cVar2 = *(char *)((int)fVar6 + 0x7b5), cVar2 != '\x13')) &&
                         ((*(uint *)((int)fVar6 + 0xef4) & 0x200) == 0)))) &&
                       ((((cVar2 != '\0' || ((*(uint *)((int)fVar6 + 0x7bc) & 0x8000) != 0)) ||
                         (cVar3 = *(char *)((int)fVar6 + 0x7b8), cVar3 == '\0')) ||
                        ((cVar3 == '\x05' || (cVar3 == '\b')))))) {
                      if (((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0) &&
                         ((cVar2 == -1 && (*(char *)((int)fVar6 + 0x281) == '\0')))) {
                        FUN_0062f1a0((int)fVar6 + 8);
                        iVar12 = FUN_004982f0();
                        if (iVar12 == 0) goto LAB_004ad2bd;
                      }
                      else {
LAB_004ad2bd:
                        *(ushort *)((int)fVar6 + 0x5a) = (ushort)local_54;
                      }
                      if ((*(char *)((int)fVar6 + 0x7b5) == ' ') &&
                         ((*(uint *)((int)fVar6 + 0xeec) & 0x100) != 0)) {
                        *(short *)((int)fVar6 + 0x5a) = *(short *)((int)fVar6 + 0x5a) + -0x8000;
                      }
                    }
                  }
                  else {
                    param_1 = *(float *)(PTR_DAT_008021b4 + 0x11c) - *(float *)((int)fVar6 + 0x5c);
                    uVar9 = FUN_005be2d0(param_1,*(float *)(PTR_DAT_008021b4 + 0x124) -
                                                 *(float *)((int)fVar6 + 100));
                    *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
                  }
                }
                else {
                  param_1 = *(float *)local_58[0x15] - *(float *)((int)fVar6 + 0x5c);
                  uVar9 = FUN_005be2d0(param_1,((float *)local_58[0x15])[2] -
                                               *(float *)((int)fVar6 + 100));
                  *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
                }
              }
              else {
                FUN_00499500(fVar6,*(int *)((int)fVar6 + 0xeac));
                *(short *)((int)fVar6 + 0x5a) = *(short *)((int)fVar6 + 0x5a) + -0x8000;
              }
            }
          }
          else {
            FUN_0059bcc0(fVar6);
          }
        }
      }
      goto LAB_004acaed;
    }
    iVar12 = FUN_004a42b0(fVar6);
LAB_004acc90:
    iVar17 = local_30;
    if (iVar12 == 0) goto LAB_004acaed;
  }
  else {
LAB_004aca93:
    if ((*(float *)((int)fVar6 + 0x68) != 0.0) || (*(float *)((int)fVar6 + 0x70) != 0.0)) {
      uVar9 = FUN_005be2d0(*(undefined4 *)((int)fVar6 + 0x68),*(undefined4 *)((int)fVar6 + 0x70));
      *(undefined2 *)((int)fVar6 + 0x5a) = uVar9;
    }
LAB_004acaed:
    if ((*(char *)((int)fVar6 + 0x7b5) == '3') || ((*(uint *)((int)fVar6 + 0xef0) & 0x400) != 0)) {
      iVar17 = 1;
    }
    else {
      iVar17 = 0;
    }
    iVar12 = FUN_00599960(fVar6);
    if (iVar12 == 0) {
      if ((*(char *)((int)fVar6 + 0x7b5) != '\x1c') && (*(char *)((int)fVar6 + 0x7b5) != '3')) {
        if (local_40 == 0.0) {
          local_5c = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x74) * 8.0;
          if ((*(short *)((int)fVar6 + 0x1064) == DAT_007f1914) &&
             (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) {
            local_5c = local_5c + local_5c;
          }
        }
        else {
          local_5c = local_40 * 8.0;
        }
      }
    }
    else {
      local_5c = *(float *)((int)fVar6 + 0x778) * 8.0;
    }
    if (((*(uint *)((int)fVar6 + 0xef0) & 0x8000) != 0) &&
       ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)((int)fVar6 + 0x7b5) * 0x10 + 8) & 1) == 0)) {
      *(short *)((int)fVar6 + 0x5a) = *(short *)((int)fVar6 + 0x5a) + -0x8000;
    }
    if ((*(uint *)((int)fVar6 + 0xef0) & 0x400) == 0) {
      if ((iVar17 == 0) &&
         ((((local_40 != 0.0 ||
            ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)((int)fVar6 + 0x7b5) * 0x10 + 0xc) & 2) != 0))
           || ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x100) != 0)) ||
          (iVar12 = FUN_00599960(fVar6), iVar12 != 0)))) {
        uVar11 = FUN_006e6b90(0);
        uVar11 = FUN_00550100(*(undefined2 *)((int)fVar6 + 0x58),*(undefined2 *)((int)fVar6 + 0x5a),
                              uVar11);
        *(short *)((int)fVar6 + 0x58) = (short)uVar11;
        uVar9 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0x27a),uVar11,0x41200000);
        *(undefined2 *)((int)fVar6 + 0x27a) = uVar9;
        *(undefined2 *)((int)fVar6 + 0x5a) = *(undefined2 *)((int)fVar6 + 0x58);
      }
      else {
        uVar9 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0x58),*(undefined2 *)((int)fVar6 + 0x5a),
                             local_5c);
        *(undefined2 *)((int)fVar6 + 0x58) = uVar9;
        *(undefined2 *)((int)fVar6 + 0x27a) = uVar9;
      }
    }
    else {
      *(undefined2 *)((int)fVar6 + 0x58) = *(undefined2 *)((int)fVar6 + 0x5a);
      *(undefined2 *)((int)fVar6 + 0x27a) = *(undefined2 *)((int)fVar6 + 0x5a);
    }
  }
  iVar12 = FUN_0056db40(fVar6);
  if (iVar12 == 0) {
    *(undefined4 *)((int)fVar6 + 0xf1c) = 0;
  }
  else {
    param_1 = *(float *)(*(int *)((int)fVar6 + 0x798) + 0x24);
    *(float *)((int)fVar6 + 0xf1c) = param_1;
    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b14c) {
      *(float *)((int)fVar6 + 0xf1c) = param_1 + param_1;
    }
  }
  local_24 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x44);
  iVar12 = 0;
  if ((*(float *)((int)fVar6 + 0x200) == 0.0) && (*(float *)((int)fVar6 + 0x208) == 0.0)) {
    cVar2 = *(char *)((int)fVar6 + 0x7b5);
    if (cVar2 == 'W') {
      *(undefined4 *)((int)fVar6 + 0x5c) = *(undefined4 *)((int)fVar6 + 0x8c);
      *(undefined4 *)((int)fVar6 + 0x60) = *(undefined4 *)((int)fVar6 + 0x90);
      *(undefined4 *)((int)fVar6 + 100) = *(undefined4 *)((int)fVar6 + 0x94);
      *(undefined4 *)((int)fVar6 + 0x80) = *(undefined4 *)((int)fVar6 + 0x98);
      *(undefined4 *)((int)fVar6 + 0x84) = *(undefined4 *)((int)fVar6 + 0x9c);
      *(undefined4 *)((int)fVar6 + 0x88) = *(undefined4 *)((int)fVar6 + 0xa0);
      *(undefined4 *)((int)fVar6 + 0x68) = DAT_0093b0cc;
      *(undefined4 *)((int)fVar6 + 0x6c) = DAT_0093b0d0;
      *(undefined4 *)((int)fVar6 + 0x70) = DAT_0093b0d4;
    }
    else if (cVar2 == 'E') {
      iVar12 = FUN_0059c980(fVar6,local_54);
    }
    else if (cVar2 == 'U') {
      iVar12 = FUN_0056bf30(fVar6);
    }
    else if (cVar2 == '[') {
      iVar12 = 1;
      *(float *)((int)fVar6 + 0xf18) =
           (*(float *)((int)fVar6 + 0x754) - *(float *)((int)fVar6 + 400)) * 20.0;
      *(float *)((int)fVar6 + 0xf1c) =
           (*(float *)((int)fVar6 + 0x758) - *(float *)((int)fVar6 + 0x194)) * 20.0;
      *(float *)((int)fVar6 + 0xf20) =
           (*(float *)((int)fVar6 + 0x75c) - *(float *)((int)fVar6 + 0x198)) * 20.0;
    }
    else if (((cVar2 == '\'') || (cVar2 == '(')) || (cVar2 == 'Y')) {
      uVar11 = (&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
      *(undefined4 *)((int)fVar6 + 0xf18) = uVar11;
      *(undefined4 *)((int)fVar6 + 0x68) = uVar11;
      param_1 = (float)(&DAT_029899a0)[(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff]
      ;
      *(float *)((int)fVar6 + 0xf20) = param_1;
      *(float *)((int)fVar6 + 0x70) = param_1;
    }
    else if (cVar2 == 'N') {
      iVar12 = FUN_0056c980(fVar6);
    }
    else if (cVar2 == 'C') {
      iVar12 = FUN_0056c620(fVar6,local_54);
    }
    else if (cVar2 == 'F') {
      FUN_0054f900(fVar6);
      iVar12 = FUN_0054f860(fVar6);
    }
    else if (cVar2 == 'J') {
      if ((*(uint *)((int)fVar6 + 0x1f8) & 0x40000) == 0) {
        pfVar14 = (float *)(*(int *)((int)fVar6 + 0x798) + 0x40);
LAB_004ad7c1:
        local_c = *pfVar14;
        local_8 = pfVar14[1];
        local_4 = pfVar14[2];
        fVar1 = *(float *)((int)fVar6 + 0x778) * 10.0 + 5.0;
        *(float *)((int)fVar6 + 0xf18) = fVar1 * (local_c - *(float *)((int)fVar6 + 0x5c));
        *(float *)((int)fVar6 + 0xf20) = (local_4 - *(float *)((int)fVar6 + 100)) * fVar1;
      }
    }
    else if (cVar2 == '\v') {
      if ((*(uint *)((int)fVar6 + 0x1f8) & 0x40000) == 0) {
        FUN_0046dc10(*(undefined4 *)((int)fVar6 + 0x798),&local_c,1);
        fVar1 = *(float *)((int)fVar6 + 0x778) * 10.0 + 5.0;
        *(float *)((int)fVar6 + 0xf18) = fVar1 * (local_c - *(float *)((int)fVar6 + 0x5c));
        *(float *)((int)fVar6 + 0xf20) = (local_4 - *(float *)((int)fVar6 + 100)) * fVar1;
      }
    }
    else {
      if ((cVar2 == 'a') && ((*(uint *)((int)fVar6 + 0x1f8) & 0x40000) == 0)) {
        pfVar14 = (float *)(*(int *)((int)fVar6 + 0x798) + 100);
        goto LAB_004ad7c1;
      }
      if (cVar2 == 'Q') {
        *(float *)((int)fVar6 + 0xf18) =
             (*(float *)(*(int *)((int)fVar6 + 0x798) + 0x1c) - *(float *)((int)fVar6 + 0x5c)) * 5.0
        ;
        *(float *)((int)fVar6 + 0xf20) =
             (*(float *)(*(int *)((int)fVar6 + 0x798) + 0x24) - *(float *)((int)fVar6 + 100)) * 5.0;
      }
      else if (cVar2 == 'S') {
        *(float *)((int)fVar6 + 0xf18) =
             (*(float *)(*(int *)((int)fVar6 + 0x798) + 100) - *(float *)((int)fVar6 + 0x5c)) * 5.0;
        *(float *)((int)fVar6 + 0xf20) =
             (*(float *)(*(int *)((int)fVar6 + 0x798) + 0x6c) - *(float *)((int)fVar6 + 100)) * 5.0;
      }
      else if (cVar2 == '\\') {
        *(float *)((int)fVar6 + 0xf18) =
             (*(float *)(*(int *)((int)fVar6 + 0x798) + 0xa4) - *(float *)((int)fVar6 + 0x5c)) * 5.0
        ;
        *(float *)((int)fVar6 + 0xf20) =
             (*(float *)(*(int *)((int)fVar6 + 0x798) + 0xac) - *(float *)((int)fVar6 + 100)) * 5.0;
      }
      else if (cVar2 == 'L') {
        iVar17 = *(int *)((int)fVar6 + 0x798);
        iVar12 = 1;
        *(float *)((int)fVar6 + 0xf18) =
             (*(float *)(iVar17 + 0x84) - *(float *)((int)fVar6 + 0x80)) * 5.0;
        *(float *)((int)fVar6 + 0xf1c) =
             (*(float *)(iVar17 + 0x88) - *(float *)((int)fVar6 + 0x84)) * 5.0;
        *(float *)((int)fVar6 + 0xf20) =
             (*(float *)(iVar17 + 0x8c) - *(float *)((int)fVar6 + 0x88)) * 5.0;
      }
      else if (cVar2 == 'D') {
        iVar12 = FUN_004d1cf0(fVar6);
      }
      else if (cVar2 == 'O') {
        iVar12 = FUN_0049d910(fVar6);
        local_20 = local_24;
        local_1c = 2.0;
        local_3c = 1;
        local_24 = 2.0;
      }
      else if (cVar2 == '\x05') {
LAB_004adae1:
        fVar4 = _DAT_007fb0b8;
        fVar1 = _DAT_007fb0a4;
        cVar2 = *(char *)((int)fVar6 + 0x7b5);
        if (((cVar2 == '&') && (*(char *)((int)fVar6 + 0x7b7) != -1)) &&
           (*(int *)((int)fVar6 + 0x790) != 0)) {
          FUN_0058b2a0(fVar6);
        }
        else if (cVar2 == '3') {
          iVar12 = FUN_004a76c0(fVar6,local_54,local_4c);
        }
        else if (cVar2 == 'X') {
          iVar12 = FUN_00599740(fVar6,local_4c);
        }
        else if (cVar2 == 'Z') {
          if ((*(char *)((int)fVar6 + 0x7b3) != '\0') || ((*(byte *)((int)fVar6 + 0x1fc) & 2) != 0))
          goto LAB_004ae238;
          *(float *)((int)fVar6 + 0xf18) =
               -(float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1] *
               *(float *)((int)fVar6 + 0x750);
          *(float *)((int)fVar6 + 0xf20) =
               -(float)(&DAT_029899a0)[(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff]
               * *(float *)((int)fVar6 + 0x750);
        }
        else {
          local_34 = *(undefined4 *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 0xc);
          if ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 2) == 0) {
            if (cVar2 == '!') {
              *(float *)((int)fVar6 + 0xf18) =
                   _DAT_007fb0a4 * -(float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
              *(float *)((int)fVar6 + 0xf20) =
                   -(float)(&DAT_029899a0)
                           [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff] * fVar1;
            }
            else if (cVar2 == '_') {
              *(undefined4 *)((int)fVar6 + 0xf18) = *(undefined4 *)((int)fVar6 + 0x748);
              *(undefined4 *)((int)fVar6 + 0xf20) = *(undefined4 *)((int)fVar6 + 0x750);
            }
            else if (cVar2 == '\"') {
              *(float *)((int)fVar6 + 0xf18) =
                   _DAT_007fb0b8 * -(float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
              *(float *)((int)fVar6 + 0xf20) =
                   -(float)(&DAT_029899a0)
                           [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff] * fVar4;
            }
            else if ((cVar2 == '\0') && (*(char *)((int)fVar6 + 0x7b8) == '\x03')) {
              iVar17 = FUN_0058e130(fVar6);
              if (iVar17 == 0) {
                *(float *)((int)fVar6 + 0xf18) =
                     (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1] *
                     *(float *)((int)fVar6 + 0x778);
                *(float *)((int)fVar6 + 0xf20) =
                     (float)(&DAT_029899a0)
                            [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff] *
                     *(float *)((int)fVar6 + 0x778);
              }
            }
            else if ((cVar2 == '\f') || (cVar2 == '\x18')) {
              if ((((*(int *)((int)fVar6 + 0xd04) == 0) || (local_4c <= 0.0)) ||
                  ((*(byte *)((int)local_58 + 0x5a) & 2) != 0)) ||
                 ((cVar2 != '\x18' && (*(char *)((int)fVar6 + 0xe2f) != '\0')))) {
LAB_004ae8db:
                *(undefined4 *)((int)fVar6 + 0xf20) = 0;
                *(undefined4 *)((int)fVar6 + 0xf18) = 0;
              }
              else {
                *(float *)((int)fVar6 + 0xf18) =
                     (float)(&DAT_029899a0)[local_54 >> 1 & 0x7fff] *
                     *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                *(float *)((int)fVar6 + 0xf20) =
                     (float)(&DAT_029899a0)[(int)((local_54 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
                     *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
              }
            }
            else {
              if ((((cVar2 == '\x17') || (cVar2 == 'A')) || ((cVar2 == '\x1f' || (cVar2 == '<'))))
                 || ((cVar2 == ')' &&
                     (*(int *)(*(int *)(*(int *)((int)fVar6 + 0x50) + 0xc) + 0x15c) == 0))))
              goto LAB_004ae238;
              if (cVar2 == '-') {
                local_18 = *(float *)((int)fVar6 + 0x5c);
                local_14 = *(undefined4 *)((int)fVar6 + 0x60);
                local_10 = *(float *)((int)fVar6 + 100);
                FUN_0058f1f0(fVar6,&local_18,0);
                *(float *)((int)fVar6 + 0xf18) = (local_18 - *(float *)((int)fVar6 + 0x5c)) * 3.0;
                *(float *)((int)fVar6 + 0xf20) = (local_10 - *(float *)((int)fVar6 + 100)) * 3.0;
              }
              else if (cVar2 == '\x1c') {
                iVar12 = FUN_004a3eb0(fVar6,&local_24);
              }
              else if ((((((((cVar2 == '\x19') || (cVar2 == '\x01')) || (cVar2 == '\x02')) ||
                          ((cVar2 == '\x03' || (cVar2 == '\x04')))) || (cVar2 == '\r')) ||
                        ((cVar2 == '\x0e' || (cVar2 == '\t')))) ||
                       ((cVar2 == '\n' ||
                        (((cVar2 == '\x16' || (cVar2 == '\x1d')) || (cVar2 == '\x1b')))))) ||
                      ((((cVar2 == '\x12' || (cVar2 == '\b')) || (cVar2 == '\x13')) ||
                       ((cVar2 == '\x14' ||
                        ((cVar2 == '\0' && (*(char *)((int)fVar6 + 0x7b8) == '\x04')))))))) {
                if ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x10) == 0) goto LAB_004ae8db;
                fVar18 = (float10)FUN_0062f1c0(*(undefined4 *)((int)fVar6 + 0x50),
                                               (int)*(short *)((int)fVar6 + 0x7aa));
                param_1 = (float)fVar18;
                *(float *)((int)fVar6 + 0xf18) =
                     param_1 * (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
                *(float *)((int)fVar6 + 0xf20) =
                     param_1 * (float)(&DAT_029899a0)
                                      [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff]
                ;
              }
              else if (cVar2 == '\x05') {
                if ((*(byte *)((int)fVar6 + 0x7bc) & 0x1c) == 0) {
                  iVar17 = FUN_0058e130(fVar6);
                  if (iVar17 == 0) {
                    fVar18 = (float10)FUN_0062f1c0(*(undefined4 *)((int)fVar6 + 0x50),
                                                   (int)*(short *)((int)fVar6 + 0x7aa));
                    param_1 = (float)fVar18;
                    *(float *)((int)fVar6 + 0xf18) =
                         param_1 * (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
                    *(float *)((int)fVar6 + 0xf20) =
                         param_1 * (float)(&DAT_029899a0)
                                          [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 &
                                           0x7fff];
                  }
                }
                else {
                  *(undefined4 *)((int)fVar6 + 0xf18) = 0;
                  *(undefined4 *)((int)fVar6 + 0x68) = 0;
                  *(undefined4 *)((int)fVar6 + 0xf20) = 0;
                  *(undefined4 *)((int)fVar6 + 0x70) = 0;
                }
              }
              else {
                if (cVar2 == '\0') {
                  cVar3 = *(char *)((int)fVar6 + 0x7b8);
                  if (cVar3 == '\x02') {
LAB_004adf43:
                    if (cVar3 == '\x06') {
LAB_004adf48:
                      fVar1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x30);
                      if (fVar1 < *(float *)((int)fVar6 + 0x77c) ==
                          (fVar1 == *(float *)((int)fVar6 + 0x77c))) {
                        if (cVar3 != '\x06') goto LAB_004adf71;
                        goto LAB_004adf9f;
                      }
                      *(undefined4 *)((int)fVar6 + 0x70) = 0;
                      *(undefined4 *)((int)fVar6 + 0x68) = 0;
                      local_5c = 0.0;
                    }
                    else {
LAB_004adf71:
                      if ((cVar3 == '\a') || (cVar3 == '\t')) {
LAB_004adf9f:
                        local_5c = *(float *)((int)fVar6 + 0x788);
                      }
                      else if ((*(uint *)((int)fVar6 + 0x7bc) & 0x2000) == 0) {
                        local_5c = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                      }
                      else {
                        local_5c = -*(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                      }
                    }
                    *(float *)((int)fVar6 + 0xf18) =
                         local_5c * (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
                    *(float *)((int)fVar6 + 0xf20) =
                         local_5c *
                         (float)(&DAT_029899a0)
                                [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff];
                    goto LAB_004ad5f0;
                  }
                  if ((*(uint *)((int)fVar6 + 0x7bc) & 0x8000) == 0) {
                    if (cVar3 == '\x06') goto LAB_004adf48;
                    if ((cVar3 == '\a') || (cVar3 == '\t')) goto LAB_004adf43;
                  }
                }
                if (cVar2 == '\x15') {
                  fVar18 = (float10)FUN_0062f1c0(*(undefined4 *)((int)fVar6 + 0x50),
                                                 (int)*(short *)((int)fVar6 + 0x7aa));
                  *(float *)((int)fVar6 + 0xf18) =
                       (float)fVar18 * (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
                  *(float *)((int)fVar6 + 0xf20) =
                       (float)fVar18 *
                       (float)(&DAT_029899a0)
                              [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff];
                }
                else if (cVar2 == 'I') {
                  *(float *)((int)fVar6 + 0xf18) =
                       (*(float *)((int)fVar6 + 0x754) - *(float *)((int)fVar6 + 0x5c)) * 8.0;
                  *(float *)((int)fVar6 + 0xf20) =
                       (*(float *)((int)fVar6 + 0x75c) - *(float *)((int)fVar6 + 100)) * 8.0;
                }
                else if (cVar2 != '\x0f') {
                  if (cVar2 == 'G') {
                    if (*(char *)((int)fVar6 + 0x7b8) == '\x01') {
                      *(undefined4 *)((int)fVar6 + 0xf18) = DAT_0093b0cc;
                      *(undefined4 *)((int)fVar6 + 0xf1c) = DAT_0093b0d0;
                      uVar11 = DAT_0093b0d4;
                      *(undefined4 *)((int)fVar6 + 0xf20) = DAT_0093b0d4;
                      *(undefined4 *)((int)fVar6 + 0x68) = *(undefined4 *)((int)fVar6 + 0xf18);
                      *(undefined4 *)((int)fVar6 + 0x6c) = *(undefined4 *)((int)fVar6 + 0xf1c);
                      *(undefined4 *)((int)fVar6 + 0x70) = uVar11;
                      iVar12 = 1;
                    }
                    else {
                      iVar12 = *(int *)((int)fVar6 + 0x798);
                      if ((*(byte *)(iVar12 + 0x68) & 1) == 0) {
                        iVar17 = (int)fVar6 + 0xf18;
                        FUN_005b3800(iVar17,iVar12 + 0x1c,(int)fVar6 + 0x5c);
                        FUN_005b3b30(iVar17,iVar17);
                        FUN_005b3830(iVar17,iVar17,0x40000000);
                        iVar12 = 1;
                      }
                      else {
                        FUN_0054fb80((int)fVar6 + 0x5c,(int)fVar6 + 0x5c,iVar12 + 0x50,_DAT_007fc254
                                    );
                        iVar12 = 1;
                      }
                    }
                  }
                  else if (cVar2 == '\x10') {
                    if (*(short *)((int)fVar6 + 0x7aa) == 0x29) {
                      fVar18 = (float10)FUN_0062f1c0(*(undefined4 *)((int)fVar6 + 0x50),0x29);
                      param_1 = (float)fVar18;
                    }
                    else {
                      param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                    }
                    *(float *)((int)fVar6 + 0xf18) =
                         param_1 * (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1];
                    *(float *)((int)fVar6 + 0xf20) =
                         param_1 * (float)(&DAT_029899a0)
                                          [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 &
                                           0x7fff];
                  }
                  else if ((cVar2 == '1') && ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0)) {
                    *(float *)((int)fVar6 + 0xf18) =
                         (float)(&DAT_029899a0)[*(ushort *)((int)fVar6 + 0x5a) >> 1] *
                         *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                    *(float *)((int)fVar6 + 0xf20) =
                         (float)(&DAT_029899a0)
                                [(int)(*(ushort *)((int)fVar6 + 0x5a) + 0x4000) >> 1 & 0x7fff] *
                         *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                  }
                  else if ((*(byte *)((int)local_58 + 0x5a) & 2) == 0) {
                    if (cVar2 == '5') goto LAB_004ae238;
                    if (((float)local_58[10] <= 0.0) &&
                       (((((sVar10 = *(short *)((int)fVar6 + 0x1064), sVar10 != DAT_007f18f4 &&
                           (sVar10 != DAT_007f1af4)) && (sVar10 != DAT_007f18f8)) &&
                         (((sVar10 != DAT_007f1914 && (sVar10 != DAT_007f1ae4)) &&
                          (sVar10 != DAT_007f1af8)))) ||
                        (iVar16 = FUN_0062f1a0((int)fVar6 + 8), iVar16 != 0)))) {
                      if (*(short *)((int)fVar6 + 0x1064) == DAT_007f19ec) {
                        iVar16 = FUN_0062f1a0((int)fVar6 + 8);
                        if ((iVar16 == 0) || (iVar16 = FUN_0062f1a0((int)fVar6 + 8), iVar16 == 0x40)
                           ) goto LAB_004ae487;
                      }
                      if (*(char *)((int)fVar6 + 0x39) != '\0') {
                        fVar18 = (float10)FUN_0062f1c0(*(undefined4 *)((int)fVar6 + 0x50),
                                                       (int)*(short *)((int)fVar6 + 0x3a));
                        param_1 = (float)fVar18;
                        if (param_1 != 0.0) {
                          iVar16 = *(short *)((int)fVar6 + 0x3a) * 4;
                          if ((*(byte *)(*(int *)(*(int *)(*(int *)((int)fVar6 + 0x50) + 8) + iVar16
                                                 ) + 4) & 2) == 0) {
                            local_2c = (double)*(float *)((int)fVar6 + 0x18);
                            fVar18 = (float10)FUN_005ca470(*(undefined4 *)
                                                            (*(int *)(*(int *)((int)fVar6 + 0x50) +
                                                                     0xc) + iVar16));
                            if (fVar18 <= (float10)local_2c) goto LAB_004ae238;
                          }
                          sVar10 = *(short *)((int)fVar6 + 0x3a);
                          if ((sVar10 < 0x2e) || (0x3b < sVar10)) {
                            fVar18 = (float10)FUN_0062f220(*(undefined4 *)((int)fVar6 + 0x50),
                                                           (int)sVar10);
                            local_4c = (float)fVar18;
                            if ((local_4c <= 0.0) || (*(float *)((int)fVar6 + 0x18) < local_4c)) {
                              if ((iVar17 == 0) &&
                                 (((*(uint *)(PTR_PTR_007fb0e4 +
                                             *(char *)((int)fVar6 + 0x7b5) * 0x10 + 0xc) & 2) != 0
                                  || ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90
                                                ) & 0x100) != 0)))) {
                                uVar7 = *(ushort *)((int)fVar6 + 0x58);
                              }
                              else {
                                uVar7 = *(ushort *)((int)fVar6 + 0x5a);
                              }
                              *(float *)((int)fVar6 + 0xf18) =
                                   param_1 * (float)(&DAT_029899a0)[uVar7 >> 1];
                              *(float *)((int)fVar6 + 0xf20) =
                                   param_1 * (float)(&DAT_029899a0)
                                                    [(int)(uVar7 + 0x4000) >> 1 & 0x7fff];
                              if ((*(short *)((int)fVar6 + 0x3a) == 0x26) ||
                                 (*(short *)((int)fVar6 + 0x3a) == 0x4f)) goto LAB_004ae46f;
                              goto LAB_004ad5f0;
                            }
                          }
                          *(undefined4 *)((int)fVar6 + 0xf18) = 0;
                          *(undefined4 *)((int)fVar6 + 0xf20) = 0;
                          if ((*(char *)((int)fVar6 + 0x281) == '\0') ||
                             (((cVar2 = *(char *)((int)fVar6 + 0x285), cVar2 < '\0' ||
                               ('\x1f' < cVar2)) || (1.0 <= *(float *)(&DAT_008034c8 + cVar2 * 0xc))
                              ))) {
                            *(undefined4 *)((int)fVar6 + 0x68) = 0;
                            *(undefined4 *)((int)fVar6 + 0x70) = 0;
                          }
                          goto LAB_004ad5f0;
                        }
                      }
LAB_004ae238:
                      *(undefined4 *)((int)fVar6 + 0xf18) = 0;
                      *(undefined4 *)((int)fVar6 + 0xf20) = 0;
                      goto LAB_004ad5f0;
                    }
LAB_004ae487:
                    local_5c = _DAT_007fb080;
                    if (*(char *)((int)fVar6 + 0x7b5) != 'K') {
                      if (((*(char *)((int)fVar6 + 0x287) == '\0') ||
                          (*(short *)((int)fVar6 + 0x1064) == DAT_007f18c8)) ||
                         (*(short *)((int)fVar6 + 0x1064) == DAT_007f18cc)) {
                        local_5c = 1.0;
                      }
                      else {
                        fVar1 = (*(float *)((int)fVar6 + 0x220) - *(float *)((int)fVar6 + 0x17c)) /
                                *(float *)((int)fVar6 + 0x1e0);
                        if (0.0 <= fVar1) {
                          if (fVar1 <= 0.5) {
                            local_5c = 1.0 - (fVar1 + fVar1) * (1.0 - _DAT_007fb080);
                          }
                        }
                        else {
                          local_5c = 0.0;
                        }
                      }
                    }
                    if ((*(uint *)((int)fVar6 + 0xef0) & 0x2000000) == 0) {
                      FUN_0062f1a0((int)fVar6 + 8);
                      iVar16 = FUN_004982f0();
                      if (iVar16 == 0) goto LAB_004ae548;
                      param_1 = 0.0;
                    }
                    else {
LAB_004ae548:
                      sVar10 = *(short *)((int)fVar6 + 0x1064);
                      param_1 = local_4c;
                      if ((sVar10 == DAT_007f18c8) || (sVar10 == DAT_007f18cc)) {
                        if ((*(float *)((int)fVar6 + 0xd3c) == 1.0) ||
                           (*(char *)((int)fVar6 + 0xe33) == '\x01')) {
                          bVar5 = true;
                        }
                        else {
                          bVar5 = false;
                        }
                        if ((*(char *)((int)fVar6 + 0x7b5) == '\0') &&
                           (*(char *)((int)fVar6 + 0x7b8) == '\0')) {
                          param_1 = 1.2;
                        }
                        else if ((!bVar5) || ((float)local_58[10] <= 0.0)) {
                          iVar16 = FUN_0062f150((int)fVar6 + 8,5,1,0);
                          if (iVar16 != 0) {
                            uVar11 = 0x3f333333;
                            goto LAB_004ae592;
                          }
                          if (((!bVar5) && (0.0 < (float)local_58[10])) &&
                             (*(char *)((int)fVar6 + 0x7b5) != '\0')) {
                            param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x14
                                                );
                          }
                        }
                        else {
                          param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x1c);
                        }
                      }
                      else {
                        iVar16 = *(int *)(*(int *)((int)fVar6 + 0x54) + 0x24);
                        if ((*(uint *)(iVar16 + 0x94) & 0x10000000) == 0) {
                          if (sVar10 == DAT_007f1a50) {
                            iVar16 = FUN_0056e160(8);
                            if (iVar16 == 0) {
                              iVar16 = FUN_0062f1a0((int)fVar6 + 8);
                              if (iVar16 == 5) {
                                param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) +
                                                    0x1c) * 0.5;
                              }
                              else {
                                param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) +
                                                    0x18);
                              }
                            }
                          }
                          else if ((sVar10 == DAT_007f1a54) || (sVar10 == DAT_007f1a58)) {
                            if ((*(char *)((int)fVar6 + 0x7b5) == -1) &&
                               (0.0 < *(float *)((int)fVar6 + 0xdb0))) {
                              uVar11 = 0x3f19999a;
                              goto LAB_004ae592;
                            }
                          }
                          else if (sVar10 == DAT_007f1900) {
                            if (*(short *)((int)fVar6 + 0x42) == 5) {
                              param_1 = local_4c * 0.5;
                            }
                          }
                          else if (((sVar10 == DAT_007f18f4) || (sVar10 == DAT_007f1af4)) ||
                                  ((sVar10 == DAT_007f18f8 ||
                                   ((((sVar10 == DAT_007f1914 || (sVar10 == DAT_007f1ae4)) ||
                                     (sVar10 == DAT_007f1af8)) || (sVar10 == DAT_007f19ec)))))) {
                            param_1 = *(float *)(iVar16 + 0x1c);
                          }
                        }
                        else if (*(char *)((int)fVar6 + 0xe32) == '\x01') {
                          uVar11 = 0x3f800000;
LAB_004ae592:
                          fVar18 = (float10)FUN_00499590(uVar11);
                          param_1 = (float)fVar18;
                        }
                        else {
                          param_1 = *(float *)(iVar16 + 0x18);
                        }
                      }
                    }
                    if ((*(char *)((int)fVar6 + 0x7b5) == '\0') &&
                       (*(char *)((int)fVar6 + 0x7b8) == '\0')) {
                      param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x84) *
                                param_1;
                    }
                    if ((*(uint *)((int)fVar6 + 0xef0) & 0x4000) != 0) {
                      param_1 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x20) *
                                param_1;
                    }
                    if ((iVar17 == 0) &&
                       (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)((int)fVar6 + 0x7b5) * 0x10 + 0xc) &
                         2) != 0 ||
                        ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x100) !=
                         0)))) {
                      uVar7 = *(ushort *)((int)fVar6 + 0x58);
                    }
                    else {
                      uVar7 = (ushort)local_54;
                    }
                    if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b158) &&
                        ((*(byte *)((int)fVar6 + 0x1fc) & 0x80) == 0)) &&
                       (PTR_DAT_008021b4[1] == '\0')) {
                      param_1 = param_1 * 1.0416666;
                    }
                    *(float *)((int)fVar6 + 0xf18) =
                         local_5c * param_1 * (float)(&DAT_029899a0)[uVar7 >> 1];
                    *(float *)((int)fVar6 + 0xf20) =
                         param_1 * (float)(&DAT_029899a0)[(int)(uVar7 + 0x4000) >> 1 & 0x7fff] *
                         local_5c;
                  }
                  else {
                    *(undefined4 *)((int)fVar6 + 0xf18) = 0;
                    *(undefined4 *)((int)fVar6 + 0xf20) = 0;
                  }
                }
              }
            }
          }
          else {
            *(undefined4 *)((int)fVar6 + 0xf18) = 0;
            *(undefined4 *)((int)fVar6 + 0xf20) = 0;
          }
        }
      }
      else {
        iVar16 = (int)local_2c._0_4_;
        fVar18 = (float10)FUN_0062f1c0(*(undefined4 *)((int)fVar6 + 0x50),local_2c._0_4_);
        param_1 = (float)fVar18;
        if (param_1 == 0.0) goto LAB_004adae1;
        iVar15 = FUN_0058e0c0(fVar6);
        if ((iVar15 != 0) && (iVar15 = FUN_0058e130(fVar6), iVar15 != 0)) goto LAB_004ad5f0;
        param_1 = *(float *)((int)fVar6 + 0x1034) * param_1;
        fVar18 = (float10)FUN_0062f220(*(undefined4 *)((int)fVar6 + 0x50),iVar16);
        local_4c = (float)fVar18;
        pfVar14 = (float *)FUN_0062f150((int)fVar6 + 8,iVar16,1,0);
        if (1.0 < local_4c) {
          if (pfVar14 != (float *)0x0) {
            if (*pfVar14 < local_4c) goto LAB_004ad9de;
            goto LAB_004ada0d;
          }
        }
        else {
LAB_004ad9de:
          if (((pfVar14 != (float *)0x0) && (*(char *)((int)fVar6 + 0x281) != '\0')) &&
             ((*(int *)(*(int *)(*(int *)((int)fVar6 + 0x50) + 0xc) + iVar16 * 4) != 0 &&
              (((*(byte *)(*(int *)(*(int *)(*(int *)((int)fVar6 + 0x50) + 8) + iVar16 * 4) + 4) & 2
                ) == 0 && ((*(byte *)((int)fVar6 + 0x38) & 1) != 0)))))) {
LAB_004ada0d:
            *(undefined4 *)((int)fVar6 + 0xf18) = 0;
            *(undefined4 *)((int)fVar6 + 0xf20) = 0;
            if ((*(char *)((int)fVar6 + 0x281) == '\0') ||
               ((cVar2 = *(char *)((int)fVar6 + 0x285), cVar2 < '\0' || ('\x1f' < cVar2)))) {
              *(undefined4 *)((int)fVar6 + 0x68) = 0;
              *(undefined4 *)((int)fVar6 + 0x70) = 0;
            }
            else if (1.0 <= *(float *)(&DAT_008034c8 + cVar2 * 0xc)) {
              *(undefined4 *)((int)fVar6 + 0x68) = 0;
              *(undefined4 *)((int)fVar6 + 0x70) = 0;
            }
            goto LAB_004ad5f0;
          }
        }
        if (((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x100) == 0) ||
           (iVar17 != 0)) {
          uVar7 = *(ushort *)((int)fVar6 + 0x5a);
        }
        else {
          uVar7 = *(ushort *)((int)fVar6 + 0x58);
        }
        *(float *)((int)fVar6 + 0xf18) = param_1 * (float)(&DAT_029899a0)[uVar7 >> 1];
        *(float *)((int)fVar6 + 0xf20) =
             param_1 * (float)(&DAT_029899a0)[(int)(uVar7 + 0x4000) >> 1 & 0x7fff];
        if ((*(char *)((int)fVar6 + 0x7b5) != '%') || (*(short *)((int)fVar6 + 0x7aa) == 0x58))
        goto LAB_004ad5f0;
LAB_004ae46f:
        FUN_005b3620((int)fVar6 + 0xf18,(int)fVar6 + 0xf18,0x4000);
      }
    }
  }
  else {
    *(uint *)((int)fVar6 + 0xe20) = *(uint *)((int)fVar6 + 0xe20) | 0x10000000;
    *(undefined4 *)((int)fVar6 + 0xf18) = *(undefined4 *)((int)fVar6 + 0x200);
    *(undefined4 *)((int)fVar6 + 0xf20) = *(undefined4 *)((int)fVar6 + 0x208);
    *(undefined4 *)((int)fVar6 + 0x208) = 0;
    *(undefined4 *)((int)fVar6 + 0x200) = 0;
  }
LAB_004ad5f0:
  if ((*(uint *)((int)fVar6 + 0xef0) & 0x8000) == 0) {
    if (((*(byte *)((int)fVar6 + 0x1fc) & 0x80) != 0) &&
       ((*(uint *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 0x100) != 0)) {
      FUN_005a83c0(fVar6,(int)fVar6 + 0xf18);
    }
  }
  else {
    FUN_005b3620((int)fVar6 + 0xf18,(int)fVar6 + 0xf18,0x8000);
  }
  if (*(char *)((int)fVar6 + 0x7b5) == 'K') {
    *(float *)((int)fVar6 + 0xf1c) =
         (*(float *)((int)fVar6 + 0x220) -
         ((*(float *)((int)fVar6 + 0x188) - *(float *)((int)fVar6 + 0x17c)) * _DAT_007fb078 +
         *(float *)((int)fVar6 + 0x17c))) * 3.0;
    if ((*(int *)((int)fVar6 + 0xcbc) == 0) ||
       ((*(byte *)(*(int *)((int)fVar6 + 0xcbc) + 0xc) & 0x10) == 0)) {
LAB_004aea8a:
      iVar12 = 1;
    }
    else {
      if ((*(uint *)(*(int *)((int)fVar6 + 0xca4) + 4) & DAT_00802280) != 0) {
        if (*(float *)((int)fVar6 + 0x194) < *(float *)((int)fVar6 + 0x220)) {
          *(undefined4 *)((int)fVar6 + 0xf1c) = 0x3f19999a;
        }
        goto LAB_004aea8a;
      }
      *(undefined4 *)((int)fVar6 + 0xf1c) = 0;
    }
    local_20 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x44);
    local_1c = 1.0;
    local_24 = 1.0;
  }
  else if (local_3c == 0) {
    if (iVar12 == 0) {
      local_20 = *(float *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x44);
      local_1c = local_24;
    }
    else {
      local_1c = local_24;
      local_20 = local_24;
    }
  }
  if (((*(char *)((int)fVar6 + 0x281) != '\0') && (*(char *)((int)fVar6 + 0x285) != -1)) &&
     (fVar1 = *(float *)(&DAT_008034c8 + *(char *)((int)fVar6 + 0x285) * 0xc), fVar1 != 1.0)) {
    local_24 = fVar1 * local_24;
    local_1c = fVar1 * local_1c;
  }
  if (*(char *)((int)fVar6 + 0x7b5) == '+') {
    if (1.0 <= *(float *)((int)fVar6 + 0xd98)) {
      *(undefined4 *)((int)fVar6 + 0xf20) = 0;
      *(undefined4 *)((int)fVar6 + 0xf18) = 0;
    }
    else {
      fVar1 = 1.0 - *(float *)((int)fVar6 + 0xd98);
      *(float *)((int)fVar6 + 0xf18) = fVar1 * *(float *)((int)fVar6 + 0xf18);
      *(float *)((int)fVar6 + 0xf20) = fVar1 * *(float *)((int)fVar6 + 0xf20);
      if ((*(char *)((int)fVar6 + 0xe37) == '\x02') || (*(char *)((int)fVar6 + 0xe37) == '\x04')) {
        *(float *)((int)fVar6 + 0xf18) = *(float *)((int)fVar6 + 0xf18) * 0.5;
        *(float *)((int)fVar6 + 0xf20) = *(float *)((int)fVar6 + 0xf20) * 0.5;
      }
    }
    if ((*(char *)((int)fVar6 + 0xe37) == '\x02') || (*(char *)((int)fVar6 + 0xe37) == '\x04')) {
      iVar17 = FUN_0054fa60(0);
      param_1 = (float)iVar17 * 1.5259022e-05 * 0.25;
      FUN_0054a850(*local_58,param_1);
      iVar17 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x488);
      if ((iVar17 != -1) && (iVar16 = FUN_0062c350(0x42700000,_DAT_00925018), 0 < iVar16)) {
        local_18 = *(float *)((int)fVar6 + 0x80);
        local_14 = *(undefined4 *)((int)fVar6 + 0x220);
        local_10 = *(float *)((int)fVar6 + 0x88);
        FUN_00684c90(iVar17,&local_18,iVar16,0,0);
      }
    }
  }
  if (((((*(uint *)((int)fVar6 + 0xe20) & 0x10000000) == 0) &&
       (*(char *)((int)fVar6 + 0x281) != '\0')) && (*(char *)((int)fVar6 + 0x285) != -1)) &&
     ((*(uint *)(&DAT_008034cc + *(char *)((int)fVar6 + 0x285) * 0xc) & 0x100) != 0)) {
    FUN_00572750((int)fVar6 + 0xf18);
  }
  if ((iVar12 == 0) && (iVar12 = FUN_0056db40(fVar6), iVar12 == 0)) {
    if (((*(byte *)((int)fVar6 + 0xe20) & 8) == 0) || (*(char *)((int)fVar6 + 0x281) == '\0')) {
      *(undefined4 *)((int)fVar6 + 0xd78) = 0x3f800000;
    }
    else {
      fVar18 = (float10)FUN_005bec80((int)fVar6 + 0x68);
      local_2c = (double)CONCAT44(local_2c._4_4_,(float)fVar18);
      fVar18 = (float10)FUN_005bec80((int)fVar6 + 0xf18);
      if ((float)fVar18 <= 0.0) {
LAB_004aed44:
        fVar4 = 5.0;
      }
      else {
        fVar1 = local_2c._0_4_ / (float)fVar18;
        if (1.0 < fVar1) {
          fVar1 = 1.0 - (fVar1 - 1.0);
        }
        fVar4 = 1.0;
        if (fVar1 < 0.7) goto LAB_004aed44;
        if (0.8 <= fVar1) {
          if (0.9 <= fVar1) {
            if (fVar1 < 1.0) {
              fVar4 = 2.0 - (fVar1 - 0.9) / 0.1;
            }
          }
          else {
            fVar4 = 3.0;
          }
        }
        else {
          fVar4 = 4.0;
        }
      }
      param_1 = _DAT_00925018 * 5.0;
      fVar18 = (float10)FUN_0054fad0(*(undefined4 *)((int)fVar6 + 0xd78),fVar4,param_1);
      param_1 = (float)fVar18;
      *(float *)((int)fVar6 + 0xd78) = param_1;
      if (1.0 < param_1) {
        local_24 = *(float *)((int)fVar6 + 0xd78) * local_24;
        local_1c = local_1c * *(float *)((int)fVar6 + 0xd78);
      }
    }
    if (*(char *)((int)fVar6 + 0x7b5) == '&') {
      *(undefined4 *)((int)fVar6 + 0x68) = *(undefined4 *)((int)fVar6 + 0xf18);
      fVar18 = (float10)*(float *)((int)fVar6 + 0xf20);
      goto LAB_004aeef3;
    }
    fVar18 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x68),
                                   *(undefined4 *)((int)fVar6 + 0xf18),local_24);
    *(float *)((int)fVar6 + 0x68) = (float)fVar18;
  }
  else {
    if ((*(int *)((int)fVar6 + 0x798) != 0) &&
       ((*(byte *)(*(int *)((int)fVar6 + 0x798) + 0x68) & 1) != 0)) {
      local_24 = _DAT_007fc250 * local_24;
      local_20 = _DAT_007fc250 * local_20;
      local_1c = _DAT_007fc250 * local_1c;
    }
    fVar18 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x68),
                                   *(undefined4 *)((int)fVar6 + 0xf18),local_24);
    *(float *)((int)fVar6 + 0x68) = (float)fVar18;
    fVar18 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x6c),
                                   *(undefined4 *)((int)fVar6 + 0xf1c),local_20);
    *(float *)((int)fVar6 + 0x6c) = (float)fVar18;
  }
  fVar18 = (float10)FUN_0054fb40(*(undefined4 *)((int)fVar6 + 0x70),
                                 *(undefined4 *)((int)fVar6 + 0xf20),local_1c);
LAB_004aeef3:
  *(float *)((int)fVar6 + 0x70) = (float)fVar18;
  if ((*(byte *)(*(int *)(*(int *)((int)fVar6 + 0x54) + 0x24) + 0x90) & 1) == 0) {
    if (*(char *)((int)fVar6 + 0x7b5) == 'K') {
      if (*(float *)(*(int *)((int)fVar6 + 0xca4) + 0x28) <= 0.0) {
        iVar12 = 0;
      }
      else {
        param_1 = (float)FUN_00550040(*(undefined2 *)((int)fVar6 + 0x1060),
                                      *(undefined2 *)((int)fVar6 + 0x27a));
        iVar12 = FUN_006e6b90();
        iVar12 = iVar12 / 0xf;
        if (iVar12 < -0x2000) {
          iVar12 = -0x2000;
        }
        else if (0x2000 < iVar12) {
          iVar12 = 0x2000;
        }
      }
      uVar9 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0xe18),iVar12,0x41000000);
      *(undefined2 *)((int)fVar6 + 0xe18) = uVar9;
    }
    else {
      *(undefined2 *)((int)fVar6 + 0xe18) = 0;
    }
  }
  else {
    param_1 = (float)FUN_00550040(*(undefined2 *)((int)fVar6 + 0x1060),
                                  *(undefined2 *)((int)fVar6 + 0x27a));
    iVar12 = FUN_006e6b90();
    if (iVar12 < -0x10000) {
      iVar12 = -0x10000;
    }
    else if (0x10000 < iVar12) {
      iVar12 = 0x10000;
    }
    iVar12 = (int)(iVar12 + (iVar12 >> 0x1f & 3U)) >> 2;
    if (iVar12 < -0x2000) {
      iVar12 = -0x2000;
    }
    else if (0x2000 < iVar12) {
      iVar12 = 0x2000;
    }
    uVar9 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0xe18),iVar12,0x41000000);
    *(undefined2 *)((int)fVar6 + 0xe18) = uVar9;
  }
  if ((*(char *)((int)fVar6 + 0x7b5) == '=') && (*(short *)((int)fVar6 + 0x7aa) != 0x85)) {
    iVar12 = (-(uint)(*(char *)((int)fVar6 + 0x7b3) != '\0') & 0x6e38) - 0x31c7;
  }
  else if ((*(char *)((int)fVar6 + 0x7b5) == '/') && (*(short *)((int)fVar6 + 0x7aa) == 5)) {
    iVar12 = -0x4000;
  }
  else {
    iVar12 = 0;
  }
  uVar9 = FUN_00550070(*(undefined2 *)((int)fVar6 + 0xe1a),iVar12,0x40a00000);
  *(undefined2 *)((int)fVar6 + 0xe1a) = uVar9;
  FUN_0056a5b0(PTR_DAT_00802c54,fVar6);
  return;
}

