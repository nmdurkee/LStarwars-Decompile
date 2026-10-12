/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58d150; label: FUN_0058d150
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058d150(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  float10 fVar7;
  
  iVar4 = (int)param_1;
  if (2 < *(byte *)((int)param_1 + 0x107d)) {
    return;
  }
  if (*(char *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x11a) == -1) {
    return;
  }
  fVar7 = (float10)FUN_005c0240((*(float *)((uint)*(byte *)((int)param_1 + 0x107d) * 0x34 + 0xf44 +
                                           (int)param_1) - _DAT_00955588) /
                                (_DAT_00804db0 - _DAT_00955588));
  fVar3 = _DAT_00955588;
  fVar2 = _DAT_00804db0;
  if (DAT_00804c0c == -1) {
LAB_0058d1fa:
    param_1 = (float)fVar7 - _DAT_00804da8 * _DAT_00925018;
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
  }
  else {
    if (*(char *)((int)param_1 + 0x39) == '\0') {
LAB_0058d1cd:
      if (*(short *)((int)param_1 + 0x3e) != DAT_00804c0c) goto LAB_0058d1fa;
    }
    else if (*(short *)((int)param_1 + 0x3c) != DAT_00804c0c) {
      if (*(char *)((int)param_1 + 0x39) != '\0') goto LAB_0058d1fa;
      goto LAB_0058d1cd;
    }
    param_1 = _DAT_00804dac * _DAT_00925018 + (float)fVar7;
    if (1.0 < param_1) {
      param_1 = 1.0;
    }
  }
  fVar1 = _DAT_00955588 * (1.0 - param_1 * param_1);
  *(undefined1 *)((uint)*(byte *)(iVar4 + 0x107d) * 0x34 + 0xf6c + iVar4) =
       *(undefined1 *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x11a);
  *(float *)((uint)*(byte *)(iVar4 + 0x107d) * 0x34 + 0xf44 + iVar4) =
       fVar1 + fVar2 * param_1 * param_1;
  iVar6 = (uint)*(byte *)(iVar4 + 0x107d) * 0x34;
  if (*(float *)(iVar6 + 0xf44 + iVar4) == 0.0) {
    *(char *)(iVar4 + 0x107d) = *(char *)(iVar4 + 0x107d) + '\x01';
    return;
  }
  *(undefined1 *)(iVar6 + iVar4 + 0xf6d) = 0x21;
  if (fVar3 <= fVar2) {
    uVar5 = FUN_006e6b90();
  }
  else {
    uVar5 = FUN_006e6b90();
  }
  *(undefined2 *)((uint)*(byte *)(iVar4 + 0x107d) * 0x34 + 0xf64 + iVar4) = uVar5;
  uVar5 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(iVar4 + 0x107d) * 0x34 + 0xf6a + iVar4) = uVar5;
  *(char *)(iVar4 + 0x107d) = *(char *)(iVar4 + 0x107d) + '\x01';
  return;
}

