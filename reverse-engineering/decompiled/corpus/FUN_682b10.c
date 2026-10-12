/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x682b10; label: FUN_00682b10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00682b10(uint *param_1,undefined4 param_2,uint *param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7,int param_8,int param_9)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if (DAT_02962070 == 0) {
    DAT_008108e8 = param_6;
    DAT_008108ec = param_7;
  }
  DAT_02962078 = 1;
  DAT_02962094 = param_8;
  DAT_02962098 = param_9;
  _DAT_0296207c = 1;
  FUN_004f4040(&LAB_00657dd0);
  DAT_02947d94 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = DAT_02947d94;
  *param_1 = *param_1 + (DAT_008108ec + DAT_008108e8) * 0x58;
  DAT_02923198 = *param_1;
  *param_1 = *param_1 + (DAT_008108ec + DAT_008108e8) * 8;
  DAT_02921200 = *param_1;
  *param_1 = *param_1 + DAT_008108e8 * 4;
  DAT_029211fc = *param_1;
  *param_1 = *param_1 + DAT_008108ec * 4;
  DAT_02961fec = *param_1;
  DAT_029620a4 = (void *)((DAT_008108ec + DAT_008108e8) * 100 + 0xf + *param_1 & 0xfffffff0);
  *param_1 = (uint)DAT_029620a4;
  *param_1 = *param_1 + DAT_02962094 * 0x330;
  DAT_02962084 = (void *)*param_1;
  *param_1 = *param_1 + DAT_02962094 * 2;
  DAT_029620a0 = (undefined4 *)*param_1;
  *param_1 = *param_1 + DAT_02962098 * 0x428;
  DAT_0296209c = (int *)*param_1;
  *param_1 = *param_1 + DAT_02962098 * 4;
  DAT_02962090 = *param_1;
  *param_1 = *param_1 + DAT_008108fc * 4;
  DAT_0292fdc4 = *param_1;
  *param_1 = *param_1 + DAT_02962094 * 8;
  DAT_02961fe4 = *param_1;
  *param_1 = *param_1 + DAT_02962094 * 8;
  DAT_029620ac = (void *)*param_1;
  *param_1 = *param_1 + DAT_008108f8 * 0xc;
  _memset(DAT_02962084,0,DAT_02962094 * 2);
  _memset(DAT_029620a4,0,DAT_02962094 * 0x330);
  _memset(DAT_029620a0,0,DAT_02962098 * 0x428);
  _memset(DAT_0296209c,0,DAT_02962098 * 4);
  _memset(DAT_029620ac,0,DAT_008108f8 * 4);
  iVar3 = 0;
  if (0 < DAT_02962094) {
    do {
      *(int *)(DAT_0292fdc4 + iVar3 * 8) = iVar3;
      *(undefined4 *)(DAT_0292fdc4 + 4 + iVar3 * 8) = 3;
      *(int *)(DAT_02961fe4 + iVar3 * 8) = iVar3;
      *(undefined4 *)(DAT_02961fe4 + 4 + iVar3 * 8) = 3;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_02962094);
  }
  puVar4 = &DAT_008104b8;
  puVar6 = DAT_029620a0;
  for (iVar3 = 0x10a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  *DAT_0296209c = (int)DAT_029620a0;
  DAT_0292fd0c = DAT_02962094;
  DAT_02920aac = DAT_02962094;
  DAT_02962a24 = 1;
  DAT_0292fd4c = FUN_00546fd0(param_1,param_2,param_5,1,2,0x100,0);
  uVar1 = *(undefined2 *)(DAT_0292fd4c + 0x74);
  *(uint *)(DAT_0292fd4c + 0x40) = *(uint *)(DAT_0292fd4c + 0x40) & 0xffff7fff | 0x4000;
  *(uint *)(DAT_0292fd4c + 0x40) = *(uint *)(DAT_0292fd4c + 0x40) & 0xff9fffff | 0x100000;
  FUN_005e4b00(DAT_0292fd4c);
  param_8 = DAT_0292fd4c;
  if (DAT_0292fd4c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005e4d40(1);
    *(undefined4 *)(iVar3 + 0x54) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x58) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x5c) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x70) = 0x3f7fbe77;
    *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffe5c0 | 0xe500;
    *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_8 + 0x74);
    *(undefined2 *)(iVar3 + 0x76) = *(undefined2 *)(param_8 + 0x76);
    *(uint *)(iVar3 + 0x44) = *(uint *)(iVar3 + 0x44) & 0xfffffffd | 1;
    FUN_005e4b00(iVar3);
  }
  DAT_0292fd50 = iVar3;
  DAT_0292fd54 = FUN_00654a90(DAT_0292fd4c,1,1,1,1);
  DAT_0292fd58 = FUN_00654a90(DAT_0292fd4c,1,3,1,1);
  param_8 = DAT_0292fd4c;
  if (DAT_0292fd4c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005e4d40(1);
    *(undefined4 *)(iVar3 + 0x54) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x58) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x5c) = 0x3f800000;
    *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffff65d1 | 0x6511;
    *(undefined4 *)(iVar3 + 0x70) = 0x3f7fbe77;
    *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_8 + 0x74);
    *(undefined2 *)(iVar3 + 0x76) = *(undefined2 *)(param_8 + 0x76);
    *(uint *)(iVar3 + 0x44) = *(uint *)(iVar3 + 0x44) & 0xfffffffd | 1;
    FUN_005e4b00(iVar3);
  }
  param_8 = DAT_0292fd4c;
  DAT_0292fd5c = iVar3;
  if (DAT_0292fd4c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005e4d40(1);
    *(undefined4 *)(iVar3 + 0x54) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x58) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x5c) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x70) = 0x3f7fbe77;
    *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffff65d2 | 0x6512;
    *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_8 + 0x74);
    *(undefined2 *)(iVar3 + 0x76) = *(undefined2 *)(param_8 + 0x76);
    *(uint *)(iVar3 + 0x44) = *(uint *)(iVar3 + 0x44) & 0xfffffffd | 1;
    FUN_005e4b00(iVar3);
  }
  DAT_0292fd60 = iVar3;
  param_8 = DAT_0292fd4c;
  if (DAT_0292fd4c == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005e4d40(1);
    *(undefined4 *)(iVar3 + 0x54) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x58) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x5c) = 0x3f800000;
    *(undefined4 *)(iVar3 + 0x70) = 0x3f7fbe77;
    *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffff25d0 | 0x2510;
    *(undefined2 *)(iVar3 + 0x74) = *(undefined2 *)(param_8 + 0x74);
    *(undefined2 *)(iVar3 + 0x76) = *(undefined2 *)(param_8 + 0x76);
    *(uint *)(iVar3 + 0x44) = *(uint *)(iVar3 + 0x44) & 0xfffffffd | 1;
    FUN_005e4b00(iVar3);
  }
  DAT_0292fd64 = iVar3;
  *(uint *)(DAT_0292fd4c + 0x1f0) = *(uint *)(DAT_0292fd4c + 0x1f0) | 0x100000;
  *(uint *)(DAT_0292fd50 + 0x1f0) = *(uint *)(DAT_0292fd50 + 0x1f0) | 0x100000;
  *(uint *)(DAT_0292fd54 + 0x1f0) = *(uint *)(DAT_0292fd54 + 0x1f0) | 0x100000;
  *(uint *)(DAT_0292fd58 + 0x1f0) = *(uint *)(DAT_0292fd58 + 0x1f0) | 0x100000;
  *(uint *)(DAT_0292fd5c + 0x1f0) = *(uint *)(DAT_0292fd5c + 0x1f0) | 0x100000;
  *(uint *)(DAT_0292fd60 + 0x1f0) = *(uint *)(DAT_0292fd60 + 0x1f0) | 0x100000;
  *(uint *)(DAT_0292fd64 + 0x1f0) = *(uint *)(DAT_0292fd64 + 0x1f0) | 0x100000;
  *(undefined2 *)(DAT_0292fd64 + 0x74) = uVar1;
  *(undefined2 *)(DAT_0292fd60 + 0x74) = uVar1;
  *(undefined2 *)(DAT_0292fd5c + 0x74) = uVar1;
  *(undefined2 *)(DAT_0292fd58 + 0x74) = uVar1;
  *(undefined2 *)(DAT_0292fd54 + 0x74) = uVar1;
  *(undefined2 *)(DAT_0292fd50 + 0x74) = uVar1;
  *(undefined2 *)(DAT_0292fd4c + 0x74) = uVar1;
  DAT_0292fd68 = FUN_005e4d60(1,2);
  *(undefined4 *)(DAT_0292fd68 + 0x54) = 0x3f800000;
  *(undefined4 *)(DAT_0292fd68 + 0x58) = 0x3f800000;
  *(undefined4 *)(DAT_0292fd68 + 0x5c) = 0x3f800000;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xffff7fff | 0x4000;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xffffffcf;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) | 0x40000;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xfffff7ff | 0x400;
  *(undefined4 *)(DAT_0292fd68 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_0292fd68 + 0x40) = *(uint *)(DAT_0292fd68 + 0x40) & 0xfffffff1 | 1;
  *(uint *)(DAT_0292fd68 + 0x44) = *(uint *)(DAT_0292fd68 + 0x44) & 0xfffffffd | 1;
  *(undefined2 *)(DAT_0292fd68 + 0x74) = 1;
  *(undefined2 *)(DAT_0292fd68 + 0x76) = 0x80;
  *(uint *)(DAT_0292fd68 + 0x1f0) = *(uint *)(DAT_0292fd68 + 0x1f0) | 0x100000;
  *(undefined4 *)(DAT_0292fd68 + 0x60) = 0x3e800000;
  *(undefined1 *)(DAT_0292fd68 + 0x99) = 0x97;
  FUN_005e4b00(DAT_0292fd68);
  iVar3 = DAT_0292fd4c;
  if (DAT_0292fd4c == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_005e4d40(1);
    *(undefined4 *)(iVar5 + 0x54) = 0x3f800000;
    *(undefined4 *)(iVar5 + 0x58) = 0x3f800000;
    *(undefined4 *)(iVar5 + 0x5c) = 0x3f800000;
    *(uint *)(iVar5 + 0x40) = *(uint *)(iVar5 + 0x40) & 0xffff25d6 | 0x2516;
    *(undefined4 *)(iVar5 + 0x70) = 0x3f7fbe77;
    *(undefined2 *)(iVar5 + 0x74) = *(undefined2 *)(iVar3 + 0x74);
    *(undefined2 *)(iVar5 + 0x76) = *(undefined2 *)(iVar3 + 0x76);
    *(uint *)(iVar5 + 0x44) = *(uint *)(iVar5 + 0x44) & 0xfffffffd | 1;
    FUN_005e4b00(iVar5);
  }
  iVar3 = 0;
  _DAT_0292fd6c = iVar5;
  if (*DAT_0296209c != 0) {
    iVar5 = 0;
    do {
      if (*(char *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0xab) == '\0') {
        *(undefined1 *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0xab) = 1;
      }
      iVar2 = *(int *)(iVar5 + (int)DAT_0296209c);
      param_8 = (*(short *)(iVar2 + 0xa8) * 0x3c) / (int)*(char *)(iVar2 + 0xab);
      iVar3 = iVar3 + 1;
      *(float *)(iVar2 + 0xac) = (float)param_8;
      iVar2 = *(int *)(iVar5 + (int)DAT_0296209c);
      *(uint *)(iVar2 + 0xac) =
           ((*(char *)(iVar2 + 0xaa) + -1) * (uint)*(ushort *)(iVar2 + 0xa8) & 0x3ff) +
           (*(uint *)(iVar2 + 0xac) & 0xfffff800);
      iVar2 = *(int *)(iVar5 + (int)DAT_0296209c);
      *(float *)(iVar2 + 0x104) = *(float *)(iVar2 + 0x104) / *(float *)(iVar2 + 0xa4);
      *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x298) =
           *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x298) + 524288.0;
      *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x2a0) =
           *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x2a0) + 524288.0;
      *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x29c) =
           *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x29c) + 524288.0;
      *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x2a4) =
           *(float *)(*(int *)(iVar5 + (int)DAT_0296209c) + 0x2a4) + 524288.0;
      iVar5 = iVar3 * 4;
    } while (DAT_0296209c[iVar3] != 0);
  }
  iVar3 = 0;
  if (0 < DAT_02962098) {
    iVar5 = 0;
    do {
      *(undefined4 *)(iVar5 + 0x2a8 + (int)DAT_029620a0) = 0;
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x428;
    } while (iVar3 < DAT_02962098);
  }
  DAT_02924b44 = 0;
  if (DAT_02962050 == 0) {
    if (param_3 == (uint *)0x0) {
      puVar4 = &param_2;
    }
    else {
      puVar4 = &param_4;
      param_1 = param_3;
    }
    FUN_00654ba0(param_1,puVar4);
  }
  iVar3 = 0;
  if (0 < DAT_02962094) {
    do {
      *(short *)((int)DAT_02962084 + iVar3 * 2) = (short)iVar3;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_02962094);
  }
  iVar3 = 0;
  if (0 < DAT_02962094) {
    iVar5 = 0;
    do {
      *(undefined1 *)(iVar5 + 0x184 + (int)DAT_029620a4) = 0;
      *(undefined2 *)(iVar5 + 0x18a + (int)DAT_029620a4) = 0;
      *(undefined2 *)(iVar5 + 0x1d0 + (int)DAT_029620a4) = 0;
      *(undefined2 *)(iVar5 + 0x1d2 + (int)DAT_029620a4) = 0;
      *(undefined4 *)(iVar5 + 0x1d4 + (int)DAT_029620a4) = 0;
      *(undefined2 *)(iVar5 + 0x182 + (int)DAT_029620a4) = 0;
      *(undefined2 *)(iVar5 + 0x32a + (int)DAT_029620a4) = 0xffff;
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x330;
    } while (iVar3 < DAT_02962094);
  }
  _DAT_02947c20 = _DAT_008065c0;
  _DAT_02947c24 = _DAT_008065c4;
  _DAT_02947c28 = _DAT_008065c8;
  _DAT_02947c2c = _DAT_008065cc;
  _DAT_02947c30 = _DAT_008065d0;
  _DAT_02947c34 = _DAT_008065d4;
  _DAT_02947c38 = _DAT_008065d8;
  _DAT_02947c3c = _DAT_008065dc;
  _DAT_02947c40 = _DAT_008065e0;
  _DAT_02947c44 = _DAT_008065e4;
  _DAT_02947c48 = _DAT_008065e8;
  _DAT_02947c4c = _DAT_008065ec;
  _DAT_02947c50 = _DAT_008065f0;
  _DAT_02947c54 = _DAT_008065f4;
  _DAT_02947c58 = _DAT_008065f8;
  _DAT_02947c5c = _DAT_008065fc;
  FUN_0064ffe0();
  return;
}

