/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66f170; label: FUN_0066f170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066f170(int param_1,float *param_2,int *param_3)

{
  short *psVar1;
  short sVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float10 fVar12;
  int local_ac;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined1 local_c [12];
  
  if ((DAT_0292fc68 != 0) && ((*(int *)(param_1 + 0x2c) == 0 || (*(int *)(param_1 + 0x2c) == 1)))) {
    pfVar10 = *(float **)(param_1 + 0xc);
    sVar2 = *(short *)pfVar10;
    pfVar5 = param_2;
    while (-1 < sVar2) {
      *(short *)pfVar5 = *(short *)pfVar10;
      local_6c = 1.2345679e+08;
      local_70 = 1.2345679e+08;
      local_74 = 1.2345679e+08;
      *(short *)((int)pfVar5 + 2) = *(short *)((int)pfVar10 + 2);
      local_78 = -1.2345679e+08;
      psVar1 = (short *)((int)pfVar10 + 2);
      local_7c = -1.2345679e+08;
      local_80 = -1.2345679e+08;
      pfVar10 = pfVar10 + 5;
      pfVar4 = pfVar5 + 5;
      for (iVar8 = (int)*psVar1; 0 < iVar8; iVar8 = iVar8 + -1) {
        if (pfVar10[0x16] <= 65535.0) {
          local_ac = 3;
          iVar6 = 3;
        }
        else {
          iVar6 = 2;
          local_ac = 2;
        }
        local_94 = 1.2345679e+08;
        local_98 = 1.2345679e+08;
        local_9c = 1.2345679e+08;
        pfVar11 = pfVar10;
        pfVar7 = pfVar4;
        for (iVar9 = 0x19; iVar9 != 0; iVar9 = iVar9 + -1) {
          *pfVar7 = *pfVar11;
          pfVar11 = pfVar11 + 1;
          pfVar7 = pfVar7 + 1;
        }
        local_88 = -1.2345679e+08;
        local_8c = -1.2345679e+08;
        local_90 = -1.2345679e+08;
        pfVar11 = pfVar4 + iVar6 * 3 + 6;
        do {
          pfVar7 = (float *)FUN_0066ed90(local_c,param_3,
                                         pfVar10 + (*(int *)(&DAT_00810b38 +
                                                            (iVar6 + *(short *)((int)param_3 + 0x1a)
                                                                     * 4) * 4) + 2) * 3,0xbf800000,
                                         (int)(short)param_3[6]);
          *pfVar11 = *pfVar7;
          pfVar11[1] = pfVar7[1];
          pfVar11[2] = pfVar7[2];
          *pfVar11 = *pfVar11 - *(float *)(*param_3 + 0x30);
          pfVar11[1] = pfVar11[1] - *(float *)(*param_3 + 0x34);
          fVar3 = pfVar11[2] - *(float *)(*param_3 + 0x38);
          pfVar11[2] = fVar3;
          if (*pfVar11 < local_74) {
            local_74 = *pfVar11;
          }
          if (local_80 < *pfVar11) {
            local_80 = *pfVar11;
          }
          if (pfVar11[1] < local_70) {
            local_70 = pfVar11[1];
          }
          if (local_7c < pfVar11[1]) {
            local_7c = pfVar11[1];
          }
          if (fVar3 < local_6c) {
            local_6c = fVar3;
          }
          if (local_78 < fVar3) {
            local_78 = fVar3;
          }
          if (*pfVar11 < local_9c) {
            local_9c = *pfVar11;
          }
          if (local_90 < *pfVar11) {
            local_90 = *pfVar11;
          }
          if (pfVar11[1] < local_98) {
            local_98 = pfVar11[1];
          }
          if (local_8c < pfVar11[1]) {
            local_8c = pfVar11[1];
          }
          if (fVar3 < local_94) {
            local_94 = fVar3;
          }
          if (local_88 < fVar3) {
            local_88 = fVar3;
          }
          iVar6 = local_ac + -1;
          pfVar11 = pfVar11 + -3;
          local_ac = iVar6;
        } while (-1 < iVar6);
        *pfVar4 = local_9c - 0.05;
        pfVar4[2] = local_98 - 0.05;
        pfVar4[4] = local_94 - 0.05;
        pfVar4[1] = local_90 + 0.05;
        pfVar4[3] = local_8c + 0.05;
        pfVar4[5] = local_88 + 0.05;
        if (pfVar10[0x16] < 65535.0) {
          pfVar4[0x15] = (pfVar4[10] - pfVar4[0x10]) * (pfVar4[0xe] - pfVar4[0x11]) -
                         (pfVar4[0xb] - pfVar4[0x11]) * (pfVar4[0xd] - pfVar4[0x10]);
          pfVar4[0x16] = (pfVar4[0xc] - pfVar4[0xf]) * (pfVar4[0xb] - pfVar4[0x11]) -
                         (pfVar4[9] - pfVar4[0xf]) * (pfVar4[0xe] - pfVar4[0x11]);
          pfVar4[0x17] = (pfVar4[0xd] - pfVar4[0x10]) * (pfVar4[9] - pfVar4[0xf]) -
                         (pfVar4[10] - pfVar4[0x10]) * (pfVar4[0xc] - pfVar4[0xf]);
          fVar12 = (float10)FUN_005c0240(pfVar4[0x17] * pfVar4[0x17] +
                                         pfVar4[0x15] * pfVar4[0x15] + pfVar4[0x16] * pfVar4[0x16]);
          if ((float)fVar12 == 0.0) {
            fVar3 = 0.0;
          }
          else {
            fVar3 = 1.0 / (float)fVar12;
          }
          pfVar4[0x15] = fVar3 * pfVar4[0x15];
          pfVar4[0x16] = pfVar4[0x16] * fVar3;
          pfVar4[0x17] = fVar3 * pfVar4[0x17];
        }
        pfVar4[0x12] = (pfVar4[0xd] - pfVar4[7]) * (pfVar4[0xb] - pfVar4[8]) -
                       (pfVar4[0xe] - pfVar4[8]) * (pfVar4[10] - pfVar4[7]);
        pfVar4[0x13] = (pfVar4[9] - pfVar4[6]) * (pfVar4[0xe] - pfVar4[8]) -
                       (pfVar4[0xc] - pfVar4[6]) * (pfVar4[0xb] - pfVar4[8]);
        pfVar4[0x14] = (pfVar4[10] - pfVar4[7]) * (pfVar4[0xc] - pfVar4[6]) -
                       (pfVar4[0xd] - pfVar4[7]) * (pfVar4[9] - pfVar4[6]);
        fVar12 = (float10)FUN_005c0240(pfVar4[0x14] * pfVar4[0x14] +
                                       pfVar4[0x12] * pfVar4[0x12] + pfVar4[0x13] * pfVar4[0x13]);
        if ((float)fVar12 == 0.0) {
          fVar3 = 0.0;
        }
        else {
          fVar3 = 1.0 / (float)fVar12;
        }
        pfVar10 = pfVar10 + 0x19;
        pfVar4[0x12] = fVar3 * pfVar4[0x12];
        pfVar4[0x13] = pfVar4[0x13] * fVar3;
        pfVar4[0x14] = fVar3 * pfVar4[0x14];
        pfVar4 = pfVar4 + 0x19;
      }
      pfVar5[1] = local_74 - 0.05;
      pfVar5[2] = local_80 + 0.05;
      pfVar5[3] = local_6c - 0.05;
      pfVar5[4] = local_78 + 0.05;
      pfVar5 = pfVar4;
      sVar2 = *(short *)pfVar10;
    }
    *(short *)pfVar5 = -1;
    *(short *)((int)pfVar5 + 2) = -1;
    *(float **)(param_1 + 0xc) = param_2;
  }
  return;
}

