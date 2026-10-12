/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff930; label: FUN_004ff930
 */

void FUN_004ff930(LPCSTR param_1)

{
  _SECURITY_ATTRIBUTES local_c;
  
  local_c.bInheritHandle = 1;
  local_c.nLength = 0xc;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  CreateDirectoryA(param_1,&local_c);
  return;
}

