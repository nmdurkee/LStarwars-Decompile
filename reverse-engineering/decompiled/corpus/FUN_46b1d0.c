/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46b1d0; label: FUN_0046b1d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b1d0(int param_1,float *param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int **ppiVar9;
  char *pcVar10;
  undefined1 auStack_8c [4];
  int local_88;
  int local_84;
  float *local_80;
  int local_7c;
  undefined4 local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  int *local_68;
  float *local_64;
  float *local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_50;
  float local_4c;
  short local_42;
  int local_40;
  uint local_3c;
  undefined1 *local_28;
  undefined1 *local_20;
  byte local_1c;
  int local_14 [2];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_8c;
  local_84 = param_1;
  local_80 = param_2;
  local_14[0] = param_5;
  if (param_5 == 0) {
    if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((DAT_0093d7f4 == 0) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar1) {
      if (bVar2) {
        iVar5 = FUN_0054fa60();
        local_88 = (int)(iVar5 + (iVar5 >> 0x1f & 0x7fffU)) >> 0xf;
        goto LAB_0046b214;
      }
      local_88 = 0;
    }
    else {
      if (!bVar2) goto LAB_0046b59d;
      local_88 = 1;
    }
  }
  else {
    local_88 = (int)*(char *)(param_5 + 0x280);
LAB_0046b214:
    if ((local_88 != 0) && (local_88 != 1)) goto LAB_0046b59d;
  }
  iVar5 = local_88;
  if ((1 < param_3) && ((param_3 < 4 && (param_5 != 0)))) {
    if ((*(int *)(local_84 + 300) == 0) ||
       ((*(ushort *)(*(int *)(local_84 + 300) + 0x7a) & 0x104) != 4)) {
      FUN_0054a8a0(**(undefined4 **)(param_5 + 0xca4),0x3dcccccd,0);
    }
    else {
      FUN_0054a8d0(**(undefined4 **)(param_5 + 0xca4),1,0);
    }
  }
  if (((0.0 < _DAT_00925040) || (param_3 == 2)) || (param_3 == 3)) {
    pcVar10 = "PickupCoinB";
  }
  else {
    pcVar10 = "PickupCoin";
  }
  FUN_00681f40(pcVar10,local_80);
  iVar4 = FUN_00570bb0();
  pfVar3 = local_80;
  if (iVar4 == 0) {
    local_74 = _DAT_007fc2e0;
    if (iVar5 != 1) {
      local_74 = -_DAT_007fc2e0;
    }
    local_7c = 0;
    local_70 = _DAT_007fc2e4 + _DAT_007fc310;
    _DAT_0087b94c = _DAT_008033a8 + 1.0;
    local_78 = _DAT_007fc2f4;
  }
  else {
    local_74 = *(float *)(&DAT_0087b9ac + iVar5 * 4);
    local_7c = 1;
    local_70 = _DAT_007fc310;
    _DAT_0087b940 = _DAT_008033a8 + 1.0;
    local_78 = _DAT_007fc368;
  }
  local_6c = 0x3f800000;
  param_4 = *(short *)(&DAT_007f8e08 + param_3 * 0x38) + param_4;
  if ((param_4 == -1) ||
     (iVar5 = *(int *)(local_84 + 0x2ac0), *(char *)(param_4 * 0x10 + 0xe + iVar5) == '\0'))
  goto LAB_0046b59d;
  uVar6 = (uint)*(ushort *)(&DAT_007f8e0a + param_3 * 0x38);
  puVar8 = &DAT_00802cd8;
  ppiVar9 = &local_68;
  for (iVar4 = 0x14; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppiVar9 = (int *)*puVar8;
    puVar8 = puVar8 + 1;
    ppiVar9 = ppiVar9 + 1;
  }
  local_42 = (short)param_4;
  local_40 = local_42 * 0x10 + iVar5;
  local_84 = 0;
  local_1c = (byte)local_88;
  if ((local_14[0] == 0) || (*(int *)(local_14[0] + 0x7fc) == 0)) {
    uVar7 = 0;
    local_3c = uVar6;
  }
  else {
    if ((DAT_0087b924 & 1 << (local_1c & 0x1f)) == 0) {
LAB_0046b487:
      uVar7 = 0;
      local_3c = uVar6;
    }
    else {
      if (DAT_007f39e4 != 0) {
        uVar6 = uVar6 * 2;
        goto LAB_0046b487;
      }
      iVar5 = *(int *)(local_14[0] + 0x7fc);
      uVar7 = (uint)*(byte *)(iVar5 + 10);
      local_3c = uVar7 * uVar6;
      if (*(byte *)(iVar5 + 10) < 10) {
        *(char *)(iVar5 + 10) = *(char *)(iVar5 + 10) + '\x01';
      }
      *(undefined4 *)(*(int *)(local_14[0] + 0x7fc) + 0xc) = 0x3f000000;
    }
    if (0.0 < *(float *)(local_14[0] + 0xdec)) {
      local_3c = local_3c * 2;
    }
  }
  if (local_7c != 0) {
    local_28 = &LAB_0046af00;
  }
  local_5c = DAT_00950f60 * _DAT_007fc2f0;
  local_60 = &local_74;
  local_64 = local_80;
  local_50 = 0x2012d;
  local_20 = &LAB_0046af20;
  local_4c = _DAT_008033a8;
  local_58 = local_78;
  FUN_00560b60(&local_68);
  if (uVar7 != 0) {
    _sprintf((char *)local_14,(char *)&PTR_LAB_00758ca8,uVar7);
    puVar8 = &DAT_00802cd8;
    ppiVar9 = &local_68;
    for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
      *ppiVar9 = (int *)*puVar8;
      puVar8 = puVar8 + 1;
      ppiVar9 = ppiVar9 + 1;
    }
    local_5c = 2.0;
    local_58 = 0x40000000;
    local_4c = 0.25;
    local_68 = local_14;
    local_64 = pfVar3;
    local_60 = pfVar3;
    local_50 = 0x8007;
    FUN_00560b60(&local_68);
  }
LAB_0046b59d:
  __security_check_cookie(local_c ^ (uint)auStack_8c);
  return;
}

