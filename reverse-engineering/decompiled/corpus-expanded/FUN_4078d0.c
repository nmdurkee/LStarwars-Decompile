/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x4078d0; label: FUN_004078d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004078d0(int param_1,int *param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = *param_2;
  if (*(char *)(iVar2 + 0x7b5) == '[') {
    puVar1 = (uint *)(*(int *)(iVar2 + 0xca4) + 8);
    *puVar1 = *puVar1 | DAT_00802278;
  }
  uVar3 = *(uint *)(*(int *)(param_1 + 0x15c) + (uint)*(byte *)(param_1 + 0x160) * 4);
  if ((uVar3 != 0) && ((uVar3 & 0x40000000) == 0)) {
    uVar6 = *(uint *)(param_1 + 500) & uVar3;
    if (((uVar3 & 0x8000) != 0) &&
       (((((*(byte *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x90) & 0x40) == 0 &&
          (*(int *)(iVar2 + 0xea4) == 0)) && (*(char *)(iVar2 + 0x7b5) != '<')) &&
        ((uVar6 & 0xffff7fff) == 0)))) {
      FUN_0052c790(param_2[1],"TakeOverJump");
      return 1;
    }
    if ((uVar6 == 0) || ((uVar3 & 0x98000000) != 0)) {
      *(int *)(param_1 + 0x104) = param_2[0x17];
      *(int *)(param_1 + 0x108) = param_2[0x18];
      iVar2 = param_2[0x19];
      *(undefined4 *)(param_1 + 0x110) = 0;
      *(int *)(param_1 + 0x10c) = iVar2;
      *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
      return 1;
    }
    puVar1 = &DAT_007ef2c0;
    puVar4 = PTR_FUN_007ef2c4;
    while (puVar4 != (undefined *)0x0) {
      if ((*puVar1 & uVar6) != 0) {
        iVar5 = (*(code *)puVar1[1])(param_1,param_2,param_3);
        if (iVar5 != 0) {
          return 1;
        }
        break;
      }
      puVar4 = (undefined *)puVar1[3];
      puVar1 = puVar1 + 2;
    }
  }
  if ((((*(uint *)(param_1 + 0x1e8) & 0x20000000) != 0) && ((*(byte *)(iVar2 + 0x7c5) & 2) == 0)) &&
     (0.0 < _DAT_00876ce4)) {
    if ((*(uint *)(*(int *)(param_1 + 0x15c) + (uint)*(byte *)(param_1 + 0x160) * 4) & 0xd8000000)
        == 0) {
      FUN_0043c9a0(iVar2,(uint)*(byte *)((*(byte *)(param_1 + 0x160) == 0) + 0x10 +
                                        *(int *)(param_1 + 0x15c)) * 0x5c +
                         *(int *)(*(int *)(param_1 + 0x158) + 0x7c),0);
    }
  }
  return 0;
}

