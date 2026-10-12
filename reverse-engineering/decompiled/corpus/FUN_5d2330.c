/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d2330; label: FUN_005d2330
 */

void FUN_005d2330(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_004f7fb0(param_1);
  uVar2 = FUN_005d1ea0(*(undefined4 *)(param_1 + 0x510));
  iVar1 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x130 + *(int *)(DAT_00971580 + 0x1b0) * 2) = uVar2;
  *(undefined2 *)(iVar1 + 0x170 + *(int *)(iVar1 + 0x1b0) * 2) = *(undefined2 *)(iVar1 + 0x1b4);
  *(int *)(iVar1 + 0x1b0) = *(int *)(iVar1 + 0x1b0) + 1;
  return;
}

