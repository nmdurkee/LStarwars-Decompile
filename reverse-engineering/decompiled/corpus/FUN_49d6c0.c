/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49d6c0; label: thunk_FUN_0049d540
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0049d540(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined1 auStack_11c [12];
  undefined4 *apuStack_110 [3];
  int iStack_104;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  int iStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  code *pcStack_d0;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 auStack_48 [17];
  
  if ((((*(char *)(param_1 + 0x7b5) == ']') &&
       (*(undefined1 *)(param_1 + 0x7b5) = 0xff,
       *(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf7e) != '\0')) &&
      (iVar1 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x108), iVar1 != -1)) &&
     (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar1 * 4) != 0)) {
    FUN_005b4500(auStack_48,iVar1 * 0x40 + 0x834 + param_1);
    uStack_128 = 0;
    uStack_124 = 0;
    uStack_120 = 0x3e4ccccd;
    FUN_005b3200(&uStack_128,&uStack_128,auStack_48);
    puVar3 = &DAT_00810210;
    ppuVar4 = apuStack_110;
    for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppuVar4 = (undefined4 *)*puVar3;
      puVar3 = puVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    apuStack_110[2] = &uStack_128;
    apuStack_110[0] = auStack_48;
    FUN_005d0260(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf70,auStack_11c,&uStack_fc);
    uStack_80 = (uint)*(byte *)(param_1 + 0x28d);
    uStack_f8 = uStack_fc;
    uStack_e8 = 0xf7;
    uStack_84 = _DAT_00925018;
    iStack_ec = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xf70;
    uStack_f4 = 0x3f000000;
    uStack_e4 = 0x8000200;
    iStack_104 = param_1;
    pcStack_d0 = FUN_0042cf20;
    iVar1 = FUN_0064d270(apuStack_110);
    if (iVar1 != 0) {
      uVar2 = FUN_0058b720(param_1);
      *(uint *)(iVar1 + 0x218) = uVar2 & 0xffff;
    }
  }
  return;
}

