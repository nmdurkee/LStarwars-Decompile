/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d2a20; label: FUN_006d2a20
 */

void FUN_006d2a20(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  char *pcVar7;
  float local_144;
  undefined4 local_140;
  int local_13c;
  undefined4 local_138;
  int local_134;
  float local_130;
  float local_12c;
  float local_128;
  undefined1 local_118 [128];
  char local_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&local_144;
  local_134 = param_1;
  pfVar1 = (float *)(param_1 + 0x20);
  pfVar2 = (float *)(param_1 + 0x30);
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  if (*(char *)(param_1 + 0x60) == '\0') {
    local_144 = 0.0;
  }
  else {
    local_144 = *(float *)(param_1 + 0x158);
  }
  iVar3 = FUN_006e6b90();
  local_130 = *pfVar2 + *pfVar1;
  local_12c = *(float *)(param_1 + 0x34) + *(float *)(param_1 + 0x24);
  local_128 = *(float *)(param_1 + 0x38) + *(float *)(param_1 + 0x28);
  local_144 = (float)FUN_005b9e30();
  FUN_006ba6a0(0);
  FUN_006ba7d0(pfVar1,&local_130,local_144);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  fVar5 = 0.0;
  if (DAT_02973c20 != 0) {
    local_128 = 0.0;
    if (DAT_0081fa9c < 1) {
      local_130 = 0.0;
    }
    else {
      local_130 = *(float *)(DAT_0081fa94 + 8);
      fVar5 = *(float *)(DAT_0081fa94 + 0xc);
      local_128 = *(float *)(DAT_0081fa94 + 0x10);
    }
    local_12c = fVar5;
    iVar4 = FUN_006c9180(pfVar1,pfVar2,&local_140,1);
    iVar6 = local_134;
    if (iVar4 == 0) {
      DAT_0081faa0 = 0;
      iVar3 = 0;
      DAT_0081faa4 = 0;
      DAT_0081faa8 = local_138;
      if (((*(char *)(local_134 + 0x83) != '\0') &&
          (local_144 = *(float *)(local_134 + 0x144), local_144 != 0.0)) && (local_12c != 0.0)) {
        FUN_006d2450(&local_130);
      }
    }
    else {
      DAT_0081faa8 = local_138;
      DAT_0081faa0 = local_140;
      DAT_0081faa4 = local_13c;
      if ((*(char *)(local_134 + 0x7b) != '\0') &&
         (local_144 = *(float *)(local_134 + 0x124), local_144 != 0.0)) {
        FUN_006c92d0(pfVar1,pfVar2,&local_140,&local_130,1);
        FUN_006c9bf0(&local_140,iVar3 != 0);
      }
      iVar3 = FUN_006c8760(2,DAT_02973ac4,local_118,0x80);
      if (iVar3 == 0) {
        pcVar7 = "object : no name";
      }
      else {
        _sprintf(local_98,"object : %s",local_118);
        pcVar7 = local_98;
      }
      FUN_006bca20(pcVar7);
      iVar3 = local_13c;
      iVar6 = local_134;
    }
    if ((*(char *)(iVar6 + 0x84) != '\0') &&
       (local_144 = *(float *)(iVar6 + 0x148), local_144 != 0.0)) {
      FUN_006c9af0();
    }
    if (((iVar3 == 0) && (*(char *)(iVar6 + 0x7b) != '\0')) &&
       (local_144 = *(float *)(iVar6 + 0x124), local_144 != 0.0)) {
      local_140 = 0;
      local_13c = 0;
      FUN_006c9bf0(&local_140,0);
    }
  }
  __security_check_cookie(local_14 ^ (uint)&local_144);
  return;
}

