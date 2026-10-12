/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5e1170; label: FUN_005e1170
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e1170(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float fStack_a4;
  int local_a0;
  int local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  undefined4 local_88 [12];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  
  local_9c = param_2 + -1;
  local_a0 = param_1 + -1;
  puVar9 = &DAT_009736e8;
  puVar10 = local_88;
  for (iVar6 = 0x1e; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  local_cc = (1.0 / (float)local_a0) * 0.0 * 2.0 - 1.0;
  local_c4 = (1.0 / (float)local_9c) * 0.0 * 2.0 - 1.0;
  local_94 = (1.0 / (float)local_a0) * 2.0;
  local_c8 = local_94 - 1.0;
  local_8c = (1.0 / (float)local_9c) * 2.0;
  local_a8 = local_8c - 1.0;
  local_d0 = *(float *)(param_3 + 8) * 128.0;
  local_b8 = *(float *)(param_3 + 0x10) * 128.0;
  local_bc = *(float *)(param_3 + 4) / 180.0;
  local_b4 = *(float *)(param_3 + 0xc) / 180.0;
  local_ac = local_b4 - local_bc;
  local_b0 = local_b8 - local_d0;
  fVar11 = (float10)local_48;
  fVar12 = (float10)0.5;
  fVar13 = (float10)10430.3779296875;
  fVar14 = (float10)-10430.3779296875;
  local_98 = local_a8;
  local_90 = local_c4;
  if (DAT_0080c050 != 0) {
    _DAT_0097ade0 = local_48;
    local_c0 = (float)(fVar11 * fVar12);
    iVar6 = FUN_006e6b90();
    fVar1 = (float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff];
    fVar14 = fVar13;
    iVar6 = FUN_006e6b90();
    DAT_0080c050 = 0;
    _DAT_0097addc =
         (float)(fVar12 / ((float10)fVar1 /
                          (float10)(float)(&DAT_029899a0)[0x4000 - iVar6 >> 1 & 0x7fff]));
    fVar12 = fVar11;
    fVar11 = extraout_ST0;
  }
  if (fVar11 != (float10)_DAT_0097ade0) {
    local_c0 = (float)(fVar11 * fVar12);
    FUN_006e6b90();
    iVar6 = FUN_006e6b90();
    _DAT_0097addc =
         (float)(fVar14 / (extraout_ST0_00 /
                          (float10)(float)(&DAT_029899a0)[0x4000 - iVar6 >> 1 & 0x7fff]));
    local_48 = (float)extraout_ST1;
  }
  DAT_02854d1c = DAT_02854d1c + 1;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0x3f800000;
  FUN_00600b20(1);
  DAT_0097add8 = 0;
  if (0 < local_a0) {
    do {
      FUN_00607d70(0xe,5,0);
      iVar6 = local_9c;
      DAT_0097add4 = 0;
      if (0 < param_2) {
        do {
          local_e0 = local_cc;
          local_c0 = -local_c4;
          local_dc = local_c0 * local_44;
          local_d8 = _DAT_0097addc;
          FUN_005b3b30(&local_e0,&local_e0);
          local_d4 = 0x3f800000;
          FUN_005b30a0(&local_e0,&local_e0,local_88);
          FUN_005b3b30(&local_e0,&local_e0);
          local_d4 = 0x3f800000;
          fVar1 = local_dc * 0.5 + 0.5;
          if (local_bc < fVar1) {
            if (local_b4 < fVar1 == (local_b4 == fVar1)) {
              local_f0 = (((fVar1 - local_bc) * local_b0) / local_ac + local_d0) *
                         *(float *)(param_3 + 0x14);
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_b8;
            }
          }
          else {
            local_f0 = *(float *)(param_3 + 0x14) * local_d0;
          }
          if (*(int *)(param_3 + 0x28) != 0) {
            fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
            sVar3 = FUN_005c13c0((float)fVar12);
            fVar1 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
            if (*(float *)(param_3 + 0x38) <= fVar1) {
              if (fVar1 <= *(float *)(param_3 + 0x40)) {
                fVar12 = (float10)FUN_005bfe40((fVar1 - *(float *)(param_3 + 0x38)) /
                                               (*(float *)(param_3 + 0x40) -
                                               *(float *)(param_3 + 0x38)),
                                               *(undefined4 *)(param_3 + 0x48));
                local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                    (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                   (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                  (float10)local_f0);
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
            }
          }
          local_ec = local_f0;
          if (0.0 <= local_f0) {
            local_e8 = local_f0;
          }
          else {
            local_e8 = 0.0;
          }
          if (local_e8 <= 255.0) {
            if (local_f0 < 0.0) {
              local_f0 = 0.0;
            }
          }
          else {
            local_f0 = 255.0;
          }
          local_e8 = local_ec;
          if (local_ec < 0.0) {
            local_e8 = 0.0;
          }
          if (local_e8 <= 255.0) {
            if (0.0 <= local_ec) {
              fStack_a4 = local_ec;
            }
            else {
              fStack_a4 = 0.0;
            }
          }
          else {
            fStack_a4 = 255.0;
          }
          local_e8 = local_ec;
          if (local_ec < 0.0) {
            local_e8 = 0.0;
          }
          if (local_e8 <= 255.0) {
            if (local_ec < 0.0) {
              local_ec = 0.0;
            }
          }
          else {
            local_ec = 255.0;
          }
          uVar4 = (int)ROUND(fStack_a4) & 0xff;
          uVar5 = (int)ROUND(local_ec) & 0xff;
          uVar7 = (((int)ROUND(local_f0) & 0xffU | 0xffff8000) << 8 | uVar4) << 8 | uVar5;
          if (DAT_02854c31 == '\0') {
            iVar8 = ((int)ROUND(local_ec) & 0xfeU) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
            uVar5 = (int)uVar7 >> 1 & 0x7f00;
            uVar4 = 0x800000;
          }
          else {
            iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar5 * 0x10000;
            uVar5 = 0x80000000;
          }
          *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
          FUN_006009e0(local_cc,local_c4,0);
          local_e0 = local_c8;
          local_dc = local_c0 * local_44;
          local_d8 = _DAT_0097addc;
          FUN_005b3b30(&local_e0,&local_e0);
          local_d4 = 0x3f800000;
          FUN_005b30a0(&local_e0,&local_e0,local_88);
          FUN_005b3b30(&local_e0,&local_e0);
          local_d4 = 0x3f800000;
          fVar1 = local_dc * 0.5 + 0.5;
          if (local_bc < fVar1) {
            if (local_b4 < fVar1 == (local_b4 == fVar1)) {
              local_f0 = (((fVar1 - local_bc) * local_b0) / local_ac + local_d0) *
                         *(float *)(param_3 + 0x14);
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_b8;
            }
          }
          else {
            local_f0 = *(float *)(param_3 + 0x14) * local_d0;
          }
          if (*(int *)(param_3 + 0x28) != 0) {
            fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
            sVar3 = FUN_005c13c0((float)fVar12);
            fVar1 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
            if (*(float *)(param_3 + 0x38) <= fVar1) {
              if (fVar1 <= *(float *)(param_3 + 0x40)) {
                fVar12 = (float10)FUN_005bfe40((fVar1 - *(float *)(param_3 + 0x38)) /
                                               (*(float *)(param_3 + 0x40) -
                                               *(float *)(param_3 + 0x38)),
                                               *(undefined4 *)(param_3 + 0x48));
                local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                    (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                   (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                  (float10)local_f0);
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
            }
          }
          if (0.0 <= local_f0) {
            local_e8 = local_f0;
          }
          else {
            local_e8 = 0.0;
          }
          if (local_e8 <= 255.0) {
            if (0.0 <= local_f0) {
              local_ec = local_f0;
            }
            else {
              local_ec = 0.0;
            }
          }
          else {
            local_ec = 255.0;
          }
          local_e8 = local_f0;
          if (local_f0 < 0.0) {
            local_e8 = 0.0;
          }
          if (local_e8 <= 255.0) {
            if (0.0 <= local_f0) {
              fStack_a4 = local_f0;
            }
            else {
              fStack_a4 = 0.0;
            }
          }
          else {
            fStack_a4 = 255.0;
          }
          local_e8 = local_f0;
          if (local_f0 < 0.0) {
            local_e8 = 0.0;
          }
          if (local_e8 <= 255.0) {
            local_e8 = local_f0;
            if (local_f0 < 0.0) {
              local_e8 = 0.0;
            }
          }
          else {
            local_e8 = 255.0;
          }
          uVar4 = (int)ROUND(fStack_a4) & 0xff;
          uVar5 = (int)ROUND(local_e8) & 0xff;
          uVar7 = (((int)ROUND(local_ec) & 0xffU | 0xffff8000) << 8 | uVar4) << 8 | uVar5;
          if (DAT_02854c31 == '\0') {
            iVar8 = ((int)ROUND(local_e8) & 0xfeU) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
            uVar5 = (int)uVar7 >> 1 & 0x7f00;
            uVar4 = 0x800000;
          }
          else {
            iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar5 * 0x10000;
            uVar5 = 0x80000000;
          }
          *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
          FUN_006009e0(local_c8,local_c4,0);
          if (DAT_0097add4 != iVar6) {
            local_e0 = local_cc;
            local_dc = local_c0 * local_44;
            local_d8 = _DAT_0097addc;
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            FUN_005b30a0(&local_e0,&local_e0,local_88);
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            fVar1 = local_dc * 0.5 + 0.5;
            if (local_bc < fVar1) {
              if (local_b4 < fVar1 == (local_b4 == fVar1)) {
                local_f0 = (((fVar1 - local_bc) * local_b0) / local_ac + local_d0) *
                           *(float *)(param_3 + 0x14);
              }
              else {
                local_f0 = *(float *)(param_3 + 0x14) * local_b8;
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_d0;
            }
            if (*(int *)(param_3 + 0x28) != 0) {
              fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
              sVar3 = FUN_005c13c0((float)fVar12);
              fVar1 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
              if (*(float *)(param_3 + 0x38) <= fVar1) {
                if (fVar1 <= *(float *)(param_3 + 0x40)) {
                  fVar12 = (float10)FUN_005bfe40((fVar1 - *(float *)(param_3 + 0x38)) /
                                                 (*(float *)(param_3 + 0x40) -
                                                 *(float *)(param_3 + 0x38)),
                                                 *(undefined4 *)(param_3 + 0x48));
                  local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                      (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                     (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                    (float10)local_f0);
                }
              }
              else {
                local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
              }
            }
            uVar5 = FUN_005e0ff0(0,0xff,local_f0);
            uVar4 = uVar5 & 0xff;
            uVar7 = ((uVar4 | 0xffff8000) << 8 | uVar4) << 8 | uVar4;
            if (DAT_02854c31 == '\0') {
              iVar8 = (uVar5 & 0xfe) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
              uVar5 = (int)uVar7 >> 1 & 0x7f00;
              uVar4 = 0x800000;
            }
            else {
              iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar4 * 0x10000;
              uVar5 = 0x80000000;
            }
            *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
            FUN_006009e0(local_cc,local_c4,0);
            local_e0 = local_cc;
            fVar1 = -local_a8;
            local_dc = fVar1 * local_44;
            local_d8 = _DAT_0097addc;
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            FUN_005b30a0(&local_e0,&local_e0,local_88);
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            fVar2 = local_dc * 0.5 + 0.5;
            if (local_bc < fVar2) {
              if (local_b4 < fVar2 == (local_b4 == fVar2)) {
                local_f0 = (((fVar2 - local_bc) * local_b0) / local_ac + local_d0) *
                           *(float *)(param_3 + 0x14);
              }
              else {
                local_f0 = *(float *)(param_3 + 0x14) * local_b8;
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_d0;
            }
            if (*(int *)(param_3 + 0x28) != 0) {
              fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
              sVar3 = FUN_005c13c0((float)fVar12);
              fVar2 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
              if (*(float *)(param_3 + 0x38) <= fVar2) {
                if (fVar2 <= *(float *)(param_3 + 0x40)) {
                  fVar12 = (float10)FUN_005bfe40((fVar2 - *(float *)(param_3 + 0x38)) /
                                                 (*(float *)(param_3 + 0x40) -
                                                 *(float *)(param_3 + 0x38)),
                                                 *(undefined4 *)(param_3 + 0x48));
                  local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                      (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                     (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                    (float10)local_f0);
                }
              }
              else {
                local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
              }
            }
            uVar5 = FUN_005e0ff0(0,0xff,local_f0);
            uVar4 = uVar5 & 0xff;
            uVar7 = ((uVar4 | 0xffff8000) << 8 | uVar4) << 8 | uVar4;
            if (DAT_02854c31 == '\0') {
              iVar8 = (uVar5 & 0xfe) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
              uVar5 = (int)uVar7 >> 1 & 0x7f00;
              uVar4 = 0x800000;
            }
            else {
              iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar4 * 0x10000;
              uVar5 = 0x80000000;
            }
            *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
            FUN_006009e0(local_cc,local_a8,0);
            local_e0 = local_c8;
            local_dc = local_c0 * local_44;
            local_d8 = _DAT_0097addc;
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            FUN_005b30a0(&local_e0,&local_e0,local_88);
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            fVar2 = local_dc * 0.5 + 0.5;
            if (local_bc < fVar2) {
              if (local_b4 < fVar2 == (local_b4 == fVar2)) {
                local_f0 = (((fVar2 - local_bc) * local_b0) / local_ac + local_d0) *
                           *(float *)(param_3 + 0x14);
              }
              else {
                local_f0 = *(float *)(param_3 + 0x14) * local_b8;
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_d0;
            }
            if (*(int *)(param_3 + 0x28) != 0) {
              fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
              sVar3 = FUN_005c13c0((float)fVar12);
              fVar2 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
              if (*(float *)(param_3 + 0x38) <= fVar2) {
                if (fVar2 <= *(float *)(param_3 + 0x40)) {
                  fVar12 = (float10)FUN_005bfe40((fVar2 - *(float *)(param_3 + 0x38)) /
                                                 (*(float *)(param_3 + 0x40) -
                                                 *(float *)(param_3 + 0x38)),
                                                 *(undefined4 *)(param_3 + 0x48));
                  local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                      (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                     (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                    (float10)local_f0);
                }
              }
              else {
                local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
              }
            }
            uVar5 = FUN_005e0ff0(0,0xff,local_f0);
            uVar4 = uVar5 & 0xff;
            uVar7 = ((uVar4 | 0xffff8000) << 8 | uVar4) << 8 | uVar4;
            if (DAT_02854c31 == '\0') {
              iVar8 = (uVar5 & 0xfe) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
              uVar5 = (int)uVar7 >> 1 & 0x7f00;
              uVar4 = 0x800000;
            }
            else {
              iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar4 * 0x10000;
              uVar5 = 0x80000000;
            }
            *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
            FUN_006009e0(local_c8,local_c4,0);
            local_e0 = local_c8;
            local_dc = fVar1 * local_44;
            local_d8 = _DAT_0097addc;
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            FUN_005b30a0(&local_e0,&local_e0,local_88);
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            fVar2 = local_dc * 0.5 + 0.5;
            if (local_bc < fVar2) {
              if (local_b4 < fVar2 == (local_b4 == fVar2)) {
                local_f0 = (((fVar2 - local_bc) * local_b0) / local_ac + local_d0) *
                           *(float *)(param_3 + 0x14);
              }
              else {
                local_f0 = *(float *)(param_3 + 0x14) * local_b8;
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_d0;
            }
            if (*(int *)(param_3 + 0x28) != 0) {
              fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
              sVar3 = FUN_005c13c0((float)fVar12);
              fVar2 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
              if (*(float *)(param_3 + 0x38) <= fVar2) {
                if (fVar2 <= *(float *)(param_3 + 0x40)) {
                  fVar12 = (float10)FUN_005bfe40((fVar2 - *(float *)(param_3 + 0x38)) /
                                                 (*(float *)(param_3 + 0x40) -
                                                 *(float *)(param_3 + 0x38)),
                                                 *(undefined4 *)(param_3 + 0x48));
                  local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                      (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                     (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                    (float10)local_f0);
                }
              }
              else {
                local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
              }
            }
            uVar5 = FUN_005e0ff0(0,0xff,local_f0);
            uVar4 = uVar5 & 0xff;
            uVar7 = ((uVar4 | 0xffff8000) << 8 | uVar4) << 8 | uVar4;
            if (DAT_02854c31 == '\0') {
              iVar8 = (uVar5 & 0xfe) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
              uVar5 = (int)uVar7 >> 1 & 0x7f00;
              uVar4 = 0x800000;
            }
            else {
              iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar4 * 0x10000;
              uVar5 = 0x80000000;
            }
            *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
            FUN_006009e0(local_c8,local_a8,0);
            local_e0 = local_c8;
            local_dc = local_c0 * local_44;
            local_d8 = _DAT_0097addc;
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            FUN_005b30a0(&local_e0,&local_e0,local_88);
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            fVar2 = local_dc * 0.5 + 0.5;
            if (local_bc < fVar2) {
              if (local_b4 < fVar2 == (local_b4 == fVar2)) {
                local_f0 = (((fVar2 - local_bc) * local_b0) / local_ac + local_d0) *
                           *(float *)(param_3 + 0x14);
              }
              else {
                local_f0 = *(float *)(param_3 + 0x14) * local_b8;
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_d0;
            }
            if (*(int *)(param_3 + 0x28) != 0) {
              fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
              sVar3 = FUN_005c13c0((float)fVar12);
              fVar2 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
              if (*(float *)(param_3 + 0x38) <= fVar2) {
                if (fVar2 <= *(float *)(param_3 + 0x40)) {
                  fVar12 = (float10)FUN_005bfe40((fVar2 - *(float *)(param_3 + 0x38)) /
                                                 (*(float *)(param_3 + 0x40) -
                                                 *(float *)(param_3 + 0x38)),
                                                 *(undefined4 *)(param_3 + 0x48));
                  local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                      (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                     (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                    (float10)local_f0);
                }
              }
              else {
                local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
              }
            }
            uVar5 = FUN_005e0ff0(0,0xff,local_f0);
            uVar4 = uVar5 & 0xff;
            uVar7 = ((uVar4 | 0xffff8000) << 8 | uVar4) << 8 | uVar4;
            if (DAT_02854c31 == '\0') {
              iVar8 = (uVar5 & 0xfe) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
              uVar5 = (int)uVar7 >> 1 & 0x7f00;
              uVar4 = 0x800000;
            }
            else {
              iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar4 * 0x10000;
              uVar5 = 0x80000000;
            }
            *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
            FUN_006009e0(local_c8,local_c4,0);
            local_e0 = local_cc;
            local_dc = fVar1 * local_44;
            local_d8 = _DAT_0097addc;
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            FUN_005b30a0(&local_e0,&local_e0,local_88);
            FUN_005b3b30(&local_e0,&local_e0);
            local_d4 = 0x3f800000;
            fVar1 = local_dc * 0.5 + 0.5;
            if (local_bc < fVar1) {
              if (local_b4 < fVar1 == (local_b4 == fVar1)) {
                local_f0 = (((fVar1 - local_bc) * local_b0) / local_ac + local_d0) *
                           *(float *)(param_3 + 0x14);
              }
              else {
                local_f0 = *(float *)(param_3 + 0x14) * local_b8;
              }
            }
            else {
              local_f0 = *(float *)(param_3 + 0x14) * local_d0;
            }
            if (*(int *)(param_3 + 0x28) != 0) {
              fVar12 = (float10)FUN_005b39e0(param_3 + 0x2c,&local_e0);
              sVar3 = FUN_005c13c0((float)fVar12);
              fVar1 = (float)(int)(short)(0x4000 - sVar3) * 0.005493164;
              if (*(float *)(param_3 + 0x38) <= fVar1) {
                if (fVar1 <= *(float *)(param_3 + 0x40)) {
                  fVar12 = (float10)FUN_005bfe40((fVar1 - *(float *)(param_3 + 0x38)) /
                                                 (*(float *)(param_3 + 0x40) -
                                                 *(float *)(param_3 + 0x38)),
                                                 *(undefined4 *)(param_3 + 0x48));
                  local_f0 = (float)((((float10)*(float *)(param_3 + 0x3c) -
                                      (float10)*(float *)(param_3 + 0x44)) * ((float10)1 - fVar12) +
                                     (float10)*(float *)(param_3 + 0x44)) * (float10)128.0 +
                                    (float10)local_f0);
                }
              }
              else {
                local_f0 = *(float *)(param_3 + 0x3c) * 128.0 + local_f0;
              }
            }
            uVar5 = FUN_005e0ff0(0,0xff,local_f0);
            uVar4 = uVar5 & 0xff;
            uVar7 = ((uVar4 | 0xffff8000) << 8 | uVar4) << 8 | uVar4;
            if (DAT_02854c31 == '\0') {
              iVar8 = (uVar5 & 0xfe) * 0x8000 + ((int)uVar7 >> 0x11 & 0x7fU);
              uVar5 = (int)uVar7 >> 1 & 0x7f00;
              uVar4 = 0x800000;
            }
            else {
              iVar8 = ((int)uVar7 >> 0x10 & 0xffU) + uVar4 * 0x10000;
              uVar5 = 0x80000000;
            }
            *(uint *)(*DAT_02854d10 + 0xc) = iVar8 + uVar5 + uVar4 * 0x100;
            FUN_006009e0(local_cc,local_a8,0);
          }
          DAT_0097add4 = DAT_0097add4 + 1;
          local_c4 = local_8c + local_c4;
          local_a8 = local_8c + local_a8;
        } while (DAT_0097add4 < param_2);
      }
      FUN_006009a0();
      local_c4 = local_90;
      local_a8 = local_98;
      DAT_0097add8 = DAT_0097add8 + 1;
      local_cc = local_94 + local_cc;
      local_c8 = local_94 + local_c8;
    } while (DAT_0097add8 < local_a0);
  }
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c50 + DAT_02854d1c * 4));
  return;
}

