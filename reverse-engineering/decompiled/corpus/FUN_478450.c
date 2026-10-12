/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x478450; label: FUN_00478450
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478450(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  undefined *puVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  float10 extraout_ST0;
  float10 fVar17;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar18;
  short local_20c;
  float local_208;
  undefined **local_200;
  float local_1f8;
  int local_1f4;
  int local_1ec;
  int local_1e8;
  undefined1 local_1e0 [48];
  float local_1b0;
  float local_1ac;
  float local_1a8;
  undefined4 local_1a0 [12];
  float fStack_170;
  undefined4 uStack_16c;
  float fStack_168;
  undefined1 local_160 [64];
  uint auStack_120 [72];
  
  if ((*(int *)(param_1 + 0x2984) != 0) && (*(int *)(param_1 + 0x2ae0) != 0)) {
    iVar14 = 0;
    iVar13 = -1;
    uVar8 = 0;
    local_1ec = 0;
    local_1f4 = -1;
    if (0 < DAT_00951360) {
      pbVar11 = (byte *)(DAT_00951354 + 0x7a);
      do {
        if ((*pbVar11 & 0x10) != 0) {
          if (uVar8 == DAT_00879b34) {
            iVar13 = iVar14;
            local_1f4 = iVar14;
          }
          auStack_120[iVar14] = uVar8;
          iVar14 = iVar14 + 1;
        }
        uVar8 = uVar8 + 1;
        pbVar11 = pbVar11 + 0x9c;
        local_1ec = iVar14;
      } while ((int)uVar8 < DAT_00951360);
    }
    local_1e8 = 0;
    if (0 < local_1ec) {
      do {
        fVar18 = (float10)32768.0;
        fVar17 = (float10)0.5;
        uVar8 = auStack_120[local_1e8];
        iVar14 = *(int *)(param_1 + 0x2984);
        iVar12 = uVar8 * 0x7c + *(int *)(param_1 + 0x2ae0);
        if ((*(int *)(iVar14 + uVar8 * 4) != 0) &&
           (*(short *)(uVar8 * 0x9c + 0x8a + DAT_00951354) != -1)) {
          local_200 = &PTR_s_negotiations_007f9368;
          puVar7 = PTR_s_negotiations_007f9368;
          while (puVar7 != (undefined *)0x0) {
            if ((local_200[8] != (undefined *)0x0) && ((byte)local_200[8][0x7c] == uVar8))
            goto LAB_00478593;
            local_200 = local_200 + 0xf;
            puVar7 = *local_200;
          }
          local_200 = (undefined **)0x0;
LAB_00478593:
          if (uVar8 == auStack_120[(local_1ec + -2 + iVar13) % local_1ec]) {
            local_208 = -_DAT_007f9344 * 2.0;
          }
          else if (uVar8 == auStack_120[(local_1ec + -1 + iVar13) % local_1ec]) {
            local_208 = -_DAT_007f9344;
          }
          else if (uVar8 == auStack_120[iVar13]) {
            local_208 = 0.0;
          }
          else if (uVar8 == auStack_120[(iVar13 + 1) % local_1ec]) {
            local_208 = _DAT_007f9344;
          }
          else {
            if (uVar8 != auStack_120[(iVar13 + 2) % local_1ec]) goto LAB_00478a8b;
            local_208 = _DAT_007f9344 * 2.0;
          }
          local_1f8 = _DAT_007f9334 + local_208;
          if (0.0 < _DAT_00879b44) {
            iVar13 = FUN_006e6b90();
            local_1f8 = (float)((float10)local_1f8 +
                               (float10)_DAT_00879b40 *
                               (float10)(float)(fVar17 - ((float10)(float)(&DAT_029899a0)
                                                                          [iVar13 >> 1 & 0x7fff] +
                                                         fVar17) * extraout_ST1) * fVar18);
            fVar17 = extraout_ST1;
          }
          fVar1 = *(float *)(iVar12 + 0xc);
          iVar14 = *(int *)(iVar14 + uVar8 * 4);
          iVar13 = FUN_006e6b90();
          fVar2 = (float)(&DAT_029899a0)[iVar13 >> 1 & 0x7fff];
          fVar3 = (float)(&DAT_029899a0)[*(int *)(iVar12 + 0x14) >> 1 & 0x7fff];
          fVar4 = (float)(&DAT_029899a0)[*(int *)(iVar12 + 0x24) >> 1 & 0x7fff];
          iVar13 = FUN_00550040(0,(int)ROUND((float10)(float)(&DAT_029899a0)
                                                             [*(int *)(iVar12 + 0x1c) >> 1 & 0x7fff]
                                             * fVar17) & 0xffff);
          local_20c = (short)(int)ROUND(fVar1 * (float)iVar13);
          sVar6 = *(short *)(iVar12 + 0x34);
          fVar5 = (float)(&DAT_029899a0)[*(int *)(iVar12 + 0x2c) >> 1 & 0x7fff];
          FUN_00550040(0,*(undefined2 *)(iVar12 + 0x38));
          FUN_006e6b90();
          FUN_004748a0();
          FUN_00550040(0,(int)ROUND((float10)fVar3 * fVar17) & 0xffff);
          FUN_006e6b90();
          FUN_004749f0();
          FUN_00550040(0,(int)ROUND(fVar17 * (float10)fVar4) & 0xffff);
          FUN_006e6b90();
          FUN_00474bb0();
          FUN_00474ad0();
          local_1b0 = *(float *)(iVar12 + 0x6c) + local_1f8;
          if (local_200 == (undefined **)0x0) {
            puVar7 = (undefined *)0x0;
          }
          else {
            puVar7 = local_200[5];
          }
          local_1ac = fVar5 * 0.025 * fVar1 +
                      (float)((extraout_ST0 - ((float10)fVar2 + extraout_ST0) * extraout_ST1_00) *
                             (float10)0.3330000042915344) + (float)puVar7 + _DAT_007f9338;
          local_1a8 = _DAT_007f933c + *(float *)(iVar12 + 0x70);
          FUN_00550040(0,*(undefined2 *)(iVar12 + 0x36));
          uVar9 = FUN_006e6b90();
          FUN_005b5240(local_1e0,uVar9);
          local_200 = (undefined **)0x0;
          if (*(char *)(iVar14 + 8) != '\0') {
            local_208 = 0.0;
            do {
              if (((*(char *)((int)local_208 + 0x66 + *(int *)(iVar14 + 4)) != '\0') &&
                  (iVar13 = FUN_005cfac0((int)local_208 + *(int *)(iVar14 + 4)), iVar13 != 0)) &&
                 ((int)local_200 < (int)(uint)*(byte *)(iVar12 + 0x3c))) {
                puVar15 = (undefined4 *)((int)local_208 + 0xc + *(int *)(iVar14 + 4));
                puVar16 = local_1a0;
                for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
                  *puVar16 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar16 = puVar16 + 1;
                }
                FUN_005c0500(local_1a0,local_1a0,local_1e0);
                uVar9 = FUN_005f33b0(*(int *)(iVar14 + 4) + (int)local_208,local_1a0);
                if ((_DAT_007f934c != 2e+06) &&
                   (iVar13 = FUN_00550490(local_1a0,2,_DAT_007f934c,0x49f42400,local_160),
                   iVar13 != 0)) {
                  FUN_005d4690(uVar9);
                  FUN_005f33b0(*(int *)(iVar14 + 4) + (int)local_208,local_160);
                  FUN_005d46b0();
                }
              }
              local_200 = (undefined **)((int)local_200 + 1);
              local_208 = (float)((int)local_208 + 0x68);
            } while ((int)local_200 < (int)(uint)*(byte *)(iVar14 + 8));
          }
          iVar10 = FUN_005cfac0(iVar14 + 0xc);
          iVar13 = local_1f4;
          if (iVar10 != 0) {
            FUN_005b4670(local_1a0,local_20c + sVar6);
            fStack_170 = local_1f8;
            uStack_16c = _DAT_007f9340;
            fStack_168 = _DAT_007f933c;
            FUN_005ff7a0(iVar14 + 0xc,local_1a0,1.0 - *(float *)(iVar12 + 0xc) * 0.5);
          }
        }
LAB_00478a8b:
        local_1e8 = local_1e8 + 1;
      } while (local_1e8 < local_1ec);
    }
    FUN_00595660(*(undefined4 *)(param_1 + 0x2ab4),0x3f800000);
  }
  return;
}

