/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x592ed0; label: FUN_00592ed0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592ed0(int param_1,int param_2,int param_3,int param_4,float param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined *local_e8;
  int local_e4;
  undefined1 local_dc [4];
  float local_d8;
  int local_d0 [2];
  undefined1 *local_c8;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined *local_ac;
  int local_a4;
  code *local_94;
  code *local_84;
  code *local_7c;
  undefined4 local_44;
  undefined *local_3c;
  
  iVar2 = (int)*(char *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0x111);
  if (((param_1 != 0) && (iVar2 != -1)) &&
     (*(int *)(*(int *)(param_2 + 0x50) + 0x14 + iVar2 * 4) != 0)) {
    uVar3 = (uint)(*(short *)(param_2 + 0x1064) != *(short *)(param_1 + 0x6c));
    local_e4 = 0;
    local_e8 = &DAT_00955634 + uVar3 * 0x120;
    do {
      if ((local_e4 != 2) &&
         ((local_e4 != 0 ||
          (((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 +
                      (uint)*(ushort *)(*(int *)(param_1 + 0x174) + 2 + uVar3 * 0x38) * 0x28) & 1)
            == 0 && ((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 +
                               (uint)*(ushort *)(*(int *)(param_1 + 0x174) + uVar3 * 0x38) * 0x28) &
                     0x20) == 0)))))) {
        iVar1 = FUN_005cfac0(local_e8);
        if (iVar1 != 0) {
          FUN_004329c0(local_dc);
          local_d8 = local_d8 + param_5;
          if (param_3 != -1) {
            local_d8 = local_d8 + 1.0;
          }
          piVar4 = &DAT_00810210;
          piVar5 = local_d0;
          for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
            *piVar5 = *piVar4;
            piVar4 = piVar4 + 1;
            piVar5 = piVar5 + 1;
          }
          local_bc = 0x3dcccccd;
          local_b8 = 0x3dcccccd;
          local_b4 = 0xc0a00000;
          local_d0[0] = iVar2 * 0x40 + 0x804 + param_2;
          local_c8 = local_dc;
          local_ac = local_e8;
          iVar1 = FUN_0056e0f0(1);
          if (iVar1 == 0) {
            local_3c = (undefined *)(param_2 + 0x4d8);
          }
          else {
            local_3c = &DAT_00955890;
          }
          local_44 = _DAT_00925018;
          local_a4 = (-(uint)(param_4 != 0) & 0xfffffc10) + 0x480;
          local_84 = FUN_00571c50;
          local_7c = FUN_00571c80;
          local_94 = FUN_00571ba0;
          FUN_0064d270(local_d0);
        }
      }
      local_e8 = local_e8 + 0x20;
      local_e4 = local_e4 + 1;
    } while (local_e4 < 9);
  }
  return;
}

