/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5f14e0; label: FUN_005f14e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f14e0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  bool bVar2;
  float fVar3;
  byte bVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  float10 fVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_12c;
  undefined1 local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  int local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  undefined4 local_c8 [12];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  float local_88;
  float local_84;
  undefined4 local_50 [19];
  
  local_f4 = param_1 + -1;
  local_f0 = 1.0 / (float)(param_2 + -1);
  puVar11 = &DAT_0080e228;
  puVar12 = local_50;
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  local_e8 = 1.0 / (float)local_f4;
  local_100 = local_e8 * 0.0 * 2.0 - 1.0;
  local_124 = local_f0 * 0.0 * 2.0 - 1.0;
  local_d8 = local_e8 * 2.0;
  local_fc = local_d8 - 1.0;
  local_cc = local_f0 * 2.0;
  local_108 = *(float *)(param_5 + 8) * 128.0;
  local_e4 = *(float *)(param_5 + 0x10) * 128.0;
  local_ec = *(float *)(param_5 + 4) / 180.0;
  local_f8 = *(float *)(param_5 + 0xc) / 180.0;
  local_e0 = local_e4 - local_108;
  local_104 = local_f8 - local_ec;
  local_d0 = local_124;
  FUN_005db310();
  iVar8 = *(int *)(param_5 + 0x18);
  puVar11 = &DAT_009736e8;
  puVar12 = local_c8;
  for (iVar9 = 0x1e; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  if (iVar8 != 0) {
    FUN_005e1070();
  }
  if (*(int *)(param_5 + 0x28) != 0) {
    FUN_005b3b30(param_5 + 0x2c,param_5 + 0x2c);
  }
  if (param_4 != 0) {
    piVar1 = *(int **)(DAT_0097157c + -4 + *(short *)(param_3 + 0x74) * 4);
    _DAT_0097bae4 = 0.5 / (float)*piVar1;
    _DAT_0097bae0 = 0.5 / (float)piVar1[1];
  }
  fVar13 = (float10)local_88;
  if (DAT_0080c0e4 != 0) {
    _DAT_0097badc = local_88;
    FUN_006e6b90();
    iVar8 = FUN_006e6b90();
    DAT_0080c0e4 = 0;
    _DAT_0097bad8 =
         (float)((float10)1 /
                (extraout_ST0 / (float10)(float)(&DAT_029899a0)[0x4000 - iVar8 >> 1 & 0x7fff]));
    fVar13 = extraout_ST1;
  }
  if (fVar13 != (float10)_DAT_0097badc) {
    FUN_006e6b90();
    iVar8 = FUN_006e6b90();
    _DAT_0097bad8 =
         (float)((float10)1 /
                (extraout_ST0_00 / (float10)(float)(&DAT_029899a0)[0x4000 - iVar8 >> 1 & 0x7fff]));
    local_88 = (float)extraout_ST1_00;
  }
  DAT_02854d1c = DAT_02854d1c + 1;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0x3f800000;
  FUN_00600b20(1);
  DAT_0097bad4 = 0;
  if (0 < local_f4) {
    do {
      bVar2 = DAT_0097bad4 < 1;
      FUN_00607d70(0xd,7,param_3);
      DAT_0097bad0 = 0;
      if (0 < param_2) {
        local_dc = (local_100 + 1.0) - 1.0;
        local_d4 = (local_fc + 1.0) - 1.0;
        do {
          local_11c = -local_84 * ((local_124 + 1.0) - 1.0);
          local_120 = local_dc;
          local_118 = _DAT_0097bad8;
          local_10c = local_11c;
          FUN_005b3b30(&local_120,&local_120);
          local_114 = 0x3f800000;
          FUN_005b30a0(&local_120,&local_120,local_c8);
          FUN_005b3b30(&local_120,&local_120);
          local_114 = 0x3f800000;
          fVar3 = local_11c * 0.5 + 0.5;
          if (bVar2) {
            if (local_ec < fVar3) {
              if (local_f8 < fVar3 == (local_f8 == fVar3)) {
                local_12c = (((fVar3 - local_ec) * local_e0) / local_104 + local_108) *
                            *(float *)(param_5 + 0x14);
              }
              else {
                local_12c = *(float *)(param_5 + 0x14) * local_e4;
              }
            }
            else {
              local_12c = *(float *)(param_5 + 0x14) * local_108;
            }
            if (*(int *)(param_5 + 0x28) != 0) {
              fVar13 = (float10)FUN_005b39e0(param_5 + 0x2c,&local_120);
              sVar5 = FUN_005c13c0((float)fVar13);
              fVar13 = (float10)((float)(int)(short)(0x4000 - sVar5) * 0.005493164);
              if ((float10)*(float *)(param_5 + 0x38) <= fVar13) {
                if (fVar13 <= (float10)*(float *)(param_5 + 0x40)) {
                  if (*(float *)(param_5 + 0x48) == 1.0) {
                    fVar13 = (fVar13 - (float10)*(float *)(param_5 + 0x38)) /
                             ((float10)*(float *)(param_5 + 0x40) -
                             (float10)*(float *)(param_5 + 0x38));
                  }
                  else {
                    fVar13 = (float10)FUN_005bfe40((float)((fVar13 - (float10)*(float *)(param_5 +
                                                                                        0x38)) /
                                                          ((float10)*(float *)(param_5 + 0x40) -
                                                          (float10)*(float *)(param_5 + 0x38))),
                                                   *(undefined4 *)(param_5 + 0x48));
                  }
                  local_12c = (float)((((float10)*(float *)(param_5 + 0x3c) -
                                       (float10)*(float *)(param_5 + 0x44)) * ((float10)1 - fVar13)
                                      + (float10)*(float *)(param_5 + 0x44)) * (float10)128.0 +
                                     (float10)local_12c);
                }
              }
              else {
                local_12c = *(float *)(param_5 + 0x3c) * 128.0 + local_12c;
              }
            }
            bVar4 = FUN_005e0ff0(0,0xff,local_12c);
          }
          else {
            bVar4 = (&DAT_00966278)[DAT_0097bad0];
          }
          uVar6 = (uint)bVar4 << 0x18;
          uVar7 = uVar6 | 0x808080;
          if (DAT_02854c31 == '\0') {
            iVar8 = ((int)uVar7 >> 0x11 & 0x7fU) + 0x400000;
            uVar10 = (int)uVar7 >> 1 & 0x7f00;
            uVar7 = uVar6;
          }
          else {
            iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + 0x800000;
            uVar7 = 0x8000;
            uVar10 = uVar6;
          }
          fVar3 = (float)DAT_0097bad4;
          *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar10 + uVar7;
          iVar8 = *DAT_02854d10;
          *(float *)(iVar8 + 0x10) = fVar3 * local_e8 + _DAT_0097bae4;
          *(float *)(iVar8 + 0x14) = ((float)DAT_0097bad0 * local_f0 + _DAT_0097bae0) * 0.9;
          FUN_006009e0(local_100,local_124,0);
          local_120 = local_d4;
          local_11c = local_10c;
          local_118 = _DAT_0097bad8;
          FUN_005b3b30(&local_120,&local_120);
          local_114 = 0x3f800000;
          FUN_005b30a0(&local_120,&local_120,local_c8);
          FUN_005b3b30(&local_120,&local_120);
          local_114 = 0x3f800000;
          fVar3 = local_11c * 0.5 + 0.5;
          if (local_ec < fVar3) {
            if (local_f8 < fVar3 == (local_f8 == fVar3)) {
              local_12c = (((fVar3 - local_ec) * local_e0) / local_104 + local_108) *
                          *(float *)(param_5 + 0x14);
            }
            else {
              local_12c = *(float *)(param_5 + 0x14) * local_e4;
            }
          }
          else {
            local_12c = *(float *)(param_5 + 0x14) * local_108;
          }
          if (*(int *)(param_5 + 0x28) != 0) {
            fVar13 = (float10)FUN_005b39e0(param_5 + 0x2c,&local_120);
            sVar5 = FUN_005c13c0((float)fVar13);
            fVar13 = (float10)((float)(int)(short)(0x4000 - sVar5) * 0.005493164);
            if ((float10)*(float *)(param_5 + 0x38) <= fVar13) {
              if (fVar13 <= (float10)*(float *)(param_5 + 0x40)) {
                if (*(float *)(param_5 + 0x48) == 1.0) {
                  fVar13 = (fVar13 - (float10)*(float *)(param_5 + 0x38)) /
                           ((float10)*(float *)(param_5 + 0x40) -
                           (float10)*(float *)(param_5 + 0x38));
                }
                else {
                  fVar13 = (float10)FUN_005bfe40((float)((fVar13 - (float10)*(float *)(param_5 +
                                                                                      0x38)) /
                                                        ((float10)*(float *)(param_5 + 0x40) -
                                                        (float10)*(float *)(param_5 + 0x38))),
                                                 *(undefined4 *)(param_5 + 0x48));
                }
                local_12c = (float)((((float10)*(float *)(param_5 + 0x3c) -
                                     (float10)*(float *)(param_5 + 0x44)) * ((float10)1 - fVar13) +
                                    (float10)*(float *)(param_5 + 0x44)) * (float10)128.0 +
                                   (float10)local_12c);
              }
            }
            else {
              local_12c = *(float *)(param_5 + 0x3c) * 128.0 + local_12c;
            }
          }
          if (0.0 <= local_12c) {
            local_10c = local_12c;
          }
          else {
            local_10c = 0.0;
          }
          if (local_10c <= 255.0) {
            if (local_12c < 0.0) {
              local_12c = 0.0;
            }
          }
          else {
            local_12c = 255.0;
          }
          local_128 = (undefined1)(int)ROUND(local_12c);
          (&DAT_00966278)[DAT_0097bad0] = local_128;
          uVar6 = (int)ROUND(local_12c) << 0x18;
          uVar7 = uVar6 | 0x808080;
          if (DAT_02854c31 == '\0') {
            iVar8 = ((int)uVar7 >> 0x11 & 0x7fU) + 0x400000;
            uVar10 = (int)uVar7 >> 1 & 0x7f00;
            uVar7 = uVar6;
          }
          else {
            iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + 0x800000;
            uVar7 = 0x8000;
            uVar10 = uVar6;
          }
          *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar10 + uVar7;
          iVar8 = *DAT_02854d10;
          *(float *)(iVar8 + 0x10) = (float)(DAT_0097bad4 + 1) * local_e8 + _DAT_0097bae4;
          *(float *)(iVar8 + 0x14) = ((float)DAT_0097bad0 * local_f0 + _DAT_0097bae0) * 0.9;
          FUN_006009e0(local_fc,local_124,0);
          local_124 = local_cc + local_124;
          DAT_0097bad0 = DAT_0097bad0 + 1;
        } while (DAT_0097bad0 < param_2);
      }
      FUN_006009a0();
      local_124 = local_d0;
      DAT_0097bad4 = DAT_0097bad4 + 1;
      local_100 = local_d8 + local_100;
      local_fc = local_d8 + local_fc;
    } while (DAT_0097bad4 < local_f4);
  }
  iVar8 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar8));
  puVar11 = local_50;
  puVar12 = &DAT_0080e228;
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar12 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar12 = puVar12 + 1;
  }
  return;
}

