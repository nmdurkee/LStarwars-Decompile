/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4ff3b0; label: FUN_004ff3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

DWORD FUN_004ff3b0(int param_1,LPVOID param_2,DWORD param_3)

{
  DWORD local_4;
  
  local_4 = 0;
  ReadFile((HANDLE)(&DAT_008007a0)[param_1],param_2,param_3,&local_4,(LPOVERLAPPED)0x0);
  return local_4;
}

