/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61b260; label: FUN_0061b260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061b260(float *param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  
  fVar3 = param_1[5];
  iVar7 = FUN_0061b120();
  if (((iVar7 != 0) || ((*(byte *)((int)fVar3 + 0x6c) & 1) != 0)) &&
     (uVar4 = *(uint *)((int)fVar3 + 0x6c), (uVar4 & 2) == 0)) {
    uVar8 = DAT_02912ec4 >> 6;
    *(float *)((int)fVar3 + 0x4c) = (_DAT_0080f550 - *param_1) / param_1[2];
    fVar5 = _DAT_0080f554 - param_1[1];
    fVar1 = param_1[3];
    *(uint *)((int)fVar3 + 0x6c) = (uVar8 ^ uVar4) & 1 ^ uVar4;
    *(float *)((int)fVar3 + 0x50) = fVar5 / (fVar1 * 0.75);
  }
  uVar9 = FUN_0061b180();
  if ((((int)uVar9 != 0) || ((*(byte *)((int)fVar3 + 0x6c) & 2) != 0)) &&
     (uVar4 = *(uint *)((int)fVar3 + 0x6c), (uVar4 & 1) == 0)) {
    fVar5 = _DAT_0080f550 - *param_1;
    fVar1 = param_1[2];
    *(uint *)((int)fVar3 + 0x6c) = ((uint)((ulonglong)uVar9 >> 0x26) * 2 ^ uVar4) & 2 ^ uVar4;
    *(float *)((int)fVar3 + 0x58) = fVar5 / fVar1;
  }
  if (0.0 <= *(float *)((int)fVar3 + 0x4c)) {
    param_1 = *(float **)((int)fVar3 + 0x4c);
  }
  else {
    param_1 = (float *)0x0;
  }
  if ((float)param_1 <= 1.0) {
    if (0.0 <= *(float *)((int)fVar3 + 0x4c)) {
      param_1 = *(float **)((int)fVar3 + 0x4c);
    }
    else {
      param_1 = (float *)0x0;
    }
  }
  else {
    param_1 = (float *)0x3f800000;
  }
  fVar1 = (float)param_1;
  uVar2 = 0x3f800000;
  *(float **)((int)fVar3 + 0x4c) = param_1;
  if (0.0 <= *(float *)((int)fVar3 + 0x50)) {
    param_1 = *(float **)((int)fVar3 + 0x50);
  }
  else {
    param_1 = (float *)0x0;
  }
  if ((float)param_1 <= 1.0) {
    if (0.0 <= *(float *)((int)fVar3 + 0x50)) {
      param_1 = *(float **)((int)fVar3 + 0x50);
    }
    else {
      param_1 = (float *)0x0;
    }
  }
  else {
    param_1 = (float *)0x3f800000;
  }
  uVar6 = param_1;
  *(float **)((int)fVar3 + 0x50) = param_1;
  if (0.0 <= *(float *)((int)fVar3 + 0x58)) {
    param_1 = *(float **)((int)fVar3 + 0x58);
  }
  else {
    param_1 = (float *)0x0;
  }
  if (((float)param_1 <= 1.0) && (uVar2 = 0, 0.0 <= *(float *)((int)fVar3 + 0x58))) {
    uVar2 = *(undefined4 *)((int)fVar3 + 0x58);
  }
  *(undefined4 *)((int)fVar3 + 0x58) = uVar2;
  *(float *)((int)fVar3 + 0x54) = fVar1 * 360.0;
  *(undefined4 *)((int)fVar3 + 0x5c) = uVar6;
  FUN_00618180(fVar1 * 360.0,uVar2,uVar6,(int)fVar3 + 0x60);
  iVar7 = FUN_0061b1f0();
  if ((iVar7 != 0) && (((byte)DAT_02912ec8 & 0x40) != 0)) {
    *(uint *)((int)fVar3 + 0x6c) = *(uint *)((int)fVar3 + 0x6c) & 0xfffffffc | 4;
  }
  if ((*(byte *)((int)fVar3 + 0x6c) & 3) != 0) {
    return 1;
  }
  return 0;
}

