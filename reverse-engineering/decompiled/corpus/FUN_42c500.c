/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42c500; label: FUN_0042c500
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042c500(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  int local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 *local_110 [3];
  int local_104;
  undefined4 local_fc;
  undefined4 local_f4;
  undefined4 local_ec;
  int local_e8;
  undefined4 local_e4;
  code *local_d0;
  undefined4 local_84;
  undefined4 local_48 [12];
  undefined1 local_18 [20];
  
  local_114 = param_1[0x42];
  local_118 = param_1[0x39];
  local_120 = param_1[0x55];
  puVar4 = param_1;
  puVar5 = local_48;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_11c = (int)*(short *)((int)param_1 + 0x13e);
  iVar3 = param_1[0x35];
  FUN_0064ac90(param_1,0);
  if ((param_5 != 0) && (iVar3 != 0)) {
    if (((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) || (*(char *)(iVar3 + 0x280) != -1)) {
      local_128 = 0;
      local_12c = 0;
      local_124 = 0x40000000;
      FUN_0054fa60();
      uVar1 = FUN_006e6b90();
      FUN_005b35a0(&local_12c,&local_12c,uVar1);
      FUN_0054fa60();
      uVar1 = FUN_006e6b90();
      FUN_005b3620(&local_12c,&local_12c,uVar1);
    }
    else {
      FUN_0049f630(&local_12c,local_18,iVar3 + 0x80,iVar3 + 0x68,param_3,param_4);
    }
    puVar4 = &DAT_00810210;
    ppuVar6 = local_110;
    for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar6 = (undefined4 *)*puVar4;
      puVar4 = puVar4 + 1;
      ppuVar6 = ppuVar6 + 1;
    }
    local_fc = local_118;
    local_f4 = param_4;
    local_84 = _DAT_00925018;
    local_110[0] = local_48;
    local_110[2] = &local_12c;
    local_e8 = local_11c;
    local_ec = local_120;
    local_e4 = local_114;
    local_104 = param_2;
    local_d0 = FUN_0042cf20;
    iVar3 = FUN_0064d270(local_110);
    if (iVar3 != 0) {
      uVar2 = FUN_0058b720(param_2);
      *(uint *)(iVar3 + 0x218) = uVar2 & 0xffff;
      if ((code *)param_1[0x6d] != (code *)0x0) {
        (*(code *)param_1[0x6d])(iVar3);
      }
    }
  }
  if (param_2 != 0) {
    if (*(char *)(param_2 + 0x7b5) == '\x18') {
      FUN_0058dfa0(param_2);
    }
    FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f400000,0);
    FUN_00549de0(PTR_DAT_008021b4,0xbe4ccccd,0,0);
    if (param_6 != -1) {
      FUN_0049f850(param_2);
    }
  }
  return;
}

