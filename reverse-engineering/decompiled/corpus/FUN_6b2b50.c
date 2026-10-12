/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b2b50; label: FUN_006b2b50
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b2b50(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  uint *puVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  undefined4 uStack_40;
  int *local_1c;
  int *local_14;
  int local_10;
  
  iVar3 = *(int *)(param_1[0x10] + 4);
  iVar4 = *(int *)(param_1[0x10] + 0x68);
  iVar27 = *(int *)(iVar3 + 0x1c);
  uVar5 = *(uint *)(iVar27 + param_1[7] * 4);
  param_1[9] = uVar5;
  iVar6 = *(int *)(iVar3 + 4);
  uStack_40 = 0x6b2b8e;
  puVar12 = (uint *)(&stack0xffffffc4 + iVar6 * -0xc);
  puVar19 = &stack0xffffffc4 + iVar6 * -0x10;
  puVar17 = &stack0xffffffc4 + iVar6 * -0x10;
  (&uStack_40)[-iVar6] = 0x6b2b98;
  (&uStack_40)[iVar6 * -2] = 0x6b2ba2;
  (&uStack_40)[iVar6 * -3] = 0x6b2bac;
  iVar24 = 0;
  if (0 < iVar6) {
    local_14 = param_2;
    do {
      local_14 = local_14 + 1;
      pcVar7 = *(code **)((&PTR_DAT_00817010)
                          [*(int *)(iVar27 + 800 + param_2[*local_14 + 0x101] * 4)] + 0x14);
      *(undefined4 *)(puVar17 + -4) =
           *(undefined4 *)(*(int *)(iVar4 + 0x30) + param_2[*local_14 + 0x101] * 4);
      *(int **)(puVar17 + -8) = param_1;
      puVar18 = puVar17 + -0xc;
      *(undefined4 *)(puVar17 + -0xc) = 0x6b2c08;
      uVar10 = (*pcVar7)();
      puVar12[-iVar6] = uVar10;
      iVar25 = *param_1;
      *(uint *)(puVar18 + -4) = (uVar5 & 0x3fffffff) << 1;
      *(undefined4 *)(puVar18 + -8) = 0;
      *puVar12 = (uint)(uVar10 != 0);
      *(undefined4 *)(puVar18 + -0xc) = *(undefined4 *)(iVar25 + iVar24 * 4);
      *(undefined4 *)(puVar18 + -0x10) = 0x6b2c28;
      _memset(*(void **)(puVar18 + -0xc),*(int *)(puVar18 + -8),*(size_t *)(puVar18 + -4));
      iVar24 = iVar24 + 1;
      puVar19 = puVar18 + 8;
      puVar17 = puVar18 + 8;
      puVar12 = puVar12 + 1;
    } while (iVar24 < *(int *)(iVar3 + 4));
  }
  iVar24 = param_2[0x121];
  if (0 < iVar24) {
    piVar11 = param_2 + 0x222;
    do {
      if ((*(int *)(&stack0xffffffc4 + piVar11[-0x100] * 4 + iVar6 * -0xc) != 0) ||
         (*(int *)(&stack0xffffffc4 + *piVar11 * 4 + iVar6 * -0xc) != 0)) {
        *(undefined4 *)(&stack0xffffffc4 + piVar11[-0x100] * 4 + iVar6 * -0xc) = 1;
        *(undefined4 *)(&stack0xffffffc4 + *piVar11 * 4 + iVar6 * -0xc) = 1;
      }
      piVar11 = piVar11 + 1;
      iVar24 = iVar24 + -1;
    } while (iVar24 != 0);
  }
  local_10 = 0;
  puVar23 = puVar19;
  if (0 < *param_2) {
    local_1c = param_2 + 0x111;
    do {
      iVar24 = 0;
      iVar25 = 0;
      puVar12 = (uint *)(&stack0xffffffc4 + iVar6 * -8);
      local_14 = param_2;
      if (0 < *(int *)(iVar3 + 4)) {
        do {
          local_14 = local_14 + 1;
          puVar13 = puVar12;
          if (*local_14 == local_10) {
            iVar25 = iVar25 + 1;
            puVar13 = puVar12 + 1;
            *puVar12 = (uint)(*(int *)(&stack0xffffffc4 + iVar24 * 4 + iVar6 * -0xc) != 0);
            puVar13[iVar6 + -1] = *(uint *)(*param_1 + iVar24 * 4);
          }
          iVar24 = iVar24 + 1;
          puVar12 = puVar13;
        } while (iVar24 < *(int *)(iVar3 + 4));
      }
      iVar24 = *local_1c;
      pcVar7 = *(code **)((&PTR_DAT_00817018)[*(int *)(iVar27 + 0x520 + iVar24 * 4)] + 0x1c);
      *(int *)(puVar19 + -4) = iVar25;
      *(undefined1 **)(puVar19 + -8) = &stack0xffffffc4 + iVar6 * -8;
      *(undefined1 **)(puVar19 + -0xc) = &stack0xffffffc4 + iVar6 * -4;
      *(undefined4 *)(puVar19 + -0x10) = *(undefined4 *)(*(int *)(iVar4 + 0x34) + iVar24 * 4);
      *(int **)(puVar19 + -0x14) = param_1;
      puVar20 = puVar19 + -0x18;
      *(undefined4 *)(puVar19 + -0x18) = 0x6b2d28;
      (*pcVar7)();
      local_1c = local_1c + 1;
      local_10 = local_10 + 1;
      puVar19 = puVar20 + 0x14;
      puVar23 = puVar20 + 0x14;
    } while (local_10 < *param_2);
  }
  iVar24 = param_2[0x121] + -1;
  if (-1 < iVar24) {
    iVar25 = (int)uVar5 / 2;
    piVar11 = param_2 + param_2[0x121] + 0x221;
    do {
      iVar8 = *(int *)(*param_1 + piVar11[-0x100] * 4);
      iVar16 = *(int *)(*param_1 + *piVar11 * 4);
      iVar28 = 0;
      if (3 < iVar25) {
        pfVar14 = (float *)(iVar8 + 4);
        iVar29 = iVar16 - iVar8;
        iVar26 = (iVar25 - 4U >> 2) + 1;
        pfVar15 = (float *)(iVar16 + 0xc);
        iVar28 = iVar26 * 4;
        do {
          fVar1 = pfVar14[-1];
          fVar2 = pfVar15[-3];
          if (fVar1 <= 0.0) {
            if (fVar2 <= 0.0) {
              pfVar15[-3] = fVar1;
              fVar1 = fVar1 - fVar2;
              goto LAB_006b2dfa;
            }
            pfVar15[-3] = fVar2 + fVar1;
          }
          else if (fVar2 <= 0.0) {
            pfVar15[-3] = fVar1;
            fVar1 = fVar1 + fVar2;
LAB_006b2dfa:
            pfVar14[-1] = fVar1;
          }
          else {
            pfVar15[-3] = fVar1 - fVar2;
          }
          fVar1 = *pfVar14;
          fVar2 = *(float *)(iVar29 + (int)pfVar14);
          if (fVar1 <= 0.0) {
            if (fVar2 <= 0.0) {
              *(float *)(iVar29 + (int)pfVar14) = fVar1;
              fVar1 = fVar1 - fVar2;
              goto LAB_006b2e43;
            }
            *(float *)(iVar29 + (int)pfVar14) = fVar2 + fVar1;
          }
          else if (fVar2 <= 0.0) {
            *(float *)(iVar29 + (int)pfVar14) = fVar1;
            fVar1 = fVar1 + fVar2;
LAB_006b2e43:
            *pfVar14 = fVar1;
          }
          else {
            *(float *)(iVar29 + (int)pfVar14) = fVar1 - fVar2;
          }
          fVar1 = pfVar14[1];
          fVar2 = pfVar15[-1];
          if (fVar1 <= 0.0) {
            if (fVar2 <= 0.0) {
              pfVar15[-1] = fVar1;
              fVar1 = fVar1 - fVar2;
              goto LAB_006b2e8c;
            }
            pfVar15[-1] = fVar2 + fVar1;
          }
          else if (fVar2 <= 0.0) {
            pfVar15[-1] = fVar1;
            fVar1 = fVar1 + fVar2;
LAB_006b2e8c:
            pfVar14[1] = fVar1;
          }
          else {
            pfVar15[-1] = fVar1 - fVar2;
          }
          fVar1 = pfVar14[2];
          fVar2 = *pfVar15;
          if (fVar1 <= 0.0) {
            if (fVar2 <= 0.0) {
              *pfVar15 = fVar1;
              fVar1 = fVar1 - fVar2;
              goto LAB_006b2ed1;
            }
            *pfVar15 = fVar2 + fVar1;
          }
          else if (fVar2 <= 0.0) {
            *pfVar15 = fVar1;
            fVar1 = fVar1 + fVar2;
LAB_006b2ed1:
            pfVar14[2] = fVar1;
          }
          else {
            *pfVar15 = fVar1 - fVar2;
          }
          pfVar14 = pfVar14 + 4;
          pfVar15 = pfVar15 + 4;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
      }
      if (iVar28 < iVar25) {
        pfVar14 = (float *)(iVar8 + iVar28 * 4);
        iVar16 = iVar16 - iVar8;
        iVar28 = iVar25 - iVar28;
        do {
          fVar1 = *pfVar14;
          fVar2 = *(float *)((int)pfVar14 + iVar16);
          if (fVar1 <= 0.0) {
            if (fVar2 <= 0.0) {
              *(float *)((int)pfVar14 + iVar16) = fVar1;
              fVar1 = fVar1 - fVar2;
              goto LAB_006b2f48;
            }
            *(float *)((int)pfVar14 + iVar16) = fVar2 + fVar1;
          }
          else if (fVar2 <= 0.0) {
            *(float *)((int)pfVar14 + iVar16) = fVar1;
            fVar1 = fVar1 + fVar2;
LAB_006b2f48:
            *pfVar14 = fVar1;
          }
          else {
            *(float *)((int)pfVar14 + iVar16) = fVar1 - fVar2;
          }
          pfVar14 = pfVar14 + 1;
          iVar28 = iVar28 + -1;
        } while (iVar28 != 0);
      }
      piVar11 = piVar11 + -1;
      iVar24 = iVar24 + -1;
    } while (-1 < iVar24);
  }
  iVar24 = 0;
  puVar21 = puVar23;
  piVar11 = param_2;
  if (0 < *(int *)(iVar3 + 4)) {
    do {
      iVar25 = param_2[piVar11[1] + 0x101];
      pcVar7 = *(code **)((&PTR_DAT_00817010)[*(int *)(iVar27 + 800 + iVar25 * 4)] + 0x18);
      *(undefined4 *)(puVar21 + -4) = *(undefined4 *)(*param_1 + iVar24 * 4);
      *(undefined4 *)(puVar21 + -8) = *(undefined4 *)(&stack0xffffffc4 + iVar24 * 4 + iVar6 * -0x10)
      ;
      *(undefined4 *)(puVar21 + -0xc) = *(undefined4 *)(*(int *)(iVar4 + 0x30) + iVar25 * 4);
      *(int **)(puVar21 + -0x10) = param_1;
      puVar22 = puVar21 + -0x14;
      *(undefined4 *)(puVar21 + -0x14) = 0x6b2fb6;
      (*pcVar7)();
      iVar24 = iVar24 + 1;
      puVar23 = puVar22 + 0x10;
      puVar21 = puVar22 + 0x10;
      piVar11 = piVar11 + 1;
    } while (iVar24 < *(int *)(iVar3 + 4));
  }
  iVar27 = 0;
  if (0 < *(int *)(iVar3 + 4)) {
    do {
      uVar9 = *(undefined4 *)(*param_1 + iVar27 * 4);
      iVar6 = param_1[7];
      *(undefined4 *)(puVar23 + -4) = uVar9;
      *(undefined4 *)(puVar23 + -8) = uVar9;
      *(undefined4 *)(puVar23 + -0xc) = **(undefined4 **)(iVar4 + 0xc + iVar6 * 4);
      *(undefined4 *)(puVar23 + -0x10) = 0x6b2fea;
      FUN_006afe00();
      iVar27 = iVar27 + 1;
    } while (iVar27 < *(int *)(iVar3 + 4));
  }
  return 0;
}

