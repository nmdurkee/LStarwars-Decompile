/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58c010; label: FUN_0058c010
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058c010(void)

{
  byte *pbVar1;
  float fVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int unaff_ESI;
  float10 fVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 fVar11;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  float local_4;
  
  bVar5 = true;
  if (2 < *(byte *)(unaff_ESI + 0x107d)) {
    return;
  }
  iVar9 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
  if (*(char *)(iVar9 + 0x118) == -1) {
    return;
  }
  local_18 = 0.0;
  local_14 = 0.0;
  if (*(char *)(unaff_ESI + 0x39) == '\0') {
    if (((*(short *)(unaff_ESI + 0x3e) < 0) ||
        (iVar7 = (int)*(short *)(unaff_ESI + 0x3e), *(int *)(DAT_029130e4 + 8) <= iVar7)) ||
       (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar7 * 4) == 0)) goto LAB_0058c0db;
    bVar3 = *(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 8) + iVar7 * 4) + 4);
LAB_0058c0d7:
    bVar5 = true;
    if ((bVar3 & 0x40) == 0) goto LAB_0058c0db;
  }
  else if (((*(short *)(unaff_ESI + 0x3c) < 0) ||
           (iVar7 = (int)*(short *)(unaff_ESI + 0x3c), *(int *)(DAT_029130e4 + 8) <= iVar7)) ||
          ((*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar7 * 4) == 0 ||
           ((*(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 8) + iVar7 * 4) + 4) & 0x40)
            == 0)))) {
    bVar5 = true;
    if (((*(short *)(unaff_ESI + 0x3a) < 0) ||
        (iVar7 = (int)*(short *)(unaff_ESI + 0x3a), *(int *)(DAT_029130e4 + 8) <= iVar7)) ||
       (*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 0xc) + iVar7 * 4) == 0)) goto LAB_0058c0db;
    bVar3 = *(byte *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x50) + 8) + iVar7 * 4) + 4);
    goto LAB_0058c0d7;
  }
  bVar5 = false;
LAB_0058c0db:
  if ((((*(int *)(unaff_ESI + 0xfd8) != 0) &&
       (*(float *)(unaff_ESI + 0xfec) < *(float *)(unaff_ESI + 0xfe8) !=
        (*(float *)(unaff_ESI + 0xfec) == *(float *)(unaff_ESI + 0xfe8)))) &&
      (cVar4 = *(char *)(iVar9 + 0x10e), cVar4 != -1)) &&
     ((bVar5 && (FUN_005b33c0(&local_c,unaff_ESI + 0xfdc,cVar4 * 0x40 + 0x804 + unaff_ESI),
                local_4 < 0.0)))) {
    fVar10 = (float10)FUN_005bfe00(-local_c,-local_4);
    iVar9 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
    local_18 = *(float *)((*(byte *)(unaff_ESI + 0x107d) + 0x4b) * 0x34 + unaff_ESI) - (float)fVar10
    ;
    if (*(float *)(iVar9 + 0x50) < local_18 == (*(float *)(iVar9 + 0x50) == local_18)) {
      if (local_18 <= -*(float *)(iVar9 + 0x50)) {
        local_18 = -*(float *)(iVar9 + 0x50);
      }
    }
    else {
      local_18 = *(float *)(iVar9 + 0x50);
    }
    fVar10 = (float10)FUN_005bfe00(-local_8,-local_4);
    iVar9 = *(int *)(*(int *)(unaff_ESI + 0x54) + 0x24);
    local_14 = *(float *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf40 + unaff_ESI) -
               (float)fVar10;
    if (*(float *)(iVar9 + 0x54) < local_14 == (*(float *)(iVar9 + 0x54) == local_14)) {
      if (local_14 <= -*(float *)(iVar9 + 0x54)) {
        local_14 = -*(float *)(iVar9 + 0x54);
      }
    }
    else {
      local_14 = *(float *)(iVar9 + 0x54);
    }
  }
  *(undefined1 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf6c + unaff_ESI) =
       *(undefined1 *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x118);
  *(undefined1 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf6d + unaff_ESI) = 0;
  fVar2 = *(float *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x58) * _DAT_00925018;
  if (1.0 < fVar2) {
    fVar2 = 1.0;
  }
  iVar9 = (*(byte *)(unaff_ESI + 0x107d) + 0x4b) * 0x34;
  *(float *)(iVar9 + unaff_ESI) = *(float *)(iVar9 + unaff_ESI) * (1.0 - fVar2) + fVar2 * local_18;
  uVar6 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf60 + unaff_ESI) = uVar6;
  fVar10 = extraout_ST0;
  fVar11 = extraout_ST1;
  uVar6 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf66 + unaff_ESI) = uVar6;
  iVar9 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
  *(float *)(iVar9 + 0xf40 + unaff_ESI) =
       (float)((float10)local_14 * fVar11 + (float10)*(float *)(iVar9 + 0xf40 + unaff_ESI) * fVar10)
  ;
  uVar6 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf62 + unaff_ESI) = uVar6;
  uVar6 = FUN_006e6b90();
  *(undefined2 *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf68 + unaff_ESI) = uVar6;
  *(float *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf44 + unaff_ESI) =
       (float)extraout_ST0_00;
  uVar8 = (uint)*(byte *)(unaff_ESI + 0x107d);
  iVar9 = (uVar8 + 0x4b) * 0x34;
  if ((((_DAT_00804d30 < *(float *)(iVar9 + unaff_ESI)) ||
       (*(float *)(iVar9 + unaff_ESI) < -_DAT_00804d30)) ||
      ((_DAT_00804d30 < *(float *)(uVar8 * 0x34 + 0xf40 + unaff_ESI) ||
       (*(float *)(uVar8 * 0x34 + 0xf40 + unaff_ESI) < -_DAT_00804d30)))) &&
     (*(undefined1 *)(uVar8 * 0x34 + 0xf6d + unaff_ESI) = 1, bVar5)) {
    if (extraout_ST0_00 !=
        (float10)*(float *)((*(byte *)(unaff_ESI + 0x107d) + 0x4b) * 0x34 + unaff_ESI)) {
      pbVar1 = (byte *)((uint)*(byte *)(unaff_ESI + 0x107d) * 0x34 + 0xf6d + unaff_ESI);
      *pbVar1 = *pbVar1 | 8;
    }
    iVar9 = (uint)*(byte *)(unaff_ESI + 0x107d) * 0x34;
    if (extraout_ST0_00 != (float10)*(float *)(iVar9 + 0xf40 + unaff_ESI)) {
      pbVar1 = (byte *)(iVar9 + unaff_ESI + 0xf6d);
      *pbVar1 = *pbVar1 | 0x10;
    }
  }
  if ((*(int *)(unaff_ESI + 0xfd8) != 0) &&
     (fVar2 = *(float *)(unaff_ESI + 0xfe8) - _DAT_00925018, *(float *)(unaff_ESI + 0xfe8) = fVar2,
     (float10)fVar2 < extraout_ST0_00)) {
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

