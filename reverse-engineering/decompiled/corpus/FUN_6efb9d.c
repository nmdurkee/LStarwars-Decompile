/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6efb9d; label: FID_conflict:__vsnprintf_c_l
 */

/* Library Function - Multiple Matches With Different Base Names
    __vsnprintf_c_l
    __vsprintf_p_l
   
   Library: Visual Studio 2005 Release */

int __cdecl
FID_conflict___vsnprintf_c_l
          (char *_DstBuf,size_t _MaxCount,char *param_3,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = __vsnprintf_helper(&DAT_006f2cec,_DstBuf,_MaxCount,param_3,_Locale,_ArgList);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

