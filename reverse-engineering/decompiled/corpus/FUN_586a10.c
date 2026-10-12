/* Ghidra analysis pseudocode, not original source.
 * ev_10a52eb163d37e971edce79c1fc8a96922bb2f4e033d0de10a3e0adcd5f651d2
 * Entry: 0x586a10; label: FUN_00586a10
 */

void FUN_00586a10(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(DAT_00954404 + 0x118);
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (-1 < iVar1) {
      *puVar2 = (char)iVar1;
    }
  }
  return;
}

