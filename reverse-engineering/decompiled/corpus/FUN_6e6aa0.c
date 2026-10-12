/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e6aa0; label: __sprintf_s_l
 */

/* Library Function - Single Match
    __sprintf_s_l
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl __sprintf_s_l(char *_DstBuf,size_t _DstSize,char *_Format,_locale_t _Locale,...)

{
  int iVar1;
  
  iVar1 = __vsprintf_s_l(_DstBuf,_DstSize,_Format,_Locale,&stack0x00000014);
  return iVar1;
}

