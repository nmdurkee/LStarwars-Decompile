/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x707d4a; label: __crtGetLocaleInfoA_stat
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtGetLocaleInfoA_stat(struct localeinfo_struct *,unsigned long,unsigned long,char
   *,int,int)
   
   Library: Visual Studio 2005 Release */

int __cdecl
__crtGetLocaleInfoA_stat
          (localeinfo_struct *param_1,ulong param_2,ulong param_3,char *param_4,int param_5,
          int param_6)

{
  uint _Size;
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  uint cchData;
  LPWSTR lpLCData;
  
  uVar1 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if (DAT_0297cb98 == 0) {
    iVar2 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x78) {
        DAT_0297cb98 = 2;
      }
      goto LAB_00707d9c;
    }
    DAT_0297cb98 = 1;
  }
  else {
LAB_00707d9c:
    if ((DAT_0297cb98 == 2) || (DAT_0297cb98 == 0)) {
      GetLocaleInfoA(param_2,param_3,param_4,param_5);
      goto LAB_00707e75;
    }
    if (DAT_0297cb98 != 1) goto LAB_00707e75;
  }
  if (param_6 == 0) {
    param_6 = param_1->locinfo->lc_codepage;
  }
  cchData = GetLocaleInfoW(param_2,param_3,(LPWSTR)0x0,0);
  if (cchData != 0) {
    if (((int)cchData < 1) || (0xffffffe0 / cchData < 2)) {
      lpLCData = (LPWSTR)0x0;
    }
    else {
      _Size = cchData * 2 + 8;
      if (_Size < 0x401) {
        if (&stack0x00000000 == (undefined1 *)0x18) goto LAB_00707e75;
        lpLCData = (LPWSTR)&stack0xfffffff0;
      }
      else {
        lpLCData = _malloc(_Size);
        if (lpLCData != (LPWSTR)0x0) {
          lpLCData[0] = L'\xdddd';
          lpLCData[1] = L'\0';
          lpLCData = lpLCData + 4;
        }
      }
    }
    if (lpLCData != (LPWSTR)0x0) {
      iVar2 = GetLocaleInfoW(param_2,param_3,lpLCData,cchData);
      if (iVar2 != 0) {
        if (param_5 == 0) {
          param_5 = 0;
          param_4 = (LPSTR)0x0;
        }
        WideCharToMultiByte(param_6,0,lpLCData,-1,param_4,param_5,(LPCSTR)0x0,(LPBOOL)0x0);
      }
      __freea(lpLCData);
    }
  }
LAB_00707e75:
  iVar2 = __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

