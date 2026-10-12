/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6efb58; label: __vsnprintf_s
 */

/* Library Function - Single Match
    __vsnprintf_s
   
   Library: Visual Studio 2005 Release */

int __cdecl
__vsnprintf_s(char *_DstBuf,size_t _SizeInBytes,size_t _MaxCount,char *_Format,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = __vsnprintf_s_l(_DstBuf,_SizeInBytes,_MaxCount,_Format,(_locale_t)0x0,_ArgList);
  return iVar1;
}

