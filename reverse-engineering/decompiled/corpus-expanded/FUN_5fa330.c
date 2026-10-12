/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa330; label: FUN_005fa330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fa330(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_5c = 0x3f800000;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = _DAT_0080e258;
  local_60 = _DAT_0080e25c;
  FUN_005b45a0(&DAT_02857108,&local_64);
  local_70 = _DAT_0080e260;
  local_6c = _DAT_0080e264;
  FUN_005b4500(&DAT_028570c8,&local_70);
  FUN_005c1240(&DAT_02857088,param_2,&DAT_02857108);
  FUN_005c1240(&DAT_02857088,&DAT_02857088,&DAT_028570c8);
  puVar2 = &DAT_00986eb8;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_02857088;
  puVar3 = &DAT_0280d820;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_005b5e90(local_40,&DAT_00986eb8);
  _DAT_0280d808 = local_10 / local_4;
  _DAT_0280d80c = local_c / local_4;
  _DAT_0280d810 = local_8 / local_4;
  _DAT_0280d814 = 0x3f800000;
  FUN_005c1240(&DAT_0097e230,&DAT_00986eb8,&DAT_0280d820);
  FUN_005b5e90(&DAT_0280d860,&DAT_0097e230);
  FUN_007412e0(0x12,&DAT_00986eb8);
  FUN_007412e0(0x13,&DAT_0097e230);
  FUN_007412e0(0x5a,&DAT_0280d808);
  FUN_005bfe80(&DAT_0280d820,local_48,local_44,&local_88,&local_84);
  local_58 = local_88;
  local_54 = local_84;
  local_50 = local_84 - local_88;
  local_4c = 1.0 / _DAT_0280d848;
  FUN_007412e0(0x46,&local_58);
  FUN_005b7a70(&DAT_0280d820,&local_80,&local_7c,&local_78,&local_74,&local_88,&local_84);
  local_7c = local_7c - local_80;
  local_74 = local_74 - local_78;
  FUN_007412e0(0x47,&local_80);
  return;
}

