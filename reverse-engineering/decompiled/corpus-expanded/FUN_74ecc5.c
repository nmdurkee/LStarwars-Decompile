/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74ecc5; label: __vsnwprintf_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __vsnwprintf_l
   
   Library: Visual Studio 2005 Release */

int __cdecl
__vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,wchar_t *_Format,_locale_t _Locale,va_list _ArgList
              )

{
  undefined4 *puVar1;
  int iVar2;
  FILE local_24;
  
  if (_Format == (wchar_t *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar2 = -1;
  }
  else if ((_MaxCount == 0) || (_DstBuf != (wchar_t *)0x0)) {
    local_24._flag = 0x42;
    local_24._base = (char *)_DstBuf;
    local_24._ptr = (char *)_DstBuf;
    if (_MaxCount < 0x40000000) {
      local_24._cnt = _MaxCount * 2;
    }
    else {
      local_24._cnt = 0x7fffffff;
    }
    iVar2 = FUN_0074ee50(&local_24,_Format,_Locale,_ArgList);
    if (_DstBuf != (wchar_t *)0x0) {
      local_24._cnt = local_24._cnt + -1;
      if (local_24._cnt < 0) {
        __flsbuf(0,&local_24);
      }
      else {
        *local_24._ptr = 0;
        local_24._ptr = (char *)((int)local_24._ptr + 1);
      }
      local_24._cnt = local_24._cnt + -1;
      if (local_24._cnt < 0) {
        __flsbuf(0,&local_24);
      }
      else {
        *local_24._ptr = 0;
      }
    }
  }
  else {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    iVar2 = -1;
  }
  return iVar2;
}

