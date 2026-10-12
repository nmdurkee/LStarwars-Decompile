/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x475350; label: FUN_00475350
 */

int FUN_00475350(void)

{
  int iVar1;
  undefined4 *in_EDX;
  
  iVar1 = *(int *)(&PTR_DAT_007fa100)[DAT_007fa188];
  if ((iVar1 == 0) || ((&DAT_0086e0f4)[(uint)*(byte *)(iVar1 + 0x7c) * 0xc] == '\0')) {
    if (in_EDX != (undefined4 *)0x0) {
      *in_EDX = 1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

