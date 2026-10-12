/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66a190; label: FUN_0066a190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066a190(int param_1,int param_2,undefined1 param_3)

{
  float fVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  float *pfVar10;
  undefined2 in_FPUControlWord;
  float10 fVar11;
  int local_1c;
  float local_18;
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1c;
  FUN_006216f0(param_1,0x10);
  *(undefined1 *)(param_1 + 0x10) = param_3;
  sVar3 = FUN_00621860();
  if (param_2 < 0x1c) {
    if (sVar3 < 1) {
      if (sVar3 < 0) {
        sVar3 = (short)(-0x3c / (longlong)(int)sVar3);
        goto LAB_0066a1f0;
      }
      *(undefined2 *)(param_1 + 0x16) = 0;
    }
    else {
      *(short *)(param_1 + 0x16) = sVar3 * 0x3c;
    }
  }
  else {
LAB_0066a1f0:
    *(short *)(param_1 + 0x16) = sVar3;
  }
  uVar4 = FUN_00621860();
  *(undefined2 *)(param_1 + 0x14) = uVar4;
  if (param_2 < 0x1c) {
    sVar3 = FUN_00621860();
    local_1c = (int)sVar3;
    *(float *)(param_1 + 0x18) = (float)local_1c / 60.0;
    sVar3 = FUN_00621860();
    local_1c = (int)sVar3;
    *(float *)(param_1 + 0x1c) = (float)local_1c / 60.0;
    sVar3 = FUN_00621860();
    local_1c = (int)sVar3;
    *(float *)(param_1 + 0x20) = (float)local_1c / 60.0;
    sVar3 = FUN_00621860();
    local_1c = (int)sVar3;
    *(float *)(param_1 + 0x24) = (float)local_1c / 60.0;
    sVar3 = FUN_00621860();
    fVar11 = (float10)(int)sVar3 / (float10)60.0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x18) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x1c) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x20) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x24) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  local_1c = (int)*(short *)(param_1 + 0x16);
  *(float *)(param_1 + 0x28) = (float)fVar11;
  if (((float)local_1c != 0.0) &&
     (fVar1 = 1.0 / (float)local_1c, *(float *)(param_1 + 0x1c) < fVar1)) {
    *(float *)(param_1 + 0x1c) = fVar1;
  }
  uVar2 = FUN_006218c0();
  *(undefined1 *)(param_1 + 0x2c) = uVar2;
  uVar2 = FUN_006218c0();
  *(undefined1 *)(param_1 + 0x2d) = uVar2;
  if (param_2 < 0x23) {
    *(undefined1 *)(param_1 + 0x12) = 0;
  }
  else {
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x12) = uVar2;
  }
  *(undefined1 *)(param_1 + 0x13) = 0;
  uVar2 = FUN_006218c0();
  *(undefined1 *)(param_1 + 0x2e) = uVar2;
  if (param_2 < 0x27) {
    FUN_006218c0();
  }
  *(undefined1 *)(param_1 + 0x2f) = 1;
  if (param_2 < 0x28) {
    *(undefined1 *)(param_1 + 0x412) = 0;
  }
  else {
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x412) = uVar2;
  }
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x30) = (float)fVar11;
  if (param_2 < 6) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    fVar11 = (float10)25.0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x34) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x38) = (float)fVar11;
  if (param_2 < 10) {
    fVar11 = (float10)0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x3c) = (float)fVar11;
  if (param_2 < 0x17) {
    fVar11 = (float10)0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x40) = (float)fVar11;
  if (param_2 < 0x18) {
    fVar11 = (float10)0.5;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x44) = (float)fVar11;
  if (param_2 < 7) {
    FUN_006217e0();
    FUN_006217e0();
  }
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x48) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x4c) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x50) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x54) = (float)fVar11;
  if (param_2 < 0x12) {
    FUN_006217a0();
    FUN_006217a0();
    FUN_006217a0();
  }
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x58) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x5c) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x60) = (float)fVar11;
  if (param_2 < 0x12) {
    FUN_006217a0();
    FUN_006217a0();
    FUN_006217a0();
  }
  if (((param_2 == 0x12) || (param_2 == 0x13)) && (*(char *)(param_1 + 0x2c) == '\x06')) {
    *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x54) * 2.0;
    *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) * 2.0;
  }
  if (param_2 < 0x1d) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 100) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x68) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x6c) = (float)fVar11;
  }
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x70) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x74) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x78) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x7c) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x80) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x84) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x88) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x8c) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x90) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x94) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x98) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x9c) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xa0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xa4) = (float)fVar11;
  uVar4 = FUN_00621860();
  *(undefined2 *)(param_1 + 0xa8) = uVar4;
  uVar2 = FUN_006218c0();
  *(undefined1 *)(param_1 + 0xaa) = uVar2;
  uVar2 = FUN_006218c0();
  *(undefined1 *)(param_1 + 0xab) = uVar2;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xac) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xb0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xb4) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xb8) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0xbc) = (float)fVar11;
  puVar9 = (undefined1 *)(param_1 + 0xc4);
  iVar8 = 8;
  if (param_2 < 0x21) {
    do {
      fVar11 = (float10)FUN_006217a0();
      *(float *)(puVar9 + -4) = (float)fVar11;
      fVar11 = (float10)FUN_006217a0();
      local_18 = (float)(int)ROUND(fVar11);
      *puVar9 = local_18._0_1_;
      fVar11 = (float10)FUN_006217a0();
      local_18 = (float)(int)ROUND(fVar11);
      puVar9[1] = local_18._0_1_;
      fVar11 = (float10)FUN_006217a0();
      local_1c = CONCAT22(local_1c._2_2_,in_FPUControlWord);
      iVar8 = iVar8 + -1;
      local_18 = (float)(int)ROUND(fVar11);
      puVar9[2] = local_18._0_1_;
      puVar9 = puVar9 + 8;
    } while (iVar8 != 0);
  }
  else {
    do {
      fVar11 = (float10)FUN_006217a0();
      *(float *)(puVar9 + -4) = (float)fVar11;
      uVar2 = FUN_006218e0();
      *puVar9 = uVar2;
      uVar2 = FUN_006218e0();
      puVar9[1] = uVar2;
      uVar2 = FUN_006218e0();
      puVar9[2] = uVar2;
      uVar2 = FUN_006218e0();
      puVar9[3] = uVar2;
      puVar9 = puVar9 + 8;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  pfVar10 = (float *)(param_1 + 0x104);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (param_2 < 0x15) {
    fVar11 = (float10)0.125;
    *(float *)(param_1 + 0x140) = (float)fVar11;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x140) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x144) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x148) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x14c) = (float)fVar11;
  pfVar10 = (float *)(param_1 + 0x154);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  pfVar10 = (float *)(param_1 + 0x194);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x1d0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x1d4) = (float)fVar11;
  pfVar10 = (float *)(param_1 + 0x1dc);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  pfVar10 = (float *)(param_1 + 0x21c);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  pfVar10 = (float *)(param_1 + 0x25c);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x298) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x29c) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x2a0) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x2a4) = (float)fVar11;
  if (param_2 < 3) {
    *(undefined1 *)(param_1 + 0x2f0) = 0;
  }
  else {
    pfVar10 = (float *)(param_1 + 0x2b4);
    iVar8 = 8;
    do {
      fVar11 = (float10)FUN_006217a0();
      pfVar10[-1] = (float)fVar11;
      fVar11 = (float10)FUN_006217a0();
      *pfVar10 = (float)fVar11;
      pfVar10 = pfVar10 + 2;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x2f0) = uVar2;
  }
  if (param_2 < 0x11) {
    *(undefined1 *)(param_1 + 0x2f1) = 0;
  }
  else {
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x2f1) = uVar2;
  }
  if (*(char *)(param_1 + 0x2e) == '\a') {
    *(undefined1 *)(param_1 + 0x2f1) = 2;
  }
  if (param_2 < 0x1f) {
    *(undefined1 *)(param_1 + 0x2f2) = 3;
  }
  else {
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x2f2) = uVar2;
  }
  fVar11 = (float10)1;
  if (param_2 < 0x20) {
    *(float *)(param_1 + 0x2f8) = (float)fVar11;
    *(undefined1 *)(param_1 + 0x2f3) = 0;
    *(float *)(param_1 + 0x2fc) = (float)fVar11;
  }
  else {
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x2f3) = uVar2;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x2f8) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x2fc) = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x300) = (float)fVar11;
  if (param_2 < 0x24) {
    *(undefined4 *)(param_1 + 0x2f4) = 0x40800000;
LAB_0066a888:
    if (param_2 < 0x1e) {
      *(undefined4 *)(param_1 + 0x304) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x308) = 0x3dcccccd;
      *(undefined4 *)(param_1 + 0x30c) = 0;
      *(undefined4 *)(param_1 + 0x310) = 0;
      *(undefined4 *)(param_1 + 0x314) = 0;
      *(undefined4 *)(param_1 + 0x350) = 0;
      *(undefined4 *)(param_1 + 0x354) = 0;
      *(undefined4 *)(param_1 + 0x390) = 0;
      *(undefined4 *)(param_1 + 0x394) = 0;
      *(undefined4 *)(param_1 + 0x318) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x31c) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x358) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x35c) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x398) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x39c) = 0x3f800000;
      goto LAB_0066a8f7;
    }
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    local_18 = (float)fVar11;
    *(float *)(param_1 + 0x2f4) = local_18;
    if (param_2 != 0x24) goto LAB_0066a888;
    if (local_18 < 4.0) {
      *(undefined4 *)(param_1 + 0x2f4) = 0x40800000;
    }
  }
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x304) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x308) = (float)fVar11;
  fVar11 = (float10)FUN_006217a0();
  *(float *)(param_1 + 0x30c) = (float)fVar11;
  pfVar10 = (float *)(param_1 + 0x314);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  pfVar10 = (float *)(param_1 + 0x354);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  pfVar10 = (float *)(param_1 + 0x394);
  iVar8 = 8;
  do {
    fVar11 = (float10)FUN_006217a0();
    pfVar10[-1] = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
    *pfVar10 = (float)fVar11;
    pfVar10 = pfVar10 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
LAB_0066a8f7:
  *(undefined4 *)(param_1 + 0x3d0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3d4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3d8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3dc) = 0xffffffff;
  if (param_2 < 0x17) {
    puVar6 = (undefined4 *)(param_1 + 0x3e4);
    iVar8 = 4;
    do {
      if (param_2 < 0xb) {
        puVar6[-1] = 0xffffffff;
        *puVar6 = 0;
        puVar6[1] = 0;
      }
      else {
        uVar5 = FUN_006217e0();
        puVar6[-1] = uVar5;
        uVar5 = FUN_006217e0();
        *puVar6 = uVar5;
        uVar5 = FUN_006217e0();
        puVar6[1] = uVar5;
      }
      puVar6 = puVar6 + 3;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  else {
    iVar8 = FUN_006217e0();
    if (0 < iVar8) {
      puVar6 = (undefined4 *)(param_1 + 0x3e4);
      iVar7 = iVar8;
      do {
        FUN_006216f0(local_14,0x10);
        uVar5 = FUN_00650e40(local_14,0x10);
        puVar6[-1] = uVar5;
        uVar5 = FUN_006217e0();
        *puVar6 = uVar5;
        uVar5 = FUN_006217e0();
        puVar6[1] = uVar5;
        puVar6 = puVar6 + 3;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (iVar8 < 4) {
      puVar6 = (undefined4 *)(param_1 + 0x3e0 + iVar8 * 0xc);
      iVar8 = 4 - iVar8;
      do {
        *puVar6 = 0xffffffff;
        puVar6 = puVar6 + 3;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  if (param_2 < 0x10) {
    *(undefined4 *)(param_1 + 0x414) = 0;
    *(undefined1 *)(param_1 + 0x410) = 0;
  }
  else {
    if (param_2 < 0x29) {
      uVar2 = FUN_006217e0();
    }
    else {
      uVar2 = FUN_006218c0();
    }
    *(undefined1 *)(param_1 + 0x410) = uVar2;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x414) = (float)fVar11;
  }
  if (param_2 < 0x19) {
    *(undefined1 *)(param_1 + 0x411) = 5;
    *(undefined4 *)(param_1 + 0x41c) = 0x3f000000;
  }
  else {
    if (param_2 < 0x29) {
      uVar2 = FUN_006217e0();
    }
    else {
      uVar2 = FUN_006218c0();
    }
    *(undefined1 *)(param_1 + 0x411) = uVar2;
    fVar11 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x41c) = (float)fVar11;
  }
  fVar11 = (float10)0;
  if (0x19 < param_2) {
    fVar11 = (float10)FUN_006217a0();
  }
  *(float *)(param_1 + 0x418) = (float)fVar11;
  *(undefined4 *)(param_1 + 0x420) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x424) = 0;
  __security_check_cookie(local_4 ^ (uint)&local_1c);
  return;
}

