/* Ghidra pseudocode, not original source.
 * ev_bdf1d7790352cc42fa475d7feda1d016092a6193a7278bd37bc81c47b8a4034d
 * Entry: 0x707bd4; label: __crtGetLocaleInfoW_stat
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtGetLocaleInfoW_stat(struct localeinfo_struct *,unsigned long,unsigned
   long,wchar_t *,int,int)
   
   Library: Visual Studio 2005 Release */

int __cdecl
__crtGetLocaleInfoW_stat
          (localeinfo_struct *param_1,ulong param_2,ulong param_3,wchar_t *param_4,int param_5,
          int param_6)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  uint cchData;
  LPSTR lpLCData;
  
  uVar1 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if (DAT_0297cb94 == 0) {
    iVar2 = GetLocaleInfoW(0,1,(LPWSTR)0x0,0);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x78) {
        DAT_0297cb94 = 2;
      }
      goto LAB_00707c26;
    }
    DAT_0297cb94 = 1;
  }
  else {
LAB_00707c26:
    if (DAT_0297cb94 != 1) {
      if ((DAT_0297cb94 == 2) || (DAT_0297cb94 == 0)) {
        if (param_6 == 0) {
          param_6 = param_1->locinfo->lc_codepage;
        }
        cchData = GetLocaleInfoA(param_2,param_3,(LPSTR)0x0,0);
        if (cchData != 0) {
          if (((int)cchData < 1) || (0xffffffe0 / cchData == 0)) {
            lpLCData = (LPSTR)0x0;
          }
          else if (cchData + 8 < 0x401) {
            if (&stack0x00000000 == (undefined1 *)0x18) goto LAB_00707cfd;
            lpLCData = &stack0xfffffff0;
          }
          else {
            lpLCData = _malloc(cchData + 8);
            if (lpLCData != (LPSTR)0x0) {
              lpLCData[0] = -0x23;
              lpLCData[1] = -0x23;
              lpLCData[2] = '\0';
              lpLCData[3] = '\0';
              lpLCData = lpLCData + 8;
            }
          }
          if (lpLCData != (LPSTR)0x0) {
            iVar2 = GetLocaleInfoA(param_2,param_3,lpLCData,cchData);
            if (iVar2 != 0) {
              if (param_5 == 0) {
                param_5 = 0;
                param_4 = (LPWSTR)0x0;
              }
              MultiByteToWideChar(param_6,1,lpLCData,-1,param_4,param_5);
            }
            __freea(lpLCData);
          }
        }
      }
      goto LAB_00707cfd;
    }
  }
  GetLocaleInfoW(param_2,param_3,param_4,param_5);
LAB_00707cfd:
  iVar2 = __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

