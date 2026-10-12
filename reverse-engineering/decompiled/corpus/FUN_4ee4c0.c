/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ee4c0; label: FUN_004ee4c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ee4c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  float10 fVar7;
  char *pcVar8;
  uint local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [8];
  float local_44;
  undefined1 local_40 [64];
  
  local_64 = 1e+09;
  local_58 = DAT_0093b0cc;
  iVar2 = 0;
  local_68 = 0;
  local_60 = 0;
  local_54 = DAT_0093b0d0;
  local_50 = DAT_0093b0d4;
  if (0.0 < _DAT_0088a648) {
    _DAT_0088a648 = _DAT_0088a648 - _DAT_00925018;
  }
  if (0.0 < _DAT_0088a64c) {
    _DAT_0088a64c = _DAT_0088a64c - _DAT_00925018;
  }
  if (DAT_0093d7f0 == 0) {
    _DAT_0088a674 = 30.0;
  }
  else {
    _DAT_0088a674 = *(float *)(*(int *)(*(int *)(DAT_0093d7f0 + 0x54) + 0x24) + 0x1c) * 1.25;
  }
  fVar7 = (float10)FUN_005b9ef0(&DAT_00802538);
  local_5c = (float)(fVar7 * (float10)4.0);
  if (1.0 <= local_5c) {
    if (2.0 <= local_5c) {
      iVar3 = 0x23;
      if (3.0 <= local_5c) {
        iVar3 = 0x24;
      }
    }
    else {
      iVar3 = 0x30;
    }
  }
  else {
    iVar3 = 0x21;
  }
  fVar7 = (float10)FUN_005b9ef0(&DAT_00802538,&local_58,&local_68,&local_60,0);
  local_5c = (float)(fVar7 * (float10)0.10000000149011612 + (float10)_DAT_0088a58c);
  FUN_00550a20(DAT_0087aa94,local_5c);
  uVar1 = FUN_0054fa60(0);
  uVar1 = FUN_0054fa60(uVar1);
  FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + iVar3 * 0x14),&local_58,
               0x5a,_DAT_00925018,uVar1);
  FUN_005b44e0(local_40);
  FUN_00550a20(DAT_0087aa94,_DAT_0088a58c,&local_58,&local_68,&local_60,0);
  FUN_005b5060(local_40,local_68 & 0xffff);
  FUN_005b4900(local_40,&DAT_0088a580);
  if (1.0 <= _DAT_0088a58c) {
    FUN_005cfc00(&DAT_0087aad8,0);
  }
  else {
    FUN_005ea570(&DAT_0087aad8,local_40);
  }
  if (_DAT_0088a66c <= 0.0) {
    puVar4 = &DAT_0088a570;
    puVar6 = &DAT_0088a650;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  piVar5 = &DAT_0093d7f0;
  do {
    iVar3 = *piVar5;
    if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0xe20) & 0x20) == 0)) {
      FUN_005b3800(local_4c,iVar3 + 0x5c,&DAT_0088a580);
      FUN_005b3620(local_4c,local_4c,-(local_68 & 0xffff));
      uVar1 = DAT_00955570;
      if (local_44 < local_64) {
        local_64 = local_44;
        DAT_00955570 = uVar1;
        if (0.0 <= local_44) goto LAB_004ee7e3;
        iVar2 = *piVar5;
      }
      DAT_00955570 = uVar1;
      if (local_44 < 0.0) {
        if (*(char *)(*piVar5 + 0x28b) != '\0') {
          _DAT_0088a594 = 0.2;
        }
        FUN_00656d40(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x8fc),iVar2 + 0x5c,
                     iVar2 + 0x68,0x28,_DAT_00925018,0,0);
        if ((*(uint *)(*piVar5 + 0x1f8) & 0x40000) == 0) {
          DAT_00955570 = 1;
          DAT_00955574 = 1;
          FUN_00438230(0,*piVar5,1,0,0,1);
          DAT_00955570 = uVar1;
        }
      }
    }
LAB_004ee7e3:
    piVar5 = piVar5 + 1;
  } while ((int)piVar5 < 0x93d810);
  if ((1.0 <= _DAT_0088a594) || (iVar2 != 0)) {
    if ((_DAT_0088a594 == 0.2) && (iVar2 != 0)) {
      _DAT_0088a594 = 0.2;
    }
    else {
      _DAT_0088a594 = 1.0;
      if (10.0 < local_64) {
        _DAT_0088a594 = 1.75;
      }
    }
  }
  else {
    _DAT_0088a594 = _DAT_00925018 / 3.0 + _DAT_0088a594;
  }
  if ((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b258) || (0.5 < _DAT_0092509c)) {
    FUN_005518a0(&DAT_0088a570,_DAT_00925018 * _DAT_0088a674 * _DAT_0088a594);
  }
  FUN_005518a0(&DAT_0088a650,-(_DAT_00925018 * _DAT_0088a674));
  fVar7 = (float10)FUN_005b9ef0(&DAT_00802538);
  if (fVar7 <= (float10)0.949999988079071) goto LAB_004ee92f;
  FUN_005b9ef0(&DAT_00802538);
  iVar2 = FUN_006e6b90();
  if (iVar2 == 0) {
LAB_004ee922:
    pcVar8 = "exp_asteroid";
  }
  else if (iVar2 == 1) {
    pcVar8 = "explode_SDest";
  }
  else {
    if (iVar2 != 2) goto LAB_004ee922;
    pcVar8 = "explode_SDG";
  }
  FUN_00681f40(pcVar8,&DAT_0088a580);
LAB_004ee92f:
  FUN_00681f40("env_lantern_lp",&DAT_0088a580);
  return;
}

