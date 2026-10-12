/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67eac0; label: FUN_0067eac0
 */

void FUN_0067eac0(byte param_1,int *param_2)

{
  char *pcVar1;
  int *piVar2;
  float *pfVar3;
  float fVar4;
  short sVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int *piVar14;
  int *piVar15;
  int *piVar16;
  int *piVar17;
  float10 fVar18;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_14;
  float local_10;
  int *local_c;
  
  piVar16 = param_2;
  iVar11 = DAT_0292186c;
  if (param_2 != (int *)0x0) {
    local_c = (int *)(DAT_0292186c + 0x148);
    pcVar1 = (char *)(DAT_0292186c + 0x34);
    piVar17 = (int *)(DAT_0292186c + 0x14c);
    piVar2 = (int *)(DAT_0292186c + 0x93c);
    DAT_0292119c = 0;
    *(undefined2 *)(DAT_0292186c + 0x8a) = 0xffff;
    if (*pcVar1 == '\x01') {
      if (*(float *)(iVar11 + 0x28) <= 0.0) {
        local_40 = ((*(float *)(iVar11 + 0x28) + *(float *)(iVar11 + 0x1c)) - 0.02) -
                   *(float *)(iVar11 + 0x50);
        fVar4 = *(float *)(iVar11 + 0x1c);
      }
      else {
        local_40 = (*(float *)(iVar11 + 0x1c) - 0.02) - *(float *)(iVar11 + 0x50);
        fVar4 = *(float *)(iVar11 + 0x28) + *(float *)(iVar11 + 0x1c);
      }
      local_44 = fVar4 + 0.02 + *(float *)(iVar11 + 0x50);
      if (*(float *)(iVar11 + 0x2c) <= 0.0) {
        local_30 = ((*(float *)(iVar11 + 0x2c) + *(float *)(iVar11 + 0x20)) - 0.02) -
                   *(float *)(iVar11 + 0x50);
        fVar4 = *(float *)(iVar11 + 0x20);
      }
      else {
        local_30 = (*(float *)(iVar11 + 0x20) - 0.02) - *(float *)(iVar11 + 0x50);
        fVar4 = *(float *)(iVar11 + 0x2c) + *(float *)(iVar11 + 0x20);
      }
      local_34 = fVar4 + 0.02 + *(float *)(iVar11 + 0x50);
      if (*(float *)(iVar11 + 0x30) <= 0.0) {
        local_38 = ((*(float *)(iVar11 + 0x30) + *(float *)(iVar11 + 0x24)) - 0.02) -
                   *(float *)(iVar11 + 0x50);
        fVar4 = *(float *)(iVar11 + 0x24);
      }
      else {
        local_38 = (*(float *)(iVar11 + 0x24) - 0.02) - *(float *)(iVar11 + 0x50);
        fVar4 = *(float *)(iVar11 + 0x30) + *(float *)(iVar11 + 0x24);
      }
      local_3c = fVar4 + 0.02 + *(float *)(iVar11 + 0x50);
      fVar4 = (local_38 - local_3c) * (local_38 - local_3c) +
              (local_40 - local_44) * (local_40 - local_44) +
              (local_30 - local_34) * (local_30 - local_34) + 1.02;
    }
    else {
      fVar4 = *(float *)(iVar11 + 0x54) + 0.02 +
              *(float *)(iVar11 + 0x30) * *(float *)(iVar11 + 0x30) +
              *(float *)(iVar11 + 0x28) * *(float *)(iVar11 + 0x28) +
              *(float *)(iVar11 + 0x2c) * *(float *)(iVar11 + 0x2c);
      local_44 = fVar4 + *(float *)(iVar11 + 0x1c);
      local_30 = *(float *)(iVar11 + 0x5c) * fVar4;
      local_34 = *(float *)(iVar11 + 0x20) + local_30;
      local_3c = fVar4 + *(float *)(iVar11 + 0x24);
      local_40 = *(float *)(iVar11 + 0x1c) - fVar4;
      local_30 = *(float *)(iVar11 + 0x20) - local_30;
      local_38 = *(float *)(iVar11 + 0x24) - fVar4;
      fVar4 = fVar4 + 1.0;
    }
    fVar18 = (float10)FUN_005c0240(fVar4);
    iVar11 = *param_2;
    param_2 = (int *)0x0;
    sVar5 = (short)iVar11;
    piVar14 = DAT_0292fc68;
    while (0 < sVar5) {
      sVar5 = *(short *)((int)piVar16 + 2);
      pfVar3 = (float *)(*piVar14 + sVar5 * 0x38);
      piVar15 = piVar16 + 1;
      if (*(int *)(*piVar14 + 0x2c + sVar5 * 0x38) == 1) {
        iVar11 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
        if (*(int *)(iVar11 + 0x40) == 0) goto LAB_0067f35b;
        iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
        if (*(float *)(*(int *)(iVar12 + 0x40) + 0x30) <= *(float *)(iVar12 + 0x30)) {
          local_28 = local_44 - *pfVar3;
          iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
          local_2c = ((*(float *)(*(int *)(iVar12 + 0x40) + 0x30) - *(float *)(iVar12 + 0x30)) * 1.5
                     + local_40) - *pfVar3;
        }
        else {
          local_2c = local_40 - *pfVar3;
          iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
          local_28 = ((*(float *)(*(int *)(iVar12 + 0x40) + 0x30) - *(float *)(iVar12 + 0x30)) * 1.5
                     + local_44) - *pfVar3;
        }
        iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
        if (*(float *)(*(int *)(iVar12 + 0x40) + 0x34) <= *(float *)(iVar12 + 0x34)) {
          local_10 = local_34 - pfVar3[1];
          iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
          local_14 = (local_30 +
                     (*(float *)(*(int *)(iVar12 + 0x40) + 0x34) - *(float *)(iVar12 + 0x34)) * 1.5)
                     - pfVar3[1];
        }
        else {
          local_14 = local_30 - pfVar3[1];
          iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
          local_10 = (local_34 +
                     (*(float *)(*(int *)(iVar12 + 0x40) + 0x34) - *(float *)(iVar12 + 0x34)) * 1.5)
                     - pfVar3[1];
        }
        iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
        if (*(float *)(*(int *)(iVar12 + 0x40) + 0x38) <= *(float *)(iVar12 + 0x38)) {
          local_20 = local_3c - pfVar3[2];
          iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
          local_24 = (local_38 +
                     (*(float *)(*(int *)(iVar12 + 0x40) + 0x38) - *(float *)(iVar12 + 0x38)) * 1.5)
                     - pfVar3[2];
        }
        else {
          local_24 = local_38 - pfVar3[2];
          iVar12 = *(short *)(pfVar3 + 0xc) * 0x6c + piVar14[0x1a];
          local_20 = (local_3c +
                     (*(float *)(*(int *)(iVar12 + 0x40) + 0x38) - *(float *)(iVar12 + 0x38)) * 1.5)
                     - pfVar3[2];
        }
        if (*(short *)(pfVar3 + 0xc) != DAT_00810b2c) {
          if ((*(byte *)(iVar11 + 0x4c) & 1) == 0) {
            if (((pfVar3[4] < local_28 == (pfVar3[4] == local_28)) ||
                (pfVar3[5] < local_10 == (pfVar3[5] == local_10))) ||
               ((pfVar3[6] < local_20 == (pfVar3[6] == local_20) ||
                ((pfVar3[7] < local_2c || (pfVar3[8] <= local_14)))))) goto LAB_0067f1c4;
            if (pfVar3[9] <= local_24) {
              piVar16 = piVar16 + (short)*piVar16 + 1;
            }
            else {
              iVar11 = (int)(short)*piVar16;
              piVar16 = piVar15;
              if (3 < iVar11) {
                iVar12 = (iVar11 - 4U >> 2) + 1;
                iVar11 = iVar11 + iVar12 * -4;
                do {
                  pfVar3 = (float *)*piVar15;
                  if (((((((*pfVar3 < local_28 != (*pfVar3 == local_28)) && (local_2c < pfVar3[1]))
                         && (pfVar3[4] < local_20 != (pfVar3[4] == local_20))) &&
                        ((local_24 < pfVar3[5] && (pfVar3[2] < local_10 != (pfVar3[2] == local_10)))
                        )) && (local_14 < pfVar3[3])) && (piVar17 < piVar2)) &&
                     ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                      ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
                    *piVar17 = (int)pfVar3;
                    piVar17 = piVar17 + 1;
                    param_2 = (int *)((int)param_2 + 1);
                  }
                  pfVar3 = (float *)piVar15[1];
                  if (((((*pfVar3 < local_28 != (*pfVar3 == local_28)) && (local_2c < pfVar3[1])) &&
                       (pfVar3[4] < local_20 != (pfVar3[4] == local_20))) &&
                      (((local_24 < pfVar3[5] && (pfVar3[2] < local_10 != (pfVar3[2] == local_10)))
                       && ((local_14 < pfVar3[3] && (piVar17 < piVar2)))))) &&
                     ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                      ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
                    *piVar17 = (int)pfVar3;
                    piVar17 = piVar17 + 1;
                    param_2 = (int *)((int)param_2 + 1);
                  }
                  pfVar3 = (float *)piVar15[2];
                  if ((((*pfVar3 < local_28 != (*pfVar3 == local_28)) && (local_2c < pfVar3[1])) &&
                      (pfVar3[4] < local_20 != (pfVar3[4] == local_20))) &&
                     ((((local_24 < pfVar3[5] && (pfVar3[2] < local_10 != (pfVar3[2] == local_10)))
                       && ((local_14 < pfVar3[3] && (piVar17 < piVar2)))) &&
                      ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                       ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))))) {
                    *piVar17 = (int)pfVar3;
                    piVar17 = piVar17 + 1;
                    param_2 = (int *)((int)param_2 + 1);
                  }
                  pfVar3 = (float *)piVar15[3];
                  if ((((((*pfVar3 < local_28 != (*pfVar3 == local_28)) && (local_2c < pfVar3[1]))
                        && (pfVar3[4] < local_20 != (pfVar3[4] == local_20))) &&
                       ((local_24 < pfVar3[5] && (pfVar3[2] < local_10 != (pfVar3[2] == local_10))))
                       ) && ((local_14 < pfVar3[3] && (piVar17 < piVar2)))) &&
                     ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                      ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
                    *piVar17 = (int)pfVar3;
                    piVar17 = piVar17 + 1;
                    param_2 = (int *)((int)param_2 + 1);
                  }
                  piVar15 = piVar15 + 4;
                  iVar12 = iVar12 + -1;
                  piVar14 = DAT_0292fc68;
                  piVar16 = piVar15;
                } while (iVar12 != 0);
              }
              for (; 0 < iVar11; iVar11 = iVar11 + -1) {
                pfVar3 = (float *)*piVar16;
                if (((((*pfVar3 < local_28 != (*pfVar3 == local_28)) && (local_2c < pfVar3[1])) &&
                     (pfVar3[4] < local_20 != (pfVar3[4] == local_20))) &&
                    (((local_24 < pfVar3[5] && (pfVar3[2] < local_10 != (pfVar3[2] == local_10))) &&
                     ((local_14 < pfVar3[3] && (piVar17 < piVar2)))))) &&
                   ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                    ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
                  *piVar17 = (int)pfVar3;
                  piVar17 = piVar17 + 1;
                  param_2 = (int *)((int)param_2 + 1);
                }
                piVar14 = DAT_0292fc68;
                piVar16 = piVar16 + 1;
              }
            }
            goto LAB_0067f6b1;
          }
          fVar6 = ((local_30 + local_34) * 0.5 - pfVar3[1]) * *(float *)(DAT_0292186c + 100);
          fVar7 = (local_40 + local_44) * 0.5 - *pfVar3;
          fVar4 = (local_38 + local_3c) * 0.5 - pfVar3[2];
          if (fVar7 * fVar7 + fVar6 * fVar6 + fVar4 * fVar4 <
              (pfVar3[0xd] + (float)fVar18) * (pfVar3[0xd] + (float)fVar18)) {
            iVar11 = (int)(short)*piVar16;
            piVar16 = piVar15;
            for (; 0 < iVar11; iVar11 = iVar11 + -1) {
              if (piVar17 < piVar2) {
                iVar12 = *piVar16;
                if ((((*(byte *)(iVar12 + 0x61) == 0) || ((param_1 & *(byte *)(iVar12 + 0x61)) != 0)
                     ) && ((local_2c < *(float *)(iVar12 + 0x18) ||
                           (((local_2c < *(float *)(iVar12 + 0x24) ||
                             (local_2c < *(float *)(iVar12 + 0x30))) ||
                            (local_2c < *(float *)(iVar12 + 0x3c))))))) &&
                   ((((*(float *)(iVar12 + 0x18) < local_28 ||
                      (*(float *)(iVar12 + 0x24) < local_28)) ||
                     ((*(float *)(iVar12 + 0x30) < local_28 ||
                      (*(float *)(iVar12 + 0x3c) < local_28)))) &&
                    ((((local_24 < *(float *)(iVar12 + 0x20) ||
                       (local_24 < *(float *)(iVar12 + 0x2c))) ||
                      ((local_24 < *(float *)(iVar12 + 0x38) ||
                       (local_24 < *(float *)(iVar12 + 0x44))))) &&
                     ((((*(float *)(iVar12 + 0x20) < local_20 ||
                        (*(float *)(iVar12 + 0x2c) < local_20)) ||
                       (*(float *)(iVar12 + 0x38) < local_20)) ||
                      (*(float *)(iVar12 + 0x44) < local_20)))))))) {
                  *piVar17 = iVar12;
                  piVar17 = piVar17 + 1;
                  param_2 = (int *)((int)param_2 + 1);
                }
              }
              piVar16 = piVar16 + 1;
              piVar14 = DAT_0292fc68;
            }
            goto LAB_0067f6b1;
          }
          goto LAB_0067f1c4;
        }
        piVar16 = piVar16 + (short)*piVar16 + 1;
      }
      else {
LAB_0067f35b:
        if (((((pfVar3[4] < local_44 == (pfVar3[4] == local_44)) ||
              (pfVar3[5] < local_34 == (pfVar3[5] == local_34))) ||
             (pfVar3[6] < local_3c == (pfVar3[6] == local_3c))) ||
            ((pfVar3[7] < local_40 || (pfVar3[8] <= local_30)))) || (pfVar3[9] <= local_38)) {
LAB_0067f1c4:
          piVar16 = piVar16 + (short)*piVar16 + 1;
        }
        else {
          iVar11 = (int)(short)*piVar16;
          fVar10 = local_44 - *pfVar3;
          fVar7 = local_40 - *pfVar3;
          fVar4 = local_34 - pfVar3[1];
          fVar8 = local_30 - pfVar3[1];
          fVar6 = local_3c - pfVar3[2];
          fVar9 = local_38 - pfVar3[2];
          piVar16 = piVar15;
          if (3 < iVar11) {
            iVar12 = (iVar11 - 4U >> 2) + 1;
            iVar11 = iVar11 + iVar12 * -4;
            do {
              pfVar3 = (float *)*piVar15;
              if ((((*pfVar3 < fVar10 != (*pfVar3 == fVar10)) && (fVar7 < pfVar3[1])) &&
                  ((pfVar3[4] < fVar6 != (pfVar3[4] == fVar6) &&
                   (((fVar9 < pfVar3[5] && (pfVar3[2] < fVar4 != (pfVar3[2] == fVar4))) &&
                    (fVar8 < pfVar3[3])))))) &&
                 ((piVar17 < piVar2 &&
                  ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                   ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))))) {
                *piVar17 = (int)pfVar3;
                piVar17 = piVar17 + 1;
                param_2 = (int *)((int)param_2 + 1);
              }
              pfVar3 = (float *)piVar15[1];
              if (((((*pfVar3 < fVar10 != (*pfVar3 == fVar10)) && (fVar7 < pfVar3[1])) &&
                   ((pfVar3[4] < fVar6 != (pfVar3[4] == fVar6) &&
                    (((fVar9 < pfVar3[5] && (pfVar3[2] < fVar4 != (pfVar3[2] == fVar4))) &&
                     (fVar8 < pfVar3[3])))))) && (piVar17 < piVar2)) &&
                 ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                  ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
                *piVar17 = (int)pfVar3;
                piVar17 = piVar17 + 1;
                param_2 = (int *)((int)param_2 + 1);
              }
              pfVar3 = (float *)piVar15[2];
              if ((((*pfVar3 < fVar10 != (*pfVar3 == fVar10)) && (fVar7 < pfVar3[1])) &&
                  ((pfVar3[4] < fVar6 != (pfVar3[4] == fVar6) &&
                   ((((fVar9 < pfVar3[5] && (pfVar3[2] < fVar4 != (pfVar3[2] == fVar4))) &&
                     (fVar8 < pfVar3[3])) && (piVar17 < piVar2)))))) &&
                 ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                  ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
                *piVar17 = (int)pfVar3;
                piVar17 = piVar17 + 1;
                param_2 = (int *)((int)param_2 + 1);
              }
              pfVar3 = (float *)piVar15[3];
              if ((((*pfVar3 < fVar10 != (*pfVar3 == fVar10)) && (fVar7 < pfVar3[1])) &&
                  ((pfVar3[4] < fVar6 != (pfVar3[4] == fVar6) &&
                   (((fVar9 < pfVar3[5] && (pfVar3[2] < fVar4 != (pfVar3[2] == fVar4))) &&
                    (fVar8 < pfVar3[3])))))) &&
                 ((piVar17 < piVar2 &&
                  ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                   ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))))) {
                *piVar17 = (int)pfVar3;
                piVar17 = piVar17 + 1;
                param_2 = (int *)((int)param_2 + 1);
              }
              piVar15 = piVar15 + 4;
              iVar12 = iVar12 + -1;
              piVar14 = DAT_0292fc68;
              piVar16 = piVar15;
            } while (iVar12 != 0);
          }
          for (; 0 < iVar11; iVar11 = iVar11 + -1) {
            pfVar3 = (float *)*piVar16;
            if (((((*pfVar3 < fVar10 != (*pfVar3 == fVar10)) && (fVar7 < pfVar3[1])) &&
                 ((pfVar3[4] < fVar6 != (pfVar3[4] == fVar6) &&
                  (((fVar9 < pfVar3[5] && (pfVar3[2] < fVar4 != (pfVar3[2] == fVar4))) &&
                   (fVar8 < pfVar3[3])))))) && (piVar17 < piVar2)) &&
               ((*(byte *)((int)pfVar3 + 0x61) == 0 ||
                ((param_1 & *(byte *)((int)pfVar3 + 0x61)) != 0)))) {
              *piVar17 = (int)pfVar3;
              piVar17 = piVar17 + 1;
              param_2 = (int *)((int)param_2 + 1);
            }
            piVar14 = DAT_0292fc68;
            piVar16 = piVar16 + 1;
          }
        }
      }
LAB_0067f6b1:
      piVar15 = piVar17;
      if (param_2 != (int *)0x0) {
        *(short *)local_c = (short)param_2;
        *(short *)((int)local_c + 2) = sVar5;
        piVar15 = piVar17 + 1;
        param_2 = (int *)0x0;
        piVar14 = DAT_0292fc68;
        local_c = piVar17;
      }
      piVar17 = piVar15;
      sVar5 = (short)*piVar16;
    }
    piVar16 = piVar16 + 1;
    *(undefined2 *)local_c = 0;
    *(undefined2 *)((int)local_c + 2) = 0;
    DAT_02924ab8 = 0;
    local_44 = local_44 + 0.02;
    local_3c = local_3c + 0.02;
    pfVar3 = (float *)*piVar16;
    pfVar13 = DAT_0292fb50;
    while (pfVar3 != (float *)0x0) {
      if ((((local_40 - 0.02 <= *pfVar3) && (pfVar3[4] < local_44 != (pfVar3[4] == local_44))) ||
          ((local_40 - 0.02 <= pfVar3[4] && (*pfVar3 < local_44 != (*pfVar3 == local_44))))) &&
         ((((local_38 - 0.02 <= pfVar3[2] && (pfVar3[6] < local_3c != (pfVar3[6] == local_3c))) ||
           ((local_38 - 0.02 <= pfVar3[6] && (pfVar3[2] < local_3c != (pfVar3[2] == local_3c))))) &&
          (DAT_02924ab8 < 0x40)))) {
        *pfVar13 = *pfVar3;
        pfVar13[1] = pfVar3[1];
        pfVar13[2] = pfVar3[2];
        pfVar13[3] = pfVar3[3];
        iVar11 = *piVar16;
        pfVar13[4] = *(float *)(iVar11 + 0x10);
        pfVar13[5] = *(float *)(iVar11 + 0x14);
        pfVar13[6] = *(float *)(iVar11 + 0x18);
        pfVar13[7] = *(float *)(iVar11 + 0x1c);
        DAT_02924ab8 = DAT_02924ab8 + 2;
        pfVar13 = pfVar13 + 8;
      }
      piVar17 = piVar16 + 1;
      piVar16 = piVar16 + 1;
      pfVar3 = (float *)*piVar17;
    }
    DAT_00810b2c = -1;
  }
  return;
}

