/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c6c50; label: FUN_004c6c50
 */

void FUN_004c6c50(void)

{
  if ((DAT_00880474 != 0) && (DAT_008800e0 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x004c6c62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_008800e0)();
    return;
  }
  return;
}

