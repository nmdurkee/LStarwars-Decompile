/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd580; label: FUN_004dd580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd580(undefined4 param_1)

{
  FUN_004dd3b0(param_1);
  DAT_00882a78 = 0;
  DAT_00882904 = 1;
  DAT_00882900 = 0;
  if (DAT_00882a70 < 2) {
    *(undefined4 *)(DAT_00882a6c + 0xb000) = 0x40400000;
  }
  return;
}

