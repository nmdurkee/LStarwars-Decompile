/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58c4d0; label: FUN_0058c4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058c4d0(void)

{
  byte *pbVar1;
  byte bVar2;
  float fVar3;
  bool bVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int unaff_ESI;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar9;
  float local_1c;
  float local_18;
  float local_c;
  float local_8;
  float local_4;
  
  bVar4 = true;
  if (2 < *(byte *)(unaff_ESI + 0x107d)) {
    return;
  }
  iVar7 = *(int *)(unaff_ESI + 0x54);
  if (*(char *)(*(int *)(iVar7 + 0x24) + 0x118) == -1) {
    return;
  }
  *(uint *)(unaff_ESI + 0xef0) = *(uint *)(unaff_ESI + 0xef0) & 0xfffeffff;
  local_1c = 0.0;
  local_18 = 0.0;
  if (*(char *)(unaff_ESI + 0x39) == '\0') {
    if (((*(short *)(unaff_ESI + 0x3e) < 0) ||
        (iVar6 = (int)*(short *)(unaff_ESI + 0x3e), *(int *)(DAT_029130e4 + 8) <= iVar6)) ||
       (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar6 * 4) == 0)) goto LAB_0058c5b4;
    bVar2 = *(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 8) + iVar6 * 4) + 4);
LAB_0058c5aa:
    if ((bVar2 & 0x40) == 0) goto LAB_0058c5b4;
  }
  else {
    if ((*(short *)(unaff_ESI + 0x3c) < 0) ||
       (iVar6 = (int)*(short *)(unaff_ESI + 0x3c), *(int *)(DAT_029130e4 + 8) <= iVar6)) {
LAB_0058c555:
      if (((*(short *)(unaff_ESI + 0x3a) < 0) ||
          (iVar6 = (int)*(short *)(unaff_ESI + 0x3a), *(int *)(DAT_029130e4 + 8) <= iVar6)) ||
         (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar6 * 4) == 0)) goto LAB_0058c5b4;
      bVar2 = *(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 8) + iVar6 * 4) + 4);
      goto LAB_0058c5aa;
    }
    if ((*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar6 * 4) == 0) ||
       ((*(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 8) + iVar6 * 4) + 4) & 0x40) == 0)
       ) {
      iVar7 = *(int *)(unaff_ESI + 0x54);
      goto LAB_0058c555;
    }
    iVar7 = *(int *)(unaff_ESI + 0x54);
  }
  bVar4 = false;
LAB_0058c5b4:
  if ((((*(int *)(unaff_ESI + 0xfd8) != 0) &&
       (*(float *)(unaff_ESI + 0xfec) < *(float *)(unaff_ESI + 0xfe8) !=
        (*(float *)(unaff_ESI + 0xfec) == *(float *)(unaff_ESI + 0xfe8)))) &&
      (*(char *)(*(int *)(iVar7 + 0x24) + 0x10e) != -1)) && (bVar4)) {
    *(uint *)(unaff_ESI + 0xef0) = *(uint *)(unaff_ESI + 0xef0) | 0x10000;
    FUN_005b33c0(&local_c,unaff_ESI + 0xfdc,
                 *(char *)(*(int *)(iVar7 + 0x24) + 0x10e) * 0x40 + 0x804 + unaff_ESI);
    if (local_4 < 0.0) {
      fVar8 = (float10)FUN_005c0240(local_c * local_c + local_4 * local_4);
      fVar8 = (float10)FUN_005bfe00(-local_8,(float)fVar8);
      iVar7 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
      local_1c = (float)fVar8 -
                 *(float *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf40 + unaff_ESI);
      if (*(float *)(iVar7 + 0x54) < local_1c == (*(float *)(iVar7 + 0x54) == local_1c)) {
        if (local_1c <= -*(float *)(iVar7 + 0x54)) {
          local_1c = -*(float *)(iVar7 + 0x54);
        }
      }
      else {
        local_1c = *(float *)(iVar7 + 0x54);
      }
      fVar8 = (float10)FUN_005bfe00(-local_c,-local_4);
      fVar3 = (float)-fVar8 -
              *(float *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf44 + unaff_ESI);
      iVar7 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
      if (*(float *)(iVar7 + 0x50) < fVar3 == (*(float *)(iVar7 + 0x50) == fVar3)) {
        local_18 = -*(float *)(iVar7 + 0x50);
        if (local_18 < fVar3) {
          *(uint *)(unaff_ESI + 0xef0) = *(uint *)(unaff_ESI + 0xef0) & 0xfffeffff;
          local_18 = fVar3;
        }
      }
      else {
        local_18 = *(float *)(iVar7 + 0x50);
      }
    }
  }
  *(undefined1 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf6c + unaff_ESI) =
       *(undefined1 *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x118);
  *(undefined1 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf6d + unaff_ESI) = 0;
  fVar8 = (float10)(*(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x58) * _DAT_00925018);
  if ((float10)1 < fVar8) {
    fVar8 = (float10)(float)(float10)1;
  }
  *(undefined4 *)((*(byte *)(unaff_ESI + 0x107d) + 0x4b) * 0x34 + unaff_ESI) = 0;
  iVar7 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
  fVar9 = (float10)1 - fVar8;
  *(float *)(iVar7 + 0xf40 + unaff_ESI) =
       (float)((float10)*(float *)(iVar7 + 0xf40 + unaff_ESI) * fVar9 + fVar8 * (float10)local_1c);
  uVar5 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf62 + unaff_ESI) = uVar5;
  fVar8 = extraout_ST0;
  uVar5 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf68 + unaff_ESI) = uVar5;
  iVar7 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
  *(float *)(iVar7 + 0xf44 + unaff_ESI) =
       (float)((float10)local_18 * fVar9 + (float10)*(float *)(iVar7 + 0xf44 + unaff_ESI) * fVar8);
  uVar5 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf64 + unaff_ESI) = uVar5;
  uVar5 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf6a + unaff_ESI) = uVar5;
  iVar6 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
  iVar7 = iVar6 + unaff_ESI;
  if ((((_DAT_00804d30 < *(float *)(iVar6 + 0xf40 + unaff_ESI)) ||
       (*(float *)(iVar7 + 0xf40) < -_DAT_00804d30)) ||
      ((_DAT_00804d30 < *(float *)(iVar7 + 0xf44) || (*(float *)(iVar7 + 0xf44) < -_DAT_00804d30))))
     && (*(undefined1 *)(iVar7 + 0xf6d) = 1, bVar4)) {
    iVar7 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
    if (extraout_ST0_00 != (float10)*(float *)(iVar7 + 0xf40 + unaff_ESI)) {
      pbVar1 = (byte *)(iVar7 + unaff_ESI + 0xf6d);
      *pbVar1 = *pbVar1 | 0x10;
    }
    iVar7 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
    if (extraout_ST0_00 != (float10)*(float *)(iVar7 + 0xf44 + unaff_ESI)) {
      pbVar1 = (byte *)(iVar7 + unaff_ESI + 0xf6d);
      *pbVar1 = *pbVar1 | 0x20;
    }
  }
  if ((*(int *)(unaff_ESI + 0xfd8) != 0) &&
     (fVar3 = *(float *)(unaff_ESI + 0xfe8) - _DAT_00925018, *(float *)(unaff_ESI + 0xfe8) = fVar3,
     (float10)fVar3 < extraout_ST0_00)) {
    *(char *)(unaff_ESI + 0x107d) = *(char *)(unaff_ESI + 0x107d) + '\x01';
    *(float *)(unaff_ESI + 0xfe8) = (float)extraout_ST0_00;
    *(float *)(unaff_ESI + 0xfec) = (float)extraout_ST0_00;
    *(undefined4 *)(unaff_ESI + 0xfd8) = 0;
    *(undefined1 *)(unaff_ESI + 0x1080) = 0;
    return;
  }
  *(char *)(unaff_ESI + 0x107d) = *(char *)(unaff_ESI + 0x107d) + '\x01';
  return;
}

