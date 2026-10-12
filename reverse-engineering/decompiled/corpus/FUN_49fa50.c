/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x49fa50; label: FUN_0049fa50
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049fa50(int param_1,undefined4 param_2)

{
  float fVar1;
  char cVar2;
  float fVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  float *pfVar9;
  uint uVar10;
  int unaff_EDI;
  float10 fVar11;
  int local_88;
  int iStack_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70 [4];
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int local_2c;
  int local_28;
  undefined1 local_24 [12];
  float local_18;
  float local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(float *)(unaff_EDI + 0xd3c) < 1.0) {
    return;
  }
  cVar2 = *(char *)(unaff_EDI + 0x7b5);
  if ((((cVar2 == '\0') &&
       ((*(char *)(unaff_EDI + 0x7b8) == '\x02' || (*(char *)(unaff_EDI + 0x7b8) == '\x04')))) ||
      ((cVar2 == '\x04' ||
       ((cVar2 == '\x10' ||
        ((((cVar2 == '\r' && (*(short *)(unaff_EDI + 0x1064) != DAT_007f19a0)) || (cVar2 == '\x0e'))
         || ((cVar2 == '\x1f' && (*(char *)(unaff_EDI + 0x7b3) == '\x01')))))))))) ||
     (((*(byte *)(unaff_EDI + 0x1fc) & 0x80) != 0 &&
      (iVar5 = FUN_0056e460((int)*(char *)(unaff_EDI + 0x280)), iVar5 != 0)))) {
    *(byte *)(unaff_EDI + 0xe34) = *(byte *)(unaff_EDI + 0xe34) | 2;
  }
  if (*(short *)(unaff_EDI + 0x1064) == DAT_007f1878) {
    *(byte *)(unaff_EDI + 0xe34) = *(byte *)(unaff_EDI + 0xe34) & 0xfc;
  }
  if (*(char *)(unaff_EDI + 0xe34) == '\0') {
    return;
  }
  iVar5 = FUN_0049f780();
  if (iVar5 == 0) {
    return;
  }
  *(undefined1 *)(unaff_EDI + 0xe44 + param_1) = 0xff;
  local_70[0] = *(float *)(local_88 * 0x40 + 0x834 + unaff_EDI);
  iVar5 = local_88 * 0x40 + 0x834 + unaff_EDI;
  local_70[1] = *(float *)(iVar5 + 4);
  local_70[2] = *(float *)(iVar5 + 8);
  pfVar9 = (float *)(iStack_84 * 0x40 + 0x834 + unaff_EDI);
  local_70[3] = *pfVar9;
  local_60 = pfVar9[1];
  local_5c = pfVar9[2];
  if ((*(byte *)(unaff_EDI + 0xe34) & 2) != 0) {
    if (*(char *)(unaff_EDI + 0x280) == -1) {
LAB_0049fbbf:
      if ((*(short *)(unaff_EDI + 0x1064) == DAT_007f1968) && ((param_1 == 0 || (param_1 == 3)))) {
        *(undefined1 *)(unaff_EDI + 0xe44 + param_1) = 2;
      }
      else {
        iVar5 = FUN_004190e0();
        if ((iVar5 == 0) &&
           ((*(short *)(unaff_EDI + 0x1064) != DAT_007f19dc ||
            ((*(uint *)(unaff_EDI + 0xef0) & 0x200) == 0)))) {
          *(undefined1 *)(unaff_EDI + 0xe44 + param_1) =
               *(undefined1 *)(*(short *)(unaff_EDI + 0x1064) * 0x120 + 0x117 + DAT_0093b284);
        }
        else {
          *(undefined1 *)(unaff_EDI + 0xe44 + param_1) = 1;
        }
      }
    }
    else {
      iVar5 = FUN_0056e160(0x19);
      if (iVar5 == 0) {
        if ((*(char *)(unaff_EDI + 0x280) == -1) || (iVar5 = FUN_0041af30(), iVar5 == 0))
        goto LAB_0049fbbf;
        *(undefined1 *)(unaff_EDI + 0xe44 + param_1) = 3;
      }
      else {
        *(undefined1 *)(unaff_EDI + 0xe44 + param_1) = 0;
      }
    }
    fVar1 = local_4c;
    iVar5 = *(char *)(unaff_EDI + 0xe44 + param_1) * 0x10;
    uVar10 = (((byte)(&DAT_007fb0f4)[iVar5] | 0xffffff00) << 8 | (uint)(byte)(&DAT_007fb0f3)[iVar5])
             << 8 | (uint)(byte)(&DAT_007fb0f2)[iVar5];
    if (((*(char *)(unaff_EDI + 0x288) != '\0') &&
        (FUN_005a3730(local_70,0x3e800000,uVar10,unaff_EDI + 0xcd8 + (int)local_4c * 8,0),
        *(char *)(unaff_EDI + 0x107b) != '\0')) && (*(float *)(unaff_EDI + 0x1014) != 2e+06)) {
      if (*(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0) == 2e+06) {
        local_74 = *(float *)(unaff_EDI + 0x1014);
      }
      else {
        local_74 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0);
      }
      local_18 = local_70[0];
      local_14 = local_74 - (local_70[1] - local_74);
      local_10 = local_70[2];
      local_c = local_70[3];
      local_8 = local_74 - (local_60 - local_74);
      local_4 = local_5c;
      FUN_005a3730(&local_18,0x3e800000,uVar10,unaff_EDI + 0xcdc + (int)fVar1 * 8,1);
    }
  }
  if ((*(byte *)(unaff_EDI + 0xe34) & 7) == 0) {
    return;
  }
  if (*(char *)(unaff_EDI + 0x280) == -1) {
LAB_0049fdb3:
    if ((*(short *)(unaff_EDI + 0x1064) == DAT_007f1968) &&
       ((param_1 == 0 || (param_2 = 2, param_1 == 3)))) {
      param_2 = 3;
    }
  }
  else {
    iVar5 = FUN_0056e160(0x19);
    if (iVar5 == 0) {
      if ((*(char *)(unaff_EDI + 0x280) == -1) || (iVar5 = FUN_0041af30(), iVar5 == 0))
      goto LAB_0049fdb3;
      param_2 = 4;
    }
    else {
      param_2 = 1;
    }
  }
  if ((((*(char *)(*(int *)(*(int *)(unaff_EDI + 0x54) + 0x24) + 0x116) == '\f') &&
       (*(char *)(unaff_EDI + 0x7b5) == '\x05')) && (*(char *)(unaff_EDI + 0x7b2) == '\x02')) &&
     ((*(short *)(unaff_EDI + 0x7aa) == 0x34 && (*(int *)(*(int *)(unaff_EDI + 0x50) + 0x24) != 0)))
     ) {
    local_70[0] = *(float *)(unaff_EDI + 0x934);
    local_70[1] = *(float *)(unaff_EDI + 0x938);
    local_70[2] = *(float *)(unaff_EDI + 0x93c);
    FUN_005b37d0(local_70 + 3,local_70,unaff_EDI + 0x80);
    FUN_005b3830(local_70 + 3,local_70 + 3,0x3f000000);
  }
  fVar11 = (float10)FUN_005becc0(local_70,local_70 + 3,&local_80);
  local_58 = local_70[3] + local_80 * 0.5;
  local_54 = local_7c * 0.5 + local_60;
  local_50 = local_78 * 0.5 + local_5c;
  *(float *)(unaff_EDI + 0xd44) = (float)fVar11 * 0.25;
  local_40 = (float)fVar11 * 1.5;
  local_3c = local_58 - local_40;
  local_38 = local_54 - local_40;
  local_34 = local_50 - local_40;
  local_48 = local_40 + local_58;
  local_44 = local_54 + local_40;
  local_40 = local_40 + local_50;
  if ((*(byte *)(unaff_EDI + 0xe34) & 4) != 0) {
    if (*(char *)(unaff_EDI + 0x7b5) == '\x10') {
      sVar4 = *(short *)(unaff_EDI + 0x27a) + -0x8000;
    }
    else {
      sVar4 = *(short *)(unaff_EDI + 0x27a);
    }
    FUN_005b3620(local_24,&DAT_0080250c,sVar4);
    FUN_005b3830(&local_80,local_24,0x3e4ccccd);
    iVar5 = unaff_EDI + 0x80;
    FUN_005b37d0(local_70,iVar5,&local_80);
    FUN_005b3830(&local_80,local_24,0x3f000000);
    FUN_005b37d0(local_70 + 3,iVar5,&local_80);
    FUN_005b3830(&local_80,local_24,0x3eb33333);
    FUN_005b37d0(&local_58,iVar5,&local_80);
    if (*(char *)(unaff_EDI + 0x7b5) == '\r') {
      local_70[1] = (*(float *)(unaff_EDI + 0x194) - *(float *)(unaff_EDI + 0x1a0)) * 0.333 +
                    *(float *)(unaff_EDI + 0x1a0);
      local_60 = local_70[1];
      local_54 = local_70[1];
    }
    fVar11 = (float10)FUN_005becc0(local_70,local_70 + 3,&local_80);
    local_58 = local_70[3] + local_80 * 0.5;
    local_54 = local_7c * 0.5 + local_60;
    local_50 = local_78 * 0.5 + local_5c;
    *(float *)(unaff_EDI + 0xd44) = (float)fVar11 * 0.25;
    local_40 = (float)fVar11 * 1.5;
    local_3c = local_58 - local_40;
    local_38 = local_54 - local_40;
    local_34 = local_50 - local_40;
    local_48 = local_40 + local_58;
    local_44 = local_54 + local_40;
    local_40 = local_40 + local_50;
  }
  if ((*(byte *)(unaff_EDI + 0xe34) & 5) == 0) goto LAB_004a0865;
  iVar5 = 0;
  local_30 = 1e+06;
  local_28 = 0;
  local_4c = 0.0;
  if (*(char *)(unaff_EDI + 0x280) == -1) {
LAB_004a011f:
    if ((*(short *)(unaff_EDI + 0x1064) == DAT_007f1968) &&
       ((param_1 == 0 || (param_2 = 2, param_1 == 3)))) {
      param_2 = 3;
    }
  }
  else {
    iVar6 = FUN_0056e160(0x19);
    if (iVar6 == 0) {
      if ((*(char *)(unaff_EDI + 0x280) == -1) || (iVar6 = FUN_0041af30(), iVar6 == 0))
      goto LAB_004a011f;
      param_2 = 4;
    }
    else {
      param_2 = 1;
    }
  }
  local_2c = 0;
  iVar6 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((((((iVar6 != unaff_EDI) && ((*(uint *)(iVar6 + 0x1fc) & 1) != 0)) &&
             ((*(uint *)(iVar6 + 0x1fc) & 0x1000) != 0)) &&
            ((1 < *(byte *)(iVar6 + 0x1079) && (*(char *)(iVar6 + 0x28b) == '\0')))) &&
           (cVar2 = *(char *)(iVar6 + 0x7b5), cVar2 != ';')) &&
          (((((cVar2 != '9' && (cVar2 != '<')) &&
             (((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000) == 0 &&
              ((((*(uint *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x90) & 0x8000) == 0 &&
                (*(float *)(iVar6 + 0x178) <= local_48)) && (local_3c <= *(float *)(iVar6 + 0x184)))
              )))) && ((*(float *)(iVar6 + 0x180) <= local_40 &&
                       (local_34 <= *(float *)(iVar6 + 0x18c))))) &&
           (*(float *)(iVar6 + 0x17c) <= local_44)))) && (local_38 <= *(float *)(iVar6 + 0x188))) {
        local_74 = 2.8026e-45;
        pfVar9 = &local_58;
        do {
          iVar7 = FUN_0054fce0(iVar6 + 0x80,*(undefined4 *)(iVar6 + 0x1dc),
                               *(undefined4 *)(iVar6 + 0x1e0),pfVar9,
                               *(undefined4 *)(unaff_EDI + 0xd44),*(undefined4 *)(unaff_EDI + 0xd44)
                              );
          if (iVar7 != 0) {
            if ((*(byte *)(unaff_EDI + 0xe34) & 1) != 0) {
              if (((*(byte *)(iVar6 + 0x1fc) & 2) == 0) &&
                 ((*(uint *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x90) & 0x1040) == 0)) {
                FUN_005b3800(&local_80,iVar6 + 0x80,unaff_EDI + 0x80);
                if ((local_80 == 0.0) && (local_78 == 0.0)) {
                  iVar5 = FUN_0054fa60();
                  local_80 = (float)iVar5 * 1.5259022e-05 - 0.5;
                  iVar5 = FUN_0054fa60();
                  local_78 = (float)iVar5 * 1.5259022e-05 - 0.5;
                }
                FUN_005b3b30(&local_80,&local_80);
                iVar5 = *(int *)(iVar6 + 0x54);
                *(float *)(iVar6 + 0x200) =
                     *(float *)(*(int *)(iVar5 + 0x24) + 0x18) * local_80 + *(float *)(iVar6 + 0x68)
                ;
                fVar3 = *(float *)(*(int *)(iVar5 + 0x24) + 0x18) * local_78 +
                        *(float *)(iVar6 + 0x70);
                *(float *)(iVar6 + 0x208) = fVar3;
                fVar1 = *(float *)(*(int *)(iVar5 + 0x24) + 0x1c);
                fVar3 = *(float *)(iVar6 + 0x200) * *(float *)(iVar6 + 0x200) + fVar3 * fVar3;
                if (fVar1 * fVar1 < fVar3) {
                  fVar11 = (float10)FUN_005c0240(fVar3);
                  *(float *)(iVar6 + 0x200) =
                       (float)((float10)fVar1 / fVar11) * *(float *)(iVar6 + 0x200);
                  *(float *)(iVar6 + 0x208) =
                       (float)((float10)fVar1 / fVar11) * *(float *)(iVar6 + 0x208);
                }
              }
              uVar8 = FUN_0062c350(0x41200000,_DAT_00925018,0,0);
              FUN_0062c680(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),param_2,pfVar9,uVar8);
              if (((((_DAT_0087b8c0 <= 0.0) && (*(char *)(unaff_EDI + 0x39) == '\0')) &&
                   (cVar2 = *(char *)(unaff_EDI + 0x7b5), cVar2 != '\x05')) &&
                  (((cVar2 != '\x10' && (cVar2 != '\r')) &&
                   ((cVar2 != '\x0e' &&
                    ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x4000000) == 0)))))) &&
                 ((((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000000) == 0 ||
                   ((*(uint *)(unaff_EDI + 0x7bc) & 0x20000) == 0)) &&
                  ((cVar2 = *(char *)(iVar6 + 0x7b5), cVar2 != '\x05' &&
                   (((((cVar2 != '\x10' && (cVar2 != '\r')) && (cVar2 != '\x0e')) &&
                     ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x4000000) == 0)) &&
                    (((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000000) == 0 ||
                     ((*(uint *)(iVar6 + 0x7bc) & 0x20000) == 0)))))))))) {
                FUN_00681f40("SaberSparks",pfVar9);
                iVar5 = FUN_0054fa60();
                _DAT_0087b8c0 = (float)iVar5 * 1.5259022e-05 * 0.3 + 0.3;
                iVar5 = FUN_0054fa60(0);
                FUN_0054a850(**(undefined4 **)(unaff_EDI + 0xca4),
                             (float)iVar5 * 1.5259022e-05 * 0.2 + 0.2);
                iVar5 = FUN_0054fa60(0);
                FUN_0054a850(**(undefined4 **)(iVar6 + 0xca4),
                             (float)iVar5 * 1.5259022e-05 * 0.2 + 0.2);
              }
            }
            fVar11 = (float10)FUN_005b3c50(unaff_EDI + 0x80,iVar6 + 0x80,0);
            iVar5 = local_28;
            if ((float)fVar11 < local_30) {
              local_4c = local_74;
              iVar5 = iVar6;
              local_30 = (float)fVar11;
              local_28 = iVar6;
            }
          }
          local_74 = (float)((int)local_74 + -1);
          pfVar9 = pfVar9 + -3;
        } while (-1 < (int)local_74);
      }
      local_2c = local_2c + 1;
      iVar6 = iVar6 + 0x10d8;
    } while (local_2c < DAT_0093d500);
    if ((iVar5 != 0) && ((*(byte *)(unaff_EDI + 0xe34) & 4) != 0)) {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),param_2,local_70 + (int)local_4c * 3);
      iVar6 = FUN_0058b7f0(iVar5);
      if (iVar6 == 0) {
        if (((*(char *)(unaff_EDI + 0xe35) != '\0') && ((*(byte *)(iVar5 + 0x1fc) & 0x80) != 0)) &&
           ((*(byte *)(unaff_EDI + 0x1fc) & 0x80) != 0)) {
          FUN_0055f320();
        }
        FUN_0058b720();
        FUN_00438230();
        return;
      }
      FUN_0054a850(**(undefined4 **)(unaff_EDI + 0xca4),0x3f000000,0);
      FUN_0054a850(**(undefined4 **)(iVar5 + 0xca4),0x3f000000,0);
      return;
    }
  }
  uVar10 = *(uint *)(unaff_EDI + 0x1fc) >> 7 & 1;
  if ((((uVar10 != 0) || ((*(byte *)(unaff_EDI + 0xeec) & 0x40) != 0)) ||
      (*(char *)(unaff_EDI + 0xf00) == '\x05')) && ((*(byte *)(unaff_EDI + 0xe34) & 4) != 0)) {
    if ((uVar10 == 0) && (*(char *)(unaff_EDI + 0x288) == '\0')) {
      if (*(int *)(unaff_EDI + 0x794) == 0) {
        return;
      }
      FUN_00567800(*(int *)(unaff_EDI + 0x794),1,0xffffffff,1,0,1);
      FUN_004399e0();
      return;
    }
    iVar5 = FUN_00569c70();
    if (iVar5 != 0) {
      pfVar9 = local_70;
      iVar5 = 3;
      do {
        FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),param_2,pfVar9);
        pfVar9 = pfVar9 + 3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      FUN_0054a850(**(undefined4 **)(unaff_EDI + 0xca4),0x3f400000,0);
      return;
    }
  }
LAB_004a0865:
  if (((*(byte *)(unaff_EDI + 0xe34) & 6) != 0) && (iVar5 = FUN_0064ab10(), iVar5 != 0)) {
    if ((*(byte *)(iVar5 + 0x108) & 8) == 0) {
      FUN_0064ac90(iVar5,0);
    }
    else {
      FUN_0042c500(iVar5);
    }
    FUN_004399e0();
  }
  return;
}

