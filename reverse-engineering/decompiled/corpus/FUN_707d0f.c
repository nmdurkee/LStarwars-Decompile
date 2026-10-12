/* Ghidra analysis pseudocode, not original source.
 * ev_67f98f38a95887d623f2b825230000473143cb3f5ba4a0d09463374d55adf1d2
 * Entry: 0x707d0f; label: ___crtGetLocaleInfoW
 */

/* Library Function - Single Match
    ___crtGetLocaleInfoW
   
   Library: Visual Studio 2005 Release */

void ___crtGetLocaleInfoW
               (localeinfo_struct *param_1,ulong param_2,ulong param_3,wchar_t *param_4,int param_5,
               int param_6)

{
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,param_1);
  __crtGetLocaleInfoW_stat(&local_14,param_2,param_3,param_4,param_5,param_6);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}

