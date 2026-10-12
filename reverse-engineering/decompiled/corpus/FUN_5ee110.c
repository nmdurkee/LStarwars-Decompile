/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ee110; label: FUN_005ee110
 */

void FUN_005ee110(float *param_1)

{
  float *in_ECX;
  float local_e0;
  float local_dc;
  undefined4 local_d8;
  float local_c4;
  float local_c0;
  undefined4 local_bc;
  float local_a8;
  float local_a4;
  undefined4 local_a0;
  float local_8c;
  float local_88;
  undefined4 local_84;
  float local_70;
  float local_6c;
  undefined4 local_68;
  float local_54;
  float local_50;
  undefined4 local_4c;
  float local_38;
  float local_34;
  undefined4 local_30;
  float local_1c;
  float local_18;
  undefined4 local_14;
  
  local_e0 = *param_1 * 0.5 + 0.5;
  local_dc = 0.5 - param_1[1] * 0.5;
  local_d8 = 0x3f800000;
  local_c0 = 0.5 - in_ECX[1] * 0.5;
  local_bc = 0x3f800000;
  local_a0 = 0x3f800000;
  local_8c = *in_ECX * 0.5 + 0.5;
  local_84 = 0x3f800000;
  local_68 = 0x3f800000;
  local_4c = 0x3f800000;
  local_30 = 0x3f800000;
  local_14 = 0x3f800000;
  local_c4 = local_e0;
  local_a8 = local_e0;
  local_a4 = local_c0;
  local_88 = local_c0;
  local_70 = local_8c;
  local_6c = local_c0;
  local_54 = local_8c;
  local_50 = local_dc;
  local_38 = local_8c;
  local_34 = local_dc;
  local_1c = local_e0;
  local_18 = local_dc;
  FUN_005dbb40(&local_e0,0,8);
  return;
}

