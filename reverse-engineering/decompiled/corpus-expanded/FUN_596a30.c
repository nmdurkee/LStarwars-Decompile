/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x596a30; label: FUN_00596a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00596a30(void)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_8c;
  float local_88;
  float local_84;
  double local_80;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c [4];
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (DAT_00951be8 == 0) {
    iVar6 = FUN_0055e340(&local_5c,0);
    if (iVar6 == 0) {
      return;
    }
    _DAT_00805124 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5110) + 0x30);
  }
  else {
    iVar6 = FUN_005d6160();
    local_5c = *(float *)(iVar6 + 0x30) + *(float *)(iVar6 + 0x20) * 2.0;
    local_58 = *(float *)(iVar6 + 0x24) * 2.0 + *(float *)(iVar6 + 0x34);
    local_54 = *(float *)(iVar6 + 0x28) * 2.0 + *(float *)(iVar6 + 0x38);
    _DAT_00805124 = -2.0;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x5110) == 0) {
    return;
  }
  local_2c = local_5c;
  local_28 = _DAT_00805124 + local_58;
  local_24 = local_54;
  if (((*(int *)(PTR_DAT_00802c54 + 300) == 0) ||
      ((*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x100) == 0)) ||
     ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x400) != 0)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (DAT_00951be8 == 0) {
    iVar6 = FUN_005967b0(&local_8c);
    if ((iVar6 == 0) || (NAN(local_8c) || 0.0 < local_8c == (local_8c == 0.0))) {
      local_74 = *(float *)(PTR_DAT_008021b4 + 0x11c) - 1.2;
      local_70 = _DAT_0080511c;
      local_6c = *(float *)(PTR_DAT_008021b4 + 0x124) - 1.5;
      local_64 = _DAT_0080511c;
      local_68 = local_74;
      local_60 = local_6c;
      goto LAB_00596ce7;
    }
    FUN_005b37d0(&local_50,&local_50,*(undefined4 *)(PTR_DAT_00802c54 + 0x5110));
    FUN_005b3b30(&local_50,&local_50);
    local_74 = local_5c - _DAT_00805120 * local_50;
    local_70 = local_58 - _DAT_00805120 * local_4c;
    local_6c = local_54 - _DAT_00805120 * local_48;
    local_60 = _DAT_00805120 + _DAT_00805120;
    local_68 = local_5c + local_60;
  }
  else {
    pfVar1 = *(float **)(PTR_DAT_00802c54 + 0x5110);
    local_50 = *pfVar1;
    local_4c = pfVar1[1];
    local_48 = pfVar1[2];
    local_8c = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5110) + 0xc);
    local_74 = local_5c - _DAT_00805120 * local_50;
    local_70 = local_58 - _DAT_00805120 * local_4c;
    local_6c = local_54 - _DAT_00805120 * local_48;
    local_60 = _DAT_00805120 * 2.0;
    local_68 = local_5c + local_60;
  }
  local_64 = _DAT_00805120 * 10.0 + local_58;
  local_60 = local_60 + local_54;
LAB_00596ce7:
  if (bVar4) {
    local_8c = 0.5;
  }
  if (DAT_00951be8 == 0) {
    if (DAT_0087b4d8 == 0) {
      FUN_005b3800(&local_20,PTR_DAT_008021b4 + 0x128,PTR_DAT_008021b4 + 0x11c);
      local_44 = *(undefined4 *)(PTR_DAT_008021b4 + 0x11c);
      local_40 = *(undefined4 *)(PTR_DAT_008021b4 + 0x120);
      local_3c[0] = *(float *)(PTR_DAT_008021b4 + 0x124);
      iVar6 = DAT_00925164;
    }
    else {
      iVar6 = FUN_005d6160();
      local_1c = *(float *)(iVar6 + 0x24);
      local_80 = (double)CONCAT44(local_80._4_4_,local_1c);
      local_84 = *(float *)(iVar6 + 0x28);
      local_20 = *(undefined4 *)(iVar6 + 0x20);
      local_14 = 0x3f800000;
      local_18 = local_84;
      iVar6 = FUN_005d6160();
      local_44 = *(undefined4 *)(iVar6 + 0x30);
      local_40 = *(undefined4 *)(iVar6 + 0x34);
      local_3c[0] = *(float *)(iVar6 + 0x38);
      iVar6 = FUN_00617e20();
    }
  }
  else {
    local_1c = *(float *)(PTR_DAT_008021b4 + 0xdc);
    local_80 = (double)CONCAT44(local_80._4_4_,local_1c);
    local_84 = *(float *)(PTR_DAT_008021b4 + 0xe0);
    local_20 = *(undefined4 *)(PTR_DAT_008021b4 + 0xd8);
    local_14 = 0x3f800000;
    local_44 = *(undefined4 *)(PTR_DAT_008021b4 + 0xe8);
    local_40 = *(undefined4 *)(PTR_DAT_008021b4 + 0xec);
    local_3c[0] = *(float *)(PTR_DAT_008021b4 + 0xf0);
    iVar6 = DAT_00925164;
    local_18 = local_84;
  }
  FUN_005b3b30(&local_20,&local_20);
  local_14 = 0x3f800000;
  fVar3 = local_1c + 1.0;
  if (1.0 < fVar3) {
    fVar3 = 1.0;
  }
  local_80 = (double)fVar3;
  fVar8 = (float10)FUN_005becc0(&local_44,&local_2c,0);
  local_84 = (float)fVar8;
  local_88 = *(float *)(*(int *)(PTR_DAT_00802c54 + 0x5110) + 0x20);
  fVar3 = (float)local_80;
  local_80._0_4_ = fVar3;
  fVar8 = (float10)FUN_005be630(fVar3,_DAT_00805118);
  if (bVar4) {
    local_88 = 16.0;
  }
  if (DAT_00951be8 == 0) {
    local_3c[1] = *(float *)(DAT_00925164 + 0x48);
    iVar7 = 2;
    _DAT_00955b40 = 1;
    local_3c[2] = local_84 + (float)fVar8 * (local_88 - local_84);
  }
  else {
    local_3c[1] = *(float *)(DAT_00925164 + 0x48);
    iVar7 = 3;
    _DAT_00955b40 = 3;
    local_3c[2] = *(float *)(DAT_00925164 + 0x48) + _DAT_00805114;
    local_3c[3] = local_84 + (float)fVar8 * (local_88 - local_84);
  }
  iVar2 = *(int *)(PTR_DAT_00802c54 + 0x5110);
  fVar3 = *(float *)(iVar2 + 0xc);
  if (bVar4) {
    fVar3 = local_8c;
  }
  *(float *)(DAT_00955b38 + 0x80c) = fVar3;
  *(undefined4 *)(DAT_00955b38 + 0x810) = *(undefined4 *)(iVar2 + 0x10);
  *(undefined4 *)(DAT_00955b38 + 0x814) = *(undefined4 *)(iVar2 + 0x14);
  *(undefined4 *)(DAT_00955b38 + 0x100) = *(undefined4 *)(iVar2 + 0x1c);
  *(undefined4 *)(DAT_00955b38 + 0x104) = *(undefined4 *)(iVar2 + 0x18);
  uVar5 = _DAT_00805104;
  *(undefined4 *)(DAT_00955b38 + 0x110) = _DAT_00805104;
  *(undefined4 *)(DAT_00955b38 + 0x480) = *(undefined4 *)(iVar2 + 0x1c);
  *(undefined4 *)(DAT_00955b38 + 0x484) = *(undefined4 *)(iVar2 + 0x18);
  *(undefined4 *)(DAT_00955b38 + 0x490) = uVar5;
  *(float *)(DAT_00955b38 + 0x81c) = local_3c[iVar7] * _DAT_00805100;
  local_80 = (double)CONCAT44(local_80._4_4_,local_3c[iVar7]);
  *(float *)(DAT_00955b38 + 0x820) = local_3c[iVar7];
  FUN_005952c0(&local_74,&local_5c,&DAT_00805108);
  FUN_005e8950(iVar6,local_3c + 1,iVar7);
  *(float *)(DAT_00955b3c + 0x80c) = local_8c;
  FUN_005952c0(&local_68,&local_5c,&DAT_00805108);
  FUN_005e8950(iVar6,local_3c + 1,iVar7);
  return;
}

