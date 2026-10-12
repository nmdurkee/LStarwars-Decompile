/* Ghidra analysis pseudocode, not original source.
 * ev_4597a773e0370c09a0c234dc3483b3ea71e6a654f79adb326cefb52c3abac04d
 * Entry: 0x5890b0; label: FUN_005890b0
 */

void FUN_005890b0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_005890e3;
    }
  }
  iVar1 = 1;
LAB_005890e3:
  *(uint *)(DAT_00954404 + 0x94) =
       *(uint *)(DAT_00954404 + 0x94) ^ (iVar1 * 4 ^ *(uint *)(DAT_00954404 + 0x94)) & 4;
  return;
}

