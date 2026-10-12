/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x608590; label: FUN_00608590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00608590(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  uint uVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_d8;
  float local_d4;
  float *local_d0;
  float local_cc;
  float local_c8;
  uint local_c4;
  uint local_c0;
  float local_bc;
  float local_b8;
  undefined4 local_b4;
  uint local_b0;
  uint local_ac;
  float local_a8;
  int local_a4;
  float local_a0;
  float local_9c;
  float local_94 [4];
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  undefined4 local_68 [4];
  double local_58;
  double local_50;
  undefined1 local_48 [68];
  
  iVar9 = 0;
  if (param_1 != 0) {
    DAT_00986efc = DAT_0097f974;
  }
  if ((DAT_0280a298 != 0) && (DAT_00986efc != 0)) {
    local_68[0] = _DAT_0280a2a0;
    local_68[1] = _DAT_0280a2a0;
    local_84 = DAT_0080e6c8;
    local_68[2] = _DAT_0280a2a8;
    local_68[3] = _DAT_0280a2a8;
    pfVar5 = (float *)FUN_006de8d0(0x80);
    FUN_005d6200(local_48,0);
    local_a8 = (float)DAT_00973900 / (float)DAT_00973904;
    local_a4 = 0;
    iVar8 = DAT_00986efc;
    if (0 < DAT_00986efc) {
      do {
        pfVar7 = pfVar5 + 0x10;
        *pfVar7 = *(float *)((int)&DAT_02835ab0 + iVar9);
        pfVar5[0x11] = *(float *)((int)&DAT_02835ab4 + iVar9);
        pfVar5[0x12] = *(float *)((int)&DAT_02835ab8 + iVar9);
        pfVar5[0x13] = 1.0;
        FUN_005c03e0(pfVar7,pfVar7,local_48);
        pfVar7 = pfVar5 + 0x14;
        *pfVar7 = *(float *)((int)&DAT_02835abc + iVar9);
        pfVar5[0x15] = *(float *)((int)&DAT_02835ac0 + iVar9);
        pfVar5[0x16] = *(float *)((int)&DAT_02835ac4 + iVar9);
        pfVar5[0x17] = 1.0;
        FUN_005c03e0(pfVar7,pfVar7,local_48);
        fVar1 = pfVar5[0x13];
        if ((!NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5)) ||
           (fVar1 = pfVar5[0x17], !NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5))) {
          if (0.5 <= pfVar5[0x13]) {
            uVar6 = *(uint *)((int)&DAT_02835ae0 + iVar9);
            pfVar5[0x18] = *(float *)((int)&DAT_02835ab0 + iVar9);
            local_c4 = uVar6 >> 0x18;
            pfVar5[0x19] = *(float *)((int)&DAT_02835ab4 + iVar9);
            fVar1 = *(float *)((int)&DAT_02835ab8 + iVar9);
            local_cc = (float)(uVar6 & 0xff);
            local_d0 = (float *)(uVar6 >> 0x10 & 0xff);
            local_c0 = uVar6 >> 8 & 0xff;
          }
          else {
            if ((&DAT_02835add)[iVar9] == '\0') {
              uVar6 = *(uint *)((int)&DAT_02835ae0 + iVar9);
              local_c4 = uVar6 >> 0x18;
              local_cc = (float)(uVar6 & 0xff);
              local_d0 = (float *)(uVar6 >> 0x10 & 0xff);
              local_c0 = uVar6 >> 8 & 0xff;
            }
            else {
              local_cc = (float)FUN_006e6b90();
              local_c0 = FUN_006e6b90();
              local_d0 = (float *)FUN_006e6b90();
              local_c4 = FUN_006e6b90();
            }
            fVar1 = pfVar5[0x17] - 0.5;
            fVar3 = pfVar5[0x17] - pfVar5[0x13];
            pfVar5[0x18] = ((*(float *)((int)&DAT_02835ab0 + iVar9) -
                            *(float *)((int)&DAT_02835abc + iVar9)) * fVar1) / fVar3 +
                           *(float *)((int)&DAT_02835abc + iVar9);
            pfVar5[0x19] = ((*(float *)((int)&DAT_02835ab4 + iVar9) -
                            *(float *)((int)&DAT_02835ac0 + iVar9)) * fVar1) / fVar3 +
                           *(float *)((int)&DAT_02835ac0 + iVar9);
            fVar1 = ((*(float *)((int)&DAT_02835ab8 + iVar9) -
                     *(float *)((int)&DAT_02835ac4 + iVar9)) * fVar1) / fVar3 +
                    *(float *)((int)&DAT_02835ac4 + iVar9);
          }
          pfVar5[0x1a] = fVar1;
          pfVar5[0x1b] = 1.0;
          fVar1 = pfVar5[0x19] - *(float *)((int)&DAT_02835ac0 + iVar9);
          fVar4 = pfVar5[0x18] - *(float *)((int)&DAT_02835abc + iVar9);
          fVar3 = pfVar5[0x1a] - *(float *)((int)&DAT_02835ac4 + iVar9);
          fVar10 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar4 * fVar4 + fVar1 * fVar1);
          local_c8 = (float)fVar10;
          if (0.5 <= pfVar5[0x17]) {
            pfVar5[0x1c] = *(float *)((int)&DAT_02835abc + iVar9);
            pfVar5[0x1d] = *(float *)((int)&DAT_02835ac0 + iVar9);
            fVar1 = *(float *)((int)&DAT_02835ac4 + iVar9);
          }
          else {
            fVar1 = pfVar5[0x13] - 0.5;
            fVar3 = pfVar5[0x13] - pfVar5[0x17];
            pfVar5[0x1c] = ((*(float *)((int)&DAT_02835abc + iVar9) -
                            *(float *)((int)&DAT_02835ab0 + iVar9)) * fVar1) / fVar3 +
                           *(float *)((int)&DAT_02835ab0 + iVar9);
            pfVar5[0x1d] = ((*(float *)((int)&DAT_02835ac0 + iVar9) -
                            *(float *)((int)&DAT_02835ab4 + iVar9)) * fVar1) / fVar3 +
                           *(float *)((int)&DAT_02835ab4 + iVar9);
            fVar1 = ((*(float *)((int)&DAT_02835ac4 + iVar9) -
                     *(float *)((int)&DAT_02835ab8 + iVar9)) * fVar1) / fVar3 +
                    *(float *)((int)&DAT_02835ab8 + iVar9);
          }
          pfVar5[0x1e] = fVar1;
          pfVar5[0x1f] = 1.0;
          pfVar7 = pfVar5 + 0x10;
          FUN_005c03e0(pfVar7,pfVar5 + 0x18,local_48);
          FUN_005c03b0(pfVar7,pfVar7,1.0 / pfVar5[0x13]);
          FUN_005c03e0(pfVar5 + 0x14,pfVar5 + 0x1c,local_48);
          FUN_005c03b0(pfVar5 + 0x14,pfVar5 + 0x14,1.0 / pfVar5[0x17]);
          if (((((-1.0 <= *pfVar7) || (-1.0 <= pfVar5[0x14])) &&
               ((*pfVar7 <= 1.0 || (pfVar5[0x14] <= 1.0)))) &&
              ((-1.0 <= pfVar5[0x11] || (-1.0 <= pfVar5[0x15])))) &&
             ((pfVar5[0x11] <= 1.0 || (pfVar5[0x15] <= 1.0)))) {
            local_bc = (pfVar5[0x15] - pfVar5[0x11]) * local_a8;
            local_b8 = *pfVar7 - pfVar5[0x14];
            local_b4 = 0;
            FUN_005b3b30(&local_bc,&local_bc);
            local_bc = *(float *)((int)&DAT_02835ac8 + iVar9) * local_a8 * local_bc;
            local_b8 = *(float *)((int)&DAT_02835ac8 + iVar9) * local_b8;
            fVar1 = pfVar5[0x1c] - pfVar5[0x18];
            pfVar5[0x1c] = fVar1;
            fVar3 = pfVar5[0x1d] - pfVar5[0x19];
            pfVar5[0x1d] = fVar3;
            fVar4 = pfVar5[0x1e] - pfVar5[0x1a];
            pfVar5[0x1e] = fVar4;
            pfVar5[0x1f] = pfVar5[0x1f] - pfVar5[0x1b];
            fVar10 = (float10)FUN_005c0240(fVar1 * fVar1 + fVar3 * fVar3 + fVar4 * fVar4);
            if (0.0 < (float)fVar10) {
              local_d8 = *(float *)((int)&DAT_02835acc + iVar9) / (float)fVar10;
              DAT_0080e6c8 = *(uint *)((int)&DAT_02835ae4 + iVar9);
              if (1.0 < local_d8) {
                local_d8 = 1.0;
              }
              local_94[2] = _DAT_0280a29c;
              local_94[0] = _DAT_0280a29c;
              local_94[3] = _DAT_0280a2a4;
              local_94[1] = _DAT_0280a2a4;
              *pfVar7 = pfVar5[0x18];
              pfVar5[0x11] = pfVar5[0x19];
              pfVar5[0x12] = pfVar5[0x1a];
              pfVar5[0x13] = 1.0;
              FUN_005c03e0(pfVar7,pfVar7,local_48);
              local_d4 = 1.0 / pfVar5[0x13];
              FUN_005c03b0(pfVar7,pfVar7,local_d4);
              if (local_c8 < *(float *)((int)&DAT_02835ad8 + iVar9)) {
                if (0.0 <= local_c8) {
                  local_d4 = local_d4 +
                             ((*(float *)((int)&DAT_02835ad8 + iVar9) - local_c8) *
                             (local_d4 * *(float *)((int)&DAT_02835ad4 + iVar9) - local_d4)) /
                             *(float *)((int)&DAT_02835ad8 + iVar9);
                }
                else {
                  local_d4 = *(float *)((int)&DAT_02835ad4 + iVar9) * local_d4;
                }
              }
              local_7c = (uint)local_cc;
              local_80 = (uint)local_cc;
              local_a0 = local_d4 * local_bc;
              local_6c = local_c0;
              local_70 = local_c0;
              local_74 = (uint)local_d0;
              local_9c = local_d4 * local_b8;
              local_78 = (uint)local_d0;
              local_ac = local_c4;
              pfVar5[4] = *pfVar7 - local_a0;
              pfVar5[5] = pfVar5[0x11] - local_9c;
              pfVar5[0xc] = *pfVar7 + local_a0;
              pfVar5[0xd] = local_9c + pfVar5[0x11];
              pfVar5[6] = pfVar5[0x12];
              pfVar5[0xe] = pfVar5[0x12];
              local_c8 = local_c8 - *(float *)((int)&DAT_02835acc + iVar9);
              local_cc = 0.0;
              local_58 = (double)(1.0 - local_d8 * 1.5);
              fVar10 = (float10)0.0;
              do {
                local_b0 = local_ac;
                fVar11 = (float10)1;
                fVar12 = fVar10 + (float10)local_d8;
                local_50 = (double)fVar12;
                if (fVar12 < (float10)1) {
                  if ((&DAT_02835add)[iVar9] != '\0') {
                    local_ac = FUN_006e6b90();
                    fVar11 = extraout_ST1;
                    fVar12 = extraout_ST0;
                  }
                  pfVar5[0x14] = (float)((float10)pfVar5[0x1c] * fVar12 + (float10)pfVar5[0x18]);
                  pfVar5[0x15] = (float)((float10)pfVar5[0x1d] * fVar12 + (float10)pfVar5[0x19]);
                  pfVar5[0x16] = (float)((float10)pfVar5[0x1a] + (float10)pfVar5[0x1e] * fVar12);
                }
                else {
                  if ((&DAT_02835add)[iVar9] != '\0') {
                    local_ac = 0;
                  }
                  pfVar5[0x14] = pfVar5[0x1c] + pfVar5[0x18];
                  pfVar5[0x15] = pfVar5[0x19] + pfVar5[0x1d];
                  pfVar5[0x16] = pfVar5[0x1e] + pfVar5[0x1a];
                  local_94[0] = (float)((((float10)_DAT_0280a29c - (float10)_DAT_0280a2a4) *
                                        ((float10)1 - fVar10)) / (float10)local_d8 +
                                       (float10)_DAT_0280a2a4);
                  local_94[2] = local_94[0];
                }
                pfVar7 = pfVar5 + 0x14;
                pfVar5[0x17] = (float)fVar11;
                FUN_005c03e0(pfVar7,pfVar7,local_48);
                local_d4 = 1.0 / pfVar5[0x17];
                FUN_005c03b0(pfVar7,pfVar7,local_d4);
                if (local_c8 < *(float *)((int)&DAT_02835ad8 + iVar9)) {
                  if (0.0 <= local_c8) {
                    local_d4 = local_d4 +
                               ((local_d4 * *(float *)((int)&DAT_02835ad4 + iVar9) - local_d4) *
                               (*(float *)((int)&DAT_02835ad8 + iVar9) - local_c8)) /
                               *(float *)((int)&DAT_02835ad8 + iVar9);
                  }
                  else {
                    local_d4 = *(float *)((int)&DAT_02835ad4 + iVar9) * local_d4;
                  }
                }
                local_9c = local_d4;
                if (((float)local_58 <= local_cc) || (*(int *)((int)&DAT_02835ae4 + iVar9) == 0)) {
                  local_d0 = (float *)0x0;
                  local_d4 = 0.0;
                }
                else {
                  uVar6 = DAT_0080e6c8 * 0x24cd + 1;
                  DAT_0080e6c8 = uVar6 & 0xffff;
                  fVar1 = (float)(int)((uVar6 & 0xff) - 0x80);
                  local_d0 = (float *)(fVar1 * local_bc * *(float *)((int)&DAT_02835ad0 + iVar9) *
                                      local_d4);
                  local_d4 = fVar1 * local_b8 * *(float *)((int)&DAT_02835ad0 + iVar9) * local_d4;
                }
                local_a0 = local_bc * local_9c;
                local_9c = local_b8 * local_9c;
                *pfVar5 = (float)local_d0 + (*pfVar7 - local_a0);
                pfVar5[1] = local_d4 + (pfVar5[0x15] - local_9c);
                pfVar5[8] = *pfVar7 + local_a0 + (float)local_d0;
                pfVar5[9] = local_9c + pfVar5[0x15] + local_d4;
                pfVar5[2] = pfVar5[0x16];
                pfVar5[10] = pfVar5[0x16];
                iVar2 = DAT_02854d1c;
                iVar8 = DAT_0280a298;
                DAT_02854d1c = DAT_02854d1c + 1;
                _DAT_0080e2b0 = 0x3f800000;
                _DAT_0080e2b4 = 0xbf800000;
                *(undefined4 *)(&DAT_00981c50 + iVar2 * 4) = 1;
                _DAT_02854d20 = 0;
                _DAT_02854d24 = 0;
                FUN_00607d70(0xd,7,iVar8);
                local_d0 = pfVar5 + 1;
                iVar8 = 0;
                do {
                  FUN_005f77d0();
                  iVar2 = *DAT_02854d10;
                  *(float *)(iVar2 + 0x10) = local_94[iVar8];
                  *(undefined4 *)(iVar2 + 0x14) = local_68[iVar8];
                  FUN_006009e0(local_d0[-1],*local_d0 * -1.0,local_d0[1]);
                  local_d0 = local_d0 + 4;
                  iVar8 = iVar8 + 1;
                } while (iVar8 < 4);
                *DAT_02854d18 = DAT_02854d14;
                iVar8 = DAT_02854d1c * 4;
                DAT_02854d1c = DAT_02854d1c + -1;
                DAT_02854d14 = 0;
                FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar8));
                pfVar5[4] = *pfVar5;
                local_b0 = local_ac;
                pfVar5[5] = pfVar5[1];
                pfVar5[6] = pfVar5[2];
                pfVar5[0xc] = pfVar5[8];
                pfVar5[0xd] = pfVar5[9];
                pfVar5[0xe] = pfVar5[10];
                local_cc = (float)local_50;
                local_c8 = local_c8 - *(float *)((int)&DAT_02835acc + iVar9);
                fVar10 = (float10)local_cc;
              } while (fVar10 < (float10)1);
            }
          }
        }
        local_a4 = local_a4 + 1;
        iVar9 = iVar9 + 0x38;
        iVar8 = DAT_00986efc;
      } while (local_a4 < DAT_00986efc);
    }
    DAT_0080e6c8 = local_84;
    DAT_00986efc = 0;
    DAT_0097f974 = iVar8;
    FUN_006de960();
    return;
  }
  DAT_0097f974 = 0;
  return;
}

