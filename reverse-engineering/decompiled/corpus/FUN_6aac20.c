/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6aac20; label: FUN_006aac20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006aac20(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  int in_EAX;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  float *pfVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  float *pfVar19;
  undefined4 *puVar20;
  float *pfVar21;
  float *in_ECX;
  int iVar22;
  float *pfVar23;
  int iVar24;
  int iVar25;
  float *pfVar26;
  int iVar27;
  int unaff_EBX;
  int iVar28;
  float10 fVar29;
  float10 fVar30;
  float *local_78;
  int local_74;
  int local_6c;
  int local_5c;
  float *local_58;
  float *local_54;
  float *local_50;
  float *local_4c;
  float *local_48;
  float *local_44;
  float *local_40;
  float *local_3c;
  float *local_38;
  float *local_34;
  float local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  fVar29 = (float10)FUN_006ebcb0();
  fVar30 = (float10)FUN_006e8e80();
  iVar7 = param_1 + 1 >> 1;
  iVar8 = unaff_EBX + -1 >> 1;
  iVar9 = unaff_EBX * param_2;
  iVar10 = unaff_EBX * param_1;
  if (unaff_EBX != 1) {
    iVar24 = 0;
    if (3 < param_3) {
      local_38 = (float *)((param_3 - 4U >> 2) + 1);
      iVar24 = (int)local_38 * 4;
      puVar11 = (undefined4 *)(param_6 + 4);
      puVar20 = (undefined4 *)(param_5 + 0xc);
      do {
        puVar11[-1] = puVar20[-3];
        local_38 = (float *)((int)local_38 + -1);
        *puVar11 = *(undefined4 *)((param_5 - param_6) + -0x10 + (int)(puVar11 + 4));
        puVar11[1] = puVar20[-1];
        puVar11[2] = *puVar20;
        puVar11 = puVar11 + 4;
        puVar20 = puVar20 + 4;
      } while (local_38 != (float *)0x0);
    }
    if (iVar24 < param_3) {
      iVar22 = param_3 - iVar24;
      puVar11 = (undefined4 *)(param_6 + iVar24 * 4);
      do {
        iVar22 = iVar22 + -1;
        *puVar11 = *(undefined4 *)((int)puVar11 + (param_5 - param_6));
        puVar11 = puVar11 + 1;
      } while (iVar22 != 0);
    }
    iVar24 = 0;
    if (1 < param_1) {
      local_38 = (float *)(param_1 + -1);
      do {
        iVar24 = iVar24 + iVar9;
        local_78 = (float *)0x0;
        iVar22 = iVar24;
        if (3 < param_2) {
          iVar25 = (param_2 - 4U >> 2) + 1;
          local_78 = (float *)(iVar25 * 4);
          do {
            *(float *)(in_EAX + iVar22 * 4) = in_ECX[iVar22];
            iVar22 = iVar22 + unaff_EBX;
            *(float *)(in_EAX + iVar22 * 4) = in_ECX[iVar22];
            iVar22 = iVar22 + unaff_EBX;
            *(float *)(in_EAX + iVar22 * 4) = in_ECX[iVar22];
            iVar22 = iVar22 + unaff_EBX;
            *(float *)(in_EAX + iVar22 * 4) = in_ECX[iVar22];
            iVar22 = iVar22 + unaff_EBX;
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
        }
        if ((int)local_78 < param_2) {
          iVar25 = param_2 - (int)local_78;
          puVar11 = (undefined4 *)(in_EAX + iVar22 * 4);
          do {
            *puVar11 = *(undefined4 *)(((int)in_ECX - in_EAX) + (int)puVar11);
            puVar11 = puVar11 + unaff_EBX;
            iVar25 = iVar25 + -1;
          } while (iVar25 != 0);
        }
        local_38 = (float *)((int)local_38 + -1);
      } while (local_38 != (float *)0x0);
    }
    iVar24 = -unaff_EBX;
    iVar22 = 0;
    if (param_2 < iVar8) {
      if (1 < param_1) {
        local_3c = (float *)(param_7 + -4 + unaff_EBX * -4);
        pfVar26 = (float *)(in_EAX + unaff_EBX * -4);
        pfVar19 = in_ECX + (-1 - unaff_EBX);
        local_50 = (float *)(param_1 + -1);
        do {
          pfVar26 = pfVar26 + iVar9;
          pfVar19 = pfVar19 + iVar9;
          local_3c = local_3c + unaff_EBX;
          if (0 < param_2) {
            local_4c = (float *)param_2;
            pfVar21 = pfVar19;
            pfVar14 = pfVar26;
            do {
              pfVar14 = pfVar14 + unaff_EBX;
              pfVar21 = pfVar21 + unaff_EBX;
              if (2 < unaff_EBX) {
                local_48 = (float *)((unaff_EBX - 3U >> 1) + 1);
                pfVar12 = pfVar21;
                pfVar23 = local_3c;
                local_40 = pfVar14;
                do {
                  local_40 = local_40 + 2;
                  pfVar13 = pfVar12 + 2;
                  local_48 = (float *)((int)local_48 + -1);
                  *(float *)((in_EAX - (int)in_ECX) + (int)pfVar13) =
                       pfVar23[1] * *pfVar13 + pfVar12[3] * pfVar23[2];
                  *local_40 = pfVar12[3] * pfVar23[1] - pfVar23[2] * *pfVar13;
                  pfVar12 = pfVar13;
                  pfVar23 = pfVar23 + 2;
                } while (local_48 != (float *)0x0);
              }
              local_4c = (float *)((int)local_4c + -1);
            } while (local_4c != (float *)0x0);
          }
          local_50 = (float *)((int)local_50 + -1);
        } while (local_50 != (float *)0x0);
      }
    }
    else if (1 < param_1) {
      local_3c = (float *)(iVar24 + -1);
      local_40 = (float *)(param_7 + -4 + unaff_EBX * -4);
      local_54 = (float *)(param_1 + -1);
      iVar25 = iVar24;
      do {
        iVar22 = iVar22 + iVar9;
        local_3c = (float *)((int)local_3c + unaff_EBX);
        iVar25 = iVar25 + unaff_EBX;
        local_40 = local_40 + unaff_EBX;
        if (2 < unaff_EBX) {
          local_48 = (float *)(((int)local_3c - iVar25) + 1 + iVar22);
          local_50 = (float *)((unaff_EBX - 3U >> 1) + 1);
          pfVar19 = local_40;
          do {
            local_48 = (float *)((int)local_48 + 2);
            pfVar26 = pfVar19 + 2;
            local_78 = (float *)0x0;
            iVar15 = (int)local_48;
            if (3 < param_2) {
              iVar27 = (param_2 - 4U >> 2) + 1;
              local_78 = (float *)(iVar27 * 4);
              do {
                *(float *)(in_EAX + -4 + iVar15 * 4) =
                     in_ECX[iVar15] * *pfVar26 + pfVar19[1] * in_ECX[iVar15 + -1];
                *(float *)(in_EAX + iVar15 * 4) =
                     pfVar19[1] * in_ECX[iVar15] - in_ECX[iVar15 + -1] * *pfVar26;
                iVar15 = iVar15 + unaff_EBX;
                *(float *)(in_EAX + -4 + iVar15 * 4) =
                     in_ECX[iVar15] * *pfVar26 + pfVar19[1] * in_ECX[iVar15 + -1];
                *(float *)(in_EAX + iVar15 * 4) =
                     pfVar19[1] * in_ECX[iVar15] - in_ECX[iVar15 + -1] * *pfVar26;
                iVar15 = iVar15 + unaff_EBX;
                *(float *)(in_EAX + -4 + iVar15 * 4) =
                     in_ECX[iVar15] * *pfVar26 + pfVar19[1] * in_ECX[iVar15 + -1];
                *(float *)(in_EAX + iVar15 * 4) =
                     pfVar19[1] * in_ECX[iVar15] - in_ECX[iVar15 + -1] * *pfVar26;
                iVar15 = iVar15 + unaff_EBX;
                *(float *)(in_EAX + -4 + iVar15 * 4) =
                     in_ECX[iVar15] * *pfVar26 + pfVar19[1] * in_ECX[iVar15 + -1];
                *(float *)(in_EAX + iVar15 * 4) =
                     pfVar19[1] * in_ECX[iVar15] - in_ECX[iVar15 + -1] * *pfVar26;
                iVar15 = iVar15 + unaff_EBX;
                iVar27 = iVar27 + -1;
              } while (iVar27 != 0);
            }
            if ((int)local_78 < param_2) {
              local_4c = (float *)(param_2 - (int)local_78);
              pfVar21 = (float *)(in_EAX + iVar15 * 4);
              pfVar14 = in_ECX + iVar15 + -1;
              do {
                *(float *)((in_EAX - (int)in_ECX) + (int)pfVar14) =
                     pfVar14[1] * *pfVar26 + pfVar19[1] * *pfVar14;
                pfVar12 = pfVar14 + 1;
                fVar1 = *pfVar14;
                pfVar14 = pfVar14 + unaff_EBX;
                *pfVar21 = pfVar19[1] * *pfVar12 - *pfVar26 * fVar1;
                pfVar21 = pfVar21 + unaff_EBX;
                local_4c = (float *)((int)local_4c + -1);
              } while (local_4c != (float *)0x0);
            }
            local_50 = (float *)((int)local_50 + -1);
            pfVar19 = pfVar26;
          } while (local_50 != (float *)0x0);
        }
        local_54 = (float *)((int)local_54 + -1);
      } while (local_54 != (float *)0x0);
    }
    iVar22 = iVar9 * param_1;
    local_74 = 0;
    if (iVar8 < param_2) {
      if (1 < iVar7) {
        local_50 = (float *)(iVar7 + -1);
        local_3c = (float *)iVar24;
        do {
          local_74 = local_74 + iVar9;
          local_3c = (float *)((int)local_3c + iVar9);
          iVar22 = iVar22 - iVar9;
          if (2 < unaff_EBX) {
            local_4c = (float *)((unaff_EBX - 3U >> 1) + 1);
            iVar24 = (int)local_3c;
            do {
              iVar24 = iVar24 + 2;
              iVar25 = iVar24 + (iVar22 - local_74);
              local_78 = (float *)0x0;
              iVar15 = iVar24;
              if (3 < param_2) {
                iVar27 = (param_2 - 4U >> 2) + 1;
                local_78 = (float *)(iVar27 * 4);
                do {
                  iVar25 = iVar25 + unaff_EBX;
                  iVar15 = iVar15 + unaff_EBX;
                  in_ECX[iVar15 + -1] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) + *(float *)(in_EAX + -4 + iVar15 * 4);
                  in_ECX[iVar25 + -1] =
                       *(float *)(in_EAX + iVar15 * 4) - *(float *)(in_EAX + iVar25 * 4);
                  in_ECX[iVar15] = *(float *)(in_EAX + iVar15 * 4) + *(float *)(in_EAX + iVar25 * 4)
                  ;
                  iVar16 = iVar15 + unaff_EBX;
                  in_ECX[iVar25] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) - *(float *)(in_EAX + -4 + iVar15 * 4);
                  iVar25 = iVar25 + unaff_EBX;
                  in_ECX[iVar16 + -1] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) + *(float *)(in_EAX + -4 + iVar16 * 4);
                  in_ECX[iVar25 + -1] =
                       *(float *)(in_EAX + iVar16 * 4) - *(float *)(in_EAX + iVar25 * 4);
                  in_ECX[iVar16] = *(float *)(in_EAX + iVar16 * 4) + *(float *)(in_EAX + iVar25 * 4)
                  ;
                  iVar17 = iVar16 + unaff_EBX;
                  in_ECX[iVar25] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) - *(float *)(in_EAX + -4 + iVar16 * 4);
                  iVar25 = iVar25 + unaff_EBX;
                  in_ECX[iVar17 + -1] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) + *(float *)(in_EAX + -4 + iVar17 * 4);
                  in_ECX[iVar25 + -1] =
                       *(float *)(in_EAX + iVar17 * 4) - *(float *)(in_EAX + iVar25 * 4);
                  in_ECX[iVar17] = *(float *)(in_EAX + iVar17 * 4) + *(float *)(in_EAX + iVar25 * 4)
                  ;
                  iVar15 = iVar17 + unaff_EBX;
                  in_ECX[iVar25] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) - *(float *)(in_EAX + -4 + iVar17 * 4);
                  iVar25 = iVar25 + unaff_EBX;
                  iVar27 = iVar27 + -1;
                  in_ECX[iVar15 + -1] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) + *(float *)(in_EAX + -4 + iVar15 * 4);
                  in_ECX[iVar25 + -1] =
                       *(float *)(in_EAX + iVar15 * 4) - *(float *)(in_EAX + iVar25 * 4);
                  in_ECX[iVar15] = *(float *)(in_EAX + iVar15 * 4) + *(float *)(in_EAX + iVar25 * 4)
                  ;
                  in_ECX[iVar25] =
                       *(float *)(in_EAX + -4 + iVar25 * 4) - *(float *)(in_EAX + -4 + iVar15 * 4);
                } while (iVar27 != 0);
              }
              if ((int)local_78 < param_2) {
                local_44 = in_ECX + iVar25;
                local_40 = in_ECX + iVar15;
                local_38 = (float *)(param_2 - (int)local_78);
                pfVar19 = (float *)(in_EAX + -4 + iVar15 * 4);
                pfVar26 = (float *)(in_EAX + -4 + iVar25 * 4);
                do {
                  pfVar21 = pfVar19 + unaff_EBX;
                  pfVar14 = pfVar26 + unaff_EBX;
                  local_40 = local_40 + unaff_EBX;
                  local_44 = local_44 + unaff_EBX;
                  pfVar19 = pfVar19 + unaff_EBX;
                  pfVar26 = pfVar26 + unaff_EBX;
                  *(float *)((int)pfVar19 + ((int)in_ECX - in_EAX)) = *pfVar21 + *pfVar14;
                  local_38 = (float *)((int)local_38 + -1);
                  *(float *)((int)pfVar26 + ((int)in_ECX - in_EAX)) = pfVar19[1] - pfVar26[1];
                  *local_40 = pfVar26[1] + pfVar19[1];
                  *local_44 = *pfVar26 - *pfVar19;
                } while (local_38 != (float *)0x0);
              }
              local_4c = (float *)((int)local_4c + -1);
            } while (local_4c != (float *)0x0);
          }
          local_50 = (float *)((int)local_50 + -1);
        } while (local_50 != (float *)0x0);
      }
    }
    else if (1 < iVar7) {
      local_40 = in_ECX + iVar22;
      local_44 = (float *)(in_EAX + -4 + iVar22 * 4);
      local_3c = (float *)(in_EAX + -4);
      local_6c = iVar7 + -1;
      pfVar19 = in_ECX;
      do {
        local_3c = local_3c + iVar9;
        local_40 = local_40 + -iVar9;
        local_44 = local_44 + -iVar9;
        pfVar19 = pfVar19 + iVar9;
        if (0 < param_2) {
          local_5c = param_2;
          pfVar26 = local_44;
          local_58 = local_40;
          local_54 = local_3c;
          local_50 = pfVar19;
          do {
            if (2 < unaff_EBX) {
              local_4c = local_58;
              local_48 = local_50;
              iVar24 = (unaff_EBX - 3U >> 1) + 1;
              pfVar21 = local_54;
              pfVar14 = pfVar26;
              do {
                local_48 = local_48 + 2;
                local_4c = local_4c + 2;
                pfVar23 = pfVar14 + 2;
                pfVar12 = pfVar21 + 2;
                iVar24 = iVar24 + -1;
                *(float *)((int)pfVar12 + ((int)in_ECX - in_EAX)) = pfVar14[2] + pfVar21[2];
                *(float *)((int)pfVar23 + ((int)in_ECX - in_EAX)) = pfVar21[3] - pfVar14[3];
                *local_48 = pfVar14[3] + pfVar21[3];
                *local_4c = *pfVar23 - *pfVar12;
                pfVar21 = pfVar12;
                pfVar14 = pfVar23;
              } while (iVar24 != 0);
            }
            local_50 = local_50 + unaff_EBX;
            local_54 = local_54 + unaff_EBX;
            local_58 = local_58 + unaff_EBX;
            pfVar26 = pfVar26 + unaff_EBX;
            local_5c = local_5c + -1;
          } while (local_5c != 0);
        }
        local_6c = local_6c + -1;
      } while (local_6c != 0);
    }
  }
  iVar24 = 0;
  if (3 < param_3) {
    local_38 = (float *)((param_3 - 4U >> 2) + 1);
    iVar24 = (int)local_38 * 4;
    puVar11 = (undefined4 *)(param_5 + 4);
    puVar20 = (undefined4 *)(param_6 + 0xc);
    do {
      puVar11[-1] = puVar20[-3];
      local_38 = (float *)((int)local_38 + -1);
      *puVar11 = *(undefined4 *)((param_6 - param_5) + -0x10 + (int)(puVar11 + 4));
      puVar11[1] = puVar20[-1];
      puVar11[2] = *puVar20;
      puVar11 = puVar11 + 4;
      puVar20 = puVar20 + 4;
    } while (local_38 != (float *)0x0);
  }
  if (iVar24 < param_3) {
    iVar22 = param_3 - iVar24;
    puVar11 = (undefined4 *)(param_5 + iVar24 * 4);
    do {
      iVar22 = iVar22 + -1;
      *puVar11 = *(undefined4 *)((param_6 - param_5) + (int)puVar11);
      puVar11 = puVar11 + 1;
    } while (iVar22 != 0);
  }
  iVar24 = param_1 * param_3;
  if (1 < iVar7) {
    iVar25 = iVar24 - unaff_EBX;
    iVar22 = -unaff_EBX;
    local_3c = (float *)(iVar7 + -1);
    do {
      iVar22 = iVar22 + iVar9;
      iVar25 = iVar25 - iVar9;
      local_78 = (float *)0x0;
      iVar15 = iVar22;
      iVar27 = iVar25;
      if (3 < param_2) {
        iVar16 = (param_2 - 4U >> 2) + 1;
        local_78 = (float *)(iVar16 * 4);
        do {
          iVar15 = iVar15 + unaff_EBX;
          iVar27 = iVar27 + unaff_EBX;
          in_ECX[iVar15] = *(float *)(in_EAX + iVar15 * 4) + *(float *)(in_EAX + iVar27 * 4);
          iVar17 = iVar15 + unaff_EBX;
          in_ECX[iVar27] = *(float *)(in_EAX + iVar27 * 4) - *(float *)(in_EAX + iVar15 * 4);
          iVar27 = iVar27 + unaff_EBX;
          in_ECX[iVar17] = *(float *)(in_EAX + iVar17 * 4) + *(float *)(in_EAX + iVar27 * 4);
          iVar18 = iVar17 + unaff_EBX;
          in_ECX[iVar27] = *(float *)(in_EAX + iVar27 * 4) - *(float *)(in_EAX + iVar17 * 4);
          iVar27 = iVar27 + unaff_EBX;
          in_ECX[iVar18] = *(float *)(in_EAX + iVar18 * 4) + *(float *)(in_EAX + iVar27 * 4);
          iVar15 = iVar18 + unaff_EBX;
          in_ECX[iVar27] = *(float *)(in_EAX + iVar27 * 4) - *(float *)(in_EAX + iVar18 * 4);
          iVar27 = iVar27 + unaff_EBX;
          iVar16 = iVar16 + -1;
          in_ECX[iVar15] = *(float *)(in_EAX + iVar15 * 4) + *(float *)(in_EAX + iVar27 * 4);
          in_ECX[iVar27] = *(float *)(in_EAX + iVar27 * 4) - *(float *)(in_EAX + iVar15 * 4);
        } while (iVar16 != 0);
      }
      if ((int)local_78 < param_2) {
        local_38 = (float *)(param_2 - (int)local_78);
        pfVar19 = (float *)(in_EAX + iVar15 * 4);
        pfVar26 = (float *)(in_EAX + iVar27 * 4);
        do {
          pfVar21 = pfVar26 + unaff_EBX;
          pfVar26 = pfVar26 + unaff_EBX;
          pfVar14 = pfVar19 + unaff_EBX;
          pfVar19 = pfVar19 + unaff_EBX;
          local_38 = (float *)((int)local_38 + -1);
          *(float *)(((int)in_ECX - in_EAX) + (int)pfVar19) = *pfVar21 + *pfVar14;
          *(float *)(((int)in_ECX - in_EAX) + (int)pfVar26) = *pfVar26 - *pfVar19;
        } while (local_38 != (float *)0x0);
      }
      local_3c = (float *)((int)local_3c + -1);
    } while (local_3c != (float *)0x0);
  }
  local_30 = 1.0;
  iVar22 = (param_1 + -1) * param_3;
  local_74 = 0;
  if (1 < iVar7) {
    local_44 = (float *)(param_6 + 8);
    fVar1 = 0.0;
    local_48 = (float *)(param_6 + 8 + iVar24 * 4);
    iVar25 = iVar7 + -1;
    do {
      local_44 = local_44 + param_3;
      local_48 = local_48 + -param_3;
      iVar24 = iVar24 - param_3;
      local_74 = local_74 + param_3;
      fVar5 = (float)fVar29 * local_30 - (float)fVar30 * fVar1;
      iVar15 = 0;
      local_5c = param_3;
      fVar1 = fVar1 * (float)fVar29 + (float)fVar30 * local_30;
      iVar27 = iVar24;
      iVar16 = local_74;
      local_3c = (float *)iVar22;
      if (3 < param_3) {
        local_58 = (float *)(param_5 + 8 + param_3 * 4);
        iVar17 = (param_3 - 4U >> 2) + 1;
        iVar15 = iVar17 * 4;
        iVar16 = local_74 + iVar15;
        iVar27 = iVar24 + iVar15;
        local_3c = (float *)(iVar22 + iVar15);
        local_5c = iVar15 + param_3;
        pfVar19 = local_44;
        local_78 = (float *)(param_5 + 8 + iVar22 * 4);
        local_54 = (float *)(param_5 + 8);
        local_4c = local_48;
        do {
          pfVar19[-2] = local_58[-2] * fVar5 + local_54[-2];
          local_4c[-2] = local_78[-2] * fVar1;
          pfVar19[-1] = local_58[-1] * fVar5 + local_54[-1];
          local_4c[-1] = local_78[-1] * fVar1;
          *pfVar19 = *local_58 * fVar5 + *local_54;
          *local_4c = *local_78 * fVar1;
          pfVar26 = local_58 + 1;
          local_58 = local_58 + 4;
          pfVar19[1] = *pfVar26 * fVar5 + local_54[1];
          iVar17 = iVar17 + -1;
          local_4c[1] = local_78[1] * fVar1;
          pfVar19 = pfVar19 + 4;
          local_78 = local_78 + 4;
          local_54 = local_54 + 4;
          local_4c = local_4c + 4;
        } while (iVar17 != 0);
      }
      if (iVar15 < param_3) {
        pfVar19 = (float *)(param_5 + local_5c * 4);
        pfVar26 = (float *)(param_6 + iVar16 * 4);
        local_4c = (float *)(param_6 + iVar27 * 4);
        local_3c = (float *)(param_5 + (int)local_3c * 4);
        do {
          iVar27 = iVar15 * 4;
          fVar2 = *pfVar19;
          iVar15 = iVar15 + 1;
          pfVar19 = pfVar19 + 1;
          *pfVar26 = fVar2 * fVar5 + *(float *)(param_5 + iVar27);
          *local_4c = *local_3c * fVar1;
          pfVar26 = pfVar26 + 1;
          local_4c = local_4c + 1;
          local_3c = local_3c + 1;
        } while (iVar15 < param_3);
      }
      if (2 < iVar7) {
        local_78 = (float *)(param_5 + 8 + param_3 * 4);
        local_4c = (float *)(param_5 + 8 + iVar22 * 4);
        local_20 = iVar7 + -2;
        iVar15 = iVar22;
        iVar27 = param_3;
        fVar2 = fVar1;
        local_2c = fVar5;
        do {
          iVar15 = iVar15 - param_3;
          local_78 = local_78 + param_3;
          local_4c = local_4c + -param_3;
          iVar27 = iVar27 + param_3;
          fVar6 = local_2c * fVar5 - fVar2 * fVar1;
          iVar16 = 0;
          fVar2 = local_2c * fVar1 + fVar2 * fVar5;
          iVar17 = local_74;
          iVar18 = iVar24;
          local_28 = iVar15;
          local_24 = iVar27;
          if (3 < param_3) {
            iVar28 = (param_3 - 4U >> 2) + 1;
            iVar16 = iVar28 * 4;
            iVar17 = local_74 + iVar16;
            iVar18 = iVar24 + iVar16;
            local_24 = iVar27 + iVar16;
            local_28 = iVar15 + iVar16;
            pfVar19 = local_44;
            pfVar26 = local_48;
            local_58 = local_4c;
            local_54 = local_78;
            do {
              pfVar19[-2] = local_54[-2] * fVar6 + pfVar19[-2];
              pfVar26[-2] = local_58[-2] * fVar2 + pfVar26[-2];
              pfVar19[-1] = local_54[-1] * fVar6 + pfVar19[-1];
              pfVar26[-1] = local_58[-1] * fVar2 + pfVar26[-1];
              *pfVar19 = *local_54 * fVar6 + *pfVar19;
              *pfVar26 = *local_58 * fVar2 + *pfVar26;
              iVar28 = iVar28 + -1;
              pfVar19[1] = local_54[1] * fVar6 + pfVar19[1];
              pfVar26[1] = local_58[1] * fVar2 + pfVar26[1];
              pfVar19 = pfVar19 + 4;
              pfVar26 = pfVar26 + 4;
              local_58 = local_58 + 4;
              local_54 = local_54 + 4;
            } while (iVar28 != 0);
          }
          if (iVar16 < param_3) {
            local_3c = (float *)(param_5 + local_24 * 4);
            iVar16 = param_3 - iVar16;
            pfVar19 = (float *)(param_6 + iVar17 * 4);
            pfVar26 = (float *)(param_6 + iVar18 * 4);
            local_54 = (float *)(param_5 + local_28 * 4);
            do {
              fVar3 = *local_3c;
              local_3c = local_3c + 1;
              iVar16 = iVar16 + -1;
              *pfVar19 = fVar3 * fVar6 + *pfVar19;
              *pfVar26 = *local_54 * fVar2 + *pfVar26;
              pfVar19 = pfVar19 + 1;
              pfVar26 = pfVar26 + 1;
              local_54 = local_54 + 1;
            } while (iVar16 != 0);
          }
          local_20 = local_20 + -1;
          local_2c = fVar6;
        } while (local_20 != 0);
      }
      iVar25 = iVar25 + -1;
      local_30 = fVar5;
    } while (iVar25 != 0);
  }
  iVar24 = 0;
  if (1 < iVar7) {
    local_38 = (float *)(param_5 + 8);
    iVar22 = iVar7 + -1;
    do {
      local_38 = local_38 + param_3;
      iVar24 = iVar24 + param_3;
      iVar25 = 0;
      iVar15 = iVar24;
      if (3 < param_3) {
        iVar27 = (param_3 - 4U >> 2) + 1;
        iVar25 = iVar27 * 4;
        iVar15 = iVar24 + iVar25;
        pfVar19 = (float *)(param_6 + 8);
        pfVar26 = local_38;
        do {
          iVar27 = iVar27 + -1;
          pfVar19[-2] = pfVar26[-2] + pfVar19[-2];
          pfVar19[-1] = pfVar26[-1] + pfVar19[-1];
          *pfVar19 = *pfVar19 + *pfVar26;
          pfVar19[1] = pfVar26[1] + pfVar19[1];
          pfVar19 = pfVar19 + 4;
          pfVar26 = pfVar26 + 4;
        } while (iVar27 != 0);
      }
      if (iVar25 < param_3) {
        pfVar19 = (float *)(param_5 + iVar15 * 4);
        do {
          iVar15 = iVar25 * 4;
          iVar25 = iVar25 + 1;
          fVar1 = *pfVar19;
          pfVar19 = pfVar19 + 1;
          *(float *)(param_6 + -4 + iVar25 * 4) = *(float *)(param_6 + iVar15) + fVar1;
        } while (iVar25 < param_3);
      }
      iVar22 = iVar22 + -1;
    } while (iVar22 != 0);
  }
  if (unaff_EBX < param_2) {
    local_3c = (float *)0x0;
    if (0 < unaff_EBX) {
      do {
        local_78 = (float *)0x0;
        pfVar19 = local_3c;
        pfVar26 = local_3c;
        if (3 < param_2) {
          iVar24 = (param_2 - 4U >> 2) + 1;
          local_78 = (float *)(iVar24 * 4);
          do {
            *(undefined4 *)(param_4 + (int)pfVar26 * 4) = *(undefined4 *)(in_EAX + (int)pfVar19 * 4)
            ;
            iVar22 = (int)pfVar19 + unaff_EBX + unaff_EBX;
            *(undefined4 *)(param_4 + ((int)pfVar26 + iVar10) * 4) =
                 *(undefined4 *)(in_EAX + ((int)pfVar19 + unaff_EBX) * 4);
            iVar15 = (int)pfVar26 + iVar10 + iVar10;
            iVar25 = iVar22 + unaff_EBX;
            *(undefined4 *)(param_4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar22 * 4);
            iVar15 = iVar15 + iVar10;
            pfVar19 = (float *)(iVar25 + unaff_EBX);
            *(undefined4 *)(param_4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar25 * 4);
            pfVar26 = (float *)(iVar15 + iVar10);
            iVar24 = iVar24 + -1;
          } while (iVar24 != 0);
        }
        if ((int)local_78 < param_2) {
          local_38 = (float *)(param_4 + (int)pfVar26 * 4);
          puVar11 = (undefined4 *)(in_EAX + (int)pfVar19 * 4);
          iVar24 = param_2 - (int)local_78;
          do {
            *local_38 = (float)*puVar11;
            puVar11 = puVar11 + unaff_EBX;
            local_38 = local_38 + iVar10;
            iVar24 = iVar24 + -1;
          } while (iVar24 != 0);
        }
        local_3c = (float *)((int)local_3c + 1);
      } while ((int)local_3c < unaff_EBX);
    }
  }
  else {
    local_74 = 0;
    local_6c = 0;
    if (0 < param_2) {
      local_38 = (float *)(in_EAX + 8);
      local_40 = (float *)(param_4 + 8);
      iVar24 = param_2;
      do {
        iVar22 = 0;
        iVar25 = local_74;
        iVar15 = local_6c;
        if (3 < unaff_EBX) {
          iVar27 = (unaff_EBX - 4U >> 2) + 1;
          iVar22 = iVar27 * 4;
          iVar25 = local_74 + iVar22;
          iVar15 = iVar22 + local_6c;
          pfVar19 = local_38;
          pfVar26 = local_40;
          do {
            pfVar26[-2] = pfVar19[-2];
            iVar27 = iVar27 + -1;
            pfVar26[-1] = pfVar19[-1];
            *pfVar26 = *pfVar19;
            pfVar26[1] = pfVar19[1];
            pfVar19 = pfVar19 + 4;
            pfVar26 = pfVar26 + 4;
          } while (iVar27 != 0);
        }
        if (iVar22 < unaff_EBX) {
          puVar11 = (undefined4 *)(param_4 + iVar15 * 4);
          puVar20 = (undefined4 *)(in_EAX + iVar25 * 4);
          iVar22 = unaff_EBX - iVar22;
          do {
            uVar4 = *puVar20;
            puVar20 = puVar20 + 1;
            *puVar11 = uVar4;
            puVar11 = puVar11 + 1;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
        }
        local_74 = local_74 + unaff_EBX;
        local_38 = local_38 + unaff_EBX;
        local_6c = local_6c + iVar10;
        local_40 = local_40 + iVar10;
        iVar24 = iVar24 + -1;
      } while (iVar24 != 0);
    }
  }
  param_1 = iVar9 * param_1;
  iVar24 = 0;
  iVar22 = 0;
  if (1 < iVar7) {
    local_20 = iVar7 + -1;
    iVar25 = param_1;
    do {
      iVar22 = iVar22 + iVar9;
      iVar25 = iVar25 - iVar9;
      iVar24 = iVar24 + unaff_EBX * 2;
      local_78 = (float *)0x0;
      iVar15 = iVar24;
      iVar27 = iVar22;
      iVar16 = iVar25;
      if (3 < param_2) {
        iVar17 = (param_2 - 4U >> 2) + 1;
        local_78 = (float *)(iVar17 * 4);
        do {
          *(undefined4 *)(param_4 + -4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar27 * 4);
          *(undefined4 *)(param_4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar16 * 4);
          iVar15 = iVar15 + iVar10;
          iVar18 = iVar27 + unaff_EBX + unaff_EBX;
          *(undefined4 *)(param_4 + -4 + iVar15 * 4) =
               *(undefined4 *)(in_EAX + (iVar27 + unaff_EBX) * 4);
          iVar27 = iVar16 + unaff_EBX + unaff_EBX;
          *(undefined4 *)(param_4 + iVar15 * 4) = *(undefined4 *)(in_EAX + (iVar16 + unaff_EBX) * 4)
          ;
          iVar15 = iVar15 + iVar10;
          iVar16 = iVar18 + unaff_EBX;
          *(undefined4 *)(param_4 + -4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar18 * 4);
          iVar18 = iVar27 + unaff_EBX;
          *(undefined4 *)(param_4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar27 * 4);
          iVar15 = iVar15 + iVar10;
          iVar27 = iVar16 + unaff_EBX;
          *(undefined4 *)(param_4 + -4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar16 * 4);
          iVar16 = iVar18 + unaff_EBX;
          *(undefined4 *)(param_4 + iVar15 * 4) = *(undefined4 *)(in_EAX + iVar18 * 4);
          iVar15 = iVar15 + iVar10;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      if ((int)local_78 < param_2) {
        local_38 = (float *)(in_EAX + iVar16 * 4);
        puVar11 = (undefined4 *)(in_EAX + iVar27 * 4);
        iVar27 = param_2 - (int)local_78;
        puVar20 = (undefined4 *)(param_4 + iVar15 * 4);
        do {
          puVar20[-1] = *puVar11;
          *puVar20 = *local_38;
          puVar20 = puVar20 + iVar10;
          local_38 = local_38 + unaff_EBX;
          puVar11 = puVar11 + unaff_EBX;
          iVar27 = iVar27 + -1;
        } while (iVar27 != 0);
      }
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  if (unaff_EBX != 1) {
    if (iVar8 < param_2) {
      iVar24 = 0;
      iVar8 = 0;
      if (1 < iVar7) {
        local_2c = (float)(iVar7 + -1);
        iVar7 = -2;
        do {
          iVar7 = iVar7 + unaff_EBX * 2;
          iVar24 = iVar24 + unaff_EBX * 2;
          iVar8 = iVar8 + iVar9;
          param_1 = param_1 - iVar9;
          if (2 < unaff_EBX) {
            local_28 = (unaff_EBX - 3U >> 1) + 1;
            local_34 = (float *)iVar7;
            iVar22 = iVar8;
            do {
              iVar22 = iVar22 + 2;
              local_5c = (iVar24 - iVar8) + iVar22;
              iVar15 = (param_1 - iVar8) + iVar22;
              local_78 = (float *)0x0;
              iVar25 = iVar22;
              pfVar19 = local_34;
              if (3 < param_2) {
                iVar27 = (param_2 - 4U >> 2) + 1;
                local_78 = (float *)(iVar27 * 4);
                do {
                  *(float *)(param_4 + -4 + local_5c * 4) =
                       *(float *)(in_EAX + -4 + iVar15 * 4) + *(float *)(in_EAX + -4 + iVar25 * 4);
                  *(float *)(param_4 + -4 + (int)pfVar19 * 4) =
                       *(float *)(in_EAX + -4 + iVar25 * 4) - *(float *)(in_EAX + -4 + iVar15 * 4);
                  *(float *)(param_4 + local_5c * 4) =
                       *(float *)(in_EAX + iVar25 * 4) + *(float *)(in_EAX + iVar15 * 4);
                  iVar17 = iVar15 + unaff_EBX;
                  iVar16 = iVar25 + unaff_EBX;
                  *(float *)(param_4 + (int)pfVar19 * 4) =
                       *(float *)(in_EAX + iVar15 * 4) - *(float *)(in_EAX + iVar25 * 4);
                  iVar18 = (int)pfVar19 + iVar10;
                  local_5c = local_5c + iVar10;
                  *(float *)(param_4 + -4 + local_5c * 4) =
                       *(float *)(in_EAX + -4 + iVar17 * 4) + *(float *)(in_EAX + -4 + iVar16 * 4);
                  *(float *)(param_4 + -4 + iVar18 * 4) =
                       *(float *)(in_EAX + -4 + iVar16 * 4) - *(float *)(in_EAX + -4 + iVar17 * 4);
                  *(float *)(param_4 + local_5c * 4) =
                       *(float *)(in_EAX + iVar16 * 4) + *(float *)(in_EAX + iVar17 * 4);
                  iVar15 = iVar17 + unaff_EBX;
                  iVar25 = iVar16 + unaff_EBX;
                  *(float *)(param_4 + iVar18 * 4) =
                       *(float *)(in_EAX + iVar17 * 4) - *(float *)(in_EAX + iVar16 * 4);
                  iVar18 = iVar18 + iVar10;
                  local_5c = local_5c + iVar10;
                  *(float *)(param_4 + -4 + local_5c * 4) =
                       *(float *)(in_EAX + -4 + iVar15 * 4) + *(float *)(in_EAX + -4 + iVar25 * 4);
                  *(float *)(param_4 + -4 + iVar18 * 4) =
                       *(float *)(in_EAX + -4 + iVar25 * 4) - *(float *)(in_EAX + -4 + iVar15 * 4);
                  *(float *)(param_4 + local_5c * 4) =
                       *(float *)(in_EAX + iVar25 * 4) + *(float *)(in_EAX + iVar15 * 4);
                  iVar17 = iVar15 + unaff_EBX;
                  iVar16 = iVar25 + unaff_EBX;
                  *(float *)(param_4 + iVar18 * 4) =
                       *(float *)(in_EAX + iVar15 * 4) - *(float *)(in_EAX + iVar25 * 4);
                  iVar18 = iVar18 + iVar10;
                  local_5c = local_5c + iVar10;
                  *(float *)(param_4 + -4 + local_5c * 4) =
                       *(float *)(in_EAX + -4 + iVar17 * 4) + *(float *)(in_EAX + -4 + iVar16 * 4);
                  *(float *)(param_4 + -4 + iVar18 * 4) =
                       *(float *)(in_EAX + -4 + iVar16 * 4) - *(float *)(in_EAX + -4 + iVar17 * 4);
                  *(float *)(param_4 + local_5c * 4) =
                       *(float *)(in_EAX + iVar16 * 4) + *(float *)(in_EAX + iVar17 * 4);
                  iVar15 = iVar17 + unaff_EBX;
                  iVar25 = iVar16 + unaff_EBX;
                  *(float *)(param_4 + iVar18 * 4) =
                       *(float *)(in_EAX + iVar17 * 4) - *(float *)(in_EAX + iVar16 * 4);
                  pfVar19 = (float *)(iVar18 + iVar10);
                  local_5c = local_5c + iVar10;
                  iVar27 = iVar27 + -1;
                } while (iVar27 != 0);
              }
              if ((int)local_78 < param_2) {
                pfVar26 = (float *)(param_4 + local_5c * 4);
                pfVar19 = (float *)(param_4 + (int)pfVar19 * 4);
                iVar27 = param_2 - (int)local_78;
                pfVar21 = (float *)(in_EAX + iVar25 * 4);
                pfVar14 = (float *)(in_EAX + iVar15 * 4);
                do {
                  pfVar26[-1] = pfVar14[-1] + pfVar21[-1];
                  pfVar19[-1] = pfVar21[-1] - pfVar14[-1];
                  *pfVar26 = *pfVar21 + *pfVar14;
                  pfVar26 = pfVar26 + iVar10;
                  *pfVar19 = *pfVar14 - *pfVar21;
                  pfVar19 = pfVar19 + iVar10;
                  pfVar21 = pfVar21 + unaff_EBX;
                  pfVar14 = pfVar14 + unaff_EBX;
                  iVar27 = iVar27 + -1;
                } while (iVar27 != 0);
              }
              local_34 = (float *)((int)local_34 + -2);
              local_28 = local_28 + -1;
            } while (local_28 != 0);
          }
          local_2c = (float)((int)local_2c + -1);
        } while (local_2c != 0.0);
        return;
      }
    }
    else if (1 < iVar7) {
      local_40 = (float *)(in_EAX + 8 + param_1 * 4);
      local_3c = (float *)(param_4 + 8);
      local_38 = (float *)(param_4 + -8);
      local_34 = (float *)(in_EAX + 8);
      local_20 = iVar7 + -1;
      do {
        local_38 = local_38 + unaff_EBX * 2;
        local_3c = local_3c + unaff_EBX * 2;
        local_34 = local_34 + iVar9;
        local_40 = local_40 + -iVar9;
        pfVar19 = local_3c;
        local_4c = local_40;
        local_48 = local_34;
        local_44 = local_38;
        iVar7 = param_2;
        if (0 < param_2) {
          do {
            if (2 < unaff_EBX) {
              iVar8 = (unaff_EBX - 3U >> 1) + 1;
              pfVar26 = local_4c;
              pfVar21 = local_48;
              pfVar14 = local_44;
              pfVar12 = pfVar19;
              do {
                iVar8 = iVar8 + -1;
                pfVar12[-1] = pfVar21[-1] + pfVar26[-1];
                pfVar14[-1] = pfVar21[-1] - pfVar26[-1];
                *pfVar12 = *pfVar21 + *pfVar26;
                *pfVar14 = *pfVar26 - *pfVar21;
                pfVar26 = pfVar26 + 2;
                pfVar21 = pfVar21 + 2;
                pfVar14 = pfVar14 + -2;
                pfVar12 = pfVar12 + 2;
              } while (iVar8 != 0);
            }
            iVar7 = iVar7 + -1;
            pfVar19 = pfVar19 + iVar10;
            local_4c = local_4c + unaff_EBX;
            local_48 = local_48 + unaff_EBX;
            local_44 = local_44 + iVar10;
          } while (iVar7 != 0);
        }
        local_20 = local_20 + -1;
      } while (local_20 != 0);
    }
  }
  return;
}

