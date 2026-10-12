/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f0470; label: FUN_005f0470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_005f0470(undefined4 *param_1,uint *param_2)

{
  short *psVar1;
  void *_Dst;
  undefined1 *puVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  size_t sVar15;
  undefined4 *puVar16;
  void *local_8;
  
  puVar3 = param_2;
  FUN_004ffaa0(DAT_00973fa4);
  uVar4 = *param_2;
  *param_2 = (uVar4 + 3 & 0xfffffffc) + 0x90;
  puVar13 = (undefined4 *)(uVar4 + 3 & 0xfffffffc);
  puVar14 = param_1;
  puVar16 = puVar13;
  for (iVar7 = 0x24; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar16 = *puVar14;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  }
  puVar13[2] = *param_2 + 3 & 0xfffffffc;
  uVar4 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar4;
  *param_2 = param_1[1] * 0x10 + uVar4;
  _memcpy((void *)puVar13[2],(void *)param_1[2],param_1[1] << 4);
  iVar7 = ((int)(param_1[4] + 7 + (param_1[4] + 7 >> 0x1f & 7U)) >> 3) * 2;
  puVar13[0xc] = *param_2 + 0xf & 0xfffffff0;
  sVar15 = (((int)(iVar7 + (iVar7 >> 0x1f & 0xfU)) >> 4) + 1) * 0x10;
  uVar4 = (*param_2 + 0xf & 0xfffffff0) + sVar15;
  *param_2 = uVar4;
  puVar13[0xd] = uVar4;
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + sVar15;
  _memset((void *)puVar13[0xc],0,sVar15);
  _memset((void *)puVar13[0xd],0,sVar15);
  iVar7 = param_1[0x13];
  puVar13[0x16] = *param_2 + 0xf & 0xfffffff0;
  sVar15 = (((int)(iVar7 + 7U >> 3) >> 4) + 1) * 0x10;
  uVar4 = (*param_2 + 0xf & 0xfffffff0) + sVar15;
  *param_2 = uVar4;
  puVar13[0x17] = uVar4;
  *param_2 = (*param_2 + 0xf & 0xfffffff0) + sVar15;
  _memset((void *)puVar13[0x16],0,sVar15);
  _memset((void *)puVar13[0x17],0,sVar15);
  uVar8 = *param_2;
  uVar4 = uVar8 + 3 & 0xfffffffc;
  *param_2 = uVar4;
  uVar8 = uVar8 + 3 & 0xfffffffc;
  uVar4 = uVar4 + param_1[0x13] * 0x44;
  *param_2 = uVar4;
  puVar13[0x15] = uVar4;
  uVar4 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar4;
  _Dst = (void *)(uVar4 + param_1[0x13] * 4);
  *param_2 = (uint)_Dst;
  *param_2 = (uint)(param_1[0x13] * 0x34 + (int)_Dst);
  _memset(_Dst,0,param_1[0x13] * 0x34);
  uVar4 = *param_2 + 3 & 0xfffffffc;
  local_8 = (void *)(*param_2 + 3 & 0xfffffffc);
  *param_2 = uVar4;
  *param_2 = param_1[0x13] * 0x10 + uVar4;
  _memset(local_8,0,param_1[0x13] << 4);
  iVar7 = 0;
  uVar4 = uVar8;
  param_2 = _Dst;
  if (0 < (int)param_1[0x13]) {
    do {
      *(uint *)(puVar13[0x15] + iVar7 * 4) = uVar4;
      puVar14 = *(undefined4 **)(param_1[0x15] + iVar7 * 4);
      puVar16 = *(undefined4 **)(puVar13[0x15] + iVar7 * 4);
      for (iVar9 = 0x11; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      **(undefined4 **)(puVar13[0x15] + iVar7 * 4) = puVar13;
      *(uint **)(*(int *)(puVar13[0x15] + iVar7 * 4) + 8) = param_2;
      *(int *)(*(int *)(puVar13[0x15] + iVar7 * 4) + 0xc) =
           (*(int *)(*(int *)(param_1[0x15] + iVar7 * 4) + 0xc) - param_1[2] >> 4) * 0x10 +
           puVar13[2];
      *(int *)(*(int *)(puVar13[0x15] + iVar7 * 4) + 0x18) =
           (*(int *)(*(int *)(param_1[0x15] + iVar7 * 4) + 0x18) - param_1[2] >> 4) * 0x10 +
           puVar13[2];
      *(void **)(*(int *)(puVar13[0x15] + iVar7 * 4) + 0x10) = local_8;
      iVar9 = *(int *)(puVar13[0x15] + iVar7 * 4);
      *(undefined4 *)(iVar9 + 0x14) = *(undefined4 *)(iVar9 + 0x10);
      *(uint *)(*(int *)(puVar13[0x15] + iVar7 * 4) + 0x28) = *puVar3 + 0xf & 0xfffffff0;
      uVar10 = *puVar3 + 0xf & 0xfffffff0;
      *puVar3 = uVar10;
      uVar10 = uVar10 + *(int *)(*(int *)(param_1[0x15] + iVar7 * 4) + 0x38) * 0x10;
      *puVar3 = uVar10;
      *(uint *)(*(int *)(puVar13[0x15] + iVar7 * 4) + 0x2c) = uVar10;
      uVar10 = *puVar3 + 0xf & 0xfffffff0;
      *puVar3 = uVar10;
      *puVar3 = *(int *)(*(int *)(param_1[0x15] + iVar7 * 4) + 0x38) * 0x10 + uVar10;
      puVar2 = *(undefined1 **)(*(int *)(puVar13[0x15] + iVar7 * 4) + 0x10);
      *puVar2 = 0x8d;
      *(undefined4 *)(puVar2 + 4) = 0;
      puVar2[1] = 1;
      local_8 = (void *)((int)local_8 + 0x10);
      iVar7 = iVar7 + 1;
      uVar4 = uVar4 + 0x44;
      param_2 = (void *)((int)param_2 + 0x34);
    } while (iVar7 < (int)param_1[0x13]);
  }
  uVar4 = *puVar3;
  uVar10 = uVar4 + 3 & 0xfffffffc;
  *puVar3 = uVar10;
  uVar10 = uVar10 + param_1[0x13] * 0x2c4;
  *puVar3 = uVar10;
  puVar13[0x14] = uVar10;
  uVar10 = *puVar3 + 3 & 0xfffffffc;
  *puVar3 = uVar10;
  *puVar3 = uVar10 + param_1[0x13] * 4;
  local_8 = (void *)(uVar4 + 3 & 0xfffffffc);
  param_2 = (uint *)0x0;
  if (0 < (int)param_1[0x13]) {
    do {
      *(void **)(puVar13[0x14] + (int)param_2 * 4) = local_8;
      puVar14 = *(undefined4 **)(param_1[0x14] + (int)param_2 * 4);
      puVar16 = *(undefined4 **)(puVar13[0x14] + (int)param_2 * 4);
      for (iVar7 = 0xb1; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      *(uint *)(*(int *)(puVar13[0x14] + (int)param_2 * 4) + 0x3c) =
           uVar8 + ((*(int *)(*(int *)(param_1[0x14] + (int)param_2 * 4) + 0x3c) -
                    *(int *)param_1[0x15]) / 0x44) * 0x44;
      iVar7 = *(int *)(puVar13[0x14] + (int)param_2 * 4);
      FUN_00601030(iVar7);
      psVar1 = (short *)(iVar7 + 0x2c0);
      *psVar1 = *psVar1 + 1;
      local_8 = (void *)((int)local_8 + 0x2c4);
      param_2 = (uint *)((int)param_2 + 1);
    } while ((int)param_2 < (int)param_1[0x13]);
  }
  puVar13[0x19] = *puVar3 + 3 & 0xfffffffc;
  uVar4 = *puVar3 + 3 & 0xfffffffc;
  *puVar3 = uVar4;
  *puVar3 = uVar4 + param_1[0x18] * 0x24;
  _memcpy((void *)puVar13[0x19],(void *)param_1[0x19],param_1[0x18] * 0x24);
  iVar7 = 0;
  if (0 < (int)param_1[0x18]) {
    iVar9 = 0;
    do {
      iVar7 = iVar7 + 1;
      *(int *)(iVar9 + 4 + puVar13[0x19]) =
           (*(int *)(iVar9 + 4 + param_1[0x19]) - param_1[2] >> 4) * 0x10 + puVar13[2];
      *(undefined4 **)(iVar9 + 0x1c + puVar13[0x19]) = puVar13;
      *(int *)(puVar13[0x19] + iVar9 + 0x10) = puVar13[0x19] + iVar9;
      iVar9 = iVar9 + 0x24;
    } while (iVar7 < (int)param_1[0x18]);
  }
  param_2 = (uint *)0x0;
  if (0 < (int)param_1[1]) {
    iVar7 = 0;
    do {
      iVar9 = puVar13[2];
      if (*(char *)(iVar9 + iVar7) == -0x80) {
        iVar9 = 0;
        if (0 < (int)param_1[0x13]) {
          piVar11 = (int *)param_1[0x14];
          do {
            if (*(int *)(iVar7 + 4 + param_1[2]) == *piVar11) {
              *(undefined4 *)(puVar13[2] + 4 + iVar7) = *(undefined4 *)(puVar13[0x14] + iVar9 * 4);
              break;
            }
            iVar9 = iVar9 + 1;
            piVar11 = piVar11 + 1;
          } while (iVar9 < (int)param_1[0x13]);
        }
      }
      else if (*(char *)(iVar9 + iVar7) == -0x7b) {
        *(int *)(iVar9 + 4 + iVar7) =
             (*(int *)(param_1[2] + 4 + iVar7) - param_1[2] >> 4) * 0x10 + iVar9;
      }
      param_2 = (uint *)((int)param_2 + 1);
      iVar7 = iVar7 + 0x10;
    } while ((int)param_2 < (int)param_1[1]);
  }
  if (param_1[0x23] == 0) {
    puVar13[0x23] = 0;
  }
  else {
    puVar13[0x23] = *puVar3 + 3 & 0xfffffffc;
    *puVar3 = (*puVar3 + 3 & 0xfffffffc) + 0x10;
    puVar14 = (undefined4 *)param_1[0x23];
    puVar16 = (undefined4 *)puVar13[0x23];
    *puVar16 = *puVar14;
    puVar16[1] = puVar14[1];
    puVar16[2] = puVar14[2];
    puVar16[3] = puVar14[3];
    *(undefined4 **)puVar13[0x23] = puVar13;
    *(undefined4 *)(puVar13[0x23] + 0xc) = DAT_00973fa8;
    DAT_00973fa8 = puVar13[0x23];
  }
  puVar13[0x20] = *puVar3 + 3 & 0xfffffffc;
  *puVar3 = (*puVar3 + 3 & 0xfffffffc) + 0x1a4;
  _memset((void *)puVar13[0x20],0,0x1a4);
  FUN_006039d0(param_1,puVar13,puVar3);
  (&DAT_009739bc)[DAT_009739b8] = puVar13;
  DAT_009739b8 = DAT_009739b8 + 1;
  FUN_005ddd10(1);
  param_2 = (uint *)0x0;
  if (0 < (int)puVar13[0x18]) {
    iVar7 = 0;
    do {
      *(uint *)(puVar13[0x19] + iVar7) = *(uint *)(puVar13[0x19] + iVar7) & 0x1ffff;
      if (DAT_00973ff4 != 0) {
        *(int *)(puVar13[0x19] + iVar7) = *(int *)(puVar13[0x19] + iVar7) + DAT_00973ff4 * 0x20000;
      }
      piVar11 = (int *)(puVar13[0x19] + iVar7);
      if (DAT_00973ecc == (int *)0x0) {
        DAT_00973ecc = piVar11;
        piVar11[2] = 0;
      }
      else {
        piVar6 = DAT_00973ecc;
        piVar12 = (int *)0x0;
        do {
          piVar5 = piVar6;
          piVar6 = piVar5;
          if (*piVar11 <= *piVar5) break;
          piVar6 = (int *)piVar5[2];
          piVar12 = piVar5;
        } while (piVar6 != (int *)0x0);
        if (piVar12 == (int *)0x0) {
          piVar11[2] = (int)DAT_00973ecc;
          DAT_00973ecc = piVar11;
        }
        else {
          piVar11[2] = (int)piVar6;
          piVar12[2] = (int)piVar11;
        }
      }
      DAT_00973ec8 = DAT_00973ec8 + 1;
      param_2 = (uint *)((int)param_2 + 1);
      iVar7 = iVar7 + 0x24;
    } while ((int)param_2 < (int)puVar13[0x18]);
  }
  puVar13[0x1d] = puVar13[0x1d] & 0xffffffef | 0x2000;
  FUN_00603980(puVar13);
  FUN_004ffac0(DAT_00973fa4);
  return puVar13;
}

