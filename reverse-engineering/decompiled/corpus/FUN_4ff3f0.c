/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff3f0; label: FUN_004ff3f0
 */

uint FUN_004ff3f0(int param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_4;
  
  local_4 = 0;
  BVar1 = WriteFile((HANDLE)(&DAT_008007a0)[param_1],param_2,param_3,&local_4,(LPOVERLAPPED)0x0);
  return -(uint)(BVar1 != 0) & local_4;
}

