/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67dca0; label: FUN_0067dca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0067dca0(int *param_1,float *param_2,float *param_3,float param_4,byte param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *local_48;
  int local_44;
  float local_40;
  float local_3c;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int *local_10;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  if ((int *)(DAT_02962b30 + 0x63c18) < DAT_02948ed8 + 1) {
    return (int *)0x0;
  }
  local_48 = DAT_02948ed8 + 0x1fd;
  if ((int *)(DAT_02962b30 + 0x63da8) < DAT_02948ed8 + 0x1fd) {
    local_48 = (int *)(DAT_02962b30 + 0x63da8);
  }
  fVar2 = *param_2;
  if (*param_3 <= 0.0) {
    fVar2 = fVar2 + *param_3;
    fVar3 = *param_2;
  }
  else {
    fVar3 = *param_2 + *param_3;
  }
  local_3c = (fVar2 - 0.02) - param_4;
  fVar3 = fVar3 + 0.02 + param_4;
  fVar2 = param_2[1];
  if (param_3[1] <= 0.0) {
    fVar2 = fVar2 + param_3[1];
    fVar4 = param_2[1];
  }
  else {
    fVar4 = param_2[1] + param_3[1];
  }
  local_2c = (fVar2 - 0.02) - param_4;
  fVar4 = fVar4 + 0.02 + param_4;
  fVar2 = param_2[2];
  if (param_3[2] <= 0.0) {
    fVar2 = fVar2 + param_3[2];
    fVar5 = param_2[2];
  }
  else {
    fVar5 = param_2[2] + param_3[2];
  }
  local_40 = (fVar2 - 0.02) - param_4;
  iVar13 = 0;
  sVar6 = (short)*param_1;
  param_4 = fVar5 + 0.02 + param_4;
  local_44 = 0;
  piVar11 = DAT_02948ed8 + 1;
  local_10 = DAT_02948ed8;
  piVar16 = DAT_0292fc68;
  do {
    if (sVar6 < 1) {
      param_1 = param_1 + 1;
      *(undefined2 *)local_10 = 0;
      *(undefined2 *)((int)local_10 + 2) = 0;
      local_10 = local_10 + 1;
      fVar3 = fVar3 + 0.02;
      param_4 = param_4 + 0.02;
      pfVar1 = (float *)*param_1;
      while (0 < (int)pfVar1) {
        if (((((local_3c - 0.02 <= *pfVar1) && (pfVar1[4] < fVar3 != (pfVar1[4] == fVar3))) ||
             ((local_3c - 0.02 <= pfVar1[4] && (*pfVar1 < fVar3 != (*pfVar1 == fVar3))))) &&
            (((local_40 - 0.02 <= pfVar1[2] && (pfVar1[6] < param_4 != (pfVar1[6] == param_4))) ||
             ((local_40 - 0.02 <= pfVar1[6] && (pfVar1[2] < param_4 != (pfVar1[2] == param_4)))))))
           && ((*(byte *)((int)pfVar1 + 0xd) == 0 || ((param_5 & *(byte *)((int)pfVar1 + 0xd)) != 0)
               ))) {
          *local_10 = (int)pfVar1;
          local_10[1] = *param_1;
          local_10 = local_10 + 2;
        }
        piVar11 = param_1 + 2;
        param_1 = param_1 + 2;
        pfVar1 = (float *)*piVar11;
      }
      piVar11 = DAT_02948ed8;
      *(undefined2 *)local_10 = 0;
      *(undefined2 *)((int)local_10 + 2) = 0;
      DAT_02948ed8 = local_10 + 1;
      return piVar11;
    }
    sVar6 = *(short *)((int)param_1 + 2);
    pfVar1 = (float *)(*piVar16 + sVar6 * 0x38);
    if ((*(int *)(*piVar16 + 0x2c + sVar6 * 0x38) == 1) &&
       (iVar14 = piVar16[0x1a] + *(short *)(pfVar1 + 0xc) * 0x6c, *(int *)(iVar14 + 0x40) != 0)) {
      iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
      if (*(float *)(*(int *)(iVar13 + 0x40) + 0x30) <= *(float *)(iVar13 + 0x30)) {
        local_24 = fVar3 - *pfVar1;
        iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
        local_28 = (local_3c +
                   (*(float *)(*(int *)(iVar13 + 0x40) + 0x30) - *(float *)(iVar13 + 0x30)) * 1.5) -
                   *pfVar1;
      }
      else {
        local_28 = local_3c - *pfVar1;
        iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
        local_24 = (fVar3 + (*(float *)(*(int *)(iVar13 + 0x40) + 0x30) - *(float *)(iVar13 + 0x30))
                            * 1.5) - *pfVar1;
      }
      iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
      if (*(float *)(*(int *)(iVar13 + 0x40) + 0x34) <= *(float *)(iVar13 + 0x34)) {
        local_14 = fVar4 - pfVar1[1];
        iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
        local_18 = ((*(float *)(*(int *)(iVar13 + 0x40) + 0x34) - *(float *)(iVar13 + 0x34)) * 1.5 +
                   local_2c) - pfVar1[1];
      }
      else {
        local_18 = local_2c - pfVar1[1];
        iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
        local_14 = ((*(float *)(*(int *)(iVar13 + 0x40) + 0x34) - *(float *)(iVar13 + 0x34)) * 1.5 +
                   fVar4) - pfVar1[1];
      }
      iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
      if (*(float *)(*(int *)(iVar13 + 0x40) + 0x38) <= *(float *)(iVar13 + 0x38)) {
        local_1c = param_4 - pfVar1[2];
        iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
        local_20 = ((*(float *)(*(int *)(iVar13 + 0x40) + 0x38) - *(float *)(iVar13 + 0x38)) * 1.5 +
                   local_40) - pfVar1[2];
      }
      else {
        local_20 = local_40 - pfVar1[2];
        iVar13 = *(short *)(pfVar1 + 0xc) * 0x6c + piVar16[0x1a];
        local_1c = ((*(float *)(*(int *)(iVar13 + 0x40) + 0x38) - *(float *)(iVar13 + 0x38)) * 1.5 +
                   param_4) - pfVar1[2];
      }
      iVar13 = local_44;
      if ((*(byte *)(iVar14 + 0x4c) & 1) == 0) {
        if (((pfVar1[4] < local_24 == (pfVar1[4] == local_24)) ||
            (pfVar1[5] < local_14 == (pfVar1[5] == local_14))) ||
           ((pfVar1[6] < local_1c == (pfVar1[6] == local_1c) || (pfVar1[7] < local_28)))) {
          param_1 = param_1 + (short)*param_1 + 1;
        }
        else {
          if ((pfVar1[8] <= local_18) || (pfVar1[9] <= local_20)) goto LAB_0067e3f8;
          iVar14 = (int)(short)*param_1;
          param_1 = param_1 + 1;
          if (3 < iVar14) {
            iVar15 = (iVar14 - 4U >> 2) + 1;
            iVar14 = iVar14 + iVar15 * -4;
            do {
              pfVar1 = (float *)*param_1;
              if (((((*pfVar1 < local_24 != (*pfVar1 == local_24)) && (local_28 < pfVar1[1])) &&
                   (pfVar1[4] < local_1c != (pfVar1[4] == local_1c))) &&
                  (((local_20 < pfVar1[5] && (pfVar1[2] < local_14 != (pfVar1[2] == local_14))) &&
                   ((local_18 < pfVar1[3] && (piVar11 < local_48)))))) &&
                 ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                  ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))) {
                *piVar11 = (int)pfVar1;
                piVar11 = piVar11 + 1;
                local_44 = local_44 + 1;
              }
              pfVar1 = (float *)param_1[1];
              if ((((*pfVar1 < local_24 != (*pfVar1 == local_24)) && (local_28 < pfVar1[1])) &&
                  (pfVar1[4] < local_1c != (pfVar1[4] == local_1c))) &&
                 ((((local_20 < pfVar1[5] && (pfVar1[2] < local_14 != (pfVar1[2] == local_14))) &&
                   ((local_18 < pfVar1[3] && (piVar11 < local_48)))) &&
                  ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                   ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))))) {
                *piVar11 = (int)pfVar1;
                piVar11 = piVar11 + 1;
                local_44 = local_44 + 1;
              }
              pfVar1 = (float *)param_1[2];
              if ((((((*pfVar1 < local_24 != (*pfVar1 == local_24)) && (local_28 < pfVar1[1])) &&
                    (pfVar1[4] < local_1c != (pfVar1[4] == local_1c))) &&
                   ((local_20 < pfVar1[5] && (pfVar1[2] < local_14 != (pfVar1[2] == local_14))))) &&
                  ((local_18 < pfVar1[3] && (piVar11 < local_48)))) &&
                 ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                  ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))) {
                *piVar11 = (int)pfVar1;
                piVar11 = piVar11 + 1;
                local_44 = local_44 + 1;
              }
              pfVar1 = (float *)param_1[3];
              if (((((*pfVar1 < local_24 != (*pfVar1 == local_24)) && (local_28 < pfVar1[1])) &&
                   (pfVar1[4] < local_1c != (pfVar1[4] == local_1c))) &&
                  (((local_20 < pfVar1[5] && (pfVar1[2] < local_14 != (pfVar1[2] == local_14))) &&
                   ((local_18 < pfVar1[3] && (piVar11 < local_48)))))) &&
                 ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                  ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))) {
                *piVar11 = (int)pfVar1;
                piVar11 = piVar11 + 1;
                local_44 = local_44 + 1;
              }
              param_1 = param_1 + 4;
              iVar15 = iVar15 + -1;
              piVar16 = DAT_0292fc68;
              iVar13 = local_44;
            } while (iVar15 != 0);
          }
          for (; local_44 = iVar13, 0 < iVar14; iVar14 = iVar14 + -1) {
            pfVar1 = (float *)*param_1;
            if ((((*pfVar1 < local_24 != (*pfVar1 == local_24)) && (local_28 < pfVar1[1])) &&
                (pfVar1[4] < local_1c != (pfVar1[4] == local_1c))) &&
               ((((local_20 < pfVar1[5] && (pfVar1[2] < local_14 != (pfVar1[2] == local_14))) &&
                 ((local_18 < pfVar1[3] && (piVar11 < local_48)))) &&
                ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                 ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))))) {
              *piVar11 = (int)pfVar1;
              piVar11 = piVar11 + 1;
              iVar13 = iVar13 + 1;
            }
            param_1 = param_1 + 1;
            piVar16 = DAT_0292fc68;
          }
        }
      }
      else {
        fVar7 = *(float *)(DAT_0292186c + 100) * ((fVar4 + local_2c) * 0.5 - pfVar1[1]);
        fVar2 = (fVar3 + local_3c) * 0.5 - *pfVar1;
        fVar5 = (param_4 + local_40) * 0.5 - pfVar1[2];
        fVar8 = pfVar1[0xd] +
                (local_3c - fVar3) * (local_3c - fVar3) + (local_2c - fVar4) * (local_2c - fVar4) +
                (local_40 - param_4) * (local_40 - param_4) + 0.05;
        if (fVar8 * fVar8 <= fVar2 * fVar2 + fVar7 * fVar7 + fVar5 * fVar5) {
LAB_0067e3f8:
          param_1 = param_1 + (short)*param_1 + 1;
        }
        else {
          for (iVar14 = (int)(short)*param_1; param_1 = param_1 + 1, local_44 = iVar13, 0 < iVar14;
              iVar14 = iVar14 + -1) {
            if (piVar11 < local_48) {
              iVar15 = *param_1;
              if ((((((*(byte *)(iVar15 + 0x61) == 0) || ((param_5 & *(byte *)(iVar15 + 0x61)) != 0)
                     ) && ((local_28 < *(float *)(iVar15 + 0x18) ||
                           (((local_28 < *(float *)(iVar15 + 0x24) ||
                             (local_28 < *(float *)(iVar15 + 0x30))) ||
                            (local_28 < *(float *)(iVar15 + 0x3c))))))) &&
                   (((*(float *)(iVar15 + 0x18) < local_24 || (*(float *)(iVar15 + 0x24) < local_24)
                     ) || ((*(float *)(iVar15 + 0x30) < local_24 ||
                           (*(float *)(iVar15 + 0x3c) < local_24)))))) &&
                  (((local_20 < *(float *)(iVar15 + 0x20) || (local_20 < *(float *)(iVar15 + 0x2c)))
                   || ((local_20 < *(float *)(iVar15 + 0x38) ||
                       (local_20 < *(float *)(iVar15 + 0x44))))))) &&
                 ((((*(float *)(iVar15 + 0x20) < local_1c || (*(float *)(iVar15 + 0x2c) < local_1c))
                   || (*(float *)(iVar15 + 0x38) < local_1c)) ||
                  (*(float *)(iVar15 + 0x44) < local_1c)))) {
                *piVar11 = iVar15;
                piVar11 = piVar11 + 1;
                iVar13 = iVar13 + 1;
              }
            }
            piVar16 = DAT_0292fc68;
          }
        }
      }
    }
    else {
      fVar2 = fVar3 - *pfVar1;
      fVar5 = local_3c - *pfVar1;
      fVar7 = fVar4 - pfVar1[1];
      fVar8 = local_2c - pfVar1[1];
      fVar9 = param_4 - pfVar1[2];
      fVar10 = local_40 - pfVar1[2];
      if ((pfVar1[4] < fVar3 == (pfVar1[4] == fVar3)) ||
         ((((pfVar1[5] < fVar4 == (pfVar1[5] == fVar4) ||
            (pfVar1[6] < param_4 == (pfVar1[6] == param_4))) || (pfVar1[7] < local_3c)) ||
          ((pfVar1[8] <= local_2c || (pfVar1[9] <= local_40)))))) {
        param_1 = param_1 + (short)*param_1 + 2;
      }
      else {
        iVar14 = (int)(short)*param_1;
        param_1 = param_1 + 1;
        if (3 < iVar14) {
          iVar15 = (iVar14 - 4U >> 2) + 1;
          iVar14 = iVar14 + iVar15 * -4;
          do {
            pfVar1 = (float *)*param_1;
            if (((((*pfVar1 < fVar2 != (*pfVar1 == fVar2)) && (fVar5 < pfVar1[1])) &&
                 ((pfVar1[4] < fVar9 != (pfVar1[4] == fVar9) &&
                  (((fVar10 < pfVar1[5] && (pfVar1[2] < fVar7 != (pfVar1[2] == fVar7))) &&
                   (fVar8 < pfVar1[3])))))) && (piVar11 < local_48)) &&
               ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))) {
              *piVar11 = (int)pfVar1;
              piVar11 = piVar11 + 1;
              iVar13 = iVar13 + 1;
            }
            pfVar1 = (float *)param_1[1];
            if ((((*pfVar1 < fVar2 != (*pfVar1 == fVar2)) && (fVar5 < pfVar1[1])) &&
                ((pfVar1[4] < fVar9 != (pfVar1[4] == fVar9) &&
                 (((fVar10 < pfVar1[5] && (pfVar1[2] < fVar7 != (pfVar1[2] == fVar7))) &&
                  (fVar8 < pfVar1[3])))))) &&
               ((piVar11 < local_48 &&
                ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                 ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))))) {
              *piVar11 = (int)pfVar1;
              piVar11 = piVar11 + 1;
              iVar13 = iVar13 + 1;
            }
            pfVar1 = (float *)param_1[2];
            if (((*pfVar1 < fVar2 != (*pfVar1 == fVar2)) && (fVar5 < pfVar1[1])) &&
               ((pfVar1[4] < fVar9 != (pfVar1[4] == fVar9) &&
                (((((fVar10 < pfVar1[5] && (pfVar1[2] < fVar7 != (pfVar1[2] == fVar7))) &&
                   (fVar8 < pfVar1[3])) && (piVar11 < local_48)) &&
                 ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                  ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))))))) {
              *piVar11 = (int)pfVar1;
              piVar11 = piVar11 + 1;
              iVar13 = iVar13 + 1;
            }
            pfVar1 = (float *)param_1[3];
            if ((((*pfVar1 < fVar2 != (*pfVar1 == fVar2)) && (fVar5 < pfVar1[1])) &&
                (((pfVar1[4] < fVar9 != (pfVar1[4] == fVar9) &&
                  (((fVar10 < pfVar1[5] && (pfVar1[2] < fVar7 != (pfVar1[2] == fVar7))) &&
                   (fVar8 < pfVar1[3])))) && (piVar11 < local_48)))) &&
               ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
                ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))) {
              *piVar11 = (int)pfVar1;
              piVar11 = piVar11 + 1;
              iVar13 = iVar13 + 1;
            }
            param_1 = param_1 + 4;
            iVar15 = iVar15 + -1;
            piVar16 = DAT_0292fc68;
            local_44 = iVar13;
          } while (iVar15 != 0);
        }
        for (; 0 < iVar14; iVar14 = iVar14 + -1) {
          pfVar1 = (float *)*param_1;
          if (((((*pfVar1 < fVar2 != (*pfVar1 == fVar2)) && (fVar5 < pfVar1[1])) &&
               ((pfVar1[4] < fVar9 != (pfVar1[4] == fVar9) &&
                (((fVar10 < pfVar1[5] && (pfVar1[2] < fVar7 != (pfVar1[2] == fVar7))) &&
                 (fVar8 < pfVar1[3])))))) && (piVar11 < local_48)) &&
             ((*(byte *)((int)pfVar1 + 0x61) == 0 ||
              ((param_5 & *(byte *)((int)pfVar1 + 0x61)) != 0)))) {
            *piVar11 = (int)pfVar1;
            piVar11 = piVar11 + 1;
            iVar13 = iVar13 + 1;
          }
          param_1 = param_1 + 1;
          piVar16 = DAT_0292fc68;
          local_44 = iVar13;
        }
      }
    }
    piVar12 = piVar11;
    if (iVar13 != 0) {
      *(short *)local_10 = (short)iVar13;
      piVar12 = piVar11 + 1;
      iVar13 = 0;
      *(short *)((int)local_10 + 2) = sVar6;
      local_44 = 0;
      piVar16 = DAT_0292fc68;
      local_10 = piVar11;
    }
    sVar6 = (short)*param_1;
    piVar11 = piVar12;
  } while( true );
}

