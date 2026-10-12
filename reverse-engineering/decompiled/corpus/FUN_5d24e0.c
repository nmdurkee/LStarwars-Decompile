/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d24e0; label: FUN_005d24e0
 */

void FUN_005d24e0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  FUN_004f7fb0(param_1);
  uVar2 = FUN_005d1e10(*(undefined4 *)(param_1 + 0x510));
  iVar1 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x1ba + *(short *)(DAT_00971580 + 0x1b4) * 2) = 10;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  *(undefined2 *)(iVar1 + 0x1ba + *(short *)(iVar1 + 0x1b4) * 2) = uVar2;
  *(short *)(iVar1 + 0x1b4) = *(short *)(iVar1 + 0x1b4) + 1;
  return;
}

