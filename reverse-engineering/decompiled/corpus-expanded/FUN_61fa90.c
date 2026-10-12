/* Ghidra pseudocode, not original source.
 * ev_8a909e0f7cdee8f131d9fa101a03e4afa99ad6c03186a84914f93ab3f48399ec
 * Entry: 0x61fa90; label: FUN_0061fa90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061fa90(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  byte bVar2;
  uint uVar3;
  float fVar4;
  
  uVar3 = *(uint *)(param_4 + 0x70);
  if (((uVar3 & 4) != 0) && ((uVar3 & 8) != 0)) {
    if ((param_2 != 0) &&
       ((*(float *)(param_2 + 0x58) <= 0.0 &&
        (0.0 <= *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58))))) {
      FUN_0061f9d0(param_1,param_2,0);
      DAT_0080fb80 = 0x1e;
      return 0;
    }
    DAT_0080fb80 = 0x1e;
    return 0;
  }
  if (((uVar3 & 1) != 0) && ((uVar3 & 2) != 0)) {
    if ((param_2 != 0) &&
       ((*(float *)(param_2 + 0x58) <= 0.0 &&
        (255.0 <= *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58))))) {
      FUN_0061f9d0(param_1,param_2,0x437f0000);
    }
    DAT_0080fb80 = 0x1e;
    return 0;
  }
  if ((uVar3 & 4) != 0) {
    DAT_0080fb80 = DAT_0080fb80 + -1;
    if (DAT_0080fb80 < 0) {
      DAT_0080fb80 = 0;
    }
    else if ((DAT_0080fb80 != 0) && ((*(byte *)(param_4 + 0x78) & 4) == 0)) {
      return 0;
    }
    fVar1 = *(float *)(param_2 + 0x54) - *(float *)(param_2 + 0x68);
    if (fVar1 < *(float *)(param_2 + 0x58)) {
      fVar1 = *(float *)(param_2 + 0x58);
    }
    FUN_0061fa00(param_1,param_2,param_4,fVar1);
    return 0;
  }
  if ((uVar3 & 8) != 0) {
    DAT_0080fb80 = DAT_0080fb80 + -1;
    if (DAT_0080fb80 < 0) {
      DAT_0080fb80 = 0;
    }
    else if ((DAT_0080fb80 != 0) && ((*(byte *)(param_4 + 0x78) & 8) == 0)) {
      return 0;
    }
    fVar1 = *(float *)(param_2 + 0x5c) + *(float *)(param_2 + 0x58);
    fVar4 = *(float *)(param_2 + 0x68) + *(float *)(param_2 + 0x54);
    if (fVar1 < fVar4) {
      fVar4 = fVar1;
    }
    FUN_0061fa00(param_1,param_2,param_4,fVar4);
    return 0;
  }
  bVar2 = *(byte *)(param_4 + 0x9e);
  DAT_0080fb80 = 0x1e;
  if (bVar2 == 0) {
    bVar2 = *(byte *)(param_4 + 0x9f);
    if (bVar2 == 0) {
      DAT_0080fb80 = 0x1e;
      _DAT_029130b8 = 1.6276043e-07;
      return 0;
    }
    if (*(char *)(param_4 + 0x99) == '\0') {
      _DAT_029130b8 = 1.6276043e-07;
      fVar1 = (float)bVar2 * 1.6276043e-05 + *(float *)(param_2 + 0x50);
    }
    else {
      _DAT_029130b8 = _DAT_029130b8 * 1.05;
      fVar1 = (float)bVar2 * _DAT_029130b8 + *(float *)(param_2 + 0x50);
    }
    fVar4 = 1.0;
    if (1.0 < fVar1) goto LAB_0061fca0;
  }
  else {
    if (*(char *)(param_4 + 0x99) == '\0') {
      _DAT_029130b8 = 1.6276043e-07;
      fVar1 = *(float *)(param_2 + 0x50);
      fVar4 = (float)bVar2 * 1.6276043e-05;
    }
    else {
      _DAT_029130b8 = _DAT_029130b8 * 1.05;
      fVar1 = *(float *)(param_2 + 0x50);
      fVar4 = (float)bVar2 * _DAT_029130b8;
    }
    fVar1 = fVar1 - fVar4;
    fVar4 = 0.0;
    if (fVar1 < 0.0) goto LAB_0061fca0;
  }
  fVar4 = fVar1;
LAB_0061fca0:
  *(float *)(param_2 + 0x50) = fVar4;
  *(undefined4 *)(param_2 + 0x60) = 0x3c;
  *(float *)(param_2 + 0x54) =
       *(float *)(param_2 + 0x5c) * *(float *)(param_2 + 0x50) + *(float *)(param_2 + 0x58);
  if (*(code **)(param_2 + 0x4c) == (code *)0x0) {
    return 0;
  }
  (**(code **)(param_2 + 0x4c))(param_1,param_2,*(undefined4 *)(param_4 + 0x70));
  return 0;
}

