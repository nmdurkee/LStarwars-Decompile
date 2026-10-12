/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467920; label: FUN_00467920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00467920(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 **ppuVar6;
  undefined1 local_11c [12];
  undefined1 *local_110 [3];
  int local_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined4 local_e4;
  code *local_d0;
  code *local_cc;
  undefined4 local_84;
  uint local_80;
  undefined1 local_48 [68];
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x28) + 0x18) + 4;
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0c8) {
    FUN_005b4500(local_48,&DAT_007f8d64);
    puVar2 = local_48;
  }
  else {
    puVar2 = (undefined1 *)FUN_005cfa20(iVar1);
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0xd10) != 0)) {
    FUN_0049f630(local_11c,puVar2 + 0x30,*(int *)(param_1 + 0xd10) + 0x80,&DAT_0093b0cc,param_3,
                 param_4);
    puVar5 = &DAT_00810210;
    ppuVar6 = local_110;
    for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {
      *ppuVar6 = (undefined1 *)*puVar5;
      puVar5 = puVar5 + 1;
      ppuVar6 = ppuVar6 + 1;
    }
    local_f8 = 0x3e19999a;
    local_fc = 0x3e19999a;
    local_f4 = param_4;
    local_84 = _DAT_00925018;
    local_110[2] = local_11c;
    local_80 = (uint)*(byte *)(param_1 + 0x28d);
    local_e4 = 0xc39b;
    local_104 = param_1;
    local_d0 = FUN_0042cf20;
    local_cc = FUN_0042d000;
    local_110[0] = puVar2;
    local_ec = iVar1;
    uVar3 = FUN_0064d270(local_110);
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
    FUN_00681f40("JForcePush",param_1 + 0x80);
    FUN_005a15e0(*(undefined4 *)(param_2 + 0x28),0);
    *(uint *)(param_2 + 0xa0) = *(uint *)(param_2 + 0xa0) | 0x10000;
    return uVar3;
  }
  return 0;
}

