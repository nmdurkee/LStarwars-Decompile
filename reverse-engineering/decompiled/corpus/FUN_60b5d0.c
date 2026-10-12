/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60b5d0; label: FUN_0060b5d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060b5d0(int param_1,int param_2,int param_3,float param_4,float *param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint *puVar9;
  undefined4 uVar10;
  undefined1 uVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  int iVar15;
  float in_stack_00000028;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  uint local_50;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar15 = 0;
  if (*(char *)(param_3 + 0x99) == -0x69) {
    local_68 = 0;
    local_60 = 0x3f800000;
    local_64 = 0x3f800000;
    local_5c = 0;
  }
  else {
    local_68 = *(undefined4 *)(param_1 + 0x28);
    local_60 = *(undefined4 *)(param_1 + 0x30);
    local_5c = *(undefined4 *)(param_1 + 0x2c);
    local_64 = *(undefined4 *)(param_1 + 0x34);
  }
  pfVar13 = (float *)(param_2 + 0x3c);
  local_58 = 0;
  do {
    fVar4 = param_4 - pfVar13[-4];
    local_50 = (uint)(longlong)ROUND(fVar4 * *pfVar13);
    if (local_50 < 0x3f) {
      fVar5 = (float)(int)local_50;
      if ((int)local_50 < 0) {
        fVar5 = fVar5 + 4.2949673e+09;
      }
      fVar5 = fVar4 * *pfVar13 - fVar5;
      pfVar3 = (float *)(param_1 + 0x4c + local_50 * 0x28);
      fVar7 = pfVar13[-3] * fVar4 + pfVar13[-7];
      fVar6 = *(float *)(param_1 + 0x10) * fVar4 * fVar4 * 0.945 + pfVar13[-2] * fVar4 + pfVar13[-6]
      ;
      fVar4 = fVar4 * pfVar13[-1] + pfVar13[-5];
      _DAT_0097f9a8 = param_5[0xc] + fVar6 * param_5[4] + fVar7 * *param_5 + fVar4 * param_5[8];
      _DAT_0097f9ac = param_5[0xd] + param_5[9] * fVar4 + param_5[1] * fVar7 + param_5[5] * fVar6;
      _DAT_0097f9b0 = param_5[0xe] + fVar4 * param_5[10] + param_5[6] * fVar6 + param_5[2] * fVar7;
      if ((param_6 == 6) || (param_6 == 7)) {
        FUN_005ffee0(&DAT_0097f9a8);
      }
      if (in_stack_00000028 <=
          _DAT_00987508 * _DAT_0097f9b0 +
          _DAT_00987500 * _DAT_0097f9a8 + _DAT_00987504 * _DAT_0097f9ac + _DAT_0098750c) {
        if (DAT_02854cfc < (uint)(DAT_02854cf4 + 6 + iVar15)) {
          *(int *)(DAT_02854d04 + 0xc) = *(int *)(DAT_02854d04 + 0xc) + iVar15;
          _DAT_02854d0c = _DAT_02854d0c + iVar15;
          iVar15 = 0;
          iVar12 = FUN_005ffc80();
          if (iVar12 == 0) {
            return;
          }
          *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
          uVar11 = (undefined1)DAT_02854cf0;
          puVar9 = DAT_009736e0;
          puVar1 = (undefined4 *)(DAT_02854d04 + 0x10);
          DAT_02854d04 = (undefined1 *)*DAT_009736e0;
          *(undefined4 *)(DAT_02854d04 + 0x10) = *puVar1;
          uVar10 = DAT_02854cec;
          *DAT_02854d04 = uVar11;
          iVar12 = DAT_02854cf4;
          *(undefined4 *)(DAT_02854d04 + 4) = uVar10;
          *(int *)(DAT_02854d04 + 8) = iVar12;
          *(undefined4 *)(DAT_02854d04 + 0xc) = 0;
          *puVar9 = *puVar9 + 0x14;
          FUN_00607cb0(DAT_02854d04);
        }
        pfVar14 = &local_30;
        param_3 = 4;
        fVar4 = 1.0 - fVar5;
        local_30 = *pfVar3 * fVar4 + pfVar3[10] * fVar5;
        local_2c = pfVar3[1] * fVar4 + pfVar3[0xb] * fVar5;
        local_28 = pfVar3[2] * fVar4 + pfVar3[0xc] * fVar5;
        local_24 = pfVar3[6] * fVar4 + pfVar3[0x10] * fVar5;
        local_20 = pfVar3[7] * fVar4 + pfVar3[0x11] * fVar5;
        local_1c = pfVar3[8] * fVar4 + pfVar3[0x12] * fVar5;
        local_18 = pfVar3[3] * fVar4 + pfVar3[0xd] * fVar5;
        local_14 = pfVar3[4] * fVar4 + pfVar3[0xe] * fVar5;
        local_10 = fVar4 * pfVar3[5] + pfVar3[0xf] * fVar5;
        local_c = (local_24 - local_18) + local_30;
        local_8 = (local_20 - local_14) + local_2c;
        local_4 = (local_1c - local_10) + local_28;
        do {
          FUN_005b30a0(pfVar14,pfVar14,&DAT_0097f978);
          iVar12 = DAT_02854d00;
          pfVar14 = pfVar14 + 3;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
        fVar4 = pfVar3[9];
        iVar2 = DAT_02854cf4 + iVar15;
        iVar8 = iVar2 * 0x18;
        *(float *)(DAT_02854d00 + iVar8) = local_30;
        *(float *)(iVar12 + 4 + iVar8) = local_2c;
        *(float *)(iVar12 + 8 + iVar8) = local_28;
        *(float *)(iVar8 + 0xc + DAT_02854d00) = fVar4;
        iVar12 = DAT_02854d00;
        *(undefined4 *)(DAT_02854d00 + 0x10 + iVar8) = local_68;
        iVar12 = iVar12 + iVar8;
        *(undefined4 *)(iVar12 + 0x14) = local_64;
        *(float *)(iVar12 + 0x18) = local_18;
        *(float *)(iVar12 + 0x1c) = local_14;
        *(float *)(iVar12 + 0x20) = local_10;
        *(float *)(iVar8 + 0x24 + DAT_02854d00) = fVar4;
        iVar12 = DAT_02854d00;
        *(undefined4 *)(DAT_02854d00 + 0x28 + iVar8) = local_60;
        *(undefined4 *)(iVar12 + iVar8 + 0x2c) = local_64;
        pfVar3 = (float *)(DAT_02854d00 + (iVar2 * 3 + 6) * 8);
        *pfVar3 = local_24;
        pfVar3[1] = local_20;
        pfVar3[2] = local_1c;
        *(float *)(iVar8 + 0x3c + DAT_02854d00) = fVar4;
        iVar12 = DAT_02854d00;
        *(undefined4 *)(DAT_02854d00 + 0x40 + iVar8) = local_60;
        *(undefined4 *)(iVar12 + iVar8 + 0x44) = local_5c;
        pfVar3 = (float *)(DAT_02854d00 + (iVar2 * 3 + 9) * 8);
        *pfVar3 = local_30;
        pfVar3[1] = local_2c;
        pfVar3[2] = local_28;
        *(float *)(iVar8 + 0x54 + DAT_02854d00) = fVar4;
        iVar12 = DAT_02854d00;
        *(undefined4 *)(DAT_02854d00 + 0x58 + iVar8) = local_68;
        *(undefined4 *)(iVar12 + iVar8 + 0x5c) = local_64;
        pfVar3 = (float *)(DAT_02854d00 + (iVar2 * 3 + 0xc) * 8);
        *pfVar3 = local_24;
        pfVar3[1] = local_20;
        pfVar3[2] = local_1c;
        *(float *)(iVar8 + 0x6c + DAT_02854d00) = fVar4;
        iVar12 = DAT_02854d00;
        *(undefined4 *)(DAT_02854d00 + 0x70 + iVar8) = local_60;
        *(undefined4 *)(iVar12 + iVar8 + 0x74) = local_5c;
        pfVar3 = (float *)(DAT_02854d00 + (iVar2 * 3 + 0xf) * 8);
        *pfVar3 = local_c;
        pfVar3[1] = local_8;
        pfVar3[2] = local_4;
        *(float *)(iVar8 + 0x84 + DAT_02854d00) = fVar4;
        iVar12 = DAT_02854d00;
        *(undefined4 *)(iVar8 + 0x88 + DAT_02854d00) = local_68;
        *(undefined4 *)(iVar8 + iVar12 + 0x8c) = local_5c;
        iVar15 = iVar15 + 6;
      }
    }
    local_58 = local_58 + 1;
    pfVar13 = pfVar13 + 8;
  } while (local_58 != 0x20);
  *(int *)(DAT_02854d04 + 0xc) = *(int *)(DAT_02854d04 + 0xc) + iVar15;
  DAT_02854cf4 = DAT_02854cf4 + iVar15;
  _DAT_02854d0c = _DAT_02854d0c + iVar15;
  return;
}

