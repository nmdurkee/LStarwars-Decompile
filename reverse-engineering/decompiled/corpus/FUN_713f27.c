/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x713f27; label: __i64toa_s
 */

/* Library Function - Single Match
    __i64toa_s
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __i64toa_s(longlong _Val,char *_DstBuf,size_t _Size,int _Radix)

{
  undefined4 uVar1;
  errno_t eVar2;
  undefined4 in_ECX;
  undefined4 in_EDX;
  
  uVar1 = 0;
  if (((_Radix == 10) && (_Val < 0x100000000)) && (_Val < 0)) {
    uVar1 = 1;
  }
  eVar2 = x64toa_s(in_ECX,in_EDX,_Val,_Size,_Radix,uVar1);
  return eVar2;
}

