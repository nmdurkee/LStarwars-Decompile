/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x4238d0; label: FUN_004238d0
 */

int FUN_004238d0(void)

{
  int iVar1;
  char in_CL;
  
  iVar1 = 0;
  do {
    if (s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar1] == in_CL) {
LAB_004238f0:
      if (0x25 < iVar1) {
        iVar1 = 0;
      }
      return iVar1;
    }
    if (s_ABCDEFGHIJKLMNOPQRSTUVWXYZ__0123_007f37ec[iVar1 + 1] == in_CL) {
      iVar1 = iVar1 + 1;
      goto LAB_004238f0;
    }
    iVar1 = iVar1 + 2;
    if (0x25 < iVar1) {
      return 0;
    }
  } while( true );
}

