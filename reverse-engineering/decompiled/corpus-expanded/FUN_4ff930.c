/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff930; label: FUN_004ff930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

