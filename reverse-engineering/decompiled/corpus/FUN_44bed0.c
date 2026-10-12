/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44bed0; label: FUN_0044bed0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0044bed0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  float10 fVar7;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 *local_120 [4];
  undefined4 local_110;
  float local_10c;
  float local_108;
  undefined4 local_104;
  int local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined1 *local_ec;
  undefined1 *local_e8;
  code *local_e0;
  undefined1 *local_dc;
  undefined4 local_94;
  float local_60;
  undefined4 local_58 [16];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_144 = 0.0;
  local_140 = 0.0;
  local_13c = 0.0;
  if (param_6 != 0) {
    iVar4 = 0;
    local_12c = 0;
    local_128 = 0;
    local_124 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"from=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757c64);
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757c60);
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757c5c);
              if (iVar1 != 0) {
                fVar7 = (float10)FUN_005147c0(param_2,iVar1 + 3);
                local_13c = (float)fVar7;
              }
            }
            else {
              fVar7 = (float10)FUN_005147c0(param_2,iVar1 + 3);
              local_140 = (float)fVar7;
            }
          }
          else {
            fVar7 = (float10)FUN_005147c0(param_2,iVar1 + 3);
            local_144 = (float)fVar7;
          }
        }
        else {
          FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&local_12c,iVar1 + 5,1);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    iVar4 = FUN_005cfac0(&local_12c);
    if (iVar4 != 0) {
      puVar2 = (undefined4 *)FUN_005d0330(&local_12c);
      puVar5 = local_58;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
      pfVar3 = (float *)FUN_005b4b90(local_c,local_58);
      local_150 = 1.0 / *pfVar3;
      local_14c = 1.0 / pfVar3[1];
      local_148 = 1.0 / pfVar3[2];
      FUN_005b4c30(local_58,&local_150);
      if (((local_144 != 0.0) || (local_140 != 0.0)) || (local_13c != 0.0)) {
        FUN_005b4900(local_58,&local_144);
      }
      local_138 = 0;
      local_134 = 0;
      local_130 = 0x3f800000;
      FUN_005b3200(&local_138,&local_138,local_58);
      puVar2 = &DAT_00810210;
      ppuVar6 = local_120;
      for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
        *ppuVar6 = (undefined4 *)*puVar2;
        puVar2 = puVar2 + 1;
        ppuVar6 = ppuVar6 + 1;
      }
      local_120[2] = &local_138;
      local_120[0] = local_58;
      FUN_005d0260(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe80,local_18,&local_10c);
      local_f8 = 0xe8;
      local_10c = _DAT_007f6844 * local_10c;
      local_94 = _DAT_00925018;
      local_fc = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe80;
      local_104 = 0;
      local_f4 = 0x831b;
      local_dc = &LAB_0044be10;
      local_60 = _DAT_007f6844;
      local_ec = &LAB_0044bb40;
      local_e8 = &LAB_0044bea0;
      local_e0 = FUN_0042cf20;
      local_110 = DAT_0093d810;
      local_108 = local_10c;
      FUN_0064d270(local_120);
    }
    return 1;
  }
  return 1;
}

