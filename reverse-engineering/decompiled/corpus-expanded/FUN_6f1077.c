/* Ghidra pseudocode, not original source.
 * ev_97f9900fcd0ba7492838edfd98b0150dba956191b40272664bd26bb1f92bea67
 * Entry: 0x6f1077; label: __setargv
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 2005 Release */

int __cdecl __setargv(void)

{
  uint _Size;
  void *pvVar1;
  int iVar2;
  uint local_10;
  uint local_c;
  char *local_8;
  
  if (DAT_029a9c58 == 0) {
    ___initmbctable();
  }
  DAT_0297c96c = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_0297c868,0x104);
  _DAT_0297c1e4 = &DAT_0297c868;
  if ((DAT_029aac84 == (char *)0x0) || (local_8 = DAT_029aac84, *DAT_029aac84 == '\0')) {
    local_8 = &DAT_0297c868;
  }
  parse_cmdline(0,0,&local_c);
  if ((local_c < 0x3fffffff) && (local_10 != 0xffffffff)) {
    iVar2 = local_c * 4;
    _Size = iVar2 + local_10;
    if ((local_10 <= _Size) && (pvVar1 = __malloc_crt(_Size), pvVar1 != (void *)0x0)) {
      parse_cmdline(pvVar1,(void *)(iVar2 + (int)pvVar1),&local_c);
      _DAT_0297c1c8 = local_c - 1;
      _DAT_0297c1cc = pvVar1;
      return 0;
    }
  }
  return -1;
}

