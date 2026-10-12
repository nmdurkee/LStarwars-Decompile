/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c49b0; label: FUN_006c49b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c49b0(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int in_ECX;
  float local_120;
  float local_11c;
  float local_118;
  undefined4 local_114;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  float local_d4;
  undefined1 local_d0 [48];
  float local_a0;
  float local_9c;
  float local_98;
  undefined4 local_94;
  undefined1 local_90 [16];
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  FUN_006bce50(param_1,local_90,param_2);
  FUN_006ba6a0(1);
  uVar4 = DAT_0081f9bc;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bb070(&local_80,_DAT_0081f9b4 * _DAT_0081f9dc,0x3f800000,uVar4);
  uVar4 = DAT_0081f9c0;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bb070(&local_70,_DAT_0081f9b4 * _DAT_0081f9dc,0x3f800000,uVar4);
  uVar4 = DAT_0081f9c4;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bb070(&local_60,_DAT_0081f9b4 * _DAT_0081f9dc,0x3f800000,uVar4);
  FUN_006b7df0();
  local_a0 = (float)local_50;
  local_9c = (float)local_4c;
  local_98 = (float)local_48;
  local_94 = 0x3f800000;
  uVar4 = DAT_0081f9c8;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bada0(local_d0,_DAT_0081f9e0 * _DAT_0081f9b4,uVar4);
  local_a0 = (float)local_40;
  local_9c = (float)local_3c;
  local_98 = (float)local_38;
  local_94 = 0x3f800000;
  uVar4 = DAT_0081f9cc;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bada0(local_d0,_DAT_0081f9e0 * _DAT_0081f9b4,uVar4);
  local_a0 = (float)local_30;
  local_9c = (float)local_2c;
  local_98 = (float)local_28;
  local_94 = 0x3f800000;
  uVar4 = DAT_0081f9d0;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bada0(local_d0,_DAT_0081f9e0 * _DAT_0081f9b4,uVar4);
  local_a0 = local_20;
  local_9c = local_1c;
  local_98 = local_18;
  local_94 = 0x3f800000;
  uVar4 = DAT_0081f9d4;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bada0(local_d0,_DAT_0081f9e0 * _DAT_0081f9b4,uVar4);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  FUN_006ba6a0(0);
  local_d4 = _DAT_0081f9b4 * _DAT_0081f9dc;
  fVar1 = local_d4 * (local_80 - local_20);
  fVar2 = (local_7c - local_1c) * local_d4;
  fVar3 = (local_78 - local_18) * local_d4;
  local_f0 = local_80 - fVar1 * 0.5;
  local_ec = local_7c - fVar2 * 0.5;
  local_e8 = local_78 - fVar3 * 0.5;
  local_e4 = local_114;
  local_120 = fVar1 * 0.5 + local_80;
  local_11c = fVar2 * 0.5 + local_7c;
  local_118 = local_78 + fVar3 * 0.5;
  uVar4 = DAT_0081f9bc;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  local_104 = local_d4 * 0.2;
  FUN_006bbec0(&local_f0,&local_120,8,uVar4,local_104,local_104,0x3f000000,0);
  local_100 = local_d4 * (local_70 - local_20);
  local_fc = (local_6c - local_1c) * local_d4;
  local_f8 = (local_68 - local_18) * local_d4;
  local_f0 = local_70 - local_100 * 0.5;
  local_ec = local_6c - local_fc * 0.5;
  local_e8 = local_68 - local_f8 * 0.5;
  local_100 = local_100 * 0.5;
  local_fc = local_fc * 0.5;
  local_f8 = local_f8 * 0.5;
  local_120 = local_100 + local_70;
  local_11c = local_6c + local_fc;
  local_118 = local_68 + local_f8;
  uVar4 = DAT_0081f9c0;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bbec0(&local_f0,&local_120,8,uVar4,local_104,local_104,0x3e4ccccd,0);
  local_100 = local_d4 * (local_60 - local_20);
  local_fc = (local_5c - local_1c) * local_d4;
  local_f8 = (local_58 - local_18) * local_d4;
  local_f0 = local_60 - local_100 * 0.5;
  local_ec = local_5c - local_fc * 0.5;
  local_e8 = local_58 - local_f8 * 0.5;
  local_100 = local_100 * 0.5;
  local_fc = local_fc * 0.5;
  local_f8 = local_f8 * 0.5;
  local_120 = local_100 + local_60;
  local_11c = local_5c + local_fc;
  local_118 = local_58 + local_f8;
  uVar4 = DAT_0081f9c4;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar4 = 0xff808080;
  }
  FUN_006bbec0(&local_f0,&local_120,8,uVar4,local_104,local_104,0x3e4ccccd,0);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  return;
}

