/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f4d59; label: ___getlocaleinfo
 */

/* Library Function - Single Match
    ___getlocaleinfo
   
   Library: Visual Studio 2005 Release */

int __cdecl
___getlocaleinfo(_locale_t _Locale,int _Lc_type,LPCWSTR _LocaleName,LCTYPE _FieldType,void *_Address
                )

{
  byte bVar1;
  bool bVar2;
  size_t sVar3;
  DWORD DVar4;
  LPSTR _LpLCData;
  char *_Dst;
  int iVar5;
  errno_t eVar6;
  byte *pbVar7;
  CHAR local_88 [32];
  undefined1 local_68 [96];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)local_68;
  if (_Lc_type != 1) {
    if (_Lc_type == 0) {
      pbVar7 = &DAT_0297cae4;
      iVar5 = ___crtGetLocaleInfoW(_Locale,_LocaleName,_FieldType,&DAT_0297cae4,4,0);
      if (iVar5 != 0) {
        *(undefined1 *)_Address = 0;
        do {
          bVar1 = *pbVar7;
          iVar5 = _isdigit((uint)bVar1);
          if (iVar5 == 0) break;
          pbVar7 = pbVar7 + 2;
          *(byte *)_Address = *(char *)_Address * '\n' + bVar1 + -0x30;
        } while ((int)pbVar7 < 0x297caec);
      }
    }
    goto LAB_006f4e26;
  }
  _LpLCData = local_88;
  bVar2 = false;
  sVar3 = ___crtGetLocaleInfoA(_Locale,_LocaleName,_FieldType,_LpLCData,0x80);
  if (sVar3 == 0) {
    DVar4 = GetLastError();
    if (((DVar4 != 0x7a) ||
        (sVar3 = ___crtGetLocaleInfoA(_Locale,_LocaleName,_FieldType,(LPSTR)0x0,0), sVar3 == 0)) ||
       (_LpLCData = __calloc_crt(sVar3,1), _LpLCData == (LPSTR)0x0)) goto LAB_006f4e26;
    bVar2 = true;
    sVar3 = ___crtGetLocaleInfoA(_Locale,_LocaleName,_FieldType,_LpLCData,sVar3);
    if (sVar3 != 0) goto LAB_006f4e04;
  }
  else {
LAB_006f4e04:
    _Dst = __calloc_crt(sVar3,1);
    *(char **)_Address = _Dst;
    if (_Dst != (char *)0x0) {
      eVar6 = _strncpy_s(_Dst,sVar3,_LpLCData,sVar3 - 1);
      if (eVar6 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      if (bVar2) {
        _free(_LpLCData);
      }
      goto LAB_006f4e26;
    }
    if (!bVar2) goto LAB_006f4e26;
  }
  _free(_LpLCData);
LAB_006f4e26:
  iVar5 = __security_check_cookie(local_8 ^ (uint)local_68);
  return iVar5;
}

