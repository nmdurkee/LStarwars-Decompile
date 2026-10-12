/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x597780; label: FUN_00597780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597780(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 **ppuVar4;
  int local_140;
  uint local_13c;
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
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x10ac) != 0)) {
    local_13c = 0;
    if (*(short *)(*(int *)(param_1 + 0x10ac) + 0x10c) != 0) {
      local_140 = 0;
      do {
        local_118 = FUN_005be590(*(undefined4 *)(local_140 + 0x10 + *(int *)(param_1 + 0x10ac)),
                                 0x8000);
        local_11c = *(undefined4 *)(local_140 + 0x14 + *(int *)(param_1 + 0x10ac));
        FUN_005c0820(local_110,&local_11c);
        if (*(float *)(*(int *)(param_1 + 0x10ac) + 0x108) != 1.0) {
          local_134 = *(undefined4 *)(*(int *)(param_1 + 0x10ac) + 0x108);
          local_130 = local_134;
          local_12c = local_134;
          FUN_005b4c30(local_110,&local_134);
        }
        iVar2 = *(int *)(param_1 + 0x10ac);
        local_e0 = local_e0 + *(float *)(local_140 + iVar2);
        local_dc = *(float *)(iVar2 + 0x108) * _DAT_00805140 + *(float *)(local_140 + 4 + iVar2) +
                   local_dc;
        local_d8 = *(float *)(local_140 + 8 + iVar2) + local_d8;
        if (local_13c == *(ushort *)(iVar2 + 0x10c) - 1) {
          uVar1 = 2;
        }
        else {
          uVar1 = local_13c & 0x80000001;
          if ((int)uVar1 < 0) {
            uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
          }
        }
        iVar2 = FUN_005cfac0(&DAT_00955b48 + uVar1 * 0xc);
        if (iVar2 != 0) {
          FUN_004329c0(local_128);
          local_124 = _DAT_00805144 + local_124;
          puVar3 = &DAT_00810210;
          ppuVar4 = local_d0;
          for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
            *ppuVar4 = (undefined1 *)*puVar3;
            puVar3 = puVar3 + 1;
            ppuVar4 = ppuVar4 + 1;
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
          local_ac = &DAT_00955b48 + uVar1 * 0xc;
          FUN_0064d270(local_d0);
        }
        local_13c = local_13c + 1;
        local_140 = local_140 + 0x18;
      } while ((int)local_13c < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x10ac) + 0x10c));
    }
    if (*(void **)(param_1 + 0x10ac) != (void *)0x0) {
      _memset(*(void **)(param_1 + 0x10ac),0,0x110);
      *(undefined4 *)(param_1 + 0x10ac) = 0;
    }
  }
  return;
}

