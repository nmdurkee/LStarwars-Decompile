/* Ghidra pseudocode, not original source.
 * ev_167fb1af16662301ac7ec00e42056ea51ba92ee67c43a8d5117ba6e42cb74a01
 * Entry: 0x6ef98a; label: FID_conflict:__vsnprintf_c_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
  
  iVar1 = __vsnprintf_helper(FUN_006eef05,_DstBuf,_MaxCount,param_3,_Locale,_ArgList);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  return iVar1;
}

