/* Ghidra pseudocode, not original source.
 * ev_7661b65940d612abb24c352a2878817c29de5a09135c60a7ac694e4ecef30f99
 * Entry: 0x701f0c; label: _wctomb
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

