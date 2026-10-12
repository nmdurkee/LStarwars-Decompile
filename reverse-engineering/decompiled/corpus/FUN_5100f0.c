/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x5100f0; label: FUN_005100f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005100f0(undefined4 param_1,float param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined *puVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  float local_28;
  char local_24 [32];
  uint local_4;
  
  bVar4 = DAT_00921dae;
  local_4 = DAT_00829570 ^ (uint)&local_28;
  if (param_3 == 0) {
    uVar6 = (uint)DAT_008009a1;
    uVar7 = (uint)DAT_00921dae;
    uVar5 = (uint)DAT_008009a2;
  }
  else {
    bVar1 = DAT_008009a1;
    bVar2 = DAT_008009a2;
    bVar3 = DAT_00921dae;
    if (DAT_009213e4 != 0) {
      bVar1 = DAT_00921dad;
      bVar2 = DAT_008009a0;
      bVar3 = DAT_0080099f;
    }
    uVar7 = (uint)bVar3;
    uVar5 = (uint)bVar2;
    uVar6 = (uint)bVar1;
    if (0.0 < _DAT_00921d70) {
      local_28 = (float)(uint)DAT_008009a1;
      uVar6 = FUN_006e6b90();
      local_28 = (float)(uint)bVar4;
      uVar7 = FUN_006e6b90();
      local_28 = (float)(uint)DAT_008009a2;
      uVar5 = FUN_006e6b90();
    }
  }
  _sprintf(local_24,"%s %i",PTR_s_Profile_008009e0,param_4 + 1);
  FUN_0050f4c0(local_24,param_1,param_2,0x3f800000,_DAT_0080098c,_DAT_0080098c,_DAT_0080098c,0,uVar6
               ,uVar7,uVar5,_DAT_00921d60 & 0xff);
  uVar11 = DAT_00921da8;
  uVar9 = DAT_00800998;
  uVar10 = DAT_00800999;
  if ((&DAT_02989540)[param_4] == 0) {
    if (DAT_0080200c < DAT_008015a4) {
      local_28 = _DAT_0080098c * 0.5 + param_2;
      puVar8 = PTR_s_No_Space_008009ec;
      uVar11 = DAT_00921dac;
      uVar9 = DAT_0080099e;
      uVar10 = DAT_00921dab;
    }
    else {
      local_28 = _DAT_0080098c * 0.5 + param_2;
      puVar8 = PTR_s_Empty_008009e8;
    }
  }
  else {
    local_28 = _DAT_0080098c * 0.5 + param_2;
    puVar8 = PTR_s_Present_008009e4;
  }
  FUN_0050f3b0(puVar8,param_1,local_28,0x3f800000,_DAT_0080098c,_DAT_0080098c,_DAT_0080098c,0,uVar9,
               uVar10,uVar11,0x3ecccccd,2,0,0,_DAT_00921d60);
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

