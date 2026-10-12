/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e9190; label: FUN_006e9190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e9190(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006f7490();
    return;
  }
  FUN_006f6968((double)in_ST0);
  FUN_006e91e8();
  return;
}

