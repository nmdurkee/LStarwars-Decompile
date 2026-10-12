/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61d990; label: FUN_0061d990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061d990(undefined4 param_1,int param_2,float param_3,int param_4)

{
  float fVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 extraout_ST0_00;
  
  uVar3 = *(uint *)(param_4 + 0x70);
  if (((uVar3 & 4) != 0) && ((uVar3 & 8) != 0)) {
    uVar4 = 0;
    if ((0.0 < *(float *)(param_2 + 0x58)) ||
       (fVar1 = 0.0, *(float *)(param_2 + 0x58) + *(float *)(param_2 + 0x5c) <= 0.0)) {
      uVar4 = 0x3f800000;
      if (1.0 < *(float *)(param_2 + 0x58)) {
        DAT_0080fb7c = 0x1e;
        return 0;
      }
      fVar5 = *(float *)(param_2 + 0x58) + *(float *)(param_2 + 0x5c);
      fVar1 = 1.0;
      if (NAN(fVar5) || 1.0 < fVar5 == (fVar5 == 1.0)) {
        DAT_0080fb7c = 0x1e;
        return 0;
      }
    }
    *(undefined4 *)(param_2 + 0x54) = uVar4;
    *(undefined4 *)(param_2 + 0x60) = 0x3c;
    *(float *)(param_2 + 0x50) = (fVar1 - *(float *)(param_2 + 0x58)) / *(float *)(param_2 + 0x5c);
    if (*(code **)(param_2 + 0x4c) == (code *)0x0) {
      DAT_0080fb7c = 0x1e;
      return 0;
    }
    (**(code **)(param_2 + 0x4c))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
    DAT_0080fb7c = 0x1e;
    return 0;
  }
  if ((uVar3 & 4) != 0) {
    DAT_0080fb7c = DAT_0080fb7c + -1;
    if (DAT_0080fb7c < 0) {
      DAT_0080fb7c = 0;
    }
    else if ((DAT_0080fb7c != 0) && ((*(byte *)(param_4 + 0x78) & 4) == 0)) {
      return 0;
    }
    fVar5 = *(float *)(param_2 + 0x68) * _DAT_0080fb78;
    fVar1 = *(float *)(param_2 + 0x54) - fVar5;
    if (fVar1 < *(float *)(param_2 + 0x58)) {
      fVar1 = *(float *)(param_2 + 0x58);
    }
    *(float *)(param_2 + 0x54) = fVar1;
    fVar5 = fVar5 * 0.5;
    if (fVar1 <= 0.0) {
      fVar1 = fVar1 - fVar5;
    }
    else {
      fVar1 = fVar5 + fVar1;
    }
    *(float *)(param_2 + 0x54) = fVar1;
    iVar7 = FUN_006e6b90();
    fVar8 = extraout_ST0 * (float10)iVar7;
LAB_0061daca:
    *(float *)(param_2 + 0x54) = (float)fVar8;
    *(undefined4 *)(param_2 + 0x60) = 0x3c;
    *(float *)(param_2 + 0x50) =
         ((float)fVar8 - *(float *)(param_2 + 0x58)) / *(float *)(param_2 + 0x5c);
    if (*(code **)(param_2 + 0x4c) != (code *)0x0) {
      (**(code **)(param_2 + 0x4c))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
    }
    _DAT_0080fb78 = _DAT_02912ea8 + _DAT_0080fb78;
    return 0;
  }
  if ((uVar3 & 8) != 0) {
    DAT_0080fb7c = DAT_0080fb7c + -1;
    if (DAT_0080fb7c < 0) {
      DAT_0080fb7c = 0;
    }
    else if ((DAT_0080fb7c != 0) && ((*(byte *)(param_4 + 0x78) & 8) == 0)) {
      return 0;
    }
    fVar1 = *(float *)(param_2 + 0x58) + *(float *)(param_2 + 0x5c);
    fVar6 = *(float *)(param_2 + 0x68) * _DAT_0080fb78;
    fVar5 = *(float *)(param_2 + 0x54) + fVar6;
    if (fVar1 < fVar5) {
      fVar5 = fVar1;
    }
    *(float *)(param_2 + 0x54) = fVar5;
    fVar6 = fVar6 * 0.5;
    if (fVar5 <= 0.0) {
      fVar5 = fVar5 - fVar6;
    }
    else {
      fVar5 = fVar6 + fVar5;
    }
    *(float *)(param_2 + 0x54) = fVar5;
    iVar7 = FUN_006e6b90();
    fVar8 = extraout_ST0_00 * (float10)iVar7;
    goto LAB_0061daca;
  }
  bVar2 = *(byte *)(param_4 + 0x9e);
  _DAT_0080fb78 = 1.0;
  DAT_0080fb7c = 0x1e;
  if (bVar2 == 0) {
    bVar2 = *(byte *)(param_4 + 0x9f);
    if (bVar2 == 0) {
      _DAT_0080fb78 = 1.0;
      DAT_0080fb7c = 0x1e;
      _DAT_029130ac = 1.6276043e-07;
      return 0;
    }
    if ((uVar3 & 0x20) == 0) {
      _DAT_029130ac = 1.6276043e-07;
      fVar1 = (((float)bVar2 * param_3) / _DAT_0080f54c) * 1.6276043e-05 +
              *(float *)(param_2 + 0x50);
    }
    else {
      _DAT_029130ac = _DAT_029130ac * 1.05;
      fVar1 = (((float)bVar2 * param_3) / _DAT_0080f54c) * _DAT_029130ac +
              *(float *)(param_2 + 0x50);
    }
    fVar5 = 1.0;
    if (1.0 < fVar1) goto LAB_0061dc41;
  }
  else {
    if ((uVar3 & 0x20) == 0) {
      _DAT_029130ac = 1.6276043e-07;
      fVar1 = *(float *)(param_2 + 0x50);
      fVar5 = (((float)bVar2 * param_3) / _DAT_0080f54c) * 1.6276043e-05;
    }
    else {
      _DAT_029130ac = _DAT_029130ac * 1.05;
      fVar1 = *(float *)(param_2 + 0x50);
      fVar5 = (((float)bVar2 * param_3) / _DAT_0080f54c) * _DAT_029130ac;
    }
    fVar1 = fVar1 - fVar5;
    fVar5 = 0.0;
    if (fVar1 < 0.0) goto LAB_0061dc41;
  }
  fVar5 = fVar1;
LAB_0061dc41:
  *(float *)(param_2 + 0x50) = fVar5;
  *(undefined4 *)(param_2 + 0x60) = 0x3c;
  *(float *)(param_2 + 0x54) =
       *(float *)(param_2 + 0x5c) * *(float *)(param_2 + 0x50) + *(float *)(param_2 + 0x58);
  if (*(code **)(param_2 + 0x4c) == (code *)0x0) {
    return 0;
  }
  (**(code **)(param_2 + 0x4c))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
  return 0;
}

