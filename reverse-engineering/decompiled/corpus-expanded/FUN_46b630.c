/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46b630; label: FUN_0046b630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b630(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 *local_50 [4];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_2a;
  int local_28;
  code *local_14;
  code *local_8;
  undefined1 local_3;
  
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x62,param_1);
  uVar1 = FUN_00650dc0("MK-Pickup",param_1,3,0);
  FUN_005478a0(uVar1);
  if ((*(int *)(PTR_DAT_00802c54 + 0x120) == -1) ||
     ((&DAT_0086e0fa)[*(int *)(PTR_DAT_00802c54 + 0x120) * 0xc] == '\0')) {
    local_5c = _DAT_007fc324;
    local_58 = _DAT_007fc328;
    puVar3 = &DAT_00802cd8;
    ppuVar4 = local_50;
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = (undefined4 *)*puVar3;
      puVar3 = puVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    local_54 = 0x3f800000;
    local_2a = 0xd2;
    local_50[1] = (undefined4 *)param_1;
    local_50[3] = (undefined4 *)DAT_00950f60;
    local_28 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd20;
    local_40 = _DAT_007fc320;
    local_50[2] = &local_5c;
    local_34 = 0x3f800000;
    local_14 = FUN_0059a420;
    local_8 = FUN_0046b5c0;
    local_3 = 1;
    local_38 = 0x2112d;
    FUN_00560b60(local_50);
    _DAT_0087b944 = 0x40000000;
    if (*(int *)(PTR_DAT_00802c54 + 0x120) != -1) {
      DAT_0095122c = 1;
    }
  }
  return;
}

