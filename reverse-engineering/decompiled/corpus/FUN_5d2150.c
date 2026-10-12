/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d2150; label: FUN_005d2150
 */

void FUN_005d2150(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  
  FUN_004f9e70(param_1);
  FUN_004f9e70(param_1);
  iVar2 = DAT_00971580;
  *(undefined2 *)(DAT_00971580 + 0x1ba + *(short *)(DAT_00971580 + 0x1b4) * 2) = 4;
  *(short *)(iVar2 + 0x1b4) = *(short *)(iVar2 + 0x1b4) + 1;
  sVar1 = *(short *)(iVar2 + 0x1b4);
  uVar3 = FUN_006e6b90();
  *(undefined2 *)(iVar2 + 0x1ba + sVar1 * 2) = uVar3;
  *(short *)(iVar2 + 0x1b4) = *(short *)(iVar2 + 0x1b4) + 1;
  sVar1 = *(short *)(iVar2 + 0x1b4);
  uVar3 = FUN_006e6b90();
  *(undefined2 *)(iVar2 + 0x1ba + sVar1 * 2) = uVar3;
  *(short *)(iVar2 + 0x1b4) = *(short *)(iVar2 + 0x1b4) + 1;
  return;
}

