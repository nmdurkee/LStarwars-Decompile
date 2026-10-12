/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e92e0; label: FUN_006e92e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e92e0(void)

{
  ushort in_FPUControlWord;
  float10 in_ST0;
  float10 in_ST1;
  
  if ((DAT_029a9c44 != 0) && ((MXCSR & 0x1f80) == 0x1f80 && (in_FPUControlWord & 0x7f) == 0x7f)) {
    FUN_006f7720();
    return;
  }
  FUN_006e933d((double)in_ST1,(double)in_ST0);
  return;
}

