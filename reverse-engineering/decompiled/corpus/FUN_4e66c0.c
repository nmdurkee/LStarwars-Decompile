/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e66c0; label: FUN_004e66c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e66c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 **ppuVar8;
  int local_150;
  undefined4 local_144;
  undefined4 local_140;
  float local_13c;
  int local_138 [5];
  undefined4 local_124;
  undefined4 local_120;
  undefined1 local_11c [12];
  undefined4 *local_110 [5];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 *local_ec;
  undefined4 local_e4;
  code *local_d0;
  undefined1 *local_cc;
  undefined4 local_84;
  float local_6c;
  undefined4 local_48 [17];
  
  local_138[0] = 0;
  local_138[1] = 0xffffffff;
  local_138[2] = 0xffffffff;
  local_138[3] = 0xffffffff;
  iVar2 = FUN_0054fa60();
  iVar7 = ((int)(iVar2 + (iVar2 >> 0x1f & 0x3fffU)) >> 0xe) + 1;
  iVar2 = 1;
  if (1 < iVar7) {
    do {
      iVar3 = FUN_0054fa60();
      local_138[iVar2] = iVar3 / 0x5556 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar7);
  }
  local_150 = 0;
  if (0 < iVar7) {
    do {
      puVar1 = &DAT_0087aad8 + local_138[local_150] * 3;
      iVar2 = FUN_005cfac0(puVar1);
      if (iVar2 != 0) {
        uVar4 = FUN_0054fa60();
        uVar5 = FUN_0054fa60();
        local_138[4] = FUN_0054fa60();
        local_124 = uVar5;
        local_120 = uVar4;
        thunk_FUN_005b5300(local_48,local_138 + 4);
        FUN_005b4900(local_48,param_1 + 0x30);
        local_140 = 0;
        local_144 = 0;
        iVar2 = FUN_0054fa60();
        local_13c = (float)iVar2 * 1.5259022e-05 * 3.0 + 2.0;
        uVar4 = FUN_0054fa60();
        FUN_005b3620(&local_144,&local_144,uVar4);
        puVar6 = &DAT_00810210;
        ppuVar8 = local_110;
        for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppuVar8 = (undefined4 *)*puVar6;
          puVar6 = puVar6 + 1;
          ppuVar8 = ppuVar8 + 1;
        }
        local_110[0] = local_48;
        local_110[2] = &local_144;
        FUN_005d0260(puVar1,local_11c,&local_fc);
        local_f8 = local_fc;
        local_e4 = 0x8000193;
        local_f4 = 0;
        if (local_150 == 0) {
          local_e4 = 0x800019b;
        }
        local_d0 = FUN_0042cf20;
        local_84 = _DAT_00925018;
        local_cc = &LAB_004e6600;
        local_ec = puVar1;
        iVar2 = FUN_0054fa60();
        local_6c = (float)iVar2 * 1.5259022e-05 * 3.0 + 7.0;
        iVar2 = FUN_0064d270(local_110);
        if (iVar2 != 0) {
          *(char *)(iVar2 + 0x206) = (local_150 != 0) + '\x01';
        }
      }
      local_150 = local_150 + 1;
    } while (local_150 < iVar7);
  }
  return;
}

