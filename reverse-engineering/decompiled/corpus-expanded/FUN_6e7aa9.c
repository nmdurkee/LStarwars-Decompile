/* Ghidra pseudocode, not original source.
 * ev_b64bd83017f0ebae738352c8f5b7965ab01e6ce8652f7cf557bf7c06ee96df94
 * Entry: 0x6e7aa9; label: __vsprintf_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __vsprintf_l
   
   Library: Visual Studio 2005 Release */

int __cdecl __vsprintf_l(char *_DstBuf,char *_Format,_locale_t param_3,va_list _ArgList)

{
  undefined4 *puVar1;
  int iVar2;
  FILE local_24;
  
  if ((_Format == (char *)0x0) || (_DstBuf == (char *)0x0)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    local_24._base = _DstBuf;
    local_24._ptr = _DstBuf;
    local_24._cnt = 0x7fffffff;
    local_24._flag = 0x42;
    iVar2 = FUN_006eef05(&local_24,_Format,param_3,_ArgList);
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar2;
}

