/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c5c4; label: _LanguageEnumProc@4
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _LanguageEnumProc@4
   
   Library: Visual Studio 2005 Release */

void _LanguageEnumProc_4(void)

{
  int *piVar1;
  _ptiddata p_Var2;
  LCID Locale;
  int iVar3;
  undefined4 uVar4;
  CHAR local_80 [120];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  p_Var2 = __getptd();
  Locale = _LcidFromHexString();
  iVar3 = GetLocaleInfoA(Locale,(-(uint)((p_Var2->_setloc_data).bAbbrevLanguage != 0) & 0xfffff002)
                                + 0x1001,local_80,0x78);
  if (iVar3 == 0) {
    (p_Var2->_setloc_data).iLocState = 0;
    goto LAB_0070c673;
  }
  iVar3 = __stricmp((char *)(p_Var2->_setloc_data).pchLanguage,local_80);
  if (iVar3 == 0) {
    if ((p_Var2->_setloc_data).bAbbrevLanguage == 0) {
      uVar4 = 1;
      goto LAB_0070c650;
    }
  }
  else {
    if ((((p_Var2->_setloc_data).bAbbrevLanguage != 0) || ((p_Var2->_setloc_data).iPrimaryLen == 0))
       || (iVar3 = __stricmp((char *)(p_Var2->_setloc_data).pchLanguage,local_80), iVar3 != 0))
    goto LAB_0070c673;
    uVar4 = 0;
LAB_0070c650:
    iVar3 = _TestDefaultLanguage(Locale,uVar4);
    if (iVar3 == 0) goto LAB_0070c673;
  }
  piVar1 = &(p_Var2->_setloc_data).iLocState;
  *piVar1 = *piVar1 | 4;
  (p_Var2->_setloc_data)._cachecp = Locale;
  *(LCID *)(p_Var2->_setloc_data)._cachein = Locale;
LAB_0070c673:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

