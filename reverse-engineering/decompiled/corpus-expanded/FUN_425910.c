/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x425910; label: FUN_00425910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00425910(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  float fVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  ushort *puVar12;
  float **ppfVar13;
  float *pfVar14;
  float10 fVar15;
  uint local_a8;
  int *local_a4;
  int local_a0;
  short *local_9c;
  uint local_98;
  int local_94;
  float *local_90;
  ushort *local_8c;
  float local_88;
  int local_84;
  uint local_80;
  int local_7c;
  short *local_78;
  float *local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  float *local_50 [5];
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined1 local_1;
  
  local_64 = FUN_006e6b90();
  local_60 = FUN_006e6b90();
  local_58 = FUN_006e6b90();
  local_5c = FUN_006e6b90();
  if (param_1 != 0) {
    FUN_004246f0(&local_a8,&local_7c);
    local_80 = 0xffffffff;
    if (local_7c == 1) {
      if ((&DAT_0087b6ca)[local_a8] == '\0') {
        local_80 = local_a8;
      }
      else {
        local_80 = (uint)(local_a8 == 0);
      }
    }
    puVar10 = &DAT_00802cd8;
    ppfVar13 = local_50;
    for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
      *ppfVar13 = (float *)*puVar10;
      puVar10 = puVar10 + 1;
      ppfVar13 = ppfVar13 + 1;
    }
    local_88 = (float)((-(uint)(DAT_009213e4 != 0) & 0xffffffc0) + 0xff);
    local_78 = (short *)(param_1 + 0x1b2);
    uVar9 = 0;
    local_90 = (float *)(param_1 + 0xa70);
    local_9c = (short *)(param_1 + 0x6c);
    local_a8 = 0;
    local_84 = 0;
    local_74 = (float *)&DAT_00856990;
    local_8c = &DAT_0086e4ec;
    local_a0 = 0;
    do {
      local_98 = uVar9;
      if (local_7c != 2) {
        if (DAT_0087b6c8 == '\0') {
          local_98 = (uint)(DAT_0087b6c9 != '\0') * 2 - 1;
        }
        else {
          local_98 = 0;
        }
      }
      psVar4 = (short *)((int)&DAT_00856970 + uVar9 * 2);
      *psVar4 = *psVar4 + (short)local_64;
      psVar4 = (short *)((int)&DAT_008568f8 + uVar9 * 2);
      *psVar4 = *psVar4 + (short)local_60;
      psVar4 = (short *)((int)&DAT_0085696c + uVar9 * 2);
      *psVar4 = *psVar4 + (short)local_58;
      psVar4 = (short *)((int)&DAT_008568fc + uVar9 * 2);
      *psVar4 = *psVar4 + (short)local_5c;
      FUN_004239e0(0x2aaa);
      FUN_004239e0(0x4000);
      FUN_004239e0(0x4000);
      pfVar14 = local_74;
      puVar12 = local_8c;
      uVar2 = *(ushort *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)local_8c[1] * 0x28);
      if ((uVar2 & 1) == 0) {
        fVar3 = 0.0;
      }
      else if ((uVar2 & 4) == 0) {
        if ((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*local_8c * 0x28) & 8) == 0) {
          fVar3 = _DAT_007f37d8 * 0.6;
        }
        else {
          fVar3 = _DAT_007f37d8 * 0.8;
        }
      }
      else {
        fVar3 = _DAT_007f37d8;
        if ((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*local_8c * 0x28) & 8) == 0) {
          fVar3 = _DAT_007f37d8 * 0.8;
        }
      }
      fVar15 = (float10)FUN_0054fb40(*local_74,fVar3,0x41200000);
      *pfVar14 = (float)fVar15;
      (&DAT_0085692c)[uVar9] = _DAT_00925018 + (float)(&DAT_0085692c)[uVar9];
      psVar4 = (short *)FUN_0062df80((int)*local_9c);
      if (psVar4 != (short *)0x0) {
        iVar6 = FUN_0049f800((int)*(short *)(*(int *)(param_1 + 0x2c) + 8 + (uint)puVar12[2] * 0x28)
                             ,0);
        pfVar14 = local_90;
        cVar1 = *(char *)(param_1 + 0xa6e + uVar9);
        if (cVar1 != '\0') {
          *(char *)(param_1 + 0xa6e + uVar9) = cVar1 + -1;
        }
        if ((*(char *)(param_1 + 0xa6c + uVar9) == '\0') &&
           (iVar7 = (iVar6 == -1) + 0x61, *(int *)(*(int *)(psVar4 + 6) + iVar7 * 4) != 0)) {
          if (*local_90 == 0.0) {
            fVar15 = (float10)FUN_0062e040((int)*psVar4,iVar7,0,0,1);
            *pfVar14 = (float)fVar15;
          }
          else {
            fVar3 = *local_90 - _DAT_00925018;
            *local_90 = fVar3;
            if (fVar3 < 0.0 != (fVar3 == 0.0)) {
              *(undefined1 *)(param_1 + 0xa6c + uVar9) = 1;
            }
          }
        }
        else {
          *(undefined1 *)(param_1 + 0xa6c + uVar9) = 1;
        }
        local_78[-1] = local_78[-2];
        if (iVar6 == -1) {
          *local_78 = (*(char *)(param_1 + 0xa6c + uVar9) != '\0') + 0x62;
        }
        else {
          *local_78 = (-(ushort)(*(char *)(param_1 + 0xa6c + uVar9) != '\0') & 0x5d) + 0x61;
        }
        local_a4 = (int *)(_DAT_00925018 * 30.0);
        FUN_0062e9b0(psVar4,local_78 + -0x1d,local_a4,0,_DAT_00925018,0);
        local_54 = (uint)(ushort)((&DAT_0085697c)[uVar9] + 0xc000);
        local_a4 = (int *)(param_2 + 0x5120);
        local_94 = 0;
        pfVar8 = (float *)(param_1 + 0xc50);
        do {
          iVar6 = local_94;
          if (((((local_94 == (&DAT_00856984)[uVar9]) && (iVar7 = FUN_00574e20(), iVar7 == 0xc)) &&
               (DAT_008569ac == 0)) && ((local_7c == 2 || (uVar9 == local_80)))) &&
             ((local_98 != 0xffffffff &&
              ((iVar7 = (int)*(char *)(iVar6 + 0x250 + param_1), iVar7 != -1 &&
               (*(int *)(psVar4 + iVar7 * 2 + 10) != 0)))))) {
            local_50[0] = (float *)PTR_DAT_007f3a20;
            pfVar14 = (float *)((local_84 + iVar7) * 0x40 + 0x298 + param_1);
            local_70 = *pfVar14;
            local_68 = pfVar14[2];
            local_1 = 2;
            if (*pfVar8 != 0.0) {
              local_70 = (float)(&DAT_029899a0)[local_54 >> 1 & 0x7fff] * *pfVar8 + local_70;
              local_68 = (float)(&DAT_029899a0)[(int)((local_54 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
                         *pfVar8 + local_68;
            }
            local_6c = pfVar8[9] + pfVar14[1];
            local_3c = local_88._0_1_;
            local_3b = local_88._0_1_;
            local_3a = local_88._0_1_;
            local_50[1] = &local_70;
            local_50[3] = (float *)0x3fa00000;
            local_39 = 0x60;
            local_38 = 0x87;
            FUN_00560b60(local_50);
          }
          if ((((*local_a4 != 0) && (0 < (int)pfVar8[-0x302])) &&
              (*(char *)((int)pfVar8[-0x314] + 4) == '\0')) &&
             ((*(char *)((int)pfVar8[-0x314] + 5) != -1 &&
              (iVar7 = (uint)(ushort)(&DAT_0086e4ec)[local_a8 + iVar6] * 0x20 + *local_a4,
              *(int *)(iVar7 + 0x14) != 0)))) {
            iVar5 = *(int *)(psVar4 + 2);
            iVar11 = 0;
            iVar6 = local_94;
            if (0 < *(int *)(iVar5 + 0x10)) {
              do {
                if ((uint)*(byte *)(*(int *)(*(int *)(iVar5 + 0xc) + iVar11 * 4) + 0x9a) ==
                    (int)*(char *)((int)pfVar8[-0x314] + 5)) {
                  *(undefined2 *)
                   (*(int *)(*(int *)(*(int *)(psVar4 + 2) + 0xc) + iVar11 * 4) + 0x74) =
                       *(undefined2 *)(iVar7 + 0x14);
                  FUN_005e4b00(*(undefined4 *)(*(int *)(*(int *)(psVar4 + 2) + 0xc) + iVar11 * 4));
                }
                iVar5 = *(int *)(psVar4 + 2);
                iVar11 = iVar11 + 1;
                iVar6 = local_94;
              } while (iVar11 < *(int *)(iVar5 + 0x10));
            }
          }
          local_a4 = local_a4 + 1;
          local_94 = iVar6 + 1;
          pfVar8 = pfVar8 + 1;
          puVar12 = local_8c;
          pfVar14 = local_74;
        } while (local_94 < 9);
      }
      local_a0 = local_a0 + 0x14;
      local_78 = local_78 + 0x24;
      local_9c = local_9c + 1;
      local_90 = local_90 + 1;
      local_84 = local_84 + 0x10;
      local_a8 = local_a8 + 0x1c;
      local_74 = pfVar14 + 3;
      local_8c = puVar12 + 0x1c;
      uVar9 = uVar9 + 1;
    } while ((int)local_74 < 0x8569a8);
    iVar6 = FUN_00574e20();
    if ((iVar6 == 0xc) && (DAT_008569ac == 0)) {
      local_a8 = 0x3f800000;
    }
    else {
      local_a8 = 0;
    }
    local_88 = _DAT_00925018 * 1.5;
    fVar15 = (float10)FUN_0054fad0(_DAT_008569a4,local_a8,local_88);
    _DAT_008569a4 = (float)fVar15;
  }
  return;
}

