/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5470; label: FUN_005e5470
 */

int FUN_005e5470(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_0096e570) {
    do {
      if (*(int *)(DAT_0097157c + iVar1 * 4) == 0) {
        *(undefined4 *)(DAT_0097157c + iVar1 * 4) = param_1;
        return iVar1 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0096e570);
  }
  return 0;
}

