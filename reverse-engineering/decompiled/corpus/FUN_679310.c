/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x679310; label: FUN_00679310
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00679310(undefined4 param_1)

{
  float *pfVar1;
  short *psVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  short *psVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  float10 fVar16;
  float local_44;
  int local_40;
  int local_3c;
  float *local_38;
  int local_34;
  short *local_30;
  float *local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  fVar10 = DAT_0292186c;
  local_1c = (int)*(short *)(*DAT_0292fc68 + 0x30 + *(short *)((int)DAT_0292186c + 0x6c) * 0x38);
  iVar14 = local_1c * 0x6c;
  local_40 = 0;
  if (*(int *)(DAT_0292fc68[0x1a] + iVar14 + 0x40) == 0) {
    return 1;
  }
  if (((*(float *)(*(int *)(DAT_0292fc68[0x1a] + iVar14 + 0x40) + 0x30) ==
        *(float *)(DAT_0292fc68[0x1a] + 0x30 + iVar14)) &&
      (*(float *)(*(int *)(DAT_0292fc68[0x1a] + iVar14 + 0x40) + 0x34) ==
       *(float *)(DAT_0292fc68[0x1a] + 0x34 + iVar14))) &&
     (*(float *)(*(int *)(DAT_0292fc68[0x1a] + iVar14 + 0x40) + 0x38) ==
      *(float *)(DAT_0292fc68[0x1a] + 0x38 + iVar14))) {
    if ((*(byte *)(DAT_0292fc68[0x1a] + iVar14 + 0x4c) & 1) == 0) {
      return 1;
    }
    iVar11 = DAT_0292fc68[0x1a];
    if (((((**(float **)(iVar14 + iVar11 + 0x40) == *(float *)(iVar14 + iVar11)) &&
          (*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 4) == *(float *)(iVar14 + 4 + iVar11))) &&
         ((*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 8) == *(float *)(iVar14 + 8 + iVar11) &&
          ((*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 0x10) ==
            *(float *)(iVar14 + 0x10 + iVar11) &&
           (*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 0x14) ==
            *(float *)(iVar14 + 0x14 + iVar11))))))) &&
        (*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 0x18) == *(float *)(iVar14 + 0x18 + iVar11)))
       && (((*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 0x20) ==
             *(float *)(iVar14 + 0x20 + iVar11) &&
            (*(float *)(*(int *)(iVar14 + iVar11 + 0x40) + 0x24) ==
             *(float *)(iVar14 + 0x24 + iVar11))) &&
           (*(float *)(*(int *)(iVar14 + 0x40 + iVar11) + 0x28) ==
            *(float *)(iVar14 + 0x28 + iVar11))))) {
      return 1;
    }
  }
  local_28 = DAT_0292186c;
  local_24 = DAT_0292fc64;
  DAT_0292fc64 = 0;
  DAT_02924b34 = DAT_02962b34;
  DAT_0292186c = (float)FUN_006de8d0(0x948);
  local_20 = DAT_0292186c;
  iVar8 = FUN_006de8d0(0xd0);
  iVar11 = (int)DAT_0292186c;
  *(undefined4 *)((int)DAT_0292186c + 0x50) = *(undefined4 *)((int)fVar10 + 0x50);
  *(undefined4 *)(iVar11 + 0x5c) = *(undefined4 *)((int)fVar10 + 0x5c);
  pfVar13 = (float *)(iVar8 + 0x1fU & 0xfffffff0);
  *(undefined4 *)(iVar11 + 0x68) = *(undefined4 *)((int)fVar10 + 0x68);
  *(undefined4 *)(iVar11 + 0x58) = *(undefined4 *)((int)fVar10 + 0x58);
  *(undefined4 *)(iVar11 + 0xa0) = *(undefined4 *)((int)fVar10 + 0xa0);
  *(undefined4 *)(iVar11 + 100) = *(undefined4 *)((int)fVar10 + 100);
  *(undefined4 *)(iVar11 + 0xa4) = *(undefined4 *)((int)fVar10 + 0xa4);
  *(undefined4 *)(iVar11 + 0x54) = *(undefined4 *)((int)fVar10 + 0x54);
  *(undefined4 *)(iVar11 + 0x60) = *(undefined4 *)((int)fVar10 + 0x60);
  *(undefined2 *)(iVar11 + 0x36) = *(undefined2 *)((int)fVar10 + 0x36);
  *(undefined4 *)(iVar11 + 0x40) = *(undefined4 *)((int)fVar10 + 0x40);
  *(undefined1 *)(iVar11 + 0x34) = *(undefined1 *)((int)fVar10 + 0x34);
  *(undefined4 *)(iVar11 + 0x38) = *(undefined4 *)((int)fVar10 + 0x38);
  *(float *)(iVar11 + 0x28) =
       (*(float *)(DAT_0292fc68[0x1a] + 0x30 + iVar14) -
       *(float *)(*(int *)(DAT_0292fc68[0x1a] + iVar14 + 0x40) + 0x30)) * 1.73;
  *(float *)(iVar11 + 0x2c) =
       (*(float *)(DAT_0292fc68[0x1a] + 0x34 + iVar14) -
       *(float *)(*(int *)(DAT_0292fc68[0x1a] + 0x40 + iVar14) + 0x34)) * 1.73 *
       *(float *)(iVar11 + 100);
  *(float *)(iVar11 + 0x30) =
       (*(float *)(DAT_0292fc68[0x1a] + 0x38 + iVar14) -
       *(float *)(*(int *)(DAT_0292fc68[0x1a] + iVar14 + 0x40) + 0x38)) * 1.73;
  if ((*(byte *)(DAT_0292fc68[0x1a] + iVar14 + 0x4c) & 1) != 0) {
    FUN_005b5b90(&DAT_0292fdd0,DAT_0292fc68[0x1a] + iVar14);
    _DAT_02921874 = *(float *)((int)fVar10 + 0x1c) - *(float *)(iVar14 + 0x30 + DAT_0292fc68[0x1a]);
    _DAT_02921878 =
         (*(float *)((int)fVar10 + 0x20) - *(float *)((int)DAT_0292186c + 0x50)) *
         *(float *)((int)DAT_0292186c + 0x5c) - *(float *)(iVar14 + 0x34 + DAT_0292fc68[0x1a]);
    _DAT_0292187c = *(float *)((int)fVar10 + 0x24) - *(float *)(iVar14 + 0x38 + DAT_0292fc68[0x1a]);
    _DAT_02921880 = 0x3f800000;
    FUN_005c03e0(&DAT_02921874,&DAT_02921874,&DAT_0292fdd0);
    FUN_005c03e0(&DAT_02921874,&DAT_02921874,*(undefined4 *)(DAT_0292fc68[0x1a] + 0x40 + iVar14));
    iVar11 = (int)DAT_0292186c;
    *(float *)((int)DAT_0292186c + 0x28) = (*(float *)((int)fVar10 + 0x1c) - _DAT_02921874) * 1.3;
    *(float *)(iVar11 + 0x2c) =
         (*(float *)((int)fVar10 + 0x20) -
         (*(float *)(iVar11 + 100) * _DAT_02921878 + *(float *)(iVar11 + 0x50))) * 1.3;
    *(float *)(iVar11 + 0x30) = (*(float *)((int)fVar10 + 0x24) - _DAT_0292187c) * 1.3;
  }
  local_38 = (float *)(iVar11 + 0x14c);
  local_2c = (float *)(iVar11 + 0x148);
  local_3c = 0;
  *(float *)(iVar11 + 0x28) = *(float *)(iVar11 + 0x28) - *(float *)((int)fVar10 + 0xa8) * 0.01;
  *(float *)(iVar11 + 0x2c) = *(float *)(iVar11 + 0x2c) - *(float *)((int)fVar10 + 0xac) * 0.01;
  *(float *)(iVar11 + 0x30) = *(float *)(iVar11 + 0x30) - *(float *)((int)fVar10 + 0xb0) * 0.01;
  *(float *)(iVar11 + 0x1c) = *(float *)((int)fVar10 + 0x1c) - *(float *)(iVar11 + 0x28) * 0.91;
  *(float *)(iVar11 + 0x20) = *(float *)((int)fVar10 + 0x20) - *(float *)(iVar11 + 0x2c) * 0.91;
  *(float *)(iVar11 + 0x24) = *(float *)((int)fVar10 + 0x24) - *(float *)(iVar11 + 0x30) * 0.91;
  iVar8 = *DAT_0292fc68 + *(short *)((int)fVar10 + 0x6c) * 0x38;
  psVar12 = *(short **)(iVar8 + 0xc);
  local_30 = psVar12;
  if (*(float *)(iVar11 + 0x5c) == 1.0) {
    if ((*(byte *)(DAT_0292fc68[0x1a] + 0x4c + iVar14) & 1) == 0) {
      if (*psVar12 < 0) goto LAB_0067a15d;
      local_3c = 0;
      do {
        psVar2 = psVar12 + 1;
        psVar12 = psVar12 + 10;
        for (iVar14 = (int)*psVar2; 0 < iVar14; iVar14 = iVar14 + -1) {
          if (*(char *)((int)psVar12 + 0x61) == '\0') {
            *local_38 = (float)psVar12;
            local_38 = local_38 + 1;
            local_3c = local_3c + 1;
          }
          psVar12 = psVar12 + 0x32;
        }
      } while (-1 < *psVar12);
    }
    else {
      if (*psVar12 < 0) goto LAB_0067a15d;
      do {
        local_34 = (int)psVar12[1];
        psVar12 = psVar12 + 10;
        if (0 < local_34) {
          local_30 = (short *)(local_40 * 100);
          do {
            if (*(char *)((int)psVar12 + 0x61) == '\0') {
              *pfVar13 = *(float *)(psVar12 + 0xc);
              pfVar13[1] = *(float *)(psVar12 + 0xe);
              pfVar13[2] = *(float *)(psVar12 + 0x10);
              pfVar13[3] = 0.0;
              pfVar13[4] = *(float *)(psVar12 + 0x12);
              pfVar13[5] = *(float *)(psVar12 + 0x14);
              pfVar13[6] = *(float *)(psVar12 + 0x16);
              pfVar13[7] = 0.0;
              pfVar13[8] = *(float *)(psVar12 + 0x18);
              pfVar13[9] = *(float *)(psVar12 + 0x1a);
              pfVar13[10] = *(float *)(psVar12 + 0x1c);
              pfVar13[0xb] = 0.0;
              FUN_005c0620(pfVar13,pfVar13,
                           *(undefined4 *)
                            (*(short *)(iVar8 + 0x30) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
              if (65535.0 <= *(float *)(psVar12 + 0x2c)) {
                pfVar13[0xc] = pfVar13[8];
                pfVar13[0xd] = pfVar13[9];
                pfVar13[0xe] = pfVar13[10];
                pfVar13[0xf] = pfVar13[0xb];
              }
              else {
                pfVar1 = pfVar13 + 0xc;
                *pfVar1 = *(float *)(psVar12 + 0x1e);
                pfVar13[0xd] = *(float *)(psVar12 + 0x20);
                pfVar13[0xe] = *(float *)(psVar12 + 0x22);
                pfVar13[0xf] = 0.0;
                FUN_005c03e0(pfVar1,pfVar1,
                             *(undefined4 *)
                              (*(short *)(iVar8 + 0x30) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
              }
              iVar14 = DAT_02924b34 + (int)local_30;
              *(undefined4 *)(iVar14 + 0x60) = *(undefined4 *)(psVar12 + 0x30);
              *(float *)(iVar14 + 0x18) = *pfVar13;
              *(float *)(iVar14 + 0x20) = pfVar13[2];
              *(float *)(iVar14 + 0x1c) = pfVar13[1];
              *(float *)(iVar14 + 0x24) = pfVar13[4];
              *(float *)(iVar14 + 0x2c) = pfVar13[6];
              *(float *)(iVar14 + 0x28) = pfVar13[5];
              *(float *)(iVar14 + 0x30) = pfVar13[8];
              *(float *)(iVar14 + 0x38) = pfVar13[10];
              *(float *)(iVar14 + 0x34) = pfVar13[9];
              if (65535.0 <= *(float *)(psVar12 + 0x2c)) {
                *(undefined4 *)(iVar14 + 0x58) = 0x47800000;
              }
              else {
                *(float *)(iVar14 + 0x3c) = pfVar13[0xc];
                *(float *)(iVar14 + 0x44) = pfVar13[0xe];
                *(float *)(iVar14 + 0x40) = pfVar13[0xd];
                *pfVar13 = *(float *)(iVar14 + 0x24) - *(float *)(iVar14 + 0x3c);
                pfVar13[1] = *(float *)(iVar14 + 0x28) - *(float *)(iVar14 + 0x40);
                pfVar13[2] = *(float *)(iVar14 + 0x2c) - *(float *)(iVar14 + 0x44);
                pfVar13[4] = *(float *)(iVar14 + 0x30) - *(float *)(iVar14 + 0x3c);
                pfVar13[5] = *(float *)(iVar14 + 0x34) - *(float *)(iVar14 + 0x40);
                pfVar13[6] = *(float *)(iVar14 + 0x38) - *(float *)(iVar14 + 0x44);
                local_18 = pfVar13[6] * pfVar13[1] - pfVar13[5] * pfVar13[2];
                local_14 = pfVar13[4] * pfVar13[2] - *pfVar13 * pfVar13[6];
                fVar9 = *pfVar13;
                fVar4 = pfVar13[5];
                fVar5 = pfVar13[4];
                fVar6 = pfVar13[1];
                *(float *)(iVar14 + 0x54) = local_18;
                *(float *)(iVar14 + 0x58) = local_14;
                local_10 = fVar9 * fVar4 - fVar5 * fVar6;
                *(float *)(iVar14 + 0x5c) = local_10;
                local_28 = *(float *)(iVar14 + 0x5c) * *(float *)(iVar14 + 0x5c) +
                           *(float *)(iVar14 + 0x54) * *(float *)(iVar14 + 0x54) +
                           *(float *)(iVar14 + 0x58) * *(float *)(iVar14 + 0x58);
                fVar16 = (float10)FUN_005c0240(local_28);
                if ((float)fVar16 == 0.0) {
                  local_44 = 0.0;
                }
                else {
                  local_44 = 1.0 / (float)fVar16;
                }
                iVar14 = (int)local_30 + DAT_02924b34;
                *(float *)(iVar14 + 0x54) =
                     local_44 * *(float *)((int)local_30 + DAT_02924b34 + 0x54);
                *(float *)(iVar14 + 0x58) = *(float *)(iVar14 + 0x58) * local_44;
                *(float *)(iVar14 + 0x5c) = local_44 * *(float *)(iVar14 + 0x5c);
              }
              *pfVar13 = *(float *)(iVar14 + 0x30) - *(float *)(iVar14 + 0x18);
              pfVar13[1] = *(float *)(iVar14 + 0x34) - *(float *)(iVar14 + 0x1c);
              pfVar13[2] = *(float *)(iVar14 + 0x38) - *(float *)(iVar14 + 0x20);
              pfVar13[4] = *(float *)(iVar14 + 0x24) - *(float *)(iVar14 + 0x18);
              pfVar13[5] = *(float *)(iVar14 + 0x28) - *(float *)(iVar14 + 0x1c);
              pfVar13[6] = *(float *)(iVar14 + 0x2c) - *(float *)(iVar14 + 0x20);
              local_c = pfVar13[6] * pfVar13[1] - pfVar13[5] * pfVar13[2];
              local_8 = pfVar13[4] * pfVar13[2] - *pfVar13 * pfVar13[6];
              fVar9 = *pfVar13;
              fVar4 = pfVar13[5];
              fVar5 = pfVar13[4];
              fVar6 = pfVar13[1];
              *(float *)(iVar14 + 0x48) = local_c;
              *(float *)(iVar14 + 0x4c) = local_8;
              local_4 = fVar9 * fVar4 - fVar5 * fVar6;
              *(float *)(iVar14 + 0x50) = local_4;
              local_28 = *(float *)(iVar14 + 0x50) * *(float *)(iVar14 + 0x50) +
                         *(float *)(iVar14 + 0x48) * *(float *)(iVar14 + 0x48) +
                         *(float *)(iVar14 + 0x4c) * *(float *)(iVar14 + 0x4c);
              fVar16 = (float10)FUN_005c0240(local_28);
              local_28 = (float)fVar16;
              if (local_28 == 0.0) {
                local_44 = 0.0;
              }
              else {
                local_44 = 1.0 / local_28;
              }
              fVar9 = (float)(DAT_02924b34 + (int)local_30);
              *(float *)((int)fVar9 + 0x48) =
                   local_44 * *(float *)(DAT_02924b34 + 0x48 + (int)local_30);
              *(float *)((int)fVar9 + 0x4c) = *(float *)((int)fVar9 + 0x4c) * local_44;
              *(float *)((int)fVar9 + 0x50) = local_44 * *(float *)((int)fVar9 + 0x50);
              *local_38 = fVar9;
              local_3c = local_3c + 1;
              local_40 = local_40 + 1;
              local_30 = local_30 + 0x32;
              local_38 = local_38 + 1;
            }
            local_34 = local_34 + -1;
            psVar12 = psVar12 + 0x32;
          } while (0 < local_34);
        }
      } while (-1 < *psVar12);
    }
  }
  else if ((*(byte *)(DAT_0292fc68[0x1a] + 0x4c + iVar14) & 1) == 0) {
    iVar14 = DAT_02924b34;
    if (*psVar12 < 0) goto LAB_0067a15d;
    do {
      local_34 = (int)psVar12[1];
      psVar12 = psVar12 + 10;
      if (0 < local_34) {
        iVar15 = local_40 * 100;
        do {
          if (*(char *)((int)psVar12 + 0x61) == '\0') {
            *(undefined4 *)(iVar15 + 0x60 + iVar14) = *(undefined4 *)(psVar12 + 0x30);
            *(undefined4 *)(iVar15 + 0x18 + iVar14) = *(undefined4 *)(psVar12 + 0xc);
            *(undefined4 *)(iVar15 + 0x20 + iVar14) = *(undefined4 *)(psVar12 + 0x10);
            *(float *)(iVar15 + 0x1c + iVar14) =
                 (*(float *)(psVar12 + 0xe) + *(float *)(iVar8 + 4)) * *(float *)(iVar11 + 100) -
                 *(float *)(iVar8 + 4);
            *(undefined4 *)(iVar15 + 0x24 + iVar14) = *(undefined4 *)(psVar12 + 0x12);
            *(undefined4 *)(iVar15 + 0x2c + iVar14) = *(undefined4 *)(psVar12 + 0x16);
            *(float *)(iVar15 + 0x28 + iVar14) =
                 (*(float *)(psVar12 + 0x14) + *(float *)(iVar8 + 4)) * *(float *)(iVar11 + 100) -
                 *(float *)(iVar8 + 4);
            *(undefined4 *)(iVar15 + 0x30 + iVar14) = *(undefined4 *)(psVar12 + 0x18);
            *(undefined4 *)(iVar15 + 0x38 + iVar14) = *(undefined4 *)(psVar12 + 0x1c);
            *(float *)(iVar15 + 0x34 + iVar14) =
                 (*(float *)(psVar12 + 0x1a) + *(float *)(iVar8 + 4)) * *(float *)(iVar11 + 100) -
                 *(float *)(iVar8 + 4);
            if (65535.0 <= *(float *)(psVar12 + 0x2c)) {
              *(undefined4 *)(iVar15 + 0x58 + iVar14) = 0x47800000;
            }
            else {
              *(undefined4 *)(iVar15 + 0x3c + iVar14) = *(undefined4 *)(psVar12 + 0x1e);
              *(undefined4 *)(iVar15 + 0x44 + iVar14) = *(undefined4 *)(psVar12 + 0x22);
              *(float *)(iVar15 + 0x40 + iVar14) =
                   (*(float *)(psVar12 + 0x20) + *(float *)(iVar8 + 4)) * *(float *)(iVar11 + 100) -
                   *(float *)(iVar8 + 4);
              local_30 = (short *)(*(float *)(iVar11 + 0x60) *
                                   *(float *)(psVar12 + 0x2c) * *(float *)(psVar12 + 0x2c) +
                                   *(float *)(psVar12 + 0x2a) * *(float *)(psVar12 + 0x2a) +
                                  *(float *)(psVar12 + 0x2e) * *(float *)(psVar12 + 0x2e));
              fVar16 = (float10)FUN_005c0240(local_30);
              iVar14 = DAT_02924b34;
              iVar11 = (int)DAT_0292186c;
              if ((float)fVar16 == 0.0) {
                local_44 = 0.0;
              }
              else {
                local_44 = 1.0 / (float)fVar16;
              }
              *(float *)(iVar15 + 0x54 + DAT_02924b34) = local_44 * *(float *)(psVar12 + 0x2a);
              *(float *)(iVar15 + 0x58 + iVar14) =
                   *(float *)(iVar11 + 0x5c) * *(float *)(psVar12 + 0x2c) * local_44;
              *(float *)(iVar15 + 0x5c + iVar14) = local_44 * *(float *)(psVar12 + 0x2e);
            }
            local_30 = (short *)(*(float *)(iVar11 + 0x60) *
                                 *(float *)(psVar12 + 0x26) * *(float *)(psVar12 + 0x26) +
                                 *(float *)(psVar12 + 0x24) * *(float *)(psVar12 + 0x24) +
                                *(float *)(psVar12 + 0x28) * *(float *)(psVar12 + 0x28));
            fVar16 = (float10)FUN_005c0240(local_30);
            iVar14 = DAT_02924b34;
            iVar11 = (int)DAT_0292186c;
            local_30 = (short *)(float)fVar16;
            if ((float)local_30 == 0.0) {
              local_44 = 0.0;
            }
            else {
              local_44 = 1.0 / (float)local_30;
            }
            fVar10 = (float)(iVar15 + DAT_02924b34);
            *(float *)((int)fVar10 + 0x48) = local_44 * *(float *)(psVar12 + 0x24);
            *(float *)((int)fVar10 + 0x4c) =
                 *(float *)(iVar11 + 0x5c) * *(float *)(psVar12 + 0x26) * local_44;
            *(float *)((int)fVar10 + 0x50) = local_44 * *(float *)(psVar12 + 0x28);
            *local_38 = fVar10;
            local_3c = local_3c + 1;
            local_40 = local_40 + 1;
            iVar15 = iVar15 + 100;
            fVar10 = local_28;
            local_38 = local_38 + 1;
          }
          local_34 = local_34 + -1;
          psVar12 = psVar12 + 0x32;
        } while (0 < local_34);
      }
    } while (-1 < *psVar12);
  }
  else {
    if (*psVar12 < 0) goto LAB_0067a15d;
    do {
      local_34 = (int)psVar12[1];
      psVar12 = psVar12 + 10;
      if (0 < local_34) {
        local_30 = (short *)(local_40 * 100);
        do {
          if (*(char *)((int)psVar12 + 0x61) == '\0') {
            *pfVar13 = *(float *)(psVar12 + 0xc);
            pfVar13[1] = *(float *)(psVar12 + 0xe);
            pfVar13[2] = *(float *)(psVar12 + 0x10);
            pfVar13[3] = 0.0;
            pfVar13[4] = *(float *)(psVar12 + 0x12);
            pfVar13[5] = *(float *)(psVar12 + 0x14);
            pfVar13[6] = *(float *)(psVar12 + 0x16);
            pfVar13[7] = 0.0;
            pfVar13[8] = *(float *)(psVar12 + 0x18);
            pfVar13[9] = *(float *)(psVar12 + 0x1a);
            pfVar13[10] = *(float *)(psVar12 + 0x1c);
            pfVar13[0xb] = 0.0;
            FUN_005c0620(pfVar13,pfVar13,
                         *(undefined4 *)
                          (*(short *)(iVar8 + 0x30) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
            pfVar1 = pfVar13 + 0xc;
            if (65535.0 <= *(float *)(psVar12 + 0x2c)) {
              *pfVar1 = pfVar13[8];
              pfVar13[0xd] = pfVar13[9];
              pfVar13[0xe] = pfVar13[10];
              pfVar13[0xf] = pfVar13[0xb];
            }
            else {
              *pfVar1 = *(float *)(psVar12 + 0x1e);
              pfVar13[0xd] = *(float *)(psVar12 + 0x20);
              pfVar13[0xe] = *(float *)(psVar12 + 0x22);
              pfVar13[0xf] = 0.0;
              FUN_005c03e0(pfVar1,pfVar1,
                           *(undefined4 *)
                            (*(short *)(iVar8 + 0x30) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
            }
            iVar11 = DAT_02924b34;
            *(undefined4 *)(DAT_02924b34 + 0x60 + (int)local_30) = *(undefined4 *)(psVar12 + 0x30);
            *(float *)(iVar11 + 0x18 + (int)local_30) = *pfVar13;
            iVar14 = (int)DAT_0292186c;
            iVar11 = iVar11 + (int)local_30;
            *(float *)(iVar11 + 0x20) = pfVar13[2];
            *(float *)(iVar11 + 0x1c) =
                 (pfVar13[1] + *(float *)(iVar8 + 4)) * *(float *)(iVar14 + 100) -
                 *(float *)(iVar8 + 4);
            *(float *)(iVar11 + 0x24) = pfVar13[4];
            *(float *)(iVar11 + 0x2c) = pfVar13[6];
            *(float *)(iVar11 + 0x28) =
                 (pfVar13[5] + *(float *)(iVar8 + 4)) * *(float *)(iVar14 + 100) -
                 *(float *)(iVar8 + 4);
            *(float *)(iVar11 + 0x30) = pfVar13[8];
            *(float *)(iVar11 + 0x38) = pfVar13[10];
            *(float *)(iVar11 + 0x34) =
                 (pfVar13[9] + *(float *)(iVar8 + 4)) * *(float *)(iVar14 + 100) -
                 *(float *)(iVar8 + 4);
            if (65535.0 <= *(float *)(psVar12 + 0x2c)) {
              *(undefined4 *)(iVar11 + 0x58) = 0x47800000;
            }
            else {
              *(float *)(iVar11 + 0x3c) = *pfVar1;
              *(float *)(iVar11 + 0x44) = pfVar13[0xe];
              *(float *)(iVar11 + 0x40) =
                   (pfVar13[0xd] + *(float *)(iVar8 + 4)) * *(float *)(iVar14 + 100) -
                   *(float *)(iVar8 + 4);
              *pfVar13 = *(float *)(iVar11 + 0x24) - *(float *)(iVar11 + 0x3c);
              pfVar13[1] = *(float *)(iVar11 + 0x28) - *(float *)(iVar11 + 0x40);
              pfVar13[2] = *(float *)(iVar11 + 0x2c) - *(float *)(iVar11 + 0x44);
              pfVar13[4] = *(float *)(iVar11 + 0x30) - *(float *)(iVar11 + 0x3c);
              pfVar13[5] = *(float *)(iVar11 + 0x34) - *(float *)(iVar11 + 0x40);
              pfVar13[6] = *(float *)(iVar11 + 0x38) - *(float *)(iVar11 + 0x44);
              local_c = pfVar13[1] * pfVar13[6] - pfVar13[2] * pfVar13[5];
              local_8 = pfVar13[4] * pfVar13[2] - *pfVar13 * pfVar13[6];
              fVar10 = *pfVar13;
              fVar9 = pfVar13[5];
              fVar4 = pfVar13[4];
              fVar5 = pfVar13[1];
              *(float *)(iVar11 + 0x54) = local_c;
              *(float *)(iVar11 + 0x58) = local_8;
              local_4 = fVar10 * fVar9 - fVar4 * fVar5;
              *(float *)(iVar11 + 0x5c) = local_4;
              local_44 = *(float *)(iVar11 + 0x5c) * *(float *)(iVar11 + 0x5c) +
                         *(float *)(iVar11 + 0x54) * *(float *)(iVar11 + 0x54) +
                         *(float *)(iVar11 + 0x58) * *(float *)(iVar11 + 0x58);
              fVar16 = (float10)FUN_005c0240(local_44);
              if ((float)fVar16 == 0.0) {
                fVar10 = 0.0;
              }
              else {
                fVar10 = 1.0 / (float)fVar16;
              }
              iVar11 = (int)local_30 + DAT_02924b34;
              *(float *)(iVar11 + 0x54) = fVar10 * *(float *)((int)local_30 + DAT_02924b34 + 0x54);
              *(float *)(iVar11 + 0x58) = *(float *)(iVar11 + 0x58) * fVar10;
              *(float *)(iVar11 + 0x5c) = fVar10 * *(float *)(iVar11 + 0x5c);
            }
            *pfVar13 = *(float *)(iVar11 + 0x30) - *(float *)(iVar11 + 0x18);
            pfVar13[1] = *(float *)(iVar11 + 0x34) - *(float *)(iVar11 + 0x1c);
            pfVar13[2] = *(float *)(iVar11 + 0x38) - *(float *)(iVar11 + 0x20);
            pfVar13[4] = *(float *)(iVar11 + 0x24) - *(float *)(iVar11 + 0x18);
            pfVar13[5] = *(float *)(iVar11 + 0x28) - *(float *)(iVar11 + 0x1c);
            pfVar13[6] = *(float *)(iVar11 + 0x2c) - *(float *)(iVar11 + 0x20);
            local_18 = pfVar13[6] * pfVar13[1] - pfVar13[5] * pfVar13[2];
            local_14 = pfVar13[4] * pfVar13[2] - *pfVar13 * pfVar13[6];
            fVar10 = *pfVar13;
            fVar9 = pfVar13[5];
            fVar4 = pfVar13[4];
            fVar5 = pfVar13[1];
            *(float *)(iVar11 + 0x48) = local_18;
            *(float *)(iVar11 + 0x4c) = local_14;
            local_10 = fVar10 * fVar9 - fVar4 * fVar5;
            *(float *)(iVar11 + 0x50) = local_10;
            local_44 = *(float *)(iVar11 + 0x50) * *(float *)(iVar11 + 0x50) +
                       *(float *)(iVar11 + 0x48) * *(float *)(iVar11 + 0x48) +
                       *(float *)(iVar11 + 0x4c) * *(float *)(iVar11 + 0x4c);
            fVar16 = (float10)FUN_005c0240(local_44);
            if ((float)fVar16 == 0.0) {
              local_44 = 0.0;
            }
            else {
              local_44 = 1.0 / (float)fVar16;
            }
            fVar10 = (float)(DAT_02924b34 + (int)local_30);
            *(float *)((int)fVar10 + 0x48) =
                 local_44 * *(float *)(DAT_02924b34 + 0x48 + (int)local_30);
            *(float *)((int)fVar10 + 0x4c) = local_44 * *(float *)((int)fVar10 + 0x4c);
            *(float *)((int)fVar10 + 0x50) = local_44 * *(float *)((int)fVar10 + 0x50);
            *local_38 = fVar10;
            local_3c = local_3c + 1;
            local_40 = local_40 + 1;
            local_30 = local_30 + 0x32;
            fVar10 = local_28;
            local_38 = local_38 + 1;
          }
          local_34 = local_34 + -1;
          psVar12 = psVar12 + 0x32;
        } while (0 < local_34);
      }
    } while (-1 < *psVar12);
  }
  if (local_3c != 0) {
    *(short *)local_2c = (short)local_3c;
    *(undefined2 *)((int)local_2c + 2) = *(undefined2 *)((int)fVar10 + 0x6c);
    local_2c = local_38;
  }
LAB_0067a15d:
  *(undefined2 *)local_2c = 0;
  *(undefined2 *)((int)local_2c + 2) = 0;
  FUN_0066f8f0();
  FUN_00675240();
  FUN_00678410();
  iVar14 = FUN_00678f60(&local_44);
  fVar9 = local_20;
  if (iVar14 != 0) {
    FUN_006de960();
    FUN_006de960();
    DAT_0292fc64 = local_24;
    DAT_02924b34 = DAT_02962b30;
    DAT_0292186c = fVar10;
    return 1;
  }
  *(undefined4 *)((int)local_20 + 4) = *(undefined4 *)((int)local_20 + 0x1c);
  iVar14 = (int)DAT_0292186c;
  puVar3 = (undefined4 *)((int)local_20 + 0x1c);
  *(undefined4 *)((int)local_20 + 8) = *(undefined4 *)((int)local_20 + 0x20);
  *(undefined4 *)((int)local_20 + 0xc) = *(undefined4 *)((int)local_20 + 0x24);
  *(float *)(iVar14 + 0x20) = *(float *)((int)local_20 + 8) + 0.025;
  *(undefined4 *)(iVar14 + 0x28) = 0;
  *(undefined4 *)(iVar14 + 0x2c) = 0xbd4ccccd;
  *(undefined4 *)(iVar14 + 0x30) = 0;
  FUN_0066f8f0();
  DAT_02948edc = (int)fVar10 + 0x148;
  FUN_00675240();
  fVar4 = local_44;
  local_20 = *(float *)((int)fVar9 + 8);
  *(float *)((int)DAT_0292186c + 0x20) = local_20;
  if ((*(byte *)((int)DAT_0292186c + 0x88) == 0) || (0xf < *(byte *)((int)DAT_0292186c + 0x88))) {
    fVar5 = 2e+06;
  }
  else {
    fVar5 = *(float *)((int)DAT_0292186c + 0x98) * *(float *)((int)DAT_0292186c + 0x2c) + local_20 +
            0.001 + 0.025;
  }
  *(float *)((int)fVar9 + 8) = fVar5;
  local_44 = (float)((uint)local_44 & 0xffffff00);
  fVar5 = local_44;
  DAT_0292186c = fVar10;
  if (2e+06 <= *(float *)((int)fVar9 + 8)) {
    *(undefined4 *)((int)fVar9 + 8) = *(undefined4 *)((int)fVar9 + 0x20);
  }
  else {
    local_20 = *(float *)((int)fVar9 + 8) - *(float *)((int)fVar9 + 0x20);
    if (-0.008 <= local_20) {
      local_44._1_3_ = SUB43(fVar4,1);
      if (local_20 < 0.01) {
        local_44 = (float)CONCAT31(local_44._1_3_,1);
        *(float *)((int)fVar9 + 0x20) = local_20 + *(float *)((int)fVar9 + 0x20);
        fVar5 = local_44;
      }
      else if ((local_20 - 0.0025) * (local_20 - 0.0025) <
               *(float *)((int)fVar9 + 0x28) * *(float *)((int)fVar9 + 0x28) +
               *(float *)((int)fVar9 + 0x30) * *(float *)((int)fVar9 + 0x30)) {
        local_44 = (float)CONCAT31(local_44._1_3_,1);
        *(float *)((int)fVar9 + 0x20) = local_20 + *(float *)((int)fVar9 + 0x20);
        fVar5 = local_44;
      }
    }
  }
  local_44 = fVar5;
  iVar14 = FUN_00679080(puVar3,0,local_1c,1,1);
  fVar4 = DAT_0292186c;
  if (iVar14 == 0) {
    cVar7 = '\0';
  }
  else {
    cVar7 = local_44._0_1_;
  }
  *(undefined4 *)((int)DAT_0292186c + 0x1c) = *puVar3;
  *(undefined4 *)((int)fVar4 + 0x20) = *(undefined4 *)((int)fVar9 + 0x20);
  *(undefined4 *)((int)fVar4 + 0x24) = *(undefined4 *)((int)fVar9 + 0x24);
  if ((cVar7 == '\0') ||
     (iVar14 = (int)DAT_02961fdc, *(int *)(iVar14 * 0x38 + 0x2c + *DAT_0292fc68) != 1)) {
    if (DAT_02947c74 != 0) {
      *(ushort *)(DAT_02947c74 + 6) = *(ushort *)(DAT_02947c74 + 6) & 0xfffe;
    }
  }
  else {
    *(undefined1 *)(*(int *)((int)fVar4 + 0x40) + 1) = 1;
    FUN_00678640(*(undefined4 *)((int)fVar10 + 0x40),(int)fVar10 + 0x28,param_1,
                 (int)*(short *)(iVar14 * 0x38 + 0x30 + *DAT_0292fc68));
  }
  FUN_006de960();
  FUN_006de960();
  DAT_02924b34 = DAT_02962b30;
  DAT_0292186c = fVar10;
  DAT_0292fc64 = local_24;
  return 0;
}

