/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x680e90; label: FUN_00680e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00680e90(int param_1,short *param_2,int *param_3)

{
  float *pfVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  float *pfVar9;
  int iVar10;
  short *psVar11;
  float10 fVar12;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined1 local_c [12];
  
  if ((DAT_0292fc68 != (int *)0x0) && (-1 < param_1)) {
    local_74 = 1.2345679e+08;
    local_78 = 1.2345679e+08;
    local_7c = 1.2345679e+08;
    local_88 = -1.2345679e+08;
    pfVar1 = (float *)(*DAT_0292fc68 + param_1 * 0x38);
    local_8c = -1.2345679e+08;
    local_90 = -1.2345679e+08;
    local_70 = 0.0;
    if ((pfVar1[0xb] == 0.0) || (pfVar1[0xb] == 1.4013e-45)) {
      psVar7 = (short *)pfVar1[3];
      sVar2 = *psVar7;
      while (-1 < sVar2) {
        *param_2 = *psVar7;
        param_2[1] = psVar7[1];
        psVar8 = psVar7 + 1;
        psVar7 = psVar7 + 10;
        param_2 = param_2 + 10;
        for (iVar10 = (int)*psVar8; 0 < iVar10; iVar10 = iVar10 + -1) {
          if (*(float *)(psVar7 + 0x2c) <= 65535.0) {
            local_98 = 4.2039e-45;
            iVar4 = 3;
          }
          else {
            iVar4 = 2;
            local_98 = 2.8026e-45;
          }
          psVar8 = psVar7;
          psVar11 = param_2;
          for (iVar6 = 0x19; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined4 *)psVar11 = *(undefined4 *)psVar8;
            psVar8 = psVar8 + 2;
            psVar11 = psVar11 + 2;
          }
          pfVar9 = (float *)(param_2 + (iVar4 * 3 + 6) * 2);
          do {
            pfVar5 = (float *)FUN_0066ed90(local_c,param_3,
                                           psVar7 + (*(int *)(&DAT_00810b38 +
                                                             (iVar4 + *(short *)((int)param_3 + 0x1a
                                                                                ) * 4) * 4) + 2) * 6
                                           ,0xbf800000,(int)(short)param_3[6]);
            *pfVar9 = *pfVar5;
            pfVar9[1] = pfVar5[1];
            pfVar9[2] = pfVar5[2];
            *pfVar9 = *pfVar9 - *(float *)(*param_3 + 0x30);
            pfVar9[1] = pfVar9[1] - *(float *)(*param_3 + 0x34);
            fVar3 = pfVar9[2] - *(float *)(*param_3 + 0x38);
            pfVar9[2] = fVar3;
            if (*pfVar9 < local_7c) {
              local_7c = *pfVar9;
            }
            if (local_90 < *pfVar9) {
              local_90 = *pfVar9;
            }
            if (pfVar9[1] < local_78) {
              local_78 = pfVar9[1];
            }
            if (local_8c < pfVar9[1]) {
              local_8c = pfVar9[1];
            }
            if (fVar3 < local_74) {
              local_74 = fVar3;
            }
            if (local_88 < fVar3) {
              local_88 = fVar3;
            }
            fVar3 = pfVar9[1] * pfVar9[1] + *pfVar9 * *pfVar9 + fVar3 * fVar3;
            if (local_70 < fVar3) {
              local_70 = fVar3;
            }
            iVar4 = (int)local_98 + -1;
            pfVar9 = pfVar9 + -3;
            local_98 = (float)iVar4;
          } while (-1 < iVar4);
          if (*(float *)(psVar7 + 0x2c) < 65535.0) {
            *(float *)(param_2 + 0x2a) =
                 (*(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x20)) *
                 (*(float *)(param_2 + 0x1c) - *(float *)(param_2 + 0x22)) -
                 (*(float *)(param_2 + 0x16) - *(float *)(param_2 + 0x22)) *
                 (*(float *)(param_2 + 0x1a) - *(float *)(param_2 + 0x20));
            *(float *)(param_2 + 0x2c) =
                 (*(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x1e)) *
                 (*(float *)(param_2 + 0x16) - *(float *)(param_2 + 0x22)) -
                 (*(float *)(param_2 + 0x12) - *(float *)(param_2 + 0x1e)) *
                 (*(float *)(param_2 + 0x1c) - *(float *)(param_2 + 0x22));
            *(float *)(param_2 + 0x2e) =
                 (*(float *)(param_2 + 0x1a) - *(float *)(param_2 + 0x20)) *
                 (*(float *)(param_2 + 0x12) - *(float *)(param_2 + 0x1e)) -
                 (*(float *)(param_2 + 0x14) - *(float *)(param_2 + 0x20)) *
                 (*(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x1e));
            fVar3 = *(float *)(param_2 + 0x2e) * *(float *)(param_2 + 0x2e) +
                    *(float *)(param_2 + 0x2a) * *(float *)(param_2 + 0x2a) +
                    *(float *)(param_2 + 0x2c) * *(float *)(param_2 + 0x2c);
            if (fVar3 == 0.0) {
              local_98 = 0.0;
            }
            else {
              fVar12 = (float10)FUN_005c0240(fVar3);
              local_98 = (float)((float10)1 / fVar12);
            }
            *(float *)(param_2 + 0x2a) = local_98 * *(float *)(param_2 + 0x2a);
            *(float *)(param_2 + 0x2c) = *(float *)(param_2 + 0x2c) * local_98;
            *(float *)(param_2 + 0x2e) = local_98 * *(float *)(param_2 + 0x2e);
          }
          *(float *)(param_2 + 0x24) =
               (*(float *)(param_2 + 0x1a) - *(float *)(param_2 + 0xe)) *
               (*(float *)(param_2 + 0x16) - *(float *)(param_2 + 0x10)) -
               (*(float *)(param_2 + 0x1c) - *(float *)(param_2 + 0x10)) *
               (*(float *)(param_2 + 0x14) - *(float *)(param_2 + 0xe));
          *(float *)(param_2 + 0x26) =
               (*(float *)(param_2 + 0x12) - *(float *)(param_2 + 0xc)) *
               (*(float *)(param_2 + 0x1c) - *(float *)(param_2 + 0x10)) -
               (*(float *)(param_2 + 0x18) - *(float *)(param_2 + 0xc)) *
               (*(float *)(param_2 + 0x16) - *(float *)(param_2 + 0x10));
          *(float *)(param_2 + 0x28) =
               (*(float *)(param_2 + 0x14) - *(float *)(param_2 + 0xe)) *
               (*(float *)(param_2 + 0x18) - *(float *)(param_2 + 0xc)) -
               (*(float *)(param_2 + 0x1a) - *(float *)(param_2 + 0xe)) *
               (*(float *)(param_2 + 0x12) - *(float *)(param_2 + 0xc));
          fVar3 = *(float *)(param_2 + 0x28) * *(float *)(param_2 + 0x28) +
                  *(float *)(param_2 + 0x24) * *(float *)(param_2 + 0x24) +
                  *(float *)(param_2 + 0x26) * *(float *)(param_2 + 0x26);
          if (fVar3 == 0.0) {
            local_98 = 0.0;
          }
          else {
            fVar12 = (float10)FUN_005c0240(fVar3);
            local_98 = (float)((float10)1 / fVar12);
          }
          psVar7 = psVar7 + 0x32;
          *(float *)(param_2 + 0x24) = local_98 * *(float *)(param_2 + 0x24);
          *(float *)(param_2 + 0x26) = *(float *)(param_2 + 0x26) * local_98;
          *(float *)(param_2 + 0x28) = local_98 * *(float *)(param_2 + 0x28);
          param_2 = param_2 + 0x32;
        }
        sVar2 = *psVar7;
      }
      *param_2 = -1;
      param_2[1] = -1;
      iVar10 = (int)psVar7 + (4 - (int)pfVar1[3]);
    }
    else {
      iVar10 = 0;
    }
    *pfVar1 = *(float *)(*param_3 + 0x30);
    pfVar1[1] = *(float *)(*param_3 + 0x34);
    pfVar1[2] = *(float *)(*param_3 + 0x38);
    pfVar1[4] = *pfVar1 + (local_7c - 0.1);
    pfVar1[5] = (local_78 - 0.1) + pfVar1[1];
    pfVar1[6] = (local_74 - 0.1) + pfVar1[2];
    pfVar1[7] = local_90 + 0.1 + *pfVar1;
    pfVar1[8] = local_8c + 0.1 + pfVar1[1];
    pfVar1[9] = local_88 + 0.1 + pfVar1[2];
    fVar12 = (float10)FUN_005c0240(local_70);
    pfVar1[0xd] = (float)fVar12;
    if (DAT_0292fc08 < iVar10) {
      DAT_0292fc08 = iVar10;
    }
  }
  return;
}

