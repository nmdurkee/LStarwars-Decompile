/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5bc2b0; label: FUN_005bc2b0
 */

float10 FUN_005bc2b0(undefined4 param_1,float param_2)

{
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_40 = 0xbf800000;
  local_3c = 0x40400000;
  local_38 = 0xc0400000;
  local_34 = 0x3f800000;
  local_30 = 0x40400000;
  local_2c = 0xc0c00000;
  local_28 = 0x40400000;
  local_24 = 0;
  local_18 = 0;
  local_14 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_20 = 0xc0400000;
  local_1c = 0x40400000;
  local_10 = 0x3f800000;
  local_4c = param_2 * param_2;
  local_50 = param_2 * local_4c;
  FUN_005b3f50(&local_60,param_1,&local_40);
  return (float10)(local_58 * param_2 + local_5c * local_4c + local_60 * local_50 + local_54);
}

