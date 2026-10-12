/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62b800; label: FUN_0062b800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062b800(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  float10 fVar13;
  float local_2c;
  
  iVar11 = (int)param_2;
  iVar10 = (int)param_1;
  uVar12 = *(uint *)((int)param_2 + 0x1ec);
  if (((*(uint *)((int)param_2 + 0x1e8) & *(uint *)((int)param_1 + 0x1f0)) == 0 &&
       (uVar12 & *(uint *)((int)param_1 + 500)) == 0) &&
     ((*(uint *)((int)param_1 + 0x1e8) & *(uint *)((int)param_2 + 0x1f0)) == 0 &&
      (*(uint *)((int)param_1 + 0x1ec) & *(uint *)((int)param_2 + 500)) == 0)) {
    bVar9 = false;
  }
  else {
    bVar9 = true;
  }
  *(uint *)((int)param_1 + 0x1f0) =
       *(uint *)((int)param_2 + 0x1e8) | *(uint *)((int)param_1 + 0x1f0);
  *(uint *)((int)param_1 + 500) = uVar12 | *(uint *)((int)param_1 + 500);
  *(uint *)((int)param_2 + 0x1f0) =
       *(uint *)((int)param_2 + 0x1f0) | *(uint *)((int)param_1 + 0x1e8);
  *(uint *)((int)param_2 + 500) = *(uint *)((int)param_2 + 500) | *(uint *)((int)param_1 + 0x1ec);
  fVar5 = *(float *)((int)param_2 + 0xa4) + *(float *)((int)param_1 + 0xa4);
  if (fVar5 <= 0.0) {
    local_2c = 1.0;
    param_2 = 1.0;
  }
  else {
    param_2 = (*(float *)((int)param_1 + 0xa4) / fVar5) * 2.0;
    local_2c = 2.0 - param_2;
  }
  if (bVar9) {
    if (((*(byte *)((int)param_1 + 0x1f8) & 0x80) != 0) || ((*(byte *)(iVar11 + 0x1f8) & 0x80) != 0)
       ) {
      return 1;
    }
    fVar5 = *(float *)(iVar11 + 0x98) - *(float *)((int)param_1 + 0x98);
    if (((((ABS(fVar5) < 0.0001) &&
          (ABS(*(float *)(iVar11 + 0xa0) - *(float *)((int)param_1 + 0xa0)) < 0.0001)) &&
         (ABS(*(float *)((int)param_1 + 0x74)) < 0.0001)) &&
        ((ABS(*(float *)((int)param_1 + 0x7c)) < 0.0001 && (ABS(*(float *)(iVar11 + 0x74)) < 0.0001)
         ))) && (ABS(*(float *)(iVar11 + 0x7c)) < 0.0001)) {
      FUN_0062b6a0();
      return 1;
    }
    fVar1 = (*(float *)((int)param_1 + 0x74) + *(float *)(iVar11 + 0x74)) * 0.5;
    fVar6 = (*(float *)((int)param_1 + 0x7c) + *(float *)(iVar11 + 0x7c)) * 0.5;
    if ((*(float *)(iVar11 + 0x98) == *(float *)((int)param_1 + 0x98)) &&
       (*(float *)(iVar11 + 0xa0) == *(float *)((int)param_1 + 0xa0))) {
      return 1;
    }
    fVar7 = *(float *)(iVar11 + 0xa0) - *(float *)((int)param_1 + 0xa0);
    fVar13 = (float10)FUN_005c0240(fVar5 * fVar5 + fVar7 * fVar7);
    fVar13 = (float10)FUN_0062a620(0x3f800000,(float)fVar13);
    fVar5 = (float)fVar13 * fVar5;
    fVar7 = (float)fVar13 * fVar7;
    if ((fVar5 == 0.0) && (fVar7 == 0.0)) {
      FUN_0062b6a0();
      return 1;
    }
    fVar13 = (float10)FUN_005c0240(fVar1 * fVar1 + fVar6 * fVar6);
    param_1 = (float)fVar13;
    if (_DAT_0080fb88 <= param_1) {
      if (_DAT_0080fb8c < param_1) {
        param_1 = _DAT_0080fb8c;
      }
    }
    else {
      param_1 = _DAT_0080fb88;
    }
    uVar12 = *(uint *)(iVar10 + 0x1fc) >> 1 & 1;
    fVar5 = param_1 * 1.4285715 * fVar5;
    fVar7 = param_1 * 1.4285715 * fVar7;
    if ((uVar12 == 0) || ((*(byte *)(iVar11 + 0x1fc) & 2) != 0)) {
      if ((uVar12 == 0) && ((*(byte *)(iVar11 + 0x1fc) & 2) != 0)) {
        *(float *)(iVar10 + 0x68) = fVar1 - fVar5 * 2.0;
        *(float *)(iVar10 + 0x70) = fVar6 - fVar7 * 2.0;
        goto LAB_0062bfe8;
      }
      *(float *)(iVar10 + 0x68) = fVar1 - fVar5;
      *(float *)(iVar10 + 0x70) = fVar6 - fVar7;
      *(float *)(iVar11 + 0x68) = fVar1 + fVar5;
    }
    else {
      *(float *)(iVar11 + 0x68) = fVar1 + fVar5 * 2.0;
      fVar7 = fVar7 * 2.0;
    }
    *(float *)(iVar11 + 0x70) = fVar7 + fVar6;
LAB_0062bfe8:
    *(undefined4 *)(iVar10 + 0x200) = *(undefined4 *)(iVar10 + 0x68);
    *(undefined4 *)(iVar10 + 0x208) = *(undefined4 *)(iVar10 + 0x70);
    *(undefined4 *)(iVar11 + 0x200) = *(undefined4 *)(iVar11 + 0x68);
    *(undefined4 *)(iVar11 + 0x208) = *(undefined4 *)(iVar11 + 0x70);
    return 1;
  }
  if (((*(byte *)((int)param_1 + 0x1f8) & 0x80) != 0) || ((*(byte *)(iVar11 + 0x1f8) & 0x80) != 0))
  {
    return 2;
  }
  fVar5 = *(float *)(iVar11 + 0x98) - *(float *)((int)param_1 + 0x98);
  if ((((ABS(fVar5) < 0.0001) &&
       (ABS(*(float *)(iVar11 + 0xa0) - *(float *)((int)param_1 + 0xa0)) < 0.0001)) &&
      (ABS(*(float *)((int)param_1 + 0x74)) < 0.0001)) &&
     (((ABS(*(float *)((int)param_1 + 0x7c)) < 0.0001 && (ABS(*(float *)(iVar11 + 0x74)) < 0.0001))
      && (ABS(*(float *)(iVar11 + 0x7c)) < 0.0001)))) {
    FUN_0062b6a0();
    return 2;
  }
  fVar1 = *(float *)(iVar11 + 0xa0) - *(float *)((int)param_1 + 0xa0);
  fVar13 = (float10)FUN_005c0240(fVar5 * fVar5 + fVar1 * fVar1);
  fVar6 = 0.0;
  if ((float)fVar13 != 0.0) {
    fVar6 = 1.0 / (float)fVar13;
  }
  fVar5 = fVar6 * fVar5;
  fVar6 = fVar6 * fVar1;
  fVar13 = (float10)FUN_005c0240(*(float *)((int)param_1 + 0x74) * *(float *)((int)param_1 + 0x74) +
                                 *(float *)((int)param_1 + 0x7c) * *(float *)((int)param_1 + 0x7c));
  fVar1 = (float)fVar13;
  fVar7 = 0.0;
  if (fVar1 != 0.0) {
    fVar7 = 1.0 / fVar1;
  }
  fVar2 = *(float *)((int)param_1 + 0x74);
  fVar3 = *(float *)((int)param_1 + 0x7c);
  fVar13 = (float10)FUN_005c0240(*(float *)(iVar11 + 0x74) * *(float *)(iVar11 + 0x74) +
                                 *(float *)(iVar11 + 0x7c) * *(float *)(iVar11 + 0x7c));
  fVar4 = (float)fVar13;
  fVar8 = 0.0;
  if (fVar4 != 0.0) {
    fVar8 = 1.0 / fVar4;
  }
  uVar12 = *(uint *)((int)param_1 + 0x1fc) >> 1 & 1;
  fVar1 = (fVar6 * fVar7 * fVar3 + fVar5 * fVar7 * fVar2) * fVar1;
  fVar7 = fVar1 * fVar5;
  fVar1 = fVar1 * fVar6;
  fVar4 = (fVar8 * *(float *)(iVar11 + 0x74) * fVar5 + fVar8 * *(float *)(iVar11 + 0x7c) * fVar6) *
          fVar4;
  fVar5 = fVar4 * fVar5;
  fVar4 = fVar4 * fVar6;
  if ((uVar12 == 0) || ((*(byte *)(iVar11 + 0x1fc) & 2) != 0)) {
    if ((uVar12 == 0) && ((*(byte *)(iVar11 + 0x1fc) & 2) != 0)) {
      *(float *)((int)param_1 + 0x68) =
           *(float *)((int)param_1 + 0x68) + local_2c * (fVar5 - fVar7) * 2.0;
      *(float *)((int)param_1 + 0x70) =
           (fVar4 - fVar1) * local_2c * 2.0 + *(float *)((int)param_1 + 0x70);
      goto LAB_0062bc97;
    }
    *(float *)((int)param_1 + 0x68) = *(float *)((int)param_1 + 0x68) + local_2c * (fVar5 - fVar7);
    *(float *)((int)param_1 + 0x70) = *(float *)((int)param_1 + 0x70) + (fVar4 - fVar1) * local_2c;
    *(float *)(iVar11 + 0x68) = *(float *)(iVar11 + 0x68) + param_2 * (fVar7 - fVar5);
    param_2 = (fVar1 - fVar4) * param_2;
  }
  else {
    *(float *)(iVar11 + 0x68) = *(float *)(iVar11 + 0x68) + param_2 * (fVar7 - fVar5) * 2.0;
    param_2 = (fVar1 - fVar4) * param_2 * 2.0;
  }
  *(float *)(iVar11 + 0x70) = param_2 + *(float *)(iVar11 + 0x70);
LAB_0062bc97:
  *(undefined4 *)((int)param_1 + 0x200) = *(undefined4 *)((int)param_1 + 0x68);
  *(undefined4 *)((int)param_1 + 0x208) = *(undefined4 *)((int)param_1 + 0x70);
  *(undefined4 *)(iVar11 + 0x200) = *(undefined4 *)(iVar11 + 0x68);
  *(undefined4 *)(iVar11 + 0x208) = *(undefined4 *)(iVar11 + 0x70);
  return 2;
}

