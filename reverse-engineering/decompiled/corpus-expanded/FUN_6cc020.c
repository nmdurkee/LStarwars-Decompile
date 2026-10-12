/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cc020; label: FUN_006cc020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006cc020(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
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
  
  param_2 = (undefined4 *)*param_2;
  FUN_006ca2f0(&local_60);
  if (param_3 != 0) {
    for (; param_2 != (undefined4 *)0x0; param_2 = (undefined4 *)*param_2) {
      local_50 = _DAT_008065c0;
      local_4c = _DAT_008065c4;
      local_48 = _DAT_008065c8;
      local_44 = _DAT_008065cc;
      local_40 = _DAT_008065d0;
      local_3c = _DAT_008065d4;
      local_38 = _DAT_008065d8;
      local_34 = _DAT_008065dc;
      local_30 = _DAT_008065e0;
      local_2c = _DAT_008065e4;
      local_28 = _DAT_008065e8;
      local_24 = _DAT_008065ec;
      local_20 = _DAT_008065f0;
      local_1c = _DAT_008065f4;
      local_18 = _DAT_008065f8;
      local_14 = _DAT_008065fc;
      iVar1 = FUN_006c8760(0x10,DAT_02973abc,&local_50,0);
      if (iVar1 != 0) {
        if (param_4 == 1) {
          local_60 = local_20;
          local_5c = local_1c;
          local_58 = local_18;
          local_54 = local_14;
          FUN_006b8110();
        }
        else if (param_4 == 2) {
          local_60 = local_20;
          local_5c = local_1c;
          local_58 = local_18;
          local_54 = local_14;
          FUN_006b81f0();
        }
        else {
          if (param_4 != 3) goto LAB_006cc1e2;
          local_60 = local_20;
          local_5c = local_1c;
          local_58 = local_18;
          local_54 = local_14;
          FUN_006b82d0();
        }
        local_20 = local_60;
        local_1c = local_5c;
        local_18 = local_58;
        local_14 = local_54;
        FUN_006c87f0(0x10,DAT_02973abc,&local_50,0);
      }
LAB_006cc1e2:
    }
  }
  return param_4;
}

