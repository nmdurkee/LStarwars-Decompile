/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd2b0; label: FUN_004dd2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd2b0(void)

{
  int iStack00000004;
  
  if (DAT_00951b50 != 0) {
    return;
  }
  if (((DAT_00882a8c != 0) && (DAT_00882a90 != 0)) && (*(float *)(DAT_00882a90 + 0x28) == 1.0)) {
    iStack00000004 = DAT_00882a8c;
    FUN_004ba2d0();
    return;
  }
  iStack00000004 = 0;
  FUN_004ba2d0();
  return;
}

