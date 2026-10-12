/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x416d60; label: FUN_00416d60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00416d60(int param_1)

{
  float fVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  float fVar6;
  float fVar7;
  undefined1 uVar8;
  short sVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined *puVar17;
  int *piVar18;
  float *pfVar19;
  undefined1 *puVar20;
  undefined4 *puVar21;
  uint uVar22;
  undefined4 *puVar23;
  bool bVar24;
  float10 fVar25;
  float local_1e4;
  float local_1e0;
  uint local_1dc;
  int local_1d8;
  float local_1d4;
  int local_1d0;
  uint local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  int local_198;
  uint local_194;
  uint local_190;
  int local_18c;
  float local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c [2];
  undefined4 local_174;
  undefined4 local_170 [2];
  undefined4 local_168;
  int local_164 [25];
  undefined4 auStack_100 [7];
  undefined1 local_e4 [16];
  float local_d4 [52];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1e4;
  local_1c8 = 1.0;
  local_190 = (uint)*(byte *)(param_1 + 0x286);
  local_194 = (uint)*(byte *)(param_1 + 0x287);
  local_198 = *(int *)(param_1 + 0xca4);
  local_18c = FUN_00574e20();
  local_1d0 = (int)*(short *)(param_1 + 0x27e);
  local_1d4 = 0.0;
  local_1ac = -NAN;
  if (*(char *)(param_1 + 0x28b) != '\0') goto LAB_00418c52;
  if ((*(int *)(param_1 + 0xcd0) != 0) && (*(char *)(param_1 + 0x7b5) == ';')) {
    FUN_00488770(param_1,*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802284);
    goto LAB_00418c52;
  }
  iVar14 = *(int *)(param_1 + 0x54);
  local_1cc = DAT_008034c4;
  if (((*(byte *)(iVar14 + 4) & 0x10) == 0) &&
     ((*(uint *)(*(int *)(iVar14 + 0x24) + 0x90) & 0x8000) == 0)) {
    local_1cc = DAT_008034c4 | DAT_0095100c;
  }
  local_1e0 = (float)(*(uint *)(param_1 + 0x1f8) & 0x400);
  if (((local_1e0 != 0.0) && (*(short *)(param_1 + 0x1064) != DAT_007f191c)) &&
     ((*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087afb4 ||
      (*(float *)(*(int *)(iVar14 + 0x24) + 0x28) != 0.0)))) {
    local_1cc = local_1cc | 0x40;
  }
  local_1a8 = *(float *)(param_1 + 0x6c);
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffffff7;
  local_1d8 = 0;
  if (((*(int *)(param_1 + 0x420) != 0) && (iVar15 = *(int *)(param_1 + 0x424), iVar15 != 0)) &&
     (iVar4 = *(int *)(*(int *)(param_1 + 0x420) + 0x7c),
     ((*(byte *)((uint)*(byte *)((*(byte *)(param_1 + 0x428) == 0) + 0x10 + iVar15) * 0x5c + 0x2b +
                iVar4) |
      *(byte *)((uint)*(byte *)(*(byte *)(param_1 + 0x428) + 0x10 + iVar15) * 0x5c + 0x2b + iVar4))
     & 0x82) != 0)) {
    local_1d8 = 1;
  }
  if (param_1 == DAT_00889614) {
    uVar22 = 0;
    local_1dc = 1;
  }
  else if ((*(byte *)(*(int *)(iVar14 + 0x24) + 0x90) & 0x80) == 0) {
    uVar16 = *(uint *)(param_1 + 0x1fc);
    if (((uVar16 & 0x40) == 0) &&
       ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x8000) == 0)) {
      if (local_1e0 == 0.0) {
        uVar11 = *(uint *)(param_1 + 0xef4);
        uVar22 = uVar16 >> 4 & 1;
        if ((uVar11 & 0x40) == 0) {
          local_1dc = uVar16 >> 3 & 1;
        }
        else {
LAB_0041702b:
          local_1dc = 1;
          *(uint *)(param_1 + 0xef4) = uVar11 & 0xffffffbf;
        }
      }
      else if (((((*(int *)(param_1 + 0xe64) == 0) && ((*(ushort *)(param_1 + 0x42e) & 1) != 0)) &&
                (((*(ushort *)(param_1 + 0x42e) & 8) == 0 &&
                 ((((*(char *)(param_1 + 0x7b5) != '\x1c' && (*(int *)(param_1 + 0xeac) == 0)) &&
                   (local_1d8 == 0)) &&
                  ((iVar14 = FUN_004cca90(param_1), iVar14 == 0 &&
                   ((*(uint *)(param_1 + 0x1fc) & 0x40000) == 0)))))))) &&
               ((puVar5 = *(uint **)(param_1 + 0x424), puVar5 == (uint *)0x0 ||
                (((puVar5[2] & DAT_00950d50) == 0 &&
                 ((puVar5 == (uint *)0x0 ||
                  (((*puVar5 & DAT_00950d54) == 0 &&
                   ((puVar5 == (uint *)0x0 || ((*puVar5 & DAT_00950d80) == 0)))))))))))) &&
              ((*(char *)(param_1 + 0x7b5) != 'Z' || (*(char *)(param_1 + 0x7b3) != '\0')))) {
        uVar22 = *(uint *)(param_1 + 0x1fc) >> 4 & 1;
        local_1dc = 1;
      }
      else {
        uVar11 = *(uint *)(param_1 + 0xef4);
        uVar22 = 0;
        if ((uVar11 & 0x40) != 0) goto LAB_0041702b;
        local_1dc = *(uint *)(param_1 + 0x1fc) >> 3 & 1;
      }
    }
    else {
      uVar22 = 0;
      local_1dc = 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x68) = 0;
    uVar22 = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
    local_1dc = 1;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) || (*(float *)(param_1 + 0x1000) <= 1.25)) {
    bVar24 = false;
  }
  else {
    bVar24 = true;
  }
  if ((((((DAT_00951288 == 0) && (*(char *)(param_1 + 0x28b) == '\0')) &&
        ((*(char *)(param_1 + 0x281) != '\0' ||
         (((bVar24 && (*(char *)(param_1 + 0x7b5) == -1)) && (*(char *)(param_1 + 0xe32) != '\x01'))
         )))) && ((*(float *)(param_1 + 0x21c) != 2e+06 &&
                  (_DAT_029927d8 < *(float *)(param_1 + 0xf28))))) &&
      ((bVar24 || ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 0xc) & 1) != 0)
       ))) && (((*(float *)(param_1 + 0x200) == 0.0 && (*(float *)(param_1 + 0x208) == 0.0)) &&
               ((*(float *)(param_1 + 0x68) != 0.0 || (*(float *)(param_1 + 0x70) != 0.0)))))) {
    local_1b8 = *(float *)(param_1 + 0x5c) + _DAT_00925018 * *(float *)(param_1 + 0x68);
    local_1b4 = *(float *)(param_1 + 0x60);
    local_1b0 = _DAT_00925018 * *(float *)(param_1 + 0x70) + *(float *)(param_1 + 100);
    fVar25 = (float10)FUN_005506f0(param_1,&local_1b8,0x40a00000,local_1cc | 0x1f);
    local_1e0 = (float)fVar25;
    if ((local_1e0 != 2e+06) && (_DAT_029927d8 < DAT_0292fdbc)) {
      if (bVar24) {
        fVar1 = *(float *)(param_1 + 0x17c);
      }
      else {
        fVar1 = *(float *)(param_1 + 0x21c);
      }
      if (0.2 < fVar1 - local_1e0) {
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x68) = 0;
      }
    }
  }
  if (((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) || (*(char *)(param_1 + 0x7b5) == '3'))
     || ((*(char *)(param_1 + 0x281) != '\0' &&
         (((cVar2 = *(char *)(param_1 + 0x285), -1 < cVar2 && (cVar2 < ' ')) &&
          (*(float *)(&DAT_008034c8 + cVar2 * 0xc) < 1.0)))))) {
LAB_00417274:
    local_1e0 = 0.0;
  }
  else {
    uVar12 = FUN_0062f1a0(param_1 + 8);
    fVar25 = (float10)FUN_0062f1c0(*(undefined4 *)(param_1 + 0x50),uVar12);
    if (((float10)0 != fVar25) || ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x800) != 0))
    goto LAB_00417274;
    local_1e0 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xc) *
                *(float *)(param_1 + 0xa8);
  }
  pfVar19 = (float *)(param_1 + 0x68);
  local_1e4 = *(float *)(param_1 + 0x6c) * *(float *)(param_1 + 0x6c) +
              *(float *)(param_1 + 0x68) * *(float *)(param_1 + 0x68) +
              *(float *)(param_1 + 0x70) * *(float *)(param_1 + 0x70);
  if ((((((*(byte *)(param_1 + 0xef0) & 0x20) == 0) &&
        ((*(uint *)(param_1 + 0xef4) & 0x400000) != 0)) &&
       ((local_1d8 == 0 &&
        ((((*(int *)(param_1 + 0x44c) == 0 && (-1 < (char)*(uint *)(param_1 + 0x1fc))) &&
          ((*(uint *)(param_1 + 0xe20) & 0x10000000) == 0)) &&
         ((*(char *)(param_1 + 0xe32) == '\0' && (cVar2 = *(char *)(param_1 + 0x7b5), cVar2 != '\0')
          ))))))) && (cVar2 != '\x1c')) &&
     ((((*(char *)(param_1 + 0x285) != '\b' &&
        ((1 < DAT_00925068 || ((*(byte *)(param_1 + 0x1f8) & 5) != 0)))) &&
       ((*(byte *)(param_1 + 0x281) & 3) != 0)) &&
      ((((*(short *)(param_1 + 0x27e) == -1 &&
         (local_1e4 < local_1e0 * local_1e0 != (local_1e4 == local_1e0 * local_1e0))) &&
        (cVar2 != '\x0f')) && ((cVar2 != '\v' && (cVar2 != '\x1e')))))))) {
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 4;
  }
  else {
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xfffffffb;
  }
  local_180 = *(undefined4 *)(param_1 + 0x70);
  local_188 = *pfVar19;
  local_184 = *(undefined4 *)(param_1 + 0x6c);
  uVar16 = *(uint *)(param_1 + 0x1fc);
  *(undefined1 *)(param_1 + 0x1078) = 0;
  if ((((((uVar16 & 0x20) == 0) && ((*(uint *)(param_1 + 0xe20) & 0x20) == 0)) &&
       ((*(int *)(param_1 + 0xe64) == 0 && (*(int *)(param_1 + 0x10b0) == 0)))) &&
      ((cVar2 = *(char *)(param_1 + 0x7b5), cVar2 != '\x0f' ||
       ((*(char *)(param_1 + 0x7b3) != '\x01' && (*(char *)(param_1 + 0x7b3) != '\0')))))) &&
     (((cVar2 != ',' || (*(char *)(param_1 + 0x7b3) != '\0')) &&
      ((cVar2 != 'G' || (*(char *)(param_1 + 0x7b8) != '\x01')))))) {
    if (((uVar22 == 0) && (local_1dc == 0)) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x10) == 0)) {
      if ((uVar16 & 4) == 0) {
        local_1b8 = *(float *)(param_1 + 0x5c);
        local_1b4 = *(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xff0) +
                    *(float *)(param_1 + 0x60);
        local_1b0 = *(float *)(param_1 + 100);
        local_1d4 = (float)((uint)(param_1 - DAT_0093d504) / 0x10d8);
        FUN_005b3830(&local_1c4,pfVar19,_DAT_00925018);
        *(undefined4 *)(param_1 + 0x6c0) = 0;
        if ((((*(char *)(param_1 + 0x1079) != '\0') && (*(char *)(param_1 + 0x281) != '\0')) &&
            ((local_1c4 != 0.0 || (local_1bc != 0.0)))) &&
           ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b29c ||
            (*(short *)(param_1 + 0x1064) != DAT_007f18f4)))) {
          if ((DAT_00951288 == 0) ||
             (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0 ||
              (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) == 0.0)))) {
            if ((*(char *)(param_1 + 0x7b5) != -1) ||
               (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0)) goto LAB_0041758e;
            iVar14 = 1;
          }
          else {
            iVar14 = 2;
          }
          FUN_00572810(param_1 + 0xf24,&local_1c4,&local_1a4,iVar14);
          if (local_1c0 < local_1a0) {
            local_1c4 = local_1a4;
            local_1c0 = local_1a0;
            local_1bc = local_19c;
            if (iVar14 == 1) {
              *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 8;
            }
          }
        }
LAB_0041758e:
        local_1d8 = 0;
        if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x800) == 0) {
          local_1d8 = _DAT_007f2380;
        }
        FUN_0066b310(local_1d8);
        if ((*(byte *)(param_1 + 0x4b0) & 0x80) != 0) {
          DAT_02962b28 = 1;
        }
        FUN_0066b2e0(local_e4,&local_1ac,8);
        if ((*(uint *)(param_1 + 0xef0) & 0x400) != 0) {
          if (*(short *)(param_1 + 0x1064) == DAT_007f1948) {
            if (*(char *)(param_1 + 0x407) == '\x01') {
              local_1c8 = _DAT_007f17b4 /
                          *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x18);
            }
            else if (*(char *)(param_1 + 0x407) == '\x02') {
              local_1c8 = _DAT_007f17b4 /
                          *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x14);
            }
            else {
              local_1c8 = _DAT_007f17b4 /
                          *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
            }
          }
          else {
            local_1c8 = _DAT_007f17b0 / *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c)
            ;
          }
          local_1c4 = local_1c8 * local_1c4;
          local_1bc = local_1c8 * local_1bc;
        }
        sVar9 = *(short *)(param_1 + 0x106e);
        if (sVar9 != -1) {
          local_164[0] = (int)sVar9;
        }
        uVar16 = (uint)(sVar9 != -1);
        if (*(short *)(param_1 + 0x1070) != -1) {
          local_164[uVar16] = (int)*(short *)(param_1 + 0x1070);
          uVar16 = uVar16 + 1;
        }
        cVar2 = *(char *)(param_1 + 0x7b5);
        if ((((cVar2 == '\0') && (*(int *)(param_1 + 0xd1c) != 0)) &&
            (sVar9 = *(short *)(*(int *)(param_1 + 0xd1c) + 0x1070), sVar9 != -1)) ||
           (((cVar2 == 'X' && (*(char *)(param_1 + 0x7b3) == '\x01')) &&
            (sVar9 = *(short *)(*(int *)(param_1 + 0x798) + 0x102), sVar9 != -1)))) {
          local_164[uVar16] = (int)sVar9;
          uVar16 = uVar16 + 1;
        }
        if (((*(int *)(PTR_DAT_00802c54 + 0x2adc) != 0) && (DAT_00951288 == 0)) &&
           ((uVar22 = *(uint *)(param_1 + 0x1fc) >> 7 & 1, uVar22 == 0 ||
            ((((cVar2 == '=' || (*(int *)(param_1 + 0xcd0) != 0)) || (cVar2 == ';')) ||
             ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8040) != 0)))))) {
          iVar14 = *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2adc) + 4);
          if (0 < iVar14) {
            piVar18 = (int *)(*(int *)(PTR_DAT_00802c54 + 0x2adc) + 0x18);
            do {
              if ((*piVar18 != 0) &&
                 (((*(uint *)(param_1 + 0xef4) & 0x80000) == 0 || (uVar22 != 0)))) {
                local_164[uVar16] = (int)*(short *)(*piVar18 + 0x1070);
                uVar16 = uVar16 + 1;
              }
              piVar18 = piVar18 + 5;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
        }
        iVar14 = 0;
        if (0 < (int)uVar16) {
          do {
            FUN_0067c8e0(local_164[iVar14],0);
            iVar14 = iVar14 + 1;
          } while (iVar14 < (int)uVar16);
        }
        uVar22 = local_1cc;
        if (*(float *)(local_198 + 0x28) <= 0.0) {
          local_1e4 = _DAT_00925018 * local_1e0;
        }
        else {
          local_1e4 = 0.0;
        }
        iVar14 = 0;
        FUN_0068f940(&local_1b8,&local_1c4,param_1 + 0x1050,local_1d4,local_1e4,
                     *(undefined4 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0x1004),0,0,local_1cc
                    );
        local_1d4 = 1.4013e-45;
        DAT_02962b28 = 0;
        if (0 < (int)uVar16) {
          do {
            FUN_0067c8e0(local_164[iVar14],1);
            iVar14 = iVar14 + 1;
          } while (iVar14 < (int)uVar16);
        }
        if ((*(uint *)(param_1 + 0xef0) & 0x400) != 0) {
          local_1c4 = local_1c4 / local_1c8;
          local_1bc = local_1bc / local_1c8;
        }
        uVar10 = FUN_0067a6e0();
        *(undefined2 *)(param_1 + 0x27e) = uVar10;
        bVar24 = DAT_0292125c == '\0';
        *(char *)(param_1 + 0x1078) = DAT_0292125c;
        if ((bVar24) || ((int)local_1ac < 1)) {
          *(undefined1 *)(param_1 + 0x1078) = 0;
        }
        else {
          puVar21 = auStack_100 + (int)local_1ac * 7;
          puVar23 = (undefined4 *)(param_1 + 0x6a8);
          for (iVar14 = 7; iVar14 != 0; iVar14 = iVar14 + -1) {
            *puVar23 = *puVar21;
            puVar21 = puVar21 + 1;
            puVar23 = puVar23 + 1;
          }
          fVar25 = (float10)FUN_005b39e0(param_1 + 0x6b4,&local_188);
          *(float *)(param_1 + 0x1030) = (float)-fVar25;
        }
        local_1e4 = 1.0 / _DAT_00925018;
        FUN_005b3830(param_1 + 0x68,&local_1c4,local_1e4);
        *(float *)(param_1 + 0x5c) = local_1b8;
        *(float *)(param_1 + 0x60) =
             local_1b4 - *(float *)(param_1 + 0xa8) * *(float *)(param_1 + 0xff0);
        *(float *)(param_1 + 100) = local_1b0;
        if (*(char *)(param_1 + 0x28b) == '\0') {
          if (*(short *)(param_1 + 0x27e) != -1) {
            local_1e0 = 0.0;
            local_1d8 = 0;
            FUN_0067fb50((int)*(short *)(param_1 + 0x27e),&local_1e0,&local_1d8);
            if ((local_1e0 != 0.0) && (local_1d8 != 0)) {
              local_1a4 = 0.0;
              local_1a0 = 0.0;
              local_19c = 1.0;
              FUN_005b3200(local_17c,&local_1a4,local_1e0);
              uVar12 = FUN_005be2d0(local_17c[0],local_174);
              FUN_005b3200(local_170,&local_1a4,local_1d8);
              uVar13 = FUN_005be2d0(local_170[0],local_168);
              iVar14 = FUN_005be5b0(uVar13,uVar12);
              if (iVar14 != 0) {
                uVar10 = FUN_005be590(iVar14,*(undefined2 *)(param_1 + 0x27a));
                *(undefined2 *)(param_1 + 0x27a) = uVar10;
                uVar10 = FUN_005be590(iVar14,*(undefined2 *)(param_1 + 0x58));
                *(undefined2 *)(param_1 + 0x58) = uVar10;
                uVar10 = FUN_005be590(iVar14,*(undefined2 *)(param_1 + 0x5a));
                *(undefined2 *)(param_1 + 0x5a) = uVar10;
              }
            }
          }
          if (*(char *)(param_1 + 0x28b) == '\0') {
            if ((((*(char *)(param_1 + 0x1078) != '\0') && ((*(uint *)(param_1 + 0x1fc) & 4) == 0))
                && (cVar2 = *(char *)(param_1 + 0x7b5), cVar2 != '\0')) &&
               (((-1 < (char)*(uint *)(param_1 + 0x1fc) && (cVar2 != 'C')) &&
                ((cVar2 != 'E' &&
                 (((*(byte *)(param_1 + 0xef6) & 1) == 0 && (iVar14 = 0, 0 < (int)local_1ac))))))))
            {
              pfVar19 = local_d4;
              do {
                if (*pfVar19 < 0.707) {
                  *(float *)(param_1 + 0x1d8) = _DAT_00925018 + *(float *)(param_1 + 0x1d8);
                  goto LAB_00417aca;
                }
                iVar14 = iVar14 + 1;
                pfVar19 = pfVar19 + 7;
              } while (iVar14 < (int)local_1ac);
            }
            local_1e4 = *(float *)(param_1 + 0x1d8) - _DAT_00925018 * 0.333;
            *(float *)(param_1 + 0x1d8) = local_1e4;
            if (local_1e4 < 0.0) {
              *(undefined4 *)(param_1 + 0x1d8) = 0;
            }
          }
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x70) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        *pfVar19 = 0.0;
        uVar22 = local_1cc;
      }
LAB_00417aca:
      if ((*(byte *)(param_1 + 0x1fc) & 4) == 0) {
        fVar25 = (float10)FUN_005506f0(param_1,param_1 + 0x5c,0x40a00000,uVar22 | 0x1f);
        local_1e0 = (float)fVar25;
      }
      else {
        local_1e0 = *(float *)(param_1 + 0x21c);
      }
      if (local_1e0 == 2e+06) {
        *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffffffd;
        if (DAT_0087b50c == 0) goto LAB_00417bd5;
        *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x8c);
        *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x94);
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x70) = 0;
      }
      else {
        *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 2;
        if (local_1d4 != 0.0) {
          local_1e4 = *(float *)(param_1 + 0xff4) * *(float *)(param_1 + 0xa8) +
                      *(float *)(param_1 + 0x60);
          fVar7 = *(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8);
          local_1d4 = *(float *)(param_1 + 0x60) + fVar7;
          fVar1 = local_1e4 - local_1d4;
          if ((fVar1 * 0.1 + local_1d4 < local_1e0) &&
             (fVar6 = (fVar1 + local_1e0) - local_1e4, local_1e4 = fVar1, fVar6 <= fVar1 + 0.01)) {
            *(float *)(param_1 + 0x60) = local_1e0 - fVar7;
          }
        }
LAB_00417bd5:
        if ((*(byte *)(param_1 + 0x1fc) & 4) == 0) {
          *(undefined4 *)(param_1 + 0x21c) = 0x49f42400;
          if (local_1e0 != 2e+06) {
            *(float *)(param_1 + 0x21c) = local_1e0;
          }
          FUN_00572440(param_1,local_1e0 != 2e+06,local_1e0);
          if (((*(short *)(param_1 + 0x27e) == -1) && (*(char *)(param_1 + 0x281) != '\0')) &&
             (*(short *)(param_1 + 0x106c) != -1)) {
            *(short *)(param_1 + 0x27e) = *(short *)(param_1 + 0x106c);
          }
          if ((((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0) &&
              (*(float *)(param_1 + 0x1014) == 2e+06)) && (*(short *)(param_1 + 0x106c) != -1)) {
            fVar25 = (float10)FUN_00553500(param_1 + 0x5c);
            local_1e4 = (float)fVar25;
            if (local_1e4 != 2e+06) {
              *(float *)(param_1 + 0x1014) = local_1e4;
              *(undefined1 *)(param_1 + 0x107b) = 2;
            }
          }
        }
      }
      *(undefined1 *)(param_1 + 0x281) = 0;
      if (*(short *)(param_1 + 0x1050) != 0) {
        *(undefined1 *)(param_1 + 0x281) = 1;
      }
      iVar14 = FUN_0055d130(param_1,0x3f800000,0);
      if (iVar14 != 0) {
        *(byte *)(param_1 + 0x281) = *(byte *)(param_1 + 0x281) | 2;
      }
      if (*(char *)(param_1 + 0x281) != '\0') {
        *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) | 0x2000000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      if ((uVar16 & 4) == 0) {
        *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 2;
        *(float *)(param_1 + 0x5c) =
             *(float *)(param_1 + 0x68) * _DAT_00925018 + *(float *)(param_1 + 0x5c);
        *(float *)(param_1 + 0x60) =
             *(float *)(param_1 + 0x6c) * _DAT_00925018 + *(float *)(param_1 + 0x60);
        fVar1 = *(float *)(param_1 + 0x70) * _DAT_00925018;
        *(undefined2 *)(param_1 + 0x27e) = 0xffff;
        *(float *)(param_1 + 100) = fVar1 + *(float *)(param_1 + 100);
        if (local_1dc != 0) {
          if (param_1 == DAT_00889614) {
            FUN_0067a6d0();
          }
          if (DAT_007f2394 == 0) {
            pfVar19 = (float *)(param_1 + 0x80);
          }
          else {
            local_1b8 = *(float *)(param_1 + 0x80);
            local_1b0 = *(float *)(param_1 + 0x88);
            if (*(float *)(param_1 + 0x9c) <= *(float *)(param_1 + 0x84)) {
              local_1b4 = *(float *)(param_1 + 0x84);
            }
            else {
              local_1b4 = *(float *)(param_1 + 0x9c);
            }
            pfVar19 = &local_1b8;
          }
          fVar25 = (float10)FUN_005506f0(param_1,pfVar19,0x40a00000,local_1cc | 0x1f);
          *(float *)(param_1 + 0x21c) = (float)fVar25;
          uVar10 = FUN_0067a6e0();
          *(undefined2 *)(param_1 + 0x27e) = uVar10;
          if (*(float *)(param_1 + 0x21c) == 2e+06) {
            FUN_00572440(param_1,0,*(undefined4 *)(param_1 + 0x21c));
            FUN_00416c30();
          }
          else {
            FUN_00572440(param_1,1,*(undefined4 *)(param_1 + 0x21c));
          }
          uVar8 = FUN_00572790(param_1);
          *(undefined1 *)(param_1 + 0x286) = uVar8;
          uVar8 = FUN_005727c0(param_1);
          *(undefined1 *)(param_1 + 0x287) = uVar8;
          if (((*(short *)(param_1 + 0x27e) == -1) && (*(char *)(param_1 + 0x281) != '\0')) &&
             (*(short *)(param_1 + 0x106c) != -1)) {
            *(short *)(param_1 + 0x27e) = *(short *)(param_1 + 0x106c);
          }
        }
        local_1e4 = *(float *)(param_1 + 0xff0) * *(float *)(param_1 + 0xa8);
        if ((*(float *)(param_1 + 0x21c) != 2e+06) &&
           (local_1e4 + *(float *)(param_1 + 0x60) < *(float *)(param_1 + 0x21c))) {
          *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x21c) - local_1e4;
          *(undefined4 *)(param_1 + 0x6c) = 0;
        }
        *(undefined1 *)(param_1 + 0x281) = 0;
        iVar14 = FUN_0055d130(param_1,0x3f800000,0);
        if (iVar14 != 0) {
          *(byte *)(param_1 + 0x281) = *(byte *)(param_1 + 0x281) | 2;
        }
        if (*(float *)(param_1 + 0x17c) <= *(float *)(param_1 + 0x21c)) {
          *(byte *)(param_1 + 0x281) = *(byte *)(param_1 + 0x281) | 1;
        }
        if ((*(byte *)(param_1 + 0x281) & 1) == 0) goto LAB_00417fdb;
        *(undefined4 *)(param_1 + 0x6a8) = *(undefined4 *)(param_1 + 0x5c);
        *(undefined1 *)(param_1 + 0x1078) = 1;
        *(undefined4 *)(param_1 + 0x6ac) = *(undefined4 *)(param_1 + 0x21c);
        *(undefined1 *)(param_1 + 0x6c0) = *(undefined1 *)(param_1 + 0x285);
        *(undefined4 *)(param_1 + 0x6b0) = *(undefined4 *)(param_1 + 100);
        if (local_1dc == 0) {
          *(undefined4 *)(param_1 + 0x6b4) = DAT_00802500;
          *(undefined4 *)(param_1 + 0x6b8) = DAT_00802504;
          uVar12 = DAT_00802508;
        }
        else {
          *(undefined4 *)(param_1 + 0x6b4) = *(undefined4 *)(param_1 + 0xf24);
          *(undefined4 *)(param_1 + 0x6b8) = *(undefined4 *)(param_1 + 0xf28);
          uVar12 = *(undefined4 *)(param_1 + 0xf2c);
        }
        *(undefined4 *)(param_1 + 0x6bc) = uVar12;
        *(float *)(param_1 + 0x1030) = -*(float *)(param_1 + 0x6c);
      }
    }
  }
  else {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 2;
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(float *)(param_1 + 0x5c) = *pfVar19 * _DAT_00925018 + *(float *)(param_1 + 0x5c);
    *(float *)(param_1 + 0x60) =
         *(float *)(param_1 + 0x6c) * _DAT_00925018 + *(float *)(param_1 + 0x60);
    fVar1 = *(float *)(param_1 + 0x70) * _DAT_00925018;
    *(undefined1 *)(param_1 + 0x281) = 0;
    *(undefined2 *)(param_1 + 0x27e) = 0xffff;
    *(float *)(param_1 + 100) = fVar1 + *(float *)(param_1 + 100);
LAB_00417fdb:
    *(undefined1 *)(param_1 + 0x6c0) = 0;
  }
  iVar14 = local_1d0;
  if (*(char *)(param_1 + 0x281) == '\0') {
LAB_004180a6:
    if (((iVar14 != -1) && (*(short *)(param_1 + 0x27e) == -1)) &&
       (*(short *)(param_1 + 0x106c) == iVar14)) {
      if ((*(int *)(PTR_DAT_00802c54 + 0x46ec) == 0) ||
         (iVar15 = *(int *)(PTR_DAT_00802c54 + 0x46ec), *(short *)(iVar15 + 0x560) != iVar14)) {
        iVar14 = FUN_0058bbf0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2adc),iVar14);
        if ((iVar14 != 0) && (0.0 < *(float *)(*(int *)(*(int *)(iVar14 + 0x54) + 0x24) + 0x28))) {
          *(float *)(iVar14 + 0x6c) = *(float *)(iVar14 + 0x6c) - local_1a8 * 0.5;
        }
      }
      else if (*(float *)(iVar15 + 0x554) <= 0.0) {
        *(undefined4 *)(iVar15 + 0x554) = 0x3e800000;
      }
    }
  }
  else {
    if (((local_1d0 == -1) && (sVar9 = *(short *)(param_1 + 0x27e), sVar9 != -1)) &&
       ((*(short *)(param_1 + 0x106c) == sVar9 && (local_1a8 < 0.0)))) {
      if ((*(int *)(PTR_DAT_00802c54 + 0x46ec) == 0) ||
         (iVar15 = *(int *)(PTR_DAT_00802c54 + 0x46ec), *(short *)(iVar15 + 0x560) != sVar9)) {
        iVar15 = FUN_0058bbf0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2adc),(int)sVar9);
        if ((iVar15 != 0) && (0.0 < *(float *)(*(int *)(*(int *)(iVar15 + 0x54) + 0x24) + 0x28))) {
          *(float *)(iVar15 + 0x6c) = local_1a8 * 0.5 + *(float *)(iVar15 + 0x6c);
        }
      }
      else if (*(float *)(iVar15 + 0x554) <= 0.0) {
        *(undefined4 *)(iVar15 + 0x554) = 0x3e800000;
      }
    }
    if (*(char *)(param_1 + 0x281) == '\0') goto LAB_004180a6;
  }
  if (((DAT_00951288 == 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) &&
     ((*(short *)(param_1 + 0x27e) != -1 &&
      ((((iVar14 = FUN_0058bbf0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2adc),
                                (int)*(short *)(param_1 + 0x27e)), iVar14 != 0 &&
         (iVar15 = *(int *)(*(int *)(iVar14 + 0x54) + 0x24),
         (*(uint *)(iVar15 + 0x90) & 0x1000) != 0)) &&
        (*(float *)(param_1 + 0x60) < *(float *)(iVar14 + 0x60))) &&
       (*(float *)(iVar15 + 0x1c) * 0.5 < *(float *)(iVar14 + 0x22c))))))) {
    FUN_0049bc30(iVar14,param_1);
  }
  if (*(char *)(param_1 + 0x28b) == '\0') {
    if (*(char *)(param_1 + 0x7b5) == '+') {
      if (*(char *)(param_1 + 0x281) == '\0') {
        if (*(char *)(param_1 + 0x288) != '\0') {
          fVar1 = *(float *)(param_1 + 0xd98);
          if ((NAN(fVar1) || 5.0 < fVar1 == (fVar1 == 5.0)) &&
             ((*(char *)(param_1 + 0xe37) != '\x03' || (*(char *)(param_1 + 0x1078) == '\0'))))
          goto LAB_00418aab;
          goto LAB_00418254;
        }
      }
      else {
LAB_00418254:
        if (*(char *)(param_1 + 0x288) != '\0') {
          FUN_004381e0(param_1,0,0);
        }
      }
      FUN_00437390(param_1,3,1,0);
      if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b14c) &&
         (*(char *)(param_1 + 0xe37) == '\x03')) {
        _DAT_0087a830 = 0x3dcccccd;
      }
    }
    else if (((*(byte *)(param_1 + 0x1fc) & 4) == 0) && (DAT_00951388 == 0)) {
      if (local_1ac == -NAN) {
        puVar20 = (undefined1 *)(param_1 + 0x6a8);
        local_1d4 = 1.4013e-45;
      }
      else {
        puVar20 = local_e4;
        local_1d4 = local_1ac;
      }
      fVar1 = local_1d4;
      iVar14 = FUN_0058b7f0(param_1);
      if ((((iVar14 == 0) && (*(char *)(param_1 + 0x28b) == '\0')) &&
          ((DAT_00951288 == 0 || ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)))) &&
         ((((*(uint *)(param_1 + 0xef0) & 0x40000) != 0 &&
           ((*(uint *)(param_1 + 0xeec) & 0x40000) == 0)) && (*(char *)(param_1 + 0x7b5) != ']'))))
      {
        if (*(char *)(param_1 + 0x1078) == '\0') {
          if (((*(char *)(param_1 + 0x281) != '\0') &&
              ((*(int *)(PTR_DAT_00802c54 + 300) == 0 ||
               (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)))) &&
             (*(byte *)(param_1 + 0x285) < 0x20)) {
            FUN_00416c90();
          }
        }
        else {
          local_1d0 = 0;
          if (0 < (int)fVar1) {
            puVar20 = puVar20 + 0xc;
            puVar17 = PTR_DAT_00802c54;
            do {
              cVar2 = puVar20[0xc];
              if ((uint)(int)cVar2 < 0x20) {
                if ((*(int *)(puVar17 + 0x128) == DAT_0087b0dc) ||
                   (((DAT_0087b014 != 0 && (*(int *)(puVar17 + 300) == DAT_0087b014)) &&
                    (1.0 < _DAT_0092505c != (_DAT_0092505c == 1.0))))) {
                  iVar14 = FUN_0054fa60(0);
                  local_1e4 = (float)iVar14 * 1.5259022e-05 * 0.5;
                  FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),local_1e4);
                  puVar17 = PTR_DAT_00802c54;
                  if ((*(char *)(param_1 + 0x288) == '\0') && (*(char *)(param_1 + 0x7b5) != '#')) {
                    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
                      FUN_0046c6e0(param_1,2);
                    }
                    FUN_00437390(param_1,2,1,0);
                    break;
                  }
                }
                else if ((((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0) ||
                         ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x4000000)
                          != 0)) && (*(char *)(param_1 + 0x283) == '\x06')) break;
                if (((*(int *)(puVar17 + 300) == 0) || (*(int *)(puVar17 + 300) != DAT_0087af5c)) &&
                   (iVar14 = FUN_00416c90(), puVar17 = PTR_DAT_00802c54, iVar14 != 0)) {
                  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b20c) {
                    FUN_0054a3e0(PTR_DAT_008021b4,0x3f800000,0,1);
                  }
                  break;
                }
                if ((((&DAT_008034cc)[cVar2 * 0xc] & 0x80) != 0) &&
                   (*(int *)(puVar17 + 0x128) != DAT_0087b0dc)) {
                  FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f19999a,0);
                  FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3dcccccd,0);
                  if ((*(float *)(param_1 + 0xd30) != 1.0) &&
                     (iVar14 = FUN_0058b7f0(param_1), iVar14 == 0)) {
                    FUN_00438230(0,param_1,1,0,0,1);
                  }
                  break;
                }
              }
              local_1d0 = local_1d0 + 1;
              puVar20 = puVar20 + 0x1c;
            } while (local_1d0 < (int)local_1d4);
          }
        }
      }
      iVar14 = FUN_0058b7f0(param_1);
      if (((((iVar14 == 0) && ((*(uint *)(param_1 + 0xeec) & 0x40000) == 0)) &&
           (*(char *)(param_1 + 0x28b) == '\0')) && (*(float *)(param_1 + 0x220) != 2e+06)) &&
         (((cVar2 = *(char *)(param_1 + 0x283), cVar2 == '\x03' ||
           ((((cVar2 == '\t' && (*(short *)(param_1 + 0x1064) == DAT_007f1a80)) &&
             ((*(int *)(PTR_DAT_00802c54 + 300) != 0 &&
              (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afc0)))) ||
            ((((&DAT_0080364c)[cVar2 * 0xc] & 0x20) != 0 ||
             (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0 &&
              ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x4000000) == 0)))))))
           ) && ((iVar14 = FUN_0058b840(param_1), iVar14 == 0 &&
                 (cVar2 = *(char *)(param_1 + 0x7b5), cVar2 != ']')))))) {
        cVar3 = *(char *)(param_1 + 0x283);
        if (((((*(uint *)(&DAT_0080364c + cVar3 * 0xc) & 1) != 0) ||
             ((((cVar3 == '\t' && (*(short *)(param_1 + 0x1064) == DAT_007f1a80)) &&
               (*(int *)(PTR_DAT_00802c54 + 300) != 0)) &&
              (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afc0)))) &&
            (((*(float *)(param_1 + 0x60) < *(float *)(param_1 + 0x220) &&
              (((DAT_00951288 == 0 || (DAT_00951154 == 0)) ||
               (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) <= 0.0)))) &&
             ((uVar16 = *(uint *)(param_1 + 0x1fc) >> 7 & 1, uVar16 != 0 ||
              ((cVar2 != 'G' && (cVar2 != 'F')))))))) ||
           (((*(uint *)(&DAT_0080364c + cVar3 * 0xc) & 0x20) != 0 &&
            ((*(float *)(param_1 + 0x220) < *(float *)(param_1 + 0x188) &&
             ((uVar16 = *(uint *)(param_1 + 0x1fc) >> 7 & 1, uVar16 != 0 ||
              ((cVar2 != 'G' && (cVar2 != 'F')))))))))) {
          if ((*(int *)(param_1 + 0xf14) == 0) || (uVar16 != 0)) {
            bVar24 = false;
            if ((((DAT_007f39e4 == 0) && (DAT_00876580 == 0)) && (cVar3 == '\x06')) &&
               ((cVar2 = *(char *)(param_1 + 0x285), -1 < cVar2 && (cVar2 < ' ')))) {
              if (((&DAT_008034cc)[cVar2 * 0xc] & 1) == 0) {
                if (*(float *)(param_1 + 0x1018) <= 0.0) {
                  FUN_00438230(0,param_1,1,0,0,1);
                }
                goto LAB_00418a8c;
              }
              bVar24 = true;
            }
            FUN_00434280(param_1);
            FUN_0055e4a0(param_1,1);
            *(undefined2 *)(param_1 + 0x7aa) = 5;
            if ((*(char *)(param_1 + 0x7b5) != -1) &&
               (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x42) * 4)
                != 0)) {
              *(short *)(param_1 + 0x7aa) = *(short *)(param_1 + 0x42);
            }
            *(undefined1 *)(param_1 + 0x7b5) = 0x2b;
            *(undefined1 *)(param_1 + 0xe32) = 0;
            if (((&DAT_0080364c)[*(char *)(param_1 + 0x283) * 0xc] & 0x20) == 0) {
              if ((bVar24) || (*(char *)(param_1 + 0x283) == '\x06')) {
                *(undefined4 *)(param_1 + 0x6c) = 0xbe800000;
                *(undefined1 *)(param_1 + 0xe37) = 2;
                uVar12 = **(undefined4 **)(param_1 + 0xca4);
              }
              else {
                if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b160) {
                  *(undefined1 *)(param_1 + 0xe37) = 1;
                  goto LAB_004189aa;
                }
                *(undefined4 *)(param_1 + 0x6c) = 0xbf000000;
                *(undefined1 *)(param_1 + 0xe37) = 4;
                uVar12 = **(undefined4 **)(param_1 + 0xca4);
              }
              FUN_0054a8a0(uVar12,0x3dcccccd,0);
            }
            else {
              *(undefined1 *)(param_1 + 0xe37) = 3;
            }
LAB_004189aa:
            *(undefined4 *)(param_1 + 0xd98) = 0;
            FUN_00548460(param_1);
            *(undefined1 *)(param_1 + 0x107f) = 0;
            if (((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
                 (*(int **)(param_1 + 0x7fc) != (int *)0x0)) && (**(int **)(param_1 + 0x7fc) != 0))
               && (DAT_007f3b14 == -1)) {
              iVar14 = FUN_0046c6e0(param_1,2);
              if (0 < iVar14) {
                if ((*(float *)(param_1 + 0x220) == 2e+06) ||
                   (((&DAT_0080364c)[*(char *)(param_1 + 0x283) * 0xc] & 1) == 0)) {
                  local_1d0 = 0x49f42400;
                }
                else {
                  local_1d0 = *(int *)(param_1 + 0x220);
                }
                FUN_0046d270(iVar14,0,0,0,param_1 + 0x80,0,0x40000000,
                             (int)*(char *)(param_1 + 0x280),0x3f800000,local_1d0,0,1,0);
              }
              *(undefined4 *)(*(int *)(param_1 + 0x7fc) + 4) = 0x3fc00000;
            }
          }
          else {
            if ((*(uint *)(param_1 + 0xef0) & 0x800) != 0) {
              FUN_00438230(0,param_1,1,0,0,1);
            }
            if (*(char *)(param_1 + 0x28b) == '\0') {
              FUN_00561e20(param_1,*(int *)(param_1 + 0xf14) + 0x10,0,0x3f800000,0x3f800000,0);
            }
          }
        }
        else if ((((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x40) == 0) &&
                 (*(short *)(param_1 + 0x1064) != DAT_007f18bc)) &&
                ((cVar3 == '\t' && (*(float *)(param_1 + 0x188) < *(float *)(param_1 + 0x220))))) {
          if ((DAT_007f3b14 == -1) && (iVar14 = FUN_0046c6e0(param_1,2), 0 < iVar14)) {
            FUN_0046d270(iVar14,0,0,0,param_1 + 400,0,0x40000000,(int)*(char *)(param_1 + 0x280),
                         0x3f800000,0x49f42400,0,1,0);
          }
          FUN_004381e0(param_1,1,0x40000000);
          FUN_00437390(param_1,3,1,0);
        }
      }
LAB_00418a8c:
      uVar8 = FUN_00572790(param_1);
      *(undefined1 *)(param_1 + 0x286) = uVar8;
      uVar8 = FUN_005727c0(param_1);
      *(undefined1 *)(param_1 + 0x287) = uVar8;
    }
LAB_00418aab:
    if ((((*(char *)(param_1 + 0x287) != '\0') && (local_194 == 0)) && (local_190 == 0)) &&
       (((((cVar2 = *(char *)(param_1 + 0x7b5), cVar2 == '\0' || (cVar2 == '\x1f')) ||
          (((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 4) != 0 ||
           ((cVar2 == '\x0e' || (cVar2 == '\r')))))) ||
         (iVar14 = FUN_0062f1a0(param_1 + 8), iVar14 == 5)) ||
        (((iVar14 == 0x28 || (iVar14 == 0x4b)) || (iVar14 == 0x4c)))))) {
      FUN_0042f950(param_1,param_1 + 0x80);
    }
    if (((*(char *)(param_1 + 0x288) != '\0') && (*(char *)(param_1 + 0x7b5) != ',')) &&
       (*(char *)(param_1 + 0x7b5) != '@')) {
      FUN_00431740(param_1,2);
    }
    iVar14 = *(int *)(param_1 + 0xca4);
    uVar12 = *(undefined4 *)(iVar14 + 4);
    uVar13 = *(undefined4 *)(iVar14 + 8);
    if ((((char)*(uint *)(param_1 + 0x1fc) < '\0') && ((*(uint *)(param_1 + 0x1fc) & 0x100) == 0))
       && ((local_18c != -1 || (DAT_00855de0 == 2)))) {
      *(undefined4 *)(iVar14 + 4) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0xca4) + 8) = 0;
    }
    FUN_00487dc0(param_1);
    FUN_00498a40(param_1);
    (**(code **)(*(int *)(param_1 + 0x54) + 0x18))(param_1);
    FUN_004b6b80(param_1);
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x200000) == 0) {
      FUN_00563ec0(param_1);
    }
    *(undefined4 *)(*(int *)(param_1 + 0xca4) + 4) = uVar12;
    *(undefined4 *)(*(int *)(param_1 + 0xca4) + 8) = uVar13;
  }
  else {
    if (*(char *)(param_1 + 0x281) != '\0') {
      *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 4;
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
    if ((*(byte *)(param_1 + 0x1fc) & 4) == 0) {
      FUN_004abac0(param_1,0,0,0,0);
    }
  }
  if (((((*(uint *)(param_1 + 0xeec) & 0x40000) == 0) && (DAT_0292fc68 != 0)) &&
      (*(char *)(param_1 + 0x28b) == '\0')) &&
     (((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0xe0) == 0 &&
      (*(float *)(param_1 + 0x60) < (float)*(int *)(DAT_0292fc68 + 0x1bac) - 5.0)))) {
    if (*(char *)(param_1 + 0x288) == '\0') {
      FUN_00437390(param_1,3,1,0);
    }
    else {
      FUN_004381e0(param_1,0,0);
      FUN_00437390(param_1,3,1,0);
    }
  }
LAB_00418c52:
  *(ushort *)(local_198 + 0x5a) = *(ushort *)(local_198 + 0x5a) & 0xffe9;
  *(undefined4 *)(param_1 + 0xd20) = 0;
  *(undefined4 *)(local_198 + 0x54) = 0;
  FUN_005b3710(param_1 + 0xf30,0x3f800000,*(undefined2 *)(param_1 + 0x27a));
  __security_check_cookie(local_4 ^ (uint)&local_1e4);
  return;
}

