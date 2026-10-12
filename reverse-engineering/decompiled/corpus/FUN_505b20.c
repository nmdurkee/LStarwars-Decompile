/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505b20; label: FUN_00505b20
 */

void FUN_00505b20(int param_1)

{
  if ((*(int *)(param_1 + 0x18) != 0) && (DAT_0092139c != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00505b37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0092139c)();
    return;
  }
  return;
}

