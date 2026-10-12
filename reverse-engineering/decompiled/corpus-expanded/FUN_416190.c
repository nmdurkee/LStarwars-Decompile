/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x416190; label: FUN_00416190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00416190(float param_1)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  byte bVar13;
  bool bVar14;
  float10 fVar15;
  float local_2c;
  float local_24 [2];
  float local_1c;
  float local_18;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar6 = (int)param_1;
  piVar4 = *(int **)((int)param_1 + 0xca4);
  iVar9 = *piVar4;
  *(uint *)((int)param_1 + 0xe20) = *(uint *)((int)param_1 + 0xe20) & 0xffdfffff;
  bVar13 = 0;
  if (iVar9 == 0) {
    bVar3 = 0;
  }
  else {
    bVar3 = *(byte *)(iVar9 + 0x93);
    bVar13 = *(byte *)(iVar9 + 0x92);
  }
  if ((float)piVar4[0xe] != (float)piVar4[10]) {
    *(ushort *)((int)piVar4 + 0x5a) = *(ushort *)((int)piVar4 + 0x5a) | 0x40;
  }
  *(undefined4 *)((int)param_1 + 0x218) = *(undefined4 *)((int)param_1 + 0x21c);
  *(undefined4 *)((int)param_1 + 0x8c) = *(undefined4 *)((int)param_1 + 0x5c);
  *(undefined4 *)((int)param_1 + 0x90) = *(undefined4 *)((int)param_1 + 0x60);
  *(undefined4 *)((int)param_1 + 0x98) = *(undefined4 *)((int)param_1 + 0x80);
  *(undefined4 *)((int)param_1 + 0x94) = *(undefined4 *)((int)param_1 + 100);
  *(undefined4 *)((int)param_1 + 0x9c) = *(undefined4 *)((int)param_1 + 0x84);
  *(undefined4 *)((int)param_1 + 0xa0) = *(undefined4 *)((int)param_1 + 0x88);
  *(undefined1 *)((int)param_1 + 0x282) = *(undefined1 *)((int)param_1 + 0x281);
  piVar4[0xe] = piVar4[10];
  *(undefined2 *)(piVar4 + 0x16) = *(undefined2 *)((int)piVar4 + 0x26);
  *(uint *)((int)param_1 + 0xef0) = *(uint *)((int)param_1 + 0xef0) & 0xffffbfff;
  *(undefined2 *)((int)param_1 + 0x1060) = *(undefined2 *)((int)param_1 + 0x27a);
  if (*(char *)((int)param_1 + 0x288) == '\0') {
    *(float *)((int)param_1 + 0xf10) = *(float *)((int)param_1 + 0xf10) + _DAT_00925018;
  }
  else {
    *(undefined4 *)((int)param_1 + 0xf10) = 0;
  }
  if (*(char *)((int)param_1 + 0x7b5) == '+') {
    *(float *)((int)param_1 + 0xd98) = _DAT_00925018 + *(float *)((int)param_1 + 0xd98);
  }
  if ((*(uint *)((int)param_1 + 0xef4) & 0x4000000) != 0) {
    FUN_0062b040(param_1);
    FUN_0055d2b0(param_1);
    return;
  }
  if (*(char *)((int)param_1 + 0x28b) != '\0') {
    return;
  }
  *(ushort *)((int)piVar4 + 0x5a) = *(ushort *)((int)piVar4 + 0x5a) & 0xfff7;
  piVar4[0xf] = 0;
  *(uint *)((int)param_1 + 0xef0) = *(uint *)((int)param_1 + 0xef0) & 0xfffffbff;
  *(undefined2 *)((int)param_1 + 0x106e) = 0xffff;
  iVar9 = FUN_00574e20();
  if (((*(uint *)((int)param_1 + 0x1fc) & 0x80) == 0) ||
     ((*(uint *)((int)param_1 + 0x1fc) & 0x100) != 0)) {
    if ((*(byte *)((int)param_1 + 0xef0) & 0x10) == 0) {
      if (*(char *)((int)param_1 + 0x408) == '\x01') {
        piVar4[10] = 0;
        piVar4[0xb] = 0;
        piVar4[0xc] = 0;
      }
      else {
        if ((*(char *)((int)param_1 + 0x7b5) == '\x17') &&
           ((*(byte *)((int)param_1 + 0xef8) & 1) == 0)) {
          piVar4[10] = 0;
          goto LAB_00416853;
        }
        local_18 = *(float *)((int)param_1 + 0x3dc) - *(float *)((int)param_1 + 0x5c);
        local_10 = *(float *)((int)param_1 + 0x3e4) - *(float *)((int)param_1 + 100);
        if ((local_18 == 0.0) && (local_10 == 0.0)) {
          *(undefined2 *)((int)piVar4 + 0x26) = 0;
          piVar4[10] = 0;
          piVar4[0xb] = 0;
          piVar4[0xc] = 0;
        }
        else {
          fVar15 = (float10)FUN_005c0240(local_18 * local_18 + local_10 * local_10);
          fVar1 = (float)fVar15 / _DAT_00801c6c;
          piVar4[10] = (int)fVar1;
          if (1.0 < fVar1) {
            piVar4[10] = 0x3f800000;
          }
          fVar1 = 1.0 / (float)fVar15;
          piVar4[0xc] = (int)(fVar1 * local_18);
          fVar1 = fVar1 * local_10;
          piVar4[0xb] = (int)fVar1;
          uVar8 = FUN_005be2d0(piVar4[0xc],fVar1);
          *(undefined2 *)((int)piVar4 + 0x26) = uVar8;
          uVar8 = FUN_005be5b0(uVar8,*(undefined4 *)(PTR_DAT_008021b4 + 0x1fc));
          *(undefined2 *)((int)piVar4 + 0x26) = uVar8;
        }
      }
      *(undefined1 *)((int)piVar4 + 0x25) = 1;
    }
    else {
      piVar4[10] = 0;
      *(undefined4 *)(*(int *)((int)param_1 + 0xca4) + 4) = 0;
      *(undefined4 *)(*(int *)((int)param_1 + 0xca4) + 8) = 0;
    }
LAB_00416853:
    if (*(int *)((int)param_1 + 0xeac) == 0) {
      if (*(float *)((int)param_1 + 0xed4) == 1e+09) {
        fVar1 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x1c);
      }
      else {
        fVar1 = *(float *)((int)param_1 + 0xed4);
      }
      if (*(float *)((int)param_1 + 0xed8) == 1e+09) {
        fVar2 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x18);
      }
      else {
        fVar2 = *(float *)((int)param_1 + 0xed8);
      }
      if ((*(uint *)((int)param_1 + 0x4b0) & 0x40000) == 0) {
        piVar4[10] = (int)((float)piVar4[10] * fVar1);
      }
      else {
        piVar4[10] = 0;
      }
      if (((*(uint *)((int)param_1 + 0x4b0) & 0x80000) == 0) &&
         ((float)piVar4[10] <
          *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x14) * 0.5)) {
        piVar4[10] = 0;
      }
      if (((*(byte *)((int)param_1 + 0x4b0) & 8) == 0) &&
         (cVar7 = *(char *)((int)param_1 + 0x407), cVar7 != '\0')) {
        if (cVar7 == '\x01') {
          if (fVar2 < (float)piVar4[10]) {
            piVar4[10] = (int)fVar2;
          }
        }
        else if ((cVar7 == '\x02') &&
                (iVar10 = *(int *)(*(int *)((int)param_1 + 0x54) + 0x24),
                *(float *)(iVar10 + 0x14) < (float)piVar4[10])) {
          piVar4[10] = *(int *)(iVar10 + 0x14);
        }
      }
      if (((((*(uint *)((int)param_1 + 0x1f8) & 0x400) == 0) &&
           ((*(uint *)((int)param_1 + 0xeec) & 0x2000000) == 0)) &&
          ((_DAT_007f6738 < *(float *)((int)param_1 + 0xf10) !=
            (_DAT_007f6738 == *(float *)((int)param_1 + 0xf10)) ||
           (((*(char *)((int)param_1 + 0x288) == '\0' &&
             ((*(byte *)((int)param_1 + 0x7c5) & 2) == 0)) && (0.0 < _DAT_00876ce4)))))) &&
         ((fVar2 <= (float)piVar4[10] + 0.001 || (*(short *)((int)param_1 + 0x1064) == DAT_007f1948)
          ))) {
        *(uint *)((int)param_1 + 0xef0) = *(uint *)((int)param_1 + 0xef0) | 0x400;
      }
    }
    else {
      piVar4[10] = 0;
    }
    *(undefined4 *)(*(int *)((int)param_1 + 0xca4) + 0x54) = *(undefined4 *)((int)param_1 + 0x4ac);
    goto LAB_004169d4;
  }
  if (((0.0 < _DAT_00950780) || (DAT_0087b738 != 0)) ||
     ((DAT_00855de0 == 2 || ((iVar9 != -1 && (iVar9 != 0xe)))))) {
    *(undefined1 *)((int)piVar4 + 0x25) = 1;
    piVar4[10] = 0;
    piVar4[0xb] = 0;
    piVar4[0xc] = 0;
    local_24[0] = 0.0;
    local_1c = 0.0;
    goto LAB_004169d4;
  }
  iVar10 = FUN_0040aa60();
  if (*(int *)((int)param_1 + 0xca4) == iVar10) {
    piVar4[10] = 0;
    goto LAB_004169d4;
  }
  uVar5 = piVar4[1];
  if ((uVar5 & (DAT_0080229c | DAT_00802298 | DAT_00802294 | DAT_00802290)) == 0) {
    param_1 = (float)bVar13 - 127.5;
    local_2c = -((float)bVar3 - 127.5);
    if (1806.25 <= param_1 * param_1 + local_2c * local_2c) {
      if (param_1 == 0.0) {
        if (local_2c != 0.0) {
          *(undefined1 *)((int)piVar4 + 0x25) = 2;
        }
      }
      else {
        *(undefined1 *)((int)piVar4 + 0x25) = 2;
      }
    }
    else {
      param_1 = 0.0;
      local_2c = 0.0;
    }
  }
  else {
    if ((DAT_00802298 & uVar5) == 0) {
      if ((DAT_0080229c & uVar5) == 0) {
        param_1 = 0.0;
      }
      else {
        param_1 = 127.5;
      }
    }
    else {
      param_1 = -127.5;
    }
    if ((DAT_00802294 & uVar5) == 0) {
      if ((DAT_00802290 & uVar5) == 0) {
        local_2c = 0.0;
      }
      else {
        local_2c = 127.5;
      }
    }
    else {
      local_2c = -127.5;
    }
    if (param_1 == 0.0) {
      if (local_2c != 0.0) {
        *(undefined1 *)((int)piVar4 + 0x25) = 1;
      }
    }
    else {
      *(undefined1 *)((int)piVar4 + 0x25) = 1;
    }
  }
  local_24[0] = param_1 * 0.007843138;
  local_1c = local_2c * 0.007843138;
  uVar11 = FUN_005be2d0(local_24[0],local_1c);
  local_8 = 0;
  local_c = 0;
  local_4 = local_1c;
  if (ABS(local_1c) < ABS(local_24[0])) {
    local_4 = local_24[0];
  }
  local_4 = ABS(local_4);
  FUN_005b3620(local_24,&local_c,uVar11);
  fVar15 = (float10)FUN_005c0240(local_1c * local_1c + local_24[0] * local_24[0]);
  fVar1 = (float)fVar15;
  if (iVar6 == DAT_0093d7f0) {
    iVar10 = 0;
LAB_0041657d:
    uVar8 = (&DAT_009253a8)[iVar10];
    (&DAT_00926bb8)[iVar10] = (&DAT_00926bc4)[iVar10];
    (&DAT_00926bc0)[iVar10] = uVar8;
    (&DAT_00926bc4)[iVar10] = piVar4[10];
    (&DAT_009253a8)[iVar10] = *(undefined2 *)((int)piVar4 + 0x26);
  }
  else if (iVar6 == DAT_0093d7f4) {
    iVar10 = 1;
    goto LAB_0041657d;
  }
  if (0.2 <= fVar1) {
    iVar10 = *(int *)(iVar6 + 0x54);
    if ((*(byte *)(iVar10 + 4) & 0x20) == 0) {
LAB_004165ff:
      if ((0.5 <= fVar1) || ((*(byte *)(*(int *)(iVar10 + 0x24) + 0x90) & 8) != 0)) {
        if (0.8 <= fVar1) {
          iVar10 = *(int *)(*(int *)(iVar10 + 0x24) + 0x1c);
        }
        else {
          iVar10 = *(int *)(*(int *)(iVar10 + 0x24) + 0x18);
        }
      }
      else {
        iVar10 = *(int *)(*(int *)(iVar10 + 0x24) + 0x14);
      }
    }
    else {
      if (*(char *)(iVar6 + 0x280) == -1) {
LAB_004165ed:
        if ('\x02' < *(char *)(iVar6 + 0x107f)) goto LAB_004165ff;
      }
      else if (2 < *(byte *)(iVar6 + 0xe39)) {
        if (*(char *)(iVar6 + 0x280) != -1) goto LAB_004165ff;
        goto LAB_004165ed;
      }
      iVar10 = *(int *)(*(int *)(iVar10 + 0x24) + 0x18);
    }
  }
  else {
    iVar10 = 0;
  }
  piVar4[10] = iVar10;
  piVar4[0xb] = (int)local_24[0];
  piVar4[0xc] = (int)local_1c;
  if (0.0 < (float)piVar4[10]) {
    uVar8 = FUN_005be2d0(piVar4[0xb],local_1c);
    *(undefined2 *)((int)piVar4 + 0x26) = uVar8;
  }
  cVar7 = FUN_0054a770(*(undefined4 *)(iVar6 + 0xca4));
  *(ushort *)((int)piVar4 + 0x5a) =
       *(ushort *)((int)piVar4 + 0x5a) ^ (byte)(cVar7 * '\b' ^ *(byte *)((int)piVar4 + 0x5a)) & 8;
  if ((iVar6 == DAT_0093d7f0) || (iVar6 == DAT_0093d7f4)) {
    fVar15 = (float10)FUN_0054a690(iVar6);
    piVar4[0xf] = (int)(float)fVar15;
  }
  else {
    piVar4[0xf] = 0;
  }
LAB_004169d4:
  if ((((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0) && (iVar9 == 0xe)) &&
     ((iVar6 == DAT_0093d7f0 || (iVar6 == DAT_0093d7f4)))) {
    bVar14 = iVar6 != DAT_0093d7f0;
    *(int *)(&DAT_00879b04 + (uint)bVar14 * 4) = piVar4[10];
    (&DAT_008794e8)[bVar14] = *(undefined2 *)((int)piVar4 + 0x26);
    piVar4[10] = 0;
    *(undefined1 *)((int)piVar4 + 0x25) = 1;
    piVar4[0xb] = 0;
    piVar4[0xc] = 0;
  }
  if (0.0 < (float)piVar4[10]) {
    piVar4[0xd] = piVar4[10];
  }
  if ((*(char *)(iVar6 + 0x7b5) != ';') && (*(char *)(iVar6 + 0x7b5) != '9')) {
    *(undefined1 *)(iVar6 + 0x107a) = 2;
    FUN_0058b440(iVar6);
    if (*(short *)(iVar6 + 0x1064) == DAT_007f191c) {
      FUN_0049a5f0();
    }
    else {
      iVar10 = FUN_004b08d0(iVar6);
      if ((((iVar10 == 0) && (iVar10 = FUN_0049a260(iVar6), iVar10 == 0)) &&
          (iVar10 = FUN_00499e20(iVar6), iVar10 == 0)) &&
         (iVar10 = FUN_0049a8f0(iVar6), iVar10 == 0)) {
        if ((*(uint *)(*(int *)(iVar6 + 0x54) + 4) & 0x2000) == 0) {
          FUN_004ac620(iVar6);
        }
        else {
          FUN_004af0c0();
        }
      }
    }
    if (((((DAT_0093d830 != 0) && (iVar9 == -1)) &&
         ((*(char *)(iVar6 + 0x28b) == '\0' &&
          ((*(char *)(iVar6 + 0x7b5) != '+' &&
           ((*(byte *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x90) & 0x80) == 0)))))) &&
        ((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0)) &&
       (((piVar4[1] & DAT_008022c0) != 0 && (piVar12 = (int *)FUN_0040aa60(), piVar4 != piVar12))))
    {
      if ((*(char *)(iVar6 + 0x7b5) == 'Q') &&
         (((iVar9 = *(int *)(iVar6 + 0x798), iVar9 != 0 && (*(char *)(iVar9 + 0x37) == '\x01')) &&
          (*(int *)(iVar9 + 0x6c) != 0)))) {
        *(float *)(*(int *)(iVar9 + 0x6c) + 0x60) =
             _DAT_00925018 * 1.5 + *(float *)(*(int *)(iVar9 + 0x6c) + 0x60);
        *(undefined4 *)(*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) + 0x6c) = 0;
        *(undefined1 *)(*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) + 0x281) = 0;
        *(undefined2 *)(*(int *)(*(int *)(iVar6 + 0x798) + 0x6c) + 0x1050) = 0;
        iVar9 = *(int *)(*(int *)(iVar6 + 0x798) + 0x6c);
        if (*(char *)(iVar9 + 0x7b5) == '3') {
          *(undefined1 *)(iVar9 + 0x7b5) = 0xff;
        }
      }
      else {
        fVar1 = _DAT_00925018 * 1.5;
        *(undefined1 *)(iVar6 + 0x281) = 0;
        *(undefined2 *)(iVar6 + 0x1050) = 0;
        *(float *)(iVar6 + 0x60) = fVar1 + *(float *)(iVar6 + 0x60);
        *(undefined4 *)(iVar6 + 0x6c) = 0;
        if (*(char *)(iVar6 + 0x7b5) == '3') {
          *(undefined1 *)(iVar6 + 0x7b5) = 0xff;
        }
      }
    }
    *(uint *)(iVar6 + 0x1fc) = *(uint *)(iVar6 + 0x1fc) | 0x10000;
    *(undefined4 *)(iVar6 + 0x74) = *(undefined4 *)(iVar6 + 0x68);
    *(undefined4 *)(iVar6 + 0x78) = *(undefined4 *)(iVar6 + 0x6c);
    *(undefined4 *)(iVar6 + 0x7c) = *(undefined4 *)(iVar6 + 0x70);
    FUN_0062b040(iVar6);
    FUN_0055d2b0(iVar6);
    return;
  }
  return;
}

