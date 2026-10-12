/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594c30; label: FUN_00594c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00594c30(int *param_1,float param_2,float param_3,float param_4,int param_5,float param_6,
                 int param_7)

{
  short sVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  float local_54;
  float fStack_50;
  float fStack_48;
  undefined4 uStack_44;
  float local_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_24;
  int iStack_18;
  int iStack_14;
  int local_10 [4];
  
  local_54 = param_4 * _DAT_00804fa4;
  fVar4 = _DAT_00804fa8 * param_4;
  local_40 = param_4 * _DAT_00804fb0;
  if ((*param_1 != 0) && (_DAT_00950780 <= 0.0)) {
    uVar8 = (uint)*(ushort *)((int)param_1 + 6);
    uVar12 = (uint)*(ushort *)(param_1 + 1);
    if ((uVar12 != 0) && (uVar8 != 0)) {
      iVar9 = (int)((ulonglong)uVar8 / (ulonglong)(longlong)(int)uVar12);
      if ((DAT_0093b0d8 != 0) && (*(char *)(DAT_0093b0d8 + 0xb) != '\0')) {
        local_54 = local_54 * 0.75;
        local_40 = local_40 * 0.875;
      }
      iVar13 = 0;
      local_10[1] = 0xffffffff;
      local_10[0] = -1;
      local_10[3] = 0xffffffff;
      local_10[2] = 0xffffffff;
      if ((param_5 != 0) && (DAT_00955888 != (code *)0x0)) {
        param_4._0_2_ = -1;
        param_4._2_2_ = -1;
        (*DAT_00955888)(&param_4);
        if (((param_4._0_2_ != -1) || (param_4._2_2_ != -1)) && (iVar11 = 0, iVar9 != -1)) {
          iVar14 = 0;
          do {
            iVar10 = 0;
            if (uVar12 != 0) {
              do {
                if (((iVar13 != 2) && (iVar14 + iVar10 < (int)uVar8)) &&
                   ((sVar1 = *(short *)(*param_1 + (iVar14 + iVar10) * 0x1c), sVar1 == param_4._0_2_
                    || (sVar1 == param_4._2_2_)))) {
                  local_10[iVar13] = iVar10;
                  local_10[iVar13 + 2] = iVar11;
                  iVar13 = iVar13 + 1;
                }
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)uVar12);
            }
            iVar11 = iVar11 + 1;
            iVar14 = iVar14 + uVar12;
          } while (iVar11 < iVar9 + 1);
        }
      }
      if (1.0 < param_6) {
        param_6 = 1.0;
      }
      iVar13 = 0;
      fStack_48 = param_3 - (float)iVar9 * fVar4 * 0.5;
      if (iVar9 != -1) {
        iVar11 = uVar12 * 0x1c;
        iStack_34 = 0;
        iStack_24 = 0;
        iStack_14 = iVar11;
        do {
          iVar14 = 0;
          if (uVar12 != 0) {
            iStack_38 = iStack_34;
            iVar10 = iStack_24;
            fStack_50 = param_2 - (float)(int)(uVar12 - 1) * local_54 * 0.5;
            do {
              if (iStack_38 < (int)uVar8) {
                iStack_3c = (int)*(short *)(*param_1 + iVar10);
                *(float *)(*param_1 + 0x14 + iVar10) = fStack_50;
                *(float *)(iVar10 + 0x18 + *param_1) = fStack_48;
                if (0.0 < param_6) {
                  uStack_44 = DAT_00803b88;
                  param_4 = 1.0;
                  if ((param_5 != 0) &&
                     (iVar11 = FUN_00630680(param_5,iStack_3c,&iStack_18), iVar11 != 0)) {
                    if (param_7 != 0) goto LAB_00595086;
                    if (iStack_18 == 0) {
                      uStack_44 = DAT_00803b90;
                    }
                    else {
                      if (iStack_18 != 1) {
                        param_4 = 0.25;
                        goto LAB_00594ede;
                      }
                      uStack_44 = DAT_00803b8c;
                    }
                    iVar11 = FUN_006e6b90();
                    param_4 = (float)(&DAT_029899a0)[iVar11 >> 1 & 0x7fff] * 0.125 + 0.375;
                  }
LAB_00594ede:
                  iVar11 = FUN_00594960(iStack_3c);
                  if (iVar11 == 0) {
                    iStack_3c = -1;
                    param_4 = param_4 * 0.25;
                  }
                  fVar3 = param_4 * param_6;
                  if (0.0 < fVar3) {
                    bVar7 = false;
                    bVar6 = false;
                    bVar5 = false;
                    param_4 = 0.0;
                    do {
                      iVar11 = *(int *)((int)local_10 + (int)param_4);
                      if ((iVar11 != -1) &&
                         (iVar2 = *(int *)((int)local_10 + (int)param_4 + 8), iVar2 != -1)) {
                        if ((iVar14 == iVar11) && ((iVar13 == iVar2 + -1 || (iVar13 == iVar2 + 1))))
                        {
                          bVar5 = true;
                        }
                        else if ((iVar13 == iVar2) &&
                                ((iVar14 == iVar11 + -1 || (iVar14 == iVar11 + 1)))) {
                          bVar5 = true;
                        }
                        else if (((iVar14 == iVar11 + -1) &&
                                 ((iVar13 == iVar2 + -1 ||
                                  ((iVar14 == iVar11 + -1 && (iVar13 == iVar2 + 1)))))) ||
                                ((iVar14 == iVar11 + 1 &&
                                 ((iVar13 == iVar2 + -1 ||
                                  ((iVar14 == iVar11 + 1 && (iVar13 == iVar2 + 1)))))))) {
                          bVar6 = true;
                        }
                        else if (((iVar14 == iVar11) &&
                                 ((iVar13 == iVar2 + -2 || (iVar13 == iVar2 + 2)))) ||
                                ((iVar13 == iVar2 &&
                                 ((iVar14 == iVar11 + -2 || (iVar14 == iVar11 + 2)))))) {
                          bVar7 = true;
                        }
                      }
                      param_4 = (float)((int)param_4 + 4);
                    } while ((int)param_4 < 8);
                    if (bVar5) {
                      fVar3 = fVar3 * 0.333;
                      param_4 = fVar3;
                    }
                    else if (bVar6) {
                      fVar3 = fVar3 * 0.5;
                      param_4 = fVar3;
                    }
                    else if (bVar7) {
                      fVar3 = fVar3 * 0.666;
                      param_4 = fVar3;
                    }
                    FUN_0055b830(iStack_3c,fStack_50,fStack_48,0x3b03126f,local_40,uStack_44,fVar3,
                                 fVar3,1,0);
                  }
                }
              }
LAB_00595086:
              iStack_38 = iStack_38 + 1;
              fStack_50 = fStack_50 + local_54;
              iVar14 = iVar14 + 1;
              iVar10 = iVar10 + 0x1c;
              iVar11 = iStack_14;
            } while (iVar14 < (int)uVar12);
          }
          fStack_48 = fStack_48 + fVar4;
          iStack_34 = iStack_34 + uVar12;
          iVar13 = iVar13 + 1;
          iStack_24 = iStack_24 + iVar11;
        } while (iVar13 < iVar9 + 1);
      }
    }
  }
  return;
}

