/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e8040; label: FUN_004e8040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e8040(void)

{
  int iStack00000004;
  
  if (((DAT_00951b50 == 0) && (DAT_0087a7f0 != 0)) && (DAT_0087aa5c != 0)) {
    if (*(float *)(DAT_0087aa5c + 0x28) == 1.0) {
      iStack00000004 = DAT_0087a7f0;
      FUN_004ba2d0();
      return;
    }
    iStack00000004 = 0;
    FUN_004ba2d0();
    return;
  }
  return;
}

