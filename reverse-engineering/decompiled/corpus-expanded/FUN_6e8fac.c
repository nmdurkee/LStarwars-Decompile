/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e8fac; label: FUN_006e8fac
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e8fac(void)

{
  ushort in_FPUControlWord;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006f6ad0();
    return;
  }
  __cintrindisp1();
  return;
}

