/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e6abd; label: __snprintf_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __snprintf_s
   
   Library: Visual Studio 2005 Release */

int __cdecl __snprintf_s(char *_DstBuf,size_t _SizeInBytes,size_t _MaxCount,char *_Format,...)

{
  int iVar1;
  
  iVar1 = __vsnprintf_s_l(_DstBuf,_SizeInBytes,_MaxCount,_Format,(_locale_t)0x0,&stack0x00000014);
  return iVar1;
}

