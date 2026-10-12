/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x6786f0; label: FUN_006786f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006786f0(float *param_1,float *param_2,undefined1 *param_3)

{
  float *pfVar1;
  float fVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  float10 fVar11;
  float local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_20 = 0.0;
  fVar11 = (float10)FUN_006783a0();
  puVar6 = DAT_0292186c;
  bVar3 = (byte)DAT_0292186c[0x22];
  if (bVar3 != 0) {
    uVar5 = DAT_0292186c[0x24];
    if (uVar5 == 0) {
      local_20 = 0.707;
    }
    else {
      local_20 = (float)DAT_0292186c[0x2c] * *(float *)(uVar5 + 0x50) +
                 (float)DAT_0292186c[0x2a] * *(float *)(uVar5 + 0x48) +
                 (float)DAT_0292186c[0x2b] * *(float *)(uVar5 + 0x4c);
    }
    sVar4 = (short)DAT_0292186c[0x1b];
    if ((sVar4 == -1) || (*(int *)(*DAT_0292fc68 + 0x2c + sVar4 * 0x38) != 1)) {
      if (*(char *)((int)DAT_0292186c + 0x35) == '\0') {
        local_20 = -1.1;
      }
      else {
        local_20 = 1.1;
      }
    }
    else if (((bVar3 & 0xf) < 2) || (0.95 <= local_20)) {
      local_20 = 0.707;
    }
    else {
      local_20 = 0.98;
    }
    if ((-1 < sVar4) && ((*(byte *)(uVar5 + 99) & 0x7c) == 4)) {
      DAT_0292186c[7] = (uint)((float)DAT_0292186c[7] + (float)DAT_0292186c[0x2a] * 0.0015);
      puVar6[9] = (uint)((float)puVar6[0x2c] * 0.0015 + (float)puVar6[9]);
      local_20 = 1.1;
    }
    if ((float10)_DAT_02947c0c != fVar11) {
      local_20 = _DAT_02947c0c;
    }
  }
  switch(bVar3) {
  case 0:
    *param_3 = 0;
    *param_1 = (float)puVar6[10] + (float)puVar6[7];
    param_1[1] = ((float)puVar6[0xb] + (float)puVar6[8]) * (float)puVar6[0x17] -
                 (float)puVar6[0x14] * (float)puVar6[0x17];
    param_1[2] = (float)puVar6[0xc] + (float)puVar6[9];
    *puVar6 = *puVar6 & 0xfffffffe;
    goto LAB_00678d2a;
  case 1:
switchD_00678831_caseD_1:
    break;
  case 2:
  case 3:
  case 4:
    if ((-1 < (short)puVar6[0x1b]) && ((*(byte *)(puVar6[0x24] + 99) & 0x7c) == 4))
    goto switchD_00678831_caseD_1;
    local_20 = 0.707;
    break;
  default:
    goto LAB_00678d2a;
  case 0x11:
    goto LAB_00678aba;
  case 0x12:
  case 0x13:
  case 0x14:
    local_20 = 0.707;
LAB_00678aba:
    local_18 = (float)puVar6[0x2a];
    local_14 = (float)puVar6[0x2b];
    local_10 = (float)puVar6[0x2c];
    if (((*puVar6 & 1) != 0) &&
       (local_14 * (float)puVar6[0x37] + local_18 * (float)puVar6[0x36] +
        local_10 * (float)puVar6[0x38] < 0.0)) {
      FUN_00677fb0(&local_18,puVar6 + 0x36,&local_c);
      fVar2 = local_14 * local_8 + local_18 * local_c + local_10 * local_4;
      if (0.25 < fVar2) {
        local_18 = local_c / fVar2;
        local_14 = local_8 / fVar2;
        local_10 = local_4 / fVar2;
      }
    }
    pfVar1 = (float *)(puVar6 + 10);
    if (local_20 <= (float)puVar6[0x2e]) {
      fVar2 = 0.0035 - (float)puVar6[0x27] * 1.05;
      puVar6[7] = (uint)((float)puVar6[7] + local_18 * fVar2);
      puVar6[9] = (uint)(local_10 * fVar2 + (float)puVar6[9]);
      puVar6[8] = (uint)((float)puVar6[8] + local_14 * fVar2 + local_14 * 0.01);
      puVar6[0xb] = (uint)(local_14 * 0.01 + (float)puVar6[0xb]);
      FUN_00677fb0(&local_18,pfVar1,pfVar1);
      FUN_00677fb0(puVar6 + 0x2d,param_2,param_2);
    }
    else {
      fVar2 = 0.0035 - (float)puVar6[0x27] * 1.05;
      puVar6[7] = (uint)(local_18 * fVar2 + (float)puVar6[7]);
      puVar6[8] = (uint)(local_14 * fVar2 + (float)puVar6[8]);
      puVar6[9] = (uint)((float)puVar6[9] + local_10 * fVar2);
      fVar2 = 0.0035 - (float)puVar6[0x27] * 0.35;
      *pfVar1 = *pfVar1 + local_18 * fVar2;
      puVar6[0xb] = (uint)(local_14 * fVar2 + (float)puVar6[0xb]);
      puVar6[0xc] = (uint)(local_10 * fVar2 + (float)puVar6[0xc]);
      *param_3 = 1;
      FUN_00677fb0(&local_18,pfVar1,pfVar1);
      FUN_00678010(puVar6 + 0x2d,param_2,param_2);
      puVar10 = DAT_02947c74;
      if (DAT_02947c74 == (uint *)0x0) {
        puVar10 = (uint *)FUN_006705a0();
        DAT_02947c74 = puVar10;
        *puVar10 = puVar6[0x10];
        *(undefined2 *)((int)puVar10 + 6) = 0;
        *(undefined2 *)(puVar10 + 1) = 0;
        *(undefined2 *)(puVar10 + 2) = 0;
      }
      *(undefined2 *)((int)puVar10 + 10) = 4;
      puVar10[3] = puVar6[0x2d];
      puVar10[4] = puVar6[0x2e];
      puVar10[5] = puVar6[0x2f];
    }
    *puVar6 = *puVar6 | 1;
    puVar6[0x36] = puVar6[0x2a];
    puVar6[0x37] = puVar6[0x2b];
    puVar6[0x38] = puVar6[0x2c];
    goto LAB_00678d2a;
  }
  fVar2 = (float)puVar6[0x26];
  puVar6[0x26] = (uint)(fVar2 - (float)puVar6[0x28]);
  if ((float10)(fVar2 - (float)puVar6[0x28]) < fVar11) {
    puVar6[0x26] = (uint)(float)fVar11;
  }
  pfVar1 = (float *)(puVar6 + 10);
  puVar6[7] = (uint)((float)puVar6[7] + (float)puVar6[10] * (float)puVar6[0x26]);
  puVar6[8] = (uint)((float)puVar6[8] + (float)puVar6[0x26] * (float)puVar6[0xb]);
  puVar6[9] = (uint)((float)puVar6[9] + (float)puVar6[0x26] * (float)puVar6[0xc]);
  *pfVar1 = *pfVar1 - (float)puVar6[10] * (float)puVar6[0x26];
  puVar6[0xb] = (uint)((float)puVar6[0xb] - (float)puVar6[0x26] * (float)puVar6[0xb]);
  puVar6[0xc] = (uint)((float)puVar6[0xc] - (float)puVar6[0x26] * (float)puVar6[0xc]);
  if (local_20 <= (float)puVar6[0x2e]) {
    FUN_00677fb0(puVar6 + 0x2a,pfVar1,pfVar1);
    FUN_00677fb0(puVar6 + 0x2d,param_2,param_2);
    _DAT_02921258 = _DAT_02921258 | 2;
    *param_3 = 1;
    param_3[1] = 1;
    sVar4 = (short)puVar6[0x1b];
    puVar6[8] = (uint)((float)puVar6[0x2b] * 0.0003 + (float)puVar6[8]);
    if ((sVar4 != -1) && (*(int *)(*DAT_0292fc68 + 0x2c + sVar4 * 0x38) == 1)) {
      puVar10 = (uint *)(*(short *)(*DAT_0292fc68 + sVar4 * 0x38 + 0x30) * 0x6c + 0x4c +
                        DAT_0292fc68[0x1a]);
      *puVar10 = *puVar10 | 2;
    }
    *puVar6 = *puVar6 & 0xfffffffe;
  }
  else {
    *param_3 = 0;
    uVar5 = _DAT_02921258;
    _DAT_02921258 = _DAT_02921258 | 1;
    if (((short)puVar6[0x1b] == -1) ||
       (*(int *)(*DAT_0292fc68 + 0x2c + (short)puVar6[0x1b] * 0x38) != 1)) {
      _DAT_02921258 = uVar5 | 0x11;
    }
    puVar6[7] = (uint)((float)puVar6[7] + (float)puVar6[0x2a] * 0.0006);
    puVar6[9] = (uint)((float)puVar6[9] + (float)puVar6[0x2c] * 0.0006);
    *pfVar1 = *pfVar1 + (float)puVar6[0x2a] * 0.0006;
    puVar6[0xc] = (uint)((float)puVar6[0x2c] * 0.0006 + (float)puVar6[0xc]);
    *param_2 = *param_2 + (float)puVar6[0x2a] * 0.0009;
    param_2[2] = (float)puVar6[0x2c] * 0.0009 + param_2[2];
    FUN_00677fb0(puVar6 + 0x2a,pfVar1,pfVar1);
    puVar10 = puVar6 + 0x2d;
    FUN_00678010(puVar10,param_2,param_2);
    puVar9 = DAT_02947c74;
    if (DAT_02947c74 == (uint *)0x0) {
      puVar9 = (uint *)FUN_006705a0();
      DAT_02947c74 = puVar9;
      *puVar9 = puVar6[0x10];
      *(undefined2 *)((int)puVar9 + 6) = 0;
      *(undefined2 *)(puVar9 + 1) = 0;
      *(undefined2 *)(puVar9 + 2) = 0;
    }
    *(undefined2 *)((int)puVar9 + 10) = 4;
    puVar9[3] = *puVar10;
    puVar9[4] = puVar6[0x2e];
    puVar9[5] = puVar6[0x2f];
    _DAT_029231ac = *puVar10;
    _DAT_029231b0 = puVar6[0x2e];
    _DAT_029231b4 = puVar6[0x2f];
    *puVar6 = *puVar6 & 0xfffffffe;
  }
LAB_00678d2a:
  if (((((byte)puVar6[0x22] != 0) && ((byte)puVar6[0x22] < 0x10)) &&
      (sVar4 = (short)puVar6[0x1b], sVar4 != -1)) &&
     ((*(int *)(*DAT_0292fc68 + 0x2c + sVar4 * 0x38) == 1 &&
      (local_20 < (float)puVar6[0x2e] != (local_20 == (float)puVar6[0x2e]))))) {
    FUN_00678640(puVar6[0x10],puVar6 + 10,param_2,
                 (int)*(short *)(*DAT_0292fc68 + sVar4 * 0x38 + 0x30));
  }
  iVar8 = DAT_02962b38;
  piVar7 = DAT_02948ed4;
  if (((DAT_02962b38 != 0) && (*DAT_02948ed4 < DAT_02948ed0)) && ((char)puVar6[0x22] != '\0')) {
    *(float *)(DAT_02962b38 + *DAT_02948ed4 * 0x1c) =
         (float)puVar6[7] - (float)puVar6[0x2a] * (float)puVar6[0x14];
    *(float *)(iVar8 + 4 + *piVar7 * 0x1c) =
         ((float)puVar6[8] - (float)puVar6[0x2b] * (float)puVar6[0x14]) * (float)puVar6[0x17];
    *(float *)(iVar8 + 8 + *piVar7 * 0x1c) =
         (float)puVar6[9] - (float)puVar6[0x2c] * (float)puVar6[0x14];
    puVar10 = (uint *)(iVar8 + 0xc + *piVar7 * 0x1c);
    *puVar10 = puVar6[0x2a];
    puVar10[1] = puVar6[0x2b];
    puVar10[2] = puVar6[0x2c];
    if (puVar6[0x24] != 0) {
      *(undefined1 *)(iVar8 + 0x18 + *piVar7 * 0x1c) = *(undefined1 *)(puVar6[0x24] + 0x60);
      *(undefined1 *)(iVar8 + 0x19 + *piVar7 * 0x1c) = *(undefined1 *)(puVar6[0x24] + 0x61);
      *(undefined1 *)(iVar8 + 0x1a + *piVar7 * 0x1c) = *(undefined1 *)(puVar6[0x24] + 0x62);
      *(undefined1 *)(iVar8 + 0x1b + *piVar7 * 0x1c) = *(undefined1 *)(puVar6[0x24] + 99);
      *piVar7 = *piVar7 + 1;
      return;
    }
    if (DAT_0292125e != '\0') {
      *(undefined1 *)(iVar8 + 0x18 + *piVar7 * 0x1c) = DAT_02924b40;
      *(undefined1 *)(iVar8 + 0x19 + *piVar7 * 0x1c) = DAT_02924b41;
      *(undefined1 *)(iVar8 + 0x1a + *piVar7 * 0x1c) = 0;
      *(undefined1 *)(iVar8 + 0x1b + *piVar7 * 0x1c) = 0;
    }
    *piVar7 = *piVar7 + 1;
  }
  return;
}

