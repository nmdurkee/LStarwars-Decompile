/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ec65c; label: __set_controlfp
 */

/* Library Function - Single Match
    __set_controlfp
   
   Library: Visual Studio 2005 Release */

void __cdecl __set_controlfp(uint _NewValue,uint _Mask)

{
  errno_t eVar1;
  ushort in_FPUControlWord;
  
  if ((((_NewValue != 0x9001f) || (_Mask != 0xffffffff)) || ((in_FPUControlWord & 0x1f3d) != 0x23d))
     || ((DAT_029a9c48 != 0 && ((MXCSR & 0xfec0) != 0x1e80)))) {
    eVar1 = __controlfp_s((uint *)0x0,_NewValue,_Mask & 0xfff7ffff);
    if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return;
}

