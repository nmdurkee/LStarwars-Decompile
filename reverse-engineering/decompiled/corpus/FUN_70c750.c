/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x70c750; label: ___get_qualified_locale
 */

/* Library Function - Single Match
    ___get_qualified_locale
   
   Library: Visual Studio 2005 Release */

BOOL __cdecl ___get_qualified_locale(LPLC_STRINGS _LpInStr,UINT *_LpCodePage,LPLC_STRINGS _LpOutStr)

{
  int *piVar1;
  wchar_t **ppwVar2;
  wchar_t *pwVar3;
  _ptiddata p_Var4;
  size_t sVar5;
  LCID LVar6;
  uint _Value;
  BOOL BVar7;
  errno_t eVar8;
  int iVar9;
  _setloc_struct *p_Var10;
  
  p_Var4 = __getptd();
  p_Var10 = &p_Var4->_setloc_data;
  if (_LpInStr == (LPLC_STRINGS)0x0) {
    piVar1 = &(p_Var4->_setloc_data).iLocState;
    *piVar1 = *piVar1 | 0x104;
LAB_0070c828:
    LVar6 = GetUserDefaultLCID();
    (p_Var4->_setloc_data)._cachecp = LVar6;
    *(LCID *)(p_Var4->_setloc_data)._cachein = LVar6;
  }
  else {
    pwVar3 = _LpInStr->szLanguage + 0x20;
    ppwVar2 = &(p_Var4->_setloc_data).pchCountry;
    p_Var10->pchLanguage = _LpInStr->szLanguage;
    *ppwVar2 = pwVar3;
    if ((pwVar3 != (wchar_t *)0x0) && ((char)*pwVar3 != '\0')) {
      _TranslateName(&PTR_s_america_00782270,0x16,ppwVar2);
    }
    (p_Var4->_setloc_data).iLocState = 0;
    if ((p_Var10->pchLanguage == (wchar_t *)0x0) || ((char)*p_Var10->pchLanguage == '\0')) {
      pwVar3 = *ppwVar2;
      if ((pwVar3 == (wchar_t *)0x0) || ((char)*pwVar3 == '\0')) {
        (p_Var4->_setloc_data).iLocState = 0x104;
        goto LAB_0070c828;
      }
      sVar5 = _strlen((char *)pwVar3);
      (p_Var4->_setloc_data).bAbbrevCountry = (uint)(sVar5 == 3);
      EnumSystemLocalesA(_CountryEnumProc_4,1);
      if (((p_Var4->_setloc_data).iLocState & 4) == 0) {
        (p_Var4->_setloc_data).iLocState = 0;
      }
    }
    else {
      if ((*ppwVar2 == (wchar_t *)0x0) || ((char)**ppwVar2 == '\0')) {
        _GetLcidFromLanguage();
      }
      else {
        _GetLcidFromLangCountry();
      }
      if ((p_Var4->_setloc_data).iLocState != 0) goto LAB_0070c83d;
      iVar9 = _TranslateName(&PTR_s_american_00782068,0x40,p_Var10);
      if (iVar9 != 0) {
        if ((*ppwVar2 == (wchar_t *)0x0) || ((char)**ppwVar2 == '\0')) {
          _GetLcidFromLanguage();
        }
        else {
          _GetLcidFromLangCountry();
        }
      }
    }
  }
  if ((p_Var4->_setloc_data).iLocState == 0) {
    return 0;
  }
LAB_0070c83d:
  _Value = _ProcessCodePage();
  if ((((_Value == 0) || (_Value == 65000)) || (_Value == 0xfde9)) ||
     ((BVar7 = IsValidCodePage(_Value & 0xffff), BVar7 == 0 ||
      (BVar7 = IsValidLocale((p_Var4->_setloc_data)._cachecp,1), BVar7 == 0)))) {
    return 0;
  }
  if (_LpCodePage != (UINT *)0x0) {
    *(short *)_LpCodePage = (short)(p_Var4->_setloc_data)._cachecp;
    *(wchar_t *)((int)_LpCodePage + 2) = (p_Var4->_setloc_data)._cachein[0];
    *(short *)(_LpCodePage + 1) = (short)_Value;
  }
  if (_LpOutStr != (LPLC_STRINGS)0x0) {
    if ((short)*_LpCodePage == 0x814) {
      eVar8 = _strcpy_s((char *)_LpOutStr,0x40,"Norwegian-Nynorsk");
      if (eVar8 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
    }
    else {
      iVar9 = GetLocaleInfoA((p_Var4->_setloc_data)._cachecp,0x1001,(LPSTR)_LpOutStr,0x40);
      if (iVar9 == 0) {
        return 0;
      }
    }
    iVar9 = GetLocaleInfoA(*(LCID *)(p_Var4->_setloc_data)._cachein,0x1002,
                           (LPSTR)(_LpOutStr->szLanguage + 0x20),0x40);
    if (iVar9 == 0) {
      return 0;
    }
    __itoa_s(_Value,(char *)_LpOutStr->szCountry,0x10,10);
  }
  return 1;
}

