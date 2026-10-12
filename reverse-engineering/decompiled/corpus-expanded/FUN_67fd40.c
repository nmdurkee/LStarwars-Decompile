/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67fd40; label: FUN_0067fd40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067fd40(int param_1,byte param_2)

{
  char *pcVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  float *pfVar16;
  float *pfVar17;
  int iVar18;
  short *psVar19;
  int iVar20;
  float10 fVar21;
  float *local_50;
  float local_4c;
  int local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  float local_28;
  float *local_24;
  float local_20;
  
  local_2c = 0;
  iVar13 = FUN_006de8d0(0xd0);
  iVar12 = DAT_0292186c;
  DAT_02924b34 = DAT_02962b30;
  local_50 = (float *)(DAT_0292186c + 0x14c);
  pfVar14 = (float *)(DAT_0292186c + 0x93c);
  pcVar1 = (char *)(DAT_0292186c + 0x34);
  pfVar16 = (float *)(iVar13 + 0x1fU & 0xfffffff0);
  local_24 = (float *)(DAT_0292186c + 0x148);
  local_48 = 0;
  DAT_0292119c = 0;
  *(undefined2 *)(DAT_0292186c + 0x8a) = 0xffff;
  if (*pcVar1 == '\x01') {
    if (*(float *)(iVar12 + 0x28) <= 0.0) {
      local_44 = ((*(float *)(iVar12 + 0x1c) + *(float *)(iVar12 + 0x28)) - 0.02) -
                 *(float *)(iVar12 + 0x50);
      fVar11 = *(float *)(iVar12 + 0x1c);
    }
    else {
      local_44 = (*(float *)(iVar12 + 0x1c) - 0.02) - *(float *)(iVar12 + 0x50);
      fVar11 = *(float *)(iVar12 + 0x1c) + *(float *)(iVar12 + 0x28);
    }
    local_4c = fVar11 + 0.02 + *(float *)(iVar12 + 0x50);
    if (*(float *)(iVar12 + 0x2c) <= 0.0) {
      local_3c = ((*(float *)(iVar12 + 0x2c) + *(float *)(iVar12 + 0x20)) - 0.02) -
                 *(float *)(iVar12 + 0x50);
      fVar11 = *(float *)(iVar12 + 0x20);
    }
    else {
      local_3c = (*(float *)(iVar12 + 0x20) - 0.02) - *(float *)(iVar12 + 0x50);
      fVar11 = *(float *)(iVar12 + 0x2c) + *(float *)(iVar12 + 0x20);
    }
    local_40 = fVar11 + 0.02 + *(float *)(iVar12 + 0x50);
    if (*(float *)(iVar12 + 0x30) <= 0.0) {
      local_34 = ((*(float *)(iVar12 + 0x30) + *(float *)(iVar12 + 0x24)) - 0.02) -
                 *(float *)(iVar12 + 0x50);
      fVar11 = *(float *)(iVar12 + 0x24);
    }
    else {
      local_34 = (*(float *)(iVar12 + 0x24) - 0.02) - *(float *)(iVar12 + 0x50);
      fVar11 = *(float *)(iVar12 + 0x30) + *(float *)(iVar12 + 0x24);
    }
    local_38 = fVar11 + 0.02 + *(float *)(iVar12 + 0x50);
    fVar11 = *(float *)(iVar12 + 0x50) + 1.02 +
             (local_34 - local_38) * (local_34 - local_38) +
             (local_44 - local_4c) * (local_44 - local_4c) +
             (local_3c - local_40) * (local_3c - local_40);
  }
  else {
    fVar11 = *(float *)(iVar12 + 0x54) + 0.02 +
             *(float *)(iVar12 + 0x30) * *(float *)(iVar12 + 0x30) +
             *(float *)(iVar12 + 0x28) * *(float *)(iVar12 + 0x28) +
             *(float *)(iVar12 + 0x2c) * *(float *)(iVar12 + 0x2c);
    local_4c = fVar11 + *(float *)(iVar12 + 0x1c);
    local_3c = *(float *)(iVar12 + 0x5c) * fVar11;
    local_40 = *(float *)(iVar12 + 0x20) + local_3c;
    local_38 = *(float *)(iVar12 + 0x24) + fVar11;
    local_44 = *(float *)(iVar12 + 0x1c) - fVar11;
    local_3c = *(float *)(iVar12 + 0x20) - local_3c;
    local_34 = *(float *)(iVar12 + 0x24) - fVar11;
    fVar11 = fVar11 + 1.0;
  }
  fVar21 = (float10)FUN_005c0240(fVar11);
  iVar13 = DAT_0292186c;
  *(float **)(DAT_0292186c + 0x8c) = local_24;
  fVar11 = local_44 - 0.05;
  pfVar2 = (float *)(*DAT_0292fc68 + param_1 * 0x38);
  local_4c = local_4c + 0.05;
  fVar3 = local_3c - 0.05;
  fVar4 = local_40 + 0.05;
  iVar18 = DAT_0292fc68[0x1a] + *(short *)(pfVar2 + 0xc) * 0x6c;
  local_34 = local_34 - 0.05;
  fVar5 = local_38 + 0.05;
  if (*(int *)(iVar18 + 0x40) == 0) {
    local_28 = local_4c - *pfVar2;
    local_44 = fVar11 - *pfVar2;
    local_40 = fVar4 - pfVar2[1];
    local_20 = fVar3 - pfVar2[1];
    local_38 = fVar5 - pfVar2[2];
    local_3c = local_34 - pfVar2[2];
  }
  else {
    iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
    if (*(float *)(*(int *)(iVar15 + 0x40) + 0x30) <= *(float *)(iVar15 + 0x30)) {
      local_28 = local_4c - *pfVar2;
      iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      local_44 = (fVar11 + (*(float *)(*(int *)(iVar15 + 0x40) + 0x30) - *(float *)(iVar15 + 0x30))
                           * 1.5) - *pfVar2;
    }
    else {
      local_44 = fVar11 - *pfVar2;
      iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      local_28 = (local_4c +
                 (*(float *)(*(int *)(iVar15 + 0x40) + 0x30) - *(float *)(iVar15 + 0x30)) * 1.5) -
                 *pfVar2;
    }
    iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
    if (*(float *)(*(int *)(iVar15 + 0x40) + 0x34) <= *(float *)(iVar15 + 0x34)) {
      local_40 = fVar4 - pfVar2[1];
      iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      local_20 = (fVar3 + (*(float *)(*(int *)(iVar15 + 0x40) + 0x34) - *(float *)(iVar15 + 0x34)) *
                          1.5) - pfVar2[1];
    }
    else {
      local_20 = fVar3 - pfVar2[1];
      iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      local_40 = (fVar4 + (*(float *)(*(int *)(iVar15 + 0x40) + 0x34) - *(float *)(iVar15 + 0x34)) *
                          1.5) - pfVar2[1];
    }
    iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
    if (*(float *)(*(int *)(iVar15 + 0x40) + 0x38) <= *(float *)(iVar15 + 0x38)) {
      local_38 = fVar5 - pfVar2[2];
      iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      local_3c = (local_34 +
                 (*(float *)(*(int *)(iVar15 + 0x40) + 0x38) - *(float *)(iVar15 + 0x38)) * 1.5) -
                 pfVar2[2];
    }
    else {
      local_3c = local_34 - pfVar2[2];
      iVar15 = *(short *)(pfVar2 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      local_38 = (fVar5 + (*(float *)(*(int *)(iVar15 + 0x40) + 0x38) - *(float *)(iVar15 + 0x38)) *
                          1.5) - pfVar2[2];
    }
  }
  if ((*(byte *)(iVar18 + 0x4c) & 1) == 0) {
    if (((((pfVar2[4] < local_28 != (pfVar2[4] == local_28)) &&
          (pfVar2[5] < local_40 != (pfVar2[5] == local_40))) &&
         (pfVar2[6] < local_38 != (pfVar2[6] == local_38))) &&
        ((local_44 <= pfVar2[7] && (local_20 < pfVar2[8])))) &&
       ((local_3c < pfVar2[9] &&
        ((pfVar2[0xb] != -NAN &&
         (pfVar16 = (float *)pfVar2[3], iVar18 = DAT_02924b34, -1 < *(short *)pfVar16)))))) {
      do {
        iVar15 = (int)*(short *)((int)pfVar16 + 2);
        pfVar17 = pfVar16 + 5;
        if ((pfVar16[1] < local_28 == (pfVar16[1] == local_28)) ||
           (((pfVar16[2] <= local_44 || (pfVar16[3] < local_38 == (pfVar16[3] == local_38))) ||
            (pfVar16[4] <= local_3c)))) {
          pfVar17 = pfVar17 + iVar15 * 0x19;
        }
        else if (0 < iVar15) {
          iVar20 = local_2c * 100;
          do {
            if (((((*pfVar17 < local_28 != (*pfVar17 == local_28)) && (local_44 < pfVar17[1])) &&
                 ((pfVar17[4] < local_38 != (pfVar17[4] == local_38) &&
                  ((local_3c < pfVar17[5] && (pfVar17[2] < local_40 != (pfVar17[2] == local_40))))))
                 ) && (local_20 < pfVar17[3])) &&
               ((DAT_0292119c = 1, local_50 < pfVar14 &&
                ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
                 ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))))) {
              if (*(float *)(iVar13 + 0x5c) == 1.0) {
                *local_50 = (float)pfVar17;
                local_48 = local_48 + 1;
                local_50 = local_50 + 1;
              }
              else {
                *(float *)(iVar20 + 0x60 + iVar18) = pfVar17[0x18];
                *(float *)(iVar20 + 0x18 + iVar18) = pfVar17[6];
                *(float *)(iVar20 + 0x20 + iVar18) = pfVar17[8];
                *(float *)(iVar20 + 0x1c + iVar18) =
                     (pfVar17[7] + pfVar2[1]) * *(float *)(iVar13 + 100) - pfVar2[1];
                *(float *)(iVar20 + 0x24 + iVar18) = pfVar17[9];
                *(float *)(iVar20 + 0x2c + iVar18) = pfVar17[0xb];
                *(float *)(iVar20 + 0x28 + iVar18) =
                     (pfVar17[10] + pfVar2[1]) * *(float *)(iVar13 + 100) - pfVar2[1];
                *(float *)(iVar20 + 0x30 + iVar18) = pfVar17[0xc];
                *(float *)(iVar20 + 0x38 + iVar18) = pfVar17[0xe];
                *(float *)(iVar20 + 0x34 + iVar18) =
                     (pfVar17[0xd] + pfVar2[1]) * *(float *)(iVar13 + 100) - pfVar2[1];
                if (65535.0 <= pfVar17[0x16]) {
                  *(undefined4 *)(iVar20 + 0x58 + iVar18) = 0x47800000;
                }
                else {
                  *(float *)(iVar20 + 0x3c + iVar18) = pfVar17[0xf];
                  *(float *)(iVar20 + 0x44 + iVar18) = pfVar17[0x11];
                  *(float *)(iVar20 + 0x40 + iVar18) =
                       (pfVar17[0x10] + pfVar2[1]) * *(float *)(iVar13 + 100) - pfVar2[1];
                  fVar21 = (float10)FUN_005c0240(*(float *)(iVar13 + 0x60) *
                                                 pfVar17[0x16] * pfVar17[0x16] +
                                                 pfVar17[0x15] * pfVar17[0x15] +
                                                 pfVar17[0x17] * pfVar17[0x17]);
                  fVar21 = (float10)FUN_0064fde0(0x3f800000,(float)fVar21);
                  iVar18 = DAT_02924b34;
                  iVar13 = DAT_0292186c;
                  fVar11 = (float)fVar21;
                  *(float *)(iVar20 + 0x54 + DAT_02924b34) = fVar11 * pfVar17[0x15];
                  *(float *)(iVar20 + 0x58 + iVar18) =
                       *(float *)(iVar13 + 0x5c) * pfVar17[0x16] * fVar11;
                  *(float *)(iVar20 + 0x5c + iVar18) = fVar11 * pfVar17[0x17];
                }
                fVar21 = (float10)FUN_005c0240(*(float *)(iVar13 + 0x60) *
                                               pfVar17[0x13] * pfVar17[0x13] +
                                               pfVar17[0x12] * pfVar17[0x12] +
                                               pfVar17[0x14] * pfVar17[0x14]);
                fVar21 = (float10)FUN_0064fde0(0x3f800000,(float)fVar21);
                iVar18 = DAT_02924b34;
                iVar13 = DAT_0292186c;
                fVar3 = (float)fVar21;
                fVar11 = (float)(iVar20 + DAT_02924b34);
                *(float *)((int)fVar11 + 0x48) = fVar3 * pfVar17[0x12];
                *(float *)((int)fVar11 + 0x4c) = *(float *)(iVar13 + 0x5c) * pfVar17[0x13] * fVar3;
                *(float *)((int)fVar11 + 0x50) = fVar3 * pfVar17[0x14];
                *local_50 = fVar11;
                local_48 = local_48 + 1;
                local_2c = local_2c + 1;
                iVar20 = iVar20 + 100;
                local_50 = local_50 + 1;
              }
            }
            iVar15 = iVar15 + -1;
            pfVar17 = pfVar17 + 0x19;
          } while (0 < iVar15);
        }
        pfVar16 = pfVar17;
      } while (-1 < *(short *)pfVar17);
      if (local_48 != 0) {
        *(short *)local_24 = (short)local_48;
        *(undefined2 *)(iVar12 + 0x14a) = (undefined2)param_1;
        local_24 = local_50;
      }
    }
  }
  else {
    fVar4 = *(float *)(iVar13 + 100) * ((fVar3 + fVar4) * 0.5 - pfVar2[1]);
    fVar11 = (fVar11 + local_4c) * 0.5 - *pfVar2;
    fVar3 = (local_34 + fVar5) * 0.5 - pfVar2[2];
    fVar11 = fVar11 * fVar11 + fVar4 * fVar4 + fVar3 * fVar3;
    if (((pfVar2[0xb] != -NAN) &&
        (fVar11 < (pfVar2[0xd] + (float)fVar21) * (pfVar2[0xd] + (float)fVar21))) &&
       (psVar19 = (short *)pfVar2[3], -1 < *psVar19)) {
      do {
        local_34 = (float)(int)psVar19[1];
        psVar19 = psVar19 + 10;
        if (0 < (int)local_34) {
          local_30 = local_2c * 100;
          do {
            DAT_0292119c = 1;
            if ((local_50 < pfVar14) &&
               ((*(byte *)((int)psVar19 + 0x61) == 0 ||
                ((param_2 & *(byte *)((int)psVar19 + 0x61)) != 0)))) {
              *pfVar16 = *(float *)(psVar19 + 0xc);
              pfVar16[1] = *(float *)(psVar19 + 0xe);
              pfVar16[2] = *(float *)(psVar19 + 0x10);
              pfVar16[3] = 0.0;
              pfVar16[4] = *(float *)(psVar19 + 0x12);
              pfVar16[5] = *(float *)(psVar19 + 0x14);
              pfVar16[6] = *(float *)(psVar19 + 0x16);
              pfVar16[7] = 0.0;
              pfVar16[8] = *(float *)(psVar19 + 0x18);
              pfVar16[9] = *(float *)(psVar19 + 0x1a);
              pfVar16[10] = *(float *)(psVar19 + 0x1c);
              pfVar16[0xb] = 0.0;
              FUN_005c0620(pfVar16,pfVar16,
                           *(undefined4 *)
                            (*(short *)(pfVar2 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
              pfVar17 = pfVar16 + 0xc;
              if (65535.0 <= *(float *)(psVar19 + 0x2c)) {
                *pfVar17 = pfVar16[8];
                pfVar16[0xd] = pfVar16[9];
                pfVar16[0xe] = pfVar16[10];
                pfVar16[0xf] = pfVar16[0xb];
              }
              else {
                *pfVar17 = *(float *)(psVar19 + 0x1e);
                pfVar16[0xd] = *(float *)(psVar19 + 0x20);
                pfVar16[0xe] = *(float *)(psVar19 + 0x22);
                pfVar16[0xf] = 0.0;
                FUN_005c03e0(pfVar17,pfVar17,
                             *(undefined4 *)
                              (*(short *)(pfVar2 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
              }
              if (((((fVar11 < *pfVar16) || (fVar11 < pfVar16[4])) ||
                   ((fVar11 < pfVar16[8] || (fVar11 < *pfVar17)))) &&
                  ((((*pfVar16 < local_28 || (pfVar16[4] < local_28)) || (pfVar16[8] < local_28)) ||
                   (*pfVar17 < local_28)))) &&
                 (((((local_3c < pfVar16[2] || (local_3c < pfVar16[6])) || (local_3c < pfVar16[10]))
                   || (local_3c < pfVar16[0xe])) &&
                  (((pfVar16[2] < local_38 || (pfVar16[6] < local_38)) ||
                   ((pfVar16[10] < local_38 || (pfVar16[0xe] < local_38)))))))) {
                iVar13 = local_30 + DAT_02924b34;
                *(undefined4 *)(iVar13 + 0x60) = *(undefined4 *)(psVar19 + 0x30);
                *(float *)(iVar13 + 0x18) = *pfVar16;
                iVar18 = DAT_0292186c;
                *(float *)(iVar13 + 0x20) = pfVar16[2];
                *(float *)(iVar13 + 0x1c) =
                     (pfVar2[1] + pfVar16[1]) * *(float *)(iVar18 + 100) - pfVar2[1];
                *(float *)(iVar13 + 0x24) = pfVar16[4];
                *(float *)(iVar13 + 0x2c) = pfVar16[6];
                *(float *)(iVar13 + 0x28) =
                     (pfVar16[5] + pfVar2[1]) * *(float *)(iVar18 + 100) - pfVar2[1];
                *(float *)(iVar13 + 0x30) = pfVar16[8];
                *(float *)(iVar13 + 0x38) = pfVar16[10];
                *(float *)(iVar13 + 0x34) =
                     (pfVar16[9] + pfVar2[1]) * *(float *)(iVar18 + 100) - pfVar2[1];
                if (65535.0 <= *(float *)(psVar19 + 0x2c)) {
                  *(undefined4 *)(iVar13 + 0x58) = 0x47800000;
                }
                else {
                  *(float *)(iVar13 + 0x3c) = *pfVar17;
                  *(float *)(iVar13 + 0x44) = pfVar16[0xe];
                  *(float *)(iVar13 + 0x40) =
                       (pfVar16[0xd] + pfVar2[1]) * *(float *)(iVar18 + 100) - pfVar2[1];
                  *pfVar16 = *(float *)(iVar13 + 0x24) - *(float *)(iVar13 + 0x3c);
                  pfVar16[1] = *(float *)(iVar13 + 0x28) - *(float *)(iVar13 + 0x40);
                  pfVar16[2] = *(float *)(iVar13 + 0x2c) - *(float *)(iVar13 + 0x44);
                  pfVar16[4] = *(float *)(iVar13 + 0x30) - *(float *)(iVar13 + 0x3c);
                  pfVar16[5] = *(float *)(iVar13 + 0x34) - *(float *)(iVar13 + 0x40);
                  pfVar16[6] = *(float *)(iVar13 + 0x38) - *(float *)(iVar13 + 0x44);
                  fVar3 = pfVar16[2];
                  fVar4 = pfVar16[4];
                  fVar5 = pfVar16[6];
                  fVar6 = *pfVar16;
                  fVar7 = pfVar16[5];
                  fVar8 = *pfVar16;
                  fVar9 = pfVar16[4];
                  fVar10 = pfVar16[1];
                  *(float *)(iVar13 + 0x54) = pfVar16[6] * pfVar16[1] - pfVar16[5] * pfVar16[2];
                  *(float *)(iVar13 + 0x58) = fVar3 * fVar4 - fVar5 * fVar6;
                  *(float *)(iVar13 + 0x5c) = fVar7 * fVar8 - fVar9 * fVar10;
                  fVar21 = (float10)FUN_005c0240(*(float *)(iVar13 + 0x5c) *
                                                 *(float *)(iVar13 + 0x5c) +
                                                 *(float *)(iVar13 + 0x54) *
                                                 *(float *)(iVar13 + 0x54) +
                                                 *(float *)(iVar13 + 0x58) *
                                                 *(float *)(iVar13 + 0x58));
                  if ((float)fVar21 == 0.0) {
                    fVar3 = 0.0;
                  }
                  else {
                    fVar3 = 1.0 / (float)fVar21;
                  }
                  iVar13 = DAT_02924b34 + local_30;
                  *(float *)(iVar13 + 0x54) = fVar3 * *(float *)(DAT_02924b34 + 0x54 + local_30);
                  *(float *)(iVar13 + 0x58) = *(float *)(iVar13 + 0x58) * fVar3;
                  *(float *)(iVar13 + 0x5c) = fVar3 * *(float *)(iVar13 + 0x5c);
                }
                *pfVar16 = *(float *)(iVar13 + 0x30) - *(float *)(iVar13 + 0x18);
                pfVar16[1] = *(float *)(iVar13 + 0x34) - *(float *)(iVar13 + 0x1c);
                pfVar16[2] = *(float *)(iVar13 + 0x38) - *(float *)(iVar13 + 0x20);
                pfVar16[4] = *(float *)(iVar13 + 0x24) - *(float *)(iVar13 + 0x18);
                pfVar16[5] = *(float *)(iVar13 + 0x28) - *(float *)(iVar13 + 0x1c);
                pfVar16[6] = *(float *)(iVar13 + 0x2c) - *(float *)(iVar13 + 0x20);
                fVar3 = pfVar16[2];
                fVar4 = pfVar16[4];
                fVar5 = *pfVar16;
                fVar6 = pfVar16[6];
                fVar7 = *pfVar16;
                fVar8 = pfVar16[5];
                fVar9 = pfVar16[4];
                fVar10 = pfVar16[1];
                *(float *)(iVar13 + 0x48) = pfVar16[6] * pfVar16[1] - pfVar16[5] * pfVar16[2];
                *(float *)(iVar13 + 0x4c) = fVar3 * fVar4 - fVar5 * fVar6;
                *(float *)(iVar13 + 0x50) = fVar7 * fVar8 - fVar9 * fVar10;
                fVar21 = (float10)FUN_005c0240(*(float *)(iVar13 + 0x50) * *(float *)(iVar13 + 0x50)
                                               + *(float *)(iVar13 + 0x48) *
                                                 *(float *)(iVar13 + 0x48) +
                                                 *(float *)(iVar13 + 0x4c) *
                                                 *(float *)(iVar13 + 0x4c));
                if ((float)fVar21 == 0.0) {
                  local_4c = 0.0;
                }
                else {
                  local_4c = 1.0 / (float)fVar21;
                }
                fVar3 = (float)(local_30 + DAT_02924b34);
                *(float *)((int)fVar3 + 0x48) =
                     local_4c * *(float *)(local_30 + 0x48 + DAT_02924b34);
                *(float *)((int)fVar3 + 0x4c) = *(float *)((int)fVar3 + 0x4c) * local_4c;
                *(float *)((int)fVar3 + 0x50) = local_4c * *(float *)((int)fVar3 + 0x50);
                *local_50 = fVar3;
                local_48 = local_48 + 1;
                local_2c = local_2c + 1;
                local_30 = local_30 + 100;
                local_50 = local_50 + 1;
              }
            }
            local_34 = (float)((int)local_34 + -1);
            psVar19 = psVar19 + 0x32;
          } while (0 < (int)local_34);
        }
      } while (-1 < *psVar19);
      if (local_48 != 0) {
        *(undefined2 *)local_24 = (undefined2)local_48;
        *(undefined2 *)(iVar12 + 0x14a) = (undefined2)param_1;
        local_24 = local_50;
      }
    }
  }
  FUN_006de960();
  *(undefined2 *)local_24 = 0;
  *(undefined2 *)((int)local_24 + 2) = 0;
  return;
}

