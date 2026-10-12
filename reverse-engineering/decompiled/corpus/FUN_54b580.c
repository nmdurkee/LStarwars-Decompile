/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54b580; label: FUN_0054b580
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

