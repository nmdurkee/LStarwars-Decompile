/* Ghidra pseudocode, not original source.
 * ev_0b5d44e813c4aa355d260cb866ec5aec765804eee128937753d2ed60240642a2
 * Entry: 0x6e9040; label: FUN_006e9040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e9040(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006f7220();
    return;
  }
  FUN_006f6968((double)in_ST0);
  FUN_006e9098();
  return;
}

