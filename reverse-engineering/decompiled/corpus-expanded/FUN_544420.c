/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x544420; label: FUN_00544420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00544420(float *param_1)

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
  int iVar10;
  int iVar11;
  float *pfVar12;
  undefined4 uVar13;
  short *psVar14;
  float *pfVar15;
  float *pfVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 extraout_ST1;
  int local_40;
  
  if (DAT_029892c0 != 0) {
    pfVar15 = (float *)&DAT_02984560;
    local_40 = 8;
    do {
      if (*(char *)(pfVar15 + -0x2c0) != '\0') {
        if (DAT_00973734 * DAT_00973734 + pfVar15[-0x14] <=
            (pfVar15[-0x15] - DAT_00973720) * (pfVar15[-0x15] - DAT_00973720) +
            (pfVar15[-0x17] - DAT_00973718) * (pfVar15[-0x17] - DAT_00973718) +
            (pfVar15[-0x16] - DAT_0097371c) * (pfVar15[-0x16] - DAT_0097371c)) {
          *(undefined1 *)(pfVar15 + -7) = 0;
        }
        else {
          *(undefined1 *)(pfVar15 + -7) = 1;
          if (*(char *)((int)pfVar15 + -0x1b) != '\0') {
            if (*(short *)(pfVar15 + -5) != 0) {
              pfVar12 = pfVar15 + *(char *)((int)pfVar15 + -0x1a) * 6 + -0x2c0;
              fVar1 = pfVar12[-3];
              fVar2 = *pfVar12;
              fVar3 = pfVar15[-0x2bd];
              fVar4 = pfVar15[-0x2ba];
              fVar5 = pfVar12[2];
              fVar6 = pfVar12[-1];
              fVar7 = pfVar15[-699];
              fVar8 = pfVar15[-0x2b8];
              iVar10 = FUN_006e6b90();
              fVar9 = (float)(extraout_ST0 - (float10)iVar10);
              fVar17 = (float10)FUN_005c0240((float)extraout_ST1);
              fVar1 = ((*param_1 - (pfVar15[-0x2ba] + pfVar15[-0x2bd]) * 0.5) *
                       (((fVar5 + fVar6) - fVar7) - fVar8) * 0.5 +
                      (((fVar1 + fVar2) - fVar3) - fVar4) * 0.5 *
                      ((pfVar15[-0x2b8] + pfVar15[-699]) * 0.5 - param_1[2])) *
                      (float)((float10)2.0 / (fVar17 * (float10)pfVar15[-4]));
              if (fVar1 <= 1.0) {
                if (fVar1 < -1.0) {
                  fVar1 = -1.0;
                }
              }
              else {
                fVar1 = 1.0;
              }
              fVar2 = pfVar15[-2] * (3.0 - fVar1) * 0.25;
              fVar1 = pfVar15[-2] * (fVar1 + 3.0) * 0.25;
              if (fVar9 == 0.0) {
                if ((iVar10 < 1) || (*(char *)((int)pfVar15 + -0x1a) + -1 <= iVar10)) {
LAB_00544764:
                  *(short *)(pfVar15 + -5) = *(short *)(pfVar15 + -5) + -1;
                }
                else {
                  pfVar15[iVar10 * 6 + -0x22c] = fVar2 * *pfVar15 + pfVar15[iVar10 * 6 + -0x22c];
                  pfVar15[iVar10 * 6 + -0x229] = fVar1 * *pfVar15 + pfVar15[iVar10 * 6 + -0x229];
                  *(short *)(pfVar15 + -5) = *(short *)(pfVar15 + -5) + -1;
                }
              }
              else {
                if ((0 < iVar10) && (iVar10 < *(char *)((int)pfVar15 + -0x1a) + -1)) {
                  pfVar15[iVar10 * 6 + -0x22c] =
                       fVar2 * *pfVar15 * (1.0 - fVar9) + pfVar15[iVar10 * 6 + -0x22c];
                  pfVar15[iVar10 * 6 + -0x229] =
                       fVar1 * *pfVar15 * (1.0 - fVar9) + pfVar15[iVar10 * 6 + -0x229];
                }
                if (*(char *)((int)pfVar15 + -0x1a) + -1 <= iVar10 + 1) goto LAB_00544764;
                pfVar15[iVar10 * 6 + -0x226] =
                     pfVar15[iVar10 * 6 + -0x226] + fVar9 * *pfVar15 * fVar2;
                pfVar15[iVar10 * 6 + -0x223] =
                     fVar1 * *pfVar15 * fVar9 + pfVar15[iVar10 * 6 + -0x223];
                *(short *)(pfVar15 + -5) = *(short *)(pfVar15 + -5) + -1;
              }
            }
            iVar10 = FUN_0067c860((int)*(short *)(pfVar15 + -0x13));
            if (iVar10 != 0) {
              *(undefined2 *)(pfVar15 + -5) = 5;
            }
            iVar10 = FUN_0067c860((int)*(short *)((int)pfVar15 +
                                                 *(char *)((int)pfVar15 + -0x1a) * 2 + -0x4e));
            if (iVar10 != 0) {
              *(undefined2 *)(pfVar15 + -5) = 5;
            }
            iVar10 = 1;
            if (1 < *(char *)((int)pfVar15 + -0x1a) + -1) {
              psVar14 = (short *)((int)pfVar15 + -0x4a);
              do {
                iVar11 = FUN_0067c860((int)*psVar14);
                if (iVar11 != 0) {
                  *(undefined2 *)(pfVar15 + -5) = 5;
                }
                iVar10 = iVar10 + 1;
                psVar14 = psVar14 + 1;
              } while (iVar10 < *(char *)((int)pfVar15 + -0x1a) + -1);
            }
            if (*(short *)(pfVar15 + -5) == 0) {
              if (*(short *)((int)pfVar15 + -0xafe) < 0x4000) {
                *(short *)((int)pfVar15 + -0xafe) = *(short *)((int)pfVar15 + -0xafe) + 1;
              }
            }
            else {
              *(undefined2 *)((int)pfVar15 + -0xafe) = 0;
            }
            if (*(short *)((int)pfVar15 + -0xafe) < 0xb4) {
              iVar10 = 1;
              if (1 < *(char *)((int)pfVar15 + -0x1a) + -1) {
                pfVar12 = pfVar15 + -700;
                do {
                  pfVar12[0x95] = pfVar12[0x95] - pfVar15[-1] * pfVar12[0x95];
                  pfVar12[0x96] = (pfVar15[-2] - pfVar12[0x96] * pfVar15[-1]) + pfVar12[0x96];
                  pfVar12[0x97] = pfVar12[0x97] - pfVar15[-1] * pfVar12[0x97];
                  pfVar12[0x98] = pfVar12[0x98] - pfVar15[-1] * pfVar12[0x98];
                  pfVar12[0x99] = (pfVar15[-2] - pfVar15[-1] * pfVar12[0x99]) + pfVar12[0x99];
                  pfVar12[0x9a] = pfVar12[0x9a] - pfVar15[-1] * pfVar12[0x9a];
                  fVar1 = pfVar12[-1] - pfVar12[5];
                  pfVar12[0x95] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x95];
                  fVar1 = *pfVar12 - pfVar12[6];
                  pfVar12[0x96] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x96];
                  fVar1 = pfVar12[1] - pfVar12[7];
                  pfVar12[0x97] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x97];
                  fVar1 = pfVar12[0xb] - pfVar12[5];
                  pfVar12[0x95] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x95];
                  fVar1 = pfVar12[0xc] - pfVar12[6];
                  pfVar12[0x96] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x96];
                  fVar1 = pfVar12[0xd] - pfVar12[7];
                  pfVar12[0x97] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x97];
                  fVar1 = pfVar12[2] - pfVar12[8];
                  pfVar12[0x98] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x98];
                  fVar1 = pfVar12[3] - pfVar12[9];
                  pfVar12[0x99] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x99];
                  fVar1 = pfVar12[4] - pfVar12[10];
                  iVar10 = iVar10 + 1;
                  pfVar12[0x9a] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x9a];
                  fVar1 = pfVar12[0xe] - pfVar12[8];
                  pfVar12[0x98] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x98];
                  fVar1 = pfVar12[0xf] - pfVar12[9];
                  pfVar12[0x99] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x99];
                  fVar1 = pfVar12[0x10] - pfVar12[10];
                  pfVar12[0x9a] =
                       ABS(fVar1) * fVar1 * pfVar15[-3] * 0.5 + pfVar15[-3] * fVar1 + pfVar12[0x9a];
                  pfVar12 = pfVar12 + 6;
                } while (iVar10 < *(char *)((int)pfVar15 + -0x1a) + -1);
              }
              iVar10 = 1;
              if (1 < *(char *)((int)pfVar15 + -0x1a) + -1) {
                pfVar12 = pfVar15 + -0x18d;
                pfVar16 = pfVar15 + -0x226;
                do {
                  pfVar16[-0x91] = pfVar16[-1] + pfVar16[-0x91];
                  pfVar16[-0x90] = pfVar16[-0x90] + *pfVar16;
                  pfVar16[-0x8f] = pfVar16[1] + pfVar16[-0x8f];
                  pfVar16[-0x8e] = pfVar16[2] + pfVar16[-0x8e];
                  pfVar16[-0x8d] = pfVar16[3] + pfVar16[-0x8d];
                  pfVar16[-0x8c] = pfVar16[4] + pfVar16[-0x8c];
                  FUN_005b4670(pfVar12,(int)*(short *)((int)pfVar15 + -0x12));
                  fVar17 = (float10)FUN_005c0240((pfVar16[-0x8e] - pfVar16[-0x91]) *
                                                 (pfVar16[-0x8e] - pfVar16[-0x91]) +
                                                 (pfVar16[-0x8c] - pfVar16[-0x8f]) *
                                                 (pfVar16[-0x8c] - pfVar16[-0x8f]));
                  uVar13 = FUN_005be2d0(pfVar16[-0x8d] - pfVar16[-0x90],(float)fVar17);
                  FUN_005b4dd0(pfVar12,uVar13);
                  fVar1 = ((pfVar16[-0x88] + pfVar16[-0x8b]) - pfVar16[-0x97]) - pfVar16[-0x94];
                  fVar2 = ((pfVar16[-0x86] + pfVar16[-0x89]) - pfVar16[-0x95]) - pfVar16[-0x92];
                  fVar17 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1 * fVar1);
                  uVar13 = FUN_005be2d0(((pfVar16[-0x8a] + pfVar16[-0x87]) - pfVar16[-0x96]) -
                                        pfVar16[-0x93],(float)fVar17);
                  FUN_005b5240(pfVar12,uVar13);
                  iVar10 = iVar10 + 1;
                  pfVar12[0xc] = (pfVar16[-0x91] + pfVar16[-0x8e]) * 0.5;
                  pfVar12[0xd] = (pfVar16[-0x90] + pfVar16[-0x8d]) * 0.5;
                  pfVar12[0xe] = (pfVar16[-0x8f] + pfVar16[-0x8c]) * 0.5;
                  pfVar12 = pfVar12 + 0x10;
                  pfVar16 = pfVar16 + 6;
                } while (iVar10 < *(char *)((int)pfVar15 + -0x1a) + -1);
              }
              pfVar12 = pfVar15 + -0x19d;
              FUN_005b4670(pfVar12,(int)*(short *)((int)pfVar15 + -0x12));
              fVar17 = (float10)FUN_005c0240((pfVar15[-0x2ba] - pfVar15[-0x2bd]) *
                                             (pfVar15[-0x2ba] - pfVar15[-0x2bd]) +
                                             (pfVar15[-0x2b8] - pfVar15[-699]) *
                                             (pfVar15[-0x2b8] - pfVar15[-699]));
              uVar13 = FUN_005be2d0(pfVar15[-0x2b9] - pfVar15[-700],(float)fVar17);
              FUN_005b4dd0(pfVar12,uVar13);
              fVar1 = ((pfVar15[-0x2b2] + pfVar15[-0x2b5]) - pfVar15[-699]) - pfVar15[-0x2b8];
              fVar2 = ((pfVar15[-0x2b4] + pfVar15[-0x2b7]) - pfVar15[-0x2bd]) - pfVar15[-0x2ba];
              fVar17 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1 * fVar1);
              fVar1 = (pfVar15[-0x2b9] + pfVar15[-700] + pfVar15[-0x2b6] + pfVar15[-0x2b3]) * 0.25;
              uVar13 = FUN_005be2d0((pfVar15[-0x2b3] + pfVar15[-0x2b6]) - (fVar1 + fVar1),
                                    (float)fVar17);
              FUN_005b5240(pfVar12,uVar13);
              pfVar15[-0x191] = (pfVar15[-0x2ba] + pfVar15[-0x2bd]) * 0.5;
              pfVar15[-400] = fVar1;
              pfVar15[-399] = (pfVar15[-0x2b8] + pfVar15[-699]) * 0.5;
              FUN_005b4670(pfVar15 + *(char *)((int)pfVar15 + -0x1a) * 0x10 + -0x1ad,
                           (int)*(short *)((int)pfVar15 + -0x12));
              iVar10 = (int)*(char *)((int)pfVar15 + -0x1a);
              fVar17 = (float10)FUN_005c0240((pfVar15[iVar10 * 6 + -0x2c4] -
                                             pfVar15[iVar10 * 6 + -0x2c7]) *
                                             (pfVar15[iVar10 * 6 + -0x2c4] -
                                             pfVar15[iVar10 * 6 + -0x2c7]) +
                                             (pfVar15[iVar10 * 6 + -0x2c6] -
                                             pfVar15[iVar10 * 6 + -0x2c9]) *
                                             (pfVar15[iVar10 * 6 + -0x2c6] -
                                             pfVar15[iVar10 * 6 + -0x2c9]));
              uVar13 = FUN_005be2d0(pfVar15[*(char *)((int)pfVar15 + -0x1a) * 6 + -0x2c5] -
                                    pfVar15[*(char *)((int)pfVar15 + -0x1a) * 6 + -0x2c8],
                                    (float)fVar17);
              FUN_005b4dd0(pfVar12,uVar13);
              pfVar12 = pfVar15 + *(char *)((int)pfVar15 + -0x1a) * 6 + -0x2c0;
              fVar1 = ((pfVar12[-3] + *pfVar12) - pfVar12[-9]) - pfVar12[-6];
              fVar2 = ((pfVar12[-1] + pfVar12[2]) - pfVar12[-7]) - pfVar12[-4];
              fVar17 = (float10)FUN_005c0240(fVar2 * fVar2 + fVar1 * fVar1);
              iVar10 = (int)*(char *)((int)pfVar15 + -0x1a);
              fVar1 = (pfVar15[iVar10 * 6 + -0x2c8] +
                       pfVar15[iVar10 * 6 + -0x2c2] + pfVar15[iVar10 * 6 + -0x2bf] +
                      pfVar15[iVar10 * 6 + -0x2c5]) * 0.25;
              uVar13 = FUN_005be2d0((pfVar15[iVar10 * 6 + -0x2c2] + pfVar15[iVar10 * 6 + -0x2bf]) -
                                    (fVar1 + fVar1),(float)fVar17);
              FUN_005b5240(pfVar15 + *(char *)((int)pfVar15 + -0x1a) * 0x10 + -0x1ad,uVar13);
              pfVar15[*(char *)((int)pfVar15 + -0x1a) * 0x10 + -0x1a1] =
                   ((pfVar15 + *(char *)((int)pfVar15 + -0x1a) * 6 + -0x2c0)[-3] +
                   pfVar15[*(char *)((int)pfVar15 + -0x1a) * 6 + -0x2c0]) * 0.5;
              pfVar15[(*(char *)((int)pfVar15 + -0x1a) + 0x12) * 0x10 + -0x2c0] = fVar1;
              iVar10 = (int)*(char *)((int)pfVar15 + -0x1a);
              pfVar15[iVar10 * 0x10 + -0x19f] =
                   (pfVar15[iVar10 * 6 + -0x2be] + pfVar15[iVar10 * 6 + -0x2c1]) * 0.5;
            }
          }
        }
      }
      pfVar15 = pfVar15 + 0x2c3;
      local_40 = local_40 + -1;
    } while (local_40 != 0);
  }
  return;
}

