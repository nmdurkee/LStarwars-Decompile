/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6ea5d8; label: __vsnprintf
 */

/* Library Function - Single Match
    __vsnprintf
   
   Library: Visual Studio 2005 Release */

int __cdecl __vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = __vsnprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}

