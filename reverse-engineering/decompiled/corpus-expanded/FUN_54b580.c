/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54b580; label: FUN_0054b580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054b580(void)

{
  DAT_0080235c = FUN_004f5240();
  if (DAT_00926c40 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0054b598. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00926c40)();
    return;
  }
  return;
}

