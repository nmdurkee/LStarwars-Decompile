/* Ghidra analysis pseudocode, not original source.
 * ev_7cebcd231b4f420658515fe731eecd90e8f898d61da81d56368ea9915da5e025
 * Entry: 0x5979d0; label: FUN_005979d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005979d0(int param_1)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined1 **ppuVar6;
  int local_13c;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 local_128 [4];
  float local_124;
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 local_110 [48];
  float local_e0;
  float local_dc;
  float local_d8;
  undefined1 *local_d0 [5];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined *local_ac;
  undefined4 local_a4;
  code *local_94;
  code *local_84;
  code *local_7c;
  undefined4 local_44;
  int local_3c;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x10ac) != 0)) &&
     (2 < *(ushort *)(*(int *)(param_1 + 0x10ac) + 0x10c))) {
    local_13c = 0;
    do {
      uVar4 = ((uint)*(ushort *)(*(int *)(param_1 + 0x10ac) + 0x10c) - local_13c) - 1;
      iVar3 = uVar4 * 0x18;
      local_118 = FUN_005be590(*(undefined4 *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10ac)),0x8000);
      local_11c = *(undefined4 *)(iVar3 + 0x14 + *(int *)(param_1 + 0x10ac));
      FUN_005c0820(local_110,&local_11c);
      if (*(float *)(*(int *)(param_1 + 0x10ac) + 0x108) != 1.0) {
        local_134 = *(undefined4 *)(*(int *)(param_1 + 0x10ac) + 0x108);
        local_130 = local_134;
        local_12c = local_134;
        FUN_005b4c30(local_110,&local_134);
      }
      iVar2 = *(int *)(param_1 + 0x10ac);
      local_e0 = *(float *)(iVar2 + iVar3) + local_e0;
      local_dc = *(float *)(iVar2 + 0x108) * _DAT_00805140 + *(float *)(iVar2 + 4 + iVar3) +
                 local_dc;
      local_d8 = *(float *)(iVar2 + 8 + iVar3) + local_d8;
      if (uVar4 == *(ushort *)(iVar2 + 0x10c) - 1) {
        uVar4 = 2;
      }
      else {
        uVar4 = uVar4 & 0x80000001;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
        }
      }
      iVar3 = FUN_005cfac0(&DAT_00955b48 + uVar4 * 0xc);
      if (iVar3 != 0) {
        FUN_004329c0(local_128);
        local_124 = _DAT_00805144 + local_124;
        puVar5 = &DAT_00810210;
        ppuVar6 = local_d0;
        for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppuVar6 = (undefined1 *)*puVar5;
          puVar5 = puVar5 + 1;
          ppuVar6 = ppuVar6 + 1;
        }
        local_bc = 0x3dcccccd;
        local_b8 = 0x3dcccccd;
        local_b4 = 0xc0a00000;
        local_44 = _DAT_00925018;
        local_d0[2] = local_128;
        local_d0[0] = local_110;
        local_3c = param_1 + 0x4d8;
        local_a4 = 0x90;
        local_84 = FUN_00571c50;
        local_7c = FUN_00571c80;
        local_94 = FUN_00571ba0;
        local_ac = &DAT_00955b48 + uVar4 * 0xc;
        FUN_0064d270(local_d0);
      }
      local_13c = local_13c + 1;
    } while (local_13c < 2);
    psVar1 = (short *)(*(int *)(param_1 + 0x10ac) + 0x10c);
    *psVar1 = *psVar1 + -2;
  }
  return;
}

