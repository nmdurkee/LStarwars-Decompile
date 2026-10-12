/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f05ba; label: __mtinit
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 2005 Release */

int __cdecl __mtinit(void)

{
  HMODULE hModule;
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  DWORD *pDVar4;
  DWORD DVar5;
  
  hModule = GetModuleHandleA("KERNEL32.DLL");
  if (hModule == (HMODULE)0x0) {
    __mtterm();
    return 0;
  }
  DAT_0297c538 = GetProcAddress(hModule,"FlsAlloc");
  DAT_0297c53c = GetProcAddress(hModule,"FlsGetValue");
  DAT_0297c540 = GetProcAddress(hModule,"FlsSetValue");
  DAT_0297c544 = GetProcAddress(hModule,"FlsFree");
  if ((((DAT_0297c538 == (FARPROC)0x0) || (DAT_0297c53c == (FARPROC)0x0)) ||
      (DAT_0297c540 == (FARPROC)0x0)) || (DAT_0297c544 == (FARPROC)0x0)) {
    DAT_0297c53c = TlsGetValue_exref;
    DAT_0297c538 = (FARPROC)&LAB_006f022a;
    DAT_0297c540 = TlsSetValue_exref;
    DAT_0297c544 = TlsFree_exref;
  }
  DAT_00829ab8 = TlsAlloc();
  if ((DAT_00829ab8 != 0xffffffff) && (BVar1 = TlsSetValue(DAT_00829ab8,DAT_0297c53c), BVar1 != 0))
  {
    __init_pointers();
    DAT_0297c538 = (FARPROC)FUN_006f0145(DAT_0297c538);
    DAT_0297c53c = (FARPROC)FUN_006f0145(DAT_0297c53c);
    DAT_0297c540 = (FARPROC)FUN_006f0145(DAT_0297c540);
    DAT_0297c544 = (FARPROC)FUN_006f0145(DAT_0297c544);
    iVar2 = __mtinitlocks();
    if (iVar2 != 0) {
      pcVar3 = (code *)FUN_006f01bc(DAT_0297c538,&LAB_006f0424);
      DAT_00829ab4 = (*pcVar3)();
      if ((DAT_00829ab4 != -1) && (pDVar4 = __calloc_crt(1,0x214), pDVar4 != (DWORD *)0x0)) {
        pcVar3 = (code *)FUN_006f01bc(DAT_0297c540,DAT_00829ab4,pDVar4);
        iVar2 = (*pcVar3)();
        if (iVar2 != 0) {
          FUN_006f02d6(pDVar4,0);
          DVar5 = GetCurrentThreadId();
          pDVar4[1] = 0xffffffff;
          *pDVar4 = DVar5;
          return 1;
        }
      }
    }
    __mtterm();
  }
  return 0;
}

