/* Ghidra analysis pseudocode, not original source.
 * ev_e9352ae8b4f9815c7bd33078f32d38974dd715693a5fa54abaaf9429a7276350
 * Entry: 0x5191f0; label: FUN_005191f0
 */

void FUN_005191f0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_108;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_e4;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_c0;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_9c;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_78;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_54;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_c;
  
  local_120 = *in_ECX;
  local_11c = in_ECX[1];
  local_118 = in_ECX[2];
  local_fc = *in_EAX;
  puVar1 = &local_120;
  iVar2 = 8;
  local_f8 = in_ECX[1];
  local_f4 = in_ECX[2];
  local_d8 = *in_EAX;
  local_d4 = in_ECX[1];
  local_d0 = in_EAX[2];
  local_b4 = *in_ECX;
  local_b0 = in_ECX[1];
  local_ac = in_EAX[2];
  local_90 = *in_ECX;
  local_8c = in_EAX[1];
  local_88 = in_ECX[2];
  local_6c = *in_EAX;
  local_68 = in_EAX[1];
  local_64 = in_ECX[2];
  local_48 = *in_EAX;
  local_44 = in_EAX[1];
  local_40 = in_EAX[2];
  local_24 = *in_ECX;
  local_20 = in_EAX[1];
  local_1c = in_EAX[2];
  do {
    FUN_005b30a0(puVar1,puVar1,param_1);
    puVar1 = puVar1 + 9;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_108 = param_2;
  local_e4 = param_2;
  local_c0 = param_2;
  local_9c = param_2;
  local_78 = param_2;
  local_54 = param_2;
  local_30 = param_2;
  local_c = param_2;
  FUN_00512cc0(local_120,local_11c,local_118,local_fc,local_f8,local_f4,param_2);
  FUN_00512cc0(local_fc,local_f8,local_f4,local_d8,local_d4,local_d0,param_2);
  FUN_00512cc0(local_d8,local_d4,local_d0,local_b4,local_b0,local_ac,param_2);
  FUN_00512cc0(local_b4,local_b0,local_ac,local_120,local_11c,local_118,param_2);
  FUN_00512cc0(local_90,local_8c,local_88,local_6c,local_68,local_64,param_2);
  FUN_00512cc0(local_6c,local_68,local_64,local_48,local_44,local_40,param_2);
  FUN_00512cc0(local_48,local_44,local_40,local_24,local_20,local_1c,param_2);
  FUN_00512cc0(local_24,local_20,local_1c,local_90,local_8c,local_88,param_2);
  FUN_00512cc0(local_120,local_11c,local_118,local_90,local_8c,local_88,param_2);
  FUN_00512cc0(local_fc,local_f8,local_f4,local_6c,local_68,local_64,param_2);
  FUN_00512cc0(local_d8,local_d4,local_d0,local_48,local_44,local_40,param_2);
  FUN_00512cc0(local_b4,local_b0,local_ac,local_24,local_20,local_1c,param_2);
  return;
}

