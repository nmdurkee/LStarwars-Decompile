/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff380; label: FUN_004ff380
 */

bool FUN_004ff380(int param_1)

{
  BOOL BVar1;
  
  BVar1 = CloseHandle((HANDLE)(&DAT_008007a0)[param_1]);
  (&DAT_008007a0)[param_1] = 0xffffffff;
  return BVar1 == 0;
}

