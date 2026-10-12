/* Ghidra analysis pseudocode, not original source.
 * ev_fd7ef47e89ee49e811b9d461fb0d02a426b46bfab1eb980b5176b797a15dd7e8
 * Entry: 0x701c97; label: FUN_00701c97
 */

void FUN_00701c97(void)

{
  int unaff_EBP;
  
  __unlock_fhandle(*(int *)(unaff_EBP + 8));
  return;
}

