/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x7133f1; label: FUN_007133f1
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_007133f1(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  errno_t eVar5;
  UINT CodePage;
  char *_Str1;
  size_t sVar6;
  DWORD DVar7;
  int *piVar8;
  long lVar9;
  char *pcVar10;
  int local_34;
  int local_30;
  long local_2c;
  int local_28;
  int *local_24;
  int local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007ed9a8;
  uStack_c = 0x7133fd;
  local_30 = 0;
  local_20[0] = 0;
  local_28 = 0;
  local_2c = 0;
  local_24 = (int *)0x0;
  __lock(7);
  local_8 = (undefined *)0x0;
  local_24 = (int *)FUN_007133c7();
  iVar4 = FUN_007132df(local_20);
  if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  eVar5 = __get_daylight(&local_28);
  if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  eVar5 = __get_dstbias(&local_2c);
  if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  CodePage = ____lc_codepage_func();
  DAT_0297cc54 = 0;
  DAT_0082ab2c = 0xffffffff;
  DAT_0082ab20 = 0xffffffff;
  _Str1 = __getenv_helper_nolock("TZ");
  if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {
    if (DAT_0297cc58 != (char *)0x0) {
      _free(DAT_0297cc58);
      DAT_0297cc58 = (char *)0x0;
    }
    DVar7 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_0297cba8);
    if (DVar7 != 0xffffffff) {
      DAT_0297cc54 = 1;
      local_20[0] = DAT_0297cba8 * 0x3c;
      if (DAT_0297cbee != 0) {
        local_20[0] = local_20[0] + DAT_0297cbfc * 0x3c;
      }
      if ((DAT_0297cc42 == 0) || (DAT_0297cc50 == 0)) {
        local_28 = 0;
        local_2c = 0;
      }
      else {
        local_28 = 1;
        local_2c = (DAT_0297cc50 - DAT_0297cbfc) * 0x3c;
      }
      iVar4 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_0297cbac,-1,(LPSTR)*local_24,0x3f,
                                  (LPCSTR)0x0,&local_34);
      if ((iVar4 == 0) || (local_34 != 0)) {
        *(undefined1 *)*local_24 = 0;
      }
      else {
        *(undefined1 *)(*local_24 + 0x3f) = 0;
      }
      iVar4 = WideCharToMultiByte(CodePage,0,(LPCWSTR)&DAT_0297cc00,-1,(LPSTR)local_24[1],0x3f,
                                  (LPCSTR)0x0,&local_34);
      if ((iVar4 == 0) || (local_34 != 0)) {
        *(undefined1 *)local_24[1] = 0;
      }
      else {
        *(undefined1 *)(local_24[1] + 0x3f) = 0;
      }
    }
  }
  else {
    if (DAT_0297cc58 != (char *)0x0) {
      iVar4 = _strcmp(_Str1,DAT_0297cc58);
      if (iVar4 == 0) goto LAB_0071360d;
      if (DAT_0297cc58 != (char *)0x0) {
        _free(DAT_0297cc58);
      }
    }
    sVar6 = _strlen(_Str1);
    DAT_0297cc58 = __malloc_crt(sVar6 + 1);
    if (DAT_0297cc58 != (char *)0x0) {
      pcVar10 = _Str1;
      sVar6 = _strlen(_Str1);
      eVar5 = _strcpy_s(DAT_0297cc58,sVar6 + 1,pcVar10);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      goto LAB_00713614;
    }
  }
LAB_0071360d:
  local_30 = 1;
LAB_00713614:
  iVar3 = local_20[0];
  piVar8 = (int *)FUN_007133c1();
  iVar4 = local_28;
  *piVar8 = iVar3;
  piVar8 = (int *)FUN_007133b5();
  lVar9 = local_2c;
  *piVar8 = iVar4;
  piVar8 = (int *)FUN_007133bb();
  *piVar8 = lVar9;
  local_8 = (undefined *)0xfffffffe;
  FUN_007136a0();
  piVar8 = local_24;
  if (local_30 == 0) {
    eVar5 = _strncpy_s((char *)*local_24,0x40,_Str1,3);
    if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    pcVar10 = _Str1 + 3;
    cVar1 = *pcVar10;
    if (cVar1 == '-') {
      pcVar10 = _Str1 + 4;
    }
    lVar9 = _atol(pcVar10);
    local_20[0] = lVar9 * 0xe10;
    for (; (cVar2 = *pcVar10, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
        pcVar10 = pcVar10 + 1) {
    }
    if (*pcVar10 == ':') {
      pcVar10 = pcVar10 + 1;
      lVar9 = _atol(pcVar10);
      local_20[0] = local_20[0] + lVar9 * 0x3c;
      for (; ('/' < *pcVar10 && (*pcVar10 < ':')); pcVar10 = pcVar10 + 1) {
      }
      if (*pcVar10 == ':') {
        pcVar10 = pcVar10 + 1;
        lVar9 = _atol(pcVar10);
        local_20[0] = local_20[0] + lVar9;
        for (; ('/' < *pcVar10 && (*pcVar10 < ':')); pcVar10 = pcVar10 + 1) {
        }
      }
    }
    if (cVar1 == '-') {
      local_20[0] = -local_20[0];
    }
    local_28 = (int)*pcVar10;
    if (local_28 == 0) {
      *(undefined1 *)piVar8[1] = 0;
    }
    else {
      eVar5 = _strncpy_s((char *)piVar8[1],0x40,pcVar10,3);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
    }
    iVar3 = local_20[0];
    piVar8 = (int *)FUN_007133c1();
    iVar4 = local_28;
    *piVar8 = iVar3;
    piVar8 = (int *)FUN_007133b5();
    *piVar8 = iVar4;
  }
  return;
}

