/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5d20; label: FUN_005e5d20
 */

void FUN_005e5d20(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 0x58) = uVar1;
  *(undefined2 *)(in_ECX + 0x88) = 0;
  *(undefined1 *)(in_ECX + 0x8a) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  return;
}

