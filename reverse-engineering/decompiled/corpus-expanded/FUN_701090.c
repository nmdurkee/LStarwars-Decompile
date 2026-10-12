/* Ghidra pseudocode, not original source.
 * ev_7661b65940d612abb24c352a2878817c29de5a09135c60a7ac694e4ecef30f99
 * Entry: 0x701090; label: __ispunct_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __ispunct_l
   
   Library: Visual Studio 2005 Release */

int __cdecl __ispunct_l(int _C,_locale_t _Locale)

{
  uint uVar1;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,_Locale);
  if ((int)(local_14.locinfo)->locale_name[3] < 2) {
    uVar1 = (byte)local_14.locinfo[1].lc_category[0].locale[_C * 2] & 0x10;
  }
  else {
    uVar1 = __isctype_l(_C,0x10,&local_14);
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return uVar1;
}

