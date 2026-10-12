/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x713f5a; label: __ui64toa_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

