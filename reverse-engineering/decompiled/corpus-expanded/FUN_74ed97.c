/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74ed97; label: __vsnwprintf
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

