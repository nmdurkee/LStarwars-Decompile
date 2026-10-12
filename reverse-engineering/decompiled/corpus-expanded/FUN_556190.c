/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x556190; label: FUN_00556190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00556190(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  char cVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  char cVar14;
  short sVar15;
  undefined2 uVar16;
  int iVar17;
  uint uVar18;
  undefined *puVar19;
  ushort uVar20;
  uint *puVar21;
  bool bVar22;
  float10 fVar23;
  undefined4 uVar24;
  float local_7c;
  float local_78;
  short local_6c;
  undefined1 local_40 [64];
  
  uVar10 = *(uint *)(param_1 + 0x84);
  bVar22 = (uVar10 & 0x20) != 0;
  *(uint *)(param_1 + 0x84) = uVar10 & 0xfffffcef;
  if (bVar22) {
    FUN_005a1170(*(undefined4 *)(param_1 + 0x68));
  }
  fVar1 = *(float *)(param_1 + 0x5c);
  fVar2 = *(float *)(param_1 + 0x9c);
  fVar3 = *(float *)(param_1 + 0x9c);
  fVar4 = *(float *)(param_1 + 0x5c);
  fVar5 = *(float *)(param_1 + 100);
  fVar6 = *(float *)(param_1 + 0x9c);
  fVar7 = *(float *)(param_1 + 0x9c);
  fVar8 = *(float *)(param_1 + 100);
  if (((*(byte *)(param_1 + 0x84) & 0xc) == 0) && (local_78 = 0.0, 0 < DAT_0093d500)) {
    puVar21 = (uint *)(DAT_0093d504 + 0x1fc);
    puVar19 = PTR_PTR_007fb0e4;
    do {
      if (((((((*puVar21 & 1) != 0) && ((*puVar21 & 0x1000) != 0)) &&
            (*(char *)((int)puVar21 + 0x8f) == '\0')) &&
           ((((puVar21[0x309] & 0x20) == 0 &&
             ((*(uint *)(puVar19 + *(char *)((int)puVar21 + 0x5b9) * 0x10 + 8) & 0x40000000) == 0))
            && (((*(uint *)(puVar19 + *(char *)((int)puVar21 + 0x5b9) * 0x10 + 8) & 0x40008000) == 0
                && ((fVar1 - fVar2 <= (float)puVar21[-0x1e] &&
                    ((float)puVar21[-0x21] <= fVar3 + fVar4)))))))) &&
          (fVar5 - fVar6 <= (float)puVar21[-0x1c])) && ((float)puVar21[-0x1f] <= fVar7 + fVar8)) {
        fVar11 = *(float *)(param_1 + 0x9c) + 0.5 + (float)puVar21[-8];
        fVar12 = (float)puVar21[-0x68] - *(float *)(param_1 + 0x5c);
        fVar13 = (float)puVar21[-0x66] - *(float *)(param_1 + 100);
        if (fVar12 * fVar12 + fVar13 * fVar13 < fVar11 * fVar11) {
          if ((fVar12 == 0.0) && (fVar13 == 0.0)) {
            sVar15 = FUN_0054fa60();
          }
          else {
            sVar15 = FUN_005be2d0(fVar12,fVar13);
          }
          if (((float)puVar21[-0x65] == 0.0) && ((float)puVar21[-99] == 0.0)) {
            uVar16 = (undefined2)puVar21[-0x69];
            local_7c = *(float *)(*(int *)(puVar21[-0x6a] + 0x24) + 0x14);
          }
          else {
            uVar16 = FUN_005be2d0(puVar21[-0x65],puVar21[-99]);
            fVar23 = (float10)FUN_005c0240((float)puVar21[-0x65] * (float)puVar21[-0x65] +
                                           (float)puVar21[-99] * (float)puVar21[-99]);
            local_7c = (float)fVar23;
            iVar17 = *(int *)(puVar21[-0x6a] + 0x24);
            if (local_7c < *(float *)(iVar17 + 0x14)) {
              local_7c = *(float *)(iVar17 + 0x14);
            }
            else if (local_7c < *(float *)(iVar17 + 0x1c)) {
              local_7c = *(float *)(iVar17 + 0x1c);
            }
          }
          iVar17 = FUN_00550040(sVar15,uVar16);
          if (iVar17 < 0) {
            uVar20 = sVar15 + 0xcaab;
          }
          else {
            uVar20 = sVar15 + 0x3555;
          }
          puVar21[-0x65] = (uint)(local_7c * (float)(&DAT_029899a0)[uVar20 >> 1]);
          puVar21[-99] = (uint)(local_7c *
                               (float)(&DAT_029899a0)[(int)(uVar20 + 0x4000) >> 1 & 0x7fff]);
          puVar19 = PTR_PTR_007fb0e4;
        }
      }
      local_78 = (float)((int)local_78 + 1);
      puVar21 = puVar21 + 0x436;
    } while ((int)local_78 < DAT_0093d500);
  }
  if (bVar22) {
    uVar24 = *(undefined4 *)(param_1 + 0x68);
    goto LAB_005568bf;
  }
  cVar9 = *(char *)(param_1 + 0x8a);
  if (*(float *)(param_1 + 0x90) <= 0.0) {
    if (*(char *)(param_1 + 0x89) == -1) {
      if (((*(byte *)(param_1 + 0xac) & 0x10) == 0) ||
         ((((*(uint *)(param_1 + 0x84) & 0x400) != 0 &&
           (*(int *)(*(int *)(param_1 + 0x68) + 0xc) == 2)) || (0.0 < *(float *)(param_1 + 0x90)))))
      {
        FUN_005a1170(*(undefined4 *)(param_1 + 0x68));
        *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xffffffbf;
      }
      else if (*(float *)(param_1 + 0x90) <= -0.0) {
        iVar17 = FUN_005a0f10(*(undefined4 *)(param_1 + 0x68));
        if (iVar17 == 0) {
          uVar18 = *(uint *)(param_1 + 0x84) & 6;
          if ((uVar18 == 0) || (uVar18 == 6)) {
            local_6c = (short)(int)ROUND(_DAT_00925018 * 5461.0 *
                                         (*(float *)(param_1 + 0x2dc) / *(float *)(param_1 + 0x78)))
            ;
            *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + local_6c;
          }
          else {
            local_6c = (short)(int)ROUND(_DAT_00925018 * -5461.0 *
                                         (*(float *)(param_1 + 0x2dc) / *(float *)(param_1 + 0x78)))
            ;
            *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + local_6c;
          }
          if (-*(float *)(param_1 + 0x2dc) != 0.0) {
            FUN_005a1030(*(undefined4 *)(param_1 + 0x68),-*(float *)(param_1 + 0x2dc),1);
            goto LAB_005567f5;
          }
        }
        FUN_005a1170(*(undefined4 *)(param_1 + 0x68));
      }
      else {
        *(float *)(param_1 + 0x90) = *(float *)(param_1 + 0x90) - _DAT_00925018;
        FUN_005a1170(*(undefined4 *)(param_1 + 0x68));
      }
    }
    else {
      if (*(char *)(param_1 + 0x89) == '\x1e') {
        if ((*(byte *)(param_1 + 0x84) & 4) != 0) goto LAB_0055663b;
LAB_0055662a:
        if (*(int *)(*(int *)(param_1 + 0x68) + 0xc) != 2) {
          local_78 = *(float *)(param_1 + 0x78);
          goto LAB_00556658;
        }
      }
      else {
        if ((*(byte *)(param_1 + 0x84) & 4) != 0) goto LAB_0055662a;
LAB_0055663b:
        iVar17 = FUN_005a0f10(*(undefined4 *)(param_1 + 0x68));
        if (iVar17 == 0) {
          local_78 = -*(float *)(param_1 + 0x78);
LAB_00556658:
          if (local_78 != 0.0) {
            FUN_005a1030(*(undefined4 *)(param_1 + 0x68),local_78,1);
            goto LAB_005567f5;
          }
        }
      }
      FUN_005a1170(*(undefined4 *)(param_1 + 0x68));
    }
  }
  else {
    fVar1 = *(float *)(param_1 + 0x90) - _DAT_00925018;
    *(float *)(param_1 + 0x90) = fVar1;
    if (fVar1 < 0.0 == (fVar1 == 0.0)) {
      iVar17 = FUN_006e6b90();
      fVar1 = (float)(&DAT_029899a0)[iVar17 >> 1 & 0x7fff];
      local_78 = (float)FUN_00550040(*(undefined2 *)(param_1 + 0x80),*(undefined2 *)(param_1 + 0x7e)
                                    );
      uVar18 = *(uint *)(param_1 + 0x84) & 1;
      if ((uVar18 == 0) || (-1 < (int)local_78)) {
        if ((uVar18 == 0) && (0 < (int)local_78)) {
          local_78 = (float)((int)local_78 + -0x10000);
        }
      }
      else {
        local_78 = (float)((int)local_78 + 0x10000);
      }
      local_6c = (short)(int)ROUND((float)*(ushort *)(param_1 + 0x80) + (float)(int)local_78 * fVar1
                                  );
      *(short *)(param_1 + 0x7c) = local_6c;
    }
    else {
      *(undefined2 *)(param_1 + 0x7c) = *(undefined2 *)(param_1 + 0x7e);
      FUN_005a1170(*(undefined4 *)(param_1 + 0x68));
      *(undefined4 *)(param_1 + 0x90) = 0;
    }
  }
LAB_005567f5:
  FUN_00553780();
  if (((uVar10 & 0x100) != 0) || ((uVar10 & 0x200) != 0)) {
    FUN_00553830();
  }
  FUN_005b4900(local_40,param_1 + 0x5c);
  iVar17 = FUN_005a0f10(*(undefined4 *)(param_1 + 0x68));
  if (iVar17 == 0) {
    cVar14 = (*(int *)(*(int *)(param_1 + 0x68) + 0xc) == 2) + '\x01';
  }
  else {
    cVar14 = '\0';
  }
  *(char *)(param_1 + 0x8a) = cVar14;
  if ((((uVar10 & 0x10) == 0) && (cVar9 == '\x01')) && (cVar14 != '\x01')) {
    FUN_0054a910(0,0x3dcccccd,0,0);
    FUN_00549de0(PTR_DAT_008021b4,0xbe4ccccd,0,0);
    FUN_00547930(0x39,param_1 + 0x5c,0,0);
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 0x2000;
  }
  uVar24 = *(undefined4 *)(param_1 + 0x68);
LAB_005568bf:
  *(undefined1 *)(param_1 + 0x89) = 0xff;
  fVar23 = (float10)FUN_005a1500(uVar24);
  *(float *)(param_1 + 0x70) = (float)fVar23;
  return;
}

