/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a7910; label: FUN_006a7910
 */

void FUN_006a7910(int param_1,int param_2,int *param_3,int param_4,int param_5,int param_6,
                 int *param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  uint *puVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  float *pfVar20;
  float10 fVar21;
  float local_ac;
  int *local_a4;
  int local_98;
  int local_94;
  int local_8c;
  float local_84;
  int local_7c;
  int local_74;
  int local_70;
  
  iVar5 = *param_3;
  local_70 = 0;
  if (0 < *(int *)(param_4 + 0x484)) {
    piVar15 = (int *)(param_4 + 0x888);
    local_a4 = param_7;
    iVar14 = iVar5;
    do {
      if ((*(int *)(param_9 + piVar15[-0x100] * 4) != 0) || (*(int *)(param_9 + *piVar15 * 4) != 0))
      {
        iVar6 = *(int *)(piVar15[-0x100] * 4 + param_5);
        iVar7 = *(int *)(*piVar15 * 4 + param_5);
        iVar1 = iVar6 + iVar5 * 4;
        iVar8 = *(int *)(piVar15[-0x100] * 4 + param_8);
        iVar9 = *(int *)(*piVar15 * 4 + param_8);
        dVar3 = *(double *)(&DAT_00816b00 + *(int *)(param_2 + 0xfc + param_1 * 4) * 8);
        dVar4 = *(double *)(&DAT_00816b00 + *(int *)(param_2 + 0x138 + param_1 * 4) * 8);
        piVar10 = (int *)param_3[1];
        iVar18 = iVar14;
        if (piVar10[0x7e] != 0) {
          iVar18 = piVar10[0x80];
        }
        iVar11 = *(int *)(param_2 + 0x84 + (*piVar10 * 0xf + param_1) * 4);
        *(undefined4 *)(param_9 + piVar15[-0x100] * 4) = 1;
        *(undefined4 *)(param_9 + *piVar15 * 4) = 1;
        if (1000 < iVar5) {
          dVar4 = *(double *)(&DAT_00816b48 + *(int *)(param_2 + 0x138 + param_1 * 4) * 8);
        }
        local_84 = (float)dVar4;
        iVar14 = *param_3;
        local_74 = 0;
        if (0 < iVar14) {
          local_8c = 0;
          do {
            local_ac = 0.0;
            if (0 < iVar18) {
              pfVar20 = (float *)(local_8c + iVar7);
              iVar14 = iVar6 - iVar7;
              iVar19 = iVar1 - iVar7;
              local_98 = local_8c;
              local_94 = local_74;
              local_7c = iVar18;
              do {
                if (local_94 < param_10) {
                  if ((((iVar11 <= local_94) && (ABS(*(float *)(iVar14 + (int)pfVar20)) < local_84))
                      && (ABS(*pfVar20) < local_84)) ||
                     ((ABS(*(float *)(iVar14 + (int)pfVar20)) < (float)dVar3 &&
                      (ABS(*pfVar20) < (float)dVar3)))) {
                    puVar2 = (uint *)((iVar8 - iVar7) + (int)pfVar20);
                    uVar12 = *(uint *)((int)puVar2 + (iVar9 - iVar8));
                    uVar13 = *puVar2;
                    uVar17 = (int)(uVar13 - uVar12) >> 0x1f;
                    uVar16 = ((int)uVar12 < (int)uVar13) - 1;
                    uVar17 = 0x1f - ((uVar13 - uVar12 ^ uVar17) - uVar17);
                    *(float *)(iVar19 + (int)pfVar20) =
                         *(float *)(&DAT_00816b90 + (~uVar16 & uVar13 | uVar16 & uVar12) * 4) *
                         (*(float *)(&DAT_00816f90 + (((int)uVar17 < 0) - 1 & uVar17) * 4) + 1.0) *
                         *(float *)(*(int *)((param_6 - (int)param_7) + (int)local_a4) + local_98);
                    pfVar20[iVar5] = 0.0;
                    fVar21 = (float10)FUN_006eafc0();
                    if (fVar21 == (float10)0.0) {
                      local_ac = *(float *)(iVar19 + (int)pfVar20) *
                                 *(float *)(iVar19 + (int)pfVar20) + local_ac;
                    }
                  }
                  else {
                    FUN_006a6f80(*(undefined4 *)(iVar14 + (int)pfVar20),*pfVar20);
                  }
                }
                else {
                  *(undefined4 *)(iVar19 + (int)pfVar20) = 0;
                  pfVar20[iVar5] = 0.0;
                }
                local_98 = local_98 + 4;
                local_94 = local_94 + 1;
                pfVar20 = pfVar20 + 1;
                local_7c = local_7c + -1;
              } while (local_7c != 0);
            }
            if ((*(int *)(param_3[1] + 0x1f8) != 0) && (local_7c = 0, iVar14 = local_8c, 0 < iVar18)
               ) {
              do {
                if (local_ac < (float)*(double *)(param_3[1] + 0x208)) break;
                iVar19 = *(int *)(iVar14 + *local_a4);
                if (((iVar19 < param_10) && (iVar11 <= iVar19)) &&
                   (fVar21 = (float10)FUN_006eafc0(), fVar21 == (float10)0.0)) {
                  local_ac = local_ac - 1.0;
                  *(uint *)(iVar1 + iVar19 * 4) =
                       *(uint *)(iVar1 + iVar19 * 4) & 0xbf800000 | 0x3f800000;
                }
                local_7c = local_7c + 1;
                iVar14 = iVar14 + 4;
              } while (local_7c < iVar18);
            }
            iVar14 = *param_3;
            local_74 = local_74 + iVar18;
            local_8c = local_8c + iVar18 * 4;
          } while (local_74 < iVar14);
        }
      }
      local_a4 = local_a4 + 1;
      local_70 = local_70 + 1;
      piVar15 = piVar15 + 1;
    } while (local_70 < *(int *)(param_4 + 0x484));
  }
  return;
}

