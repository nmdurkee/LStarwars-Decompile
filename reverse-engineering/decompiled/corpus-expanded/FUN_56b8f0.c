/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56b8f0; label: FUN_0056b8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056b8f0(int param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  int iVar8;
  float10 fVar9;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c [3];
  
  if (_DAT_0080282c == -1) {
    return;
  }
  iVar8 = (int)*(char *)(param_1 + 0x7b5);
  if (iVar8 != _DAT_0080282c) {
    if (*(char *)(param_1 + 0x281) != '\0') {
      return;
    }
    if (0.0 < *(float *)(param_1 + 0x6c)) {
      return;
    }
    if (DAT_008030e4 != 0) {
      if (DAT_00804c30 == -1) {
        return;
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c30 * 4) == 0) {
        return;
      }
    }
    if ((*(char *)(param_1 + 0x7b5) != -1) && ((DAT_00802830 == -1 || (iVar8 != DAT_00802830)))) {
      if (DAT_00802838 == -1) {
        return;
      }
      if (iVar8 != DAT_00802838) {
        return;
      }
      if (*(float *)(param_1 + 0x77c) < 0.1) {
        return;
      }
    }
    if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) && ((*(uint *)(param_1 + 0xef4) & 0x8000) == 0))
    {
      return;
    }
    if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
      return;
    }
    uVar6 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4),&local_20);
    iVar8 = FUN_0056b730(uVar6);
    if (iVar8 == 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x7b5) = DAT_0080282c;
    *(undefined4 *)(param_1 + 0x68) = DAT_0093b0cc;
    *(undefined4 *)(param_1 + 0x6c) = DAT_0093b0d0;
    uVar6 = DAT_0093b0d4;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined4 *)(param_1 + 0x70) = uVar6;
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    sVar4 = DAT_00804c30;
    sVar3 = DAT_00804c2c;
    if ((DAT_00804c2c == -1) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c2c * 4) == 0)) {
      iVar8 = (int)DAT_00804c30;
      *(undefined4 *)(param_1 + 0x778) = 0x3dcccccd;
      *(short *)(param_1 + 0x7aa) = sVar4;
      FUN_0062e650(param_1 + 8,iVar8);
    }
    else {
      *(short *)(param_1 + 0x7aa) = DAT_00804c2c;
      fVar9 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar3,0,0,1);
      *(float *)(param_1 + 0x778) = (float)fVar9;
    }
    *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x74c) = local_14;
    *(short *)(param_1 + 0x5a) = local_20._0_2_ + -0x8000;
    *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x754) = local_18;
    *(undefined4 *)(param_1 + 0x758) = local_14;
    *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
    *(undefined4 *)(param_1 + 0x75c) = local_10;
    return;
  }
  if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0) {
    FUN_00561ba0(param_1,0);
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
    local_20 = (*(float *)(param_1 + 0x74c) + 0.1) - *(float *)(param_1 + 0x78c);
    if (local_20 <= 0.0) {
      return;
    }
    local_20 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x24) * -2.0 * local_20;
    fVar9 = (float10)FUN_005c0240(local_20);
    *(float *)(param_1 + 0x6c) = (float)fVar9;
    return;
  }
  if ((*(byte *)(param_1 + 0x281) & 2) != 0) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    return;
  }
  if (((*(char *)(param_1 + 0x7b3) != '\0') || (*(short *)(param_1 + 0x7aa) != DAT_00804c2c)) ||
     (iVar8 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0), iVar8 != 0)) {
    *(float *)(param_1 + 0x77c) = _DAT_00925018 + *(float *)(param_1 + 0x77c);
  }
  if ((*(char *)(param_1 + 0x7b3) == '\0') &&
     (*(float *)(param_1 + 0x778) < *(float *)(param_1 + 0x77c) !=
      (*(float *)(param_1 + 0x778) == *(float *)(param_1 + 0x77c)))) {
    *(undefined1 *)(param_1 + 0x7b3) = 1;
  }
  iVar8 = FUN_0056b730(*(undefined2 *)(param_1 + 0x5a),&local_20);
  if (iVar8 == 0) {
    local_1c = *(float *)(param_1 + 0x784) - _DAT_00925018;
    *(float *)(param_1 + 0x784) = local_1c;
    if (local_1c < 0.0 != (local_1c == 0.0)) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
    local_20 = 0.0;
  }
  else {
    fVar1 = *(float *)(param_1 + 0x748);
    fVar2 = *(float *)(param_1 + 0x750);
    *(short *)(param_1 + 0x5a) = local_20._0_2_ + -0x8000;
    *(undefined4 *)(param_1 + 0x754) = local_18;
    *(float *)(param_1 + 0x748) = *(float *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x758) = local_14;
    *(undefined4 *)(param_1 + 0x75c) = local_10;
    *(undefined4 *)(param_1 + 0x74c) = local_14;
    *(float *)(param_1 + 0x750) = *(float *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
    fVar1 = *(float *)(param_1 + 0x5c) - fVar1;
    local_20 = *(float *)(param_1 + 100) - fVar2;
    local_1c = fVar1 * fVar1 + local_20 * local_20;
    fVar9 = (float10)FUN_005c0240(local_1c);
    local_20 = (float)fVar9;
  }
  if (*(char *)(param_1 + 0x7b3) == '\0') {
    return;
  }
  if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
    *(short *)(param_1 + 0x7aa) = DAT_00804c30;
    return;
  }
  uVar5 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4));
  uVar7 = *(short *)(param_1 + 0x5a) + 0x4000;
  fVar9 = (float10)FUN_00550180(uVar5,(uint)uVar7);
  sVar4 = DAT_00804c38;
  sVar3 = DAT_00804c34;
  local_1c = (float)fVar9;
  if (local_1c <= DAT_02996ef4) {
    if (-DAT_02996ef4 <= local_1c) {
      *(short *)(param_1 + 0x7aa) = DAT_00804c30;
      return;
    }
    if ((DAT_00804c34 != -1) &&
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c34 * 4) != 0)) {
      *(short *)(param_1 + 0x7aa) = DAT_00804c34;
      fVar9 = (float10)FUN_0062f1c0(*(int *)(param_1 + 0x50),(int)sVar3);
      local_1c = ABS((float)fVar9);
      local_24 = -local_1c;
      goto LAB_0056bbce;
    }
    if (DAT_008030e4 != 0) {
      return;
    }
    local_24 = -0.5;
  }
  else {
    if ((DAT_00804c38 == -1) ||
       (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c38 * 4) == 0)) {
      if (DAT_008030e4 != 0) {
        return;
      }
      local_24 = 0.5;
      goto LAB_0056bc1f;
    }
    *(short *)(param_1 + 0x7aa) = DAT_00804c38;
    fVar9 = (float10)FUN_0062f1c0(*(int *)(param_1 + 0x50),(int)sVar4);
    local_1c = (float)fVar9;
    local_24 = ABS(local_1c);
LAB_0056bbce:
    if ((local_24 == 0.0) ||
       ((DAT_008030e4 != 0 &&
        (iVar8 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0), iVar8 == 0)))) {
      return;
    }
    if (0.0 <= local_24) goto LAB_0056bc1f;
  }
  local_20 = -local_20;
LAB_0056bc1f:
  local_c[2] = _DAT_00925018 * local_24 + local_20;
  local_c[0] = (float)(&DAT_029899a0)[uVar7 >> 1] * local_c[2];
  local_c[1] = 0.0;
  local_c[2] = local_c[2] * (float)(&DAT_029899a0)[(int)(uVar7 + 0x4000) >> 1 & 0x7fff];
  FUN_005b37d0(param_1 + 0x748,param_1 + 0x748,local_c);
  FUN_005b37d0(param_1 + 0x754,param_1 + 0x754,local_c);
  return;
}

