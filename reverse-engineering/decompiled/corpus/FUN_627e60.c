/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627e60; label: FUN_00627e60
 */

void FUN_00627e60(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00627da0(param_1,param_2,&LAB_00627cf0);
  if (iVar1 != 0) {
    FUN_004f1f10(iVar1 + 0x4c,param_2 + 0x4c);
    uVar2 = FUN_004f1ff0(iVar1 + 0x4c);
    *(undefined4 *)(iVar1 + 0x154) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    *(undefined2 *)(iVar1 + 0x15a) = *(undefined2 *)(param_2 + 0x15a);
    *(uint *)(iVar1 + 0x164) =
         *(uint *)(iVar1 + 0x164) ^ (*(uint *)(param_2 + 0x164) ^ *(uint *)(iVar1 + 0x164)) & 2;
  }
  return;
}

