/* Ghidra analysis pseudocode, not original source.
 * ev_70a853f58009e9efad9666889d27826b6f4536c979d6a0e9b36ce7b492b6680b
 * Entry: 0x5877c0; label: FUN_005877c0
 */

void FUN_005877c0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&PTR_PTR_0076362c);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 0;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"green");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 1;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00754f70);
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 2;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"purple");
    if (iVar1 == 0) {
      *(undefined1 *)(DAT_00954404 + 0x117) = 3;
    }
  }
  return;
}

