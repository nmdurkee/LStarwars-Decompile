/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64daa0; label: FUN_0064daa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064daa0(float param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  float **ppfVar15;
  int *piVar16;
  float10 fVar17;
  float local_254;
  uint local_250;
  int local_24c;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  float local_234;
  float local_230;
  float local_22c;
  undefined4 local_228;
  int local_224;
  float *local_220 [7];
  undefined4 local_204;
  undefined4 local_200;
  undefined1 *local_1fc;
  int local_1f8;
  uint local_1f4;
  int local_1c8;
  int local_1c0;
  int local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  float local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  int local_164;
  undefined4 local_160;
  undefined1 local_154 [12];
  float local_148 [12];
  float local_118;
  float local_114;
  float local_110;
  int iStack_108;
  int aiStack_104 [64];
  
  local_250 = 0xffffffff;
  local_24c = 0;
  do {
    iVar9 = local_24c * 0x6c;
    if ((*(int *)(&DAT_02913a2c + (char)(&DAT_0291f7da)[iVar9] * 4) == 0) ||
       (iVar3 = (&DAT_0291f7b4)[local_24c * 0x1b], iVar3 == -1)) goto LAB_0064e4f0;
    iVar12 = iVar3 * 0x178;
    if ((&DAT_02913ae8)[iVar3 * 0xbc] == -1) goto LAB_0064e4f0;
    fVar5 = 1.0 / (float)(&DAT_02913b24)[iVar3 * 0x5e];
    if (((&DAT_0291f7ec)[local_24c * 0x36] != 1) || ((&DAT_0291f7e5)[iVar9] == '\x02'))
    goto LAB_0064dc02;
    sVar7 = (&DAT_0291f7ee)[local_24c * 0x36];
    if (sVar7 == -1) goto switchD_0064db5e_default;
    switch((&DAT_0292fb70)[sVar7]) {
    case 0:
      (&DAT_0291f7e5)[iVar9] = 0;
      break;
    case 1:
      (&DAT_0291f7e5)[iVar9] = 1;
      break;
    case 2:
      local_250 = local_250 + 1 & 0x1f;
      (&DAT_0291f7e5)[iVar9] = 2;
      aiStack_104[local_250 * 2] = 4;
      goto LAB_0064dbae;
    case 3:
      (&DAT_0291f7e5)[iVar9] = 2;
      goto LAB_0064dba0;
    case 4:
LAB_0064dba0:
      local_250 = local_250 + 1 & 0x1f;
      aiStack_104[local_250 * 2] = 0;
LAB_0064dbae:
      aiStack_104[local_250 * 2 + -1] = (int)sVar7;
    }
switchD_0064db5e_default:
    if ((&DAT_0291f7e5)[iVar9] == '\x02') {
      FUN_0064ae50(local_24c,0);
      fVar6 = _DAT_02920a90;
      fVar1 = (float)(&DAT_0291f7cc)[local_24c * 0x1b] - _DAT_02920a90;
      (&DAT_0291f7cc)[local_24c * 0x1b] = (float)(&DAT_0291f7cc)[local_24c * 0x1b] - fVar1;
      (&DAT_0291f7d0)[local_24c * 0x1b] = (float)(&DAT_0291f7d0)[local_24c * 0x1b] - fVar1;
      (&DAT_0291f7c8)[local_24c * 0x1b] = fVar6 - fVar5;
    }
LAB_0064dc02:
    fVar1 = (float)(&DAT_0291f7e8)[local_24c * 0x1b];
    fVar17 = (float10)FUN_006585a0(&DAT_0291f7a8 + local_24c * 0x1b);
    (&DAT_0291f7e8)[local_24c * 0x1b] = (float)fVar17;
    if ((&DAT_0291f7e4)[iVar9] != '\0') {
      iVar13 = 0;
      piVar16 = &DAT_02913ba0 + iVar3 * 0x5e;
      do {
        if ((*piVar16 != -1) &&
           (FUN_00650570(*piVar16), (&DAT_02913a58)[iVar13 + 0x158 + iVar12] == '\x04')) {
          FUN_00681e90(*piVar16,&DAT_0291f7a8 + local_24c * 0x1b);
        }
        iVar13 = iVar13 + 1;
        piVar16 = piVar16 + 1;
      } while (iVar13 < 4);
    }
    fVar6 = _DAT_02920a90;
    local_224 = 0;
    if (((&DAT_02913b6c)[iVar3 * 0x5e] & 0x400000) != 0) {
      if (((float)(&DAT_02913bb4)[iVar3 * 0x5e] <= (float)(&DAT_0291f7e8)[local_24c * 0x1b]) ||
         ((float)(&DAT_02913bb4)[iVar3 * 0x5e] < fVar1 ==
          ((float)(&DAT_02913bb4)[iVar3 * 0x5e] == fVar1))) {
        if ((float)(&DAT_0291f7d0)[local_24c * 0x1b] < (float)(&DAT_0291f7cc)[local_24c * 0x1b]) {
          (&DAT_0291f7d0)[local_24c * 0x1b] = param_1 + (float)(&DAT_0291f7d0)[local_24c * 0x1b];
          (&DAT_0291f7cc)[local_24c * 0x1b] = (float)(&DAT_0291f7cc)[local_24c * 0x1b] + param_1;
          (&DAT_0291f7c8)[local_24c * 0x1b] = (float)(&DAT_0291f7c8)[local_24c * 0x1b] + param_1;
        }
      }
      else {
        (&DAT_0291f7c8)[local_24c * 0x1b] = (_DAT_02920a90 - fVar5) + 0.001;
        (&DAT_0291f7cc)[local_24c * 0x1b] = fVar6;
        (&DAT_0291f7d0)[local_24c * 0x1b] = (float)(&DAT_0291f7cc)[local_24c * 0x1b] - 1.0;
      }
    }
    local_254 = (float)(&DAT_0291f7c8)[local_24c * 0x1b] + fVar5;
    fVar1 = local_254;
    if (local_254 < fVar6 + param_1) {
      do {
        iVar13 = local_224 + 1;
        bVar4 = 99 < local_224;
        local_224 = iVar13;
        if (bVar4) break;
        if ((float)(&DAT_0291f7d0)[local_24c * 0x1b] < fVar1 !=
            ((float)(&DAT_0291f7d0)[local_24c * 0x1b] == fVar1)) {
          do {
            if ((fVar1 <= (float)(&DAT_0291f7cc)[local_24c * 0x1b]) || (fVar6 + param_1 <= fVar1))
            break;
            if ((float)(&DAT_0291f7d0)[local_24c * 0x1b] < (float)(&DAT_0291f7cc)[local_24c * 0x1b]
                == ((float)(&DAT_0291f7d0)[local_24c * 0x1b] ==
                   (float)(&DAT_0291f7cc)[local_24c * 0x1b])) {
              fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
              cVar2 = (&DAT_0291f7e5)[iVar9];
              local_254 = (float)(&DAT_0291f7d0)[local_24c * 0x1b] +
                          (float)(fVar17 * (float10)(float)(&DAT_02913b50)[iVar3 * 0x5e] +
                                 (float10)(float)(&DAT_02913b4c)[iVar3 * 0x5e]);
              (&DAT_0291f7cc)[local_24c * 0x1b] = local_254;
              local_254 = local_254 + 0.001;
              (&DAT_0291f7c8)[local_24c * 0x1b] = (local_254 - fVar5) + 0.001;
              if (cVar2 == '\x02') {
                (&DAT_0291f7e5)[iVar9] = 0;
              }
              if (((&DAT_0291f7e4)[iVar9] != '\0') && ((&DAT_0291f7e5)[iVar9] != '\0')) {
                iVar13 = 0;
                piVar16 = &DAT_02913ba0 + iVar3 * 0x5e;
                do {
                  if ((*piVar16 != -1) && ((&DAT_02913a58)[iVar13 + 0x158 + iVar12] == '\x02')) {
                    FUN_00681e90(*piVar16,&DAT_0291f7a8 + local_24c * 0x1b);
                  }
                  iVar13 = iVar13 + 1;
                  piVar16 = piVar16 + 1;
                } while (iVar13 < 4);
              }
            }
            else {
              fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
              cVar2 = (&DAT_0291f7e4)[iVar9];
              (&DAT_0291f7d0)[local_24c * 0x1b] =
                   (float)((float10)(float)(&DAT_02913b44)[iVar3 * 0x5e] +
                           (float10)(float)(&DAT_0291f7cc)[local_24c * 0x1b] +
                          fVar17 * (float10)(float)(&DAT_02913b48)[iVar3 * 0x5e]);
              if ((cVar2 != '\0') && ((&DAT_0291f7e5)[iVar9] != '\0')) {
                iVar13 = 0;
                piVar16 = &DAT_02913ba0 + iVar3 * 0x5e;
                do {
                  if ((*piVar16 != -1) && ((&DAT_02913a58)[iVar13 + 0x158 + iVar12] == '\x01')) {
                    FUN_00681e90(*piVar16,&DAT_0291f7a8 + local_24c * 0x1b);
                  }
                  iVar13 = iVar13 + 1;
                  piVar16 = piVar16 + 1;
                } while (iVar13 < 4);
              }
              if (((&DAT_0291f7dc)[local_24c * 0x1b] != 0) &&
                 (iVar13 = (&DAT_0291f7dc)[local_24c * 0x1b] + -1,
                 (&DAT_0291f7dc)[local_24c * 0x1b] = iVar13, iVar13 == 0)) {
                if ((local_24c != -1) && ((&DAT_0291f7b4)[local_24c * 0x1b] != -1)) {
                  DAT_02920a98 = DAT_02920a98 + -1;
                  (&DAT_0291f7b4)[local_24c * 0x1b] = 0xffffffff;
                }
                local_254 = _DAT_02920a90 + 99999.9;
              }
            }
            fVar6 = _DAT_02920a90;
            fVar1 = local_254;
          } while ((float)(&DAT_0291f7d0)[local_24c * 0x1b] < local_254 !=
                   ((float)(&DAT_0291f7d0)[local_24c * 0x1b] == local_254));
        }
        if (fVar1 < fVar6 + param_1) {
          if (((&DAT_0291f7e5)[iVar9] != '\0') &&
             (((float)(&DAT_02913bb4)[iVar3 * 0x5e] == 0.0 ||
              ((float)(&DAT_0291f7e8)[local_24c * 0x1b] < (float)(&DAT_02913bb4)[iVar3 * 0x5e])))) {
            uVar11 = (&DAT_02913b0c)[iVar3 * 0x5e];
            puVar14 = &DAT_00810210;
            ppfVar15 = local_220;
            for (iVar13 = 0x32; iVar13 != 0; iVar13 = iVar13 + -1) {
              *ppfVar15 = (float *)*puVar14;
              puVar14 = puVar14 + 1;
              ppfVar15 = ppfVar15 + 1;
            }
            local_160 = uVar11;
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_238 = (float)((fVar17 + fVar17) * (float10)*(float *)(&DAT_02913b2c + iVar12) -
                               (float10)*(float *)(&DAT_02913b2c + iVar12));
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_234 = (float)((fVar17 + fVar17) * (float10)*(float *)(&DAT_02913b30 + iVar12) -
                               (float10)*(float *)(&DAT_02913b30 + iVar12));
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_230 = (float)((fVar17 + fVar17) * (float10)*(float *)(&DAT_02913b34 + iVar12) -
                               (float10)*(float *)(&DAT_02913b34 + iVar12));
            FUN_005b3690(&local_238,&local_238,(int)(short)(&DAT_0291f7d4)[local_24c * 0x36]);
            FUN_005b3620(&local_238,&local_238,(int)(short)(&DAT_0291f7d6)[local_24c * 0x36]);
            FUN_005b35a0(&local_238,&local_238,(int)(short)(&DAT_0291f7d8)[local_24c * 0x36]);
            FUN_005b37d0(&local_238,&local_238,&DAT_0291f7a8 + local_24c * 0x1b);
            local_220[1] = &local_238;
            local_23c = 0.0;
            local_244 = 0.0;
            local_240 = (float)(&DAT_02913b1c)[iVar3 * 0x5e];
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_244 = (float)(((fVar17 + fVar17) * (float10)*(float *)(&DAT_02913b38 + iVar12) -
                                (float10)*(float *)(&DAT_02913b38 + iVar12)) + (float10)local_244);
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_240 = (float)(((fVar17 + fVar17) * (float10)*(float *)(&DAT_02913b3c + iVar12) -
                                (float10)*(float *)(&DAT_02913b3c + iVar12)) + (float10)local_240);
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_23c = (float)(((fVar17 + fVar17) * (float10)*(float *)(&DAT_02913b40 + iVar12) -
                                (float10)*(float *)(&DAT_02913b40 + iVar12)) + (float10)local_23c);
            FUN_005b3690(&local_244,&local_244,(int)(short)(&DAT_0291f7d4)[local_24c * 0x36]);
            FUN_005b3620(&local_244,&local_244,(int)(short)(&DAT_0291f7d6)[local_24c * 0x36]);
            FUN_005b35a0(&local_244,&local_244,(int)(short)(&DAT_0291f7d8)[local_24c * 0x36]);
            cVar2 = (&DAT_02913b08)[iVar12];
            local_204 = (&DAT_02913b20)[iVar3 * 0x5e];
            local_200 = (&DAT_02913b28)[iVar3 * 0x5e];
            local_220[2] = &local_244;
            if (cVar2 == '\0') {
LAB_0064e185:
              iVar13 = 0;
            }
            else if ((&DAT_02913b09)[iVar12] == '\0') {
              FUN_005b9d90(&DAT_008102e8);
              iVar13 = FUN_006e6b90();
              iVar13 = iVar13 % (int)(char)(&DAT_02913b08)[iVar12];
            }
            else {
              if ((&DAT_02913b09)[iVar12] != '\x01') goto LAB_0064e185;
              (&DAT_0291f7db)[iVar9] = (&DAT_0291f7db)[iVar9] + '\x01';
              if (cVar2 <= (char)(&DAT_0291f7db)[iVar9]) {
                (&DAT_0291f7db)[iVar9] = 0;
              }
              iVar13 = (int)(char)(&DAT_0291f7db)[iVar9];
            }
            sVar7 = (&DAT_02913ae8)[iVar3 * 0xbc + iVar13];
            local_1f8 = (int)sVar7;
            if ((sVar7 == 9999) || (sVar7 == 0x270e)) {
              local_1fc = (undefined1 *)0x0;
            }
            else if (sVar7 != -1) {
              local_1fc = local_154;
              FUN_005da860(local_1fc,(&DAT_029208d0)[(char)(&DAT_02913a58)[iVar13 + 0xa8 + iVar12]],
                           local_1f8);
            }
            fVar17 = (float10)FUN_005b9d90(&DAT_008102e8);
            local_17c = (float)(fVar17 * (float10)(float)(&DAT_02913b18)[iVar3 * 0x5e] +
                               (float10)(float)(&DAT_02913b14)[iVar3 * 0x5e]);
            FUN_005b44e0(local_148);
            FUN_005b9d90(&DAT_008102e8);
            sVar7 = FUN_006e6b90();
            FUN_005b9d90(&DAT_008102e8);
            sVar8 = FUN_006e6b90();
            iVar13 = (&DAT_02913b68)[iVar3 * 0x5e];
            local_22c = (float)iVar13;
            local_228 = (&DAT_02913b5c)[iVar3 * 0x5e];
            FUN_005b9d90(&DAT_008102e8);
            uVar10 = FUN_006e6b90();
            local_178 = (&DAT_02913b54)[iVar3 * 0x5e];
            local_22c = (float)(uVar10 & 0xffff);
            local_174 = (&DAT_02913b58)[iVar3 * 0x5e];
            local_16c = (&DAT_02913b60)[iVar3 * 0x5e];
            local_168 = (&DAT_02913b64)[iVar3 * 0x5e];
            local_170 = local_228;
            local_164 = iVar13;
            FUN_005b4cf0(local_148,(int)sVar7);
            FUN_005b4f70(local_148,(int)sVar8);
            FUN_005b5160(local_148,(int)local_22c._0_2_);
            local_118 = local_238;
            local_114 = local_234;
            local_1f4 = (&DAT_02913b6c)[iVar3 * 0x5e] & 0xfff9ffff;
            local_220[0] = local_148;
            local_110 = local_230;
            if ((&DAT_02913b70)[iVar3 * 0x5e] != -1) {
              local_1f4 = local_1f4 | 0x40000;
              local_1c0 = (&DAT_02913b70)[iVar3 * 0x5e];
            }
            if ((&DAT_02913b74)[iVar3 * 0x5e] != -1) {
              local_1f4 = local_1f4 | 0x40000;
              local_1bc = (&DAT_02913b74)[iVar3 * 0x5e];
            }
            if ((&DAT_02913b80)[iVar3 * 0x5e] != -1) {
              local_1f4 = local_1f4 | 0x20000;
              local_1c8 = (&DAT_02913b80)[iVar3 * 0x5e];
            }
            local_1b8 = (&DAT_02913b78)[iVar3 * 0x5e];
            local_1b0 = (&DAT_02913b84)[iVar3 * 0x5e];
            local_1b4 = (&DAT_02913b7c)[iVar3 * 0x5e];
            if (((&DAT_02913b88)[iVar3 * 0x5e] == -1) && ((&DAT_02913b8c)[iVar12] != '\0')) {
              uVar11 = FUN_0064afd0(&DAT_02913b8c + iVar12);
              (&DAT_02913b88)[iVar3 * 0x5e] = uVar11;
            }
            local_1a4 = (&DAT_02913b10)[iVar3 * 0x5e];
            local_1ac = (&DAT_02913b88)[iVar3 * 0x5e];
            local_1a8 = (&DAT_02913b9c)[iVar3 * 0x5e];
            local_188 = (&DAT_02913bb8)[iVar3 * 0x5e];
            local_184 = (&DAT_02913bbc)[iVar3 * 0x5e];
            local_180 = (&DAT_02913bc0)[iVar3 * 0x5e];
            FUN_0064d270(local_220);
            if ((&DAT_0291f7e4)[iVar9] != '\0') {
              iVar13 = 0;
              piVar16 = &DAT_02913ba0 + iVar3 * 0x5e;
              do {
                if ((*piVar16 != -1) && ((&DAT_02913a58)[iVar13 + 0x158 + iVar12] == '\x03')) {
                  FUN_00681e90(*piVar16,&DAT_0291f7a8 + local_24c * 0x1b);
                }
                iVar13 = iVar13 + 1;
                piVar16 = piVar16 + 1;
              } while (iVar13 < 4);
            }
            (&DAT_02913bc4)[iVar3 * 0x5e] = local_254;
            fVar1 = local_254;
          }
          (&DAT_0291f7c8)[local_24c * 0x1b] = fVar1;
          local_254 = fVar1 + fVar5;
          fVar1 = local_254;
          fVar6 = _DAT_02920a90;
        }
      } while (fVar1 < fVar6 + param_1);
    }
LAB_0064e4f0:
    local_24c = local_24c + 1;
    if (0x27 < local_24c) {
      iVar9 = 0;
      if (-1 < (int)local_250) {
        do {
          iVar3 = iVar9 * 2;
          iVar12 = iVar9 * 2;
          iVar9 = iVar9 + 1;
          (&DAT_0292fb70)[aiStack_104[iVar3 + -1]] = (char)aiStack_104[iVar12];
        } while (iVar9 <= (int)local_250);
      }
      return;
    }
  } while( true );
}

