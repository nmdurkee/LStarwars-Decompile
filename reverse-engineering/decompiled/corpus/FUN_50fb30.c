/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50fb30; label: FUN_0050fb30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050fb30(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *_Format;
  float local_190;
  float local_18c;
  char *local_188;
  char local_184 [128];
  char local_104 [128];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_190;
  pcVar6 = "[[accept]]";
  pcVar4 = "[[back]]";
  pcVar5 = "[[padleft]]";
  local_188 = "[[padright]]";
  uVar2 = FUN_006d6350();
  local_190 = (float)FUN_004f48e0(uVar2);
  iVar3 = FUN_006d67a0(local_190);
  if (iVar3 != 0) {
    iVar3 = FUN_006d6d80();
    pcVar6 = *(char **)(iVar3 + 0x70);
    pcVar4 = *(char **)(iVar3 + 4);
    pcVar5 = *(char **)(iVar3 + 0x32c);
    local_188 = *(char **)(iVar3 + 0x334);
  }
  if (param_4 == 0) {
    _sprintf(local_184,"~0$s~~ %s",pcVar6,PTR_s_Select_00800a48);
    _Format = "~0%s~~ %s";
    pcVar6 = pcVar4;
    pcVar4 = PTR_DAT_00800a4c;
  }
  else {
    _sprintf(local_184,"%s ~0%s",PTR_s_Select_00800a48,pcVar6);
    _Format = "%s ~0%s";
    pcVar6 = PTR_DAT_00800a4c;
  }
  _sprintf(local_104,_Format,pcVar6,pcVar4);
  iVar3 = FUN_006d67f0(local_190);
  if (iVar3 == 0) {
    pcVar4 = "%s ~0%s~~ / ~0$s";
    pcVar6 = PTR_s_Select_00800a48;
  }
  else {
    pcVar4 = "~0$s~~ %s ~0$s";
    pcVar6 = pcVar5;
    pcVar5 = PTR_s_Select_00800a48;
  }
  _sprintf(local_84,pcVar4,pcVar6,pcVar5,local_188);
  fVar1 = _DAT_008015f4 * _DAT_00800994 * 0.8;
  local_190 = (fVar1 - 0.85) + fVar1;
  local_18c = local_190 - 0.05;
  if (param_1 != 0) {
    local_18c = local_18c - fVar1;
  }
  if (param_2 != 0) {
    local_18c = local_18c - fVar1;
  }
  if (param_3 != 0) {
    local_18c = local_18c - fVar1;
  }
  if (param_1 != 0) {
    if (param_4 == 0) {
      local_190 = -0.85;
    }
    else {
      local_190 = 0.85;
    }
    local_188 = (char *)(_DAT_0080098c * 0.8);
    FUN_0050f4c0(local_184,local_190,local_18c,0x3f800000,local_188,local_188,local_188,
                 (-(param_4 != 0) & 6U) + 6,param_5,param_6,param_7,param_8);
    local_18c = local_18c + _DAT_008015f4 * _DAT_00800994 * 0.8;
  }
  if (param_2 != 0) {
    if (param_4 == 0) {
      local_190 = -0.85;
    }
    else {
      local_190 = 0.85;
    }
    local_188 = (char *)(_DAT_0080098c * 0.8);
    FUN_0050f4c0(local_104,local_190,local_18c,0x3f800000,local_188,local_188,local_188,
                 (-(param_4 != 0) & 6U) + 6,param_5,param_6,param_7,param_8);
    local_18c = local_18c + _DAT_008015f4 * _DAT_00800994 * 0.8;
  }
  if (param_3 != 0) {
    if (param_4 == 0) {
      local_190 = -0.85;
    }
    else {
      local_190 = 0.85;
    }
    local_188 = (char *)(_DAT_0080098c * 0.8);
    FUN_0050f4c0(local_84,local_190,local_18c,0x3f800000,local_188,local_188,local_188,
                 (-(param_4 != 0) & 6U) + 6,param_5,param_6,param_7,param_8);
  }
  __security_check_cookie(local_4 ^ (uint)&local_190);
  return;
}

