/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48a3f0; label: FUN_0048a3f0
 */

void FUN_0048a3f0(void)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = 0;
  if (0 < *(int *)(unaff_EDI + 0x2aec)) {
    do {
      FUN_0048a250();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(unaff_EDI + 0x2aec));
  }
  return;
}

