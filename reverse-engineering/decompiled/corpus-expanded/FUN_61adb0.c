/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61adb0; label: FUN_0061adb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061adb0(undefined4 param_1,float param_2,float param_3,int param_4)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar6 = param_4;
  iVar5 = (int)param_2;
  if (DAT_02912ec4 == 0) {
    *(uint *)((int)param_2 + 0x6c) = *(uint *)((int)param_2 + 0x6c) & 0xfffffffc;
  }
  uVar7 = (uint)*(byte *)(param_4 + 0x92);
  iVar8 = uVar7 - 0x80;
  if (iVar8 < 1) {
    if (iVar8 < -0x1f) {
      param_2 = (float)((int)((uVar7 - 0x60) * 0xff) / 0xdf);
    }
    else {
      param_2 = 0.0;
    }
  }
  else if (iVar8 < 0x20) {
    param_2 = 0.0;
  }
  else {
    param_2 = (float)((int)((uVar7 - 0xa0) * 0xff) / 0xdf);
  }
  uVar7 = (uint)*(byte *)(param_4 + 0x93);
  iVar8 = uVar7 - 0x80;
  if (iVar8 < 1) {
    if (iVar8 < -0x1f) {
      param_4 = (int)((uVar7 - 0x60) * 0xff) / 0xdf;
    }
    else {
      param_4 = 0;
    }
  }
  else if (iVar8 < 0x20) {
    param_4 = 0;
  }
  else {
    param_4 = (int)((uVar7 - 0xa0) * 0xff) / 0xdf;
  }
  fVar1 = *(float *)(iVar5 + 0x4c) + (float)(int)param_2 * 0.001;
  *(float *)(iVar5 + 0x4c) = fVar1;
  fVar2 = *(float *)(iVar5 + 0x50) + (float)param_4 * 0.001;
  *(float *)(iVar5 + 0x50) = fVar2;
  if (0.0 <= fVar1) {
    param_2 = *(float *)(iVar5 + 0x4c);
  }
  else {
    param_2 = 0.0;
  }
  if (param_2 <= 1.0) {
    if (0.0 <= *(float *)(iVar5 + 0x4c)) {
      param_2 = *(float *)(iVar5 + 0x4c);
    }
    else {
      param_2 = 0.0;
    }
  }
  else {
    param_2 = 1.0;
  }
  fVar1 = param_2;
  uVar4 = 0x3f800000;
  uVar3 = 0x3f800000;
  *(float *)(iVar5 + 0x4c) = param_2;
  if (0.0 <= fVar2) {
    param_2 = *(float *)(iVar5 + 0x50);
  }
  else {
    param_2 = 0.0;
  }
  if ((param_2 <= 1.0) && (uVar4 = 0, 0.0 <= *(float *)(iVar5 + 0x50))) {
    uVar4 = *(undefined4 *)(iVar5 + 0x50);
  }
  *(undefined4 *)(iVar5 + 0x50) = uVar4;
  if (*(byte *)(iVar6 + 0x9e) == 0) {
    if (*(byte *)(iVar6 + 0x9f) == 0) {
      *(float *)(iVar5 + 0x54) = fVar1 * 360.0;
      *(undefined4 *)(iVar5 + 0x5c) = uVar4;
      FUN_00618180(fVar1 * 360.0,*(undefined4 *)(iVar5 + 0x58),uVar4,iVar5 + 0x60);
      if ((((*(byte *)(iVar6 + 0x78) & 0x40) != 0) || ((*(byte *)(iVar5 + 0x6c) & 4) != 0)) &&
         (*(code **)(iVar5 + 0x70) != (code *)0x0)) {
        (**(code **)(iVar5 + 0x70))(param_1,iVar5,*(undefined4 *)(iVar6 + 0x70));
      }
      return 0;
    }
    fVar1 = (float)*(byte *)(iVar6 + 0x9f) * param_3 * 0.005 + *(float *)(iVar5 + 0x58);
    if (1.0 < fVar1) goto LAB_0061afeb;
  }
  else {
    fVar1 = *(float *)(iVar5 + 0x58) - (float)*(byte *)(iVar6 + 0x9e) * param_3 * 0.005;
    uVar3 = 0;
    if (fVar1 < 0.0) {
LAB_0061afeb:
      *(undefined4 *)(iVar5 + 0x58) = uVar3;
      return 1;
    }
  }
  *(float *)(iVar5 + 0x58) = fVar1;
  return 1;
}

