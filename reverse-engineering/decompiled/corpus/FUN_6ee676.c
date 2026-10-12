/* Ghidra analysis pseudocode, not original source.
 * ev_fecaad0f39b6546b4dc9650dce16c9bbcd2a84d15696a82d10463b768249874c
 * Entry: 0x6ee676; label: __cftoa
 */

/* Library Function - Single Match
    __cftoa
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __cftoa(double *_Value,char *_Buf,size_t _SizeInBytes,int _Dec,int _Caps)

{
  errno_t eVar1;
  
  eVar1 = __cftoa_l(_Value,_Buf,_SizeInBytes,_Dec,_Caps,0);
  return eVar1;
}

