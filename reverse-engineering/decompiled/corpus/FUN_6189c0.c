/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x6189c0; label: FUN_006189c0
 */

void FUN_006189c0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,uint param_7,uint param_8,uint param_9,float param_10)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  float local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_5c;
  local_5c = (float)(param_2 << 4);
  local_3c = FUN_006e6b90();
  local_3c = local_3c + in_ECX * 0x10;
  local_18 = FUN_006e6b90();
  local_18 = local_18 + in_ECX * 0x10;
  iVar2 = 0;
  local_14 = param_6;
  local_10 = param_7;
  if (0 < (int)param_10) {
    local_1c = (param_9 >> 0x18) - (param_7 >> 0x18);
    local_24 = (param_9 >> 0x10 & 0xff) - (param_7 >> 0x10 & 0xff);
    local_2c = (param_9 >> 8 & 0xff) - (param_7 >> 8 & 0xff);
    local_34 = (param_9 & 0xff) - (param_7 & 0xff);
    local_38 = (param_8 >> 0x18) - (param_6 >> 0x18);
    local_28 = (param_8 >> 0x10 & 0xff) - (param_6 >> 0x10 & 0xff);
    local_20 = (param_8 >> 8 & 0xff) - (param_6 >> 8 & 0xff);
    iVar1 = 0;
    local_30 = (param_8 & 0xff) - (param_6 & 0xff);
    local_48 = 0;
    local_50 = 0;
    local_54 = 0;
    local_58 = 0;
    local_44 = 0;
    local_40 = 0;
    local_4c = 0;
    local_5c = param_10;
    do {
      local_c = CONCAT13((char)(local_40 / (int)param_10) + param_6._3_1_,
                         CONCAT12((char)(local_4c / (int)param_10) + param_6._2_1_,
                                  CONCAT11((char)(iVar1 / (int)param_10) + (char)(param_6 >> 8),
                                           (char)(iVar2 / (int)param_10) + (char)param_6)));
      local_8 = CONCAT13((char)(local_50 / (int)param_10) + param_7._3_1_,
                         CONCAT12((char)(local_54 / (int)param_10) + param_7._2_1_,
                                  CONCAT11((char)(local_58 / (int)param_10) + (char)(param_7 >> 8),
                                           (char)(local_44 / (int)param_10) + (char)param_7)));
      if (DAT_02912eb8 == 0) {
        FUN_005dbd70(local_3c,local_48 / (int)param_10 + param_1 * 8,local_18 - local_3c,
                     (param_3 * 8) / (int)param_10,&local_14,(&DAT_02900c70)[DAT_02912e90]);
      }
      local_14 = local_c;
      local_10 = local_8;
      iVar2 = iVar2 + local_30;
      iVar1 = iVar1 + local_20;
      local_4c = local_4c + local_28;
      local_44 = local_44 + local_34;
      local_54 = local_54 + local_24;
      local_48 = local_48 + param_3 * 8;
      local_40 = local_40 + local_38;
      local_58 = local_58 + local_2c;
      local_50 = local_50 + local_1c;
      local_5c = (float)((int)local_5c + -1);
    } while (local_5c != 0.0);
    local_5c = 0.0;
  }
  __security_check_cookie(local_4 ^ (uint)&local_5c);
  return;
}

