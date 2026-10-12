/* Ghidra analysis pseudocode, not original source.
 * ev_10a52eb163d37e971edce79c1fc8a96922bb2f4e033d0de10a3e0adcd5f651d2
 * Entry: 0x586c80; label: FUN_00586c80
 */

void FUN_00586c80(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(DAT_00954404 + 0xe8);
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    *puVar3 = uVar1;
  }
  return;
}

