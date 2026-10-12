/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x506880; label: FUN_00506880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00506880(int param_1,float param_2)

{
  byte *pbVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  uint *puVar5;
  ushort *puVar6;
  int *piVar7;
  undefined4 uVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  float *pfVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  float10 fVar17;
  float local_cc;
  byte local_c6;
  undefined1 local_c5;
  float local_c4;
  float local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 local_b0 [16];
  undefined1 local_a0 [16];
  undefined1 local_90 [16];
  undefined1 local_80 [64];
  undefined4 local_40 [16];
  
  piVar4 = *(int **)(param_1 + 0x9c);
  puVar5 = *(uint **)(*(int *)(param_1 + 0x58) + 0x10);
  DAT_00921360 = 0.0;
  DAT_00921364 = 0.0;
  DAT_0092135a = 0;
  _DAT_00921368 = 0.0;
  if (((4 < (**(uint **)(param_1 + 0x58) & 0xff)) && (puVar5[8] != 0)) &&
     (iVar10 = FUN_005da520(puVar5[8],(int)piVar4 + 0xd,&local_c6,param_2), iVar10 != 0)) {
    if (local_c6 == 0xff) {
      *(undefined1 *)((int)piVar4 + 0xe) = 0xff;
    }
    else {
      *(undefined1 *)((int)piVar4 + 0xe) =
           *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x54) + (uint)local_c6 * 2);
    }
  }
  if (puVar5[3] != 0) {
    iVar10 = FUN_005da520(puVar5[3],piVar4 + 2,&local_c5,param_2);
    if (iVar10 != 0) {
      *(undefined1 *)((int)piVar4 + 9) = local_c5;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x1000;
      _DAT_0092136c = 1;
    }
    bVar9 = *(byte *)(piVar4 + 2);
    puVar6 = (ushort *)puVar5[3];
    if ((ushort)bVar9 < *puVar6) {
      pfVar13 = (float *)(*(int *)(puVar6 + 2) + (uint)bVar9 * 4);
      if ((*pfVar13 - param_2 < 1.0) &&
         ((uint)*(byte *)(*(int *)(puVar6 + 4) + (uint)bVar9) != (int)*(char *)((int)piVar4 + 9))) {
        local_c4 = *pfVar13 - 1.0;
        *(float *)(param_1 + 0x94) = local_c4;
        if ((*(uint *)(param_1 + 0x88) & 0x40000) != 0) {
          *(float *)(param_1 + 0x94) = *(float *)(*(int *)(param_1 + 0x58) + 8) - local_c4;
        }
        if (*(float *)(param_1 + 0x94) < 1.0) {
          *(undefined4 *)(param_1 + 0x94) = 0x3f800000;
        }
      }
    }
  }
  if (*(byte *)((int)piVar4 + 10) < *(byte *)(piVar4 + 3)) {
    do {
      iVar10 = *piVar4 + (uint)*(byte *)((int)piVar4 + 10) * 0x10;
      fVar2 = *(float *)(iVar10 + 4);
      if (fVar2 < param_2 == (fVar2 == param_2)) break;
      iVar11 = (int)*(char *)(*(char *)(iVar10 + 0xc) + 0x11 + (int)puVar5);
      iVar10 = piVar4[1];
      pbVar1 = (byte *)(iVar10 + iVar11 * 4);
      *pbVar1 = *pbVar1 | 2;
      *(undefined1 *)(iVar10 + iVar11 * 4 + 1) = *(undefined1 *)((int)piVar4 + 10);
      *(char *)((int)piVar4 + 10) = *(char *)((int)piVar4 + 10) + '\x01';
    } while (*(byte *)((int)piVar4 + 10) < *(byte *)(piVar4 + 3));
  }
  cVar3 = *(char *)((int)piVar4 + 10);
  while (cVar3 != '\0') {
    if (*(float *)((uint)*(byte *)((int)piVar4 + 10) * 0x10 + -0xc + *piVar4) <= param_2) break;
    bVar9 = *(byte *)((int)piVar4 + 10) - 1;
    *(byte *)((int)piVar4 + 10) = bVar9;
    iVar11 = (int)*(char *)(*(char *)((uint)bVar9 * 0x10 + 0xc + *piVar4) + 0x11 + (int)puVar5);
    iVar10 = piVar4[1];
    pbVar1 = (byte *)(iVar10 + iVar11 * 4);
    *pbVar1 = *pbVar1 | 2;
    *(undefined1 *)(iVar10 + iVar11 * 4 + 1) = *(undefined1 *)((int)piVar4 + 10);
    cVar3 = *(char *)((int)piVar4 + 10);
  }
  DAT_00921359 = -1 < *(char *)((int)piVar4 + 9);
  if ((bool)DAT_00921359) {
    _DAT_0092135c = 2;
  }
  if (*(char *)((int)piVar4 + 9) < '\0') {
    return;
  }
  uVar12 = (uint)*(char *)((int)piVar4 + 9);
  if (*puVar5 <= uVar12) {
    uVar12 = FUN_004fff00();
  }
  puVar14 = (undefined4 *)(uVar12 * 0x50 + puVar5[1]);
  pbVar1 = (byte *)(piVar4[1] + uVar12 * 4);
  if ((*(byte *)(puVar14 + 0x10) & 1) == 0) {
LAB_00506c5d:
    puVar15 = &DAT_00921298;
    for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
      *puVar15 = *puVar14;
      puVar14 = puVar14 + 1;
      puVar15 = puVar15 + 1;
    }
  }
  else {
    bVar9 = *(byte *)((int)puVar14 + 0x42);
    iVar10 = FUN_005ca450(puVar5[2]);
    if (iVar10 <= (int)(uint)bVar9) goto LAB_00506c5d;
    if (((4 < (**(uint **)(param_1 + 0x58) & 0xff)) &&
        (piVar7 = (int *)puVar5[7], piVar7 != (int *)0x0)) &&
       ((0x414e4933 < *piVar7 && (*piVar7 < 0x414e4936)))) {
      pfVar13 = (float *)FUN_005ce7e0(piVar7,(uint)bVar9,*(undefined4 *)(param_1 + 0x94),0);
      _DAT_00921368 = pfVar13[2];
      DAT_00921360 = *pfVar13 * 1.3;
      if ((*(byte *)((int)puVar14 + 0x43) & 2) == 0) {
        if (((puVar5[8] != 0) && (-1 < *(char *)((int)piVar4 + 0xe))) &&
           (iVar10 = *(char *)((int)piVar4 + 0xe) * 100 +
                     **(int **)(*(int *)(param_1 + 0x58) + 0x1c), *(int *)(iVar10 + 0x50) != 0)) {
          FUN_00500e50(iVar10,param_2,local_80,0);
          if ((*(byte *)(iVar10 + 0x58) & 4) != 0) {
            FUN_005b4960(local_80,iVar10 + 0x40);
          }
          if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
            FUN_005b5430(local_80,local_80,param_1 + 0x18);
          }
          FUN_005b6ec0(local_80,&DAT_00921318);
          DAT_0092135a = 1;
        }
      }
      else {
        DAT_00921364 = pfVar13[1];
      }
    }
    iVar10 = *(int *)puVar5[2];
    if ((iVar10 < 0x414e4934) || (0x414e4935 < iVar10)) {
      FUN_004fff00();
    }
    else {
      FUN_005ea390((int *)puVar5[2],*(undefined1 *)((int)puVar14 + 0x42),
                   *(undefined4 *)(param_1 + 0x94),&DAT_00921298);
    }
  }
  if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
    FUN_005b5430(&DAT_00921298,&DAT_00921298,param_1 + 0x18);
  }
  DAT_00921358 = 1;
  if ((*pbVar1 & 2) == 0) {
    DAT_00921358 = 1;
    return;
  }
  puVar14 = (undefined4 *)((uint)pbVar1[1] * 0x10 + *piVar4);
  local_c4 = (float)puVar14[2];
  local_c0 = ABS(local_c4);
  fVar17 = (float10)FUN_005b7c20(puVar14[2]);
  uVar8 = DAT_009212c8;
  if ((float10)0.0 <= fVar17) {
    local_c4 = 0.0;
  }
  else {
    local_c4 = 1.4013e-45;
    if ((float)puVar14[1] + local_c0 < param_2 != ((float)puVar14[1] + local_c0 == param_2)) {
      *pbVar1 = *pbVar1 & 0xfd;
      return;
    }
  }
  local_b8 = DAT_009212cc;
  puVar15 = &DAT_00921298;
  puVar16 = local_40;
  for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar16 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar16 = puVar16 + 1;
  }
  local_b4 = DAT_009212d0;
  FUN_005b6a80(local_40,*puVar14);
  if (local_c0 <= 0.01) {
    local_cc = 1.0;
LAB_00506e1f:
    if (local_c4 == 0.0) goto LAB_00506d9e;
  }
  else {
    local_cc = (param_2 - (float)puVar14[1]) / local_c0;
    if (local_cc <= 1.0) {
      if (local_cc < 0.0) goto LAB_00506d9e;
      goto LAB_00506e1f;
    }
  }
  local_cc = 1.0 - local_cc;
LAB_00506d9e:
  FUN_005b7ea0(local_40,local_a0);
  FUN_005b7ea0(&DAT_00921298,local_90);
  FUN_005b87a0(local_b0,local_90,local_a0,local_cc);
  FUN_005b8040(local_b0,&DAT_00921298);
  DAT_009212d0 = local_b4;
  DAT_009212cc = local_b8;
  DAT_009212c8 = uVar8;
  return;
}

