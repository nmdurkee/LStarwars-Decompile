/* Ghidra analysis pseudocode, not original source.
 * ev_10a52eb163d37e971edce79c1fc8a96922bb2f4e033d0de10a3e0adcd5f651d2
 * Entry: 0x587040; label: FUN_00587040
 */

void FUN_00587040(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) | 4;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) & 0xfffffffb;
    }
  }
  return;
}

