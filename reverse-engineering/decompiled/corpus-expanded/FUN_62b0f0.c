/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62b0f0; label: FUN_0062b0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062b0f0(float param_1,float param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  float10 fVar11;
  float10 fVar12;
  float local_40;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar8 = (int)param_2;
  iVar7 = (int)param_1;
  uVar10 = *(uint *)((int)param_2 + 0x1ec);
  if (((*(uint *)((int)param_2 + 0x1e8) & *(uint *)((int)param_1 + 0x1f0)) == 0 &&
       (uVar10 & *(uint *)((int)param_1 + 500)) == 0) &&
     ((*(uint *)((int)param_1 + 0x1e8) & *(uint *)((int)param_2 + 0x1f0)) == 0 &&
      (*(uint *)((int)param_1 + 0x1ec) & *(uint *)((int)param_2 + 500)) == 0)) {
    bVar6 = false;
  }
  else {
    bVar6 = true;
  }
  *(uint *)((int)param_1 + 0x1f0) =
       *(uint *)((int)param_2 + 0x1e8) | *(uint *)((int)param_1 + 0x1f0);
  *(uint *)((int)param_1 + 500) = uVar10 | *(uint *)((int)param_1 + 500);
  *(uint *)((int)param_2 + 0x1f0) =
       *(uint *)((int)param_2 + 0x1f0) | *(uint *)((int)param_1 + 0x1e8);
  *(uint *)((int)param_2 + 500) = *(uint *)((int)param_2 + 500) | *(uint *)((int)param_1 + 0x1ec);
  fVar2 = *(float *)((int)param_2 + 0xa4) + *(float *)((int)param_1 + 0xa4);
  if (fVar2 <= 0.0) {
    local_40 = 1.0;
    param_2 = 1.0;
  }
  else {
    param_2 = (*(float *)((int)param_1 + 0xa4) / fVar2) * 2.0;
    local_40 = 2.0 - param_2;
  }
  if (bVar6) {
    if (((*(byte *)((int)param_1 + 0x1f8) & 0x80) == 0) && ((*(byte *)(iVar8 + 0x1f8) & 0x80) == 0))
    {
      iVar1 = (int)param_1 + 0x68;
      local_c = (*(float *)(iVar8 + 0x68) + *(float *)((int)param_1 + 0x68)) * 0.5;
      local_8 = (*(float *)((int)param_1 + 0x6c) + *(float *)(iVar8 + 0x6c)) * 0.5;
      local_4 = (*(float *)((int)param_1 + 0x70) + *(float *)(iVar8 + 0x70)) * 0.5;
      if ((*(float *)(iVar8 + 0x98) != *(float *)((int)param_1 + 0x98)) ||
         ((*(float *)(iVar8 + 0x9c) != *(float *)((int)param_1 + 0x9c) ||
          (*(float *)(iVar8 + 0xa0) != *(float *)((int)param_1 + 0xa0))))) {
        FUN_005b3800(&local_30,(float *)(iVar8 + 0x98),(float *)((int)param_1 + 0x98));
        FUN_005b3b30(&local_30,&local_30);
        fVar11 = (float10)FUN_005c0240(local_4 * local_4 + local_c * local_c + local_8 * local_8);
        param_1 = (float)fVar11;
        if (_DAT_0080fb88 <= param_1) {
          if (_DAT_0080fb8c < param_1) {
            param_1 = _DAT_0080fb8c;
          }
        }
        else {
          param_1 = _DAT_0080fb88;
        }
        FUN_005b3830(&local_30,&local_30,param_1 * 1.4285715);
        uVar10 = *(uint *)(iVar7 + 0x1fc) >> 1 & 1;
        if ((uVar10 == 0) || ((*(byte *)(iVar8 + 0x1fc) & 2) != 0)) {
          if ((uVar10 == 0) && ((*(byte *)(iVar8 + 0x1fc) & 2) != 0)) {
            FUN_005b3800(iVar1,&local_c,&local_30);
            FUN_005b3800(iVar1,&local_c,&local_30);
            return 1;
          }
          FUN_005b3800(iVar1,&local_c,&local_30);
        }
        else {
          FUN_005b37d0(iVar8 + 0x68,&local_c,&local_30);
        }
        FUN_005b37d0(iVar8 + 0x68,&local_c,&local_30);
      }
    }
    return 1;
  }
  if (((*(byte *)((int)param_1 + 0x1f8) & 0x80) != 0) || ((*(byte *)(iVar8 + 0x1f8) & 0x80) != 0)) {
    return 2;
  }
  FUN_005b3800(&local_30,iVar8 + 0x98,(int)param_1 + 0x98);
  FUN_005b3b30(&local_30,&local_30);
  fVar11 = (float10)FUN_005c0240(*(float *)((int)param_1 + 0x70) * *(float *)((int)param_1 + 0x70) +
                                 *(float *)((int)param_1 + 0x68) * *(float *)((int)param_1 + 0x68) +
                                 *(float *)((int)param_1 + 0x6c) * *(float *)((int)param_1 + 0x6c));
  fVar2 = (float)fVar11;
  local_1c = 0.0;
  if (fVar2 != 0.0) {
    local_1c = 1.0 / fVar2;
  }
  local_24 = local_1c * *(float *)((int)param_1 + 0x68);
  local_20 = *(float *)((int)param_1 + 0x6c) * local_1c;
  local_1c = local_1c * *(float *)((int)param_1 + 0x70);
  fVar11 = (float10)FUN_005c0240(*(float *)(iVar8 + 0x70) * *(float *)(iVar8 + 0x70) +
                                 *(float *)(iVar8 + 0x68) * *(float *)(iVar8 + 0x68) +
                                 *(float *)(iVar8 + 0x6c) * *(float *)(iVar8 + 0x6c));
  fVar3 = (float)fVar11;
  local_10 = 0.0;
  if (fVar3 != 0.0) {
    local_10 = 1.0 / fVar3;
  }
  local_18 = local_10 * *(float *)(iVar8 + 0x68);
  local_14 = *(float *)(iVar8 + 0x6c) * local_10;
  local_10 = local_10 * *(float *)(iVar8 + 0x70);
  fVar11 = (float10)FUN_005b39e0(&local_24,&local_30);
  fVar12 = (float10)FUN_005b39e0(&local_18,&local_30);
  fVar2 = (float)fVar11 * fVar2;
  uVar10 = *(uint *)((int)param_1 + 0x1fc) >> 1 & 1;
  uVar9 = 2;
  fVar5 = fVar2 * local_30;
  fVar4 = local_2c * fVar2;
  fVar2 = local_28 * fVar2;
  fVar3 = (float)fVar12 * fVar3;
  local_30 = fVar3 * local_30;
  local_2c = local_2c * fVar3;
  local_28 = local_28 * fVar3;
  if ((uVar10 != 0) && ((*(byte *)(iVar8 + 0x1fc) & 2) == 0)) {
    *(float *)(iVar8 + 0x68) = *(float *)(iVar8 + 0x68) + param_2 * (fVar5 - local_30) * 2.0;
    *(float *)(iVar8 + 0x6c) = (fVar4 - local_2c) * param_2 * 2.0 + *(float *)(iVar8 + 0x6c);
    *(float *)(iVar8 + 0x70) = (fVar2 - local_28) * param_2 * 2.0 + *(float *)(iVar8 + 0x70);
    return uVar9;
  }
  if ((uVar10 == 0) && ((*(byte *)(iVar8 + 0x1fc) & 2) != 0)) {
    *(float *)((int)param_1 + 0x68) =
         *(float *)((int)param_1 + 0x68) + local_40 * (local_30 - fVar5) * 2.0;
    *(float *)((int)param_1 + 0x6c) =
         (local_2c - fVar4) * local_40 * 2.0 + *(float *)((int)param_1 + 0x6c);
    *(float *)((int)param_1 + 0x70) =
         (local_28 - fVar2) * local_40 * 2.0 + *(float *)((int)param_1 + 0x70);
    return uVar9;
  }
  *(float *)((int)param_1 + 0x68) = *(float *)((int)param_1 + 0x68) + local_40 * (local_30 - fVar5);
  *(float *)((int)param_1 + 0x6c) = *(float *)((int)param_1 + 0x6c) + local_40 * (local_2c - fVar4);
  *(float *)((int)param_1 + 0x70) = *(float *)((int)param_1 + 0x70) + (local_28 - fVar2) * local_40;
  *(float *)(iVar8 + 0x68) = *(float *)(iVar8 + 0x68) + param_2 * (fVar5 - local_30);
  *(float *)(iVar8 + 0x6c) = (fVar4 - local_2c) * param_2 + *(float *)(iVar8 + 0x6c);
  *(float *)(iVar8 + 0x70) = (fVar2 - local_28) * param_2 + *(float *)(iVar8 + 0x70);
  return uVar9;
}

