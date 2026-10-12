/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x6729e0; label: FUN_006729e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006729e0(float *param_1,float param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  short sVar15;
  short sVar16;
  int iVar17;
  float local_68;
  float local_64;
  float local_5c;
  float local_58;
  int local_50;
  int local_4c;
  int local_40;
  int local_3c;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_5c = -2e+06;
  local_68 = 2e+06;
  sVar15 = -1;
  local_58 = -2e+06;
  sVar16 = -1;
  DAT_02961fdc = -1;
  local_64 = 2e+06;
  _DAT_0292fbf4 = -1;
  DAT_0292fbf0 = 0;
  DAT_0292fd44 = 0;
  piVar12 = (int *)(DAT_0292186c + 0x148);
  local_3c = 0;
  local_4c = 0;
  local_40 = 0;
  local_50 = 0;
  if (0 < *(short *)piVar12) {
    iVar6 = *DAT_0292fc68;
    sVar15 = -1;
    sVar16 = -1;
    do {
      sVar5 = *(short *)((int)piVar12 + 2);
      iVar14 = (int)sVar5;
      pfVar1 = (float *)(iVar6 + iVar14 * 0x38);
      fVar9 = *param_1 - *pfVar1;
      fVar10 = param_1[2] - pfVar1[2];
      DAT_0292fd44 = local_50;
      DAT_0292fbf0 = local_4c;
      for (iVar13 = (int)(short)*piVar12; piVar12 = piVar12 + 1, local_50 = DAT_0292fd44,
          local_4c = DAT_0292fbf0, 0 < iVar13; iVar13 = iVar13 + -1) {
        iVar7 = *piVar12;
        bVar8 = *(float *)(iVar7 + 0x4c) <= 0.0;
        if (*(float *)(iVar7 + 0x58) <= 65535.0) {
          if (bVar8) {
            if (*(float *)(iVar7 + 0x4c) < 0.0) {
              bVar8 = 0.0 <= (*(float *)(iVar7 + 0x24) - *(float *)(iVar7 + 0x30)) *
                             (fVar10 - *(float *)(iVar7 + 0x2c)) +
                             (*(float *)(iVar7 + 0x38) - *(float *)(iVar7 + 0x2c)) *
                             (fVar9 - *(float *)(iVar7 + 0x24));
              if (bVar8) {
                if (0.0 <= (*(float *)(iVar7 + 0x18) - *(float *)(iVar7 + 0x24)) *
                           (fVar10 - *(float *)(iVar7 + 0x20)) +
                           (*(float *)(iVar7 + 0x2c) - *(float *)(iVar7 + 0x20)) *
                           (fVar9 - *(float *)(iVar7 + 0x18))) {
                  fVar2 = (*(float *)(iVar7 + 0x30) - *(float *)(iVar7 + 0x18)) *
                          (fVar10 - *(float *)(iVar7 + 0x38));
                  fVar3 = (fVar9 - *(float *)(iVar7 + 0x30)) *
                          (*(float *)(iVar7 + 0x20) - *(float *)(iVar7 + 0x38));
                  goto LAB_0067302c;
                }
              }
              else if (0.0 <= (*(float *)(iVar7 + 0x24) - *(float *)(iVar7 + 0x3c)) *
                              (fVar10 - *(float *)(iVar7 + 0x2c)) +
                              (*(float *)(iVar7 + 0x44) - *(float *)(iVar7 + 0x2c)) *
                              (fVar9 - *(float *)(iVar7 + 0x24))) {
                fVar3 = (*(float *)(iVar7 + 0x3c) - *(float *)(iVar7 + 0x30)) *
                        (fVar10 - *(float *)(iVar7 + 0x44));
                fVar2 = (*(float *)(iVar7 + 0x38) - *(float *)(iVar7 + 0x44)) *
                        (fVar9 - *(float *)(iVar7 + 0x3c));
LAB_0067302c:
                if (0.0 <= fVar3 + fVar2) {
                  iVar17 = 2;
                  goto LAB_00673040;
                }
              }
            }
          }
          else {
            bVar8 = 0.0 <= (*(float *)(iVar7 + 0x30) - *(float *)(iVar7 + 0x24)) *
                           (fVar10 - *(float *)(iVar7 + 0x38)) +
                           (*(float *)(iVar7 + 0x2c) - *(float *)(iVar7 + 0x38)) *
                           (fVar9 - *(float *)(iVar7 + 0x30));
            if (bVar8) {
              if (0.0 <= (fVar9 - *(float *)(iVar7 + 0x24)) *
                         (*(float *)(iVar7 + 0x20) - *(float *)(iVar7 + 0x2c)) +
                         (*(float *)(iVar7 + 0x24) - *(float *)(iVar7 + 0x18)) *
                         (fVar10 - *(float *)(iVar7 + 0x2c))) {
                fVar2 = *(float *)(iVar7 + 0x18);
                fVar3 = *(float *)(iVar7 + 0x20);
                fVar11 = (fVar2 - *(float *)(iVar7 + 0x30)) * (fVar10 - fVar3);
                fVar4 = *(float *)(iVar7 + 0x38);
                goto LAB_00672ec6;
              }
            }
            else if (0.0 <= (*(float *)(iVar7 + 0x3c) - *(float *)(iVar7 + 0x24)) *
                            (fVar10 - *(float *)(iVar7 + 0x44)) +
                            (*(float *)(iVar7 + 0x2c) - *(float *)(iVar7 + 0x44)) *
                            (fVar9 - *(float *)(iVar7 + 0x3c))) {
              fVar2 = *(float *)(iVar7 + 0x30);
              fVar3 = *(float *)(iVar7 + 0x38);
              fVar11 = (fVar2 - *(float *)(iVar7 + 0x3c)) * (fVar10 - fVar3);
              fVar4 = *(float *)(iVar7 + 0x44);
LAB_00672ec6:
              if (0.0 <= fVar11 + (fVar4 - fVar3) * (fVar9 - fVar2)) {
                iVar17 = 1;
LAB_00673040:
                if ((bVar8) || (*(float *)(iVar7 + 0x58) == 0.0)) {
                  fVar2 = *(float *)(iVar6 + 4 + iVar14 * 0x38) + *(float *)(iVar7 + 0x1c) +
                          ((fVar9 - *(float *)(iVar7 + 0x18)) * *(float *)(iVar7 + 0x48) +
                          (fVar10 - *(float *)(iVar7 + 0x20)) * *(float *)(iVar7 + 0x50)) /
                          -*(float *)(iVar7 + 0x4c);
                  bVar8 = param_1[1] < fVar2;
                  if (*(char *)(iVar7 + 0x61) != '\0') {
                    if (((!bVar8) && (local_58 < fVar2)) && (iVar17 == 1)) {
                      local_18 = *(undefined4 *)(iVar7 + 0x48);
                      local_14 = *(float *)(iVar7 + 0x4c);
                      local_10 = *(undefined4 *)(iVar7 + 0x50);
                      _DAT_0292fbf4 = sVar5;
                      local_58 = fVar2;
                      local_40 = iVar7;
                      goto LAB_006732dd;
                    }
                    goto LAB_0067327f;
                  }
                  goto LAB_00672cf1;
                }
                fVar2 = *(float *)(iVar6 + 4 + iVar14 * 0x38) + *(float *)(iVar7 + 0x40) +
                        ((fVar9 - *(float *)(iVar7 + 0x3c)) * *(float *)(iVar7 + 0x54) +
                        (fVar10 - *(float *)(iVar7 + 0x44)) * *(float *)(iVar7 + 0x5c)) /
                        -*(float *)(iVar7 + 0x58);
                if (*(char *)(iVar7 + 0x61) == '\0') {
                  if (((param_1[1] < fVar2) || (fVar2 <= local_5c)) || (iVar17 != 1)) {
                    if (((param_1[1] < fVar2) && (fVar2 <= local_68)) &&
                       ((fVar2 != local_68 || (*(float *)(iVar7 + 0x58) < local_2c)))) {
                      local_30 = *(undefined4 *)(iVar7 + 0x54);
                      local_2c = *(float *)(iVar7 + 0x58);
                      local_28 = *(undefined4 *)(iVar7 + 0x5c);
                      local_68 = fVar2;
                      local_4c = iVar7;
                      sVar15 = sVar5;
                    }
                  }
                  else {
                    local_c = *(undefined4 *)(iVar7 + 0x54);
                    local_8 = *(undefined4 *)(iVar7 + 0x58);
                    local_4 = *(undefined4 *)(iVar7 + 0x5c);
                    DAT_02961fdc = sVar5;
                    local_5c = fVar2;
                    local_4c = DAT_0292fbf0;
                    local_3c = iVar7;
                  }
                }
                else if (((param_1[1] < fVar2) || (fVar2 <= local_58)) || (iVar17 != 1)) {
                  if (((param_1[1] < fVar2) && (fVar2 <= local_64)) &&
                     ((fVar2 != local_64 || (*(float *)(iVar7 + 0x58) < local_20)))) {
                    local_24 = *(undefined4 *)(iVar7 + 0x54);
                    local_20 = *(float *)(iVar7 + 0x58);
                    local_1c = *(undefined4 *)(iVar7 + 0x5c);
                    local_64 = fVar2;
                    local_50 = iVar7;
                    local_4c = DAT_0292fbf0;
                    sVar16 = sVar5;
                  }
                }
                else {
                  local_18 = *(undefined4 *)(iVar7 + 0x54);
                  local_14 = *(float *)(iVar7 + 0x58);
                  local_10 = *(undefined4 *)(iVar7 + 0x5c);
                  _DAT_0292fbf4 = sVar5;
                  local_58 = fVar2;
                  local_50 = DAT_0292fd44;
                  local_4c = DAT_0292fbf0;
                  local_40 = iVar7;
                }
              }
            }
          }
        }
        else if (bVar8) {
          if (((*(float *)(iVar7 + 0x4c) < 0.0) &&
              (0.0 <= (fVar9 - *(float *)(iVar7 + 0x18)) *
                      (*(float *)(iVar7 + 0x2c) - *(float *)(iVar7 + 0x20)) +
                      (*(float *)(iVar7 + 0x18) - *(float *)(iVar7 + 0x24)) *
                      (fVar10 - *(float *)(iVar7 + 0x20)))) &&
             ((0.0 <= (*(float *)(iVar7 + 0x30) - *(float *)(iVar7 + 0x18)) *
                      (fVar10 - *(float *)(iVar7 + 0x38)) +
                      (*(float *)(iVar7 + 0x20) - *(float *)(iVar7 + 0x38)) *
                      (fVar9 - *(float *)(iVar7 + 0x30)) &&
              (0.0 <= (*(float *)(iVar7 + 0x24) - *(float *)(iVar7 + 0x30)) *
                      (fVar10 - *(float *)(iVar7 + 0x2c)) +
                      (*(float *)(iVar7 + 0x38) - *(float *)(iVar7 + 0x2c)) *
                      (fVar9 - *(float *)(iVar7 + 0x24)))))) {
            iVar17 = 2;
            goto LAB_00672c5d;
          }
        }
        else if (((0.0 <= (fVar9 - *(float *)(iVar7 + 0x24)) *
                          (*(float *)(iVar7 + 0x20) - *(float *)(iVar7 + 0x2c)) +
                          (*(float *)(iVar7 + 0x24) - *(float *)(iVar7 + 0x18)) *
                          (fVar10 - *(float *)(iVar7 + 0x2c))) &&
                 (0.0 <= (fVar9 - *(float *)(iVar7 + 0x18)) *
                         (*(float *)(iVar7 + 0x38) - *(float *)(iVar7 + 0x20)) +
                         (*(float *)(iVar7 + 0x18) - *(float *)(iVar7 + 0x30)) *
                         (fVar10 - *(float *)(iVar7 + 0x20)))) &&
                (0.0 <= (fVar9 - *(float *)(iVar7 + 0x30)) *
                        (*(float *)(iVar7 + 0x2c) - *(float *)(iVar7 + 0x38)) +
                        (*(float *)(iVar7 + 0x30) - *(float *)(iVar7 + 0x24)) *
                        (fVar10 - *(float *)(iVar7 + 0x38)))) {
          iVar17 = 1;
LAB_00672c5d:
          fVar2 = *(float *)(iVar6 + 4 + iVar14 * 0x38) + *(float *)(iVar7 + 0x1c) +
                  ((fVar9 - *(float *)(iVar7 + 0x18)) * *(float *)(iVar7 + 0x48) +
                  (fVar10 - *(float *)(iVar7 + 0x20)) * *(float *)(iVar7 + 0x50)) /
                  -*(float *)(iVar7 + 0x4c);
          bVar8 = param_1[1] < fVar2;
          if (*(char *)(iVar7 + 0x61) == '\0') {
LAB_00672cf1:
            if (((bVar8) || (fVar2 <= local_5c)) || (iVar17 != 1)) {
              if (((param_1[1] < fVar2) && (fVar2 <= local_68)) &&
                 ((fVar2 != local_68 || (*(float *)(iVar7 + 0x4c) < local_2c)))) {
                local_30 = *(undefined4 *)(iVar7 + 0x48);
                local_2c = *(float *)(iVar7 + 0x4c);
                local_28 = *(undefined4 *)(iVar7 + 0x50);
                local_68 = fVar2;
                local_50 = DAT_0292fd44;
                local_4c = iVar7;
                sVar15 = sVar5;
              }
            }
            else {
              local_c = *(undefined4 *)(iVar7 + 0x48);
              local_8 = *(undefined4 *)(iVar7 + 0x4c);
              local_4 = *(undefined4 *)(iVar7 + 0x50);
              DAT_02961fdc = sVar5;
              local_5c = fVar2;
              local_50 = DAT_0292fd44;
              local_4c = DAT_0292fbf0;
              local_3c = iVar7;
            }
          }
          else if (((bVar8) || (fVar2 <= local_58)) || (iVar17 != 1)) {
LAB_0067327f:
            if (((param_1[1] < fVar2) && (fVar2 <= local_64)) &&
               ((fVar2 != local_64 || (*(float *)(iVar7 + 0x4c) < local_20)))) {
              local_24 = *(undefined4 *)(iVar7 + 0x48);
              local_20 = *(float *)(iVar7 + 0x4c);
              local_1c = *(undefined4 *)(iVar7 + 0x50);
              local_64 = fVar2;
              local_50 = iVar7;
              local_4c = DAT_0292fbf0;
              sVar16 = sVar5;
            }
          }
          else {
            local_18 = *(undefined4 *)(iVar7 + 0x48);
            local_14 = *(float *)(iVar7 + 0x4c);
            local_10 = *(undefined4 *)(iVar7 + 0x50);
            _DAT_0292fbf4 = sVar5;
            local_58 = fVar2;
            local_50 = DAT_0292fd44;
            local_4c = DAT_0292fbf0;
            local_40 = iVar7;
          }
        }
LAB_006732dd:
        DAT_0292fd44 = local_50;
        DAT_0292fbf0 = local_4c;
      }
    } while (0 < (short)*piVar12);
  }
  if (((2e+06 <= local_64) || (0.0 <= local_20)) || (param_1[1] + param_3 <= local_64)) {
    _DAT_02920ab0 = 0;
    _DAT_02924b08 = 2e+06;
  }
  else if ((((2e+06 <= local_68) || (0.0 <= local_2c)) || (param_1[1] + param_3 <= local_68)) ||
          (local_64 <= local_68)) {
    _DAT_02921188 = 1;
    _DAT_02924b08 = local_64;
    _DAT_02921208 = local_24;
    _DAT_0292120c = local_20;
    _DAT_02921210 = local_1c;
    _DAT_02920ab0 = DAT_0292fd44;
    _DAT_02947c1c = sVar16;
  }
  else {
    _DAT_02920ab0 = 0;
    _DAT_02924b08 = 2e+06;
  }
  if (((2e+06 <= local_64) || (local_20 <= 0.0)) || (param_1[1] + param_3 <= local_64)) {
    _DAT_02920d84 = local_58;
    if ((local_58 <= -2e+06) || ((-2e+06 < local_5c && (local_58 < local_5c)))) {
      DAT_0292fd44 = 0;
      _DAT_0292fdcc = 3;
      _DAT_02920d84 = 2e+06;
      _DAT_02962004 = 1.0;
    }
    else {
      DAT_0292fd44 = local_40;
      _DAT_02962000 = local_18;
      _DAT_0292fdcc = 2;
      _DAT_02962004 = local_14;
      _DAT_02962008 = local_10;
    }
  }
  else if ((((2e+06 <= local_68) || (0.0 <= local_2c)) || (param_1[1] + param_3 <= local_68)) ||
          (local_64 <= local_68)) {
    _DAT_0292fdcc = 1;
    _DAT_02920d84 = local_64;
    _DAT_02962000 = local_24;
    _DAT_02962004 = local_20;
    _DAT_02962008 = local_1c;
    _DAT_0292fbf4 = sVar16;
  }
  else {
    _DAT_0292fdcc = 3;
    DAT_0292fd44 = 0;
    _DAT_02920d84 = 2e+06;
    _DAT_02962004 = 1.0;
  }
  if (((2e+06 <= local_68) || (0.0 <= local_2c)) || (param_1[1] + param_3 <= local_68)) {
    DAT_0292182c = 0;
    _DAT_02921864 = 2e+06;
  }
  else {
    _DAT_02924b0c = 1;
    _DAT_02921864 = local_68;
    _DAT_0292fc30 = local_30;
    _DAT_0292fc34 = local_2c;
    _DAT_0292fc38 = local_28;
    DAT_0292182c = DAT_0292fbf0;
    _DAT_029231a0 = sVar15;
  }
  if (((local_68 < 2e+06) && (0.0 < local_2c)) && (local_68 < param_1[1] + param_2)) {
    param_1[1] = local_68;
    DAT_02961fdc = sVar15;
    DAT_0292fdb8 = local_30;
    _DAT_02947d90 = 1;
    DAT_0292fdbc = local_2c;
    DAT_0292fdc0 = local_28;
    return (float10)0;
  }
  if (local_5c <= -2e+06) {
    param_1[1] = 2e+06;
    _DAT_02947d90 = 3;
    DAT_0292fdbc = 1.0;
    DAT_0292fbf0 = 0;
    return (float10)0;
  }
  DAT_0292fdb8 = local_c;
  _DAT_02947d90 = 2;
  DAT_0292fdbc = (float)local_8;
  DAT_0292fbf0 = local_3c;
  DAT_0292fdc0 = local_4;
  param_1[1] = local_5c;
  return (float10)0;
}

