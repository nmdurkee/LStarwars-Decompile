/* Ghidra analysis pseudocode, not original source.
 * ev_8796502379899d0b28c9a8f4b97b0d36d854998b625fcb8bf104f142ac17f22c
 * Entry: 0x588890; label: FUN_00588890
 */

void FUN_00588890(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_005888bf;
  }
  iVar1 = 1;
LAB_005888bf:
  *(uint *)(DAT_00954404 + 0x94) =
       *(uint *)(DAT_00954404 + 0x94) ^
       (iVar1 << 0x1d ^ *(uint *)(DAT_00954404 + 0x94)) & 0x20000000;
  return;
}

