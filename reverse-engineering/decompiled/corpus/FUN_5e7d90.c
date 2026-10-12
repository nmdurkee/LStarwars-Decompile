/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e7d90; label: FUN_005e7d90
 */

void FUN_005e7d90(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  char *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  
  if ((*in_ECX != '\0') && (in_ECX[1] != '\0')) {
    local_90 = *param_1;
    puVar1 = &local_90;
    local_6c = param_1[1];
    iVar2 = 8;
    local_88 = param_1[2];
    local_80 = *param_2;
    local_8c = param_2[1];
    local_78 = param_2[2];
    local_84 = 0x3f800000;
    local_74 = 0x3f800000;
    local_64 = 0x3f800000;
    local_54 = 0x3f800000;
    local_44 = 0x3f800000;
    local_34 = 0x3f800000;
    local_24 = 0x3f800000;
    local_14 = 0x3f800000;
    local_7c = local_8c;
    local_70 = local_80;
    local_68 = local_78;
    local_60 = local_90;
    local_5c = local_6c;
    local_58 = local_88;
    local_50 = local_90;
    local_4c = local_8c;
    local_48 = local_78;
    local_40 = local_80;
    local_3c = local_8c;
    local_38 = local_88;
    local_30 = local_80;
    local_2c = local_6c;
    local_28 = local_88;
    local_20 = local_90;
    local_1c = local_6c;
    local_18 = local_78;
    do {
      FUN_005b30a0(puVar1,puVar1,param_3);
      puVar1 = puVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_005e7840(&local_90,&local_80,&local_70,&local_60);
    FUN_005e7840(&local_50,&local_40,&local_30,&local_20);
  }
  return;
}

