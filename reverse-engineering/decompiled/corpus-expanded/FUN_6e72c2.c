/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e72c2; label: ___tmainCRTStartup
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___tmainCRTStartup
   
   Library: Visual Studio 2005 Release */

int ___tmainCRTStartup(void)

{
  HANDLE pvVar1;
  LPOSVERSIONINFOA lpVersionInformation;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  DWORD DVar6;
  SIZE_T dwBytes;
  _STARTUPINFOA local_74;
  DWORD local_2c;
  DWORD local_28;
  DWORD local_24;
  int local_20;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x6e72ce;
  local_8 = 0;
  GetStartupInfoA(&local_74);
  local_8 = 0xfffffffe;
  dwBytes = 0x94;
  DVar6 = 0;
  pvVar1 = GetProcessHeap();
  lpVersionInformation = HeapAlloc(pvVar1,DVar6,dwBytes);
  if (lpVersionInformation == (LPOSVERSIONINFOA)0x0) {
    fast_error_exit(0x12);
  }
  else {
    lpVersionInformation->dwOSVersionInfoSize = 0x94;
    BVar2 = GetVersionExA(lpVersionInformation);
    DVar6 = 0;
    if (BVar2 != 0) {
      local_24 = lpVersionInformation->dwPlatformId;
      local_28 = lpVersionInformation->dwMajorVersion;
      local_2c = lpVersionInformation->dwMinorVersion;
      uVar5 = lpVersionInformation->dwBuildNumber & 0x7fff;
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,DVar6,lpVersionInformation);
      if (local_24 != 2) {
        uVar5 = uVar5 | 0x8000;
      }
      _DAT_0297c1bc = local_28 * 0x100 + local_2c;
      DAT_0297c1b4 = local_24;
      DAT_0297c1c0 = local_28;
      _DAT_0297c1c4 = local_2c;
      _DAT_0297c1b8 = uVar5;
      local_24 = check_managed_app();
      iVar3 = __heap_init();
      if (iVar3 == 0) {
        fast_error_exit(0x1c);
      }
      iVar3 = __mtinit();
      if (iVar3 == 0) {
        fast_error_exit(0x10);
      }
      __RTC_Initialize();
      local_8 = 1;
      iVar3 = __ioinit();
      if (iVar3 < 0) {
        __amsg_exit(0x1b);
      }
      DAT_029aac84 = GetCommandLineA();
      DAT_0297c188 = ___crtGetEnvironmentStringsA();
      iVar3 = __setargv();
      if (iVar3 < 0) {
        __amsg_exit(8);
      }
      iVar3 = __setenvp();
      if (iVar3 < 0) {
        __amsg_exit(9);
      }
      iVar3 = __cinit(1);
      if (iVar3 != 0) {
        __amsg_exit(iVar3);
      }
      uVar4 = __wincmdln();
      if (((byte)local_74.dwFlags & 1) == 0) {
        local_74.wShowWindow = 10;
      }
      local_20 = FUN_006de0e0(0x400000,0,uVar4,local_74.wShowWindow);
      if (local_24 != 0) {
        __cexit();
        return local_20;
      }
                    /* WARNING: Subroutine does not return */
      _exit(local_20);
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,DVar6,lpVersionInformation);
  }
  return 0xff;
}

