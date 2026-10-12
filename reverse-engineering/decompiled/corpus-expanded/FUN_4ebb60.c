/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ebb60; label: FUN_004ebb60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ebb60(void)

{
  int iStack00000004;
  
  DAT_0087b9b4 = 1;
  if (((DAT_0087a7f0 != 0) && (DAT_0087aa5c != 0)) && (*(float *)(DAT_0087aa5c + 0x28) == 1.0)) {
    iStack00000004 = DAT_0087a7f0;
    FUN_004ba2d0();
    return;
  }
  return;
}

