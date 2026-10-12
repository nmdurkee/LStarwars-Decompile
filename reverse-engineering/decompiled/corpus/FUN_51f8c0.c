/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51f8c0; label: FUN_0051f8c0
 */

void FUN_0051f8c0(undefined4 *param_1,float param_2,float param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 int param_9)

{
  int iVar1;
  int iVar2;
  float local_54 [3];
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  undefined4 local_30;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_c;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = param_3;
  FUN_005b3620(&local_24,&local_24,param_4);
  FUN_005b37d0(&local_24,&local_24,param_1);
  iVar2 = 1;
  local_30 = param_7;
  local_c = param_7;
  if (0 < param_9) {
    do {
      local_44 = local_20;
      local_20 = param_1[1];
      local_48 = local_24;
      iVar1 = (iVar2 << 0x10) / param_9;
      local_40 = local_1c;
      local_54[0] = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * param_2;
      local_54[1] = 0.0;
      local_54[2] = (float)(&DAT_029899a0)[iVar1 + 0x4000 >> 1 & 0x7fff] * param_3;
      local_24 = *param_1;
      local_1c = (float)param_1[2];
      FUN_005b3620(local_54,local_54,param_4);
      FUN_005b37d0(&local_24,param_1,local_54);
      local_44 = param_5;
      local_20 = param_5;
      FUN_00512cc0(local_48,param_5,local_40,local_24,param_5,local_1c,param_7);
      local_44 = param_6;
      local_20 = param_6;
      FUN_00512cc0(local_48,param_6,local_40,local_24,param_6,local_1c,param_7);
      local_48 = local_24;
      local_44 = param_5;
      local_40 = local_1c;
      FUN_00512cc0(local_24,param_5,local_1c,local_24,local_20,local_1c,param_7);
      iVar2 = iVar2 + 1;
    } while (iVar2 <= param_9);
  }
  return;
}

