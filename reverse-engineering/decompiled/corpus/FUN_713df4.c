/* Ghidra analysis pseudocode, not original source.
 * ev_7b35a8fafa232ee0b9a0913c200a618a9d6b1b7e21f700964d68a0258798e3f5
 * Entry: 0x713df4; label: __ltoa_s
 */

/* Library Function - Single Match
    __ltoa_s
   
   Library: Visual Studio 2005 Release */

errno_t __cdecl __ltoa_s(long _Val,char *_DstBuf,size_t _Size,int _Radix)

{
  undefined4 uVar1;
  errno_t eVar2;
  
  uVar1 = 0;
  if ((_Radix == 10) && (_Val < 0)) {
    uVar1 = 1;
  }
  eVar2 = xtoa_s(_Size,_Radix,uVar1);
  return eVar2;
}

