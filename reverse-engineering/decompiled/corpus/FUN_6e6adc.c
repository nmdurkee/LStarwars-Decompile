/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e6adc; label: __snprintf_s_l
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

