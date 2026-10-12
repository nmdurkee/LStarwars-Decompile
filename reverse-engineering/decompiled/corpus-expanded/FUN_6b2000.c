/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b2000; label: FUN_006b2000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x006b244f) */
/* WARNING: Removing unreachable block (ram,0x006b23f5) */
/* WARNING: Removing unreachable block (ram,0x006b222e) */
/* WARNING: Removing unreachable block (ram,0x006b20f7) */
/* WARNING: Removing unreachable block (ram,0x006b21b4) */
/* WARNING: Removing unreachable block (ram,0x006b23c4) */
/* WARNING: Removing unreachable block (ram,0x006b2422) */
/* WARNING: Removing unreachable block (ram,0x006b24aa) */

undefined4 FUN_006b2000(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  code *pcVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  int *piVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int *piVar20;
  undefined4 uVar21;
  int iVar22;
  undefined4 uVar23;
  int iVar24;
  float *pfVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 *puVar28;
  int iVar29;
  int iVar30;
  uint *puVar31;
  int iVar32;
  int iVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  undefined1 *puVar37;
  int *piVar38;
  int iVar39;
  int aiStack_d4 [9];
  float fStack_b0;
  int aiStack_ac [3];
  float fStack_a0;
  size_t asStack_9c [3];
  float fStack_90;
  size_t sStack_8c;
  undefined1 *local_6c;
  int local_68;
  int *local_58;
  int local_50;
  int *local_48;
  float local_44;
  undefined4 *local_40;
  float *local_2c;
  int local_20;
  uint local_14;
  
  piVar17 = param_1;
  iVar1 = *(int *)(param_1[0x10] + 0x68);
  iVar2 = *(int *)(param_1[0x10] + 4);
  iVar3 = *(int *)(iVar2 + 4);
  iVar4 = *(int *)(iVar2 + 0x1c);
  iVar29 = param_1[0x1a];
  uVar5 = param_1[9];
  sStack_8c = 0x6b203b;
  iVar13 = iVar3 * -4;
  (&sStack_8c)[-iVar3] = iVar3 * 4;
  (&fStack_90)[-iVar3] = (float)param_1;
  asStack_9c[2 - iVar3] = 0x6b2045;
  puVar18 = (undefined4 *)FUN_006a1550();
  asStack_9c[2 - iVar3] = *(int *)(iVar2 + 4) * 4;
  asStack_9c[1 - iVar3] = (size_t)param_1;
  asStack_9c[-iVar3] = 0x6b2056;
  puVar19 = (undefined4 *)FUN_006a1550();
  asStack_9c[-iVar3] = *(int *)(iVar2 + 4) * 4;
  (&fStack_a0)[-iVar3] = (float)param_1;
  aiStack_ac[2 - iVar3] = 0x6b2067;
  piVar20 = (int *)FUN_006a1550();
  local_44 = *(float *)(iVar29 + 4);
  iVar6 = *(int *)(iVar2 + 4);
  (&sStack_8c)[-iVar3] = 0x6b2082;
  iVar14 = iVar6 * -4;
  local_2c = (float *)(&stack0xffffff78 + iVar14 + iVar13);
  iVar7 = param_1[7];
  piVar8 = *(int **)(iVar4 + 0x220 + iVar7 * 4);
  iVar32 = ((-(uint)(iVar7 != 0) & 2) + *(int *)(iVar29 + 8)) * 0x34 + *(int *)(iVar1 + 0x38);
  param_1[10] = iVar7;
  param_1 = (int *)0x0;
  if (0 < *(int *)(iVar2 + 4)) {
    fVar15 = ((float)(int)ABS(4.0 / (float)(int)uVar5) * 7.1771143e-07 - 764.6162) + 0.345;
    do {
      pfVar25 = *(float **)(*piVar17 + (int)param_1 * 4);
      (&sStack_8c)[-iVar3 - iVar6] = ((int)uVar5 / 2) * 4;
      (&fStack_90)[-iVar3 - iVar6] = (float)piVar17;
      asStack_9c[(-iVar3 - iVar6) + 2] = 0x6b2142;
      uVar21 = FUN_006a1550();
      *(undefined4 *)(((int)puVar18 - (int)(&stack0xffffff78 + iVar14 + iVar13)) + (int)local_2c) =
           uVar21;
      iVar30 = piVar17[7];
      iVar22 = piVar17[6];
      asStack_9c[(-iVar3 - iVar6) + 2] = piVar17[8];
      asStack_9c[(1 - iVar6) - iVar3] = iVar30;
      asStack_9c[-iVar3 - iVar6] = iVar22;
      (&fStack_a0)[-iVar3 - iVar6] = (float)iVar4;
      aiStack_ac[(2 - iVar6) - iVar3] = iVar1 + 4;
      aiStack_ac[(1 - iVar6) - iVar3] = (int)pfVar25;
      aiStack_ac[-iVar3 - iVar6] = 0x6b2168;
      FUN_006b19d0();
      iVar30 = piVar17[7];
      aiStack_ac[-iVar3 - iVar6] =
           *(undefined4 *)
            (((int)puVar18 - (int)(&stack0xffffff78 + iVar14 + iVar13)) + (int)local_2c);
      uVar21 = **(undefined4 **)(iVar1 + 0xc + iVar30 * 4);
      (&fStack_b0)[-iVar3 - iVar6] = (float)pfVar25;
      aiStack_d4[(8 - iVar6) - iVar3] = uVar21;
      aiStack_d4[(7 - iVar6) - iVar3] = 0x6b2185;
      FUN_006b0070();
      iVar30 = piVar17[7];
      aiStack_d4[(7 - iVar6) - iVar3] = (int)pfVar25;
      aiStack_d4[(6 - iVar6) - iVar3] = iVar1 + 0x14 + iVar30 * 0xc;
      aiStack_d4[(5 - iVar6) - iVar3] = 0x6b2199;
      FUN_006af1b0();
      local_6c = (undefined1 *)*pfVar25;
      iVar30 = 1;
      fVar16 = ((float)(int)ABS((float)local_6c) * 7.1771143e-07 - 764.6162) + fVar15 + 0.345;
      *pfVar25 = fVar16;
      *local_2c = fVar16;
      if (1 < (int)(uVar5 - 1)) {
        do {
          fVar16 = ((float)(int)ABS(pfVar25[iVar30] * pfVar25[iVar30] +
                                    pfVar25[iVar30 + 1] * pfVar25[iVar30 + 1]) * 7.1771143e-07 -
                   764.6162) * 0.5 + fVar15 + 0.345;
          pfVar25[iVar30 + 1 >> 1] = fVar16;
          if (*local_2c < fVar16) {
            *local_2c = fVar16;
          }
          iVar30 = iVar30 + 2;
        } while (iVar30 < (int)(uVar5 - 1));
      }
      if (0.0 < *local_2c) {
        *local_2c = 0.0;
      }
      if (local_44 < *local_2c) {
        local_44 = *local_2c;
      }
      param_1 = (int *)((int)param_1 + 1);
      local_2c = local_2c + 1;
    } while ((int)param_1 < *(int *)(iVar2 + 4));
  }
  iVar22 = (int)uVar5 / 2;
  iVar30 = iVar22 * 4;
  (&sStack_8c)[-iVar3 - iVar6] = iVar30;
  (&fStack_90)[-iVar3 - iVar6] = (float)piVar17;
  asStack_9c[(-iVar3 - iVar6) + 2] = 0x6b22db;
  uVar21 = FUN_006a1550();
  asStack_9c[(-iVar3 - iVar6) + 2] = iVar30;
  asStack_9c[(1 - iVar6) - iVar3] = (size_t)piVar17;
  asStack_9c[-iVar3 - iVar6] = 0x6b22e8;
  uVar23 = FUN_006a1550();
  param_1 = (int *)0x0;
  if (0 < *(int *)(iVar2 + 4)) {
    local_6c = &stack0xffffff78 + ((iVar14 + iVar13) - (int)piVar20);
    piVar38 = piVar20;
    local_58 = piVar8;
    do {
      local_58 = local_58 + 1;
      iVar39 = *local_58;
      iVar9 = *(int *)((int)puVar18 +
                      (int)piVar38 + ((int)local_6c - (int)(&stack0xffffff78 + iVar14 + iVar13)));
      iVar10 = *(int *)(*piVar17 + (int)param_1 * 4);
      (&sStack_8c)[-iVar3 - iVar6] = 0x3c;
      (&fStack_90)[-iVar3 - iVar6] = (float)piVar17;
      iVar33 = iVar30 + iVar10;
      piVar17[10] = iVar7;
      asStack_9c[(-iVar3 - iVar6) + 2] = 0x6b2355;
      iVar24 = FUN_006a1550();
      asStack_9c[(-iVar3 - iVar6) + 2] = 0x3c;
      asStack_9c[(1 - iVar6) - iVar3] = 0;
      asStack_9c[-iVar3 - iVar6] = iVar24;
      *piVar38 = iVar24;
      (&fStack_a0)[-iVar3 - iVar6] = 9.83909e-39;
      _memset((void *)asStack_9c[-iVar3 - iVar6],asStack_9c[(1 - iVar6) - iVar3],
              asStack_9c[(-iVar3 - iVar6) + 2]);
      local_50 = 0;
      if (3 < iVar22) {
        puVar31 = (uint *)(iVar9 + 0xc);
        local_68 = (iVar22 - 4U >> 2) + 1;
        local_50 = local_68 * 4;
        pfVar25 = (float *)(iVar33 + 4);
        do {
          pfVar25[-1] = ((float)(puVar31[-3] & 0x7fffffff) * 7.1771143e-07 - 764.6162) + 0.345;
          *pfVar25 = ((float)(*(uint *)((iVar9 - iVar33) + (int)pfVar25) & 0x7fffffff) *
                      7.1771143e-07 - 764.6162) + 0.345;
          pfVar25[1] = ((float)(puVar31[-1] & 0x7fffffff) * 7.1771143e-07 - 764.6162) + 0.345;
          local_14 = *puVar31;
          puVar31 = puVar31 + 4;
          local_68 = local_68 + -1;
          pfVar25[2] = ((float)(local_14 & 0x7fffffff) * 7.1771143e-07 - 764.6162) + 0.345;
          pfVar25 = pfVar25 + 4;
        } while (local_68 != 0);
      }
      if (local_50 < iVar22) {
        iVar24 = iVar22 - local_50;
        pfVar25 = (float *)(iVar33 + local_50 * 4);
        do {
          local_14 = *(uint *)((int)pfVar25 + (iVar9 - iVar33));
          iVar24 = iVar24 + -1;
          *pfVar25 = ((float)(local_14 & 0x7fffffff) * 7.1771143e-07 - 764.6162) + 0.345;
          pfVar25 = pfVar25 + 1;
        } while (iVar24 != 0);
      }
      (&sStack_8c)[-iVar3 - iVar6] = uVar21;
      (&fStack_90)[-iVar3 - iVar6] = (float)iVar33;
      asStack_9c[(-iVar3 - iVar6) + 2] = iVar32;
      asStack_9c[(1 - iVar6) - iVar3] = 0x6b24db;
      FUN_006a6670();
      (&sStack_8c)[-iVar3 - iVar6] = *(size_t *)(local_6c + (int)piVar38);
      (&fStack_90)[-iVar3 - iVar6] = local_44;
      asStack_9c[(-iVar3 - iVar6) + 2] = uVar23;
      asStack_9c[(1 - iVar6) - iVar3] = iVar10;
      asStack_9c[-iVar3 - iVar6] = iVar32;
      (&fStack_a0)[-iVar3 - iVar6] = 9.839675e-39;
      FUN_006a6860();
      (&fStack_a0)[-iVar3 - iVar6] = (float)iVar33;
      aiStack_ac[(2 - iVar6) - iVar3] = iVar9;
      aiStack_ac[(1 - iVar6) - iVar3] = iVar10;
      aiStack_ac[-iVar3 - iVar6] = 1;
      (&fStack_b0)[-iVar3 - iVar6] = (float)uVar23;
      aiStack_d4[(8 - iVar6) - iVar3] = uVar21;
      aiStack_d4[(7 - iVar6) - iVar3] = iVar32;
      aiStack_d4[(6 - iVar6) - iVar3] = 0x6b251f;
      FUN_006a69b0();
      iVar24 = piVar8[iVar39 + 0x101];
      if (*(int *)(iVar4 + 800 + iVar24 * 4) != 1) {
        return 0xffffffff;
      }
      (&sStack_8c)[-iVar3 - iVar6] = iVar10;
      uVar26 = *(undefined4 *)(*(int *)(iVar1 + 0x30) + iVar24 * 4);
      (&fStack_90)[-iVar3 - iVar6] = (float)iVar33;
      asStack_9c[(-iVar3 - iVar6) + 2] = uVar26;
      asStack_9c[(1 - iVar6) - iVar3] = (size_t)piVar17;
      asStack_9c[-iVar3 - iVar6] = 0x6b2555;
      uVar26 = FUN_006b5a10();
      iVar24 = *piVar38;
      asStack_9c[-iVar3 - iVar6] = (size_t)piVar17;
      *(undefined4 *)(iVar24 + 0x1c) = uVar26;
      (&fStack_a0)[-iVar3 - iVar6] = 9.839806e-39;
      iVar24 = FUN_006b0470();
      if ((iVar24 != 0) && (*(int *)(*piVar38 + 0x1c) != 0)) {
        (&sStack_8c)[-iVar3 - iVar6] = iVar33;
        (&fStack_90)[-iVar3 - iVar6] = (float)iVar9;
        asStack_9c[(-iVar3 - iVar6) + 2] = iVar10;
        asStack_9c[(1 - iVar6) - iVar3] = 2;
        asStack_9c[-iVar3 - iVar6] = uVar23;
        (&fStack_a0)[-iVar3 - iVar6] = (float)uVar21;
        aiStack_ac[(2 - iVar6) - iVar3] = iVar32;
        aiStack_ac[(1 - iVar6) - iVar3] = 0x6b2593;
        FUN_006a69b0();
        aiStack_ac[(1 - iVar6) - iVar3] = iVar10;
        uVar26 = *(undefined4 *)(*(int *)(iVar1 + 0x30) + piVar8[iVar39 + 0x101] * 4);
        aiStack_ac[-iVar3 - iVar6] = iVar33;
        (&fStack_b0)[-iVar3 - iVar6] = (float)uVar26;
        aiStack_d4[(8 - iVar6) - iVar3] = (int)piVar17;
        aiStack_d4[(7 - iVar6) - iVar3] = 0x6b25b5;
        uVar26 = FUN_006b5a10();
        iVar24 = *piVar38;
        aiStack_d4[(7 - iVar6) - iVar3] = iVar33;
        aiStack_d4[(6 - iVar6) - iVar3] = iVar9;
        *(undefined4 *)(iVar24 + 0x38) = uVar26;
        aiStack_d4[(5 - iVar6) - iVar3] = iVar10;
        aiStack_d4[(4 - iVar6) - iVar3] = 0;
        aiStack_d4[(3 - iVar6) - iVar3] = uVar23;
        aiStack_d4[(2 - iVar6) - iVar3] = uVar21;
        aiStack_d4[(1 - iVar6) - iVar3] = iVar32;
        aiStack_d4[-iVar3 - iVar6] = 0x6b25d6;
        FUN_006a69b0();
        (&sStack_8c)[-iVar3 - iVar6] = iVar10;
        uVar26 = *(undefined4 *)(*(int *)(iVar1 + 0x30) + piVar8[iVar39 + 0x101] * 4);
        (&fStack_90)[-iVar3 - iVar6] = (float)iVar33;
        asStack_9c[(-iVar3 - iVar6) + 2] = uVar26;
        asStack_9c[(1 - iVar6) - iVar3] = (size_t)piVar17;
        asStack_9c[-iVar3 - iVar6] = 0x6b25fb;
        uVar26 = FUN_006b5a10();
        *(undefined4 *)*piVar38 = uVar26;
        local_68 = 4;
        iVar33 = 0x10000;
        do {
          puVar28 = (undefined4 *)*piVar38;
          uVar26 = puVar28[7];
          (&sStack_8c)[-iVar3 - iVar6] = iVar33 / 7;
          uVar27 = *puVar28;
          (&fStack_90)[-iVar3 - iVar6] = (float)uVar26;
          asStack_9c[(-iVar3 - iVar6) + 2] = uVar27;
          asStack_9c[(1 - iVar6) - iVar3] =
               *(undefined4 *)(*(int *)(iVar1 + 0x30) + piVar8[iVar39 + 0x101] * 4);
          asStack_9c[-iVar3 - iVar6] = (size_t)piVar17;
          (&fStack_a0)[-iVar3 - iVar6] = 9.840134e-39;
          uVar26 = FUN_006b5ed0();
          *(undefined4 *)(local_68 + *piVar38) = uVar26;
          iVar33 = iVar33 + 0x10000;
          local_68 = local_68 + 4;
        } while (iVar33 < 0x70000);
        local_68 = 0x20;
        iVar33 = 0x10000;
        do {
          iVar9 = *piVar38;
          uVar26 = *(undefined4 *)(iVar9 + 0x38);
          (&sStack_8c)[-iVar3 - iVar6] = iVar33 / 7;
          uVar27 = *(undefined4 *)(iVar9 + 0x1c);
          (&fStack_90)[-iVar3 - iVar6] = (float)uVar26;
          asStack_9c[(-iVar3 - iVar6) + 2] = uVar27;
          asStack_9c[(1 - iVar6) - iVar3] =
               *(undefined4 *)(*(int *)(iVar1 + 0x30) + piVar8[iVar39 + 0x101] * 4);
          asStack_9c[-iVar3 - iVar6] = (size_t)piVar17;
          (&fStack_a0)[-iVar3 - iVar6] = 9.840277e-39;
          uVar26 = FUN_006b5ed0();
          *(undefined4 *)(local_68 + *piVar38) = uVar26;
          iVar33 = iVar33 + 0x10000;
          local_68 = local_68 + 4;
        } while (iVar33 < 0x70000);
      }
      param_1 = (int *)((int)param_1 + 1);
      piVar38 = piVar38 + 1;
    } while ((int)param_1 < *(int *)(iVar2 + 4));
  }
  *(float *)(iVar29 + 4) = local_44;
  iVar22 = *(int *)(iVar2 + 4);
  (&sStack_8c)[-iVar3 - iVar6] = 0x6b2708;
  (&sStack_8c)[(-iVar6 - iVar22) - iVar3] = 0x6b2713;
  (&sStack_8c)[(iVar22 * -2 - iVar6) - iVar3] = 0x6b271e;
  (&sStack_8c)[(iVar22 * -3 - iVar6) - iVar3] = 0x6b2729;
  if (piVar8[0x121] != 0) {
    (&sStack_8c)[(iVar22 * -4 - iVar6) - iVar3] = (size_t)puVar18;
    (&fStack_90)[(iVar22 * -4 - iVar6) - iVar3] = (float)piVar8;
    asStack_9c[((iVar22 * -4 - iVar6) - iVar3) + 2] = iVar32;
    asStack_9c[((iVar22 * -4 + 1) - iVar6) - iVar3] = iVar4 + 0xb34;
    asStack_9c[(iVar22 * -4 - iVar6) - iVar3] = (size_t)piVar17;
    (&fStack_a0)[(iVar22 * -4 - iVar6) - iVar3] = 9.840497e-39;
    local_6c = (undefined1 *)FUN_006a7250();
    (&fStack_a0)[(iVar22 * -4 - iVar6) - iVar3] = (float)local_6c;
    aiStack_ac[((iVar22 * -4 + 2) - iVar6) - iVar3] = (int)piVar8;
    aiStack_ac[((iVar22 * -4 + 1) - iVar6) - iVar3] = iVar32;
    aiStack_ac[(iVar22 * -4 - iVar6) - iVar3] = (int)piVar17;
    (&fStack_b0)[(iVar22 * -4 - iVar6) - iVar3] = 9.840518e-39;
    local_14 = FUN_006a7430();
    (&fStack_b0)[(iVar22 * -4 - iVar6) - iVar3] = (float)local_6c;
    aiStack_d4[((iVar22 * -4 + 8) - iVar6) - iVar3] = (int)piVar8;
    aiStack_d4[((iVar22 * -4 + 7) - iVar6) - iVar3] = iVar32;
    aiStack_d4[((iVar22 * -4 + 6) - iVar6) - iVar3] = iVar4 + 0xb34;
    aiStack_d4[((iVar22 * -4 + 5) - iVar6) - iVar3] = 0x6b2776;
    FUN_006a7d60();
  }
  (&sStack_8c)[(iVar22 * -4 - iVar6) - iVar3] = *(int *)(iVar2 + 4) * 4;
  (&fStack_90)[(iVar22 * -4 - iVar6) - iVar3] = 0.0;
  asStack_9c[((iVar22 * -4 - iVar6) - iVar3) + 2] =
       (size_t)(&stack0xffffff78 + iVar22 * -0x10 + iVar14 + iVar13);
  asStack_9c[((iVar22 * -4 + 1) - iVar6) - iVar3] = 0x6b278c;
  _memset((void *)asStack_9c[((iVar22 * -4 - iVar6) - iVar3) + 2],
          (int)(&fStack_90)[(iVar22 * -4 - iVar6) - iVar3],
          (&sStack_8c)[(iVar22 * -4 - iVar6) - iVar3]);
  puVar34 = &stack0xffffff78 + iVar22 * -0x10 + iVar14 + iVar13;
  if ((*(int *)(*(int *)(iVar32 + 4) + 500) != 0) &&
     (param_1 = (int *)0x0, puVar34 = &stack0xffffff78 + iVar22 * -0x10 + iVar14 + iVar13,
     0 < *(int *)(iVar2 + 4))) {
    puVar37 = &stack0xffffff78 + iVar22 * -0x10 + iVar14 + iVar13;
    local_58 = puVar18;
    do {
      *(undefined4 *)(puVar37 + -4) = 0x6b27dc;
      iVar33 = (uVar5 & 0x3fffffff) * -2;
      puVar34 = puVar37 + iVar33;
      *(undefined1 **)(puVar37 + iVar33 + -4) = puVar37 + iVar33;
      *(undefined1 **)
       (&stack0xffffff78 + ((iVar22 * -0x10 + iVar14 + iVar13) - (int)puVar18) + (int)local_58) =
           puVar37 + iVar33;
      *(int *)(puVar37 + iVar33 + -8) = *local_58;
      *(int *)(puVar37 + iVar33 + -0xc) = iVar32;
      *(undefined4 *)(puVar37 + iVar33 + -0x10) = 0x6b27f1;
      FUN_006a7570();
      local_58 = local_58 + 1;
      param_1 = (int *)((int)param_1 + 1);
      puVar37 = puVar37 + iVar33;
    } while ((int)param_1 < *(int *)(iVar2 + 4));
  }
  *(int **)(puVar34 + -4) = piVar17;
  *(undefined4 *)(puVar34 + -8) = 0x6b280c;
  iVar33 = FUN_006b0470();
  local_20 = (-(uint)(iVar33 != 0) & 0xfffffff9) + 7;
  *(int **)(puVar34 + -8) = piVar17;
  *(undefined4 *)(puVar34 + -0xc) = 0x6b281f;
  iVar33 = FUN_006b0470();
  if (local_20 <= (int)((-(uint)(iVar33 != 0) & 7) + 7)) {
    local_44 = (float)(local_20 * 4);
    local_40 = (undefined4 *)(iVar29 + 0xc + local_20 * 4);
    do {
      uVar21 = *local_40;
      *(undefined4 *)(puVar34 + -4) = 1;
      *(undefined4 *)(puVar34 + -8) = 0;
      *(undefined4 *)(puVar34 + -0xc) = uVar21;
      *(undefined4 *)(puVar34 + -0x10) = 0x6b285f;
      FUN_006a3570();
      *(undefined4 *)(puVar34 + -0x10) = *(undefined4 *)(iVar1 + 0x2c);
      *(int *)(puVar34 + -0x14) = iVar7;
      *(undefined4 *)(puVar34 + -0x18) = uVar21;
      *(undefined4 *)(puVar34 + -0x1c) = 0x6b2873;
      FUN_006a3570();
      if (piVar17[7] != 0) {
        iVar29 = piVar17[6];
        *(undefined4 *)(puVar34 + -4) = 1;
        *(int *)(puVar34 + -8) = iVar29;
        *(undefined4 *)(puVar34 + -0xc) = uVar21;
        *(undefined4 *)(puVar34 + -0x10) = 0x6b288b;
        FUN_006a3570();
        iVar29 = piVar17[8];
        *(undefined4 *)(puVar34 + -0x10) = 1;
        *(int *)(puVar34 + -0x14) = iVar29;
        *(undefined4 *)(puVar34 + -0x18) = uVar21;
        *(undefined4 *)(puVar34 + -0x1c) = 0x6b289a;
        FUN_006a3570();
      }
      param_1 = (int *)0x0;
      if (0 < *(int *)(iVar2 + 4)) {
        puVar28 = puVar19;
        local_58 = piVar8;
        do {
          local_58 = local_58 + 1;
          uVar23 = *(undefined4 *)(((int)puVar18 - (int)puVar19) + (int)puVar28);
          iVar29 = *local_58;
          iVar33 = *(int *)(*piVar17 + (int)param_1 * 4);
          *(int *)(puVar34 + -4) = iVar30;
          *(int **)(puVar34 + -8) = piVar17;
          *(undefined4 *)(puVar34 + -0xc) = 0x6b2903;
          uVar26 = FUN_006a1550();
          *puVar28 = uVar26;
          iVar39 = *(int *)(((int)piVar20 - (int)puVar19) + (int)puVar28);
          *(undefined4 *)(puVar34 + -0xc) = uVar26;
          *(undefined4 *)(puVar34 + -0x10) = *(undefined4 *)(iVar39 + (int)local_44);
          *(undefined4 *)(puVar34 + -0x14) =
               *(undefined4 *)(*(int *)(iVar1 + 0x30) + piVar8[iVar29 + 0x101] * 4);
          *(int **)(puVar34 + -0x18) = piVar17;
          *(undefined4 *)(puVar34 + -0x1c) = uVar21;
          *(undefined4 *)(puVar34 + -0x20) = 0x6b2937;
          uVar27 = FUN_006b5f80();
          *(undefined4 *)(&stack0xffffff78 + (iVar13 - (int)puVar19) + (int)puVar28) = uVar27;
          *(undefined4 *)(puVar34 + -0x20) =
               *(undefined4 *)(iVar4 + ((piVar17[7] + 0x36) * 0xf + local_20) * 4);
          *(int *)(puVar34 + -0x24) = iVar33;
          *(undefined4 *)(puVar34 + -0x28) = uVar26;
          *(undefined4 *)(puVar34 + -0x2c) = uVar23;
          *(int *)(puVar34 + -0x30) = iVar32;
          *(undefined4 *)(puVar34 + -0x34) = 0x6b2966;
          FUN_006a6560();
          *(undefined4 *)(puVar34 + -0x34) =
               *(undefined4 *)
                (&stack0xffffff78 + ((iVar22 * -0x10 + iVar14 + iVar13) - (int)puVar19) +
                (int)puVar28);
          *(int *)(puVar34 + -0x38) = iVar33 + iVar30;
          *(int *)(puVar34 + -0x3c) = iVar33;
          *(int *)(puVar34 + -0x40) = iVar32;
          *(undefined4 *)(puVar34 + -0x44) = 0x6b297e;
          FUN_006a7620();
          param_1 = (int *)((int)param_1 + 1);
          puVar28 = puVar28 + 1;
        } while ((int)param_1 < *(int *)(iVar2 + 4));
      }
      if (piVar8[0x121] != 0) {
        *(undefined4 *)(puVar34 + -4) =
             *(undefined4 *)(iVar4 + ((piVar17[7] + 0x36) * 0xf + local_20) * 4);
        *(undefined1 **)(puVar34 + -8) = &stack0xffffff78 + iVar13;
        *(undefined4 **)(puVar34 + -0xc) = puVar19;
        *(uint *)(puVar34 + -0x10) = local_14;
        *(undefined1 **)(puVar34 + -0x14) = local_6c;
        *(int *)(puVar34 + -0x18) = *piVar17;
        *(int **)(puVar34 + -0x1c) = piVar8;
        *(int *)(puVar34 + -0x20) = iVar32;
        *(int *)(puVar34 + -0x24) = iVar4 + 0xb34;
        *(int *)(puVar34 + -0x28) = local_20;
        *(undefined4 *)(puVar34 + -0x2c) = 0x6b29ec;
        FUN_006a7910();
      }
      param_1 = (int *)0x0;
      puVar37 = puVar34;
      if (0 < *piVar8) {
        local_48 = piVar8 + 0x111;
        do {
          iVar29 = *local_48;
          iVar33 = 0;
          iVar39 = 0;
          puVar28 = (undefined4 *)(&stack0xffffff78 + iVar22 * -0xc + iVar14 + iVar13);
          local_58 = piVar8;
          if (0 < *(int *)(iVar2 + 4)) {
            do {
              local_58 = local_58 + 1;
              if ((int *)*local_58 == param_1) {
                *puVar28 = 0;
                if (*(int *)(&stack0xffffff78 + iVar33 * 4 + iVar13) != 0) {
                  *puVar28 = 1;
                }
                iVar9 = *(int *)(*piVar17 + iVar33 * 4);
                puVar28[iVar22 * 2] = iVar9;
                puVar28[iVar6 + iVar3 + iVar22 + (-iVar6 - iVar3)] = iVar9 + iVar30;
                iVar39 = iVar39 + 1;
                puVar28 = puVar28 + 1;
              }
              iVar33 = iVar33 + 1;
            } while (iVar33 < *(int *)(iVar2 + 4));
          }
          puVar11 = (&PTR_DAT_00817018)[*(int *)(iVar4 + 0x520 + iVar29 * 4)];
          *(int *)(puVar34 + -4) = iVar39;
          *(undefined1 **)(puVar34 + -8) = &stack0xffffff78 + iVar22 * -0xc + iVar14 + iVar13;
          *(undefined1 **)(puVar34 + -0xc) = &stack0xffffff78 + iVar22 * -8 + iVar14 + iVar13;
          pcVar12 = *(code **)(puVar11 + 0x14);
          *(undefined4 *)(puVar34 + -0x10) = *(undefined4 *)(*(int *)(iVar1 + 0x34) + iVar29 * 4);
          *(int **)(puVar34 + -0x14) = piVar17;
          puVar35 = puVar34 + -0x18;
          *(undefined4 *)(puVar34 + -0x18) = 0x6b2ab7;
          uVar23 = (*pcVar12)();
          pcVar12 = *(code **)((&PTR_DAT_00817018)[*(int *)(iVar4 + 0x520 + iVar29 * 4)] + 0x18);
          *(undefined4 *)(puVar35 + -4) = uVar23;
          *(int *)(puVar35 + -8) = iVar39;
          *(undefined1 **)(puVar35 + -0xc) = &stack0xffffff78 + iVar22 * -0xc + iVar14 + iVar13;
          *(undefined4 *)(puVar35 + -0x10) = 0;
          *(undefined1 **)(puVar35 + -0x14) = &stack0xffffff78 + iVar22 * -8 + iVar14 + iVar13;
          *(undefined4 *)(puVar35 + -0x18) = *(undefined4 *)(*(int *)(iVar1 + 0x34) + iVar29 * 4);
          *(int **)(puVar35 + -0x1c) = piVar17;
          *(undefined4 *)(puVar35 + -0x20) = uVar21;
          puVar36 = puVar35 + -0x24;
          *(undefined4 *)(puVar35 + -0x24) = 0x6b2ae8;
          (*pcVar12)();
          local_48 = local_48 + 1;
          param_1 = (int *)((int)param_1 + 1);
          puVar34 = puVar36 + 0x34;
          puVar37 = puVar36 + 0x34;
        } while ((int)param_1 < *piVar8);
      }
      local_20 = local_20 + 1;
      local_44 = (float)((int)local_44 + 4);
      local_40 = local_40 + 1;
      *(int **)(puVar37 + -4) = piVar17;
      *(undefined4 *)(puVar37 + -8) = 0x6b2b1e;
      iVar29 = FUN_006b0470();
      puVar34 = puVar37;
    } while (local_20 <= (int)((-(uint)(iVar29 != 0) & 7) + 7));
  }
  return 0;
}

