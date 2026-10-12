/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67cb40; label: FUN_0067cb40
 */

float * FUN_0067cb40(float *param_1,float *param_2,float param_3,int param_4,byte param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  byte bVar11;
  short sVar12;
  uint *puVar13;
  ushort *puVar14;
  float *pfVar15;
  ushort uVar16;
  float *pfVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  uint uVar22;
  float *pfVar23;
  float *pfVar24;
  float *pfVar25;
  float *pfVar26;
  short *psVar27;
  float10 fVar28;
  float10 fVar29;
  float *local_74;
  float local_70;
  float local_68;
  int local_60;
  float local_58;
  short *local_54;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  int local_34;
  float *local_30;
  int local_2c;
  int local_24;
  
  pfVar17 = DAT_02948ed8;
  pfVar23 = DAT_02948ed8 + 1;
  local_2c = 0;
  DAT_02924b34 = DAT_02962b30;
  if ((float *)(DAT_02962b30 + 0x63c18) < pfVar23) {
    return (float *)0x0;
  }
  local_30 = DAT_02948ed8 + 0x1fd;
  if ((float *)(DAT_02962b30 + 0x63da8) < DAT_02948ed8 + 0x1fd) {
    local_30 = (float *)(DAT_02962b30 + 0x63da8);
  }
  iVar18 = FUN_006de8d0(0xd0);
  pfVar26 = (float *)(iVar18 + 0x1fU & 0xfffffff0);
  fVar1 = *param_1;
  local_60 = 0;
  DAT_0292119c = 0;
  if (*param_2 <= 0.0) {
    fVar1 = fVar1 + *param_2;
    fVar2 = *param_1;
  }
  else {
    fVar2 = *param_1 + *param_2;
  }
  local_70 = (fVar1 - 0.02) - param_3;
  fVar2 = fVar2 + 0.02 + param_3;
  fVar1 = param_1[1];
  if (param_2[1] <= 0.0) {
    fVar1 = fVar1 + param_2[1];
    fVar3 = param_1[1];
  }
  else {
    fVar3 = param_1[1] + param_2[1];
  }
  local_58 = (fVar1 - 0.02) - param_3;
  fVar3 = fVar3 + 0.02 + param_3;
  fVar1 = param_1[2];
  if (param_2[2] <= 0.0) {
    fVar1 = fVar1 + param_2[2];
    fVar4 = param_1[2];
  }
  else {
    fVar4 = param_1[2] + param_2[2];
  }
  local_68 = (fVar1 - 0.02) - param_3;
  param_3 = param_3 + fVar4 + 0.02;
  fVar28 = (float10)FUN_005c0240((local_68 - param_3) * (local_68 - param_3) +
                                 (local_70 - fVar2) * (local_70 - fVar2) +
                                 (local_58 - fVar3) * (local_58 - fVar3) + 0.05);
  local_24 = 0;
  pfVar25 = pfVar17;
  local_74 = pfVar23;
  if (0 < DAT_0292fc68[0x6ec]) {
    local_50 = 0;
    piVar21 = DAT_0292fc68;
    do {
      fVar1 = *(float *)((int)piVar21 + local_50 + 0x79c);
      if ((((fVar1 < fVar2 != (fVar1 == fVar2)) &&
           (fVar1 = *(float *)((int)piVar21 + local_50 + 0x7a0),
           fVar1 < param_3 != (fVar1 == param_3))) &&
          (local_70 <= *(float *)((int)piVar21 + local_50 + 0x7a4))) &&
         (local_68 <= *(float *)(local_50 + 0x7a8 + (int)piVar21))) {
        local_54 = (short *)(piVar21[0x6ed] + *(short *)((int)piVar21 + local_50 + 0x798) * 2);
        local_34 = 0;
        if (0 < *(short *)((int)piVar21 + local_50 + 0x79a)) {
          do {
            pfVar24 = (float *)(*piVar21 + *local_54 * 0x38);
            if (((((pfVar24[4] < fVar2 != (pfVar24[4] == fVar2)) &&
                  (pfVar24[5] < fVar3 != (pfVar24[5] == fVar3))) &&
                 ((pfVar24[6] < param_3 != (pfVar24[6] == param_3) &&
                  ((local_70 <= pfVar24[7] && (local_58 < pfVar24[8])))))) &&
                (local_68 < pfVar24[9])) && (pfVar24[0xb] != -NAN)) {
              fVar8 = fVar2 - *pfVar24;
              fVar1 = pfVar24[1];
              fVar7 = param_3 - pfVar24[2];
              fVar4 = *pfVar24;
              fVar5 = pfVar24[1];
              fVar6 = pfVar24[2];
              if (*(short *)(pfVar24 + 0xc) < 0) {
                FUN_0066f790(pfVar24);
                piVar21 = DAT_0292fc68;
              }
              sVar12 = *(short *)pfVar24[3];
              pfVar15 = (float *)pfVar24[3];
              pfVar24 = pfVar23;
              while (-1 < sVar12) {
                iVar18 = (int)*(short *)((int)pfVar15 + 2);
                pfVar23 = pfVar15 + 5;
                if ((((pfVar15[1] < fVar8 == (pfVar15[1] == fVar8)) ||
                     (pfVar15[2] <= local_70 - fVar4)) ||
                    (pfVar15[3] < fVar7 == (pfVar15[3] == fVar7))) ||
                   (pfVar15[4] <= local_68 - fVar6)) {
                  pfVar23 = pfVar23 + iVar18 * 0x19;
                }
                else {
                  for (; 0 < iVar18; iVar18 = iVar18 + -1) {
                    if (((*pfVar23 < fVar8 != (*pfVar23 == fVar8)) &&
                        (local_70 - fVar4 < pfVar23[1])) &&
                       ((((pfVar23[4] < fVar7 != (pfVar23[4] == fVar7) &&
                          ((local_68 - fVar6 < pfVar23[5] &&
                           (pfVar23[2] < fVar3 - fVar1 != (pfVar23[2] == fVar3 - fVar1))))) &&
                         (local_58 - fVar5 < pfVar23[3])) &&
                        ((pfVar24 < local_30 &&
                         ((*(byte *)((int)pfVar23 + 0x61) == 0 ||
                          (pfVar24 = local_74, (param_5 & *(byte *)((int)pfVar23 + 0x61)) != 0))))))
                       )) {
                      *pfVar24 = (float)pfVar23;
                      pfVar24 = pfVar24 + 1;
                      local_60 = local_60 + 1;
                      local_74 = pfVar24;
                    }
                    pfVar23 = pfVar23 + 0x19;
                  }
                }
                pfVar15 = pfVar23;
                piVar21 = DAT_0292fc68;
                sVar12 = *(short *)pfVar23;
              }
              pfVar23 = pfVar24;
              if (local_60 != 0) {
                *(short *)pfVar25 = (short)local_60;
                *(short *)((int)pfVar25 + 2) = *local_54;
                pfVar23 = pfVar24 + 1;
                local_60 = 0;
                piVar21 = DAT_0292fc68;
                pfVar25 = pfVar24;
                local_74 = pfVar23;
              }
            }
            local_54 = local_54 + 1;
            local_34 = local_34 + 1;
          } while (local_34 < *(short *)(local_50 + 0x79a + (int)piVar21));
        }
      }
      local_50 = local_50 + 0x14;
      local_24 = local_24 + 1;
    } while (local_24 < piVar21[0x6ec]);
  }
  local_70 = local_70 - 0.05;
  *(float **)(DAT_0292186c + 0x8c) = pfVar25;
  fVar2 = fVar2 + 0.05;
  local_58 = local_58 - 0.05;
  fVar3 = fVar3 + 0.05;
  local_68 = local_68 - 0.05;
  param_3 = param_3 + 0.05;
  if (param_4 != 0) {
    local_54 = (short *)(DAT_0292fc68[0x6ed] + (short)DAT_0292fc68[0x6e6] * 2);
    local_34 = 0;
    piVar21 = DAT_0292fc68;
    if (0 < *(short *)((int)DAT_0292fc68 + 0x1b9a)) {
      do {
        pfVar23 = (float *)(*piVar21 + *local_54 * 0x38);
        iVar18 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
        puVar13 = *(uint **)(iVar18 + 0x68);
        if (puVar13 == (uint *)0x0) {
LAB_0067d107:
          if (*(int *)(iVar18 + 0x40) == 0) {
            local_48 = fVar2 - *pfVar23;
            local_4c = local_70 - *pfVar23;
            local_3c = fVar3 - pfVar23[1];
            local_38 = local_58 - pfVar23[1];
            local_40 = pfVar23[2];
            local_44 = local_68;
LAB_0067d56f:
            local_40 = param_3 - local_40;
            local_44 = local_44 - pfVar23[2];
          }
          else {
            iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
            if (*(float *)(*(int *)(iVar19 + 0x40) + 0x30) <= *(float *)(iVar19 + 0x30)) {
              local_48 = fVar2 - *pfVar23;
              iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
              local_4c = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x30) - *(float *)(iVar19 + 0x30)) *
                          1.5 + local_70) - *pfVar23;
            }
            else {
              local_4c = local_70 - *pfVar23;
              iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
              local_48 = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x30) - *(float *)(iVar19 + 0x30)) *
                          1.5 + fVar2) - *pfVar23;
            }
            iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
            if (*(float *)(*(int *)(iVar19 + 0x40) + 0x34) <= *(float *)(iVar19 + 0x34)) {
              local_3c = fVar3 - pfVar23[1];
              iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
              local_38 = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x34) - *(float *)(iVar19 + 0x34)) *
                          1.5 + local_58) - pfVar23[1];
            }
            else {
              local_38 = local_58 - pfVar23[1];
              iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
              local_3c = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x34) - *(float *)(iVar19 + 0x34)) *
                          1.5 + fVar3) - pfVar23[1];
            }
            iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
            if (*(float *)(*(int *)(iVar19 + 0x40) + 0x38) <= *(float *)(iVar19 + 0x38)) {
              local_40 = pfVar23[2];
              iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
              local_44 = (*(float *)(*(int *)(iVar19 + 0x40) + 0x38) - *(float *)(iVar19 + 0x38)) *
                         1.5 + local_68;
              goto LAB_0067d56f;
            }
            local_44 = local_68 - pfVar23[2];
            iVar19 = *(short *)(pfVar23 + 0xc) * 0x6c + piVar21[0x1a];
            local_40 = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x38) - *(float *)(iVar19 + 0x38)) *
                        1.5 + param_3) - pfVar23[2];
          }
          if ((*(byte *)(iVar18 + 0x4c) & 1) == 0) {
            if ((((pfVar23[4] < local_48 != (pfVar23[4] == local_48)) &&
                 (pfVar23[5] < local_3c != (pfVar23[5] == local_3c))) &&
                (pfVar23[6] < local_40 != (pfVar23[6] == local_40))) &&
               (((local_4c <= pfVar23[7] && (local_38 < pfVar23[8])) &&
                ((local_44 < pfVar23[9] && (pfVar23[0xb] != -NAN)))))) {
              sVar12 = *(short *)pfVar23[3];
              pfVar23 = (float *)pfVar23[3];
              while (-1 < sVar12) {
                iVar18 = (int)*(short *)((int)pfVar23 + 2);
                pfVar24 = pfVar23 + 5;
                if (((pfVar23[1] < local_48 == (pfVar23[1] == local_48)) || (pfVar23[2] <= local_4c)
                    ) || ((pfVar23[3] < local_40 == (pfVar23[3] == local_40) ||
                          (pfVar23[4] <= local_44)))) {
                  pfVar24 = pfVar24 + iVar18 * 0x19;
                }
                else {
                  for (; 0 < iVar18; iVar18 = iVar18 + -1) {
                    if ((((((*pfVar24 < local_48 != (*pfVar24 == local_48)) &&
                           (local_4c < pfVar24[1])) &&
                          (pfVar24[4] < local_40 != (pfVar24[4] == local_40))) &&
                         ((local_44 < pfVar24[5] &&
                          (pfVar24[2] < local_3c != (pfVar24[2] == local_3c))))) &&
                        (local_38 < pfVar24[3])) &&
                       ((DAT_0292119c = 1, local_74 < local_30 &&
                        ((*(byte *)((int)pfVar24 + 0x61) == 0 ||
                         ((param_5 & *(byte *)((int)pfVar24 + 0x61)) != 0)))))) {
                      *local_74 = (float)pfVar24;
                      local_74 = local_74 + 1;
                      local_60 = local_60 + 1;
                    }
                    pfVar24 = pfVar24 + 0x19;
                  }
                }
                pfVar23 = pfVar24;
                piVar21 = DAT_0292fc68;
                sVar12 = *(short *)pfVar24;
              }
            }
          }
          else if ((pfVar23[0xb] != -NAN) &&
                  (fVar5 = ((fVar3 + local_58) * 0.5 - pfVar23[1]) * *(float *)(DAT_0292186c + 100),
                  fVar1 = (fVar2 + local_70) * 0.5 - *pfVar23,
                  fVar4 = (param_3 + local_68) * 0.5 - pfVar23[2],
                  fVar1 * fVar1 + fVar5 * fVar5 + fVar4 * fVar4 <
                  (pfVar23[0xd] + (float)fVar28) * (pfVar23[0xd] + (float)fVar28))) {
            psVar27 = (short *)pfVar23[3];
            sVar12 = *psVar27;
            while (-1 < sVar12) {
              local_50 = (int)psVar27[1];
              psVar27 = psVar27 + 10;
              if (0 < local_50) {
                local_3c = (float)(local_2c * 100);
                do {
                  DAT_0292119c = 1;
                  if ((local_74 < local_30) &&
                     ((*(byte *)((int)psVar27 + 0x61) == 0 ||
                      ((param_5 & *(byte *)((int)psVar27 + 0x61)) != 0)))) {
                    *pfVar26 = *(float *)(psVar27 + 0xc);
                    pfVar26[1] = *(float *)(psVar27 + 0xe);
                    pfVar26[2] = *(float *)(psVar27 + 0x10);
                    pfVar26[3] = 0.0;
                    pfVar26[4] = *(float *)(psVar27 + 0x12);
                    pfVar26[5] = *(float *)(psVar27 + 0x14);
                    pfVar26[6] = *(float *)(psVar27 + 0x16);
                    pfVar26[7] = 0.0;
                    pfVar26[8] = *(float *)(psVar27 + 0x18);
                    pfVar26[9] = *(float *)(psVar27 + 0x1a);
                    pfVar26[10] = *(float *)(psVar27 + 0x1c);
                    pfVar26[0xb] = 0.0;
                    FUN_005c0620(pfVar26,pfVar26,
                                 *(undefined4 *)
                                  (*(short *)(pfVar23 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
                    pfVar24 = pfVar26 + 0xc;
                    if (65535.0 <= *(float *)(psVar27 + 0x2c)) {
                      *pfVar24 = pfVar26[8];
                      pfVar26[0xd] = pfVar26[9];
                      pfVar26[0xe] = pfVar26[10];
                      pfVar26[0xf] = pfVar26[0xb];
                    }
                    else {
                      *pfVar24 = *(float *)(psVar27 + 0x1e);
                      pfVar26[0xd] = *(float *)(psVar27 + 0x20);
                      pfVar26[0xe] = *(float *)(psVar27 + 0x22);
                      pfVar26[0xf] = 0.0;
                      FUN_005c03e0(pfVar24,pfVar24,
                                   *(undefined4 *)
                                    (*(short *)(pfVar23 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
                    }
                    if (((((local_4c < *pfVar26) || (local_4c < pfVar26[4])) ||
                         (local_4c < pfVar26[8])) || (local_4c < *pfVar24)) &&
                       (((((*pfVar26 < local_48 || (pfVar26[4] < local_48)) ||
                          ((pfVar26[8] < local_48 || (*pfVar24 < local_48)))) &&
                         (((local_44 < pfVar26[2] || (local_44 < pfVar26[6])) ||
                          ((local_44 < pfVar26[10] || (local_44 < pfVar26[0xe])))))) &&
                        ((((pfVar26[2] < local_40 || (pfVar26[6] < local_40)) ||
                          (pfVar26[10] < local_40)) || (pfVar26[0xe] < local_40)))))) {
                      iVar18 = (int)local_3c + DAT_02924b34;
                      *(undefined4 *)(iVar18 + 0x60) = *(undefined4 *)(psVar27 + 0x30);
                      *(float *)(iVar18 + 0x18) = *pfVar26;
                      *(float *)(iVar18 + 0x20) = pfVar26[2];
                      *(float *)(iVar18 + 0x1c) = pfVar26[1];
                      *(float *)(iVar18 + 0x24) = pfVar26[4];
                      *(float *)(iVar18 + 0x2c) = pfVar26[6];
                      *(float *)(iVar18 + 0x28) = pfVar26[5];
                      *(float *)(iVar18 + 0x30) = pfVar26[8];
                      *(float *)(iVar18 + 0x38) = pfVar26[10];
                      *(float *)(iVar18 + 0x34) = pfVar26[9];
                      if (65535.0 <= *(float *)(psVar27 + 0x2c)) {
                        *(undefined4 *)(iVar18 + 0x58) = 0x47800000;
                      }
                      else {
                        *(float *)(iVar18 + 0x3c) = *pfVar24;
                        *(float *)(iVar18 + 0x44) = pfVar26[0xe];
                        *(float *)(iVar18 + 0x40) = pfVar26[0xd];
                        *pfVar26 = *(float *)(iVar18 + 0x24) - *(float *)(iVar18 + 0x3c);
                        pfVar26[1] = *(float *)(iVar18 + 0x28) - *(float *)(iVar18 + 0x40);
                        pfVar26[2] = *(float *)(iVar18 + 0x2c) - *(float *)(iVar18 + 0x44);
                        pfVar26[4] = *(float *)(iVar18 + 0x30) - *(float *)(iVar18 + 0x3c);
                        pfVar26[5] = *(float *)(iVar18 + 0x34) - *(float *)(iVar18 + 0x40);
                        pfVar26[6] = *(float *)(iVar18 + 0x38) - *(float *)(iVar18 + 0x44);
                        fVar1 = pfVar26[4];
                        fVar4 = pfVar26[2];
                        fVar5 = pfVar26[6];
                        fVar6 = *pfVar26;
                        fVar7 = *pfVar26;
                        fVar8 = pfVar26[5];
                        fVar9 = pfVar26[1];
                        fVar10 = pfVar26[4];
                        *(float *)(iVar18 + 0x54) =
                             pfVar26[1] * pfVar26[6] - pfVar26[5] * pfVar26[2];
                        *(float *)(iVar18 + 0x58) = fVar1 * fVar4 - fVar5 * fVar6;
                        *(float *)(iVar18 + 0x5c) = fVar7 * fVar8 - fVar9 * fVar10;
                        fVar29 = (float10)FUN_005c0240(*(float *)(iVar18 + 0x5c) *
                                                       *(float *)(iVar18 + 0x5c) +
                                                       *(float *)(iVar18 + 0x54) *
                                                       *(float *)(iVar18 + 0x54) +
                                                       *(float *)(iVar18 + 0x58) *
                                                       *(float *)(iVar18 + 0x58));
                        if ((float)fVar29 == 0.0) {
                          fVar1 = 0.0;
                        }
                        else {
                          fVar1 = 1.0 / (float)fVar29;
                        }
                        iVar18 = DAT_02924b34 + (int)local_3c;
                        *(float *)(iVar18 + 0x54) = fVar1 * *(float *)(iVar18 + 0x54);
                        *(float *)(iVar18 + 0x58) = fVar1 * *(float *)(iVar18 + 0x58);
                        *(float *)(iVar18 + 0x5c) = fVar1 * *(float *)(iVar18 + 0x5c);
                      }
                      *pfVar26 = *(float *)(iVar18 + 0x30) - *(float *)(iVar18 + 0x18);
                      pfVar26[1] = *(float *)(iVar18 + 0x34) - *(float *)(iVar18 + 0x1c);
                      pfVar26[2] = *(float *)(iVar18 + 0x38) - *(float *)(iVar18 + 0x20);
                      pfVar26[4] = *(float *)(iVar18 + 0x24) - *(float *)(iVar18 + 0x18);
                      pfVar26[5] = *(float *)(iVar18 + 0x28) - *(float *)(iVar18 + 0x1c);
                      pfVar26[6] = *(float *)(iVar18 + 0x2c) - *(float *)(iVar18 + 0x20);
                      fVar1 = pfVar26[4];
                      fVar4 = pfVar26[2];
                      fVar5 = *pfVar26;
                      fVar6 = pfVar26[6];
                      fVar7 = pfVar26[5];
                      fVar8 = *pfVar26;
                      fVar9 = pfVar26[1];
                      fVar10 = pfVar26[4];
                      *(float *)(iVar18 + 0x48) = pfVar26[1] * pfVar26[6] - pfVar26[5] * pfVar26[2];
                      *(float *)(iVar18 + 0x4c) = fVar1 * fVar4 - fVar5 * fVar6;
                      *(float *)(iVar18 + 0x50) = fVar7 * fVar8 - fVar9 * fVar10;
                      fVar29 = (float10)FUN_005c0240(*(float *)(iVar18 + 0x50) *
                                                     *(float *)(iVar18 + 0x50) +
                                                     *(float *)(iVar18 + 0x48) *
                                                     *(float *)(iVar18 + 0x48) +
                                                     *(float *)(iVar18 + 0x4c) *
                                                     *(float *)(iVar18 + 0x4c));
                      if ((float)fVar29 == 0.0) {
                        local_38 = 0.0;
                      }
                      else {
                        local_38 = 1.0 / (float)fVar29;
                      }
                      fVar1 = (float)((int)local_3c + DAT_02924b34);
                      *(float *)((int)fVar1 + 0x48) =
                           local_38 * *(float *)((int)local_3c + 0x48 + DAT_02924b34);
                      *(float *)((int)fVar1 + 0x4c) = *(float *)((int)fVar1 + 0x4c) * local_38;
                      *(float *)((int)fVar1 + 0x50) = local_38 * *(float *)((int)fVar1 + 0x50);
                      *local_74 = fVar1;
                      local_60 = local_60 + 1;
                      local_2c = local_2c + 1;
                      local_3c = (float)((int)local_3c + 100);
                      local_74 = local_74 + 1;
                    }
                  }
                  local_50 = local_50 + -1;
                  psVar27 = psVar27 + 0x32;
                } while (0 < local_50);
              }
              piVar21 = DAT_0292fc68;
              sVar12 = *psVar27;
            }
          }
        }
        else if ((*(byte *)(iVar18 + 0x4c) & 4) == 0) {
          if ((*puVar13 & 1) != 0) goto LAB_0067d107;
        }
        else if ((*puVar13 & 2) != 0) goto LAB_0067d107;
        if (local_60 != 0) {
          *(short *)pfVar25 = (short)local_60;
          *(short *)((int)pfVar25 + 2) = *local_54;
          local_60 = 0;
          pfVar25 = local_74;
          piVar21 = DAT_0292fc68;
          local_74 = local_74 + 1;
        }
        local_54 = local_54 + 1;
        local_34 = local_34 + 1;
      } while (local_34 < *(short *)((int)piVar21 + 0x1b9a));
    }
  }
  local_70 = local_70 - 0.02;
  *(undefined2 *)pfVar25 = 0;
  *(undefined2 *)((int)pfVar25 + 2) = 0;
  puVar14 = (ushort *)DAT_0292fc68[0x52];
  local_68 = local_68 - 0.02;
  fVar2 = fVar2 + 0.02;
  param_3 = param_3 + 0.02;
  do {
    if (puVar14 == (ushort *)0x0) {
      *(undefined2 *)(pfVar25 + 1) = 0;
      *(undefined2 *)((int)pfVar25 + 6) = 0;
      DAT_02948ed8 = pfVar25 + 2;
      FUN_006de960();
      return pfVar17;
    }
    bVar11 = *(byte *)((int)puVar14 + 3);
    if ((bVar11 == 0) || ((param_5 & bVar11) != 0)) {
      uVar16 = puVar14[1];
      uVar22 = (uint)*puVar14;
      iVar18 = 0;
      if (uVar22 != 0) {
        pfVar23 = (float *)(puVar14 + 4);
        do {
          if (*pfVar23 == 2.1474836e+09) {
LAB_0067d2c1:
            uVar20 = uVar22;
          }
          else if (((pfVar23[3] < local_70) || (*pfVar23 < fVar2 == (*pfVar23 == fVar2))) ||
                  ((pfVar23[9] < local_68 || (pfVar23[6] < param_3 == (pfVar23[6] == param_3))))) {
            uVar20 = 0;
          }
          else {
            uVar20 = iVar18 + 0x10U;
            if ((int)uVar22 < (int)(iVar18 + 0x10U)) goto LAB_0067d2c1;
          }
          if (iVar18 < (int)uVar20) {
            iVar19 = uVar20 - iVar18;
            pfVar26 = pfVar23 + 1;
            do {
              if (((((local_70 <= pfVar26[-2]) && (pfVar26[1] < fVar2 != (pfVar26[1] == fVar2))) ||
                   ((local_70 <= pfVar26[1] && (pfVar26[-2] < fVar2 != (pfVar26[-2] == fVar2))))) &&
                  (((local_68 <= *pfVar26 && (pfVar26[3] < param_3 != (pfVar26[3] == param_3))) ||
                   ((local_68 <= pfVar26[3] && (*pfVar26 < param_3 != (*pfVar26 == param_3))))))) &&
                 (DAT_02924ab8 < 0x40)) {
                pfVar24 = (float *)pfVar25[1];
                *pfVar24 = pfVar26[-2];
                pfVar24[1] = pfVar26[-1];
                pfVar24[2] = *pfVar26;
                *(char *)((int)pfVar25[1] + 0xc) = (char)uVar16;
                *(byte *)((int)pfVar25[1] + 0xd) = bVar11;
                *(undefined1 *)((int)pfVar25[1] + 0xe) = 0;
                *(undefined1 *)((int)pfVar25[1] + 0xf) = 0;
                pfVar25[1] = (float)((int)pfVar25[1] + 0x10);
                pfVar24 = (float *)pfVar25[1];
                *pfVar24 = pfVar26[1];
                pfVar24[1] = pfVar26[2];
                pfVar24[2] = pfVar26[3];
                *(char *)((int)pfVar25[1] + 0xc) = (char)uVar16;
                *(byte *)((int)pfVar25[1] + 0xd) = bVar11;
                *(undefined1 *)((int)pfVar25[1] + 0xe) = 0;
                *(undefined1 *)((int)pfVar25[1] + 0xf) = 0;
                pfVar25[1] = (float)((int)pfVar25[1] + 0x10);
              }
              pfVar26 = pfVar26 + 3;
              iVar19 = iVar19 + -1;
            } while (iVar19 != 0);
          }
          uVar22 = (uint)*puVar14;
          iVar18 = iVar18 + 0x10;
          pfVar23 = pfVar23 + 0x30;
        } while (iVar18 < (int)uVar22);
      }
    }
    puVar14 = *(ushort **)(puVar14 + -2);
  } while( true );
}

