/* Ghidra analysis pseudocode, not original source.
 * ev_05a50d78b1ac39cbc8ac7a43523eae9528fc8f40ae743077c5c3f4eab8d21813
 * Entry: 0x6e6abd; label: __snprintf_s
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

