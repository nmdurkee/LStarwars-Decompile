/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61bd30; label: FUN_0061bd30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061bd30(undefined4 param_1,int param_2,undefined4 param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  float10 extraout_ST0;
  int local_4;
  
  iVar5 = (int)param_4;
  uVar6 = (uint)*(byte *)((int)param_4 + 0x92);
  uVar8 = (uint)*(byte *)((int)param_4 + 0x93);
  iVar7 = uVar6 - 0x80;
  iVar9 = uVar8 - 0x80;
  if (iVar7 < 1) {
    if (-0x20 < iVar7) {
      param_4 = 0.0;
      goto LAB_0061bd92;
    }
    iVar7 = uVar6 - 0x60;
  }
  else {
    if (iVar7 < 0x20) {
      param_4 = 0.0;
      goto LAB_0061bd92;
    }
    iVar7 = uVar6 - 0xa0;
  }
  param_4 = (float)((iVar7 * 0xff) / 0xdf);
LAB_0061bd92:
  if (iVar9 < 1) {
    if (iVar9 < -0x1f) {
      local_4 = (int)((uVar8 - 0x60) * 0xff) / 0xdf;
    }
    else {
      local_4 = 0;
    }
  }
  else if (iVar9 < 0x20) {
    local_4 = 0;
  }
  else {
    local_4 = (int)((uVar8 - 0xa0) * 0xff) / 0xdf;
  }
  pfVar1 = (float *)(param_2 + 0x4c + *(int *)(param_2 + 100) * 4);
  *pfVar1 = (float)(int)param_4 / (*(float *)(param_2 + 0x68) * 8192.0) + *pfVar1;
  pfVar1 = (float *)(param_2 + 0x54 + *(int *)(param_2 + 100) * 4);
  *pfVar1 = (float)local_4 / (*(float *)(param_2 + 0x68) * 8192.0) + *pfVar1;
  pfVar1 = (float *)(param_2 + 0x4c + *(int *)(param_2 + 100) * 4);
  if (0.0 <= *(float *)(param_2 + 0x4c + *(int *)(param_2 + 100) * 4)) {
    param_4 = *pfVar1;
  }
  else {
    param_4 = 0.0;
  }
  if (param_4 <= 1.0) {
    if (0.0 <= *pfVar1) {
      param_4 = *pfVar1;
    }
    else {
      param_4 = 0.0;
    }
  }
  else {
    param_4 = 1.0;
  }
  fVar2 = 1.0;
  *pfVar1 = param_4;
  pfVar1 = (float *)(param_2 + 0x54 + *(int *)(param_2 + 100) * 4);
  if (0.0 <= *(float *)(param_2 + 0x54 + *(int *)(param_2 + 100) * 4)) {
    param_4 = *pfVar1;
  }
  else {
    param_4 = 0.0;
  }
  if ((param_4 <= 1.0) && (fVar2 = 0.0, 0.0 <= *pfVar1)) {
    fVar2 = *pfVar1;
  }
  *pfVar1 = fVar2;
  bVar3 = *(byte *)(iVar5 + 0x9e);
  if (*(byte *)(iVar5 + 0x9c) != 0) {
    bVar3 = *(byte *)(iVar5 + 0x9c);
  }
  bVar4 = *(byte *)(iVar5 + 0x9f);
  if (*(byte *)(iVar5 + 0x9d) != 0) {
    bVar4 = *(byte *)(iVar5 + 0x9d);
  }
  if (bVar3 != 0) {
    fVar2 = *(float *)(param_2 + 0x68) - (float)bVar3 / 4192.0;
    if (1.0 <= fVar2) {
      *(float *)(param_2 + 0x68) = fVar2;
      return 1;
    }
    *(undefined4 *)(param_2 + 0x68) = 0x3f800000;
    return 1;
  }
  if (bVar4 == 0) {
    if ((*(uint *)(iVar5 + 0x78) & 0x100) != 0) {
      iVar7 = *(int *)(param_2 + 100);
      iVar9 = FUN_006e6b90();
      *(float *)(param_2 + 0x4c + iVar7 * 4) = (float)iVar9 * 0.00390625;
      iVar7 = *(int *)(param_2 + 100);
      iVar9 = FUN_006e6b90();
      *(float *)(param_2 + 0x54 + iVar7 * 4) = (float)(extraout_ST0 * (float10)iVar9);
    }
    if ((*(byte *)(iVar5 + 0x78) & 0x80) != 0) {
      *(uint *)(param_2 + 100) = (uint)(*(int *)(param_2 + 100) != 1);
    }
    if (((*(byte *)(iVar5 + 0x78) & 0x40) != 0) && (*(code **)(param_2 + 0x5c) != (code *)0x0)) {
      (**(code **)(param_2 + 0x5c))(param_1,param_2,*(undefined4 *)(iVar5 + 0x70));
    }
    return 0;
  }
  fVar2 = (float)bVar4 / 4192.0 + *(float *)(param_2 + 0x68);
  if (fVar2 <= 16.0) {
    *(float *)(param_2 + 0x68) = fVar2;
    return 1;
  }
  *(undefined4 *)(param_2 + 0x68) = 0x41800000;
  return 1;
}

