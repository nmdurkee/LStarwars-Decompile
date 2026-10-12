/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x713f5a; label: __ui64toa_s
 */

/* Library Function - Single Match
    __ui64toa_s
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __ui64toa_s(ulonglong _Val,char *_DstBuf,size_t _Size,int _Radix)

{
  errno_t eVar1;
  undefined4 in_ECX;
  undefined4 in_EDX;
  
  eVar1 = x64toa_s(in_ECX,in_EDX,_Val,_Size,_Radix,0);
  return eVar1;
}

