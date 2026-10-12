/* ev_a5ce9298448d10ec34abd40a2f8730c6a9f59583676630cf85e1d90ae936d228 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f4370(int param_1)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  uint extraout_EDX;
  uint uVar7;
  float10 fVar8;
  undefined1 local_4;
  
  uVar7 = *(uint *)(param_1 + 0x10);
  uVar6 = uVar7 ^ *(uint *)(param_1 + 0x1c);
  *(uint *)(param_1 + 0x18) = uVar6 & *(uint *)(param_1 + 0x1c);
  *(uint *)(param_1 + 0x1c) = uVar7;
  piVar1 = (int *)(param_1 + 0x24);
  *piVar1 = *(byte *)(param_1 + 8) - 0x80;
  piVar2 = (int *)(param_1 + 0x28);
  *piVar2 = 0x80 - (uint)*(byte *)(param_1 + 9);
  *(uint *)(param_1 + 0x2c) = *(byte *)(param_1 + 10) - 0x80;
  *(uint *)(param_1 + 0x14) = uVar6 & uVar7;
  *(uint *)(param_1 + 0x30) = 0x80 - (uint)*(byte *)(param_1 + 0xb);
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_004f4110(*(int *)(param_1 + 0x34));
    FUN_004f4110(*(undefined4 *)(param_1 + 0x34));
    *(char *)(param_1 + 8) = *(char *)piVar1 + -0x80;
    *(char *)(param_1 + 9) = -0x80 - *(char *)piVar2;
    *(char *)(param_1 + 10) = *(char *)(param_1 + 0x2c) + -0x80;
    *(char *)(param_1 + 0xb) = -0x80 - *(char *)(param_1 + 0x30);
  }
  fVar3 = (float)*piVar1 * 0.0078125;
  *(float *)(param_1 + 0x38) = fVar3;
  fVar4 = (float)*piVar2 * 0.0078125;
  *(float *)(param_1 + 0x3c) = fVar4;
  if (0.0 < fVar3) {
    fVar3 = fVar3 - *(float *)(param_1 + 0x48);
    if (0.0 <= fVar3) {
      *(float *)(param_1 + 0x38) = fVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
  }
  fVar3 = 0.0;
  if (*(float *)(param_1 + 0x38) < 0.0) {
    fVar5 = *(float *)(param_1 + 0x48) + *(float *)(param_1 + 0x38);
    if (0.0 < fVar5) {
      fVar5 = fVar3;
    }
    *(float *)(param_1 + 0x38) = fVar5;
  }
  if (0.0 < fVar4) {
    fVar4 = fVar4 - *(float *)(param_1 + 0x4c);
    if (fVar4 < 0.0) {
      fVar4 = fVar3;
    }
    *(float *)(param_1 + 0x3c) = fVar4;
  }
  if (*(float *)(param_1 + 0x3c) < 0.0) {
    fVar4 = *(float *)(param_1 + 0x4c) + *(float *)(param_1 + 0x3c);
    if (0.0 < fVar4) {
      fVar4 = fVar3;
    }
    *(float *)(param_1 + 0x3c) = fVar4;
  }
  fVar4 = (float)*(int *)(param_1 + 0x2c) * 0.0078125;
  *(float *)(param_1 + 0x58) = fVar4;
  fVar5 = (float)*(int *)(param_1 + 0x30) * 0.0078125;
  *(float *)(param_1 + 0x5c) = fVar5;
  if (0.0 < fVar4) {
    fVar4 = fVar4 - *(float *)(param_1 + 0x50);
    if (fVar4 < 0.0) {
      fVar4 = fVar3;
    }
    *(float *)(param_1 + 0x58) = fVar4;
  }
  if (*(float *)(param_1 + 0x58) < 0.0) {
    fVar4 = *(float *)(param_1 + 0x50) + *(float *)(param_1 + 0x58);
    if (0.0 < fVar4) {
      fVar4 = fVar3;
    }
    *(float *)(param_1 + 0x58) = fVar4;
  }
  if (0.0 < fVar5) {
    fVar5 = fVar5 - *(float *)(param_1 + 0x54);
    if (fVar5 < 0.0) {
      fVar5 = fVar3;
    }
    *(float *)(param_1 + 0x5c) = fVar5;
  }
  if (*(float *)(param_1 + 0x5c) < 0.0) {
    fVar3 = *(float *)(param_1 + 0x54) + *(float *)(param_1 + 0x5c);
    if (fVar3 <= 0.0) {
      *(float *)(param_1 + 0x5c) = fVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
  }
  uVar7 = *(uint *)(param_1 + 0x20);
  if ((uVar7 & 1) == 0) {
    uVar7 = *(uint *)(param_1 + 0x10);
    fVar3 = _DAT_008004ec / 30.0;
    if ((uVar7 & 0x1000) == 0) {
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    else {
      fVar4 = *(float *)(param_1 + 0x68) + fVar3;
      if (1.0 < fVar4) {
        fVar4 = 1.0;
      }
      *(float *)(param_1 + 0x68) = fVar4;
    }
    if ((uVar7 & 0x4000) == 0) {
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
    else {
      fVar4 = *(float *)(param_1 + 0x6c) + fVar3;
      if (1.0 < fVar4) {
        fVar4 = 1.0;
      }
      *(float *)(param_1 + 0x6c) = fVar4;
    }
    if ((uVar7 & 0x8000) == 0) {
      *(undefined4 *)(param_1 + 0x70) = 0;
    }
    else {
      fVar4 = fVar3 + *(float *)(param_1 + 0x70);
      if (1.0 < fVar4) {
        fVar4 = 1.0;
      }
      *(float *)(param_1 + 0x70) = fVar4;
    }
    if ((uVar7 & 0x2000) == 0) {
      *(undefined4 *)(param_1 + 0x74) = 0;
    }
    else {
      fVar3 = fVar3 + *(float *)(param_1 + 0x74);
      if (fVar3 <= 1.0) {
        *(float *)(param_1 + 0x74) = fVar3;
      }
      else {
        *(undefined4 *)(param_1 + 0x74) = 0x3f800000;
      }
    }
    fVar8 = (float10)FUN_004f4280(*(undefined4 *)(param_1 + 0x70));
    local_4 = (undefined1)(int)ROUND(fVar8 * (float10)255.0);
    *(undefined1 *)(param_1 + 0x78) = local_4;
    fVar8 = (float10)FUN_004f4280(*(undefined4 *)(param_1 + 0x74));
    local_4 = (undefined1)(int)ROUND(fVar8 * (float10)255.0);
    *(undefined1 *)(param_1 + 0x79) = local_4;
    fVar8 = (float10)FUN_004f4280(*(undefined4 *)(param_1 + 0x68));
    local_4 = (undefined1)(int)ROUND(fVar8 * (float10)255.0);
    *(undefined1 *)(param_1 + 0x7a) = local_4;
    fVar8 = (float10)FUN_004f4280(*(undefined4 *)(param_1 + 0x6c));
    local_4 = (undefined1)(int)ROUND(fVar8 * (float10)255.0);
    uVar7 = extraout_EDX;
  }
  else {
    *(undefined1 *)(param_1 + 0x78) = *(undefined1 *)(param_1 + 0x7c);
    *(undefined1 *)(param_1 + 0x79) = *(undefined1 *)(param_1 + 0x7d);
    local_4 = *(undefined1 *)(param_1 + 0x7f);
    *(undefined1 *)(param_1 + 0x7a) = *(undefined1 *)(param_1 + 0x7e);
  }
  *(undefined1 *)(param_1 + 0x7b) = local_4;
  if ((uVar7 & 2) == 0) {
    *(undefined1 *)(param_1 + 0x82) = 0x7f;
    *(undefined1 *)(param_1 + 0x83) = 0x7f;
    return;
  }
  *(undefined1 *)(param_1 + 0x82) = *(undefined1 *)(param_1 + 0x80);
  *(undefined1 *)(param_1 + 0x83) = *(undefined1 *)(param_1 + 0x81);
  return;
}

