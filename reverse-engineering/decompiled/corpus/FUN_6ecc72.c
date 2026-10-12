/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ecc72; label: __statusfp2
 */

/* Library Function - Single Match
    __statusfp2
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __statusfp2(uint *_X86_status,uint *_SSE2_status)

{
  uint uVar1;
  ushort in_FPUStatusWord;
  
  if (_X86_status != (uint *)0x0) {
    uVar1 = 0;
    if ((in_FPUStatusWord & 0x3f) != 0) {
      if ((in_FPUStatusWord & 1) != 0) {
        uVar1 = 0x10;
      }
      if ((in_FPUStatusWord & 4) != 0) {
        uVar1 = uVar1 | 8;
      }
      if ((in_FPUStatusWord & 8) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((in_FPUStatusWord & 0x10) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((in_FPUStatusWord & 0x20) != 0) {
        uVar1 = uVar1 | 1;
      }
      if ((in_FPUStatusWord & 2) != 0) {
        uVar1 = uVar1 | 0x80000;
      }
    }
    *_X86_status = uVar1;
  }
  if (_SSE2_status != (uint *)0x0) {
    uVar1 = ___statusfp_sse2();
    *_SSE2_status = uVar1;
  }
  return;
}

