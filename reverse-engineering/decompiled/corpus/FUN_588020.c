/* Ghidra analysis pseudocode, not original source.
 * ev_70a853f58009e9efad9666889d27826b6f4536c979d6a0e9b36ce7b492b6680b
 * Entry: 0x588020; label: FUN_00588020
 */

void FUN_00588020(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      uVar2 = 0;
      goto LAB_00588053;
    }
  }
  uVar2 = 1;
LAB_00588053:
  *(uint *)(DAT_00954404 + 0x98) =
       *(uint *)(DAT_00954404 + 0x98) ^ (*(uint *)(DAT_00954404 + 0x98) ^ uVar2) & 1;
  return;
}

