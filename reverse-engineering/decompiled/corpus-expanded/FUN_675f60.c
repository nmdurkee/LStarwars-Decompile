/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x675f60; label: FUN_00675f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00675f60(int param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  byte bVar7;
  short sVar8;
  int iVar9;
  uint *puVar10;
  ushort *puVar11;
  float fVar12;
  float fVar13;
  int iVar14;
  ushort uVar15;
  float *pfVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  float *pfVar20;
  int *piVar21;
  float *pfVar22;
  int iVar23;
  short *psVar24;
  float *pfVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  float10 fVar29;
  float *local_c0;
  int local_bc;
  int local_b8;
  float local_b4;
  int local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  int local_9c;
  float local_98;
  float local_94;
  float local_90;
  int local_8c;
  float local_88;
  float local_84;
  float local_80;
  int local_7c;
  float *local_78;
  float local_74;
  float local_70;
  short *local_6c;
  int local_64;
  float local_60;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar28 = DAT_0292186c;
  local_9c = 0;
  if (DAT_02962b2c != 0) {
    FUN_00675840(param_1,param_2,param_3);
    return;
  }
  DAT_02924b34 = DAT_02962b30;
  local_c0 = (float *)(DAT_0292186c + 0x14c);
  pfVar16 = (float *)(DAT_0292186c + 0x93c);
  local_78 = (float *)(DAT_0292186c + 0x148);
  *(undefined2 *)(DAT_0292186c + 0x8a) = 0xffff;
  iVar9 = *DAT_0292fc68;
  local_bc = 0;
  DAT_0292119c = 0;
  if (*(char *)(iVar28 + 0x34) == '\x01') {
    if (*(float *)(iVar28 + 0x28) <= 0.0) {
      local_a4 = ((*(float *)(iVar28 + 0x1c) + *(float *)(iVar28 + 0x28)) - 0.02) -
                 *(float *)(iVar28 + 0x50);
      fVar1 = *(float *)(iVar28 + 0x1c);
    }
    else {
      local_a4 = (*(float *)(iVar28 + 0x1c) - 0.02) - *(float *)(iVar28 + 0x50);
      fVar1 = *(float *)(iVar28 + 0x1c) + *(float *)(iVar28 + 0x28);
    }
    local_a0 = fVar1 + 0.02 + *(float *)(iVar28 + 0x50);
    if (*(float *)(iVar28 + 0x2c) <= 0.0) {
      local_80 = ((*(float *)(iVar28 + 0x20) + *(float *)(iVar28 + 0x2c)) - 0.02) -
                 *(float *)(iVar28 + 0x50);
      fVar1 = *(float *)(iVar28 + 0x20);
    }
    else {
      local_80 = (*(float *)(iVar28 + 0x20) - 0.02) - *(float *)(iVar28 + 0x50);
      fVar1 = *(float *)(iVar28 + 0x20) + *(float *)(iVar28 + 0x2c);
    }
    local_94 = fVar1 + 0.02 + *(float *)(iVar28 + 0x50);
    if (*(float *)(iVar28 + 0x30) <= 0.0) {
      local_a8 = ((*(float *)(iVar28 + 0x30) + *(float *)(iVar28 + 0x24)) - 0.02) -
                 *(float *)(iVar28 + 0x50);
      fVar1 = *(float *)(iVar28 + 0x24);
    }
    else {
      local_a8 = (*(float *)(iVar28 + 0x24) - 0.02) - *(float *)(iVar28 + 0x50);
      fVar1 = *(float *)(iVar28 + 0x30) + *(float *)(iVar28 + 0x24);
    }
    local_ac = fVar1 + 0.02 + *(float *)(iVar28 + 0x50);
    fVar29 = (float10)FUN_005c0240((local_a8 - local_ac) * (local_a8 - local_ac) +
                                   (local_a4 - local_a0) * (local_a4 - local_a0) +
                                   (local_80 - local_94) * (local_80 - local_94));
    local_60 = (float)fVar29;
  }
  else {
    fVar29 = (float10)FUN_005c0240(*(float *)(iVar28 + 0x30) * *(float *)(iVar28 + 0x30) +
                                   *(float *)(iVar28 + 0x28) * *(float *)(iVar28 + 0x28) +
                                   *(float *)(iVar28 + 0x2c) * *(float *)(iVar28 + 0x2c));
    local_60 = *(float *)(DAT_0292186c + 0x50) + 0.1 + (float)fVar29;
    local_a0 = local_60 + *(float *)(DAT_0292186c + 0x1c) + 0.05;
    local_80 = *(float *)(DAT_0292186c + 0x5c) * local_60;
    local_94 = *(float *)(DAT_0292186c + 0x20) + 0.05 + local_80;
    local_ac = *(float *)(DAT_0292186c + 0x24) + 0.05 + local_60;
    local_a4 = (*(float *)(DAT_0292186c + 0x1c) - 0.05) - local_60;
    local_80 = (*(float *)(DAT_0292186c + 0x20) - 0.05) - local_80;
    local_a8 = (*(float *)(DAT_0292186c + 0x24) - 0.05) - local_60;
  }
  if (1.0 < *(float *)(DAT_0292186c + 0x5c)) {
    local_60 = (*(float *)(DAT_0292186c + 0x5c) - 1.0) * *(float *)(DAT_0292186c + 0x50) + local_60;
  }
  local_7c = 0;
  iVar28 = DAT_02924b34;
  piVar21 = DAT_0292fc68;
  iVar23 = DAT_0292186c;
  if (0 < DAT_0292fc68[0x6ec]) {
    local_b0 = 0;
    do {
      fVar1 = *(float *)((int)piVar21 + local_b0 + 0x79c);
      if ((((fVar1 < local_a0 != (fVar1 == local_a0)) &&
           (fVar1 = *(float *)((int)piVar21 + local_b0 + 0x7a0),
           fVar1 < local_ac != (fVar1 == local_ac))) &&
          (local_a4 <= *(float *)((int)piVar21 + local_b0 + 0x7a4))) &&
         (local_a8 <= *(float *)(local_b0 + 0x7a8 + (int)piVar21))) {
        local_6c = (short *)(piVar21[0x6ed] + *(short *)((int)piVar21 + local_b0 + 0x798) * 2);
        local_b8 = 0;
        if (0 < *(short *)((int)piVar21 + local_b0 + 0x79a)) {
          do {
            pfVar22 = (float *)(iVar9 + *local_6c * 0x38);
            pfVar20 = local_c0;
            if ((((pfVar22[4] < local_a0 != (pfVar22[4] == local_a0)) &&
                 (pfVar22[5] < local_94 != (pfVar22[5] == local_94))) &&
                ((pfVar22[6] < local_ac != (pfVar22[6] == local_ac) &&
                 ((local_a4 <= pfVar22[7] && (local_80 < pfVar22[8])))))) &&
               ((local_a8 < pfVar22[9] && (pfVar22[0xb] != -NAN)))) {
              fVar12 = local_a0 - *pfVar22;
              fVar1 = pfVar22[1];
              fVar13 = local_ac - pfVar22[2];
              fVar6 = *pfVar22;
              fVar2 = pfVar22[1];
              fVar3 = pfVar22[2];
              if (*(short *)(pfVar22 + 0xc) < 0) {
                FUN_0066f790(pfVar22);
                iVar28 = DAT_02924b34;
                piVar21 = DAT_0292fc68;
                iVar23 = DAT_0292186c;
              }
              sVar8 = *(short *)pfVar22[3];
              pfVar20 = (float *)pfVar22[3];
              while (-1 < sVar8) {
                local_8c = (int)*(short *)((int)pfVar20 + 2);
                pfVar25 = pfVar20 + 5;
                if ((((pfVar20[1] < fVar12 == (pfVar20[1] == fVar12)) ||
                     (pfVar20[2] <= local_a4 - fVar6)) ||
                    (pfVar20[3] < fVar13 == (pfVar20[3] == fVar13))) ||
                   (pfVar20[4] <= local_a8 - fVar3)) {
                  pfVar25 = pfVar25 + local_8c * 0x19;
                }
                else if (0 < local_8c) {
                  iVar26 = local_9c * 100;
                  do {
                    if ((((*pfVar25 < fVar12 != (*pfVar25 == fVar12)) &&
                         (local_a4 - fVar6 < pfVar25[1])) &&
                        ((pfVar25[4] < fVar13 != (pfVar25[4] == fVar13) &&
                         ((local_a8 - fVar3 < pfVar25[5] &&
                          (pfVar25[2] < local_94 - fVar1 != (pfVar25[2] == local_94 - fVar1)))))))
                       && ((local_80 - fVar2 < pfVar25[3] &&
                           ((local_c0 < pfVar16 &&
                            (((*(byte *)((int)pfVar25 + 0x61) == 0 ||
                              (((byte)param_2 & *(byte *)((int)pfVar25 + 0x61)) != 0)) &&
                             ((*(byte *)((int)pfVar25 + 0x62) & (byte)param_3) != 0x40)))))))) {
                      if (*(float *)(iVar23 + 0x5c) == 1.0) {
                        *local_c0 = (float)pfVar25;
                        local_bc = local_bc + 1;
                        local_c0 = local_c0 + 1;
                      }
                      else {
                        *(undefined1 *)(iVar26 + 0x60 + iVar28) = *(undefined1 *)(pfVar25 + 0x18);
                        *(undefined1 *)(iVar26 + 0x61 + iVar28) =
                             *(undefined1 *)((int)pfVar25 + 0x61);
                        *(undefined1 *)(iVar26 + 0x62 + iVar28) =
                             *(undefined1 *)((int)pfVar25 + 0x62);
                        *(undefined1 *)(iVar26 + 99 + iVar28) = *(undefined1 *)((int)pfVar25 + 99);
                        *(float *)(iVar26 + 0x18 + iVar28) = pfVar25[6];
                        *(float *)(iVar26 + 0x20 + iVar28) = pfVar25[8];
                        *(float *)(iVar26 + 0x1c + iVar28) =
                             (pfVar25[7] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                        *(float *)(iVar26 + 0x24 + iVar28) = pfVar25[9];
                        *(float *)(iVar26 + 0x2c + iVar28) = pfVar25[0xb];
                        *(float *)(iVar26 + 0x28 + iVar28) =
                             (pfVar25[10] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                        *(float *)(iVar26 + 0x30 + iVar28) = pfVar25[0xc];
                        *(float *)(iVar26 + 0x38 + iVar28) = pfVar25[0xe];
                        *(float *)(iVar26 + 0x34 + iVar28) =
                             (pfVar25[0xd] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                        if (65535.0 <= pfVar25[0x16]) {
                          *(undefined4 *)(iVar26 + 0x58 + iVar28) = 0x47800000;
                        }
                        else {
                          *(float *)(iVar26 + 0x3c + iVar28) = pfVar25[0xf];
                          *(float *)(iVar26 + 0x44 + iVar28) = pfVar25[0x11];
                          *(float *)(iVar26 + 0x40 + iVar28) =
                               (pfVar25[0x10] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                          fVar29 = (float10)FUN_005c0240(*(float *)(iVar23 + 0x60) *
                                                         pfVar25[0x16] * pfVar25[0x16] +
                                                         pfVar25[0x15] * pfVar25[0x15] +
                                                         pfVar25[0x17] * pfVar25[0x17]);
                          fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                          iVar28 = DAT_02924b34;
                          iVar23 = DAT_0292186c;
                          fVar4 = (float)fVar29;
                          *(float *)(iVar26 + 0x54 + DAT_02924b34) = fVar4 * pfVar25[0x15];
                          *(float *)(iVar26 + 0x58 + iVar28) =
                               *(float *)(iVar23 + 0x5c) * pfVar25[0x16] * fVar4;
                          *(float *)(iVar26 + 0x5c + iVar28) = fVar4 * pfVar25[0x17];
                        }
                        fVar29 = (float10)FUN_005c0240(*(float *)(iVar23 + 0x60) *
                                                       pfVar25[0x13] * pfVar25[0x13] +
                                                       pfVar25[0x12] * pfVar25[0x12] +
                                                       pfVar25[0x14] * pfVar25[0x14]);
                        fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                        iVar28 = DAT_02924b34;
                        iVar23 = DAT_0292186c;
                        fVar5 = (float)fVar29;
                        fVar4 = (float)(iVar26 + DAT_02924b34);
                        *(float *)((int)fVar4 + 0x48) = fVar5 * pfVar25[0x12];
                        *(float *)((int)fVar4 + 0x4c) =
                             *(float *)(iVar23 + 0x5c) * pfVar25[0x13] * fVar5;
                        *(float *)((int)fVar4 + 0x50) = fVar5 * pfVar25[0x14];
                        *local_c0 = fVar4;
                        local_bc = local_bc + 1;
                        local_9c = local_9c + 1;
                        iVar26 = iVar26 + 100;
                        local_c0 = local_c0 + 1;
                      }
                    }
                    local_8c = local_8c + -1;
                    pfVar25 = pfVar25 + 0x19;
                  } while (0 < local_8c);
                }
                pfVar20 = pfVar25;
                piVar21 = DAT_0292fc68;
                sVar8 = *(short *)pfVar25;
              }
              pfVar20 = local_c0;
              if (local_bc != 0) {
                *(short *)local_78 = (short)local_bc;
                *(short *)((int)local_78 + 2) = *local_6c;
                local_bc = 0;
                piVar21 = DAT_0292fc68;
                pfVar20 = local_c0 + 1;
                local_78 = local_c0;
              }
            }
            local_c0 = pfVar20;
            local_6c = local_6c + 1;
            local_b8 = local_b8 + 1;
          } while (local_b8 < *(short *)(local_b0 + 0x79a + (int)piVar21));
        }
      }
      local_b0 = local_b0 + 0x14;
      local_7c = local_7c + 1;
    } while (local_7c < piVar21[0x6ec]);
  }
  if ((DAT_02961f50 != 0) && (local_7c = 0, iVar26 = DAT_02961f50, 0 < DAT_02961f50)) {
    do {
      fVar6 = local_a0 - *(float *)(iVar9 + (piVar21[0x2922] + local_7c) * 0x38);
      pfVar22 = (float *)(iVar9 + (piVar21[0x2922] + local_7c) * 0x38);
      fVar2 = local_94 - pfVar22[1];
      fVar3 = local_ac - pfVar22[2];
      fVar12 = local_a4 - *pfVar22;
      fVar1 = pfVar22[1];
      fVar13 = local_a8 - pfVar22[2];
      pfVar20 = local_c0;
      if ((((pfVar22[4] < fVar6 != (pfVar22[4] == fVar6)) &&
           ((pfVar22[5] < fVar2 != (pfVar22[5] == fVar2) &&
            (pfVar22[6] < fVar3 != (pfVar22[6] == fVar3))))) && (fVar12 <= pfVar22[7])) &&
         (((local_80 - fVar1 < pfVar22[8] && (fVar13 < pfVar22[9])) && (pfVar22[0xb] != -NAN)))) {
        sVar8 = *(short *)pfVar22[3];
        pfVar20 = (float *)pfVar22[3];
        while (-1 < sVar8) {
          local_8c = (int)*(short *)((int)pfVar20 + 2);
          pfVar25 = pfVar20 + 5;
          if (((pfVar20[1] < fVar6 == (pfVar20[1] == fVar6)) || (pfVar20[2] <= fVar12)) ||
             ((pfVar20[3] < fVar3 == (pfVar20[3] == fVar3) || (pfVar20[4] <= fVar13)))) {
            pfVar25 = pfVar25 + local_8c * 0x19;
          }
          else if (0 < local_8c) {
            iVar26 = local_9c * 100;
            do {
              if ((((*pfVar25 < fVar6 != (*pfVar25 == fVar6)) && (fVar12 < pfVar25[1])) &&
                  ((pfVar25[4] < fVar3 != (pfVar25[4] == fVar3) &&
                   (((((fVar13 < pfVar25[5] && (pfVar25[2] < fVar2 != (pfVar25[2] == fVar2))) &&
                      (local_80 - fVar1 < pfVar25[3])) && (local_c0 < pfVar16)) &&
                    ((*(byte *)((int)pfVar25 + 0x61) == 0 ||
                     (((byte)param_2 & *(byte *)((int)pfVar25 + 0x61)) != 0)))))))) &&
                 ((*(byte *)((int)pfVar25 + 0x62) & (byte)param_3) != 0x40)) {
                if (*(float *)(iVar23 + 0x5c) == 1.0) {
                  *local_c0 = (float)pfVar25;
                  local_bc = local_bc + 1;
                  local_c0 = local_c0 + 1;
                }
                else {
                  *(undefined1 *)(iVar26 + 0x60 + iVar28) = *(undefined1 *)(pfVar25 + 0x18);
                  *(undefined1 *)(iVar26 + 0x61 + iVar28) = *(undefined1 *)((int)pfVar25 + 0x61);
                  *(undefined1 *)(iVar26 + 0x62 + iVar28) = *(undefined1 *)((int)pfVar25 + 0x62);
                  *(undefined1 *)(iVar26 + 99 + iVar28) = *(undefined1 *)((int)pfVar25 + 99);
                  *(float *)(iVar26 + 0x18 + iVar28) = pfVar25[6];
                  *(float *)(iVar26 + 0x20 + iVar28) = pfVar25[8];
                  *(float *)(iVar26 + 0x1c + iVar28) =
                       (pfVar25[7] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                  *(float *)(iVar26 + 0x24 + iVar28) = pfVar25[9];
                  *(float *)(iVar26 + 0x2c + iVar28) = pfVar25[0xb];
                  *(float *)(iVar26 + 0x28 + iVar28) =
                       (pfVar25[10] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                  *(float *)(iVar26 + 0x30 + iVar28) = pfVar25[0xc];
                  *(float *)(iVar26 + 0x38 + iVar28) = pfVar25[0xe];
                  *(float *)(iVar26 + 0x34 + iVar28) =
                       (pfVar25[0xd] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                  if (65535.0 <= pfVar25[0x16]) {
                    *(undefined4 *)(iVar26 + 0x58 + iVar28) = 0x47800000;
                  }
                  else {
                    *(float *)(iVar26 + 0x3c + iVar28) = pfVar25[0xf];
                    *(float *)(iVar26 + 0x44 + iVar28) = pfVar25[0x11];
                    *(float *)(iVar26 + 0x40 + iVar28) =
                         (pfVar25[0x10] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                    fVar29 = (float10)FUN_005c0240(*(float *)(iVar23 + 0x60) *
                                                   pfVar25[0x16] * pfVar25[0x16] +
                                                   pfVar25[0x15] * pfVar25[0x15] +
                                                   pfVar25[0x17] * pfVar25[0x17]);
                    fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                    iVar28 = DAT_02924b34;
                    iVar23 = DAT_0292186c;
                    fVar4 = (float)fVar29;
                    *(float *)(iVar26 + 0x54 + DAT_02924b34) = fVar4 * pfVar25[0x15];
                    *(float *)(iVar26 + 0x58 + iVar28) =
                         *(float *)(iVar23 + 0x5c) * pfVar25[0x16] * fVar4;
                    *(float *)(iVar26 + 0x5c + iVar28) = fVar4 * pfVar25[0x17];
                  }
                  fVar29 = (float10)FUN_005c0240(*(float *)(iVar23 + 0x60) *
                                                 pfVar25[0x13] * pfVar25[0x13] +
                                                 pfVar25[0x12] * pfVar25[0x12] +
                                                 pfVar25[0x14] * pfVar25[0x14]);
                  fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                  iVar28 = DAT_02924b34;
                  iVar23 = DAT_0292186c;
                  fVar5 = (float)fVar29;
                  fVar4 = (float)(iVar26 + DAT_02924b34);
                  *(float *)((int)fVar4 + 0x48) = fVar5 * pfVar25[0x12];
                  *(float *)((int)fVar4 + 0x4c) = *(float *)(iVar23 + 0x5c) * pfVar25[0x13] * fVar5;
                  *(float *)((int)fVar4 + 0x50) = fVar5 * pfVar25[0x14];
                  *local_c0 = fVar4;
                  local_bc = local_bc + 1;
                  local_9c = local_9c + 1;
                  iVar26 = iVar26 + 100;
                  local_c0 = local_c0 + 1;
                }
              }
              local_8c = local_8c + -1;
              pfVar25 = pfVar25 + 0x19;
            } while (0 < local_8c);
          }
          pfVar20 = pfVar25;
          piVar21 = DAT_0292fc68;
          iVar26 = DAT_02961f50;
          sVar8 = *(short *)pfVar25;
        }
        pfVar20 = local_c0;
        if (local_bc != 0) {
          *(short *)local_78 = (short)local_bc;
          local_bc = 0;
          *(short *)((int)local_78 + 2) = (short)DAT_0292fc68[0x2922] + (short)local_7c;
          piVar21 = DAT_0292fc68;
          pfVar20 = local_c0 + 1;
          local_78 = local_c0;
        }
      }
      local_c0 = pfVar20;
      local_7c = local_7c + 1;
    } while (local_7c < iVar26);
  }
  local_a4 = local_a4 - 0.05;
  *(float **)(iVar23 + 0x8c) = local_78;
  local_a0 = local_a0 + 0.05;
  local_80 = local_80 - 0.05;
  local_94 = local_94 + 0.05;
  local_a8 = local_a8 - 0.05;
  local_ac = local_ac + 0.05;
  if (param_1 != 0) {
    if (((local_a4 <= (float)DAT_0292fc68[0x4c]) || ((float)DAT_0292fc68[0x4f] <= local_a0)) ||
       ((local_a8 <= (float)DAT_0292fc68[0x4e] || ((float)DAT_0292fc68[0x51] <= local_ac)))) {
      iVar26 = (int)*(short *)((int)DAT_0292fc68 + 0x1b9a);
      piVar21 = (int *)(DAT_0292fc68[0x6ed] + (short)DAT_0292fc68[0x6e6] * 2);
    }
    else {
      piVar21 = DAT_0292fc68 + 0x1b;
      iVar26 = DAT_0292fc68[0x4b];
    }
    for (; 0 < iVar26; iVar26 = iVar26 + -1) {
      iVar14 = *piVar21;
      pfVar22 = (float *)(iVar9 + (short)iVar14 * 0x38);
      if ((((local_a0 < *pfVar22 - pfVar22[0xd]) || (pfVar22[0xd] + *pfVar22 < local_a4)) ||
          (local_ac < pfVar22[2] - pfVar22[0xd])) || (pfVar22[0xd] + pfVar22[2] < local_a8))
      goto LAB_00677a27;
      iVar27 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
      puVar10 = *(uint **)(iVar27 + 0x68);
      if (puVar10 == (uint *)0x0) {
LAB_00676d84:
        if (*(int *)(iVar27 + 0x40) == 0) {
          local_98 = local_a0 - *pfVar22;
          local_90 = local_a4 - *pfVar22;
          local_70 = local_94 - pfVar22[1];
          local_74 = local_80 - pfVar22[1];
          local_88 = pfVar22[2];
          local_84 = local_a8;
LAB_00676f02:
          local_88 = local_ac - local_88;
          local_84 = local_84 - pfVar22[2];
        }
        else {
          iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
          if (*(float *)(*(int *)(iVar17 + 0x40) + 0x30) <= *(float *)(iVar17 + 0x30)) {
            local_98 = local_a0 - *pfVar22;
            iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
            local_90 = ((*(float *)(*(int *)(iVar17 + 0x40) + 0x30) - *(float *)(iVar17 + 0x30)) +
                       local_a4) - *pfVar22;
          }
          else {
            local_90 = local_a4 - *pfVar22;
            iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
            local_98 = ((*(float *)(*(int *)(iVar17 + 0x40) + 0x30) - *(float *)(iVar17 + 0x30)) +
                       local_a0) - *pfVar22;
          }
          iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
          if (*(float *)(*(int *)(iVar17 + 0x40) + 0x34) <= *(float *)(iVar17 + 0x34)) {
            local_70 = local_94 - pfVar22[1];
            iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
            local_74 = ((*(float *)(*(int *)(iVar17 + 0x40) + 0x34) - *(float *)(iVar17 + 0x34)) +
                       local_80) - pfVar22[1];
          }
          else {
            local_74 = local_80 - pfVar22[1];
            iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
            local_70 = ((*(float *)(*(int *)(iVar17 + 0x40) + 0x34) - *(float *)(iVar17 + 0x34)) +
                       local_94) - pfVar22[1];
          }
          iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
          if (*(float *)(*(int *)(iVar17 + 0x40) + 0x38) <= *(float *)(iVar17 + 0x38)) {
            local_88 = pfVar22[2];
            iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
            local_84 = (*(float *)(*(int *)(iVar17 + 0x40) + 0x38) - *(float *)(iVar17 + 0x38)) +
                       local_a8;
            goto LAB_00676f02;
          }
          local_84 = local_a8 - pfVar22[2];
          iVar17 = *(short *)(pfVar22 + 0xc) * 0x6c + DAT_0292fc68[0x1a];
          local_88 = ((*(float *)(*(int *)(iVar17 + 0x40) + 0x38) - *(float *)(iVar17 + 0x38)) +
                     local_ac) - pfVar22[2];
        }
        if ((*(byte *)(iVar27 + 0x4c) & 1) == 0) {
          if (((pfVar22[4] < local_98 != (pfVar22[4] == local_98)) &&
              (pfVar22[5] < local_70 != (pfVar22[5] == local_70))) &&
             (((pfVar22[6] < local_88 != (pfVar22[6] == local_88) &&
               ((local_90 <= pfVar22[7] && (local_74 < pfVar22[8])))) &&
              ((local_84 < pfVar22[9] && (pfVar22[0xb] != -NAN)))))) {
            sVar8 = *(short *)pfVar22[3];
            pfVar20 = (float *)pfVar22[3];
            while (-1 < sVar8) {
              local_8c = (int)*(short *)((int)pfVar20 + 2);
              pfVar25 = pfVar20 + 5;
              if ((((pfVar20[1] < local_98 == (pfVar20[1] == local_98)) || (pfVar20[2] <= local_90))
                  || (pfVar20[3] < local_88 == (pfVar20[3] == local_88))) ||
                 (pfVar20[4] <= local_84)) {
                pfVar25 = pfVar25 + local_8c * 0x19;
              }
              else if (0 < local_8c) {
                iVar27 = local_9c * 100;
                do {
                  if (((((*pfVar25 < local_98 != (*pfVar25 == local_98)) && (local_90 < pfVar25[1]))
                       && ((pfVar25[4] < local_88 != (pfVar25[4] == local_88) &&
                           ((local_84 < pfVar25[5] &&
                            (pfVar25[2] < local_70 != (pfVar25[2] == local_70))))))) &&
                      (local_74 < pfVar25[3])) &&
                     ((local_c0 < pfVar16 &&
                      (((*(byte *)((int)pfVar25 + 0x61) == 0 ||
                        (((byte)param_2 & *(byte *)((int)pfVar25 + 0x61)) != 0)) &&
                       ((*(byte *)((int)pfVar25 + 0x62) & (byte)param_3) != 0x40)))))) {
                    DAT_0292119c = 1;
                    if (*(float *)(iVar23 + 0x5c) == 1.0) {
                      *local_c0 = (float)pfVar25;
                      local_bc = local_bc + 1;
                      local_c0 = local_c0 + 1;
                    }
                    else {
                      *(undefined1 *)(iVar27 + 0x60 + iVar28) = *(undefined1 *)(pfVar25 + 0x18);
                      *(undefined1 *)(iVar27 + 0x61 + iVar28) = *(undefined1 *)((int)pfVar25 + 0x61)
                      ;
                      *(undefined1 *)(iVar27 + 0x62 + iVar28) = *(undefined1 *)((int)pfVar25 + 0x62)
                      ;
                      *(undefined1 *)(iVar27 + 99 + iVar28) = *(undefined1 *)((int)pfVar25 + 99);
                      *(float *)(iVar27 + 0x18 + iVar28) = pfVar25[6];
                      *(float *)(iVar27 + 0x20 + iVar28) = pfVar25[8];
                      *(float *)(iVar27 + 0x1c + iVar28) =
                           (pfVar25[7] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                      *(float *)(iVar27 + 0x24 + iVar28) = pfVar25[9];
                      *(float *)(iVar27 + 0x2c + iVar28) = pfVar25[0xb];
                      *(float *)(iVar27 + 0x28 + iVar28) =
                           (pfVar25[10] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                      *(float *)(iVar27 + 0x30 + iVar28) = pfVar25[0xc];
                      *(float *)(iVar27 + 0x38 + iVar28) = pfVar25[0xe];
                      *(float *)(iVar27 + 0x34 + iVar28) =
                           (pfVar25[0xd] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                      if (65535.0 <= pfVar25[0x16]) {
                        *(undefined4 *)(iVar27 + 0x58 + iVar28) = 0x47800000;
                      }
                      else {
                        *(float *)(iVar27 + 0x3c + iVar28) = pfVar25[0xf];
                        *(float *)(iVar27 + 0x44 + iVar28) = pfVar25[0x11];
                        *(float *)(iVar27 + 0x40 + iVar28) =
                             (pfVar25[0x10] + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                        fVar29 = (float10)FUN_005c0240(*(float *)(iVar23 + 0x60) *
                                                       pfVar25[0x16] * pfVar25[0x16] +
                                                       pfVar25[0x15] * pfVar25[0x15] +
                                                       pfVar25[0x17] * pfVar25[0x17]);
                        fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                        iVar28 = DAT_02924b34;
                        iVar23 = DAT_0292186c;
                        fVar1 = (float)fVar29;
                        *(float *)(iVar27 + 0x54 + DAT_02924b34) = fVar1 * pfVar25[0x15];
                        *(float *)(iVar27 + 0x58 + iVar28) =
                             *(float *)(iVar23 + 0x5c) * pfVar25[0x16] * fVar1;
                        *(float *)(iVar27 + 0x5c + iVar28) = fVar1 * pfVar25[0x17];
                      }
                      fVar29 = (float10)FUN_005c0240(*(float *)(iVar23 + 0x60) *
                                                     pfVar25[0x13] * pfVar25[0x13] +
                                                     pfVar25[0x12] * pfVar25[0x12] +
                                                     pfVar25[0x14] * pfVar25[0x14]);
                      fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                      iVar28 = DAT_02924b34;
                      iVar23 = DAT_0292186c;
                      fVar6 = (float)fVar29;
                      fVar1 = (float)(iVar27 + DAT_02924b34);
                      *(float *)((int)fVar1 + 0x48) = fVar6 * pfVar25[0x12];
                      *(float *)((int)fVar1 + 0x4c) =
                           *(float *)(iVar23 + 0x5c) * pfVar25[0x13] * fVar6;
                      *(float *)((int)fVar1 + 0x50) = fVar6 * pfVar25[0x14];
                      *local_c0 = fVar1;
                      local_bc = local_bc + 1;
                      local_9c = local_9c + 1;
                      iVar27 = iVar27 + 100;
                      local_c0 = local_c0 + 1;
                    }
                  }
                  local_8c = local_8c + -1;
                  pfVar25 = pfVar25 + 0x19;
                } while (0 < local_8c);
              }
              pfVar20 = pfVar25;
              sVar8 = *(short *)pfVar25;
            }
            if (local_bc != 0) {
              *(short *)local_78 = (short)local_bc;
              goto LAB_006771a0;
            }
          }
        }
        else if ((pfVar22[0xb] != -NAN) &&
                (fVar2 = (local_80 + local_94) * 0.5 - pfVar22[1],
                fVar1 = (local_a0 + local_a4) * 0.5 - *pfVar22,
                fVar6 = (local_a8 + local_ac) * 0.5 - pfVar22[2],
                fVar6 * fVar6 + fVar1 * fVar1 + fVar2 * fVar2 <
                (pfVar22[0xd] + local_60) * (pfVar22[0xd] + local_60))) {
          psVar24 = (short *)pfVar22[3];
          sVar8 = *psVar24;
          while (-1 < sVar8) {
            local_8c = (int)psVar24[1];
            psVar24 = psVar24 + 10;
            if (0 < local_8c) {
              iVar27 = local_9c * 100;
              do {
                if (((local_c0 < pfVar16) &&
                    ((*(byte *)((int)psVar24 + 0x61) == 0 ||
                     (((byte)param_2 & *(byte *)((int)psVar24 + 0x61)) != 0)))) &&
                   ((*(byte *)(psVar24 + 0x31) & (byte)param_3) != 0x40)) {
                  local_58 = *(float *)(psVar24 + 0xc);
                  local_54 = *(float *)(psVar24 + 0xe);
                  local_50 = *(float *)(psVar24 + 0x10);
                  local_4c = 0;
                  local_48 = *(float *)(psVar24 + 0x12);
                  local_44 = *(float *)(psVar24 + 0x14);
                  local_40 = *(float *)(psVar24 + 0x16);
                  local_3c = 0;
                  local_38 = *(float *)(psVar24 + 0x18);
                  local_34 = *(float *)(psVar24 + 0x1a);
                  local_30 = *(float *)(psVar24 + 0x1c);
                  local_2c = 0;
                  FUN_005c0620(&local_58,&local_58,
                               *(undefined4 *)
                                (*(short *)(pfVar22 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
                  if (65535.0 <= *(float *)(psVar24 + 0x2c)) {
                    local_28 = local_38;
                    local_24 = local_34;
                    local_20 = local_30;
                    local_1c = local_2c;
                  }
                  else {
                    local_28 = *(float *)(psVar24 + 0x1e);
                    local_24 = *(float *)(psVar24 + 0x20);
                    local_20 = *(float *)(psVar24 + 0x22);
                    local_1c = 0;
                    FUN_005c03e0(&local_28,&local_28,
                                 *(undefined4 *)
                                  (*(short *)(pfVar22 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
                  }
                  iVar28 = DAT_02924b34;
                  iVar23 = DAT_0292186c;
                  if (((((((local_90 < local_58) || (local_90 < local_48)) || (local_90 < local_38))
                        || (local_90 < local_28)) &&
                       (((local_58 < local_98 || (local_48 < local_98)) ||
                        ((local_38 < local_98 || (local_28 < local_98)))))) &&
                      (((local_84 < local_50 || (local_84 < local_40)) ||
                       ((local_84 < local_30 || (local_84 < local_20)))))) &&
                     ((((local_50 < local_88 || (local_40 < local_88)) || (local_30 < local_88)) ||
                      (local_20 < local_88)))) {
                    *(char *)(iVar27 + 0x60 + DAT_02924b34) = (char)psVar24[0x30];
                    iVar28 = iVar27 + iVar28;
                    *(undefined1 *)(iVar28 + 0x61) = *(undefined1 *)((int)psVar24 + 0x61);
                    *(char *)(iVar28 + 0x62) = (char)psVar24[0x31];
                    *(undefined1 *)(iVar28 + 99) = *(undefined1 *)((int)psVar24 + 99);
                    iVar23 = DAT_0292186c;
                    DAT_0292119c = 1;
                    *(float *)(iVar28 + 0x18) = local_58;
                    *(float *)(iVar28 + 0x20) = local_50;
                    *(float *)(iVar28 + 0x1c) =
                         (local_54 + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                    *(float *)(iVar28 + 0x24) = local_48;
                    *(float *)(iVar28 + 0x2c) = local_40;
                    *(float *)(iVar28 + 0x28) =
                         (local_44 + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                    *(float *)(iVar28 + 0x30) = local_38;
                    *(float *)(iVar28 + 0x38) = local_30;
                    *(float *)(iVar28 + 0x34) =
                         (local_34 + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                    if (65535.0 <= *(float *)(psVar24 + 0x2c)) {
                      *(undefined4 *)(iVar28 + 0x58) = 0x47800000;
                    }
                    else {
                      *(float *)(iVar28 + 0x3c) = local_28;
                      *(float *)(iVar28 + 0x44) = local_20;
                      *(float *)(iVar28 + 0x40) =
                           (local_24 + pfVar22[1]) * *(float *)(iVar23 + 100) - pfVar22[1];
                      local_58 = *(float *)(iVar28 + 0x24) - *(float *)(iVar28 + 0x3c);
                      local_54 = *(float *)(iVar28 + 0x28) - *(float *)(iVar28 + 0x40);
                      local_50 = *(float *)(iVar28 + 0x2c) - *(float *)(iVar28 + 0x44);
                      local_48 = *(float *)(iVar28 + 0x30) - *(float *)(iVar28 + 0x3c);
                      local_44 = *(float *)(iVar28 + 0x34) - *(float *)(iVar28 + 0x40);
                      local_40 = *(float *)(iVar28 + 0x38) - *(float *)(iVar28 + 0x44);
                      local_18 = local_54 * local_40 - local_50 * local_44;
                      *(float *)(iVar28 + 0x54) = local_18;
                      local_14 = local_48 * local_50 - local_58 * local_40;
                      *(float *)(iVar28 + 0x58) = local_14;
                      local_10 = local_44 * local_58 - local_54 * local_48;
                      *(float *)(iVar28 + 0x5c) = local_10;
                      fVar29 = (float10)FUN_005c0240(*(float *)(iVar28 + 0x5c) *
                                                     *(float *)(iVar28 + 0x5c) +
                                                     *(float *)(iVar28 + 0x54) *
                                                     *(float *)(iVar28 + 0x54) +
                                                     *(float *)(iVar28 + 0x58) *
                                                     *(float *)(iVar28 + 0x58));
                      fVar29 = (float10)FUN_0064fde0(0x3f800000,(float)fVar29);
                      fVar1 = (float)fVar29;
                      iVar28 = DAT_02924b34 + iVar27;
                      *(float *)(iVar28 + 0x54) = fVar1 * *(float *)(DAT_02924b34 + 0x54 + iVar27);
                      *(float *)(iVar28 + 0x58) = *(float *)(iVar28 + 0x58) * fVar1;
                      *(float *)(iVar28 + 0x5c) = fVar1 * *(float *)(iVar28 + 0x5c);
                    }
                    local_58 = *(float *)(iVar28 + 0x30) - *(float *)(iVar28 + 0x18);
                    local_54 = *(float *)(iVar28 + 0x34) - *(float *)(iVar28 + 0x1c);
                    local_50 = *(float *)(iVar28 + 0x38) - *(float *)(iVar28 + 0x20);
                    local_48 = *(float *)(iVar28 + 0x24) - *(float *)(iVar28 + 0x18);
                    local_44 = *(float *)(iVar28 + 0x28) - *(float *)(iVar28 + 0x1c);
                    local_40 = *(float *)(iVar28 + 0x2c) - *(float *)(iVar28 + 0x20);
                    local_c = local_54 * local_40 - local_50 * local_44;
                    *(float *)(iVar28 + 0x48) = local_c;
                    local_8 = local_48 * local_50 - local_58 * local_40;
                    *(float *)(iVar28 + 0x4c) = local_8;
                    local_4 = local_44 * local_58 - local_54 * local_48;
                    *(float *)(iVar28 + 0x50) = local_4;
                    fVar29 = (float10)FUN_005c0240(*(float *)(iVar28 + 0x50) *
                                                   *(float *)(iVar28 + 0x50) +
                                                   *(float *)(iVar28 + 0x48) *
                                                   *(float *)(iVar28 + 0x48) +
                                                   *(float *)(iVar28 + 0x4c) *
                                                   *(float *)(iVar28 + 0x4c));
                    iVar28 = DAT_02924b34;
                    if ((float)fVar29 == 0.0) {
                      local_b4 = 0.0;
                    }
                    else {
                      local_b4 = 1.0 / (float)fVar29;
                    }
                    fVar1 = (float)(iVar27 + DAT_02924b34);
                    *(float *)((int)fVar1 + 0x48) =
                         local_b4 * *(float *)(iVar27 + 0x48 + DAT_02924b34);
                    *(float *)((int)fVar1 + 0x4c) = *(float *)((int)fVar1 + 0x4c) * local_b4;
                    *(float *)((int)fVar1 + 0x50) = local_b4 * *(float *)((int)fVar1 + 0x50);
                    *local_c0 = fVar1;
                    local_bc = local_bc + 1;
                    local_9c = local_9c + 1;
                    iVar27 = iVar27 + 100;
                    iVar23 = DAT_0292186c;
                    local_c0 = local_c0 + 1;
                  }
                }
                local_8c = local_8c + -1;
                psVar24 = psVar24 + 0x32;
              } while (0 < local_8c);
            }
            sVar8 = *psVar24;
          }
          if (local_bc != 0) {
            *(undefined2 *)local_78 = (undefined2)local_bc;
LAB_006771a0:
            *(short *)((int)local_78 + 2) = (short)iVar14;
            local_78 = local_c0;
            local_c0 = local_c0 + 1;
            local_bc = 0;
          }
        }
      }
      else if ((*(byte *)(iVar27 + 0x4c) & 4) == 0) {
        if ((*puVar10 & 1) != 0) goto LAB_00676d84;
      }
      else if ((*puVar10 & 2) != 0) goto LAB_00676d84;
LAB_00677a27:
      piVar21 = (int *)((int)piVar21 + 2);
    }
  }
  local_a4 = local_a4 - 0.02;
  *(undefined2 *)local_78 = 0;
  *(undefined2 *)((int)local_78 + 2) = 0;
  puVar11 = (ushort *)DAT_0292fc68[0x52];
  local_a8 = local_a8 - 0.02;
  DAT_02924ab8 = 0;
  local_a0 = local_a0 + 0.02;
  local_ac = local_ac + 0.02;
  if (DAT_02962b28 == 0) {
    DAT_02962b28 = 0;
    DAT_02924ab8 = 0;
    for (; puVar11 != (ushort *)0x0; puVar11 = *(ushort **)(puVar11 + -2)) {
      bVar7 = *(byte *)((int)puVar11 + 3);
      if ((bVar7 == 0) || (((byte)param_2 & bVar7) != 0)) {
        uVar15 = puVar11[1];
        uVar19 = (uint)*puVar11;
        iVar28 = 0;
        if (uVar19 != 0) {
          pfVar16 = (float *)(puVar11 + 4);
          do {
            if (*pfVar16 == 2.1474836e+09) {
LAB_00677b54:
              uVar18 = uVar19;
            }
            else if (((pfVar16[3] < local_a4) || (*pfVar16 < local_a0 == (*pfVar16 == local_a0))) ||
                    ((pfVar16[9] < local_a8 || (pfVar16[6] < local_ac == (pfVar16[6] == local_ac))))
                    ) {
              uVar18 = 0;
            }
            else {
              uVar18 = iVar28 + 0x10U;
              if ((int)uVar19 < (int)(iVar28 + 0x10U)) goto LAB_00677b54;
            }
            if (iVar28 < (int)uVar18) {
              pfVar20 = (float *)(DAT_02924ab8 * 0x10 + DAT_0292fb50);
              local_64 = uVar18 - iVar28;
              pfVar22 = pfVar16 + 1;
              do {
                if ((((local_a4 <= pfVar22[-2]) &&
                     (pfVar22[1] < local_a0 != (pfVar22[1] == local_a0))) ||
                    ((local_a4 <= pfVar22[1] &&
                     (pfVar22[-2] < local_a0 != (pfVar22[-2] == local_a0))))) &&
                   ((((local_a8 <= *pfVar22 && (pfVar22[3] < local_ac != (pfVar22[3] == local_ac)))
                     || ((local_a8 <= pfVar22[3] && (*pfVar22 < local_ac != (*pfVar22 == local_ac)))
                        )) && (DAT_02924ab8 < 0x40)))) {
                  *pfVar20 = pfVar22[-2];
                  pfVar20[1] = pfVar22[-1];
                  pfVar20[2] = *pfVar22;
                  *(char *)(pfVar20 + 3) = (char)uVar15;
                  *(byte *)((int)pfVar20 + 0xd) = bVar7;
                  *(undefined1 *)((int)pfVar20 + 0xe) = 0;
                  *(undefined1 *)((int)pfVar20 + 0xf) = 0;
                  pfVar20[4] = pfVar22[1];
                  pfVar20[5] = pfVar22[2];
                  pfVar20[6] = pfVar22[3];
                  *(char *)(pfVar20 + 7) = (char)uVar15;
                  *(byte *)((int)pfVar20 + 0x1d) = bVar7;
                  *(undefined1 *)((int)pfVar20 + 0x1e) = 0;
                  *(undefined1 *)((int)pfVar20 + 0x1f) = 0;
                  DAT_02924ab8 = DAT_02924ab8 + 2;
                  pfVar20 = pfVar20 + 8;
                }
                pfVar22 = pfVar22 + 3;
                local_64 = local_64 + -1;
              } while (local_64 != 0);
            }
            uVar19 = (uint)*puVar11;
            iVar28 = iVar28 + 0x10;
            pfVar16 = pfVar16 + 0x30;
          } while (iVar28 < (int)uVar19);
        }
      }
    }
  }
  else {
    DAT_02962b28 = 0;
  }
  DAT_02948edc = 0;
  return;
}

