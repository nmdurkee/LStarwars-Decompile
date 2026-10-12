/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c70a0; label: FUN_005c70a0
 */

void FUN_005c70a0(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  float local_12c;
  undefined4 local_128;
  float local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  float local_10c;
  float local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined1 local_c0 [8];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80 [48];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_40 [64];
  
  FUN_005b5a40(local_80,in_ECX + 0x780);
  if (*(int *)(in_ECX + 0x800) == 0) {
    local_150 = 0;
    local_14c = 0;
    local_148 = 0xbf800000;
    FUN_005b3200(&local_150,&local_150,local_80);
    FUN_005b3200(&local_150,&local_150,&DAT_00986eb8);
    FUN_005b3b30(&local_150,&local_150);
    FUN_006e52e0(0x85,&local_150,1);
  }
  else {
    local_150 = local_50;
    local_14c = local_4c;
    local_148 = local_48;
    FUN_005b3110(&local_150,&local_150,&DAT_00986eb8);
    FUN_006e52e0(0x85,&local_150,1);
  }
  local_110 = *(undefined4 *)(in_ECX + 0x80c);
  if (*(float *)(in_ECX + 0x810) <= 0.0) {
    local_10c = 0.0;
  }
  else {
    local_10c = 1.0 / *(float *)(in_ECX + 0x810);
  }
  local_108 = 1.0 - *(float *)(in_ECX + 0x814);
  local_104 = *(undefined4 *)(in_ECX + 0x818);
  FUN_006e52e0(0x86,&local_110,1);
  if (*(int *)(in_ECX + 0x710) == 1) {
    local_140 = 0x447a0000;
  }
  else {
    local_140 = *(undefined4 *)(in_ECX + 0x704);
  }
  local_13c = 0;
  local_138 = 0;
  local_134 = 0;
  FUN_006e52e0(0x88,&local_140,1);
  local_100 = 0x3f000000;
  iVar2 = 0;
  local_fc = 0;
  local_f8 = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_ec = 0xbf000000;
  local_e8 = 0;
  local_e4 = 0;
  local_e0 = 0;
  local_dc = 0;
  local_d4 = 0;
  local_d8 = 0x3f000000;
  local_d0 = 0x3f000000;
  local_cc = 0x3f000000;
  local_c8 = 0x3f000000;
  local_c4 = 0x3f800000;
  if (0 < *(int *)(in_ECX + 0x710)) {
    iVar1 = 0x8d;
    iVar3 = in_ECX + 0x80;
    do {
      FUN_005b59a0(local_40,iVar3 + 0x40);
      FUN_006e52e0(iVar1 + -4,local_40,4);
      FUN_005c1240(local_c0,local_80,iVar3);
      FUN_005c1240(local_c0,local_c0,&local_100);
      FUN_005b5e90(local_c0,local_c0);
      local_150 = local_b8;
      local_14c = local_a8;
      local_148 = local_98;
      local_144 = local_88;
      local_120 = local_b4;
      local_11c = local_a4;
      local_118 = local_94;
      local_114 = local_84;
      FUN_006e52e0(iVar1,&local_150,1);
      FUN_006e52e0(iVar1 + 1,&local_120,1);
      local_130 = *(undefined4 *)(iVar3 + 0x80);
      local_12c = 1.0 - *(float *)(iVar3 + 0x84);
      local_128 = *(undefined4 *)(in_ECX + 0x81c);
      local_124 = *(float *)(in_ECX + 0x820) - *(float *)(in_ECX + 0x81c);
      FUN_006e52e0(iVar1 + 2,&local_130,1);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x380;
      iVar1 = iVar1 + 7;
    } while (iVar2 < *(int *)(in_ECX + 0x710));
  }
  return;
}

