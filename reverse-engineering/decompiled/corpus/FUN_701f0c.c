/* Ghidra analysis pseudocode, not original source.
 * ev_fd7ef47e89ee49e811b9d461fb0d02a426b46bfab1eb980b5176b797a15dd7e8
 * Entry: 0x701f0c; label: _wctomb
 */

/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 2005 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  size_t _SizeInBytes;
  errno_t eVar1;
  _locale_t _Locale;
  int local_8;
  
  local_8 = -1;
  _Locale = (_locale_t)0x0;
  _SizeInBytes = ____mb_cur_max_func();
  eVar1 = __wctomb_s_l(&local_8,_MbCh,_SizeInBytes,_WCh,_Locale);
  if (eVar1 == 0) {
    return local_8;
  }
  return -1;
}

