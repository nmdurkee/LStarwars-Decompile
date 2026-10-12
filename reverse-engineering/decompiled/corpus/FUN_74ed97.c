/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74ed97; label: __vsnwprintf
 */

/* Library Function - Single Match
    __vsnwprintf
   
   Library: Visual Studio 2005 Release */

int __cdecl __vsnwprintf(wchar_t *_Dest,size_t _Count,wchar_t *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = __vsnwprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}

