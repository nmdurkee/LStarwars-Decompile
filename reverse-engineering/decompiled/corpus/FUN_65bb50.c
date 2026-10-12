/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65bb50; label: FUN_0065bb50
 */

void FUN_0065bb50(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  float *pfVar1;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float *local_144;
  int local_140;
  int local_13c;
  undefined4 local_138;
  float local_134 [60];
  float local_44;
  float local_40;
  undefined4 local_30;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_c;
  
  local_138 = 0xbf800000;
  local_134[0] = -1.0;
  local_134[1] = 1.0;
  local_134[2] = 1.0;
  local_144 = local_134;
  local_134[4] = 1.0;
  local_134[5] = 1.0;
  local_134[6] = 1.0;
  local_134[7] = 1.0;
  local_140 = 4;
  local_134[9] = 1.0;
  local_134[10] = 1.0;
  local_134[0xd] = 1.0;
  local_134[0x11] = 1.0;
  local_134[0x14] = 1.0;
  local_134[0x15] = 1.0;
  local_134[0x18] = 1.0;
  local_134[0x1f] = 1.0;
  local_134[0x24] = 1.0;
  local_134[0x27] = 1.0;
  local_134[0x28] = 1.0;
  local_134[0x2b] = 1.0;
  local_134[0x2c] = 1.0;
  local_134[0x2e] = 1.0;
  local_134[0x2f] = 1.0;
  local_134[0x32] = 1.0;
  local_134[0x33] = 1.0;
  local_134[0x35] = 1.0;
  local_134[0x36] = 1.0;
  local_134[0x37] = 1.0;
  local_134[0x38] = 1.0;
  local_134[0x3a] = 1.0;
  local_134[3] = -1.0;
  local_134[8] = -1.0;
  local_134[0xb] = -1.0;
  local_134[0xc] = -1.0;
  local_134[0xe] = -1.0;
  local_134[0xf] = -1.0;
  local_134[0x10] = -1.0;
  local_134[0x12] = -1.0;
  local_134[0x13] = -1.0;
  local_134[0x16] = -1.0;
  local_134[0x17] = -1.0;
  local_134[0x19] = -1.0;
  local_134[0x1a] = -1.0;
  local_134[0x1b] = -1.0;
  local_134[0x1c] = -1.0;
  local_134[0x1d] = -1.0;
  local_134[0x1e] = -1.0;
  local_134[0x20] = -1.0;
  local_134[0x21] = -1.0;
  local_134[0x22] = -1.0;
  local_134[0x23] = -1.0;
  local_134[0x25] = -1.0;
  local_134[0x26] = -1.0;
  local_134[0x29] = -1.0;
  local_134[0x2a] = -1.0;
  local_134[0x2d] = -1.0;
  local_134[0x30] = -1.0;
  local_134[0x31] = -1.0;
  local_134[0x34] = -1.0;
  local_134[0x39] = -1.0;
  do {
    local_13c = 4;
    pfVar1 = local_144;
    do {
      local_15c = pfVar1[-1] * param_4;
      local_158 = *pfVar1 * param_5;
      local_154 = pfVar1[1] * param_6;
      local_150 = param_4 * pfVar1[2];
      local_14c = param_5 * pfVar1[3];
      local_148 = param_6 * pfVar1[4];
      FUN_005b3690(&local_15c,&local_15c,param_7);
      FUN_005b3620(&local_15c,&local_15c,param_8);
      FUN_005b35a0(&local_15c,&local_15c,param_9);
      FUN_005b3690(&local_15c,&local_15c,param_10);
      FUN_005b3620(&local_15c,&local_15c,param_11);
      FUN_005b3690(&local_150,&local_150,param_7);
      FUN_005b3620(&local_150,&local_150,param_8);
      FUN_005b35a0(&local_150,&local_150,param_9);
      FUN_005b3690(&local_150,&local_150,param_10);
      FUN_005b3620(&local_150,&local_150,param_11);
      local_134[0x3b] = param_1 + local_15c;
      local_30 = param_12;
      local_c = param_12;
      local_44 = param_2 + local_158;
      local_40 = param_3 + local_154;
      local_24 = local_150 + param_1;
      local_20 = param_2 + local_14c;
      local_1c = param_3 + local_148;
      FUN_005dbed0(local_134 + 0x3b,param_13,0);
      pfVar1 = pfVar1 + 3;
      local_13c = local_13c + -1;
    } while (local_13c != 0);
    local_144 = local_144 + 0xf;
    local_140 = local_140 + -1;
  } while (local_140 != 0);
  return;
}

