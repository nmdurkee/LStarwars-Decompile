/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e6adc; label: __snprintf_s_l
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __snprintf_s_l
   
   Library: Visual Studio 2005 Release */

int __cdecl
__snprintf_s_l(char *_DstBuf,size_t _DstSize,size_t _MaxCount,char *_Format,_locale_t _Locale,...)

{
  int iVar1;
  
  iVar1 = __vsnprintf_s_l(_DstBuf,_DstSize,_MaxCount,_Format,_Locale,&stack0x00000018);
  return iVar1;
}

