/* Ghidra analysis pseudocode, not original source.
 * ev_70a853f58009e9efad9666889d27826b6f4536c979d6a0e9b36ce7b492b6680b
 * Entry: 0x5880c0; label: FUN_005880c0
 */

void FUN_005880c0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      iVar1 = 0;
      goto LAB_005880f3;
    }
  }
  iVar1 = 1;
LAB_005880f3:
  *(uint *)(DAT_00954404 + 0x98) =
       *(uint *)(DAT_00954404 + 0x98) ^ (iVar1 * 4 ^ *(uint *)(DAT_00954404 + 0x98)) & 4;
  return;
}

