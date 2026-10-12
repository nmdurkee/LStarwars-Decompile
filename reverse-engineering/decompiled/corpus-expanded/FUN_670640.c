/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x670640; label: FUN_00670640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00670640(float *param_1,byte param_2,int param_3)

{
  float fVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  uint *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  int *piVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  float *pfVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  int iVar22;
  float *pfVar23;
  int *piVar24;
  short sVar25;
  float *local_48;
  float *local_44;
  float local_40;
  float local_3c;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  short *local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  pfVar17 = param_1;
  iVar13 = DAT_0292186c;
  fVar3 = *param_1;
  fVar4 = param_1[2];
  iVar19 = -1;
  iVar20 = 0x7fffffff;
  iVar22 = 0;
  pfVar16 = (float *)(DAT_0292fc68 + 0x6f0);
  while ((((sVar25 = *(short *)(pfVar16 + -2), sVar25 < 1 ||
           (fVar6 = (fVar3 + 1.0) - pfVar16[-1], 2.0 <= fVar6)) ||
          (fVar7 = (fVar4 + 1.0) - *pfVar16, 2.0 <= fVar7)) || ((fVar6 <= 0.0 || (fVar7 <= 0.0)))))
  {
    if (sVar25 < iVar20) {
      iVar19 = iVar22;
      iVar20 = (int)sVar25;
    }
    iVar22 = iVar22 + 1;
    pfVar16 = pfVar16 + 0x203;
    if (0xf < iVar22) goto LAB_006708bb;
  }
  if (iVar22 < 0) goto LAB_006708bb;
  local_44 = (float *)(DAT_0292186c + 0x148);
  fVar6 = fVar3 + 0.1;
  fVar7 = fVar4 + 0.1;
  *(undefined2 *)(DAT_0292fc68 + iVar22 * 0x203 + 0x6ee) = 8;
  sVar25 = (short)DAT_0292fc68[iVar22 * 0x203 + 0x6f1];
  piVar14 = DAT_0292fc68 + iVar22 * 0x203 + 0x6f1;
  pfVar16 = (float *)(iVar13 + 0x14c);
  param_1 = (float *)0x0;
  local_48 = (float *)(iVar13 + 0x93c);
  piVar24 = DAT_0292fc68;
  if (sVar25 < 1) goto LAB_0067123c;
  do {
    sVar2 = *(short *)((int)piVar14 + 2);
    pfVar17 = (float *)(*piVar24 + sVar2 * 0x38);
    piVar14 = piVar14 + 1;
    if (((pfVar17[4] < fVar6 == (pfVar17[4] == fVar6)) ||
        (pfVar17[6] < fVar7 == (pfVar17[6] == fVar7))) ||
       ((pfVar17[7] < fVar3 - 0.1 || ((pfVar17[9] <= fVar4 - 0.1 || (pfVar17[0xb] == -NAN)))))) {
      piVar14 = piVar14 + sVar25;
    }
    else {
      iVar13 = (int)sVar25;
      fVar8 = fVar6 - *pfVar17;
      fVar9 = fVar7 - pfVar17[2];
      fVar1 = (fVar3 - 0.1) - *pfVar17;
      fVar10 = (fVar4 - 0.1) - pfVar17[2];
      pfVar17 = pfVar16;
      if (3 < iVar13) {
        iVar19 = (iVar13 - 4U >> 2) + 1;
        iVar13 = iVar13 + iVar19 * -4;
        do {
          pfVar17 = (float *)*piVar14;
          if (((((*pfVar17 < fVar8 != (*pfVar17 == fVar8)) && (fVar1 < pfVar17[1])) &&
               (pfVar17[4] < fVar9 != (pfVar17[4] == fVar9))) &&
              ((fVar10 < pfVar17[5] && (pfVar16 < local_48)))) &&
             ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
              ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))) {
            *pfVar16 = (float)pfVar17;
            pfVar16 = pfVar16 + 1;
            param_1 = (float *)((int)param_1 + 1);
          }
          pfVar17 = (float *)piVar14[1];
          if ((((*pfVar17 < fVar8 != (*pfVar17 == fVar8)) && (fVar1 < pfVar17[1])) &&
              ((pfVar17[4] < fVar9 != (pfVar17[4] == fVar9) &&
               ((fVar10 < pfVar17[5] && (pfVar16 < local_48)))))) &&
             ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
              ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))) {
            *pfVar16 = (float)pfVar17;
            pfVar16 = pfVar16 + 1;
            param_1 = (float *)((int)param_1 + 1);
          }
          pfVar17 = (float *)piVar14[2];
          if ((((*pfVar17 < fVar8 != (*pfVar17 == fVar8)) && (fVar1 < pfVar17[1])) &&
              (pfVar17[4] < fVar9 != (pfVar17[4] == fVar9))) &&
             (((fVar10 < pfVar17[5] && (pfVar16 < local_48)) &&
              ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
               ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))))) {
            *pfVar16 = (float)pfVar17;
            pfVar16 = pfVar16 + 1;
            param_1 = (float *)((int)param_1 + 1);
          }
          pfVar17 = (float *)piVar14[3];
          if ((((*pfVar17 < fVar8 != (*pfVar17 == fVar8)) && (fVar1 < pfVar17[1])) &&
              ((pfVar17[4] < fVar9 != (pfVar17[4] == fVar9) &&
               ((fVar10 < pfVar17[5] && (pfVar16 < local_48)))))) &&
             ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
              ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))) {
            *pfVar16 = (float)pfVar17;
            pfVar16 = pfVar16 + 1;
            param_1 = (float *)((int)param_1 + 1);
          }
          piVar14 = piVar14 + 4;
          iVar19 = iVar19 + -1;
          pfVar17 = pfVar16;
          piVar24 = DAT_0292fc68;
        } while (iVar19 != 0);
      }
      for (; 0 < iVar13; iVar13 = iVar13 + -1) {
        pfVar16 = (float *)*piVar14;
        if (((((*pfVar16 < fVar8 != (*pfVar16 == fVar8)) && (fVar1 < pfVar16[1])) &&
             (pfVar16[4] < fVar9 != (pfVar16[4] == fVar9))) &&
            ((fVar10 < pfVar16[5] && (pfVar17 < local_48)))) &&
           ((*(byte *)((int)pfVar16 + 0x61) == 0 ||
            ((param_2 & *(byte *)((int)pfVar16 + 0x61)) != 0)))) {
          *pfVar17 = (float)pfVar16;
          pfVar17 = pfVar17 + 1;
          param_1 = (float *)((int)param_1 + 1);
        }
        piVar14 = piVar14 + 1;
        piVar24 = DAT_0292fc68;
      }
      pfVar16 = pfVar17;
      if (param_1 != (float *)0x0) {
        *(short *)local_44 = (short)param_1;
        *(short *)((int)local_44 + 2) = sVar2;
        pfVar16 = pfVar17 + 1;
        param_1 = (float *)0x0;
        piVar24 = DAT_0292fc68;
        local_44 = pfVar17;
      }
    }
    sVar25 = (short)*piVar14;
  } while (0 < sVar25);
LAB_00671244:
  local_3c = fVar4 - 0.1;
  local_40 = fVar3 - 0.1;
  local_40 = local_40 - 0.05;
  fVar3 = fVar3 + 0.1 + 0.05;
  local_3c = local_3c - 0.05;
  fVar4 = fVar4 + 0.1 + 0.05;
  if (param_3 != 0) {
    local_20 = (short *)(piVar24[0x6ed] + (short)piVar24[0x6e6] * 2);
    local_18 = 0;
    iVar13 = (int)param_1;
    if (0 < *(short *)((int)piVar24 + 0x1b9a)) {
      do {
        pfVar17 = (float *)(*piVar24 + *local_20 * 0x38);
        iVar19 = piVar24[0x1a] + *(short *)(pfVar17 + 0xc) * 0x6c;
        puVar5 = *(uint **)(iVar19 + 0x68);
        if (puVar5 == (uint *)0x0) {
LAB_00671300:
          if (*(int *)(iVar19 + 0x40) == 0) {
            local_30 = fVar3 - *pfVar17;
            local_28 = local_40 - *pfVar17;
            local_2c = pfVar17[2];
            local_24 = local_3c;
LAB_00671404:
            local_2c = fVar4 - local_2c;
            local_24 = local_24 - pfVar17[2];
          }
          else {
            iVar19 = *(short *)(pfVar17 + 0xc) * 0x6c + piVar24[0x1a];
            if (*(float *)(*(int *)(iVar19 + 0x40) + 0x30) <= *(float *)(iVar19 + 0x30)) {
              local_30 = fVar3 - *pfVar17;
              iVar19 = *(short *)(pfVar17 + 0xc) * 0x6c + piVar24[0x1a];
              local_28 = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x30) - *(float *)(iVar19 + 0x30)) *
                          1.5 + local_40) - *pfVar17;
            }
            else {
              local_28 = local_40 - *pfVar17;
              iVar19 = *(short *)(pfVar17 + 0xc) * 0x6c + piVar24[0x1a];
              local_30 = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x30) - *(float *)(iVar19 + 0x30)) *
                          1.5 + fVar3) - *pfVar17;
            }
            iVar19 = *(short *)(pfVar17 + 0xc) * 0x6c + piVar24[0x1a];
            if (*(float *)(*(int *)(iVar19 + 0x40) + 0x38) <= *(float *)(iVar19 + 0x38)) {
              local_2c = pfVar17[2];
              iVar19 = *(short *)(pfVar17 + 0xc) * 0x6c + piVar24[0x1a];
              local_24 = (*(float *)(*(int *)(iVar19 + 0x40) + 0x38) - *(float *)(iVar19 + 0x38)) *
                         1.5 + local_3c;
              goto LAB_00671404;
            }
            local_24 = local_3c - pfVar17[2];
            iVar19 = *(short *)(pfVar17 + 0xc) * 0x6c + piVar24[0x1a];
            local_2c = ((*(float *)(*(int *)(iVar19 + 0x40) + 0x38) - *(float *)(iVar19 + 0x38)) *
                        1.5 + fVar4) - pfVar17[2];
          }
          if (((pfVar17[4] < local_30 != (pfVar17[4] == local_30)) &&
              (pfVar17[6] < local_2c != (pfVar17[6] == local_2c))) &&
             ((local_28 <= pfVar17[7] && ((local_24 < pfVar17[9] && (pfVar17[0xb] != -NAN)))))) {
            sVar25 = *(short *)pfVar17[3];
            pfVar15 = (float *)pfVar17[3];
            pfVar17 = pfVar16;
            while (-1 < sVar25) {
              iVar19 = (int)*(short *)((int)pfVar15 + 2);
              pfVar16 = pfVar15 + 5;
              if ((((pfVar15[1] < local_30 == (pfVar15[1] == local_30)) || (pfVar15[2] <= local_28))
                  || (pfVar15[3] < local_2c == (pfVar15[3] == local_2c))) ||
                 (pfVar15[4] <= local_24)) {
                pfVar16 = pfVar16 + iVar19 * 0x19;
              }
              else {
                if (3 < iVar19) {
                  param_1 = (float *)((iVar19 - 4U >> 2) + 1);
                  iVar19 = iVar19 + (int)param_1 * -4;
                  do {
                    if ((((*pfVar16 < local_30 != (*pfVar16 == local_30)) && (local_28 < pfVar16[1])
                         ) && ((pfVar16[4] < local_2c != (pfVar16[4] == local_2c) &&
                               ((local_24 < pfVar16[5] && (pfVar17 < local_48)))))) &&
                       ((*(byte *)((int)pfVar16 + 0x61) == 0 ||
                        ((param_2 & *(byte *)((int)pfVar16 + 0x61)) != 0)))) {
                      *pfVar17 = (float)pfVar16;
                      pfVar17 = pfVar17 + 1;
                      iVar13 = iVar13 + 1;
                    }
                    if (((((pfVar16[0x19] < local_30 != (pfVar16[0x19] == local_30)) &&
                          (local_28 < pfVar16[0x1a])) &&
                         (pfVar16[0x1d] < local_2c != (pfVar16[0x1d] == local_2c))) &&
                        ((local_24 < pfVar16[0x1e] && (pfVar17 < local_48)))) &&
                       ((*(byte *)((int)pfVar16 + 0xc5) == 0 ||
                        ((param_2 & *(byte *)((int)pfVar16 + 0xc5)) != 0)))) {
                      *pfVar17 = (float)(pfVar16 + 0x19);
                      pfVar17 = pfVar17 + 1;
                      iVar13 = iVar13 + 1;
                    }
                    if (((pfVar16[0x32] < local_30 != (pfVar16[0x32] == local_30)) &&
                        (local_28 < pfVar16[0x33])) &&
                       (((pfVar16[0x36] < local_2c != (pfVar16[0x36] == local_2c) &&
                         ((local_24 < pfVar16[0x37] && (pfVar17 < local_48)))) &&
                        ((*(byte *)((int)pfVar16 + 0x129) == 0 ||
                         ((param_2 & *(byte *)((int)pfVar16 + 0x129)) != 0)))))) {
                      *pfVar17 = (float)(pfVar16 + 0x32);
                      pfVar17 = pfVar17 + 1;
                      iVar13 = iVar13 + 1;
                    }
                    if ((((pfVar16[0x4b] < local_30 != (pfVar16[0x4b] == local_30)) &&
                         (local_28 < pfVar16[0x4c])) &&
                        (pfVar16[0x4f] < local_2c != (pfVar16[0x4f] == local_2c))) &&
                       (((local_24 < pfVar16[0x50] && (pfVar17 < local_48)) &&
                        ((*(byte *)((int)pfVar16 + 0x18d) == 0 ||
                         ((param_2 & *(byte *)((int)pfVar16 + 0x18d)) != 0)))))) {
                      *pfVar17 = (float)(pfVar16 + 0x4b);
                      pfVar17 = pfVar17 + 1;
                      iVar13 = iVar13 + 1;
                    }
                    pfVar16 = pfVar16 + 100;
                    param_1 = (float *)((int)param_1 + -1);
                  } while (param_1 != (float *)0x0);
                }
                for (; 0 < iVar19; iVar19 = iVar19 + -1) {
                  if ((((*pfVar16 < local_30 != (*pfVar16 == local_30)) && (local_28 < pfVar16[1]))
                      && ((pfVar16[4] < local_2c != (pfVar16[4] == local_2c) &&
                          ((local_24 < pfVar16[5] && (pfVar17 < local_48)))))) &&
                     ((*(byte *)((int)pfVar16 + 0x61) == 0 ||
                      ((param_2 & *(byte *)((int)pfVar16 + 0x61)) != 0)))) {
                    *pfVar17 = (float)pfVar16;
                    pfVar17 = pfVar17 + 1;
                    iVar13 = iVar13 + 1;
                  }
                  pfVar16 = pfVar16 + 0x19;
                }
              }
              pfVar15 = pfVar16;
              piVar24 = DAT_0292fc68;
              sVar25 = *(short *)pfVar16;
            }
            pfVar16 = pfVar17;
            if (iVar13 != 0) {
              *(short *)local_44 = (short)iVar13;
              *(short *)((int)local_44 + 2) = *local_20;
              pfVar16 = pfVar17 + 1;
              iVar13 = 0;
              piVar24 = DAT_0292fc68;
              local_44 = pfVar17;
            }
          }
        }
        else if ((*(byte *)(iVar19 + 0x4c) & 4) == 0) {
          if ((*puVar5 & 1) != 0) goto LAB_00671300;
        }
        else if ((*puVar5 & 2) != 0) goto LAB_00671300;
        local_20 = local_20 + 1;
        local_18 = local_18 + 1;
        if (*(short *)((int)piVar24 + 0x1b9a) <= local_18) {
          *(undefined2 *)local_44 = 0;
          *(undefined2 *)((int)local_44 + 2) = 0;
          return;
        }
      } while( true );
    }
  }
  *(undefined2 *)((int)local_44 + 2) = 0;
  *(undefined2 *)local_44 = 0;
  return;
LAB_006708bb:
  fVar9 = fVar3 + 1.0;
  fVar8 = fVar4 + 1.0;
  pfVar15 = (float *)(DAT_0292fc68 + iVar19 * 0x203 + 0x6f2);
  iVar13 = 0;
  fVar7 = fVar3 - 1.0;
  pfVar21 = (float *)(DAT_0292fc68 + iVar19 * 0x203 + 0x6f1);
  pfVar16 = pfVar15 + 0x1fc;
  fVar6 = fVar4 - 1.0;
  local_14 = 0;
  piVar14 = DAT_0292fc68;
  if (0 < DAT_0292fc68[0x6ec]) {
    local_1c = 0;
    local_44 = pfVar21;
    do {
      fVar1 = *(float *)(local_1c + 0x79c + (int)piVar14);
      if (((fVar1 < fVar9 != (fVar1 == fVar9)) &&
          (fVar1 = *(float *)(local_1c + 0x7a0 + (int)piVar14), fVar1 < fVar8 != (fVar1 == fVar8)))
         && ((fVar7 <= *(float *)(local_1c + 0x7a4 + (int)piVar14) &&
             (fVar6 <= *(float *)(local_1c + 0x7a8 + (int)piVar14))))) {
        local_20 = (short *)(piVar14[0x6ed] + *(short *)(local_1c + 0x798 + (int)piVar14) * 2);
        local_18 = 0;
        if (0 < *(short *)(local_1c + 0x79a + (int)piVar14)) {
          do {
            pfVar18 = (float *)(*piVar14 + *local_20 * 0x38);
            if ((((pfVar18[4] < fVar9 != (pfVar18[4] == fVar9)) &&
                 (pfVar18[6] < fVar8 != (pfVar18[6] == fVar8))) && (fVar7 <= pfVar18[7])) &&
               ((fVar6 < pfVar18[9] && (pfVar18[0xb] != -NAN)))) {
              fVar1 = fVar9 - *pfVar18;
              fVar10 = fVar8 - pfVar18[2];
              fVar11 = fVar7 - *pfVar18;
              fVar12 = fVar6 - pfVar18[2];
              if (*(short *)(pfVar18 + 0xc) < 0) {
                FUN_0066f790(pfVar18);
                piVar14 = DAT_0292fc68;
              }
              pfVar18 = (float *)pfVar18[3];
              sVar25 = *(short *)pfVar18;
              pfVar23 = pfVar15;
              while (-1 < sVar25) {
                iVar20 = (int)*(short *)((int)pfVar18 + 2);
                pfVar15 = pfVar18 + 5;
                if (((pfVar18[1] < fVar1 == (pfVar18[1] == fVar1)) || (pfVar18[2] <= fVar11)) ||
                   ((pfVar18[3] < fVar10 == (pfVar18[3] == fVar10) || (pfVar18[4] <= fVar12)))) {
                  pfVar18 = pfVar15 + iVar20 * 0x19;
                }
                else {
                  pfVar18 = pfVar15;
                  if (3 < iVar20) {
                    iVar22 = (iVar20 - 4U >> 2) + 1;
                    iVar20 = iVar20 + iVar22 * -4;
                    do {
                      if ((((*pfVar15 < fVar1 != (*pfVar15 == fVar1)) && (fVar11 < pfVar15[1])) &&
                          (pfVar15[4] < fVar10 != (pfVar15[4] == fVar10))) &&
                         ((fVar12 < pfVar15[5] && (pfVar23 < pfVar16)))) {
                        *pfVar23 = (float)pfVar15;
                        pfVar23 = pfVar23 + 1;
                        iVar13 = iVar13 + 1;
                      }
                      if (((pfVar15[0x19] < fVar1 != (pfVar15[0x19] == fVar1)) &&
                          (fVar11 < pfVar15[0x1a])) &&
                         ((pfVar15[0x1d] < fVar10 != (pfVar15[0x1d] == fVar10) &&
                          ((fVar12 < pfVar15[0x1e] && (pfVar23 < pfVar16)))))) {
                        *pfVar23 = (float)(pfVar15 + 0x19);
                        pfVar23 = pfVar23 + 1;
                        iVar13 = iVar13 + 1;
                      }
                      if ((((pfVar15[0x32] < fVar1 != (pfVar15[0x32] == fVar1)) &&
                           (fVar11 < pfVar15[0x33])) &&
                          (pfVar15[0x36] < fVar10 != (pfVar15[0x36] == fVar10))) &&
                         ((fVar12 < pfVar15[0x37] && (pfVar23 < pfVar16)))) {
                        *pfVar23 = (float)(pfVar15 + 0x32);
                        pfVar23 = pfVar23 + 1;
                        iVar13 = iVar13 + 1;
                      }
                      if (((pfVar15[0x4b] < fVar1 != (pfVar15[0x4b] == fVar1)) &&
                          (fVar11 < pfVar15[0x4c])) &&
                         ((pfVar15[0x4f] < fVar10 != (pfVar15[0x4f] == fVar10) &&
                          ((fVar12 < pfVar15[0x50] && (pfVar23 < pfVar16)))))) {
                        *pfVar23 = (float)(pfVar15 + 0x4b);
                        pfVar23 = pfVar23 + 1;
                        iVar13 = iVar13 + 1;
                      }
                      pfVar15 = pfVar15 + 100;
                      iVar22 = iVar22 + -1;
                      pfVar18 = pfVar15;
                    } while (iVar22 != 0);
                  }
                  for (; pfVar21 = local_44, 0 < iVar20; iVar20 = iVar20 + -1) {
                    if ((((*pfVar18 < fVar1 != (*pfVar18 == fVar1)) && (fVar11 < pfVar18[1])) &&
                        (pfVar18[4] < fVar10 != (pfVar18[4] == fVar10))) &&
                       ((fVar12 < pfVar18[5] && (pfVar23 < pfVar16)))) {
                      *pfVar23 = (float)pfVar18;
                      pfVar23 = pfVar23 + 1;
                      iVar13 = iVar13 + 1;
                    }
                    pfVar18 = pfVar18 + 0x19;
                  }
                }
                piVar14 = DAT_0292fc68;
                sVar25 = *(short *)pfVar18;
              }
              pfVar15 = pfVar23;
              if (iVar13 != 0) {
                *(short *)pfVar21 = (short)iVar13;
                *(short *)((int)pfVar21 + 2) = *local_20;
                pfVar15 = pfVar23 + 1;
                iVar13 = 0;
                piVar14 = DAT_0292fc68;
                pfVar21 = pfVar23;
                local_44 = pfVar23;
              }
            }
            local_20 = local_20 + 1;
            local_18 = local_18 + 1;
          } while (local_18 < *(short *)(local_1c + 0x79a + (int)piVar14));
        }
      }
      local_1c = local_1c + 0x14;
      local_14 = local_14 + 1;
    } while (local_14 < piVar14[0x6ec]);
  }
  *(undefined2 *)(piVar14 + iVar19 * 0x203 + 0x6ee) = 8;
  DAT_0292fc68[iVar19 * 0x203 + 0x6ef] = (int)*param_1;
  param_1 = (float *)0x0;
  DAT_0292fc68[iVar19 * 0x203 + 0x6f0] = (int)pfVar17[2];
  iVar13 = DAT_0292186c;
  local_44 = (float *)(DAT_0292186c + 0x148);
  pfVar16 = (float *)(DAT_0292186c + 0x14c);
  fVar7 = fVar3 + 0.1;
  *(undefined2 *)pfVar21 = 0;
  *(undefined2 *)((int)pfVar21 + 2) = 0;
  sVar25 = (short)DAT_0292fc68[iVar19 * 0x203 + 0x6f1];
  fVar6 = fVar4 + 0.1;
  local_48 = (float *)(iVar13 + 0x93c);
  piVar14 = DAT_0292fc68 + iVar19 * 0x203 + 0x6f1;
  piVar24 = DAT_0292fc68;
  if (sVar25 < 1) {
LAB_0067123c:
    param_1 = (float *)0x0;
    piVar24 = DAT_0292fc68;
  }
  else {
    do {
      sVar2 = *(short *)((int)piVar14 + 2);
      pfVar17 = (float *)(*piVar24 + sVar2 * 0x38);
      piVar14 = piVar14 + 1;
      if (((pfVar17[4] < fVar7 == (pfVar17[4] == fVar7)) ||
          (pfVar17[6] < fVar6 == (pfVar17[6] == fVar6))) ||
         ((pfVar17[7] < fVar3 - 0.1 || ((pfVar17[9] <= fVar4 - 0.1 || (pfVar17[0xb] == -NAN)))))) {
        piVar14 = piVar14 + sVar25;
      }
      else {
        iVar13 = (int)sVar25;
        fVar9 = fVar7 - *pfVar17;
        fVar8 = fVar6 - pfVar17[2];
        fVar1 = (fVar3 - 0.1) - *pfVar17;
        fVar10 = (fVar4 - 0.1) - pfVar17[2];
        pfVar17 = pfVar16;
        if (3 < iVar13) {
          iVar19 = (iVar13 - 4U >> 2) + 1;
          iVar13 = iVar13 + iVar19 * -4;
          do {
            pfVar17 = (float *)*piVar14;
            if ((((*pfVar17 < fVar9 != (*pfVar17 == fVar9)) && (fVar1 < pfVar17[1])) &&
                (pfVar17[4] < fVar8 != (pfVar17[4] == fVar8))) &&
               (((fVar10 < pfVar17[5] && (pfVar16 < local_48)) &&
                ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
                 ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))))) {
              *pfVar16 = (float)pfVar17;
              pfVar16 = pfVar16 + 1;
              param_1 = (float *)((int)param_1 + 1);
            }
            pfVar17 = (float *)piVar14[1];
            if ((((*pfVar17 < fVar9 != (*pfVar17 == fVar9)) && (fVar1 < pfVar17[1])) &&
                ((pfVar17[4] < fVar8 != (pfVar17[4] == fVar8) &&
                 ((fVar10 < pfVar17[5] && (pfVar16 < local_48)))))) &&
               ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
                ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))) {
              *pfVar16 = (float)pfVar17;
              pfVar16 = pfVar16 + 1;
              param_1 = (float *)((int)param_1 + 1);
            }
            pfVar17 = (float *)piVar14[2];
            if (((((*pfVar17 < fVar9 != (*pfVar17 == fVar9)) && (fVar1 < pfVar17[1])) &&
                 (pfVar17[4] < fVar8 != (pfVar17[4] == fVar8))) &&
                ((fVar10 < pfVar17[5] && (pfVar16 < local_48)))) &&
               ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
                ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))) {
              *pfVar16 = (float)pfVar17;
              pfVar16 = pfVar16 + 1;
              param_1 = (float *)((int)param_1 + 1);
            }
            pfVar17 = (float *)piVar14[3];
            if (((*pfVar17 < fVar9 != (*pfVar17 == fVar9)) && (fVar1 < pfVar17[1])) &&
               (((pfVar17[4] < fVar8 != (pfVar17[4] == fVar8) &&
                 ((fVar10 < pfVar17[5] && (pfVar16 < local_48)))) &&
                ((*(byte *)((int)pfVar17 + 0x61) == 0 ||
                 ((param_2 & *(byte *)((int)pfVar17 + 0x61)) != 0)))))) {
              *pfVar16 = (float)pfVar17;
              pfVar16 = pfVar16 + 1;
              param_1 = (float *)((int)param_1 + 1);
            }
            piVar14 = piVar14 + 4;
            iVar19 = iVar19 + -1;
            pfVar17 = pfVar16;
            piVar24 = DAT_0292fc68;
          } while (iVar19 != 0);
        }
        for (; 0 < iVar13; iVar13 = iVar13 + -1) {
          pfVar16 = (float *)*piVar14;
          if ((((*pfVar16 < fVar9 != (*pfVar16 == fVar9)) && (fVar1 < pfVar16[1])) &&
              (pfVar16[4] < fVar8 != (pfVar16[4] == fVar8))) &&
             (((fVar10 < pfVar16[5] && (pfVar17 < local_48)) &&
              ((*(byte *)((int)pfVar16 + 0x61) == 0 ||
               ((param_2 & *(byte *)((int)pfVar16 + 0x61)) != 0)))))) {
            *pfVar17 = (float)pfVar16;
            pfVar17 = pfVar17 + 1;
            param_1 = (float *)((int)param_1 + 1);
          }
          piVar14 = piVar14 + 1;
          piVar24 = DAT_0292fc68;
        }
        pfVar16 = pfVar17;
        if (param_1 != (float *)0x0) {
          *(short *)local_44 = (short)param_1;
          *(short *)((int)local_44 + 2) = sVar2;
          pfVar16 = pfVar17 + 1;
          param_1 = (float *)0x0;
          piVar24 = DAT_0292fc68;
          local_44 = pfVar17;
        }
      }
      sVar25 = (short)*piVar14;
    } while (0 < sVar25);
  }
  goto LAB_00671244;
}

