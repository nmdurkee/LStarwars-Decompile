/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6ebcb0; label: FUN_006ebcb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ebcb0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006fcc20();
    return;
  }
  FUN_006f6968((double)in_ST0);
  FUN_006ebd08();
  return;
}

