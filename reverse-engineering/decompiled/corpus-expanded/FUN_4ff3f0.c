/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff3f0; label: FUN_004ff3f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004ff3f0(int param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_4;
  
  local_4 = 0;
  BVar1 = WriteFile((HANDLE)(&DAT_008007a0)[param_1],param_2,param_3,&local_4,(LPOVERLAPPED)0x0);
  return -(uint)(BVar1 != 0) & local_4;
}

