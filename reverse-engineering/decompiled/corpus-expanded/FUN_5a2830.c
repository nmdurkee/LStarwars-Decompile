/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2830; label: FUN_005a2830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2830(float *param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  float local_dc [4];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  float local_c0;
  undefined4 local_bc;
  float local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_9c;
  float local_98;
  undefined4 local_90;
  float local_8c;
  undefined4 local_88;
  float local_78;
  undefined4 local_74;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_dc[1] = param_1[0x14];
  local_dc[0] = 0.0;
  local_90 = 0;
  local_dc[2] = 0.0;
  local_dc[3] = -local_dc[1];
  local_88 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0x80000000;
  local_68 = 0;
  local_64 = 0;
  local_bc = 0;
  local_b8 = -local_dc[3];
  local_b4 = 0x80000000;
  local_44 = 0x80000000;
  local_b0 = 0;
  local_40 = 0;
  local_74 = 0x3f800000;
  local_2c = 0x3f800000;
  local_24 = 0x80000000;
  local_28 = 0x3f800000;
  local_8 = 0x3f800000;
  local_78 = param_1[0x17];
  fVar1 = param_1[0x13];
  local_70 = 0;
  local_1c = 0;
  local_50 = 0;
  local_4c = 0;
  local_4 = 0;
  pfVar3 = local_dc;
  local_c0 = local_dc[3];
  local_9c = local_dc[3];
  local_98 = local_dc[1];
  local_8c = local_dc[1];
  local_6c = local_dc[3];
  local_54 = local_78;
  local_48 = local_b8;
  local_30 = local_78;
  local_20 = local_dc[3];
  local_c = local_78;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = *param_1;
    param_1 = param_1 + 1;
    pfVar3 = pfVar3 + 1;
  }
  FUN_005ddad0(&local_90,4,local_dc,fVar1);
  return;
}

