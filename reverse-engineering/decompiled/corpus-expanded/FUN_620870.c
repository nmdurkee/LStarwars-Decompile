/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x620870; label: FUN_00620870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00620870(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined2 uVar5;
  int iVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  float10 fVar13;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  if (param_1[0x23] == 0.0) {
    fVar4 = 1.0;
  }
  else {
    fVar4 = ABS(param_1[5]) * param_1[0x23] + param_1[0x22];
  }
  local_44 = 0.0;
  local_48 = 0.0;
  local_4c = 0.0;
  iVar6 = FUN_006d6c20(0x38);
  if (iVar6 != 0) {
    fVar12 = (float10)FUN_006d5bf0();
    fVar1 = (float)(fVar12 * (float10)param_1[0x1d]);
    fVar12 = (float10)FUN_006d5c10();
    fVar7 = (float)(fVar12 * (float10)param_1[0x1e]);
    fVar12 = (float10)FUN_006d5c30();
    fVar2 = param_1[0x1f];
    iVar6 = FUN_006d58b0();
    if ((iVar6 == 2) || (iVar6 == 5)) {
      if (((uint)param_1[0x24] & 0x20) != 0) {
        if ((fVar1 != 0.0) || (fVar7 != 0.0)) {
          uVar5 = FUN_005be2d0(-fVar1,-fVar7);
          _DAT_029130c0 = CONCAT22(DAT_029130c0_2,uVar5);
        }
        uVar8 = _DAT_029130c0 - DAT_029130bc & 0xffff;
        if (0x7fff < uVar8) {
          uVar8 = uVar8 - 0x10000;
        }
        uVar9 = (int)uVar8 >> 0x1f;
        if ((int)((uVar8 ^ uVar9) - uVar9) < 0x4e21) {
          DAT_029130bc._0_2_ = (short)DAT_029130bc + (short)((int)(uVar8 + (uVar9 & 3)) >> 2);
        }
        else {
          DAT_029130bc._0_2_ = DAT_029130c0;
        }
        fVar3 = (float)(&DAT_029899a0)[DAT_029130bc + 0x2000 >> 1 & 0x7fff];
        if (0.1 < ABS(fVar3)) {
          if (fVar3 <= 0.0) {
            fVar3 = fVar3 + 0.1;
          }
          else {
            fVar3 = fVar3 - 0.1;
          }
          fVar13 = (float10)FUN_005c0240(fVar1 * fVar1 + fVar7 * fVar7);
          fVar1 = param_1[0x1b] * fVar4 * (float)(fVar13 * (float10)fVar3) * param_1[0x1f] +
                  param_1[5];
          param_1[5] = fVar1;
          if (fVar1 <= -param_1[0x1c]) {
            param_1[5] = fVar1;
          }
          else {
            param_1[5] = -param_1[0x1c];
          }
        }
      }
    }
    else if (iVar6 == 1) {
      fVar1 = param_1[0x24];
      if (((uint)fVar1 & 8) != 0) {
        iVar6 = FUN_006e6b90();
        param_1[3] = (float)((int)param_1[3] + iVar6);
        fVar7 = param_1[3];
        if (0x4000 < (int)fVar7) {
          fVar7 = 2.29589e-41;
        }
        param_1[3] = fVar7;
        if ((int)fVar7 < -0x4000) {
          fVar7 = -NAN;
        }
        param_1[3] = fVar7;
      }
      if (((uint)fVar1 & 0x10) != 0) {
        iVar6 = FUN_006e6b90();
        param_1[4] = (float)((int)param_1[4] + iVar6);
      }
    }
    else if ((iVar6 == 4) || (iVar6 == 3)) {
      local_4c = local_4c + fVar1 * 0.0078125;
      local_48 = local_48 - fVar7 * 0.0078125;
    }
    fVar4 = param_1[5] - param_1[0x1b] * fVar4 * (float)(fVar12 * (float10)fVar2);
    param_1[5] = fVar4;
    if (-param_1[0x1c] < fVar4) {
      fVar4 = -param_1[0x1c];
    }
    fVar1 = param_1[3];
    param_1[5] = fVar4;
    puVar10 = &DAT_00806680;
    puVar11 = local_40;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    FUN_005b4cf0(local_40,fVar1);
    FUN_005b4f70(local_40,param_1[4]);
    FUN_005b3200(&local_4c,&local_4c,local_40);
    fVar4 = param_1[0x24];
    if (((uint)fVar4 & 1) != 0) {
      *param_1 = *param_1 + local_4c;
    }
    if (((uint)fVar4 & 2) != 0) {
      param_1[1] = local_48 + param_1[1];
    }
    if (((uint)fVar4 & 4) != 0) {
      param_1[2] = param_1[2] + local_44;
    }
  }
  return;
}

