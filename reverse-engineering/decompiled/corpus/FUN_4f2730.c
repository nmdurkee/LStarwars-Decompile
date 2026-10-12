/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f2730; label: _vsprintf
 */

int __cdecl _vsprintf(char *_Dest,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = __vsprintf_l(_Dest,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}

