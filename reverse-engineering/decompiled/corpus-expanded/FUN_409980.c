/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x409980; label: FUN_00409980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00409980(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  int local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  undefined4 local_90;
  float local_84;
  float local_80;
  float local_7c;
  undefined4 local_6c;
  undefined1 local_5c [12];
  double local_50;
  double local_48;
  
  _DAT_00855d98 = 0;
  local_90 = 0xff000000;
  local_6c = 0xff000000;
  pfVar9 = (float *)&DAT_00854e44;
  local_bc = 8;
  fVar2 = _DAT_007f1068;
  do {
    if ((*(ushort *)((int)pfVar9 + 0x1de) & 1) != 0) {
      uVar5 = (uint)*(byte *)((int)pfVar9 + 0x1db);
      local_cc = pfVar9[uVar5 * 3 + -3] - *pfVar9;
      local_dc = 0.0;
      if ((*(ushort *)((int)pfVar9 + 0x1de) & 4) == 0) {
        if (_DAT_007f1054 < pfVar9[0x6f] == (_DAT_007f1054 == pfVar9[0x6f])) {
          if (pfVar9[0x6f] / _DAT_007f1054 <= 1.0) {
            pfVar9[0x71] = (1.0 - pfVar9[0x6f] / _DAT_007f1054) * fVar2;
          }
          else {
            pfVar9[0x71] = fVar2 * 0.0;
          }
        }
        else {
          pfVar9[0x71] = 0.0;
        }
      }
      else {
        fVar1 = _DAT_00925018 * fVar2 * _DAT_007f106c + pfVar9[0x71];
        pfVar9[0x71] = fVar1;
        if (fVar2 < fVar1) {
          pfVar9[0x71] = fVar2;
        }
      }
      if (pfVar9[0x71] == 0.0) {
        iVar6 = 0;
        if (uVar5 != 1 && -1 < (int)(uVar5 - 1)) {
          pfVar7 = pfVar9 + 2;
          pfVar8 = pfVar9 + 0x5f;
          fVar1 = 0.0;
          do {
            fVar2 = 0.0;
            if ((fVar1 == 0.0) || (pfVar9[0x6f] == 0.0)) {
              local_f4 = 0.0;
            }
            else {
              local_f4 = fVar1 / pfVar9[0x6f];
            }
            local_a8 = pfVar7[-3];
            local_a0 = pfVar7[-1];
            local_a4 = local_f4 * local_cc + *pfVar9;
            fVar1 = fVar1 + *pfVar8;
            if ((fVar1 != 0.0) && (pfVar9[0x6f] != 0.0)) {
              fVar2 = fVar1 / pfVar9[0x6f];
            }
            local_84 = *pfVar7;
            local_7c = pfVar7[2];
            local_80 = *pfVar9 + fVar2 * local_cc;
            if (DAT_00855d9c == 0) {
              FUN_005dbed0(&local_a8,DAT_0093b108);
            }
            else {
              FUN_004d7930(&local_a8,&local_84,0x3f800000,DAT_00881c34,fVar2,fVar2,0x41200000);
            }
            iVar6 = iVar6 + 1;
            pfVar8 = pfVar8 + 1;
            pfVar7 = pfVar7 + 3;
            fVar2 = _DAT_007f1068;
          } while (iVar6 < (int)(*(byte *)((int)pfVar9 + 0x1db) - 1));
        }
      }
      else {
        local_d8 = pfVar9[-1];
        local_d0 = pfVar9[1];
        local_ac = pfVar9[0x6f] * _DAT_007f1064;
        local_d4 = local_cc * 0.0 + *pfVar9;
        fVar10 = (float10)FUN_005506f0(0,&local_d8,0x40a00000,0xffffffff);
        local_e0 = (float)fVar10;
        if (local_e0 == 2e+06) {
          local_e0 = local_d4;
        }
        iVar6 = 0;
        fVar2 = _DAT_007f1068;
        if (*(byte *)((int)pfVar9 + 0x1db) != 1 && -1 < (int)(*(byte *)((int)pfVar9 + 0x1db) - 1)) {
          pfVar8 = pfVar9 + 0x5f;
          pfVar7 = pfVar9 + 2;
          do {
            fVar1 = local_e0;
            fVar2 = 0.0;
            local_b4 = local_d4;
            local_b8 = local_d8;
            local_b0 = local_d0;
            if ((local_dc + *pfVar8 != 0.0) && (pfVar9[0x6f] != 0.0)) {
              fVar2 = (local_dc + *pfVar8) / pfVar9[0x6f];
            }
            local_d8 = *pfVar7;
            local_d0 = pfVar7[2];
            local_d4 = fVar2 * local_cc + *pfVar9;
            fVar10 = (float10)FUN_005506f0(0,&local_d8,0x40a00000,0xffffffff);
            local_e0 = (float)fVar10;
            if (local_e0 == 2e+06) {
              local_e0 = local_d4;
            }
            FUN_005b3800(local_5c,&local_d8,&local_b8);
            fVar2 = 0.0;
            if ((*pfVar8 != 0.0) && (pfVar9[0x6f] != 0.0)) {
              fVar2 = *pfVar8 / pfVar9[0x6f];
            }
            fVar10 = (float10)FUN_006e6c40((double)(fVar2 * local_ac));
            if ((*pfVar8 == 0.0) || ((float)fVar10 == 0.0)) {
              local_ec = 0.0;
            }
            else {
              local_ec = *pfVar8 / (float)fVar10;
            }
            FUN_005b3830(local_5c,local_5c);
            local_f0 = 0.0;
            local_c4 = local_b4;
            local_c8 = local_b8;
            local_48 = (double)(local_ec * 0.5);
            local_c0 = local_b0;
            if (local_ec * 0.5 + 0.0 < *pfVar8) {
              fVar10 = (float10)0.0;
              do {
                local_a4 = local_c4;
                local_50 = (double)(fVar10 + (float10)local_dc);
                local_a8 = local_c8;
                local_a0 = local_c0;
                iVar4 = FUN_006e6b90();
                local_a4 = (float)(extraout_ST0 -
                                  (float10)((float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] *
                                           pfVar9[0x71]));
                if ((fVar10 != extraout_ST1) && ((float10)*pfVar8 != fVar10)) {
                  fVar10 = extraout_ST1 / (float10)*pfVar8;
                }
                fVar2 = (1.0 - (float)fVar10) * fVar1 + local_e0 * (float)fVar10 + 0.05;
                if (local_a4 < fVar2) {
                  local_a4 = fVar2;
                }
                FUN_005b37d0(&local_c8,&local_c8);
                local_80 = local_c4;
                local_84 = local_c8;
                local_7c = local_c0;
                fVar10 = (float10)0;
                iVar4 = FUN_006e6b90();
                fVar2 = (float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * pfVar9[0x71];
                local_80 = local_c4 - fVar2;
                local_f0 = (float)((float10)local_f0 + fVar10);
                fVar10 = extraout_ST1_00;
                if (((float10)local_f0 != extraout_ST1_00) && ((float10)*pfVar8 != extraout_ST1_00))
                {
                  fVar10 = (float10)local_f0 / (float10)*pfVar8;
                }
                fVar3 = (1.0 - (float)fVar10) * fVar1 + local_e0 * (float)fVar10 + 0.05;
                if (local_80 < fVar3) {
                  local_80 = fVar3;
                }
                if (DAT_00855d9c == 0) {
                  FUN_005dbed0(&local_a8,DAT_0093b108);
                }
                else {
                  FUN_004d7930(&local_a8,&local_84,(float)extraout_ST0_00,DAT_00881c34,fVar2,fVar2,
                               0x41200000);
                }
                _DAT_00855d98 = _DAT_00855d98 + 1;
                fVar10 = (float10)local_f0;
              } while ((float10)local_48 + fVar10 < (float10)*pfVar8);
            }
            local_dc = local_dc + *pfVar8;
            iVar6 = iVar6 + 1;
            pfVar8 = pfVar8 + 1;
            pfVar7 = pfVar7 + 3;
            fVar2 = _DAT_007f1068;
          } while (iVar6 < (int)(*(byte *)((int)pfVar9 + 0x1db) - 1));
        }
      }
    }
    pfVar9 = pfVar9 + 0x7b;
    local_bc = local_bc + -1;
  } while (local_bc != 0);
  return;
}

