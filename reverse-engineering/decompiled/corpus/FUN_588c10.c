/* Ghidra analysis pseudocode, not original source.
 * ev_8796502379899d0b28c9a8f4b97b0d36d854998b625fcb8bf104f142ac17f22c
 * Entry: 0x588c10; label: FUN_00588c10
 */

void FUN_00588c10(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) | 0x200000;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954400 + 4) = *(uint *)(DAT_00954400 + 4) & 0xffdfffff;
    }
  }
  return;
}

