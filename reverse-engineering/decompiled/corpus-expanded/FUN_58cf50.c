/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58cf50; label: FUN_0058cf50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058cf50(float param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  float10 fVar5;
  
  iVar2 = (int)param_1;
  if (2 < *(byte *)((int)param_1 + 0x107d)) {
    return;
  }
  iVar1 = *(int *)(*(int *)((int)param_1 + 0x54) + 0x24);
  if (*(char *)(iVar1 + 0x119) == -1) {
    return;
  }
  fVar5 = (float10)FUN_005c0240((*(float *)((uint)*(byte *)((int)param_1 + 0x107d) * 0x34 + 0xf44 +
                                           (int)param_1) - *(float *)(iVar1 + 0x60)) /
                                (*(float *)(iVar1 + 0x5c) - *(float *)(iVar1 + 0x60)));
  if (DAT_00804c0c == -1) {
LAB_0058cff5:
    param_1 = (float)fVar5 - _DAT_00804da0 * _DAT_00925018;
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
  }
  else {
    if (*(char *)((int)param_1 + 0x39) == '\0') {
LAB_0058cfc8:
      if (*(short *)((int)param_1 + 0x3e) != DAT_00804c0c) goto LAB_0058cff5;
    }
    else if (*(short *)((int)param_1 + 0x3c) != DAT_00804c0c) {
      if (*(char *)((int)param_1 + 0x39) != '\0') goto LAB_0058cff5;
      goto LAB_0058cfc8;
    }
    param_1 = _DAT_00804da4 * _DAT_00925018 + (float)fVar5;
    if (1.0 < param_1) {
      param_1 = 1.0;
    }
  }
  *(undefined1 *)((uint)*(byte *)(iVar2 + 0x107d) * 0x34 + 0xf6c + iVar2) =
       *(undefined1 *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x119);
  iVar1 = *(int *)(*(int *)(iVar2 + 0x54) + 0x24);
  *(float *)((uint)*(byte *)(iVar2 + 0x107d) * 0x34 + 0xf44 + iVar2) =
       (1.0 - param_1 * param_1) * *(float *)(iVar1 + 0x60) +
       *(float *)(iVar1 + 0x5c) * param_1 * param_1;
  iVar4 = (uint)*(byte *)(iVar2 + 0x107d) * 0x34;
  iVar1 = iVar4 + iVar2;
  if (*(float *)(iVar4 + 0xf44 + iVar2) == 0.0) {
    *(undefined1 *)(iVar1 + 0xf6d) = 0;
    *(char *)(iVar2 + 0x107d) = *(char *)(iVar2 + 0x107d) + '\x01';
    return;
  }
  *(undefined1 *)(iVar1 + 0xf6d) = 0x21;
  iVar1 = *(int *)(*(int *)(iVar2 + 0x54) + 0x24);
  if (*(float *)(iVar1 + 0x60) <= *(float *)(iVar1 + 0x5c)) {
    uVar3 = FUN_006e6b90();
    *(undefined2 *)((uint)*(byte *)(iVar2 + 0x107d) * 0x34 + 0xf64 + iVar2) = uVar3;
  }
  else {
    uVar3 = FUN_006e6b90();
    *(undefined2 *)((uint)*(byte *)(iVar2 + 0x107d) * 0x34 + 0xf64 + iVar2) = uVar3;
  }
  uVar3 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(iVar2 + 0x107d) * 0x34 + 0xf6a + iVar2) = uVar3;
  *(char *)(iVar2 + 0x107d) = *(char *)(iVar2 + 0x107d) + '\x01';
  return;
}

