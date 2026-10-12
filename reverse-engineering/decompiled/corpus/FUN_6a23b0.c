/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a23b0; label: FUN_006a23b0
 */

undefined4 FUN_006a23b0(int param_1,int *param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  float *pfVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
  float *pfVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int local_3c;
  uint local_2c;
  float *local_18;
  uint local_14;
  float *local_10;
  float *local_8;
  
  iVar14 = *(int *)(param_1 + 4);
  piVar2 = *(int **)(iVar14 + 0x1c);
  iVar3 = *(int *)(param_1 + 0x68);
  iVar4 = piVar2[0x392];
  if (param_2 == (int *)0x0) {
    return 0xffffff7d;
  }
  if ((*(int *)(param_1 + 0x18) < *(int *)(param_1 + 0x14)) && (*(int *)(param_1 + 0x18) != -1)) {
    return 0xffffff7d;
  }
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = param_2[7];
  uVar5 = *(uint *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  if ((((uVar5 & *(uint *)(param_1 + 0x44)) == 0xffffffff) || (uVar5 + 1 != param_2[0xe])) ||
     (*(uint *)(param_1 + 0x44) + (uint)(0xfffffffe < uVar5) != param_2[0xf])) {
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x80) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x84) = 0xffffffff;
  }
  *(int *)(param_1 + 0x40) = param_2[0xe];
  *(int *)(param_1 + 0x44) = param_2[0xf];
  bVar6 = (byte)iVar4;
  if (*param_2 != 0) {
    bVar16 = bVar6 + 1;
    iVar7 = piVar2[*(int *)(param_1 + 0x28)] >> (bVar16 & 0x1f);
    iVar21 = *piVar2 >> (bVar16 & 0x1f);
    uVar23 = piVar2[1] >> (bVar16 & 0x1f);
    uVar15 = param_2[0x16];
    puVar1 = (uint *)(param_1 + 0x48);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + uVar15;
    *(int *)(param_1 + 0x4c) =
         *(int *)(param_1 + 0x4c) + ((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar5,uVar15);
    uVar15 = param_2[0x17];
    puVar1 = (uint *)(param_1 + 0x50);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + uVar15;
    *(int *)(param_1 + 0x54) =
         *(int *)(param_1 + 0x54) + ((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar5,uVar15);
    uVar15 = param_2[0x18];
    puVar1 = (uint *)(param_1 + 0x58);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + uVar15;
    *(int *)(param_1 + 0x5c) =
         *(int *)(param_1 + 0x5c) + ((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar5,uVar15);
    uVar15 = param_2[0x19];
    puVar1 = (uint *)(param_1 + 0x60);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + uVar15;
    *(int *)(param_1 + 100) =
         *(int *)(param_1 + 100) + ((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar5,uVar15);
    if (*(int *)(param_1 + 0x30) == 0) {
      local_14 = 0;
      local_2c = uVar23;
    }
    else {
      local_2c = 0;
      local_14 = uVar23;
    }
    local_3c = 0;
    if (0 < *(int *)(iVar14 + 4)) {
      do {
        if (*(int *)(param_1 + 0x24) == 0) {
          if (*(int *)(param_1 + 0x28) == 0) {
            iVar8 = FUN_006b19c0(*(int *)(iVar3 + 4) - iVar4);
            iVar19 = *(int *)(*(int *)(param_1 + 8) + local_3c * 4) + local_2c * 4;
            iVar17 = *(int *)(*param_2 + local_3c * 4);
            iVar18 = 0;
            if (3 < iVar21) {
              pfVar10 = (float *)(iVar19 + 4);
              pfVar12 = (float *)(iVar8 + 8);
              pfVar22 = (float *)(iVar8 + -8 + iVar21 * 4);
              do {
                iVar24 = iVar18 * 4;
                pfVar9 = (float *)((iVar8 - iVar19) + (int)pfVar10);
                iVar18 = iVar18 + 4;
                pfVar10[-1] = pfVar22[1] * pfVar10[-1] + *(float *)(iVar17 + iVar24) * pfVar12[-2];
                *pfVar10 = *pfVar22 * *pfVar10 +
                           *(float *)((iVar17 - iVar8) + (int)pfVar9) * *pfVar9;
                pfVar10[1] = pfVar22[-1] * pfVar10[1] +
                             *(float *)((int)pfVar12 + (iVar17 - iVar8)) * *pfVar12;
                pfVar10[2] = pfVar22[-2] * pfVar10[2] +
                             *(float *)(iVar17 + -4 + iVar18 * 4) * pfVar12[1];
                pfVar10 = pfVar10 + 4;
                pfVar12 = pfVar12 + 4;
                pfVar22 = pfVar22 + -4;
              } while (iVar18 < iVar21 + -3);
            }
            if (iVar18 < iVar21) {
              iVar24 = iVar21 - iVar18;
              pfVar10 = (float *)(iVar19 + iVar18 * 4);
              local_8 = (float *)(iVar8 + -4 + (iVar21 - iVar18) * 4);
              do {
                pfVar12 = (float *)((int)pfVar10 + (iVar8 - iVar19));
                iVar24 = iVar24 + -1;
                *pfVar10 = *pfVar10 * *local_8 +
                           *(float *)((int)pfVar12 + (iVar17 - iVar8)) * *pfVar12;
                pfVar10 = pfVar10 + 1;
                local_8 = local_8 + -1;
              } while (iVar24 != 0);
            }
          }
          else {
            iVar18 = FUN_006b19c0(*(int *)(iVar3 + 4) - iVar4);
            iVar19 = *(int *)(*(int *)(param_1 + 8) + local_3c * 4) + local_2c * 4;
            iVar17 = *(int *)(*param_2 + local_3c * 4) + ((int)uVar23 / 2 - iVar21 / 2) * 4;
            iVar8 = 0;
            if (3 < iVar21) {
              pfVar10 = (float *)(iVar19 + 4);
              pfVar12 = (float *)(iVar18 + 8);
              pfVar22 = (float *)(iVar18 + -8 + iVar21 * 4);
              do {
                iVar24 = iVar8 * 4;
                pfVar9 = (float *)((iVar18 - iVar19) + (int)pfVar10);
                iVar8 = iVar8 + 4;
                pfVar10[-1] = pfVar22[1] * pfVar10[-1] + *(float *)(iVar17 + iVar24) * pfVar12[-2];
                *pfVar10 = *pfVar22 * *pfVar10 +
                           *(float *)((iVar17 - iVar18) + (int)pfVar9) * *pfVar9;
                pfVar10[1] = pfVar22[-1] * pfVar10[1] +
                             *(float *)((int)pfVar12 + (iVar17 - iVar18)) * *pfVar12;
                pfVar10[2] = pfVar22[-2] * pfVar10[2] +
                             *(float *)(iVar17 + -4 + iVar8 * 4) * pfVar12[1];
                pfVar10 = pfVar10 + 4;
                pfVar12 = pfVar12 + 4;
                pfVar22 = pfVar22 + -4;
              } while (iVar8 < iVar21 + -3);
            }
            if (iVar8 < iVar21) {
              iVar11 = iVar21 - iVar8;
              iVar25 = iVar21 - iVar8;
              iVar24 = iVar8 * 4;
              iVar8 = iVar8 + iVar25;
              pfVar10 = (float *)(iVar19 + iVar24);
              local_10 = (float *)(iVar18 + -4 + iVar11 * 4);
              do {
                pfVar12 = (float *)((iVar18 - iVar19) + (int)pfVar10);
                iVar25 = iVar25 + -1;
                *pfVar10 = *pfVar10 * *local_10 +
                           *(float *)((int)pfVar12 + (iVar17 - iVar18)) * *pfVar12;
                pfVar10 = pfVar10 + 1;
                local_10 = local_10 + -1;
              } while (iVar25 != 0);
            }
            iVar18 = (int)uVar23 / 2 + iVar21 / 2;
            if (3 < iVar18 - iVar8) {
              iVar24 = iVar8 * 4;
              iVar11 = iVar8 * 4;
              iVar25 = ((iVar18 - iVar8) - 4U >> 2) + 1;
              iVar8 = iVar8 + iVar25 * 4;
              puVar13 = (undefined4 *)(iVar19 + 4 + iVar24);
              puVar20 = (undefined4 *)(iVar17 + 0xc + iVar11);
              do {
                puVar13[-1] = puVar20[-3];
                iVar25 = iVar25 + -1;
                *puVar13 = *(undefined4 *)((iVar17 - iVar19) + -0x10 + (int)(puVar13 + 4));
                puVar13[1] = puVar20[-1];
                puVar13[2] = *puVar20;
                puVar13 = puVar13 + 4;
                puVar20 = puVar20 + 4;
              } while (iVar25 != 0);
            }
            if (iVar8 < iVar18) {
              iVar18 = iVar18 - iVar8;
              puVar13 = (undefined4 *)(iVar19 + iVar8 * 4);
              do {
                iVar18 = iVar18 + -1;
                *puVar13 = *(undefined4 *)((int)puVar13 + (iVar17 - iVar19));
                puVar13 = puVar13 + 1;
              } while (iVar18 != 0);
            }
          }
        }
        else if (*(int *)(param_1 + 0x28) == 0) {
          iVar8 = FUN_006b19c0(*(int *)(iVar3 + 4) - iVar4);
          iVar19 = *(int *)(*(int *)(param_1 + 8) + local_3c * 4) +
                   (((int)uVar23 / 2 - iVar21 / 2) + local_2c) * 4;
          iVar17 = *(int *)(*param_2 + local_3c * 4);
          iVar18 = 0;
          if (3 < iVar21) {
            pfVar10 = (float *)(iVar19 + 4);
            pfVar12 = (float *)(iVar8 + 8);
            pfVar22 = (float *)(iVar8 + -8 + iVar21 * 4);
            do {
              iVar24 = iVar18 * 4;
              pfVar9 = (float *)((iVar8 - iVar19) + (int)pfVar10);
              iVar18 = iVar18 + 4;
              pfVar10[-1] = pfVar22[1] * pfVar10[-1] + *(float *)(iVar17 + iVar24) * pfVar12[-2];
              *pfVar10 = *pfVar22 * *pfVar10 + *(float *)((iVar17 - iVar8) + (int)pfVar9) * *pfVar9;
              pfVar10[1] = pfVar22[-1] * pfVar10[1] +
                           *(float *)((int)pfVar12 + (iVar17 - iVar8)) * *pfVar12;
              pfVar10[2] = pfVar22[-2] * pfVar10[2] +
                           *(float *)(iVar17 + -4 + iVar18 * 4) * pfVar12[1];
              pfVar10 = pfVar10 + 4;
              pfVar12 = pfVar12 + 4;
              pfVar22 = pfVar22 + -4;
            } while (iVar18 < iVar21 + -3);
          }
          if (iVar18 < iVar21) {
            iVar24 = iVar21 - iVar18;
            pfVar10 = (float *)(iVar19 + iVar18 * 4);
            local_10 = (float *)(iVar8 + -4 + (iVar21 - iVar18) * 4);
            do {
              pfVar12 = (float *)((int)pfVar10 + (iVar8 - iVar19));
              iVar24 = iVar24 + -1;
              *pfVar10 = *pfVar10 * *local_10 +
                         *(float *)((int)pfVar12 + (iVar17 - iVar8)) * *pfVar12;
              pfVar10 = pfVar10 + 1;
              local_10 = local_10 + -1;
            } while (iVar24 != 0);
          }
        }
        else {
          iVar8 = FUN_006b19c0(*(int *)(iVar3 + 8) - iVar4);
          iVar19 = *(int *)(*(int *)(param_1 + 8) + local_3c * 4) + local_2c * 4;
          iVar17 = *(int *)(*param_2 + local_3c * 4);
          iVar18 = 0;
          if (3 < (int)uVar23) {
            pfVar10 = (float *)(iVar19 + 4);
            pfVar12 = (float *)(iVar8 + 8);
            pfVar22 = (float *)(iVar8 + -8 + uVar23 * 4);
            do {
              iVar24 = iVar18 * 4;
              pfVar9 = (float *)((iVar8 - iVar19) + (int)pfVar10);
              iVar18 = iVar18 + 4;
              pfVar10[-1] = pfVar22[1] * pfVar10[-1] + *(float *)(iVar17 + iVar24) * pfVar12[-2];
              *pfVar10 = *pfVar22 * *pfVar10 + *(float *)((int)pfVar9 + (iVar17 - iVar8)) * *pfVar9;
              pfVar10[1] = pfVar22[-1] * pfVar10[1] +
                           *(float *)((int)pfVar12 + (iVar17 - iVar8)) * *pfVar12;
              pfVar10[2] = pfVar22[-2] * pfVar10[2] +
                           *(float *)(iVar17 + -4 + iVar18 * 4) * pfVar12[1];
              pfVar10 = pfVar10 + 4;
              pfVar12 = pfVar12 + 4;
              pfVar22 = pfVar22 + -4;
            } while (iVar18 < (int)(uVar23 - 3));
          }
          if (iVar18 < (int)uVar23) {
            iVar24 = uVar23 - iVar18;
            pfVar10 = (float *)(iVar19 + iVar18 * 4);
            local_18 = (float *)(iVar8 + -4 + (uVar23 - iVar18) * 4);
            do {
              pfVar12 = (float *)((int)pfVar10 + (iVar8 - iVar19));
              iVar24 = iVar24 + -1;
              *pfVar10 = *pfVar10 * *local_18 +
                         *(float *)((int)pfVar12 + (iVar17 - iVar8)) * *pfVar12;
              pfVar10 = pfVar10 + 1;
              local_18 = local_18 + -1;
            } while (iVar24 != 0);
          }
        }
        iVar17 = *(int *)(*(int *)(param_1 + 8) + local_3c * 4) + local_14 * 4;
        iVar8 = *(int *)(*param_2 + local_3c * 4) + iVar7 * 4;
        iVar19 = 0;
        if (3 < iVar7) {
          iVar18 = (iVar7 - 4U >> 2) + 1;
          iVar19 = iVar18 * 4;
          puVar13 = (undefined4 *)(iVar17 + 4);
          puVar20 = (undefined4 *)(iVar8 + 0xc);
          do {
            puVar13[-1] = puVar20[-3];
            iVar18 = iVar18 + -1;
            *puVar13 = *(undefined4 *)((iVar8 - iVar17) + -0x10 + (int)(puVar13 + 4));
            puVar13[1] = puVar20[-1];
            puVar13[2] = *puVar20;
            puVar13 = puVar13 + 4;
            puVar20 = puVar20 + 4;
          } while (iVar18 != 0);
        }
        if (iVar19 < iVar7) {
          iVar18 = iVar7 - iVar19;
          puVar13 = (undefined4 *)(iVar17 + iVar19 * 4);
          do {
            iVar18 = iVar18 + -1;
            *puVar13 = *(undefined4 *)((int)puVar13 + (iVar8 - iVar17));
            puVar13 = puVar13 + 1;
          } while (iVar18 != 0);
        }
        local_3c = local_3c + 1;
      } while (local_3c < *(int *)(iVar14 + 4));
    }
    *(uint *)(param_1 + 0x30) = ~-(uint)(*(int *)(param_1 + 0x30) != 0) & uVar23;
    if (*(int *)(param_1 + 0x18) == -1) {
      *(uint *)(param_1 + 0x18) = local_14;
      *(uint *)(param_1 + 0x14) = local_14;
    }
    else {
      *(uint *)(param_1 + 0x18) = local_2c;
      *(uint *)(param_1 + 0x14) =
           (((int)(piVar2[*(int *)(param_1 + 0x28)] +
                  (piVar2[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)) >> 2) +
            ((int)(piVar2[*(int *)(param_1 + 0x24)] +
                  (piVar2[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)) >> 2) >> (bVar6 & 0x1f)) +
           local_2c;
    }
  }
  uVar5 = *(uint *)(iVar3 + 0x80);
  if ((uVar5 & *(uint *)(iVar3 + 0x84)) == 0xffffffff) {
    *(undefined4 *)(iVar3 + 0x80) = 0;
    *(undefined4 *)(iVar3 + 0x84) = 0;
  }
  else {
    uVar15 = ((int)(piVar2[*(int *)(param_1 + 0x24)] +
                   (piVar2[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)) >> 2) +
             ((int)(piVar2[*(int *)(param_1 + 0x28)] +
                   (piVar2[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)) >> 2);
    *(uint *)(iVar3 + 0x80) = uVar15 + uVar5;
    *(uint *)(iVar3 + 0x84) =
         ((int)uVar15 >> 0x1f) + *(uint *)(iVar3 + 0x84) + (uint)CARRY4(uVar15,uVar5);
  }
  uVar5 = *(uint *)(param_1 + 0x38);
  if ((uVar5 & *(uint *)(param_1 + 0x3c)) == 0xffffffff) {
    uVar5 = param_2[0xc];
    if ((uVar5 & param_2[0xd]) != 0xffffffff) {
      *(int *)(param_1 + 0x3c) = param_2[0xd];
      *(uint *)(param_1 + 0x38) = uVar5;
      if ((*(int *)(param_1 + 0x3c) <= *(int *)(iVar3 + 0x84)) &&
         ((*(int *)(param_1 + 0x3c) < *(int *)(iVar3 + 0x84) ||
          (*(uint *)(param_1 + 0x38) < *(uint *)(iVar3 + 0x80))))) {
        if (param_2[0xb] == 0) {
          iVar14 = __allshr();
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar14;
          if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 0x18)) {
            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x14);
          }
        }
        else {
          iVar14 = __allshr();
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar14;
        }
      }
    }
  }
  else {
    uVar15 = ((int)(piVar2[*(int *)(param_1 + 0x24)] +
                   (piVar2[*(int *)(param_1 + 0x24)] >> 0x1f & 3U)) >> 2) +
             ((int)(piVar2[*(int *)(param_1 + 0x28)] +
                   (piVar2[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)) >> 2);
    *(uint *)(param_1 + 0x3c) =
         ((int)uVar15 >> 0x1f) + *(uint *)(param_1 + 0x3c) + (uint)CARRY4(uVar15,uVar5);
    *(uint *)(param_1 + 0x38) = uVar15 + uVar5;
    uVar5 = param_2[0xc];
    uVar15 = param_2[0xd];
    if ((uVar5 & uVar15) != 0xffffffff) {
      uVar23 = *(uint *)(param_1 + 0x3c);
      if ((*(uint *)(param_1 + 0x38) != uVar5) || (uVar23 != uVar15)) {
        if (((((int)uVar15 <= (int)uVar23) &&
             (((int)uVar15 < (int)uVar23 || (uVar5 < *(uint *)(param_1 + 0x38))))) &&
            (iVar14 = *(int *)(param_1 + 0x38) - param_2[0xc], iVar14 != 0)) && (param_2[0xb] != 0))
        {
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - (iVar14 >> (bVar6 & 0x1f));
        }
        *(int *)(param_1 + 0x38) = param_2[0xc];
        *(int *)(param_1 + 0x3c) = param_2[0xd];
      }
    }
  }
  if (param_2[0xb] != 0) {
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return 0;
}

