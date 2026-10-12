/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61c640; label: FUN_0061c640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061c640(undefined4 param_1,int param_2,undefined4 param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar5 = (int)param_4;
  uVar7 = (uint)*(byte *)((int)param_4 + 0x92);
  uVar9 = (uint)*(byte *)((int)param_4 + 0x93);
  iVar8 = uVar7 - 0x80;
  iVar10 = uVar9 - 0x80;
  DAT_02912f24 = ((int)(DAT_02912f24 - 1) < 1) - 1 & DAT_02912f24 - 1;
  DAT_02912f20 = ((int)(DAT_02912f20 - 1) < 1) - 1 & DAT_02912f20 - 1;
  if (iVar8 < 1) {
    if (iVar8 < -0x1f) {
      iVar8 = uVar7 - 0x60;
      goto LAB_0061c6bf;
    }
    param_4 = 0.0;
  }
  else if (iVar8 < 0x20) {
    param_4 = 0.0;
  }
  else {
    iVar8 = uVar7 - 0xa0;
LAB_0061c6bf:
    param_4 = (float)((iVar8 * 0xff) / 0xdf);
  }
  if (iVar10 < 1) {
    if (iVar10 < -0x1f) {
      iVar8 = uVar9 - 0x60;
      goto LAB_0061c6fa;
    }
    iVar8 = 0;
  }
  else if (iVar10 < 0x20) {
    iVar8 = 0;
  }
  else {
    iVar8 = uVar9 - 0xa0;
LAB_0061c6fa:
    iVar8 = (iVar8 * 0xff) / 0xdf;
  }
  fVar2 = *(float *)(param_2 + 0x74) + (float)(int)param_4 * 0.00012207031;
  *(float *)(param_2 + 0x74) = fVar2;
  fVar6 = *(float *)(param_2 + 0x78) + (float)-iVar8 * 0.00012207031;
  *(float *)(param_2 + 0x78) = fVar6;
  if (0.0 <= fVar2) {
    param_4 = *(float *)(param_2 + 0x74);
  }
  else {
    param_4 = 0.0;
  }
  if (param_4 <= 1.0) {
    if (0.0 <= *(float *)(param_2 + 0x74)) {
      param_4 = *(float *)(param_2 + 0x74);
    }
    else {
      param_4 = 0.0;
    }
  }
  else {
    param_4 = 1.0;
  }
  uVar3 = param_4;
  *(float *)(param_2 + 0x74) = param_4;
  if (0.0 <= fVar6) {
    param_4 = *(float *)(param_2 + 0x78);
  }
  else {
    param_4 = 0.0;
  }
  if (param_4 <= 1.0) {
    if (0.0 <= *(float *)(param_2 + 0x78)) {
      param_4 = *(float *)(param_2 + 0x78);
    }
    else {
      param_4 = 0.0;
    }
  }
  else {
    param_4 = 1.0;
  }
  *(float *)(param_2 + 0x78) = param_4;
  bVar4 = *(byte *)(iVar5 + 0x9e);
  if ((bVar4 != 0) && (*(char *)(iVar5 + 0x9f) != '\0')) {
    DAT_02912f20 = 0x3c;
    *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x44) = 0x3f800000;
    return 1;
  }
  if (0x37 < bVar4) {
    *(float *)(*(int *)(param_2 + 0x4c) + 0x44) =
         *(float *)(*(int *)(param_2 + 0x4c) + 0x44) - ((float)bVar4 * 0.02) / 255.0;
    iVar8 = *(int *)(param_2 + 0x4c);
    if (0.01 <= *(float *)(iVar8 + 0x44)) {
      fVar2 = *(float *)(iVar8 + 0x44);
    }
    else {
      fVar2 = 0.01;
    }
LAB_0061c88a:
    *(float *)(iVar8 + 0x44) = fVar2;
    DAT_02912f20 = 0x3c;
    return 1;
  }
  if (0x37 < *(byte *)(iVar5 + 0x9f)) {
    iVar8 = *(int *)(param_2 + 0x4c);
    fVar2 = ((float)*(byte *)(iVar5 + 0x9f) * 0.02) / 255.0 + *(float *)(iVar8 + 0x44);
    goto LAB_0061c88a;
  }
  bVar4 = *(byte *)(iVar5 + 0x9c);
  if (bVar4 != 0) {
    if (*(char *)(iVar5 + 0x9d) != '\0') {
      DAT_02912f24 = 0x3c;
      *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x48) = 0x3f800000;
      return 1;
    }
    if (bVar4 != 0) {
      *(float *)(*(int *)(param_2 + 0x4c) + 0x48) =
           *(float *)(*(int *)(param_2 + 0x4c) + 0x48) - ((float)bVar4 * 0.02) / 255.0;
      iVar5 = *(int *)(param_2 + 0x4c);
      if (0.01 <= *(float *)(iVar5 + 0x48)) {
        uVar3 = *(undefined4 *)(iVar5 + 0x48);
      }
      else {
        uVar3 = 0x3c23d70a;
      }
      DAT_02912f24 = 0x3c;
      *(undefined4 *)(iVar5 + 0x48) = uVar3;
      return 1;
    }
  }
  if (*(byte *)(iVar5 + 0x9d) != 0) {
    DAT_02912f24 = 0x3c;
    *(float *)(*(int *)(param_2 + 0x4c) + 0x48) =
         ((float)*(byte *)(iVar5 + 0x9d) * 0.02) / 255.0 +
         *(float *)(*(int *)(param_2 + 0x4c) + 0x48);
    return 1;
  }
  uVar7 = *(uint *)(iVar5 + 0x78);
  if (((char)uVar7 < '\0') && (-1 < *(int *)(param_2 + 0x8c))) {
    FUN_005bc4a0(*(undefined4 *)(param_2 + 0x4c),*(int *)(param_2 + 0x8c));
    FUN_005bcf50(*(undefined4 *)(param_2 + 0x4c),100);
    return 1;
  }
  if ((uVar7 & 0x20) != 0) {
    FUN_005bc3a0(*(undefined4 *)(param_2 + 0x4c),uVar3,param_4);
    FUN_005bcf50(*(undefined4 *)(param_2 + 0x4c),100);
    return 1;
  }
  if (((uVar7 & 0x40) != 0) && (iVar8 = *(int *)(param_2 + 0x8c), -1 < iVar8)) {
    *(undefined4 *)(param_2 + 0x74) = *(undefined4 *)(*(int *)(param_2 + 0x4c) + 4 + iVar8 * 4);
    *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x24 + iVar8 * 4);
  }
  if (((*(byte *)(iVar5 + 0x70) & 0x40) == 0) || (*(int *)(param_2 + 0x8c) < 0)) {
    if (((*(uint *)(iVar5 + 0x78) & 0x10) != 0) && (*(code **)(param_2 + 0x70) != (code *)0x0)) {
      (**(code **)(param_2 + 0x70))(param_1,param_2,*(uint *)(iVar5 + 0x78));
    }
    return 0;
  }
  *(undefined4 *)(*(int *)(param_2 + 0x4c) + 4 + *(int *)(param_2 + 0x8c) * 4) =
       *(undefined4 *)(param_2 + 0x74);
  *(undefined4 *)(*(int *)(param_2 + 0x4c) + 0x24 + *(int *)(param_2 + 0x8c) * 4) =
       *(undefined4 *)(param_2 + 0x78);
  iVar5 = *(int *)(param_2 + 0x8c);
  iVar8 = *(int *)(param_2 + 0x4c);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar8 + 4) = 0;
    FUN_005bcf50(*(undefined4 *)(param_2 + 0x4c),100);
    return 1;
  }
  if (iVar5 == *(char *)(iVar8 + 1) + -1) {
    *(undefined4 *)(iVar8 + 4 + iVar5 * 4) = 0x3f800000;
    FUN_005bcf50(*(undefined4 *)(param_2 + 0x4c),100);
    return 1;
  }
  pfVar1 = (float *)(iVar8 + 4 + iVar5 * 4);
  if (*(float *)(iVar8 + iVar5 * 4) < *pfVar1) {
    fVar2 = *(float *)(iVar8 + 8 + iVar5 * 4);
    if (fVar2 < *pfVar1 == (fVar2 == *pfVar1)) goto LAB_0061cafc;
    fVar2 = *(float *)(iVar8 + 8 + iVar5 * 4) - 0.01;
  }
  else {
    fVar2 = *(float *)(iVar8 + iVar5 * 4) + 0.01;
  }
  *pfVar1 = fVar2;
LAB_0061cafc:
  FUN_005bcf50(*(undefined4 *)(param_2 + 0x4c),100);
  return 1;
}

