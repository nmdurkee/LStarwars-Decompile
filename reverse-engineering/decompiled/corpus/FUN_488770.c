/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x488770; label: FUN_00488770
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00488770(float param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  char cVar3;
  short sVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float10 fVar10;
  float10 extraout_ST0;
  undefined4 uVar11;
  float local_20;
  int local_1c;
  float local_c;
  float local_8;
  float local_4;
  
  iVar7 = (int)param_1;
  cVar3 = *(char *)((int)param_1 + 0x7b5);
  if (cVar3 != '<') {
    *(byte *)((int)param_1 + 0x7c5) = *(byte *)((int)param_1 + 0x7c5) & 0xfe;
    iVar7 = *(int *)((int)param_1 + 0xcd0);
    if (iVar7 == 0) {
      fVar2 = *(float *)((int)param_1 + 0xdd0);
      if (!NAN(fVar2) && 0.0 < fVar2 != (fVar2 == 0.0)) {
        *(float *)((int)param_1 + 0xdd0) = *(float *)((int)param_1 + 0xdd0) - _DAT_00925018;
        return;
      }
      if (DAT_00855de0 != 0) {
        return;
      }
      if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) {
        return;
      }
      if (*(char *)((int)param_1 + 0x28b) != '\0') {
        return;
      }
      if (0.0 < *(float *)((int)param_1 + 0xdd0)) {
        return;
      }
      if (cVar3 == '+') {
        return;
      }
      if (cVar3 != -1) {
        if (cVar3 != '\0') {
          return;
        }
        if (*(char *)((int)param_1 + 0x7b8) == '\x03') {
          return;
        }
        if (*(char *)((int)param_1 + 0x7b8) == '\x04') {
          return;
        }
      }
      local_20 = 9.0;
      if ((*(char *)((int)param_1 + 0x281) != '\0') && (0 < DAT_0093d500)) {
        local_1c = DAT_0093d500;
        iVar7 = DAT_0093d504;
        iVar6 = 0;
        do {
          iVar9 = iVar6;
          fVar2 = local_20;
          if ((((((((*(uint *)(iVar7 + 0x1fc) & 1) != 0) &&
                  ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) && (*(char *)(iVar7 + 0x28b) == '\0'))
                && ((*(char *)(iVar7 + 0x280) == -1 &&
                    (cVar3 = *(char *)(iVar7 + 0x7b5),
                    (*(uint *)(PTR_PTR_007fb0e4 + cVar3 * 0x10 + 8) & 0x8000) == 0)))) &&
               ((*(int *)(iVar7 + 0xcd0) == 0 &&
                ((*(byte *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x90) & 0x40) != 0)))) &&
              (((*(uint *)(*(int *)(iVar7 + 0x54) + 4) & 0x40000000) == 0 ||
               ((cVar3 != '\x17' && (cVar3 != '>')))))) && ((*(byte *)(iVar7 + 0x7c5) & 2) == 0)) {
            if ((*(short *)(iVar7 + 0x1064) == DAT_007f1914) &&
               (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) {
              if (*(char *)((int)param_1 + 0x285) == '\x13') {
                iVar9 = iVar7;
              }
            }
            else if ((*(float *)((int)param_1 + 0x17c) <= *(float *)(iVar7 + 0x188)) &&
                    (*(float *)(iVar7 + 0x17c) <= *(float *)((int)param_1 + 0x188))) {
              fVar5 = *(float *)(iVar7 + 0x1dc) * 2.0 + *(float *)((int)param_1 + 0x1dc);
              local_c = *(float *)(iVar7 + 0x80) - *(float *)((int)param_1 + 0x80);
              local_4 = *(float *)(iVar7 + 0x88) - *(float *)((int)param_1 + 0x88);
              if (((local_4 * *(float *)((int)param_1 + 0xf38) +
                    local_c * *(float *)((int)param_1 + 0xf30) <= 0.0) ||
                  (fVar2 = local_4 * local_4 + local_c * local_c, fVar5 * fVar5 <= fVar2)) ||
                 (iVar9 = iVar7, local_20 <= fVar2)) {
                iVar9 = iVar6;
                fVar2 = local_20;
              }
            }
          }
          local_20 = fVar2;
          iVar7 = iVar7 + 0x10d8;
          local_1c = local_1c + -1;
          iVar6 = iVar9;
        } while (local_1c != 0);
        if (iVar9 != 0) {
          if ((param_2 == 0) &&
             ((*(short *)(iVar9 + 0x1064) != DAT_007f1914 ||
              (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234)))) {
            *(byte *)((int)param_1 + 0x7c5) = *(byte *)((int)param_1 + 0x7c5) | 1;
            *(uint *)(iVar9 + 0xe20) = *(uint *)(iVar9 + 0xe20) | 0x80000000;
            return;
          }
          FUN_004874f0(param_1,iVar9);
        }
      }
      return;
    }
    if (cVar3 == ';') {
      if ((DAT_00880564 == 0) || (*(short *)(iVar7 + 0x1064) != DAT_007f1948)) {
        uVar8 = *(uint *)(*(int *)(iVar7 + 0xca4) + 8);
        if ((*(byte *)((int)param_1 + 0xef4) & 2) != 0) {
          uVar8 = uVar8 & ~DAT_00802278;
        }
        if ((*(char *)(iVar7 + 0x7b5) != '*') && ((uVar8 & (DAT_00802284 | DAT_00802278)) != 0)) {
          FUN_004882d0(param_1,1);
          if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) {
            return;
          }
          if (DAT_007f39e4 != 0) {
            FUN_00576960(0x25e);
            return;
          }
          FUN_00576960(5);
          return;
        }
      }
      FUN_00487200();
      *(undefined4 *)((int)param_1 + 0xdd0) = 0x3f800000;
      return;
    }
    if (*(char *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x116) != '\f') {
      return;
    }
    iVar7 = FUN_0062f1a0((int)param_1 + 8);
    if (iVar7 != 3) {
      iVar7 = FUN_0062f1a0((int)param_1 + 8);
      iVar6 = 0xc3;
      if (iVar7 != 0x17) goto LAB_00488b77;
    }
    iVar6 = 0xc4;
LAB_00488b77:
    if (*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 0xcd0) + 0x50) + 0xc) + iVar6 * 4) == 0)
    {
      return;
    }
    *(short *)(*(int *)((int)param_1 + 0xcd0) + 0x7aa) = (short)iVar6;
    return;
  }
  iVar6 = *(int *)((int)param_1 + 0x790);
  if (iVar6 == 0) {
    *(undefined1 *)((int)param_1 + 0x7b5) = 0xff;
    return;
  }
  fVar2 = _DAT_00925018 + *(float *)((int)param_1 + 0x77c);
  *(float *)((int)param_1 + 0x77c) = fVar2;
  if (*(float *)((int)param_1 + 0x784) < fVar2 == (*(float *)((int)param_1 + 0x784) == fVar2)) {
    fVar2 = fVar2 / *(float *)((int)param_1 + 0x784);
    FUN_004871a0(iVar6,&local_c);
    pfVar1 = (float *)((int)param_1 + 0x748);
    *(float *)((int)param_1 + 0x5c) = *pfVar1 + fVar2 * (local_c - *(float *)((int)param_1 + 0x748))
    ;
    *(float *)((int)param_1 + 0x60) =
         (local_8 - *(float *)((int)param_1 + 0x74c)) * fVar2 + *(float *)((int)param_1 + 0x74c);
    *(float *)((int)param_1 + 100) =
         (local_4 - *(float *)((int)param_1 + 0x750)) * fVar2 + *(float *)((int)param_1 + 0x750);
    fVar2 = *(float *)(iVar6 + 0x1e0);
    if (((*(short *)((int)param_1 + 0x7aa) == 6) || (*(short *)((int)param_1 + 0x7aa) == 0xc9)) &&
       (iVar9 = *(int *)(*(int *)((int)param_1 + 0x54) + 0x24), fVar2 < *(float *)(iVar9 + 0x34))) {
      fVar2 = *(float *)(iVar9 + 0x34);
    }
    param_1 = fVar2;
    if ((*(short *)(iVar6 + 0x1064) == DAT_007f1914) &&
       (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234)) {
      fVar10 = (float10)FUN_004c99b0(&local_c,pfVar1);
      param_1 = (float)(fVar10 * (float10)_DAT_007fa568 * (float10)param_1);
    }
    iVar6 = FUN_006e6b90();
    *(float *)(iVar7 + 0x60) =
         (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] * param_1 + *(float *)(iVar7 + 0x60);
    FUN_00550040(*(undefined2 *)(iVar7 + 0x7a6),*(undefined2 *)(*(int *)(iVar7 + 0x790) + 0x27a));
    iVar6 = FUN_006e6b90();
    local_1c._0_2_ =
         (undefined2)
         (int)ROUND((float10)*(ushort *)(iVar7 + 0x7a6) +
                    ((float10)1 -
                    ((float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] + (float10)1) *
                    (float10)0.5) * extraout_ST0);
    *(undefined2 *)(iVar7 + 0x27a) = (undefined2)local_1c;
    *(undefined2 *)(iVar7 + 0x5a) = (undefined2)local_1c;
    *(undefined2 *)(iVar7 + 0x58) = (undefined2)local_1c;
    return;
  }
  *(undefined1 *)((int)param_1 + 0x7b5) = 0xff;
  if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) == 0) goto LAB_0048884b;
  if ((*(short *)(iVar6 + 0x1064) == DAT_007f1974) || (*(short *)(iVar6 + 0x1064) == DAT_007f1978))
  {
    uVar11 = 0x28a;
  }
  else if (*(code **)(*(int *)(iVar6 + 0x54) + 0x18) == FUN_004b3000) {
    if (DAT_007f39e4 == 0) {
LAB_00488813:
      uVar11 = 8;
    }
    else {
      uVar11 = 0x263;
    }
  }
  else {
    if (DAT_007f39e4 == 0) goto LAB_00488813;
    if (*(short *)((int)param_1 + 0x1064) == DAT_007f1914) {
      uVar11 = 0x28d;
    }
    else {
      uVar11 = 0x25d;
    }
  }
  FUN_00576960(uVar11);
LAB_0048884b:
  if ((*(int *)(PTR_DAT_00802c54 + 0x46ec) == 0) ||
     ((sVar4 = *(short *)(*(int *)((int)param_1 + 0x790) + 0x1064), sVar4 != DAT_007f1974 &&
      (sVar4 != DAT_007f1978)))) {
    FUN_00548020(param_1,0,0);
  }
  else {
    FUN_00681f40("env_crane_in",(int)param_1 + 0x80);
  }
  FUN_0054a8a0(**(undefined4 **)((int)param_1 + 0xca4),0x3dcccccd,0);
  FUN_00488660(param_1,*(undefined4 *)((int)param_1 + 0x790),1);
  return;
}

