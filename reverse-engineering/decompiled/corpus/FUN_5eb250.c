/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5eb250; label: FUN_005eb250
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005eb250(int param_1,ushort *param_2,uint param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  ushort uVar10;
  int *piVar11;
  float fVar12;
  float fVar13;
  short sVar14;
  uint uVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 extraout_ST0;
  float10 fVar20;
  float10 fVar21;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  local_38 = *(float *)(*(int *)(param_1 + 0x48) + 4);
  fVar3 = *(float *)(*(int *)(param_1 + 0x48) + 8);
  if (param_2 != (ushort *)0x0) {
    if (*(short *)(*(int *)(param_1 + 0x40) + 0x74) < 1) {
      fVar12 = 1.0;
      local_44 = 1.0;
    }
    else {
      piVar11 = *(int **)(DAT_0097157c + -4 + *(short *)(*(int *)(param_1 + 0x40) + 0x74) * 4);
      local_44 = 1.0 / (float)*piVar11;
      fVar12 = 1.0 / (float)piVar11[1];
    }
    fVar4 = **(float **)(param_1 + 0x30);
    fVar5 = *(float *)(param_1 + 0x14);
    if (_DAT_009738b4 == 0.0) {
      fVar13 = *(float *)(param_1 + 0x1c) * **(float **)(param_1 + 0x2c);
    }
    else {
      fVar13 = _DAT_009738b4 * **(float **)(param_1 + 0x2c);
    }
    DAT_02854d1c = DAT_02854d1c + 1;
    FUN_00600b20(0);
    uVar15 = param_3 & 4;
    if (uVar15 == 0) {
      FUN_00607d70(0x10,7,*(undefined4 *)(param_1 + 0x40));
    }
    else {
      FUN_00607ec0(0xc,7,*(undefined4 *)(param_1 + 0x40),*(int *)(param_1 + 0x48) + 0x10);
    }
    uVar10 = *param_2;
    if (uVar10 != 0) {
      fVar16 = (float10)fVar3;
      fVar17 = (float10)local_44;
      fVar18 = (float10)fVar12;
      do {
        fVar19 = (float10)(fVar4 * fVar5);
        param_2 = param_2 + 1;
        pfVar1 = (float *)(*(int *)(param_1 + 0x34) + (uint)uVar10 * 0xc);
        local_2c = fVar13;
        if (uVar10 != 0x20) {
          local_2c = pfVar1[2] * **(float **)(param_1 + 0x2c);
        }
        if (uVar15 == 0) {
          fVar20 = fVar16 + fVar19;
          fVar19 = fVar16;
        }
        else {
          fVar20 = fVar16;
          fVar19 = fVar16 - fVar19;
        }
        local_34 = (float)fVar19;
        local_3c = (float)fVar20;
        if (((param_3 & 1) == 0) || (9 < (ushort)(uVar10 - 0x30))) {
          local_30 = local_38;
          local_40 = local_2c;
        }
        else {
          sVar14 = FUN_005d0b40(param_1,0x30);
          local_40 = *(float *)(*(int *)(param_1 + 0x34) + 8 + sVar14 * 0xc) *
                     **(float **)(param_1 + 0x2c);
          local_30 = (local_40 - local_2c) + local_38;
          fVar16 = extraout_ST0;
          fVar17 = extraout_ST1;
        }
        local_2c = local_30 + local_2c;
        if (uVar10 != 0x20) {
          if (uVar15 == 0) {
            fVar16 = (float10)FUN_005c1f70();
            fVar6 = pfVar1[1];
            iVar2 = *DAT_02854d10;
            *(float *)(iVar2 + 0x10) = (float)(fVar16 * (float10)*pfVar1);
            *(float *)(iVar2 + 0x14) = (float)((float10)fVar6 * extraout_ST1_02);
            FUN_006009e0(local_30,local_34,0);
            FUN_005c1f70();
            fVar6 = pfVar1[1];
            fVar7 = *(float *)(param_1 + 0x14);
            iVar2 = *DAT_02854d10;
            *(float *)(iVar2 + 0x10) = (pfVar1[2] + *pfVar1) * local_44;
            *(float *)(iVar2 + 0x14) = (fVar6 + fVar7) * fVar12;
            FUN_006009e0(local_2c,local_3c,0);
            fVar18 = (float10)fVar12;
            fVar17 = (float10)local_44;
            fVar16 = (float10)fVar3;
          }
          else {
            fVar6 = *pfVar1;
            fVar7 = (float)((float10)pfVar1[1] * fVar18);
            fVar8 = (float)(((float10)pfVar1[2] + (float10)*pfVar1) * fVar17);
            fVar9 = (float)(((float10)pfVar1[1] + (float10)*(float *)(param_1 + 0x14)) * fVar18);
            fVar16 = (float10)FUN_005c1f70();
            fVar18 = (float10)(float)((float10)fVar6 * fVar17);
            pfVar1 = (float *)*DAT_02854d10;
            pfVar1[4] = (float)((float10)fVar6 * fVar17);
            fVar17 = (float10)fVar9;
            pfVar1[5] = fVar9;
            *pfVar1 = local_30;
            fVar19 = (float10)local_34;
            pfVar1[1] = local_34;
            *(float *)(*DAT_02854d10 + 8) = (float)fVar16;
            *DAT_02854d10 = *DAT_02854d10 + 0x18;
            DAT_02854d14 = DAT_02854d14 + 1;
            fVar16 = (float10)FUN_005c1f70();
            fVar20 = (float10)fVar8;
            pfVar1 = (float *)*DAT_02854d10;
            pfVar1[4] = fVar8;
            pfVar1[5] = (float)fVar17;
            fVar17 = (float10)local_2c;
            *pfVar1 = local_2c;
            pfVar1[1] = (float)fVar19;
            *(float *)(*DAT_02854d10 + 8) = (float)fVar16;
            *DAT_02854d10 = *DAT_02854d10 + 0x18;
            DAT_02854d14 = DAT_02854d14 + 1;
            fVar16 = extraout_ST1_00;
            fVar21 = (float10)FUN_005c1f70();
            pfVar1 = (float *)*DAT_02854d10;
            pfVar1[4] = (float)fVar20;
            pfVar1[5] = fVar7;
            *pfVar1 = (float)fVar17;
            pfVar1[1] = local_3c;
            *(float *)(*DAT_02854d10 + 8) = (float)fVar21;
            *DAT_02854d10 = *DAT_02854d10 + 0x18;
            DAT_02854d14 = DAT_02854d14 + 1;
            fVar21 = (float10)FUN_005c1f70();
            pfVar1 = (float *)*DAT_02854d10;
            pfVar1[4] = (float)fVar20;
            fVar20 = (float10)fVar7;
            pfVar1[5] = fVar7;
            *pfVar1 = (float)fVar17;
            fVar17 = (float10)local_3c;
            pfVar1[1] = local_3c;
            *(float *)(*DAT_02854d10 + 8) = (float)fVar21;
            *DAT_02854d10 = *DAT_02854d10 + 0x18;
            DAT_02854d14 = DAT_02854d14 + 1;
            fVar21 = (float10)FUN_005c1f70();
            pfVar1 = (float *)*DAT_02854d10;
            pfVar1[4] = (float)fVar18;
            pfVar1[5] = (float)fVar20;
            *pfVar1 = (float)fVar16;
            pfVar1[1] = (float)fVar17;
            *(float *)(*DAT_02854d10 + 8) = (float)fVar21;
            *DAT_02854d10 = *DAT_02854d10 + 0x18;
            DAT_02854d14 = DAT_02854d14 + 1;
            fVar17 = (float10)FUN_005c1f70();
            pfVar1 = (float *)*DAT_02854d10;
            pfVar1[4] = (float)fVar18;
            pfVar1[5] = (float)extraout_ST1_01;
            *pfVar1 = (float)fVar16;
            pfVar1[1] = (float)fVar19;
            *(float *)(*DAT_02854d10 + 8) = (float)fVar17;
            fVar16 = (float10)fVar3;
            *DAT_02854d10 = *DAT_02854d10 + 0x18;
            fVar17 = (float10)local_44;
            DAT_02854d14 = DAT_02854d14 + 1;
            fVar18 = (float10)fVar12;
          }
        }
        uVar10 = *param_2;
        local_38 = **(float **)(param_1 + 0x2c) * *(float *)(param_1 + 0x24) + local_40 + local_38;
      } while (uVar10 != 0);
    }
    if (uVar15 == 0) {
      FUN_006009a0();
    }
    else {
      FUN_006009c0();
    }
    iVar2 = DAT_02854d1c * 4;
    DAT_02854d1c = DAT_02854d1c + -1;
    FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar2));
  }
  return;
}

