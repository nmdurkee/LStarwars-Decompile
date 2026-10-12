/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49d540; label: FUN_0049d540
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049d540(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined1 local_11c [12];
  undefined4 *local_110 [3];
  int local_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  code *local_d0;
  undefined4 local_84;
  uint local_80;
  undefined4 local_48 [17];
  
  if ((((*(char *)(param_1 + 0x7b5) == ']') &&
       (*(undefined1 *)(param_1 + 0x7b5) = 0xff,
       *(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf7e) != '\0')) &&
      (iVar1 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x108), iVar1 != -1)) &&
     (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar1 * 4) != 0)) {
    FUN_005b4500(local_48,iVar1 * 0x40 + 0x834 + param_1);
    local_128 = 0;
    local_124 = 0;
    local_120 = 0x3e4ccccd;
    FUN_005b3200(&local_128,&local_128,local_48);
    puVar3 = &DAT_00810210;
    ppuVar4 = local_110;
    for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar4 = (undefined4 *)*puVar3;
      puVar3 = puVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    local_110[2] = &local_128;
    local_110[0] = local_48;
    FUN_005d0260(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf70,local_11c,&local_fc);
    local_80 = (uint)*(byte *)(param_1 + 0x28d);
    local_f8 = local_fc;
    local_e8 = 0xf7;
    local_84 = _DAT_00925018;
    local_ec = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf70;
    local_f4 = 0x3f000000;
    local_e4 = 0x8000200;
    local_104 = param_1;
    local_d0 = FUN_0042cf20;
    iVar1 = FUN_0064d270(local_110);
    if (iVar1 != 0) {
      uVar2 = FUN_0058b720(param_1);
      *(uint *)(iVar1 + 0x218) = uVar2 & 0xffff;
    }
  }
  return;
}

