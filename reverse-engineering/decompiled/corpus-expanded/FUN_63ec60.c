/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63ec60; label: FUN_0063ec60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063ec60(float *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_50 [48];
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  uVar1 = FUN_006e6b90();
  uVar2 = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  uVar5 = FUN_006e6b90();
  uVar6 = FUN_006e6b90();
  FUN_0063ca10(((int)param_1 + (-4 - DAT_0291389c)) / 0x8c,DAT_02913950);
  local_70 = *param_1;
  local_6c = param_1[1];
  local_68 = param_1[2];
  local_88 = -_DAT_0080fde0;
  local_90 = local_88 * param_1[3];
  local_8c = param_1[4] * local_88;
  local_88 = local_88 * param_1[5];
  FUN_006340e0();
  FUN_005b65a0(extraout_ECX,&local_90);
  FUN_006ba6a0(0);
  local_60 = local_90 * -0.5;
  local_5c = local_8c * -0.5;
  local_58 = local_88 * -0.5;
  local_80 = local_70 + local_60;
  local_7c = local_6c + local_5c;
  local_78 = local_68 + local_58;
  local_14 = 0x3f800000;
  local_20 = local_80;
  local_1c = local_7c;
  local_18 = local_78;
  FUN_006bb6b0(local_50,_DAT_0080fde0,_DAT_0080fde0,_DAT_0080fde0,4,
               ((uVar1 | 0xffffff00) << 8 | uVar2 & 0xff) << 8 | uVar3 & 0xff,1,0);
  local_80 = local_70 + local_90;
  local_7c = local_6c + local_8c;
  local_78 = local_68 + local_88;
  local_14 = 0x3f800000;
  local_20 = local_80;
  local_1c = local_7c;
  local_18 = local_78;
  FUN_006bb6b0(local_50,_DAT_0080fde0 * 0.75,_DAT_0080fde0,_DAT_0080fde0 + _DAT_0080fde0,4,
               ((uVar4 | 0xffffff00) << 8 | uVar5 & 0xff) << 8 | uVar6 & 0xff,0,0);
  FUN_006ba760();
  return;
}

