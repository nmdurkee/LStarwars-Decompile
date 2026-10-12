/* Ghidra pseudocode, not original source.
 * ev_a061266dd45b392e87f7d3689b136f273b070abf9372dc393200501f91b0ff88
 * Entry: 0x6ee676; label: __cftoa
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

