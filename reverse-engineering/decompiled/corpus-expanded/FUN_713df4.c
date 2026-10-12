/* Ghidra pseudocode, not original source.
 * ev_679903358dce225aedf8e0cd6850e85c923706fd55f3fc08c48a53cda153f2a5
 * Entry: 0x713df4; label: __ltoa_s
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

