/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x671750; label: FUN_00671750
 */

void FUN_00671750(float *param_1,byte param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  float fVar9;
  uint uVar10;
  uint *puVar11;
  float fVar12;
  int iVar13;
  int *piVar14;
  float *pfVar15;
  int iVar16;
  float fVar17;
  short sVar18;
  float *pfVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  int iVar23;
  short *psVar24;
  float10 fVar25;
  float *local_60;
  float *local_5c;
  float local_54;
  int local_50;
  float local_4c;
  float local_48;
  short *local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  float *local_2c;
  int local_24;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  iVar13 = FUN_006de8d0(0xd0);
  iVar20 = DAT_0292186c;
  fVar17 = *param_1;
  fVar9 = param_1[2];
  pfVar21 = (float *)(iVar13 + 0x1fU & 0xfffffff0);
  local_24 = -1;
  local_30 = 0x7fffffff;
  iVar13 = 0;
  pfVar15 = (float *)(DAT_0292fc68 + 0x6f0);
  do {
    sVar18 = *(short *)(pfVar15 + -2);
    if ((((0 < sVar18) && (fVar12 = (fVar17 + 1.0) - pfVar15[-1], 0.0 < fVar12)) && (fVar12 < 2.0))
       && ((fVar12 = (fVar9 + 1.0) - *pfVar15, 0.0 < fVar12 && (iVar23 = iVar13, fVar12 < 2.0))))
    break;
    if (sVar18 < local_30) {
      local_30 = (int)sVar18;
      local_24 = iVar13;
    }
    iVar13 = iVar13 + 1;
    pfVar15 = pfVar15 + 0x203;
    iVar23 = -1;
  } while (iVar13 < 0x10);
  iVar13 = *DAT_0292fc68;
  if (iVar23 < 0) {
    if ((short)DAT_0292fc68[local_24 * 0x203 + 0x6ee] < 2) {
      local_60 = (float *)(DAT_0292fc68 + local_24 * 0x203 + 0x6f2);
      local_48 = fVar17 + 1.0;
      local_5c = (float *)(DAT_0292fc68 + local_24 * 0x203 + 0x6f1);
      local_4c = fVar9 + 1.0;
      local_54 = fVar17 - 1.0;
      fVar12 = fVar9 - 1.0;
    }
    else {
      local_60 = (float *)(DAT_0292186c + 0x14c);
      local_5c = (float *)(DAT_0292186c + 0x148);
      local_48 = fVar17 + 0.1;
      local_4c = fVar9 + 0.1;
      local_54 = fVar17 - 0.1;
      fVar12 = fVar9 - 0.1;
    }
    iVar20 = 0;
    local_2c = local_60 + 0x1fc;
    local_50 = 0;
    local_1c = 0;
    piVar14 = DAT_0292fc68;
    if (0 < DAT_0292fc68[0x6ec]) {
      local_50 = 0;
      iVar23 = local_50;
      do {
        local_50 = iVar23;
        fVar6 = *(float *)(local_50 + 0x79c + (int)piVar14);
        if (((fVar6 < local_48 != (fVar6 == local_48)) &&
            (local_54 <= *(float *)(local_50 + 0x7a4 + (int)piVar14))) &&
           ((fVar6 = *(float *)(local_50 + 0x7a0 + (int)piVar14),
            fVar6 < local_4c != (fVar6 == local_4c) &&
            (fVar12 <= *(float *)(local_50 + 0x7a8 + (int)piVar14))))) {
          local_44 = (short *)(piVar14[0x6ed] + *(short *)(local_50 + 0x798 + (int)piVar14) * 2);
          local_30 = 0;
          if (0 < *(short *)(local_50 + 0x79a + (int)piVar14)) {
            do {
              pfVar15 = (float *)(iVar13 + *local_44 * 0x38);
              if ((((pfVar15[4] < local_48 != (pfVar15[4] == local_48)) &&
                   (pfVar15[6] < local_4c != (pfVar15[6] == local_4c))) && (local_54 <= pfVar15[7]))
                 && ((fVar12 < pfVar15[9] && (pfVar15[0xb] != -NAN)))) {
                fVar4 = local_48 - *pfVar15;
                fVar3 = local_4c - pfVar15[2];
                fVar6 = *pfVar15;
                fVar2 = pfVar15[2];
                if (*(short *)(pfVar15 + 0xc) < 0) {
                  FUN_0066f790(pfVar15);
                  piVar14 = DAT_0292fc68;
                }
                sVar18 = *(short *)pfVar15[3];
                pfVar22 = (float *)pfVar15[3];
                pfVar15 = local_60;
                while (-1 < sVar18) {
                  iVar23 = (int)*(short *)((int)pfVar22 + 2);
                  pfVar19 = pfVar22 + 5;
                  if (((pfVar22[1] < fVar4 == (pfVar22[1] == fVar4)) ||
                      (pfVar22[2] <= local_54 - fVar6)) ||
                     ((pfVar22[3] < fVar3 == (pfVar22[3] == fVar3) || (pfVar22[4] <= fVar12 - fVar2)
                      ))) {
                    pfVar19 = pfVar19 + iVar23 * 0x19;
                  }
                  else {
                    for (; 0 < iVar23; iVar23 = iVar23 + -1) {
                      if ((((*pfVar19 < fVar4 != (*pfVar19 == fVar4)) &&
                           (local_54 - fVar6 < pfVar19[1])) &&
                          (pfVar19[4] < fVar3 != (pfVar19[4] == fVar3))) &&
                         (((fVar12 - fVar2 < pfVar19[5] && (pfVar15 < local_2c)) &&
                          ((*(byte *)((int)pfVar19 + 0x61) == 0 ||
                           ((param_2 & *(byte *)((int)pfVar19 + 0x61)) != 0)))))) {
                        *pfVar15 = (float)pfVar19;
                        pfVar15 = pfVar15 + 1;
                        iVar20 = iVar20 + 1;
                      }
                      pfVar19 = pfVar19 + 0x19;
                    }
                  }
                  pfVar22 = pfVar19;
                  piVar14 = DAT_0292fc68;
                  sVar18 = *(short *)pfVar19;
                }
                local_60 = pfVar15;
                if (iVar20 != 0) {
                  *(short *)local_5c = (short)iVar20;
                  *(short *)((int)local_5c + 2) = *local_44;
                  local_60 = pfVar15 + 1;
                  iVar20 = 0;
                  piVar14 = DAT_0292fc68;
                  local_5c = pfVar15;
                }
              }
              local_44 = local_44 + 1;
              local_30 = local_30 + 1;
            } while (local_30 < *(short *)(local_50 + 0x79a + (int)piVar14));
          }
        }
        local_1c = local_1c + 1;
        iVar23 = local_50 + 0x14;
        local_50 = iVar20;
      } while (local_1c < piVar14[0x6ec]);
    }
    iVar20 = DAT_0292186c;
    if (1 < (short)piVar14[local_24 * 0x203 + 0x6ee]) goto LAB_00671a39;
    *(undefined2 *)(piVar14 + local_24 * 0x203 + 0x6ee) = 8;
    local_50 = 0;
    DAT_0292fc68[local_24 * 0x203 + 0x6ef] = (int)*param_1;
    local_60 = (float *)(iVar20 + 0x14c);
    DAT_0292fc68[local_24 * 0x203 + 0x6f0] = (int)param_1[2];
    *(undefined2 *)local_5c = 0;
    fVar6 = fVar17 + 0.1;
    *(undefined2 *)((int)local_5c + 2) = 0;
    local_5c = (float *)(iVar20 + 0x148);
    local_2c = (float *)(iVar20 + 0x93c);
    fVar12 = fVar9 + 0.1;
    pfVar15 = (float *)(DAT_0292fc68 + local_24 * 0x203 + 0x6f1);
    sVar18 = *(short *)pfVar15;
    if (sVar18 < 1) goto LAB_00672069;
    do {
      sVar8 = *(short *)((int)pfVar15 + 2);
      pfVar22 = (float *)(iVar13 + sVar8 * 0x38);
      pfVar15 = pfVar15 + 1;
      if (((pfVar22[4] < fVar6 == (pfVar22[4] == fVar6)) || (pfVar22[7] < fVar17 - 0.1)) ||
         ((pfVar22[6] < fVar12 == (pfVar22[6] == fVar12) ||
          ((pfVar22[9] <= fVar9 - 0.1 || (pfVar22[0xb] == -NAN)))))) {
        pfVar15 = pfVar15 + sVar18;
      }
      else {
        fVar2 = *pfVar22;
        fVar3 = pfVar22[2];
        fVar4 = *pfVar22;
        fVar5 = pfVar22[2];
        pfVar22 = local_60;
        for (iVar20 = (int)sVar18; 0 < iVar20; iVar20 = iVar20 + -1) {
          pfVar19 = (float *)*pfVar15;
          if ((((*pfVar19 < fVar6 - fVar2 != (*pfVar19 == fVar6 - fVar2)) &&
               ((fVar17 - 0.1) - fVar4 < pfVar19[1])) &&
              (pfVar19[4] < fVar12 - fVar3 != (pfVar19[4] == fVar12 - fVar3))) &&
             ((((fVar9 - 0.1) - fVar5 < pfVar19[5] &&
               ((*(byte *)((int)pfVar19 + 0x61) == 0 ||
                ((param_2 & *(byte *)((int)pfVar19 + 0x61)) != 0)))) && (pfVar22 < local_2c)))) {
            *pfVar22 = (float)pfVar19;
            pfVar22 = pfVar22 + 1;
            local_50 = local_50 + 1;
          }
          pfVar15 = pfVar15 + 1;
        }
        local_60 = pfVar22;
        if (local_50 != 0) {
          *(short *)local_5c = (short)local_50;
          local_60 = pfVar22 + 1;
          *(short *)((int)local_5c + 2) = sVar8;
          local_50 = 0;
          local_5c = pfVar22;
        }
      }
      sVar18 = *(short *)pfVar15;
    } while (0 < sVar18);
  }
  else {
    local_5c = (float *)(DAT_0292186c + 0x148);
    fVar12 = fVar17 + 0.1;
    fVar6 = fVar9 + 0.1;
    *(undefined2 *)(DAT_0292fc68 + iVar23 * 0x203 + 0x6ee) = 8;
    local_60 = (float *)(iVar20 + 0x14c);
    local_2c = (float *)(iVar20 + 0x93c);
    sVar18 = (short)DAT_0292fc68[iVar23 * 0x203 + 0x6f1];
    piVar14 = DAT_0292fc68 + iVar23 * 0x203 + 0x6f1;
    local_50 = 0;
    if (sVar18 < 1) {
LAB_00672069:
      local_50 = 0;
    }
    else {
      do {
        sVar8 = *(short *)((int)piVar14 + 2);
        pfVar15 = (float *)(iVar13 + sVar8 * 0x38);
        piVar14 = piVar14 + 1;
        if (((pfVar15[4] < fVar12 == (pfVar15[4] == fVar12)) ||
            (pfVar15[6] < fVar6 == (pfVar15[6] == fVar6))) ||
           ((pfVar15[7] < fVar17 - 0.1 || ((pfVar15[9] <= fVar9 - 0.1 || (pfVar15[0xb] == -NAN))))))
        {
          piVar14 = piVar14 + sVar18;
        }
        else {
          fVar2 = *pfVar15;
          fVar3 = pfVar15[2];
          fVar4 = *pfVar15;
          fVar5 = pfVar15[2];
          pfVar15 = local_60;
          for (iVar20 = (int)sVar18; 0 < iVar20; iVar20 = iVar20 + -1) {
            pfVar22 = (float *)*piVar14;
            if (((((*pfVar22 < fVar12 - fVar2 != (*pfVar22 == fVar12 - fVar2)) &&
                  ((fVar17 - 0.1) - fVar4 < pfVar22[1])) &&
                 (pfVar22[4] < fVar6 - fVar3 != (pfVar22[4] == fVar6 - fVar3))) &&
                (((fVar9 - 0.1) - fVar5 < pfVar22[5] && (pfVar15 < local_2c)))) &&
               ((*(byte *)((int)pfVar22 + 0x61) == 0 ||
                ((param_2 & *(byte *)((int)pfVar22 + 0x61)) != 0)))) {
              *pfVar15 = (float)pfVar22;
              pfVar15 = pfVar15 + 1;
              local_50 = local_50 + 1;
            }
            piVar14 = piVar14 + 1;
          }
          local_60 = pfVar15;
          if (local_50 != 0) {
            *(short *)local_5c = (short)local_50;
            local_60 = pfVar15 + 1;
            *(short *)((int)local_5c + 2) = sVar8;
            local_50 = 0;
            local_5c = pfVar15;
          }
        }
        sVar18 = (short)*piVar14;
      } while (0 < sVar18);
    }
  }
  local_54 = fVar17 - 0.1;
  fVar12 = fVar9 - 0.1;
  local_4c = fVar9 + 0.1;
  local_48 = fVar17 + 0.1;
  piVar14 = DAT_0292fc68;
LAB_00671a39:
  if (DAT_0292fb54 == 0) {
    local_54 = local_54 - 0.05;
    local_48 = local_48 + 0.05;
    fVar12 = fVar12 - 0.05;
    local_4c = local_4c + 0.05;
    if (((local_54 <= (float)piVar14[0x4c]) || ((float)piVar14[0x4f] <= local_48)) ||
       ((fVar12 <= (float)piVar14[0x4e] || ((float)piVar14[0x51] <= local_4c)))) {
      piVar1 = (int *)(piVar14[0x6ed] + (short)piVar14[0x6e6] * 2);
      iVar20 = (int)*(short *)((int)piVar14 + 0x1b9a);
    }
    else {
      piVar1 = piVar14 + 0x1b;
      iVar20 = piVar14[0x4b];
    }
    for (; 0 < iVar20; iVar20 = iVar20 + -1) {
      pfVar15 = (float *)(iVar13 + (short)*piVar1 * 0x38);
      if ((((*pfVar15 - pfVar15[0xd] <= local_48) && (local_54 <= pfVar15[0xd] + *pfVar15)) &&
          (pfVar15[2] - pfVar15[0xd] <= local_4c)) && (fVar12 <= pfVar15[2] + pfVar15[0xd])) {
        iVar23 = piVar14[0x1a] + *(short *)(pfVar15 + 0xc) * 0x6c;
        if (*(int *)(iVar23 + 0x40) == 0) {
          local_40 = local_48 - *pfVar15;
          local_38 = local_54 - *pfVar15;
          local_3c = pfVar15[2];
          local_34 = fVar12 - pfVar15[2];
LAB_00672245:
          local_3c = local_4c - local_3c;
        }
        else {
          iVar16 = *(short *)(pfVar15 + 0xc) * 0x6c + piVar14[0x1a];
          if (*(float *)(*(int *)(iVar16 + 0x40) + 0x30) <= *(float *)(iVar16 + 0x30)) {
            local_40 = local_48 - *pfVar15;
            iVar16 = *(short *)(pfVar15 + 0xc) * 0x6c + piVar14[0x1a];
            local_38 = ((*(float *)(*(int *)(iVar16 + 0x40) + 0x30) - *(float *)(iVar16 + 0x30)) *
                        1.5 + local_54) - *pfVar15;
          }
          else {
            local_38 = local_54 - *pfVar15;
            iVar16 = *(short *)(pfVar15 + 0xc) * 0x6c + piVar14[0x1a];
            local_40 = ((*(float *)(*(int *)(iVar16 + 0x40) + 0x30) - *(float *)(iVar16 + 0x30)) *
                        1.5 + local_48) - *pfVar15;
          }
          iVar16 = *(short *)(pfVar15 + 0xc) * 0x6c + piVar14[0x1a];
          if (*(float *)(*(int *)(iVar16 + 0x40) + 0x38) <= *(float *)(iVar16 + 0x38)) {
            local_3c = pfVar15[2];
            iVar16 = *(short *)(pfVar15 + 0xc) * 0x6c + piVar14[0x1a];
            local_34 = (fVar12 + (*(float *)(*(int *)(iVar16 + 0x40) + 0x38) -
                                 *(float *)(iVar16 + 0x38)) * 1.5) - pfVar15[2];
            goto LAB_00672245;
          }
          local_34 = fVar12 - pfVar15[2];
          iVar16 = *(short *)(pfVar15 + 0xc) * 0x6c + piVar14[0x1a];
          local_3c = (local_4c +
                     (*(float *)(*(int *)(iVar16 + 0x40) + 0x38) - *(float *)(iVar16 + 0x38)) * 1.5)
                     - pfVar15[2];
        }
        uVar10 = *(uint *)(iVar23 + 0x4c);
        if ((uVar10 & 1) == 0) {
          if (((pfVar15[4] < local_40 != (pfVar15[4] == local_40)) &&
              (pfVar15[6] < local_3c != (pfVar15[6] == local_3c))) &&
             ((local_38 <= pfVar15[7] && ((local_34 < pfVar15[9] && (pfVar15[0xb] != -NAN)))))) {
            puVar11 = *(uint **)(iVar23 + 0x68);
            if (puVar11 == (uint *)0x0) {
LAB_0067285d:
              sVar18 = *(short *)pfVar15[3];
              pfVar22 = (float *)pfVar15[3];
              pfVar15 = local_60;
              while (-1 < sVar18) {
                iVar23 = (int)*(short *)((int)pfVar22 + 2);
                pfVar19 = pfVar22 + 5;
                if ((((pfVar22[1] < local_40 == (pfVar22[1] == local_40)) ||
                     (pfVar22[2] <= local_38)) ||
                    (pfVar22[3] < local_3c == (pfVar22[3] == local_3c))) || (pfVar22[4] <= local_34)
                   ) {
                  pfVar19 = pfVar19 + iVar23 * 0x19;
                }
                else {
                  for (; 0 < iVar23; iVar23 = iVar23 + -1) {
                    if (((*pfVar19 < local_40 != (*pfVar19 == local_40)) && (local_38 < pfVar19[1]))
                       && (((pfVar19[4] < local_3c != (pfVar19[4] == local_3c) &&
                            ((local_34 < pfVar19[5] && (pfVar15 < local_2c)))) &&
                           ((*(byte *)((int)pfVar19 + 0x61) == 0 ||
                            ((param_2 & *(byte *)((int)pfVar19 + 0x61)) != 0)))))) {
                      *pfVar15 = (float)pfVar19;
                      pfVar15 = pfVar15 + 1;
                      local_50 = local_50 + 1;
                    }
                    pfVar19 = pfVar19 + 0x19;
                  }
                }
                pfVar22 = pfVar19;
                piVar14 = DAT_0292fc68;
                sVar18 = *(short *)pfVar19;
              }
              local_60 = pfVar15;
              if (local_50 != 0) {
                *(short *)local_5c = (short)local_50;
                local_60 = pfVar15 + 1;
                *(short *)((int)local_5c + 2) = (short)*piVar1;
                local_50 = 0;
                piVar14 = DAT_0292fc68;
                local_5c = pfVar15;
              }
            }
            else if ((uVar10 & 4) == 0) {
              if ((*puVar11 & 1) != 0) goto LAB_0067285d;
            }
            else if ((*puVar11 & 2) != 0) goto LAB_0067285d;
          }
        }
        else if ((pfVar15[0xb] != -NAN) &&
                (fVar9 = (fVar12 + local_4c) * 0.5 - pfVar15[2],
                fVar17 = (local_54 + local_48) * 0.5 - *pfVar15,
                fVar17 * fVar17 + fVar9 * fVar9 < (pfVar15[0xd] + 1e-05) * (pfVar15[0xd] + 1e-05)))
        {
          puVar11 = *(uint **)(iVar23 + 0x68);
          if (puVar11 == (uint *)0x0) {
LAB_006722c9:
            psVar24 = (short *)pfVar15[3];
            sVar18 = *psVar24;
            pfVar22 = local_60;
            while (local_60 = pfVar22, -1 < sVar18) {
              local_24 = (int)psVar24[1];
              psVar24 = psVar24 + 10;
              if (0 < local_24) {
                iVar23 = local_20 * 100;
                do {
                  if (((*(byte *)((int)psVar24 + 0x61) == 0) ||
                      ((param_2 & *(byte *)((int)psVar24 + 0x61)) != 0)) && (local_60 < local_2c)) {
                    *pfVar21 = *(float *)(psVar24 + 0xc);
                    pfVar21[1] = *(float *)(psVar24 + 0xe);
                    pfVar21[2] = *(float *)(psVar24 + 0x10);
                    pfVar21[3] = 0.0;
                    pfVar21[4] = *(float *)(psVar24 + 0x12);
                    pfVar21[5] = *(float *)(psVar24 + 0x14);
                    pfVar21[6] = *(float *)(psVar24 + 0x16);
                    pfVar21[7] = 0.0;
                    pfVar21[8] = *(float *)(psVar24 + 0x18);
                    pfVar21[9] = *(float *)(psVar24 + 0x1a);
                    pfVar21[10] = *(float *)(psVar24 + 0x1c);
                    pfVar21[0xb] = 0.0;
                    FUN_005c0620(pfVar21,pfVar21,
                                 *(undefined4 *)
                                  (*(short *)(pfVar15 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
                    pfVar22 = pfVar21 + 0xc;
                    if (65535.0 <= *(float *)(psVar24 + 0x2c)) {
                      *pfVar22 = pfVar21[8];
                      pfVar21[0xd] = pfVar21[9];
                      pfVar21[0xe] = pfVar21[10];
                      pfVar21[0xf] = pfVar21[0xb];
                    }
                    else {
                      *pfVar22 = *(float *)(psVar24 + 0x1e);
                      pfVar21[0xd] = *(float *)(psVar24 + 0x20);
                      pfVar21[0xe] = *(float *)(psVar24 + 0x22);
                      pfVar21[0xf] = 0.0;
                      FUN_005c03e0(pfVar22,pfVar22,
                                   *(undefined4 *)
                                    (*(short *)(pfVar15 + 0xc) * 0x6c + 0x40 + DAT_0292fc68[0x1a]));
                    }
                    if (((((local_38 < *pfVar21) || (local_38 < pfVar21[4])) ||
                         ((local_38 < pfVar21[8] || (local_38 < *pfVar22)))) &&
                        (((*pfVar21 < local_40 || (pfVar21[4] < local_40)) ||
                         ((pfVar21[8] < local_40 || (*pfVar22 < local_40)))))) &&
                       (((((local_34 < pfVar21[2] || (local_34 < pfVar21[6])) ||
                          (local_34 < pfVar21[10])) || (local_34 < pfVar21[0xe])) &&
                        (((pfVar21[2] < local_3c || (pfVar21[6] < local_3c)) ||
                         ((pfVar21[10] < local_3c || (pfVar21[0xe] < local_3c)))))))) {
                      iVar16 = iVar23 + DAT_02924b34;
                      *(undefined4 *)(iVar16 + 0x60) = *(undefined4 *)(psVar24 + 0x30);
                      *(float *)(iVar16 + 0x18) = *pfVar21;
                      *(float *)(iVar16 + 0x1c) = pfVar21[1];
                      *(float *)(iVar16 + 0x20) = pfVar21[2];
                      *(float *)(iVar16 + 0x24) = pfVar21[4];
                      *(float *)(iVar16 + 0x28) = pfVar21[5];
                      *(float *)(iVar16 + 0x2c) = pfVar21[6];
                      *(float *)(iVar16 + 0x30) = pfVar21[8];
                      *(float *)(iVar16 + 0x34) = pfVar21[9];
                      *(float *)(iVar16 + 0x38) = pfVar21[10];
                      if (65535.0 <= *(float *)(psVar24 + 0x2c)) {
                        *(undefined4 *)(iVar16 + 0x58) = 0x47800000;
                      }
                      else {
                        *(float *)(iVar16 + 0x3c) = *pfVar22;
                        *(float *)(iVar16 + 0x40) = pfVar21[0xd];
                        *(float *)(iVar16 + 0x44) = pfVar21[0xe];
                        *pfVar21 = *(float *)(iVar16 + 0x24) - *(float *)(iVar16 + 0x3c);
                        pfVar21[1] = *(float *)(iVar16 + 0x28) - *(float *)(iVar16 + 0x40);
                        pfVar21[2] = *(float *)(iVar16 + 0x2c) - *(float *)(iVar16 + 0x44);
                        pfVar21[4] = *(float *)(iVar16 + 0x30) - *(float *)(iVar16 + 0x3c);
                        pfVar21[5] = *(float *)(iVar16 + 0x34) - *(float *)(iVar16 + 0x40);
                        pfVar21[6] = *(float *)(iVar16 + 0x38) - *(float *)(iVar16 + 0x44);
                        fVar17 = pfVar21[2];
                        fVar9 = pfVar21[4];
                        fVar6 = *pfVar21;
                        fVar2 = pfVar21[6];
                        fVar3 = pfVar21[5];
                        fVar4 = *pfVar21;
                        fVar5 = pfVar21[1];
                        fVar7 = pfVar21[4];
                        *(float *)(iVar16 + 0x54) =
                             pfVar21[1] * pfVar21[6] - pfVar21[5] * pfVar21[2];
                        *(float *)(iVar16 + 0x58) = fVar17 * fVar9 - fVar6 * fVar2;
                        *(float *)(iVar16 + 0x5c) = fVar3 * fVar4 - fVar5 * fVar7;
                        fVar25 = (float10)FUN_005c0240(*(float *)(iVar16 + 0x5c) *
                                                       *(float *)(iVar16 + 0x5c) +
                                                       *(float *)(iVar16 + 0x54) *
                                                       *(float *)(iVar16 + 0x54) +
                                                       *(float *)(iVar16 + 0x58) *
                                                       *(float *)(iVar16 + 0x58));
                        if ((float)fVar25 == 0.0) {
                          fVar17 = 0.0;
                        }
                        else {
                          fVar17 = 1.0 / (float)fVar25;
                        }
                        iVar16 = iVar23 + DAT_02924b34;
                        *(float *)(iVar16 + 0x54) =
                             fVar17 * *(float *)(iVar23 + 0x54 + DAT_02924b34);
                        *(float *)(iVar16 + 0x58) = *(float *)(iVar16 + 0x58) * fVar17;
                        *(float *)(iVar16 + 0x5c) = fVar17 * *(float *)(iVar16 + 0x5c);
                      }
                      *pfVar21 = *(float *)(iVar16 + 0x30) - *(float *)(iVar16 + 0x18);
                      pfVar21[1] = *(float *)(iVar16 + 0x34) - *(float *)(iVar16 + 0x1c);
                      pfVar21[2] = *(float *)(iVar16 + 0x38) - *(float *)(iVar16 + 0x20);
                      pfVar21[4] = *(float *)(iVar16 + 0x24) - *(float *)(iVar16 + 0x18);
                      pfVar21[5] = *(float *)(iVar16 + 0x28) - *(float *)(iVar16 + 0x1c);
                      pfVar21[6] = *(float *)(iVar16 + 0x2c) - *(float *)(iVar16 + 0x20);
                      fVar17 = pfVar21[2];
                      fVar9 = pfVar21[4];
                      fVar6 = *pfVar21;
                      fVar2 = pfVar21[6];
                      fVar3 = *pfVar21;
                      fVar4 = pfVar21[5];
                      fVar5 = pfVar21[1];
                      fVar7 = pfVar21[4];
                      *(float *)(iVar16 + 0x48) = pfVar21[1] * pfVar21[6] - pfVar21[2] * pfVar21[5];
                      *(float *)(iVar16 + 0x4c) = fVar17 * fVar9 - fVar6 * fVar2;
                      *(float *)(iVar16 + 0x50) = fVar3 * fVar4 - fVar5 * fVar7;
                      fVar25 = (float10)FUN_005c0240(*(float *)(iVar16 + 0x50) *
                                                     *(float *)(iVar16 + 0x50) +
                                                     *(float *)(iVar16 + 0x48) *
                                                     *(float *)(iVar16 + 0x48) +
                                                     *(float *)(iVar16 + 0x4c) *
                                                     *(float *)(iVar16 + 0x4c));
                      if ((float)fVar25 == 0.0) {
                        param_1 = (float *)0x0;
                      }
                      else {
                        param_1 = (float *)(1.0 / (float)fVar25);
                      }
                      fVar17 = (float)(DAT_02924b34 + iVar23);
                      *(float *)((int)fVar17 + 0x48) =
                           (float)param_1 * *(float *)(DAT_02924b34 + 0x48 + iVar23);
                      *(float *)((int)fVar17 + 0x4c) =
                           *(float *)((int)fVar17 + 0x4c) * (float)param_1;
                      *(float *)((int)fVar17 + 0x50) =
                           (float)param_1 * *(float *)((int)fVar17 + 0x50);
                      *local_60 = fVar17;
                      local_50 = local_50 + 1;
                      local_20 = local_20 + 1;
                      iVar23 = iVar23 + 100;
                      local_60 = local_60 + 1;
                    }
                  }
                  local_24 = local_24 + -1;
                  psVar24 = psVar24 + 0x32;
                } while (0 < local_24);
              }
              piVar14 = DAT_0292fc68;
              pfVar22 = local_60;
              sVar18 = *psVar24;
            }
            if (local_50 != 0) {
              *(undefined2 *)local_5c = (undefined2)local_50;
              *(short *)((int)local_5c + 2) = (short)*piVar1;
              local_50 = 0;
              piVar14 = DAT_0292fc68;
              local_60 = pfVar22 + 1;
              local_5c = pfVar22;
            }
          }
          else if ((uVar10 & 4) == 0) {
            if ((*puVar11 & 1) != 0) goto LAB_006722c9;
          }
          else if ((*puVar11 & 2) != 0) goto LAB_006722c9;
        }
      }
      piVar1 = (int *)((int)piVar1 + 2);
    }
  }
  FUN_006de960();
  *(undefined2 *)local_5c = 0;
  *(undefined2 *)((int)local_5c + 2) = 0;
  return;
}

