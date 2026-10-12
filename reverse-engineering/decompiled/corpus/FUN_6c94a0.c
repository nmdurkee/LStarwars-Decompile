/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c94a0; label: FUN_006c94a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c94a0(int param_1,undefined4 param_2)

{
  int iVar1;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined1 local_60 [16];
  undefined1 local_50 [32];
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = FUN_006c8760(0x40,DAT_02973ab4,&local_84,0);
    if (iVar1 == 0) {
      local_84 = 1.0;
    }
    iVar1 = FUN_006c8760(0x10,DAT_02973abc,local_50,0);
    if (iVar1 == 0) {
      iVar1 = FUN_006c8760(8,DAT_02973ab8,local_60,0);
      if (iVar1 == 0) {
        return;
      }
      FUN_006ba6a0(0);
      FUN_006bb070(local_60,local_84,0x3f800000,param_2);
    }
    else {
      FUN_006ba6a0();
      FUN_006bb070(&local_20,local_84,0x3f800000,param_2);
      local_80 = local_20 - local_84 * local_30;
      local_7c = local_1c - local_2c * local_84;
      local_78 = local_18 - local_84 * local_28;
      local_64 = local_74;
      local_70 = local_80;
      local_6c = local_7c;
      local_68 = local_78;
      FUN_006bbec0(&local_20,&local_70,4,param_2,_DAT_008203ac,_DAT_008203b0,_DAT_008203b4,
                   _DAT_008203b8);
    }
    if (DAT_02973a60 != 0) {
      if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
        FUN_006009c0();
      }
      DAT_02973a60 = 0;
    }
  }
  return;
}

