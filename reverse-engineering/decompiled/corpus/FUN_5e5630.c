/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5630; label: FUN_005e5630
 */

void FUN_005e5630(int param_1)

{
  int iVar1;
  
  if (0 < param_1) {
    iVar1 = *(int *)(DAT_0097157c + -4 + param_1 * 4);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) < 1)) {
      FUN_005f8ed0(iVar1);
      *(undefined4 *)(DAT_0097157c + -4 + param_1 * 4) = 0;
      return;
    }
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
    }
  }
  return;
}

