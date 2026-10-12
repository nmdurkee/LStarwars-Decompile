/* Ghidra analysis pseudocode, not original source.
 * ev_3de2cf7b8df928d729538760151df11dfb76bb55f80af3b4d4d063063f9aa6a2
 * Entry: 0x57aff0; label: FUN_0057aff0
 */

void FUN_0057aff0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00548a60(*(undefined4 *)(param_1 + 0x510),DAT_009248cc,0xffffffff);
    *(undefined2 *)(DAT_00951c4c + 0xea) = uVar1;
    uVar3 = FUN_00694320(0x10,*(undefined4 *)(param_1 + 0x510));
    *(undefined4 *)(DAT_00951c4c + 0x18c) = uVar3;
  }
  return;
}

