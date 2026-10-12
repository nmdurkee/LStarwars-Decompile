/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70c2ec; label: _CountryEnumProc@4
 */

/* Library Function - Single Match
    _CountryEnumProc@4
   
   Library: Visual Studio 2005 Release */

void _CountryEnumProc_4(void)

{
  int *piVar1;
  _ptiddata p_Var2;
  LCID Locale;
  int iVar3;
  CHAR local_80 [120];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  p_Var2 = __getptd();
  Locale = _LcidFromHexString();
  iVar3 = GetLocaleInfoA(Locale,(-(uint)((p_Var2->_setloc_data).bAbbrevCountry != 0) & 0xfffff005) +
                                0x1002,local_80,0x78);
  if (iVar3 == 0) {
    (p_Var2->_setloc_data).iLocState = 0;
  }
  else {
    iVar3 = __stricmp((char *)(p_Var2->_setloc_data).pchCountry,local_80);
    if ((iVar3 == 0) && (iVar3 = _TestDefaultCountry(Locale), iVar3 != 0)) {
      piVar1 = &(p_Var2->_setloc_data).iLocState;
      *piVar1 = *piVar1 | 4;
      *(LCID *)(p_Var2->_setloc_data)._cachein = Locale;
      (p_Var2->_setloc_data)._cachecp = Locale;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

