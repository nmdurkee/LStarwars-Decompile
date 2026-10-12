/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6ad8d0; label: FUN_006ad8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ad8d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  undefined4 *puVar15;
  float *pfVar16;
  float *pfVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  float *pfVar22;
  float *pfVar23;
  float *pfVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  float *pfVar28;
  float *unaff_EBX;
  float *unaff_ESI;
  float10 fVar29;
  float10 fVar30;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  float *local_70;
  float *local_6c;
  float *local_68;
  float *local_64;
  int local_5c;
  float *local_58;
  float *local_54;
  float *local_50;
  float *local_4c;
  float *local_48;
  float *local_44;
  float *local_40;
  undefined4 *puVar31;
  float local_34;
  float local_30;
  float *local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  iVar7 = param_1 * param_2;
  iVar8 = param_1 * param_3;
  fVar29 = (float10)FUN_006ebcb0();
  fVar30 = (float10)FUN_006e8e80();
  iVar9 = param_1 + -1 >> 1;
  iVar10 = param_2 + 1 >> 1;
  if (param_1 < param_3) {
    local_80 = 0;
    if (0 < param_1) {
      do {
        local_70 = (float *)0x0;
        iVar11 = local_80;
        local_58 = (float *)local_80;
        if (3 < param_3) {
          iVar25 = (param_3 - 4U >> 2) + 1;
          local_70 = (float *)(iVar25 * 4);
          do {
            unaff_ESI[iVar11] = in_EAX[(int)local_58];
            unaff_ESI[iVar11 + param_1] = in_EAX[(int)local_58 + iVar7];
            iVar18 = (int)local_58 + iVar7 + iVar7;
            iVar11 = iVar11 + param_1 + param_1;
            unaff_ESI[iVar11] = in_EAX[iVar18];
            iVar18 = iVar18 + iVar7;
            iVar11 = iVar11 + param_1;
            unaff_ESI[iVar11] = in_EAX[iVar18];
            iVar11 = iVar11 + param_1;
            local_58 = (float *)(iVar18 + iVar7);
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
        }
        if ((int)local_70 < param_3) {
          iVar25 = param_3 - (int)local_70;
          pfVar16 = unaff_ESI + iVar11;
          local_58 = in_EAX + (int)local_58;
          do {
            *pfVar16 = *local_58;
            pfVar16 = pfVar16 + param_1;
            local_58 = local_58 + iVar7;
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
        }
        local_80 = local_80 + 1;
      } while (local_80 < param_1);
    }
  }
  else {
    local_80 = 0;
    local_7c = 0;
    if (0 < param_3) {
      local_40 = in_EAX + 2;
      pfVar16 = unaff_ESI + 2;
      local_44 = (float *)param_3;
      do {
        iVar11 = 0;
        iVar25 = local_7c;
        iVar18 = local_80;
        if (3 < param_1) {
          iVar19 = (param_1 - 4U >> 2) + 1;
          iVar11 = iVar19 * 4;
          iVar18 = local_80 + iVar11;
          iVar25 = local_7c + iVar11;
          pfVar14 = pfVar16;
          pfVar22 = local_40;
          do {
            pfVar14[-2] = pfVar22[-2];
            iVar19 = iVar19 + -1;
            pfVar14[-1] = pfVar22[-1];
            *pfVar14 = *pfVar22;
            pfVar14[1] = pfVar22[1];
            pfVar14 = pfVar14 + 4;
            pfVar22 = pfVar22 + 4;
          } while (iVar19 != 0);
        }
        if (iVar11 < param_1) {
          pfVar14 = in_EAX + iVar25;
          iVar11 = param_1 - iVar11;
          pfVar22 = unaff_ESI + iVar18;
          do {
            *pfVar22 = *pfVar14;
            pfVar14 = pfVar14 + 1;
            iVar11 = iVar11 + -1;
            pfVar22 = pfVar22 + 1;
          } while (iVar11 != 0);
        }
        local_80 = local_80 + param_1;
        pfVar16 = pfVar16 + param_1;
        local_7c = local_7c + iVar7;
        local_40 = local_40 + iVar7;
        local_44 = (float *)((int)local_44 + -1);
      } while (local_44 != (float *)0x0);
    }
  }
  iVar11 = iVar8 * param_2;
  local_80 = 0;
  if (1 < iVar10) {
    local_44 = (float *)(iVar10 + -1);
    iVar25 = param_1 * 2;
    local_7c = iVar11;
    do {
      local_80 = local_80 + iVar8;
      local_7c = local_7c - iVar8;
      local_70 = (float *)0x0;
      iVar18 = iVar25;
      iVar19 = local_80;
      local_6c = (float *)local_7c;
      if (3 < param_3) {
        iVar26 = (param_3 - 4U >> 2) + 1;
        local_70 = (float *)(iVar26 * 4);
        do {
          unaff_ESI[iVar19] = in_EAX[iVar18 + -1] + in_EAX[iVar18 + -1];
          iVar12 = iVar18 + iVar7;
          unaff_ESI[(int)local_6c] = in_EAX[iVar18] + in_EAX[iVar18];
          unaff_ESI[iVar19 + param_1] = in_EAX[iVar12 + -1] + in_EAX[iVar12 + -1];
          iVar19 = iVar19 + param_1 + param_1;
          iVar18 = iVar12 + iVar7;
          unaff_ESI[(int)local_6c + param_1] = in_EAX[iVar12] + in_EAX[iVar12];
          iVar27 = (int)local_6c + param_1 + param_1;
          unaff_ESI[iVar19] = in_EAX[iVar18 + -1] + in_EAX[iVar18 + -1];
          iVar19 = iVar19 + param_1;
          iVar12 = iVar18 + iVar7;
          unaff_ESI[iVar27] = in_EAX[iVar18] + in_EAX[iVar18];
          iVar27 = iVar27 + param_1;
          unaff_ESI[iVar19] = in_EAX[iVar12 + -1] + in_EAX[iVar12 + -1];
          iVar19 = iVar19 + param_1;
          iVar18 = iVar12 + iVar7;
          unaff_ESI[iVar27] = in_EAX[iVar12] + in_EAX[iVar12];
          local_6c = (float *)(iVar27 + param_1);
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
      }
      if ((int)local_70 < param_3) {
        local_6c = unaff_ESI + (int)local_6c;
        pfVar16 = unaff_ESI + iVar19;
        iVar19 = param_3 - (int)local_70;
        pfVar14 = in_EAX + iVar18;
        do {
          *pfVar16 = pfVar14[-1] + pfVar14[-1];
          *local_6c = *pfVar14 + *pfVar14;
          local_6c = local_6c + param_1;
          pfVar16 = pfVar16 + param_1;
          pfVar14 = pfVar14 + iVar7;
          iVar19 = iVar19 + -1;
        } while (iVar19 != 0);
      }
      iVar25 = iVar25 + param_1 * 2;
      local_44 = (float *)((int)local_44 + -1);
    } while (local_44 != (float *)0x0);
  }
  if (param_1 != 1) {
    if (iVar9 < param_3) {
      iVar25 = 0;
      local_80 = 0;
      if (1 < iVar10) {
        local_6c = (float *)(iVar10 + -1);
        local_7c = iVar11;
        do {
          local_80 = local_80 + iVar8;
          local_7c = local_7c - iVar8;
          iVar25 = iVar25 + param_1 * 2;
          if (2 < param_1) {
            local_58 = (float *)((param_1 - 3U >> 1) + 1);
            iVar19 = iVar25;
            iVar18 = iVar25;
            do {
              iVar18 = iVar18 + -2;
              iVar19 = iVar19 + 2;
              local_74 = (local_80 - iVar25) + iVar19;
              local_78 = (local_7c - iVar25) + iVar19;
              local_70 = (float *)0x0;
              iVar26 = iVar19;
              local_4c = (float *)iVar18;
              if (3 < param_3) {
                local_40 = (float *)((param_3 - 4U >> 2) + 1);
                local_70 = (float *)((int)local_40 * 4);
                do {
                  unaff_ESI[local_74 + -1] = in_EAX[(int)local_4c + -1] + in_EAX[iVar26 + -1];
                  unaff_ESI[local_78 + -1] = in_EAX[iVar26 + -1] - in_EAX[(int)local_4c + -1];
                  iVar12 = local_74 + param_1;
                  unaff_ESI[local_74] = in_EAX[iVar26] - in_EAX[(int)local_4c];
                  iVar27 = local_78 + param_1;
                  unaff_ESI[local_78] = in_EAX[iVar26] + in_EAX[(int)local_4c];
                  iVar20 = (int)local_4c + iVar7;
                  iVar26 = iVar26 + iVar7;
                  unaff_ESI[iVar12 + -1] = in_EAX[iVar20 + -1] + in_EAX[iVar26 + -1];
                  unaff_ESI[iVar27 + -1] = in_EAX[iVar26 + -1] - in_EAX[iVar20 + -1];
                  iVar1 = iVar12 + param_1;
                  unaff_ESI[iVar12] = in_EAX[iVar26] - in_EAX[iVar20];
                  iVar12 = iVar27 + param_1;
                  unaff_ESI[iVar27] = in_EAX[iVar26] + in_EAX[iVar20];
                  iVar20 = iVar20 + iVar7;
                  iVar26 = iVar26 + iVar7;
                  unaff_ESI[iVar1 + -1] = in_EAX[iVar20 + -1] + in_EAX[iVar26 + -1];
                  unaff_ESI[iVar12 + -1] = in_EAX[iVar26 + -1] - in_EAX[iVar20 + -1];
                  iVar27 = iVar1 + param_1;
                  unaff_ESI[iVar1] = in_EAX[iVar26] - in_EAX[iVar20];
                  iVar1 = iVar12 + param_1;
                  unaff_ESI[iVar12] = in_EAX[iVar26] + in_EAX[iVar20];
                  iVar20 = iVar20 + iVar7;
                  iVar26 = iVar26 + iVar7;
                  unaff_ESI[iVar27 + -1] = in_EAX[iVar20 + -1] + in_EAX[iVar26 + -1];
                  unaff_ESI[iVar1 + -1] = in_EAX[iVar26 + -1] - in_EAX[iVar20 + -1];
                  local_74 = iVar27 + param_1;
                  unaff_ESI[iVar27] = in_EAX[iVar26] - in_EAX[iVar20];
                  local_78 = iVar1 + param_1;
                  unaff_ESI[iVar1] = in_EAX[iVar26] + in_EAX[iVar20];
                  iVar26 = iVar26 + iVar7;
                  local_4c = (float *)(iVar20 + iVar7);
                  local_40 = (float *)((int)local_40 + -1);
                } while (local_40 != (float *)0x0);
              }
              if ((int)local_70 < param_3) {
                local_50 = unaff_ESI + local_78;
                local_40 = unaff_ESI + local_74;
                local_54 = (float *)(param_3 - (int)local_70);
                local_4c = in_EAX + (int)local_4c;
                pfVar16 = in_EAX + iVar26;
                do {
                  local_40[-1] = pfVar16[-1] + local_4c[-1];
                  local_50[-1] = pfVar16[-1] - local_4c[-1];
                  *local_40 = *pfVar16 - *local_4c;
                  *local_50 = *pfVar16 + *local_4c;
                  local_50 = local_50 + param_1;
                  local_40 = local_40 + param_1;
                  local_4c = local_4c + iVar7;
                  pfVar16 = pfVar16 + iVar7;
                  local_54 = (float *)((int)local_54 + -1);
                } while (local_54 != (float *)0x0);
              }
              local_58 = (float *)((int)local_58 + -1);
            } while (local_58 != (float *)0x0);
          }
          local_6c = (float *)((int)local_6c + -1);
        } while (local_6c != (float *)0x0);
      }
    }
    else if (1 < iVar10) {
      local_58 = (float *)(iVar10 + -1);
      pfVar16 = unaff_ESI + iVar11;
      pfVar14 = unaff_ESI;
      do {
        pfVar14 = pfVar14 + iVar8;
        pfVar16 = pfVar16 + -iVar8;
        in_EAX = in_EAX + param_1 * 2;
        if (0 < param_3) {
          local_54 = (float *)param_3;
          pfVar13 = in_EAX;
          local_40 = pfVar14;
          pfVar22 = pfVar16;
          do {
            if (2 < param_1) {
              local_4c = local_40;
              iVar25 = (param_1 - 3U >> 1) + 1;
              pfVar17 = pfVar13;
              pfVar23 = pfVar13;
              local_50 = pfVar22;
              do {
                pfVar21 = pfVar23 + -2;
                local_4c[1] = pfVar23[-3] + pfVar17[1];
                pfVar28 = pfVar17 + 1;
                pfVar17 = pfVar17 + 2;
                iVar25 = iVar25 + -1;
                local_50[1] = *pfVar28 - pfVar23[-3];
                local_4c[2] = *pfVar17 - *pfVar21;
                local_50[2] = *pfVar21 + *pfVar17;
                pfVar23 = pfVar21;
                local_50 = local_50 + 2;
                local_4c = local_4c + 2;
              } while (iVar25 != 0);
            }
            pfVar22 = pfVar22 + param_1;
            local_40 = local_40 + param_1;
            pfVar13 = pfVar13 + iVar7;
            local_54 = (float *)((int)local_54 + -1);
          } while (local_54 != (float *)0x0);
        }
        local_58 = (float *)((int)local_58 + -1);
      } while (local_58 != (float *)0x0);
    }
  }
  local_34 = 1.0;
  local_7c = param_2 * param_4;
  iVar7 = (param_2 + -1) * param_4;
  local_80 = 0;
  if (1 < iVar10) {
    iVar25 = local_7c - param_4;
    fVar2 = 0.0;
    local_40 = (float *)(param_5 + 8);
    local_44 = (float *)(param_5 + 8 + local_7c * 4);
    local_20 = iVar10 + -1;
    do {
      local_80 = local_80 + param_4;
      local_7c = local_7c - param_4;
      local_40 = local_40 + param_4;
      local_44 = local_44 + -param_4;
      fVar5 = (float)fVar29 * local_34 - (float)fVar30 * fVar2;
      local_5c = param_4;
      local_64 = (float *)0x0;
      fVar2 = fVar2 * (float)fVar29 + (float)fVar30 * local_34;
      iVar18 = local_7c;
      local_6c = (float *)local_80;
      local_30 = (float)iVar7;
      if (3 < param_4) {
        local_70 = (float *)(param_6 + 8 + param_4 * 4);
        iVar19 = (param_4 - 4U >> 2) + 1;
        local_64 = (float *)(iVar19 * 4);
        local_6c = (float *)(local_80 + (int)local_64);
        local_5c = (int)local_64 + param_4;
        iVar18 = local_7c + (int)local_64;
        local_30 = (float)(iVar7 + (int)local_64);
        pfVar16 = local_40;
        local_54 = (float *)(param_6 + 8);
        local_50 = (float *)(param_6 + 8 + iVar7 * 4);
        local_4c = local_44;
        do {
          pfVar16[-2] = local_70[-2] * fVar5 + local_54[-2];
          local_4c[-2] = local_50[-2] * fVar2;
          pfVar16[-1] = local_70[-1] * fVar5 + local_54[-1];
          local_4c[-1] = local_50[-1] * fVar2;
          *pfVar16 = *local_70 * fVar5 + *local_54;
          *local_4c = *local_50 * fVar2;
          pfVar14 = local_70 + 1;
          local_70 = local_70 + 4;
          pfVar16[1] = *pfVar14 * fVar5 + local_54[1];
          iVar19 = iVar19 + -1;
          local_4c[1] = local_50[1] * fVar2;
          pfVar16 = pfVar16 + 4;
          local_54 = local_54 + 4;
          local_50 = local_50 + 4;
          local_4c = local_4c + 4;
        } while (iVar19 != 0);
      }
      if ((int)local_64 < param_4) {
        local_70 = (float *)(param_6 + (int)local_30 * 4);
        iVar19 = (int)local_6c * 4;
        local_54 = (float *)(param_6 + local_5c * 4);
        iVar26 = param_4 - (int)local_64;
        local_6c = (float *)(param_6 + (int)local_64 * 4);
        local_50 = (float *)(param_5 + iVar18 * 4);
        local_4c = (float *)(param_5 + iVar19);
        do {
          fVar3 = *local_54;
          local_54 = local_54 + 1;
          *local_4c = fVar3 * fVar5 + *local_6c;
          fVar3 = *local_70;
          local_70 = local_70 + 1;
          iVar26 = iVar26 + -1;
          *local_50 = fVar3 * fVar2;
          local_6c = local_6c + 1;
          local_50 = local_50 + 1;
          local_4c = local_4c + 1;
        } while (iVar26 != 0);
      }
      local_78 = param_4;
      if (2 < iVar10) {
        local_70 = (float *)(param_6 + 8 + param_4 * 4);
        local_54 = (float *)(param_6 + 8 + iVar25 * 4);
        local_24 = iVar10 + -2;
        fVar3 = fVar2;
        local_5c = iVar25;
        local_30 = fVar5;
        do {
          local_78 = local_78 + param_4;
          local_5c = local_5c - param_4;
          local_70 = local_70 + param_4;
          local_54 = local_54 + -param_4;
          fVar6 = local_30 * fVar5 - fVar3 * fVar2;
          local_64 = (float *)0x0;
          fVar3 = fVar3 * fVar5 + local_30 * fVar2;
          iVar18 = local_7c;
          local_6c = (float *)local_80;
          local_4c = (float *)local_5c;
          local_28 = local_78;
          if (3 < param_4) {
            local_2c = (float *)((param_4 - 4U >> 2) + 1);
            local_64 = (float *)((int)local_2c * 4);
            local_6c = (float *)(local_80 + (int)local_64);
            iVar18 = local_7c + (int)local_64;
            local_28 = local_78 + (int)local_64;
            local_4c = (float *)(local_5c + (int)local_64);
            pfVar16 = local_40;
            pfVar14 = local_44;
            pfVar22 = local_54;
            pfVar13 = local_70;
            do {
              local_2c = (float *)((int)local_2c + -1);
              pfVar16[-2] = pfVar13[-2] * fVar6 + pfVar16[-2];
              pfVar14[-2] = pfVar22[-2] * fVar3 + pfVar14[-2];
              pfVar16[-1] = pfVar13[-1] * fVar6 + pfVar16[-1];
              pfVar14[-1] = pfVar22[-1] * fVar3 + pfVar14[-1];
              *pfVar16 = *pfVar13 * fVar6 + *pfVar16;
              *pfVar14 = *pfVar22 * fVar3 + *pfVar14;
              pfVar16[1] = pfVar13[1] * fVar6 + pfVar16[1];
              pfVar14[1] = pfVar22[1] * fVar3 + pfVar14[1];
              pfVar16 = pfVar16 + 4;
              pfVar14 = pfVar14 + 4;
              pfVar22 = pfVar22 + 4;
              pfVar13 = pfVar13 + 4;
            } while (local_2c != (float *)0x0);
          }
          if ((int)local_64 < param_4) {
            iVar19 = (int)local_4c * 4;
            local_4c = (float *)(param_6 + local_28 * 4);
            iVar26 = param_4 - (int)local_64;
            pfVar16 = (float *)(param_5 + (int)local_6c * 4);
            local_50 = (float *)(param_6 + iVar19);
            local_2c = (float *)(param_5 + iVar18 * 4);
            do {
              fVar4 = *local_4c;
              local_4c = local_4c + 1;
              *pfVar16 = fVar4 * fVar6 + *pfVar16;
              iVar26 = iVar26 + -1;
              *local_2c = *local_50 * fVar3 + *local_2c;
              pfVar16 = pfVar16 + 1;
              local_50 = local_50 + 1;
              local_2c = local_2c + 1;
            } while (iVar26 != 0);
          }
          local_24 = local_24 + -1;
          local_30 = fVar6;
        } while (local_24 != 0);
      }
      local_20 = local_20 + -1;
      local_34 = fVar5;
    } while (local_20 != 0);
  }
  local_80 = 0;
  if (1 < iVar10) {
    pfVar16 = (float *)(param_6 + 8);
    local_24 = iVar10 + -1;
    do {
      local_80 = local_80 + param_4;
      pfVar16 = pfVar16 + param_4;
      iVar7 = 0;
      local_7c = local_80;
      if (3 < param_4) {
        local_20 = (param_4 - 4U >> 2) + 1;
        iVar7 = local_20 * 4;
        local_7c = local_80 + iVar7;
        pfVar14 = (float *)(param_6 + 8);
        pfVar22 = pfVar16;
        do {
          local_20 = local_20 + -1;
          pfVar14[-2] = pfVar22[-2] + pfVar14[-2];
          pfVar14[-1] = pfVar22[-1] + pfVar14[-1];
          *pfVar14 = *pfVar22 + *pfVar14;
          pfVar14[1] = pfVar22[1] + pfVar14[1];
          pfVar14 = pfVar14 + 4;
          pfVar22 = pfVar22 + 4;
        } while (local_20 != 0);
      }
      if (iVar7 < param_4) {
        pfVar14 = (float *)(param_6 + local_7c * 4);
        do {
          fVar2 = *pfVar14;
          iVar7 = iVar7 + 1;
          pfVar14 = pfVar14 + 1;
          *(float *)(param_6 + -4 + iVar7 * 4) = fVar2 + *(float *)(param_6 + -4 + iVar7 * 4);
        } while (iVar7 < param_4);
      }
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  iVar7 = 0;
  if (1 < iVar10) {
    local_24 = iVar10 + -1;
    iVar25 = iVar11;
    do {
      iVar7 = iVar7 + iVar8;
      iVar25 = iVar25 - iVar8;
      local_70 = (float *)0x0;
      iVar18 = iVar7;
      iVar19 = iVar25;
      if (3 < param_3) {
        iVar26 = (param_3 - 4U >> 2) + 1;
        local_70 = (float *)(iVar26 * 4);
        do {
          unaff_ESI[iVar18] = unaff_EBX[iVar18] - unaff_EBX[iVar19];
          iVar12 = iVar18 + param_1;
          unaff_ESI[iVar19] = unaff_EBX[iVar19] + unaff_EBX[iVar18];
          iVar19 = iVar19 + param_1;
          unaff_ESI[iVar12] = unaff_EBX[iVar12] - unaff_EBX[iVar19];
          iVar18 = iVar12 + param_1;
          unaff_ESI[iVar19] = unaff_EBX[iVar19] + unaff_EBX[iVar12];
          iVar19 = iVar19 + param_1;
          unaff_ESI[iVar18] = unaff_EBX[iVar18] - unaff_EBX[iVar19];
          iVar12 = iVar18 + param_1;
          unaff_ESI[iVar19] = unaff_EBX[iVar19] + unaff_EBX[iVar18];
          iVar19 = iVar19 + param_1;
          unaff_ESI[iVar12] = unaff_EBX[iVar12] - unaff_EBX[iVar19];
          iVar18 = iVar12 + param_1;
          unaff_ESI[iVar19] = unaff_EBX[iVar19] + unaff_EBX[iVar12];
          iVar19 = iVar19 + param_1;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
      }
      if ((int)local_70 < param_3) {
        local_20 = param_3 - (int)local_70;
        pfVar16 = unaff_EBX + iVar18;
        pfVar14 = unaff_EBX + iVar19;
        do {
          *(float *)(((int)unaff_ESI - (int)unaff_EBX) + (int)pfVar16) = *pfVar16 - *pfVar14;
          *(float *)(((int)unaff_ESI - (int)unaff_EBX) + (int)pfVar14) = *pfVar16 + *pfVar14;
          pfVar16 = pfVar16 + param_1;
          pfVar14 = pfVar14 + param_1;
          local_20 = local_20 + -1;
        } while (local_20 != 0);
      }
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  if (param_1 != 1) {
    if (iVar9 < param_3) {
      iVar7 = 0;
      if (1 < iVar10) {
        local_28 = iVar10 + -1;
        local_7c = iVar11;
        do {
          iVar7 = iVar7 + iVar8;
          local_7c = local_7c - iVar8;
          if (2 < param_1) {
            local_24 = (param_1 - 3U >> 1) + 1;
            iVar10 = iVar7;
            do {
              iVar10 = iVar10 + 2;
              iVar25 = (local_7c - iVar7) + iVar10;
              local_70 = (float *)0x0;
              iVar11 = iVar10;
              if (3 < param_3) {
                iVar18 = (param_3 - 4U >> 2) + 1;
                local_70 = (float *)(iVar18 * 4);
                do {
                  unaff_ESI[iVar11 + -1] = unaff_EBX[iVar11 + -1] - unaff_EBX[iVar25];
                  unaff_ESI[iVar25 + -1] = unaff_EBX[iVar25] + unaff_EBX[iVar11 + -1];
                  unaff_ESI[iVar11] = unaff_EBX[iVar25 + -1] + unaff_EBX[iVar11];
                  iVar19 = iVar11 + param_1;
                  unaff_ESI[iVar25] = unaff_EBX[iVar11] - unaff_EBX[iVar25 + -1];
                  iVar25 = iVar25 + param_1;
                  unaff_ESI[iVar19 + -1] = unaff_EBX[iVar19 + -1] - unaff_EBX[iVar25];
                  unaff_ESI[iVar25 + -1] = unaff_EBX[iVar25] + unaff_EBX[iVar19 + -1];
                  unaff_ESI[iVar19] = unaff_EBX[iVar25 + -1] + unaff_EBX[iVar19];
                  iVar11 = iVar19 + param_1;
                  unaff_ESI[iVar25] = unaff_EBX[iVar19] - unaff_EBX[iVar25 + -1];
                  iVar25 = iVar25 + param_1;
                  unaff_ESI[iVar11 + -1] = unaff_EBX[iVar11 + -1] - unaff_EBX[iVar25];
                  unaff_ESI[iVar25 + -1] = unaff_EBX[iVar25] + unaff_EBX[iVar11 + -1];
                  unaff_ESI[iVar11] = unaff_EBX[iVar25 + -1] + unaff_EBX[iVar11];
                  iVar19 = iVar11 + param_1;
                  unaff_ESI[iVar25] = unaff_EBX[iVar11] - unaff_EBX[iVar25 + -1];
                  iVar25 = iVar25 + param_1;
                  unaff_ESI[iVar19 + -1] = unaff_EBX[iVar19 + -1] - unaff_EBX[iVar25];
                  unaff_ESI[iVar25 + -1] = unaff_EBX[iVar25] + unaff_EBX[iVar19 + -1];
                  unaff_ESI[iVar19] = unaff_EBX[iVar25 + -1] + unaff_EBX[iVar19];
                  iVar11 = iVar19 + param_1;
                  unaff_ESI[iVar25] = unaff_EBX[iVar19] - unaff_EBX[iVar25 + -1];
                  iVar25 = iVar25 + param_1;
                  iVar18 = iVar18 + -1;
                } while (iVar18 != 0);
              }
              if ((int)local_70 < param_3) {
                local_20 = param_3 - (int)local_70;
                pfVar16 = unaff_EBX + iVar25 + -1;
                pfVar14 = unaff_EBX + iVar11 + -1;
                local_40 = unaff_ESI + iVar25;
                pfVar22 = unaff_ESI + iVar11;
                do {
                  *(float *)(((int)unaff_ESI - (int)unaff_EBX) + (int)pfVar14) =
                       *pfVar14 - pfVar16[1];
                  *(float *)(((int)unaff_ESI - (int)unaff_EBX) + (int)pfVar16) =
                       *pfVar14 + pfVar16[1];
                  *pfVar22 = *pfVar16 + pfVar14[1];
                  pfVar13 = pfVar14 + 1;
                  fVar2 = *pfVar16;
                  pfVar14 = pfVar14 + param_1;
                  pfVar16 = pfVar16 + param_1;
                  local_20 = local_20 + -1;
                  *local_40 = *pfVar13 - fVar2;
                  local_40 = local_40 + param_1;
                  pfVar22 = pfVar22 + param_1;
                } while (local_20 != 0);
              }
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
          local_28 = local_28 + -1;
        } while (local_28 != 0);
      }
    }
    else if (1 < iVar10) {
      local_44 = unaff_ESI + iVar11;
      local_48 = unaff_EBX + iVar11 + -1;
      local_40 = unaff_EBX + -1;
      local_28 = iVar10 + -1;
      pfVar16 = unaff_ESI;
      do {
        pfVar16 = pfVar16 + iVar8;
        local_40 = local_40 + iVar8;
        local_44 = local_44 + -iVar8;
        local_48 = local_48 + -iVar8;
        if (0 < param_3) {
          local_24 = param_3;
          local_68 = local_48;
          local_64 = local_44;
          local_58 = local_40;
          local_54 = pfVar16;
          do {
            if (2 < param_1) {
              local_20 = (param_1 - 3U >> 1) + 1;
              local_4c = local_54;
              local_50 = local_64;
              pfVar14 = local_58;
              pfVar22 = local_68;
              do {
                local_4c = local_4c + 2;
                local_50 = local_50 + 2;
                pfVar13 = pfVar14 + 2;
                pfVar17 = pfVar22 + 2;
                *(float *)((int)pfVar13 + ((int)unaff_ESI - (int)unaff_EBX)) =
                     pfVar14[2] - pfVar22[3];
                local_20 = local_20 + -1;
                *(float *)((int)pfVar17 + ((int)unaff_ESI - (int)unaff_EBX)) = pfVar22[3] + *pfVar13
                ;
                *local_4c = *pfVar17 + pfVar14[3];
                *local_50 = pfVar14[3] - *pfVar17;
                pfVar14 = pfVar13;
                pfVar22 = pfVar17;
              } while (local_20 != 0);
            }
            local_54 = local_54 + param_1;
            local_58 = local_58 + param_1;
            local_64 = local_64 + param_1;
            local_68 = local_68 + param_1;
            local_24 = local_24 + -1;
          } while (local_24 != 0);
        }
        local_28 = local_28 + -1;
      } while (local_28 != 0);
    }
    iVar7 = 0;
    if (3 < param_4) {
      local_20 = (param_4 - 4U >> 2) + 1;
      iVar7 = local_20 * 4;
      puVar15 = (undefined4 *)(param_5 + 4);
      puVar31 = (undefined4 *)(param_6 + 0xc);
      do {
        puVar15[-1] = puVar31[-3];
        *puVar15 = *(undefined4 *)((int)puVar15 + (param_6 - param_5));
        local_20 = local_20 + -1;
        puVar15[1] = puVar31[-1];
        puVar15[2] = *puVar31;
        puVar15 = puVar15 + 4;
        puVar31 = puVar31 + 4;
      } while (local_20 != 0);
    }
    if (iVar7 < param_4) {
      param_4 = param_4 - iVar7;
      puVar15 = (undefined4 *)(param_5 + iVar7 * 4);
      do {
        param_4 = param_4 + -1;
        *puVar15 = *(undefined4 *)((int)puVar15 + (param_6 - param_5));
        puVar15 = puVar15 + 1;
      } while (param_4 != 0);
    }
    iVar7 = 0;
    if (1 < param_2) {
      local_20 = param_2 + -1;
      do {
        iVar7 = iVar7 + iVar8;
        iVar10 = 0;
        iVar11 = iVar7;
        if (3 < param_3) {
          iVar25 = (param_3 - 4U >> 2) + 1;
          iVar10 = iVar25 * 4;
          do {
            unaff_EBX[iVar11] = unaff_ESI[iVar11];
            iVar11 = iVar11 + param_1;
            unaff_EBX[iVar11] = unaff_ESI[iVar11];
            iVar11 = iVar11 + param_1;
            unaff_EBX[iVar11] = unaff_ESI[iVar11];
            iVar11 = iVar11 + param_1;
            unaff_EBX[iVar11] = unaff_ESI[iVar11];
            iVar11 = iVar11 + param_1;
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
        }
        if (iVar10 < param_3) {
          pfVar16 = unaff_EBX + iVar11;
          iVar10 = param_3 - iVar10;
          do {
            *pfVar16 = *(float *)(((int)unaff_ESI - (int)unaff_EBX) + (int)pfVar16);
            pfVar16 = pfVar16 + param_1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        local_20 = local_20 + -1;
      } while (local_20 != 0);
    }
    if (param_3 < iVar9) {
      if (1 < param_2) {
        pfVar14 = (float *)(param_7 + (-1 - param_1) * 4);
        pfVar16 = unaff_ESI + -1;
        local_28 = param_2 + -1;
        pfVar22 = unaff_EBX;
        do {
          pfVar22 = pfVar22 + iVar8;
          pfVar16 = pfVar16 + iVar8;
          pfVar14 = pfVar14 + param_1;
          if (0 < param_3) {
            local_24 = param_3;
            pfVar13 = pfVar22;
            local_40 = pfVar16;
            do {
              if (2 < param_1) {
                iVar7 = (param_1 - 3U >> 1) + 1;
                pfVar17 = local_40;
                pfVar23 = pfVar14;
                pfVar28 = pfVar13;
                do {
                  pfVar24 = pfVar23 + 2;
                  pfVar21 = pfVar17 + 2;
                  pfVar28 = pfVar28 + 2;
                  iVar7 = iVar7 + -1;
                  *(float *)(((int)unaff_EBX - (int)unaff_ESI) + (int)pfVar21) =
                       pfVar23[1] * pfVar17[2] - *pfVar24 * pfVar17[3];
                  *pfVar28 = pfVar17[3] * pfVar23[1] + *pfVar24 * *pfVar21;
                  pfVar17 = pfVar21;
                  pfVar23 = pfVar24;
                } while (iVar7 != 0);
              }
              local_40 = local_40 + param_1;
              pfVar13 = pfVar13 + param_1;
              local_24 = local_24 + -1;
            } while (local_24 != 0);
          }
          local_28 = local_28 + -1;
        } while (local_28 != 0);
        return;
      }
    }
    else {
      iVar7 = 0;
      if (1 < param_2) {
        local_28 = param_2 + -1;
        pfVar16 = (float *)(param_7 + (-1 - param_1) * 4);
        do {
          iVar7 = iVar7 + iVar8;
          pfVar16 = pfVar16 + param_1;
          if (2 < param_1) {
            local_24 = (param_1 - 3U >> 1) + 1;
            iVar9 = iVar7;
            pfVar14 = pfVar16;
            do {
              iVar9 = iVar9 + 2;
              pfVar22 = pfVar14 + 2;
              local_70 = (float *)0x0;
              iVar10 = iVar9;
              if (3 < param_3) {
                iVar11 = (param_3 - 4U >> 2) + 1;
                local_70 = (float *)(iVar11 * 4);
                do {
                  unaff_EBX[iVar10 + -1] =
                       unaff_ESI[iVar10 + -1] * pfVar14[1] - unaff_ESI[iVar10] * *pfVar22;
                  unaff_EBX[iVar10] =
                       unaff_ESI[iVar10] * pfVar14[1] + unaff_ESI[iVar10 + -1] * *pfVar22;
                  iVar10 = iVar10 + param_1;
                  unaff_EBX[iVar10 + -1] =
                       unaff_ESI[iVar10 + -1] * pfVar14[1] - unaff_ESI[iVar10] * *pfVar22;
                  unaff_EBX[iVar10] =
                       unaff_ESI[iVar10] * pfVar14[1] + unaff_ESI[iVar10 + -1] * *pfVar22;
                  iVar10 = iVar10 + param_1;
                  unaff_EBX[iVar10 + -1] =
                       unaff_ESI[iVar10 + -1] * pfVar14[1] - unaff_ESI[iVar10] * *pfVar22;
                  unaff_EBX[iVar10] =
                       unaff_ESI[iVar10] * pfVar14[1] + unaff_ESI[iVar10 + -1] * *pfVar22;
                  iVar10 = iVar10 + param_1;
                  unaff_EBX[iVar10 + -1] =
                       unaff_ESI[iVar10 + -1] * pfVar14[1] - unaff_ESI[iVar10] * *pfVar22;
                  unaff_EBX[iVar10] =
                       unaff_ESI[iVar10] * pfVar14[1] + unaff_ESI[iVar10 + -1] * *pfVar22;
                  iVar10 = iVar10 + param_1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
              }
              if ((int)local_70 < param_3) {
                local_20 = param_3 - (int)local_70;
                pfVar13 = unaff_EBX + iVar10;
                pfVar17 = unaff_ESI + iVar10 + -1;
                do {
                  *(float *)(((int)unaff_EBX - (int)unaff_ESI) + (int)pfVar17) =
                       pfVar14[1] * *pfVar17 - pfVar17[1] * *pfVar22;
                  pfVar23 = pfVar17 + 1;
                  fVar2 = *pfVar17;
                  pfVar17 = pfVar17 + param_1;
                  *pfVar13 = *pfVar22 * fVar2 + *pfVar23 * pfVar14[1];
                  pfVar13 = pfVar13 + param_1;
                  local_20 = local_20 + -1;
                } while (local_20 != 0);
              }
              local_24 = local_24 + -1;
              pfVar14 = pfVar22;
            } while (local_24 != 0);
          }
          local_28 = local_28 + -1;
        } while (local_28 != 0);
      }
    }
  }
  return;
}

