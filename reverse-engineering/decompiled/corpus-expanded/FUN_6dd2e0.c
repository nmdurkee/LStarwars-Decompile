/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd2e0; label: FUN_006dd2e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dd2e0(void)

{
  int iVar1;
  DWORD DVar2;
  CHAR local_108 [260];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_108;
  iVar1 = GetSystemMetrics(0x57);
  if ((iVar1 != 0) && (DAT_02975c3c != 0)) {
    DVar2 = ExpandEnvironmentStringsA("%SystemRoot%\\ehome\\ehshell.exe",local_108,0x104);
    if (DVar2 != 0) {
      DVar2 = GetFileAttributesA(local_108);
      if (DVar2 != 0xffffffff) {
        ShellExecuteA((HWND)0x0,"open",local_108,(LPCSTR)0x0,(LPCSTR)0x0,1);
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_108);
  return;
}

